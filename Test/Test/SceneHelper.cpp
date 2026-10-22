
#include "Global.h"
#include "Scene.h"
#include "Session.h"

int CurrentSceneId = -1;
// Returns sceneIndex if success, else returns -1
int ChangeScene(int sceneIndex)
{
	if (Table_Scenes[sceneIndex] != nullptr) // Success
	{
		CurrentSceneId = sceneIndex;
		Table_Scenes[sceneIndex]->LoadScene();
		Table_Scenes[sceneIndex]->InitScene();
		return sceneIndex; // success
	}
	else // fail
	{
		return -1;
	}
}

int GetCurrentSceneId()
{
	return CurrentSceneId;
}

Scene* CurrentScene()
{
	return Table_Scenes[CurrentSceneId];
}

Scene::Scene(int sid)
{
	this->sceneId = sid;
}

int Scene::LoadScene()
{
	return 0;
}

int Scene::OnChangeToScene()
{
	return 0;
}


int Scene::InitScene()
{
	return 0;
}

int Scene::DrawScene(sf::RenderWindow& window)
{
	return 0;
}

int Scene::UpdateScene(float deltaTime)
{
	return 0;
}