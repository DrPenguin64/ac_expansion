#pragma once
#include <SFML/Graphics.hpp>

class Scene
{
public:
	Scene(int sid = -1);
	virtual int LoadScene();
	virtual int InitScene();
	virtual int DrawScene(sf::RenderWindow& window);
	virtual int UpdateScene(float deltatime);
	virtual int OnChangeToScene();

	int sceneId;
};

int ChangeScene(int toScene);
int GetCurrentSceneId();
