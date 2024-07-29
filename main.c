#include "includes/source.h"

int main() {
  game_t game = {0};
  game.window.screen_height = SCREEN_HEIGHT;
  game.window.screen_width  = SCREEN_WIDTH;

  if (window_init(&game.window)) {
    while(!game.quit) {
      while(SDL_PollEvent(&game.event) != 0){
        if(game.event.type == SDL_QUIT){
          game.quit = true;
        }
      }
    }
  }
  
  exit(EXIT_SUCCESS);
}