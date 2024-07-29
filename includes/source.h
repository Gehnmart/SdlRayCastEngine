#ifndef SOURCE_H
#define SOURCE_H

#include "includes.h"

bool window_init(window_t *window);

SDL_Texture *load_media(char *image_path, SDL_Renderer *screenRenderer);

#endif // SOURCE_H