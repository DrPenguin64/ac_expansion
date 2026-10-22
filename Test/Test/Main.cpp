

#include <iostream>
#include <SFML/Graphics.hpp>
#include "Global.h"
#include "Scene.h"
#include "Save.h"
#include "Session.h"
#include "Registry.h"
#include "GUI_Fonts.h"
#include "Input.h"

sf::RenderWindow* mainWindow;

int LoadGlobalAssets() // fonts etc
{
    LoadFonts();
    return 0;
}

int LoadSaveData()
{
    return 0;
}

int InitGame()
{
    //std::cout << "Testing testing 123...\n";
    std::cout << "Checking for save data...\n";
    int saveDataExists = LoadSaveData();
    if (saveDataExists) {}
    else std::cout << "No save data found.\n";
    InitRegistry();
    std::cout << "Starting game...\n";


    return 0;
}

int main()
{
    mainWindow = new sf::RenderWindow(sf::VideoMode({ 800, 600 }), "SFML Test");
    sf::RenderWindow& window = *mainWindow;
    sf::Clock deltaClock;

    LoadGlobalAssets();
    InitGame();

    // Change Scene
    if (ChangeScene(SCENE_TITLE) == -1)
    {
        std::cout << "Error! Failed to load title screen, null ptr\n";
    }
    while (window.isOpen())
    {
        // Get time since last frame
        float deltaTime = deltaClock.restart().asSeconds();
        // Todo: Record input events
        UpdateInputEvents();

        CurrentScene()->UpdateScene(deltaTime);
        window.clear();
        //window.draw(shape);
        CurrentScene()->DrawScene(window);
        
        window.display();
    }


    return 0;
}
