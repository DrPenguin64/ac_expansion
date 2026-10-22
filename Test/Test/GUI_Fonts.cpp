#include "GUI_Fonts.h"
#include <filesystem>
#include <iostream>

sf::Font UIFont;

int LoadFonts()
{
    const std::filesystem::path path =
        std::filesystem::current_path() / "assets" / "fonts" / "arial.ttf";

    //std::cout << "Font path: " << path.string() << '\n';
    //std::cout << "Exists: " << std::filesystem::exists(path) << '\n';


    if (!UIFont.openFromFile(path.string()))
    {
        std::cerr << "Failed to load font!\n";
        return 1;
    }
    else std::cout << "arial.ttf loaded.\n";

    return 0;
}
// Load all fonts needed by the game here

/*
int LoadFonts()
{
    std::cout << "Loading fonts...\n";
    if (!UIFont.openFromFile("assets/fonts/arial.ttf"))
    {
        std::cerr << "Failed to load font: UIFont[arial]\n";
        return 1;
    }
    else std::cout << "arial.ttf loaded.\n";
}*/