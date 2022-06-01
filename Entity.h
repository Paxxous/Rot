#pragma once

// The entity class
class Entity {
public:
  Entity(SDL_Texture* texture, double x, double y);

  double getX();
  double getY();
  void fall();
  void reset();

  SDL_Texture* getTexture();
  SDL_Rect getHitbox();

private:
  double entityX;
  double entityY;

  SDL_Texture* entityTexture;
  SDL_Rect hitBox;
};