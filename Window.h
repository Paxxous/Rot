#pragma once

#include "Entity.h"



class Window {
public:
  Window(const char* wTitle, int wHeight, int wWidth);

  void windowColor(int r, int g, int b, int a);
  void clear();
  void clean();
  void show();

  SDL_Texture* loadTexture(const char* path); // Initializing your textures and images. This'll be loaded into the entity class, or just shown to the screen (NOTE: not recommended)

  void showTexture(SDL_Texture* texture); // mostly for debug purposes
  void render(Entity& p_entity);
  void render(Player& player);

private:
  // Width and height of the window once it's rendered
  int WINDOW_HEIGHT;
  int WINDOW_WIDTH;
  const char* WINDOW_TITLE;

  SDL_Window* mainWindow;
  SDL_Renderer* renderer;
};