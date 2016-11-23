#include "Game.h"



/// <summary>
/// @main Lab360
/// @Author Nikita Mullins
/// @Version 1.0
/// @brief Application to test input from 360 controller
///
/// date & time of each session and time taken
/// Total time taken on this project e.g.
/// 
/// 14/11/16 14:30 30 min
/// 21/11/16 14:00 7hr 40mins
/// 22/11/16 13:40 2hrs 54 mins
/// Total Time Taken: 11hr 4mins
/// </summary>


Game::Game() :
	m_window(sf::VideoMode (900, 600, 32), "Supah Cool 360 Game", sf::Style::Default) //sets dimensions and name of game screen
{
	
}

void Game::initialise()
{

	//Used to load in resources needed for the game.
	if (!m_controller.loadFromFile("./Resources/controller.jpg"))
	{

	}

	if (!m_font.loadFromFile("./Resources/times.ttf"))
	{

	}

	//RIGHT AND LEFT THUB STICK VALUES.
	//For right thumb stick X values
	m_RthumbstickX.setFont(m_font);
	m_RthumbstickX.setCharacterSize(24);
	m_RthumbstickX.setColor(sf::Color(100,0, 0, 100));
	m_RthumbstickX.setPosition(510, 530);

	//For right thumb stick Y values
	m_RthumbstickY.setFont(m_font);
	m_RthumbstickY.setCharacterSize(24);
	m_RthumbstickY.setColor(sf::Color(100, 0, 0, 100));
	m_RthumbstickY.setPosition(510, 510);

	//For left thumb stick X values
	m_LthumbStickX.setFont(m_font);
	m_LthumbStickX.setCharacterSize(24);
	m_LthumbStickX.setColor(sf::Color(100, 0, 0, 100));
	m_LthumbStickX.setPosition(40, 200);

	//For left thumb stick Y values
	m_LthumbStickY.setFont(m_font);
	m_LthumbStickY.setCharacterSize(24);
	m_LthumbStickY.setColor(sf::Color(100, 0, 0, 100));
	m_LthumbStickY.setPosition(40, 170);

	//For RightThumbClicked button values
	m_rightThumbStickClick.setFont(m_font);
	m_rightThumbStickClick.setCharacterSize(24);
	m_rightThumbStickClick.setColor(sf::Color(100, 0, 0, 100));
	m_rightThumbStickClick.setPosition(510, 550);

	//For LeftThumbClicked button values
	m_leftThumbStickClick.setFont(m_font);
	m_leftThumbStickClick.setCharacterSize(24);
	m_leftThumbStickClick.setColor(sf::Color(100, 0, 0, 100));
	m_leftThumbStickClick.setPosition(40, 230);


	//A B X Y VALUES
	//For A button values
	m_buttonA.setFont(m_font);
	m_buttonA.setCharacterSize(24);
	m_buttonA.setColor(sf::Color(100, 0, 0, 100));
	m_buttonA.setPosition(750, 415);
	
	//For B button values
	m_buttonB.setFont(m_font);
	m_buttonB.setCharacterSize(24);
	m_buttonB.setColor(sf::Color(100, 0, 0, 100));
	m_buttonB.setPosition(750, 360);

	//For X button values
	m_buttonX.setFont(m_font);
	m_buttonX.setCharacterSize(24);
	m_buttonX.setColor(sf::Color(100, 0, 0, 100));
	m_buttonX.setPosition(750, 305);

	//For Y button values
	m_buttonY.setFont(m_font);
	m_buttonY.setCharacterSize(24);
	m_buttonY.setColor(sf::Color(100, 0, 0, 100));
	m_buttonY.setPosition(750, 250);

	//For start button values
	m_start.setFont(m_font);
	m_start.setCharacterSize(24);
	m_start.setColor(sf::Color(100, 0, 0, 100));
	m_start.setPosition(760, 500);

	


	//LB/RB & RT/LT VALUES.
	//For LB button values
	m_lB.setFont(m_font);
	m_lB.setCharacterSize(24);
	m_lB.setColor(sf::Color(100, 0, 0, 100));
	m_lB.setPosition(40, 130);

	//For RB button values
	m_rB.setFont(m_font);
	m_rB.setCharacterSize(24);
	m_rB.setColor(sf::Color(100, 0, 0, 100));
	m_rB.setPosition(700, 130);

	//Right Trigger text values.
	m_rT.setFont(m_font);
	m_rT.setCharacterSize(24);
	m_rT.setColor(sf::Color(100, 0, 0, 100));
	m_rT.setPosition(560, 30);

	//Left Trigger text values.
	m_lT.setFont(m_font);
	m_lT.setCharacterSize(24);
	m_lT.setColor(sf::Color(100, 0, 0, 100));
	m_lT.setPosition(70, 30);


	//DIRECTION BUTTONS VALUES
	//For d-pad Up button values
	m_up.setFont(m_font);
	m_up.setCharacterSize(24);
	m_up.setColor(sf::Color(100, 0, 0, 100));
	m_up.setPosition(300, 570);

	//For d-pad down button values
	m_down.setFont(m_font);
	m_down.setCharacterSize(24);
	m_down.setColor(sf::Color(100, 0, 0, 100));
	m_down.setPosition(300, 570);

	//For d-pad Left button values
	m_left.setFont(m_font);
	m_left.setCharacterSize(24);
	m_left.setColor(sf::Color(100, 0, 0, 100));
	m_left.setPosition(300, 570);

	//For d-pad right button values
	m_right.setFont(m_font);
	m_right.setCharacterSize(24);
	m_right.setColor(sf::Color(100, 0, 0, 100));
	m_right.setPosition(300, 570);

	//LAST BUTTON PRESSED STRING
	m_lastPressed.setFont(m_font);
	m_lastPressed.setCharacterSize(20);
	m_lastPressed.setColor(sf::Color(100, 10, 10, 100));
	m_lastPressed.setPosition(620, 200);
	m_lastPressed.setString("NO FACE BUTTON PRESSED");


	m_background.setTexture(m_controller);

}

