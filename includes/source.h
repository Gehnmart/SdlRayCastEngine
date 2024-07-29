#ifndef SOURCE_H
#define SOURCE_H

#include "includes.h"

int start_game(game_t *game);

bool window_init(window_t *window);

SDL_Texture *load_media(char *image_path, SDL_Renderer *screenRenderer);

#endif // SOURCE_H