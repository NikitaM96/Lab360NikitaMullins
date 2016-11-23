#pragma once
#include "GameController.h"



class Game
{
public:
	Game();

	void initialise();
	void update();
	void draw();
	void run();
	void lastButtonPressed();

	Xbox360Controller gameController;
	sf::RenderWindow m_window;
	sf::Texture m_controller;
	sf::Sprite m_background;
	sf::Font m_font;

	//Declare Text Variables.
	sf::Text m_RthumbstickX;
	sf::Text m_RthumbstickY;
	sf::Text m_LthumbStickX;
	sf::Text m_LthumbStickY;
	sf::Text m_buttonA;
	sf::Text m_buttonB;
	sf::Text m_buttonX;
	sf::Text m_buttonY;
	sf::Text m_lB;
	sf::Text m_rB;
	sf::Text m_start;
	sf::Text m_back;
	sf::Text m_leftThumbStickClick;
	sf::Text m_rightThumbStickClick;
	sf::Text m_up;
	sf::Text m_down;
	sf::Text m_left;
	sf::Text m_right;
	sf::Text m_lT;
	sf::Text m_rT;

	sf::Text  m_lastPressed;
	~Game();
};