void Game::run()
{

	initialise();

	while (m_window.isOpen())
	{
		update();
		draw();

	}
}


//This method is used to display which of the 'Face' buttons were last pressed by the user.
void Game::lastButtonPressed()
{
	if (gameController.m_currentState.A && !gameController.m_previousState.A)
	{
		m_lastPressed.setString("Last Button Pressed: A");
	}
	if (gameController.m_currentState.B && !gameController.m_previousState.B)
	{
		m_lastPressed.setString("Last Button Pressed: B");
	}
	if (gameController.m_currentState.X && !gameController.m_previousState.X)
	{
		m_lastPressed.setString("Last Button Pressed: X");
	}
	if (gameController.m_currentState.Y && !gameController.m_previousState.Y)
	{
		m_lastPressed.setString("Last Button Pressed: Y");
	}
}



void Game::update()
{
	gameController.update();
	lastButtonPressed();

	//Calls in the values of the left and right analog sticks and sets them to a string to be displayed to the screen. 
	m_RthumbstickX.setString(std::to_string(gameController.m_currentState.rightThumbStick.x) + "X");
	m_RthumbstickY.setString(std::to_string(gameController.m_currentState.rightThumbStick.y) + "Y");

	m_LthumbStickX.setString(std::to_string(gameController.m_currentState.leftThumbStick.x) + "X");
	m_LthumbStickY.setString(std::to_string(gameController.m_currentState.leftThumbStick.y) + "Y");
	
	//Calls value of LT anf RT to the game cpp and sets them to a string.
	m_lT.setString(std::to_string(gameController.m_currentState.lTrigger));
	m_rT.setString(std::to_string(gameController.m_currentState.rTrigger));
	
	//If buttons are found to be true their respective strings are set.
	if (gameController.m_currentState.A)
	{
		m_buttonA.setString("A Pressed");
	}

	if (gameController.m_currentState.B)
	{
		m_buttonB.setString("B Pressed");
	}

	if (gameController.m_currentState.X)
	{
		m_buttonX.setString("X Pressed");
	}

	if (gameController.m_currentState.Y)
	{
		m_buttonY.setString("Y Pressed");
	}

	if (gameController.m_currentState.start)
	{
		m_start.setString("start Pressed");
	}

	if (gameController.m_currentState.LB)
	{
		m_lB.setString("LB Pressed");
	}

	if (gameController.m_currentState.RB)
	{
		m_rB.setString("RB Pressed");
	}

	if (gameController.m_currentState.rightThumbStickClick)
	{
		m_rightThumbStickClick.setString("right thumb Pressed");
	}

	if (gameController.m_currentState.LeftThumbStickClick)
	{
		m_leftThumbStickClick.setString("left thumb Pressed");
	}

	if (gameController.m_currentState.dPadUp)
	{
		m_up.setString("Up Pressed");
	}

	if (gameController.m_currentState.dPadDown)
	{
		m_down.setString("Down Pressed");
	}

	if (gameController.m_currentState.dPadLeft)
	{
		m_left.setString("Left Pressed");
	}

	if (gameController.m_currentState.dPadRight)
	{
		m_right.setString("Right Pressed");
	}

	//Used to quit the program
	if (gameController.m_currentState.back)
	{
		m_window.close();
	}
	
}

