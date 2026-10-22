
#include <iostream>
#include <SFML/Graphics.hpp>
#include "GUI_Fonts.h"
#include "TitleScreen.h"
#include "Global.h"
#include "Input.h"

// Draft
/*
* For now, the title screen will just show the title,
* and have 'New Game' 
* 'Continue'
* and 'Settings'
* Next step is to add a town in the background, and make the camera follow around
* a villager walking around
*/

// Title
sf::Text titleText(UIFont, "Animal Crossing", 60);
sf::Text pressAnyKey_Text(UIFont, "Press any key");
float pressAnyKeyTimer = 0.f;
bool pressAnyKey_dismissed = false;

// Main options menu
sf::Text NewGame_Text(UIFont, "New Game");
sf::Text ContinueGame_Text(UIFont, "Continue");
sf::Text AdjOptions_Text(UIFont, "Adjust Options");
const int MENUOPTIONS_LEN = 3;
std::array<sf::Text*, MENUOPTIONS_LEN> arr_Menu = { &NewGame_Text, &ContinueGame_Text, &AdjOptions_Text };
bool menu_looparound = false;
float menuScroll_WaitTime = 0.2f;
float menuScroll_Timer = 0;

int menu_selected = -1; // what pressing confirm selects

int TitleScreen::OnChangeToScene()
{
	mainWindow->setTitle("Title Screen");
	return 0;
}

int TitleScreen::LoadScene() {
	OnChangeToScene();
	std::cout << "Loading Title Screen...\n";
	std::cout << "Title screen loaded.\n";
	return 0;
}

// Prepare the scene layout
int TitleScreen::InitScene() {
	
	titleText.setFillColor(sf::Color::White);
	titleText.setPosition({ mainWindow->getSize().x/2.f, 100.f});
	titleText.setCharacterSize(60);
	// Justify = center
	auto bounds = titleText.getLocalBounds();
	titleText.setOrigin({bounds.position.x + bounds.size.x / 2.f, bounds.position.y + bounds.size.y / 2.f});

	pressAnyKey_Text.setFillColor(sf::Color::White);
	pressAnyKey_Text.setPosition({ mainWindow->getSize().x / 2.f, 200.f });
	pressAnyKey_Text.setCharacterSize(30);
	pressAnyKey_Text.setOrigin({ pressAnyKey_Text.getLocalBounds().position.x + pressAnyKey_Text.getLocalBounds().size.x / 2.f, pressAnyKey_Text.getLocalBounds().position.y + pressAnyKey_Text.getLocalBounds().size.y / 2.f});
	
	NewGame_Text.setFillColor(sf::Color::White);
	NewGame_Text.setPosition({ mainWindow->getSize().x / 2.f, 300.f });
	NewGame_Text.setCharacterSize(30);
	NewGame_Text.setOrigin({ NewGame_Text.getLocalBounds().position.x + NewGame_Text.getLocalBounds().size.x / 2.f, NewGame_Text.getLocalBounds().position.y + NewGame_Text.getLocalBounds().size.y / 2.f });

	ContinueGame_Text.setFillColor(sf::Color::White);
	ContinueGame_Text.setPosition({ mainWindow->getSize().x / 2.f, 400.f });
	ContinueGame_Text.setCharacterSize(30);
	ContinueGame_Text.setOrigin({ ContinueGame_Text.getLocalBounds().position.x + ContinueGame_Text.getLocalBounds().size.x / 2.f, ContinueGame_Text.getLocalBounds().position.y + ContinueGame_Text.getLocalBounds().size.y / 2.f });

	AdjOptions_Text.setFillColor(sf::Color::White);
	AdjOptions_Text.setPosition({ mainWindow->getSize().x / 2.f, 500.f });
	AdjOptions_Text.setCharacterSize(30);
	AdjOptions_Text.setOrigin({ AdjOptions_Text.getLocalBounds().position.x + AdjOptions_Text.getLocalBounds().size.x / 2.f, AdjOptions_Text.getLocalBounds().position.y + AdjOptions_Text.getLocalBounds().size.y / 2.f });

	
	return 0;
}
// Called write after clear
int TitleScreen::DrawScene(sf::RenderWindow& window)
{
	//std::cout << "In Title Screen::Draw\n";
	// debug test
	//sf::CircleShape shape(100.f);
	//shape.setFillColor(sf::Color::Red);
	//shape.setPosition(sf::Vector2f(200, 100));
	//window.draw(shape);

	// Gui step
	window.draw(titleText);
	if (!pressAnyKey_dismissed) window.draw(pressAnyKey_Text);
	else
	{
		// Adjust menu colors based on state
		for (int i = 0; i < MENUOPTIONS_LEN; i++)
		{
			if (menu_selected == i)
			{
				arr_Menu[i]->setFillColor(sf::Color(255, 255, 255, 255));
			}
			else arr_Menu[i]->setFillColor(sf::Color(255, 255, 255, 100));
		}
		window.draw(NewGame_Text);
		window.draw(ContinueGame_Text);
		window.draw(AdjOptions_Text);
	}

	// Vanilla rendering step

	return 0;
}

