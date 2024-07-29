#include "includes/source.h"

int main() {
  SDL_Renderer *screen_renderer;
  SDL_Window *sdl_window;
  game_t game = {0};
  game.window.screen_height = SCREEN_HEIGHT;
  game.window.screen_width  = SCREEN_WIDTH;
  game.window.sdl_window = sdl_window;
  game.window.screen_renderer = screen_renderer;

  if (window_init(&game.window)) {
    SDL_SetRelativeMouseMode(SDL_TRUE);
    start_game(&game);
  }
  
  exit(EXIT_SUCCESS);
}