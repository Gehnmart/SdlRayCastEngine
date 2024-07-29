#include "../includes/source.h"

bool window_init(window_t *window) {
  bool retval = true;

  if (SDL_Init(SDL_INIT_VIDEO) < 0) {
    fprintf(stderr, "SDL_Init(): %s\n", SDL_GetError());
    retval = false;
  } else {
    window->sdl_window = SDL_CreateWindow("SdlRayCasEngine", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, window->screen_width, window->screen_height, SDL_WINDOW_SHOWN);
    if (window->sdl_window == NULL) {
      fprintf(stderr, "SDL_CreateWindow(): %s\n", SDL_GetError());
      retval = false;
    } else {
      window->screen_renderer = SDL_CreateRenderer(window->sdl_window, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);
      if (window->screen_renderer == NULL) {
        fprintf(stderr, "SDL_CreateRenderer(): %s\n", SDL_GetError());
        retval = false;
      } else {
        SDL_SetRenderDrawColor(window->screen_renderer, 0xFF, 0xFF, 0xFF, 0xFF);

        int imgFlags = IMG_INIT_PNG;
        if (!(IMG_Init(imgFlags) & imgFlags)) {
          fprintf(stderr, "IMG_Init(): %s\n", IMG_GetError());
          retval = false;
        }
      }
    }
  }

  return retval;
}