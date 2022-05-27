#include <iostream>

// SDL
#include <SDL.h>
#include <SDL_image.h>
#include <SDL_mixer.h>

#include "Window.h"
#include "Game.h"

Window::Window(const char* wTitle, int wHeight, int wWidth)
  : WINDOW_HEIGHT(wHeight), WINDOW_WIDTH(wWidth), WINDOW_TITLE(wTitle)
{
  mainWindow = SDL_CreateWindow(WINDOW_TITLE, SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, WINDOW_WIDTH, WINDOW_HEIGHT, SDL_WINDOW_SHOWN);

  // Initialize most of the stuff in SDL.h
  if (SDL_Init(SDL_INIT_EVERYTHING) > 0) {
    std::cout << "lmao there was an issue initializing sdl,\n" << SDL_GetError() << std::endl;
  }

  // Initialize hardware gpu rendering
  renderer = SDL_CreateRenderer(mainWindow, -1, SDL_RENDERER_ACCELERATED);
  if (renderer == NULL) {
    std::cout << "smh... There was an error when creating a renderer...\n" << SDL_GetError() << std::endl;
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
    std::cout << "Damn bro, there seems to be a problem rendering something there\n" << SDL_GetError() << std::endl;
  }

  return loadedIMG;
}

void Window::showTexture(SDL_Texture* texture) {
  SDL_RenderCopy(renderer, texture, NULL, NULL);
}