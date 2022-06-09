#include "Math.h"
#include "Def.h"

// Some of the required dependancies (sut up)
#include <iostream>
#include <SDL.h>
#include <SDL_image.h>
#include <SDL_mixer.h>

// Init physics
Physics::Physics(int fallVelocity, int maxVelocity)
  : fVel(fallVelocity),  mVel(maxVelocity) {}

// This function is what will make the player fall. Let's hope I didn't search anything up for this one oh god
void Physics::fall(int &x, int &y, int w, int h) {
  if (currentTick - lastTick <= 0) {
    currentTick = SDL_GetTicks() + 100;
    if (SCREENHEIGHT / 2 >= y + w) {
      y += 2;
      //std::cout << y << ", " << lastTick << ", " << currentTick << "\n";
    }
  }

  lastTick = SDL_GetTicks();
}

// this probably won't be finsihed. lmao
void Physics::checkBoxCollision() {

}
