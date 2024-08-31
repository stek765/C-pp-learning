/* inclusione condizionale o guardia d'inclusione:

#ifndef GAME_HPP
#define GAME_HPP

contenuto..

// #endif
*/

// Alternativa moderna
#pragma once

#include <SFML/Graphics.hpp>
#include <vector>

class Game {
public:
    Game();
    void run();
    
private:
    void processEvents();
    void update();
    void render();
    void handlePlayerInput(sf::Keyboard::Key key);
    void checkWinCondition();

    sf::RenderWindow mWindow;
    sf::RectangleShape mGrid[3][3];
    std::vector<std::vector<char>> mBoard;
    int currentPlayer;
    bool isGameOver;

    int winningLine[3]; // Store the indices of the winning line
    char winner; // Store the winner ('X' or 'O')
};


