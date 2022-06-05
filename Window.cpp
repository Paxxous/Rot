#include <iostream>

// SDL
#include <SDL.h>
#include <SDL_image.h>
#include <SDL_mixer.h>

#include "Window.h"
#include "Entity.h"


Window::Window(const char* wTitle, int wHeight, int wWidth)
  : WINDOW_HEIGHT(wHeight), WINDOW_WIDTH(wWidth), WINDOW_TITLE(wTitle)
{
  mainWindow = SDL_CreateWindow(WINDOW_TITLE, SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, WINDOW_WIDTH, WINDOW_HEIGHT, SDL_WINDOW_SHOWN);

  // Initialize most of the stuff in SDL.h
  if (SDL_Init(SDL_INIT_EVERYTHING) > 0) {
    std::cout << "lmao there was an issue initializing sdl,\n" << SDL_GetError() << "\n";
  }

  // Initialize hardware gpu rendering
  renderer = SDL_CreateRenderer(mainWindow, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);
  if (renderer == NULL) {
    std::cout << "smh... There was an error when creating a renderer...\n" << SDL_GetError() << "\n";
  }
}


// Set the window background color
void Window::windowColor(int r, int g, int b, int a) {
  SDL_SetRenderDrawColor(renderer, r, g, b, a);
}

// Completely clear the game screen
void Window::clear() {
  SDL_RenderClear(renderer);
}

// Completely deallocate everything once the game ends. So that no strang errors occur
void Window::clean() {
  SDL_DestroyWindow(mainWindow);
}

// Show everything on the screen (may be fixing your issue that you had with the rising memory and cpu [goofy ahh data leaks])
void Window::show() {
  SDL_RenderPresent(renderer);
}

// Load the texture. Doesn't show the window to the screen, we'll have to do that with a small entity class. You know what that requires? And entity texture to go along with it. So I know what to do now :D.
SDL_Texture* Window::loadTexture(const char* path) {
  SDL_Texture* loadedIMG = IMG_LoadTexture(renderer, path);
  if (loadedIMG == NULL) {
    std::cout << "Damn bro, there seems to be a problem rendering something there\n" << SDL_GetError() << "\n";

    loadedIMG = IMG_LoadTexture(renderer, "res/gfx/Debug/Missing-Texture.png");
  }

  return loadedIMG;
}

// Render an entity to the screen, with two SDL_Rects.
void Window::render(Entity& ent) {
  SDL_Rect src;
  src.x = ent.getHitbox().x;
  src.y = ent.getHitbox().y;
  src.w = ent.getHitbox().w;
  src.h = ent.getHitbox().h;

  SDL_Rect dst;
  dst.x = ent.getX() * 2;
  dst.y = ent.getY() * 2;
  dst.w = ent.getHitbox().w * 2;
  dst.h = ent.getHitbox().h * 2;

  SDL_RenderCopy(renderer, ent.getTexture(), &src, &dst);
}

// Using function overloading because this seems to be the best method :DD
void Window::render(Player& player) {
  SDL_Rect src;
  src.x = player.getHitbox().x;
  src.y = player.getHitbox().y;
  src.w = player.getHitbox().w;
  src.h = player.getHitbox().h;

  SDL_Rect dst;
  dst.x = player.getX() * 2;
  dst.y = player.getY() * 2;
  dst.w = player.getHitbox().w * 2;
  dst.h = player.getHitbox().h * 2;

  SDL_RenderCopy(renderer, player.getTexture(), &src, &dst);
}

// Just literally render a texture to the screen. Don't do this, this is just a little debug function.
void Window::showTexture(SDL_Texture* texture) {
  SDL_RenderCopy(renderer, texture, NULL, NULL);
}