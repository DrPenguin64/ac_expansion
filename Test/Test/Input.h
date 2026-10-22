#pragma once

// Int explanation:
// 0 = not pressed
// 1 = just pressed
// 2 = held
// -1 = just released
// 
// So, to check if pressed||held just check key > 0.
// To check if key is released, check if key < 1.

class Inputs
{
public:
	int move_upKey;
	int move_downKey;
	int move_leftKey;
	int move_rightKey;

	int confirm_Key;
	int interactUse_Key;
	int cancel_Key;
};

void UpdateInputEvents();

extern Inputs Input;