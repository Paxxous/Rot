#pragma once
#include <SDL_timer.h>

// I'm just doing falling rn
class Physics {
public:
  Physics(int fallVelocity, int maxVelocity);

  void fall(int& x, int& y, int w = 64, int h = 64);
  void checkBoxCollision();
private:
  // fVel, the amount added as you fall. Mvel, the max cap of velocity that stops you. So you don't go super speed and break the game lol.
  int fVel, mVel;
  int currentTick = SDL_GetTicks();
  int lastTick = SDL_GetTicks();
};