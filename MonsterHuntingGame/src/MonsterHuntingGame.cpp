//============================================================================
// Name        : MonsterHuntingGame.cpp
// Author      : Stanislas Mbengue
// Version     : v1.0
// Copyright   :  Apache License 
// Description : !!!Monster Hunting Game, where a monster appear an a random area,
//                and has ten shot to kill the monster!!! Monster Hunting Game,
//                where a monster appear an a random area, and has ten shot to kill the monster!!!
//============================================================================

#include <iostream>
#include <string>
#include <vector>
#include "PlayerAction.hpp"


int main()
{
   const std::string playerName = "KillMonster_Gololo";
	PlayerAction  player(playerName);
	player.greatingPlayer(playerName);
	int enemyLoc = player.getEnemyDistance();

	std::cout<< "The enemy is " <<  enemyLoc << " feet away " << std::endl;
	int kill    = 0;
	int numKill = 0;
	char exitGame;

   do
   {
      kill = player.hitEnemy(enemyLoc);
      if(kill > 0)
      {
       numKill++;
      }
      std::cout<< "You have killed: "<< numKill <<  " monster(s)" << std::endl;
      std::cout << "Do you want to play again (y/n) " << std::endl;
      std::cin>> exitGame;
   }
   while ( exitGame != 'n');

	return 0;
}
