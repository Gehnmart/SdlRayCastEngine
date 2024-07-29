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
  unsigned long old_time;
  unsigned long new_time;
} framerate_t;

typedef struct {
  bool w, a, s, d;
  bool space;
  int mouse_x, new_mouse_x;
} input_t;

typedef struct {
  double posx, posy;
} camera_t;

typedef struct {
  double posx, posy;
  double dirx, diry;
  double move_speed;
  double sensitivity;
  input_t input;
  camera_t camera;
} player_t;

typedef struct {
  window_t window;
  SDL_Event event;
  player_t player;
  framerate_t framerate;
  bool quit;
} game_t;

#endif //STRUCTS_H