#pragma once


class Window {
public:
  Window(const char* wTitle, int wHeight, int wWidth);

  void windowColor(int r, int g, int b, int a);
  void clear();
  void clean();
  void show();

  SDL_Texture* loadTexture(const char* path);
  void showTexture(SDL_Texture* texture); // mostly for debug purposes

private:
  // Width and height of the window once it's rendered
  int WINDOW_HEIGHT;
  int WINDOW_WIDTH;
  const char* WINDOW_TITLE;

  SDL_Window* mainWindow = nullptr;
  SDL_Renderer* renderer = nullptr;
};