#include <iostream>

// SDL
#include <SDL.h>
#include <SDL_image.h>
#include <SDL_mixer.h>

#include "Entity.h"

// A simple entity initializer. Entities are going to dominate the entirety of the game lmao
Entity::Entity(SDL_Texture* texture, double x, double y)
  : entityX(x), entityY(y), entityTexture(texture)
{
  hitBox.x = 0;
  hitBox.y = 0;
  hitBox.w = 64;
  hitBox.h = 64;
}

// get the x axis of our entity. So we don't have to make the variable public and deal with a bunch of funky errors and unexpected behaviours
double Entity::getX() {
  return entityX;
}

// Get the privated y axis of the entity class
double Entity::getY() {
  return entityY;
}

// Get the selected texture of the entity
SDL_Texture* Entity::getTexture() {
  return entityTexture;
}

// Recieve the hitbox of the sprite, which holds the width, height, and x,y position.
SDL_Rect Entity::getHitbox() {
  return hitBox;
}

// A simple fall script
void Entity::fall() {
  if (entityY <= 311) {
    entityY += .1;
    std::cout << entityY << "\n";
  }
}

// Reset the character's x and y position
void Entity::reset() {
  entityY = 0;
  entityX = 0;
}