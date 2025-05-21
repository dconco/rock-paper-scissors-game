#include <iostream>

/**
 * Logic for playing Game
 *
 * @param char playerGame
 * @param char computerGame
 */
bool playGame(char playerGame, char computerGame);

/**
 * Generate Computer Random Game
 */
char generateComputerGame();

/**
 * Format Game from char to string
 *
 * @param char shortForm
 * @return Formatted string
 */
std::string formatGame(char shortForm);

void showResult();