void Game::draw()
{
	m_window.clear(sf::Color(0, 0, 0, 0));
	m_window.draw(m_background);


	//Left and right thumb stick Y and Y values are only displayed onto the screen by being less than -15 and greater than 15. 
	if (gameController.m_currentState.rightThumbStick.x < -15 || gameController.m_currentState.rightThumbStick.x > 15)
	{
		m_window.draw(m_RthumbstickX);
	}
	if (gameController.m_currentState.rightThumbStick.y < -15 || gameController.m_currentState.rightThumbStick.y > 15)
	{
		m_window.draw(m_RthumbstickY);
	}
	if (gameController.m_currentState.leftThumbStick.x < -15 || gameController.m_currentState.leftThumbStick.x > 15)
	{
		m_window.draw(m_LthumbStickX);
	}
	if (gameController.m_currentState.leftThumbStick.y < -15 || gameController.m_currentState.leftThumbStick.y > 15)
	{
		m_window.draw(m_LthumbStickY);
	}

	//These buttons are only displayed when their values are found to be true. 
	if (gameController.m_currentState.A)
	{
		m_window.draw(m_buttonA);
	}
	
	if (gameController.m_currentState.B)
	{
		m_window.draw(m_buttonB);
	}

	if (gameController.m_currentState.X)
	{
		m_window.draw(m_buttonX);
	}

	if (gameController.m_currentState.Y)
	{
		m_window.draw(m_buttonY);
	}

	if (gameController.m_currentState.start)
	{
		m_window.draw(m_start);
	}


	if (gameController.m_currentState.LB)
	{
		m_window.draw(m_lB);
	}

	if (gameController.m_currentState.RB)
	{
		m_window.draw(m_rB);
	}

	if (gameController.m_currentState.rightThumbStickClick)
	{
		m_window.draw(m_rightThumbStickClick);
	}

	if (gameController.m_currentState.LeftThumbStickClick)
	{
		m_window.draw(m_leftThumbStickClick);
	}

	if (gameController.m_currentState.dPadUp)
	{
		m_window.draw(m_up);
	}

	if (gameController.m_currentState.dPadDown)
	{
		m_window.draw(m_down);
	}

	if (gameController.m_currentState.dPadLeft)
	{
		m_window.draw(m_left);
	}

	if (gameController.m_currentState.dPadRight)
	{
		m_window.draw(m_right);
	}

	//The LT and RT values are always drawn onto the screen. 
	m_window.draw(m_lT);
	m_window.draw(m_rT);

	//Displays last button pressed text
	m_window.draw(m_lastPressed);


	m_window.display();
}

Game::~Game()
{
}

