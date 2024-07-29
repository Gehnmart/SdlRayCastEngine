#ifndef STRUCTS_H
#define STRUCTS_H

#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>

typedef struct {
  SDL_Renderer *screen_renderer;
  SDL_Window *sdl_window;
  int screen_width;
  int screen_height;
} window_t;

typedef struct {
  window_t window;
  SDL_Event event;
  bool quit;
} game_t;

#endif //STRUCTS_H