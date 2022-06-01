#pragma once

// The entity class
class Entity {
public:
  Entity(SDL_Texture* texture, int x, int y);

  int getX();
  int getY();
  void reset();

  SDL_Texture* getTexture();
  SDL_Rect getHitbox();

private:
  int entityX, entityY;

  SDL_Texture* entityTexture;
  SDL_Rect hitBox;
};


// Should I make a special player class? Idk man. I was thinking of just making him an entity, but I don't want to code all of the player movement and such inside of the entity class
class Player {
public:
  Player(SDL_Texture* tex, int x, int y);

  SDL_Texture* getTexture();

private:
  // mostly used for getting the current width and height of the player, as well as animating
  SDL_Rect hitBox;

  // Just the texture of the player
  SDL_Texture* texture;

  // The x and y of the player, lets movement happen.
  int playerX, playerY;

  // This takes input from the keyboard and such
  SDL_Event event;
};