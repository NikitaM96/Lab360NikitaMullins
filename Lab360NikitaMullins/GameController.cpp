#include "GameController.h"
#include <iostream>


Xbox360Controller::Xbox360Controller()
{
}

void Xbox360Controller::update()
{

	m_previousState = m_currentState;
	sf::Joystick::update();

	//Takes in the value of the d-pad X and Y axis. 
	//PovX = D-X
	//PovY = D-Y 
	double A = sf::Joystick::getAxisPosition(0, sf::Joystick::Axis::PovX);
	double B = sf::Joystick::getAxisPosition(0, sf::Joystick::Axis::PovY);


	//Takes in the values of the d-pad x & y and assigns them to their respective direactions.
	//Right Direction
	if (sf::Joystick::getAxisPosition(0, sf::Joystick::Axis::PovX) > 50)
	{
		m_currentState.dPadRight = true;
		std::cout << "Right pressed" << std::endl;//CMD TEST.
	}
	else
	{
		m_currentState.dPadRight = false;
	}

	//Left Direction
	if (sf::Joystick::getAxisPosition(0, sf::Joystick::Axis::PovX) < -50)
	{
		m_currentState.dPadLeft = true;
		std::cout << "Left pressed" << std::endl;//CMD TEST.
	}
	else
	{
		m_currentState.dPadLeft = false;
	}
	//Up Direction
	if (sf::Joystick::getAxisPosition(0, sf::Joystick::Axis::PovY) > 50)
	{
		m_currentState.dPadUp = true;
		std::cout << "Up pressed" << std::endl;//CMD TEST.
	}
	else
	{
		m_currentState.dPadUp = false;
	}
	//Down Direction
	if (sf::Joystick::getAxisPosition(0, sf::Joystick::Axis::PovY) < -50)
	{
		m_currentState.dPadDown = true;
		std::cout << "Down pressed" << std::endl;//CMD TEST.
	}
	else
	{
		m_currentState.dPadDown = false;
	}




	//This takes in the values of the analog axis for both the left and right thumb sticks.
	//U = RightThhumbstickX
	//R = RightThumbstickY
	//X = LeftThumbStickX
	//Y = RightThumbStickY
	m_currentState.rightThumbStick = sf::Vector2f(sf::Joystick::getAxisPosition(0, sf::Joystick::Axis::U), sf::Joystick::getAxisPosition(0, sf::Joystick::Axis::R));
	m_currentState.leftThumbStick = sf::Vector2f(sf::Joystick::getAxisPosition(0, sf::Joystick::Axis::X), sf::Joystick::getAxisPosition(0, sf::Joystick::Axis::Y));

	//Uses the :Joystick::Axis::Z value for both thr left and right triggers and sets the value to 0 if criteria isnt met.
	if (sf::Joystick::getAxisPosition(0, sf::Joystick::Axis::Z) < -10)
	{
		m_currentState.rTrigger = (int)sf::Joystick::getAxisPosition(0, sf::Joystick::Axis::Z) * -1; //Multiplied by -1 to convert the value shown to a positive
	}
	else
	{
		m_currentState.rTrigger = 0;
	}
	if (sf::Joystick::getAxisPosition(0, sf::Joystick::Axis::Z) > 10)
	{
		m_currentState.lTrigger = (int)sf::Joystick::getAxisPosition(0, sf::Joystick::Axis::Z);
	}
	else
	{
		m_currentState.lTrigger = 0;
	}


	//Button input check.
	m_currentState.A = sf::Joystick::isButtonPressed(0, 0); //A
	m_currentState.B = sf::Joystick::isButtonPressed(0, 1); //B
	m_currentState.X = sf::Joystick::isButtonPressed(0, 2); //X
	m_currentState.Y = sf::Joystick::isButtonPressed(0, 3); //Y

	m_currentState.start = sf::Joystick::isButtonPressed(0, 7);	//Start
	m_currentState.back = sf::Joystick::isButtonPressed(0, 6); //Back

	m_currentState.LB = sf::Joystick::isButtonPressed(0, 4);  //LB
	m_currentState.RB = sf::Joystick::isButtonPressed(0, 5);  //RB

	m_currentState.LeftThumbStickClick = sf::Joystick::isButtonPressed(0, 8); //Left Thumb Stick
	m_currentState.rightThumbStickClick = sf::Joystick::isButtonPressed(0, 9);//Right Thumb Stick



	//TESTING ON BUTTON INPUT IN CMD.
	if(m_currentState.start && !m_previousState.start)
	{
		m_currentState.start = true;
		std::cout << "start" << std::endl;
	}

	 if(m_currentState.back && !m_previousState.back)
	{
		m_currentState.back = true;
		std::cout << "back" << std::endl;
	}

	 if (m_currentState.A && !m_previousState.A)
	 {
		 m_currentState.A = true;
		 std::cout << "A" << std::endl;
	 }
}
Xbox360Controller::~Xbox360Controller()
{
}