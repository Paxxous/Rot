#include <iostream>
#include <SDL.h>
#include <SDL_image.h>
#include <SDL_mixer.h>

#include "Window.h"
#include "Game.h"
#include "Entity.h"
#include "Screens.h"
#include "Def.h"


/*
 THIS IS WHERE ALL OF THE SHIT HAPPENS

 You see, I wouldn't like to cram everything in main.cpp, now, would I?
 I want organized code, so that's what I'm going to do. This is a very special, because it essentially holds the entirety of the game.
 Also I want to try and hack this game once I'm done with it. So that'll be cool
 Now it's time to blit some images :DDD

 5/27/2022: We've made a git repo :DDD Hello github <3
 6/1/2022 Guess what time it is ;) I've done some major changes ig... It's much more difficult coding in sdl2 than I've originally expected.
*/

void game() {

  // Create the window
  Window mainWindow("Rot", 640, 640);

  

  // Begin the main game loop:
  bool running = true;

  // Initialize you.
  SDL_Texture* youTexture = mainWindow.loadTexture(PLAYERTEXTURE);
  Entity you(youTexture, 0, 0);

  SDL_Event e;
  while (running) {
    while (SDL_PollEvent(&e) > 0) {

      // Handle exit input.
      if (e.type == SDL_QUIT) {
        running = false;
      }
    }

    // Set the window color
    mainWindow.clear();
    mainWindow.windowColor(255, 255, 255, 255);

    // Show you
    mainWindow.renderEntity(you);


    // Display everything that has occured to the screen
    mainWindow.show();
  }

  // Deallocate everything once all is done
  mainWindow.clean();
}