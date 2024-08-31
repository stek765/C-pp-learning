#include "Game.hpp"
#include <iostream>

/***********************************************
 * Costruttore: Inizializza la finestra e lo stato del gioco
 ***********************************************/
Game::Game() : mWindow(sf::VideoMode(600, 600), "Tris"), currentPlayer(1), isGameOver(false) {
    mBoard.resize(3, std::vector<char>(3, ' '));  // Inizializza la griglia vuota
    
    // Configurazione della griglia visiva
    for (int i = 0; i < 3; ++i) {
        for (int j = 0; j < 3; ++j) {
            mGrid[i][j].setSize(sf::Vector2f(200, 200));
            mGrid[i][j].setFillColor(sf::Color::White);
            mGrid[i][j].setOutlineThickness(5);
            mGrid[i][j].setOutlineColor(sf::Color::Black);
            mGrid[i][j].setPosition(j * 200, i * 200);
        }
    }
}

/***********************************************
 * Metodo principale: Esegue il loop di gioco
 ***********************************************/
void Game::run() {
    while (mWindow.isOpen()) {
        processEvents();  // Gestisce gli input dell'utente
        update();         // Aggiorna lo stato del gioco
        render();         // Disegna la griglia e i contenuti
    }
}

/***********************************************
 * Gestisce gli eventi dell'utente (input da tastiera, chiusura finestra)
 ***********************************************/
void Game::processEvents() {
    sf::Event event;
    while (mWindow.pollEvent(event)) {
        if (event.type == sf::Event::Closed) {
            mWindow.close();  // Chiude la finestra
        }
        if (!isGameOver && event.type == sf::Event::KeyPressed) {
            handlePlayerInput(event.key.code);  // Gestisce l'input del giocatore
        }
    }
}

/***********************************************
 * Aggiorna lo stato del gioco, come il controllo della vittoria
 ***********************************************/
void Game::update() {
    if (isGameOver) return;  // Se il gioco è terminato, non fare nulla
    checkWinCondition();     // Controlla se c'è un vincitore o un pareggio
}

/***********************************************
 * Disegna la griglia di gioco, le mosse dei giocatori, la linea vincente e il messaggio di vittoria
 ***********************************************/
void Game::render() {
    mWindow.clear();  // Pulisce la finestra per il nuovo frame

    sf::Font font;
    if (!font.loadFromFile("/System/Library/Fonts/Helvetica.ttc")) {
        std::cerr << "Failed to load font!" << std::endl;
        return;
    }

    // Disegna la griglia e le mosse dei giocatori
    for (int i = 0; i < 3; ++i) {
        for (int j = 0; j < 3; ++j) {
            mWindow.draw(mGrid[i][j]);

            if (mBoard[i][j] != ' ') {
                sf::Text text;
                text.setFont(font);
                text.setString(mBoard[i][j]);
                text.setCharacterSize(100);
                text.setFillColor(sf::Color::Black);
                text.setPosition(j * 200 + 50, i * 200 + 25);
                mWindow.draw(text);
            }
        }
    }

    // Disegna la linea vincente
    if (isGameOver && winner != 'D') {
        sf::Vertex line[2];
        int x1 = (winningLine[0] % 3) * 200 + 100;
        int y1 = (winningLine[0] / 3) * 200 + 100;
        int x2 = (winningLine[2] % 3) * 200 + 100;
        int y2 = (winningLine[2] / 3) * 200 + 100;

        line[0] = sf::Vertex(sf::Vector2f(x1, y1), sf::Color::Red);
        line[1] = sf::Vertex(sf::Vector2f(x2, y2), sf::Color::Red);
        mWindow.draw(line, 2, sf::Lines);
    }

    // Visualizza il messaggio di vittoria
    if (isGameOver) {
        sf::Text message;
        message.setFont(font);
        if (winner == 'D') {
            message.setString("It's a draw!");
        } else {
            message.setString("Player " + std::string(1, winner) + " wins!");
        }
        message.setCharacterSize(60);
        message.setFillColor(sf::Color::Red);
        message.setPosition(100, 250);
        mWindow.draw(message);
    }

    mWindow.display();  // Mostra tutto quello che è stato disegnato
}

/***********************************************
 * Interpreta l'input del giocatore e aggiorna la griglia di gioco
 ***********************************************/
void Game::handlePlayerInput(sf::Keyboard::Key key) {
    int row = -1, col = -1;

    switch (key) {
        case sf::Keyboard::Num7: row = 2; col = 0; break;
        case sf::Keyboard::Num8: row = 2; col = 1; break;
        case sf::Keyboard::Num9: row = 2; col = 2; break;
        case sf::Keyboard::Num4: row = 1; col = 0; break;
        case sf::Keyboard::Num5: row = 1; col = 1; break;
        case sf::Keyboard::Num6: row = 1; col = 2; break;
        case sf::Keyboard::Num1: row = 0; col = 0; break;
        case sf::Keyboard::Num2: row = 0; col = 1; break;
        case sf::Keyboard::Num3: row = 0; col = 2; break;
        default: break;
    }

    if (row != -1 && col != -1 && mBoard[row][col] == ' ') {
        mBoard[row][col] = (currentPlayer == 1) ? 'X' : 'O';  // Aggiorna la griglia con la mossa
        currentPlayer = (currentPlayer == 1) ? 2 : 1;  // Cambia il turno del giocatore
    }
}

/***********************************************
 * Controlla se c'è un vincitore o se la partita è terminata in pareggio
 ***********************************************/
void Game::checkWinCondition() {
    int winConditions[8][3] = {
        {0, 1, 2}, {3, 4, 5}, {6, 7, 8},  // Righe
        {0, 3, 6}, {1, 4, 7}, {2, 5, 8},  // Colonne
        {0, 4, 8}, {2, 4, 6}              // Diagonali
    };
    
    for (int i = 0; i < 8; i++) {
        int row1 = winConditions[i][0] / 3;
        int col1 = winConditions[i][0] % 3;
        int row2 = winConditions[i][1] / 3;
        int col2 = winConditions[i][1] % 3;
        int row3 = winConditions[i][2] / 3;
        int col3 = winConditions[i][2] % 3;

        if (mBoard[row1][col1] != ' ' && 
            mBoard[row1][col1] == mBoard[row2][col2] && 
            mBoard[row2][col2] == mBoard[row3][col3]) {
            isGameOver = true;
            winner = mBoard[row1][col1];
            winningLine[0] = winConditions[i][0];
            winningLine[1] = winConditions[i][1];
            winningLine[2] = winConditions[i][2];
            render();  // Render the final move
            return;
        }
    }

    bool isDraw = true;
    for (const auto &row : mBoard) {
        for (char cell : row) {
            if (cell == ' ') {
                isDraw = false;
            }
        }
    }
    
    if (isDraw) {
        isGameOver = true;
        winner = 'D'; // 'D' per il pareggio
        render();  // Renderizza la griglia finale
    }
}
