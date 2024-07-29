#include "../includes/source.h"

SDL_Texture *load_media(char *image_path, SDL_Renderer *screenRenderer) {
  SDL_Texture *newTexture = NULL;

  newTexture = IMG_LoadTexture(screenRenderer, image_path);
  if (newTexture == NULL) {
    fprintf(stderr, "IMG_Load(): path{%s} %s\n", image_path, IMG_GetError());
  }

  return newTexture;
}