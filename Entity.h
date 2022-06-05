#pragma once

#include <vector>

// The entity class
class Entity {
public:
  Entity(SDL_Texture* texture, int x, int y, int currentFrame = 1, int w = 64, int h = 64);

  // Get both of the x and y axis' without having to publicize entityX and Y
  inline int getX() {
    return entityX;
  }

  inline int getY() {
    return entityY;
  }

  // Reset the x and y axis. I don't know why I did this if I'm being honest
  void reset();
  void animate(int frames, int strip, int speed, int w = 64, int h = 64);


  SDL_Texture* getTexture();
  SDL_Rect getHitbox();

private:
  int entityX, entityY, entityH, entityW;

  SDL_Texture* entityTexture;
  SDL_Rect hitBox;

  // An animation thing
  int currentFrame = 1;
};


// Should I make a special player class? Idk man. I was thinking of just making him an entity, but I don't want to code all of the player movement and such inside of the entity class
class Player {
public:
  Player(SDL_Texture* tex, int x, int y);

  SDL_Texture* getTexture();
  SDL_Rect getHitbox();

  inline int getX() {
    return playerX;
  }

  inline int getY() {
    return playerY;
  };

private:
  // mostly used for getting the current width and height of the player, as well as animating
  SDL_Rect hitBox;

  // Just the texture of the player
  SDL_Texture* texture;

  // The x and y of the player, lets movement happen.
  int playerX, playerY;
};  