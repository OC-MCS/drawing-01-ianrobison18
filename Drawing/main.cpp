//================================================
//Ian Robison
//================================================
#include <iostream>
#include <fstream>
using namespace std;
#include <SFML\Graphics.hpp>
#include "SettingsMgr.h"
#include "ShapeMgr.h"
#include "SettingsUI.h"
#include "DrawingUI.h"
using namespace sf;


// Finish this code. Other than where it has comments telling you to 
// add code, you shouldn't need to add any logic to main to satisfy
// the requirements of this programming assignment
settings fileRead(fstream &file);

int main()
{
	const int WINDOW_WIDTH = 800;
	const int WINDOW_HEIGHT = 600;

	RenderWindow window(VideoMode(WINDOW_WIDTH, WINDOW_HEIGHT), "Drawing"); //the render window
	window.setFramerateLimit(60);

	//Read in the settings from the file
	fstream infile; //input file object
	infile.open("shapes.bin", ios::binary | ios::in);
	if (!infile)
	{
		cout << "Error opening file";
		exit(1);
	}
	settings curSettings = fileRead(infile); //the current settings read from the file
	SettingsMgr settingsMgr(curSettings.lastColor, curSettings.lastShape); //initializing settings from the settings read
	SettingsUI  settingsUI(&settingsMgr); //displaying the settings area
	ShapeMgr    shapeMgr; //what will contain every shape
	DrawingUI   drawingUI(Vector2f(250, 50)); //drawing area
	
	//Read in the shapes of the file
	shapeMgr.fileRead(infile);
	infile.close();

	while (window.isOpen()) 
	{
		Event event;
		while (window.pollEvent(event))
		{
			if (event.type == Event::Closed)
			{
				window.close();
				//write out the settings and the shapes to the file
				fstream outfile; //output file object
				outfile.open("shapes.bin", ios::binary | ios::out);
				if (!outfile)
				{
					cout << "Error opening file";
					exit(1);
				}
				settingsMgr.fileWrite(outfile);
				shapeMgr.fileWrite(outfile);
				outfile.close();
			}
			else if (event.type == Event::MouseButtonReleased)
			{
				// maybe they just clicked on one of the settings "buttons"
				// check for this and handle it.
				//Handle releasing the mouse button and check if over any settings buttons
				Vector2f mousePos = window.mapPixelToCoords(Mouse::getPosition(window)); //the mouse's current position
				settingsUI.handleMouseUp(mousePos, settingsMgr);
			}
			else if (event.type == Event::MouseMoved && Mouse::isButtonPressed(Mouse::Button::Left))
			{
				//handling of user is trying to draw in canvas
				Vector2f mousePos = window.mapPixelToCoords(Mouse::getPosition(window)); //the mouse's current position
				// check to see if mouse is in the drawing area
				if (drawingUI.isMouseInCanvas(mousePos))
				{
					// add a shape to the list based on current settings
					shapeMgr.addShape(mousePos, settingsMgr.getCurShape(), settingsMgr.getCurColor());
				}
			}
		}

		// The remainder of the body of the loop draws one frame of the animation
		window.clear();

		// this should draw the left hand side of the window (all of the settings info)
		settingsUI.draw(window);

		// this should draw the rectangle that encloses the drawing area, then draw the
		// shapes. This is passed the shapeMgr so that the drawingUI can get the shapes
		// in order to draw them. This redraws *all* of the shapes every frame.
		drawingUI.draw(window, &shapeMgr);

		window.display();
	} // end body of animation loop

	return 0;
}

/*===========================
Name: fileRead
Purpose: reads settings from file
Parameters: file
Returns: settings struct
===========================*/
settings fileRead(fstream &file)
{
	settings lastSettings; //an object to read the settings
	
	file.read(reinterpret_cast<char*>(&lastSettings), sizeof(settings));

	return lastSettings;
}