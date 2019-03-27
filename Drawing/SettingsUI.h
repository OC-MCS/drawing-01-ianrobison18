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
	CircleShape redButton, blueButton, yellowButton,
		circleButton;
	RectangleShape squareButton;

public:
	SettingsUI(SettingsMgr *mgr);
	void handleMouseUp(Vector2f mouse, SettingsMgr &settings);
	void draw(RenderWindow& win);
};
