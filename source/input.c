#include "../includes/source.h"

int get_key(SDL_Event event) {
  return event.key.keysym.sym;
}