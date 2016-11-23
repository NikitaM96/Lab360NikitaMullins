#ifndef XBOX360CONTROLLER
#define XBOX360CONTROLLER

#include <SFML/Graphics.hpp>

/// <summary>
/// used to store controller  state
/// </summary>


struct  GamePadState
{
	bool A;
	bool B;
	bool X;
	bool Y;
	bool LB;
	bool RB;
	bool LeftThumbStickClick;
	bool rightThumbStickClick;
	bool dPadLeft;
	bool dPadRight;
	bool dPadUp;
	bool dPadDown;
	bool start;
	bool back;
	float lTrigger;
	float rTrigger;

	sf::Vector2f rightThumbStick;
	sf::Vector2f leftThumbStick;

};

/// <summary>
/// Controller class for current state of the controller
/// to mimic states like xna
/// </summary>

class Xbox360Controller
{

private:
	const int dPadThreshold = 50;

public:
	int sf_Joystick_index;

	GamePadState m_currentState;

	GamePadState m_previousState;

	Xbox360Controller();
	~Xbox360Controller();

	void update();
	bool isConnected();
	bool connect();

};

#endif // !XBOX360CONTROLLER