#pragma once
#include "Scene.h"


/// Screen related
extern sf::RenderWindow* mainWindow;

// Input related


/// <summary>
/// Scene related
/// </summary>
extern Scene* Table_Scenes[16];

/////////////////////////////////
// SCENE IDS
#define SCENE_TITLE 0
#define SCENE_INTROTRAIN 1
#define SCENE_SPOTLIGHT_PREGAME 2 // for when you talk to kk/isabelle etc.
#define SCENE_PLAYERTOWN 3
#define SCENE_PLAYERHOUSE 4
#define SCENE_OTHERPLAYERHOUSE 5
#define SCENE_NPCHOUSE 6
#define SCENE_POSTOFFICE 7
#define SCENE_TOMNOOK_SHOP 8
#define SCENE_TAILOR 9
#define SCENE_MUSEUM 10
#define SCENE_TOWNHALL 11
#define SCENE_ATCITY 12
// Buildable
#define SCENE_SCHOOLHOUSE 13;
#define SCENE_GYM 14;
#define SCENE_POLICECENTER 15;
#define SCENE_CINEMA 16;
#define SCENE_HOSPITAL 17;
#define SCENE_CLINIC 18;
#define SCENE_CAFE 19;

// Secret
#define SCENE_RESETHOUSE 69;

// Maybe you can buy 'rentable building', villager can
// setup a business there?

/////////////////////////////////////////
// Villager
#define JINKAKU_LAZY 0;
#define JINKAKU_JOCK 1;
#define JINKAKU_CRAKNY 2;
#define JINKAKU_SMUG 3;
#define JINKAKU_NORMAL 4;
#define JINKAKU_PEPPY 5;
#define JINKAKU_SNOOTY 6;
#define JINKAKU_SISTERLY 7;

//////////////////////////////////////////
// Methods