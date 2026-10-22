#pragma once
#include <iostream>
#include <SFML/Graphics.hpp>
#include "Global.h"
#include "Scene.h"
#include "GUI_Fonts.h"
#include "Dialog_IO.h"

class Scene_IntroTrain : public Scene
{
	//TitleScreen(int sid) : Scene(int sid) {}
	int OnChangeToScene() override;
	int LoadScene() override;
	int InitScene() override;
	int DrawScene(sf::RenderWindow&) override;
	int UpdateScene(float deltatime) override;
};