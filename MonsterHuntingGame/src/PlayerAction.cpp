///***************************************************************************************
/// Game.hpp
///
/// Created on: Jan 20, 2023
///     Author: s2121m
///
///*

#include <math.h>
#include <time.h>
#include "PlayerAction.hpp"

constexpr int    playTime        = 10;     // number of time to play the game
constexpr int    mininumDistatce = 100;    // min distance for a target
constexpr int    maximunDistnace = 1000;   // max distance for a target
constexpr double velocity        = 200.0;  // initial velocity of 200 ft/sec
constexpr double gravity         = 32.2;   // gravity for distance calculation
constexpr double PI              = 3.1415;

PlayerAction::PlayerAction(const std::string& name) : playerName(name)
{
   /// nothing for now
}

PlayerAction::~PlayerAction()
{
   /// empty
}

void PlayerAction::greatingPlayer(const std::string& name)
{

   std::cout
            << "Welcome to Monster Hunting Farm "<< name
			<< "\nYou are in the middle on an abandon farm occupied by 100 of monster "
			<<  "where they can randomly appear at any distance from your location."
            << "\nYou have one cannon, which you can shoot at any angle. to kill the monster. "
            << "\nYou only have 10 cannon balls for a given target.. "
            << "\nLet's begin... "
            << std::endl;
}

int PlayerAction::getEnemyDistance()
{
   //Generate a random number from the enemy position

   srand(time(NULL));
   int distance = rand() % maximunDistnace + mininumDistatce;
   return distance;
}

int PlayerAction::getPlayerInput()
{
   std::cout << "What angle do you want to shot: ";
   int angle;
   if (!(std::cin >> angle))
   {
      return -1;
   }

   int rad = 180.0;
   return static_cast<int>((angle * PI) / rad);
}
int PlayerAction::processShot(int angle)
{

   double time_in_air = (2.0 * velocity * sin(angle)) / gravity;
   int distance = round((velocity * cos(angle) * time_in_air));

   return distance;

}
int PlayerAction::hitEnemy(int enemyLoc)
{
   std::cout<< "The enemy is " <<  enemyLoc << " feet away " << std::endl;
   int input = getPlayerInput();
   int angle = processShot(input);

   //TODO NEED TO REFACTOR THIS LINE OF CODE.
   // check user input are valid
//   if (input == 1)
//   {
//      std::cout << "Enter a valid numbers only..." << std::endl;
//      std::cin.clear();
//      std::cin.ignore(10000, '\n');
//      input = getPlayerInput();
//   }

   while(angle != enemyLoc)
     {
        count++;  // count the number of shot playTime
        if(angle > enemyLoc)
        {
           std::cout << "You shot over by " << abs(angle - enemyLoc) << std::endl;
        }
        else
        {
           std::cout << "You shot under by " << abs(angle - enemyLoc) << std::endl;
        }
        if(count == playTime) // exit if player missed the target more than 5 time.
        {
           angle = 0;  // Indicate that layer lost the game;
           count = 0;
           break;
        }
        input = getPlayerInput(); // get another input from the user
        angle = processShot(input);
     }

   return angle;
}


