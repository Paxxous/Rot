#include <iostream>

// SDL
#include <SDL.h>
#include <SDL_image.h>
#include <SDL_mixer.h>

#include "Entity.h"

/* This is for entities, a universal class. Not the player class, which has its own special parts. */

// A simple entity initializer. Entities are going to dominate the entirety of the game lmao
Entity::Entity(SDL_Texture* texture, int x, int y)
  : entityX(x), entityY(y), entityTexture(texture)
{
  hitBox.x = 0;
  hitBox.y = 0;
  hitBox.w = 64;
  hitBox.h = 64;
}

// get the x axis of our entity. So we don't have to make the variable public and deal with a bunch of funky errors and unexpected behaviours
int Entity::getX() {
  return entityX;
}

// Get the privated y axis of the entity class
int Entity::getY() {
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

// Reset the character's x and y position
void Entity::reset() {
  entityY = 0;
  entityX = 0;
}


/* The player class, a special type of entity that is controlled by youand interacts with the world around it. */

Player::Player(SDL_Texture* tex, int x, int y)
  : texture(tex), playerX(x), playerY(y)
{}

// Get the player texture
SDL_Texture* Player::getTexture() {
  return texture;
}