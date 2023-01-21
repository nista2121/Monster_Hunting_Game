///***************************************************************************************
/// Game.hpp
///
/// Created on: Jan 20, 2023
///     Author: s2121m
///
///***************************************************************************************
#ifndef PLAYERACTION_HPP_
#define PLAYERACTION_HPP_

#include <iostream>
#include <string>
#include <string_view>

/// Game class
class PlayerAction
{
public:

   ///PlayerAction ctor
   PlayerAction(const std::string& playerName);
   /// Display Game Introduction to players
   void greatingPlayer( const std::string & name);

   /// Get the enemy distance
   /// @return distance which is random number
   int getEnemyDistance();
   /// Get the player input
   /// @return player input;
   int getPlayerInput();

   /// Calculate player shot from the distance
   /// @ return the distance of the shot from the target distance
   int processShot(int angle);

   /// Check if player hit the target.
   int hitEnemy(int enemyLoc);

   int getCount() {  return count; }

   virtual ~PlayerAction();

   /// Nested class that format word to bold;
   class Bold
   {

   public:
      Bold (std::string const &s) : word(s) {}

      friend std::ostream& operator<<(std::ostream &os, Bold const &b)
      {
         os << "\x1b[1m" << b.word << "\x1b[0m";
         return os;
      }
   private:
      std::string const &word;
   }; //end inner class

private:
    const std::string playerName;
    int count = 0;

};

#endif /* PLAYERACTION_HPP_ */
