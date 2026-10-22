#include "Input.h"
#include "Global.h"

Inputs Input;

void UpdateInputEvents()
{
    sf::RenderWindow& window = *mainWindow;

    // Advance previous frame's states
    auto advance = [](int& key)
        {
            if (key == 1)  key = 2;  // Just pressed -> held
            if (key == -1) key = 0;  // Just released -> up
        };

    advance(Input.move_upKey);
    advance(Input.move_downKey);
    advance(Input.move_leftKey);
    advance(Input.move_rightKey);
    advance(Input.confirm_Key);
    advance(Input.interactUse_Key);
    advance(Input.cancel_Key);

    while (const std::optional event = window.pollEvent())
    {
        if (event->is<sf::Event::Closed>())
        {
            window.close();
        }
        else if (const auto* keyPressed =
            event->getIf<sf::Event::KeyPressed>())
        {
            // Ignore key-repeat events
            if (keyPressed->scancode == sf::Keyboard::Scancode::Up)
                if (Input.move_upKey == 0)
                    Input.move_upKey = 1;

            if (keyPressed->scancode == sf::Keyboard::Scancode::Down)
                if (Input.move_downKey == 0)
                    Input.move_downKey = 1;

            if (keyPressed->scancode == sf::Keyboard::Scancode::Left)
                if (Input.move_leftKey == 0)
                    Input.move_leftKey = 1;

            if (keyPressed->scancode == sf::Keyboard::Scancode::Right)
                if (Input.move_rightKey == 0)
                    Input.move_rightKey = 1;

            if (keyPressed->scancode == sf::Keyboard::Scancode::Enter)
                if (Input.confirm_Key == 0)
                    Input.confirm_Key = 1;

            if (keyPressed->scancode == sf::Keyboard::Scancode::Z)
                if (Input.interactUse_Key == 0)
                    Input.interactUse_Key = 1;

            if (keyPressed->scancode == sf::Keyboard::Scancode::C)
                if (Input.cancel_Key == 0)
                    Input.cancel_Key = 1;
        }
        else if (const auto* keyReleased =
            event->getIf<sf::Event::KeyReleased>())
        {
            if (keyReleased->scancode == sf::Keyboard::Scancode::Up)
                Input.move_upKey = -1;

            if (keyReleased->scancode == sf::Keyboard::Scancode::Down)
                Input.move_downKey = -1;

            if (keyReleased->scancode == sf::Keyboard::Scancode::Left)
                Input.move_leftKey = -1;

            if (keyReleased->scancode == sf::Keyboard::Scancode::Right)
                Input.move_rightKey = -1;

            if (keyReleased->scancode == sf::Keyboard::Scancode::Enter)
                Input.confirm_Key = -1;

            if (keyReleased->scancode == sf::Keyboard::Scancode::Z)
                Input.interactUse_Key = -1;

            if (keyReleased->scancode == sf::Keyboard::Scancode::C)
                Input.cancel_Key = -1;
        }
    }
}