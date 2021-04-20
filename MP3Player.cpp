//
// Created by Chris Hartman on 4/27/20.
//

#include "MP3Player.hpp"

MP3Player::~MP3Player()=default;

void MP3Player::setState(std::unique_ptr<MP3PlayerState> newState) {
   _state = std::move(newState);
}

MP3Player::MP3Player()
   :_state(std::make_unique<Off>())
{}

void MP3Player::pushSourceButton() {
   _state->pushSourceButton(*this);
}

void MP3Player::pushNextButton() {
   _state->pushNextButton(*this);
}

void MP3Player::playRadio() {
   std::cout << "Playing the radio.\n";
}

void MP3Player::stopRadio() {
   std::cout << "Stopping the radio.\n";
}

void MP3Player::nextRadioStation() {
   std::cout << "Next radio station.\n";
}

void MP3Player::playMp3() {
   std::cout << "Playing MP3.\n";
}

void MP3Player::stopMp3() {
   std::cout << "Stopping MP3.\n";
}

void MP3Player::nextMp3() {
   std::cout << "Next MP3.\n";
}
