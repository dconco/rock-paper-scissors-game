#include <iostream>
#include <random>
#include <ctime>
#include "algo.hxx"

using namespace std;

int main()
{
   cout << "===========================================================" << endl;
   cout << "           ROCK PAPER SCISSORS GAME BY DCONCO" << endl;
   cout << "===========================================================" << endl
        << endl;
   cout << "'r' - Rock" << endl;
   cout << "'p' - Paper" << endl;
   cout << "'s' - Scissors" << endl;

   bool error{false};

   do
   {
      char computerGame{generateComputerGame()};
      char playerGame;

      cout << endl
           << "Choose your Game: ";
      cin >> playerGame;

      error = playGame(playerGame, computerGame);
      playerGame = {};
   } while (error);

   return 0;
}

bool playGame(char playerGame, char computerGame)
{
   string formattedGame{formatGame(computerGame)};

   string loseASCII = R"(
   __     ______  _    _    _      ____   _____ ______ 
   \ \   / / __ \| |  | |  | |    / __ \ / ____|  ____|
    \ \_/ / |  | | |  | |  | |   | |  | | (___ | |__   
     \   /| |  | | |  | |  | |   | |  | |\___ \|  __|  
      | | | |__| | |__| |  | |___| |__| |____) | |____ 
      |_|  \____/ \____/   |______\____/|_____/|______|
   )";

   string winASCII = R"(
   __   _____  _   _   __        _____ _   _ 
   \ \ / / _ \| | | |  \ \      / /_ _| \ | |
    \ V / | | | | | |   \ \ /\ / / | ||  \| |
     | || |_| | |_| |    \ V  V /  | || |\  |
     |_| \___/ \___/      \_/\_/  |___|_| \_|                                 
   )";

   string drawASCII = R"(
   ____  ____      ___        __
  |  _ \|  _ \    / \ \      / /
  | | | | |_) |  / _ \ \ /\ / / 
  | |_| |  _ <  / ___ \ V  V /  
  |____/|_| \_\/_/   \_\_/\_/                        
   )";

   switch (playerGame)
   {
   case 'r':
      cout << "You choosed 'Rock'" << endl;
      cout << "Computer choosed '" << formattedGame << "'";

      switch (computerGame)
      {
      case 'r':
         cout << drawASCII;
         break;
      case 'p':
         cout << loseASCII;
         break;
      case 's':
         cout << winASCII;
         break;
      }
      break;

   case 'p':
      cout << "You choosed 'Paper'" << endl;
      cout << "Computer choosed '" << formattedGame << "'";

      switch (computerGame)
      {
      case 'r':
         cout << winASCII;
         break;
      case 'p':
         cout << drawASCII;
         break;
      case 's':
         cout << loseASCII;
         break;
      }
      break;

   case 's':
      cout << "You choosed 'Scissors'" << endl;
      cout << "Computer choosed '" << formattedGame << "'";

      switch (computerGame)
      {
      case 'r':
         cout << loseASCII;
         break;
      case 'p':
         cout << winASCII;
         break;
      case 's':
         cout << drawASCII;
         break;
      }
      break;

   default:
      cout << "You can only choose either r, p or s."
           << endl;
   }

   return true;
}

char generateComputerGame()
{
   std::random_device rd;
   std::mt19937 generator(rd());
   std::uniform_int_distribution<int> dist(1, 3);
   int randomGuess = dist(generator);

   switch (randomGuess)
   {
   case 1:
      return 'r';
   case 2:
      return 'p';
   case 3:
      return 's';
   }

   return 0;
}

string formatGame(char shortForm)
{
   switch (shortForm)
   {
   case 'r':
      return "Rock";
   case 'p':
      return "Paper";
   case 's':
      return "Scissors";
   }

   return 0;
}