void TickOpacity_PressAnyKey(float deltatime)
{
	pressAnyKeyTimer += deltatime;

	// Fade cycle lasts 4 seconds
	float alpha = (std::sin(pressAnyKeyTimer * 3.14159f) + 1.f) / 4.f;

	auto opacity = static_cast<std::uint8_t>(alpha * 255.f);

	pressAnyKey_Text.setFillColor(
		sf::Color(255, 255, 255, opacity)
	);
}

// Called after events handled
int TitleScreen::UpdateScene(float deltatime)
{
	int old_menuSelected = menu_selected;
	TickOpacity_PressAnyKey(deltatime);
	if (Input.confirm_Key == 1 && !pressAnyKey_dismissed)
	{
		std::cout << "Enter key pressed!\n";
		menu_selected = 0; // now default to new game option
		pressAnyKey_dismissed = true;
		menuScroll_Timer = menuScroll_WaitTime + 1; // allow to scroll immediately
	}
	if (pressAnyKey_dismissed)
	{
		bool scrolledMenu = false;

		if (Input.move_downKey > 0 || Input.move_rightKey > 0) { 
			if (Input.move_downKey == 1 || Input.move_rightKey == 1 || menuScroll_Timer >= menuScroll_WaitTime) { // alllows if immediate press to proceed faster than timer
				menu_selected += 1;
				scrolledMenu = true;
			}// else ignore

		}
		else if (Input.move_upKey > 0 || Input.move_leftKey > 0) { 
			if (Input.move_upKey == 1 || Input.move_leftKey == 1 || menuScroll_Timer >= menuScroll_WaitTime) { // allows if justpressed even if timer not ready
				menu_selected -= 1;
				scrolledMenu = true;
			}
		}
		menuScroll_Timer += deltatime; // add to timer
		
		// Normalize
		if (menu_selected >= MENUOPTIONS_LEN) {
			if (menu_looparound) menu_selected = 0; // loop around
			else menu_selected = old_menuSelected; // do nothing
		}
		if (menu_selected < 0) { 
			if (menu_looparound) menu_selected = MENUOPTIONS_LEN - 1;
			else menu_selected = old_menuSelected;
		}

		// Set timer
		if (scrolledMenu) menuScroll_Timer = 0;

		// Check menu option selected
		if (Input.interactUse_Key == 1 || Input.confirm_Key == 1)
		{
			if (menu_selected == 0) OnNewGameSelected();
			else if (menu_selected == 1) OnContinueSelected();
			else if (menu_selected == 2) OnAdjustOptionsSelected();
		}
	}

	// Adjust menu colors


	return 0;
}

int OnNewGameSelected()
{
	return ChangeScene(SCENE_INTROTRAIN);
}

int OnContinueSelected()
{
	std::cout << "\n[Press:Continue:: Error; No game file could be found.\n";
	return 0;
}

int OnAdjustOptionsSelected()
{
	std::cout << "\n[Press:AdjustOptions]: Error: not implented yet!\n";
	return 0;
}