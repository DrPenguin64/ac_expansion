#pragma once
#include "Scene.h"
#include <SFML/Graphics.hpp>


class TitleScreen : public Scene
{
	//TitleScreen(int sid) : Scene(int sid) {}
	int OnChangeToScene() override;
	int LoadScene() override;
	int InitScene() override;
	int DrawScene(sf::RenderWindow&) override;
	int UpdateScene(float deltatime) override;
};

int OnNewGameSelected();
int OnContinueSelected();
int OnAdjustOptionsSelected();