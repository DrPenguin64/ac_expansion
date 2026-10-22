#include "Scene_IntroTrain.h"

int Scene_IntroTrain::OnChangeToScene()
{
	mainWindow->setTitle("Train");
	return 0;
}

// Load any assets needed
int Scene_IntroTrain::LoadScene() {
	OnChangeToScene();
	std::cout << "Loading Scene_OnTrain...\n";
	std::cout << "Title screen loaded.\n";
	return 0;
}

// Define layout of the scene
int Scene_IntroTrain::InitScene() {
}

int MainSequence()
{
	std::array<int, 12> playerChoices_Intro = { -1 }; // holds each choice they made, used for character creation
	ShowDialog("Hm, Uh... Excuse me..\nDo you have a second?", "Rover");
	ShowDialog("Could you help me out?\nIs it ... Let's see now...\n[Current time]?", "Rover", true);
	int playerChoice = Choices("Yes", "No");
	if (playerChoice == 0)
	{
		ShowDialog("Say, thanks! You're too kind!\nReally, you're a big help...\nMya ha ha ha ha ha howr!", "Rover");
		ShowDialog("So, you mind if I sit here?\nI promise I won't fall asleep,\ntumble onto you, and start\ndrooling on your shirt!", "Rover", true);
		playerChoices_Intro[0] = Choices("Please!", "No way!");
		CueAnimation(ACTOR_Rover, "Sit_on_seat");
		if (playerChoices_Intro[0] == 0)
		{

		}
		else if (playerChoices_Intro[0] == 1)
		{
			ShowDialog("Wow, thanks!\nIt sure is great to know there are still friendly folk riding the train...\nYou know what?\nI'm just going to sit here anyway.", "Rover");
			ShowDialog("I don't even know why I am asking this, but...\nWhat's your name?", "Rover");
			char* playerName;
			GetStrInput("What's your name?", playerName&, 16);
			ShowDialog("Hrm...Well...Hrmm...\n{playerName}...\nNow THAT is an odd name.\nMyah ha ha ha!", "Rover");
			ShowDialog("Not that my opinion means\nmuch. What matters is, do \nYOU like the name {playerName}?", "Rover");
			int gchoice = Choices("Isn't it cute?", "Isn't it cool?", "No! No! No!");
			if (gchoice == 0) ShowDialog("Yeah, {playerName} is a pretty name.\n", "Rover");
			else if (gchoice == 1) {
				ShowDialog("Oh, I'm sorry! Did I say it\nwas odd? It's not odd!\nIt's a great name for a boy!\nReally. It's uh...", "Rover");
				ShowDialog("It's a really great name.\nMya ha ha ha ha ha howr!", "Rover");
				int c2 = Choices("You know it!", "I'm not a boy!")
			}
		}
	}
	else
	{

	}


}