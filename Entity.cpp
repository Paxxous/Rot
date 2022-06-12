#include <iostream>

// SDL
#include <SDL.h>
#include <SDL_image.h>
#include <SDL_mixer.h>
#include <vector>

#include "Entity.h"
#include "Math.h"

/* This is for entities, a universal class. Not the player class, which has its own special parts. */

// A simple entity initializer. Entities are going to dominate the entirety of the game lmao
Entity::Entity(SDL_Texture* texture, int currentFrame, int x, int y, int w, int h)
  : entityX(x), entityY(y), entityW(w), entityH(h), entityTexture(texture)
{
  hitBox.x = 0;
  hitBox.y = 0;
  hitBox.w = entityW;
  hitBox.h = entityH;
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
  hitBox.x = 128;
}

// smh my head
void Entity::animate(int frames, int strip, int speed, int w, int h) {  
  // std::cout << currentFrame << ", " << (SDL_GetTicks() / speed) % frames << "\n";

  currentFrame += 1;

  hitBox.x = /* I really hate using code that I don't completely understand */ (SDL_GetTicks() / speed) % frames * 64;
  hitBox.y = strip * 64;


  // std::cout << hitBox.x << ", " << hitBox.y << currentFrame << "\n";

  if (currentFrame > frames) {
    currentFrame = 1;
  }

}


/* The player class, a special type of entity that is controlled by you, and interacts with the world around it. */

Player::Player(SDL_Texture* tex, int x, int y, int fVelocity, int mVelocity)
  : texture(tex), playerX(x), playerY(y), physics(fVelocity, mVelocity)
{
  hitBox.x = 0;
  hitBox.y = 0;
  hitBox.w = 64;
  hitBox.h = 64;
}

void Player::animate(int frames, int strip, int speed, int w, int h) {
  currentFrame += 1;

  hitBox.x = (SDL_GetTicks() / speed) % frames * 64;
  hitBox.y = strip * 64;


  if (currentFrame > frames) {
    currentFrame = 1;
  }

}

// Get the player texture
SDL_Texture* Player::getTexture() {
  return texture;
}

SDL_Rect Player::getHitbox() {
  return hitBox;
}

// I don't knwo how to do physics :((((( {But I do think I know how to create falling, so let's do that.}
void Player::doFall() {
  physics.fall(playerX, playerY);
}

// Handle the input from the keyboard
void Player::handleInput() {
  currentTick = SDL_GetTicks();

  // Right
  if (keyStates[SDL_SCANCODE_D] && currentTick >= lastTick) {
    playerX += 1;
    std::cout << "Right\n";
    lastTick = SDL_GetTicks();
  }

  // Left
  else if (keyStates[SDL_SCANCODE_A] && currentTick >= lastTick) {
    playerX -= 1;
    std::cout << "Left\n";
    lastTick = SDL_GetTicks();
  }
}