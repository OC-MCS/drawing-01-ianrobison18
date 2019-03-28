#pragma once
#include <SFML/Graphics.hpp>
#include <iostream>
using namespace std;
using namespace sf;
#include "SettingsMgr.h"

// finish this code; add functions, data as needed

class SettingsUI
{
private:
	CircleShape redButton,	//red settings button
		blueButton,			//blue settings button
		yellowButton,		//yellow settings button
		circleButton;		//circle settings button
	RectangleShape squareButton;	//SqUaRe SeTtInGs BuTtOn

public:
	SettingsUI(SettingsMgr *mgr);
	void handleMouseUp(Vector2f mouse, SettingsMgr &settings);
	void draw(RenderWindow& win);
};
