#include <iostream>
#include <SDL.h>
#include <SDL_image.h>
#include <SDL_mixer.h>

#include "Window.h"
#include "Game.h"


/*
 THIS IS WHERE ALL OF THE SHIT HAPPENS

 You see, I wouldn't like to cram everything in main.cpp, now, would I?
 I want organized code, so that's what I'm going to do. This is a very special, because it essentially holds the entirety of the game.
 Also I want to try and hack this game once I'm done with it. So that'll be cool
 Now it's time to blit some images :DDD

 5/27/2022: We've made a git repo :DDD Hello github <3
*/

void game() {

  Window mainWindow("Rot", 640, 960);


  // Begin the main game loop:
  bool running = true;

  // Initialize all of the textures
  SDL_Texture* you = mainWindow.loadTexture("res/Sprites/you.png");

  SDL_Event e;
  while (running) {
    while (SDL_PollEvent(&e) > 0) {
      if (e.type == SDL_QUIT) {
        running = false;
      }
    }

    // Set the window color
    mainWindow.clear();
    mainWindow.windowColor(255, 255, 255, 255);

    // Load you to the screen    
    mainWindow.showTexture(you);

    // Display
    mainWindow.show();
  }

  // Deallocate everything once all is done
  mainWindow.clean();
}