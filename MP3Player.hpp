//
// Created by Chris Hartman on 4/27/20.
//

#ifndef CS372SPRING2021EXAMPLECODE_MP3PLAYER_HPP
#define CS372SPRING2021EXAMPLECODE_MP3PLAYER_HPP
#include "MP3PlayerState.hpp"

#include <iostream>
#include <memory>

class MP3Player {
   friend class MP3PlayerState;
public:
   virtual ~MP3Player();
   explicit MP3Player();
   void pushNextButton();
   void pushSourceButton();

private:
   void setState(std::unique_ptr<MP3PlayerState> newState);
   static void playRadio();
   static void stopRadio();
   static void nextRadioStation();
   static void playMp3();
   static void stopMp3();
   static void nextMp3();

   std::unique_ptr<MP3PlayerState> _state;
};

#endif  // CS372SPRING2021EXAMPLECODE_MP3PLAYER_HPP
