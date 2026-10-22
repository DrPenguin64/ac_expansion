#include "Global.h"
#include "Scene.h"
// Scenes to include
#include "TitleScreen.h"
#include "Scene_IntroTrain.h"

// Scene
Scene* Table_Scenes[16]{};

void InitRegistry()
{
	Table_Scenes[SCENE_TITLE] = new TitleScreen();
	Table_Scenes[SCENE_INTROTRAIN] = new Scene_IntroTrain();
	// scene 1 = train
}
