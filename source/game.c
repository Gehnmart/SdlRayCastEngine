#include "../includes/source.h"

#define mapWidth 24
#define mapHeight 24

int worldMap[mapWidth][mapHeight] = {
  {1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1},
  {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,0,0,0,0,0,2,2,2,2,2,0,0,0,0,3,0,3,0,3,0,0,0,1},
  {1,0,0,0,0,0,2,0,0,0,2,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,0,0,0,0,0,2,0,0,0,2,0,0,0,0,3,0,0,0,3,0,0,0,1},
  {1,0,0,0,0,0,2,0,0,0,2,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,0,0,0,0,0,2,2,0,2,2,0,0,0,0,3,0,3,0,3,0,0,0,1},
  {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,4,4,4,4,4,4,4,4,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,4,0,4,0,0,0,0,4,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,4,0,0,0,0,5,0,4,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,4,0,4,0,0,0,0,4,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,4,0,4,4,4,4,4,4,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,4,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,4,4,4,4,4,4,4,4,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1}
};

int start_game(game_t *game) {
  player_t *player = &game->player;
  camera_t *camera = &game->player.camera;

  SDL_Texture *texture = load_media("resources/wolftextures.png", game->window.screen_renderer);
  int txwidth, txheight;
  SDL_QueryTexture(texture, NULL, NULL, &txheight, &txwidth);

  player->posx = 22.0;
  player->posy = 11.5;
  player->dirx = -1;
  player->diry = 0;
  player->move_speed = 0.521;
  player->sensitivity = 0.002;

  camera->posx = 0;
  camera->posy = 0.66;

  while(!game->quit) {
    SDL_WarpMouseInWindow(game->window.sdl_window, SCREEN_WIDTH / 2, SCREEN_HEIGHT / 2);
    SDL_GetMouseState(&player->input.mouse_x, NULL);
    while(SDL_PollEvent(&game->event) != 0){
      if(game->event.type == SDL_QUIT){
        game->quit = true;
      } 
      if (game->event.type == SDL_MOUSEMOTION) {
        SDL_GetMouseState(&player->input.new_mouse_x, NULL);
        double diff = -((player->input.new_mouse_x - player->input.mouse_x) * player->sensitivity);
        double old_dir_x = player->dirx;
        player->dirx = player->dirx * cos(diff) - player->diry * sin(diff);
        player->diry = old_dir_x * sin(diff) + player->diry * cos(diff);
        double old_cam_x = camera->posx;
        camera->posx = camera->posx * cos(diff) - camera->posy * sin(diff);
        camera->posy = old_cam_x * sin(diff) + camera->posy * cos(diff);

        player->input.mouse_x = player->input.new_mouse_x;
      }
      if (game->event.type == SDL_KEYDOWN) {
        switch (game->event.key.keysym.sym) {
          case 'w':
            if(worldMap[(int)(player->posx + player->dirx * player->move_speed)][(int)player->posy] == false) player->posx += player->dirx * player->move_speed;
            if(worldMap[(int)player->posx][(int)(player->posy + player->diry * player->move_speed)] == false) player->posy += player->diry * player->move_speed;
            break;
          case 's':
            if(worldMap[(int)(player->posx - player->dirx * player->move_speed)][(int)player->posy] == false) player->posx -= player->dirx * player->move_speed;
            if(worldMap[(int)player->posx][(int)(player->posy - player->diry * player->move_speed)] == false) player->posy -= player->diry * player->move_speed;
            break;
          case 'a':
            if(worldMap[(int)(player->posx + player->camera.posx * player->move_speed)][(int)player->posy] == false) player->posx -= player->camera.posx * player->move_speed;
            if(worldMap[(int)player->posx][(int)(player->posy + player->camera.posy * player->move_speed)] == false) player->posy -= player->camera.posy * player->move_speed;
            break;
          case 'd':
            if(worldMap[(int)(player->posx + player->camera.posx * player->move_speed)][(int)player->posy] == false) player->posx += player->camera.posx * player->move_speed;
            if(worldMap[(int)player->posx][(int)(player->posy + player->camera.posy * player->move_speed)] == false) player->posy += player->camera.posy * player->move_speed;
            break;
          case 'q':
            game->quit = 1;
            break;
        }
      }
    }

    for (int ray = 0; ray < game->window.screen_width; ray++) {
      double cam_x = 2 * ray / (double)game->window.screen_width - 1;
      double ray_dir_x = player->dirx + camera->posx * cam_x;
      double ray_dir_y = player->diry + camera->posy * cam_x;

      int map_x = (int)player->posx;
      int map_y = (int)player->posy;
      double side_dist_x;
      double side_dist_y;
      double delta_dist_x = (ray_dir_x == 0) ? INFINITY : fabs(1 / ray_dir_x);
      double delta_dist_y = (ray_dir_y == 0) ? INFINITY : fabs(1 / ray_dir_y);
      double perp_wall_dist;
      int step_x;
      int step_y;
      int hit = 0;
      int side;

      if(ray_dir_x < 0) {
        step_x = -1;
        side_dist_x = (player->posx - map_x) * delta_dist_x;
      } else {
        step_x = 1;
        side_dist_x = (map_x + 1.0 - player->posx) * delta_dist_x;
      }
      if(ray_dir_y < 0) {
        step_y = -1;
        side_dist_y = (player->posy - map_y) * delta_dist_y;
      } else {
        step_y = 1;
        side_dist_y = (map_y + 1.0 - player->posy) * delta_dist_y;
      }

      while(!hit) {
        if(side_dist_x < side_dist_y) {
          side_dist_x += delta_dist_x;
          map_x += step_x;
          side = 0;
        } else {
          side_dist_y += delta_dist_y;
          map_y += step_y;
          side = 1;
        }
        if(worldMap[map_x][map_y] > 0) hit = 1;
      }
      
      if( side == 0 ) perp_wall_dist = (side_dist_x - delta_dist_x);
      else perp_wall_dist = (side_dist_y - delta_dist_y);

      int line_height = (int)(game->window.screen_height / perp_wall_dist);
      int draw_start = -line_height / 2 + game->window.screen_height / 2;
      if(draw_start < 0) draw_start = 0;
      int draw_end = line_height / 2 + game->window.screen_height / 2;
      if(draw_end >= game->window.screen_height) draw_end = game->window.screen_height - 1;

      unsigned char r, g, b, a = 0x00;
      switch(worldMap[map_x][map_y]) {
        case 1: {r = 0xff; g = 0x00; b = 0x00; break;}
        case 2: {r = 0x00; g = 0xff; b = 0x00; break;}
        case 3: {r = 0x00; g = 0x00; b = 0xff; break;}
        case 4: {r = 0xff; g = 0x00; b = 0xff; break;}
        default: {r = 0xff; g = 0xff; b = 0xff; break;}
      }

      if(side) {r /= 2; g /= 2; b /= 2;}

      double wallX; //where exactly the wall was hit
      if(side == 0) wallX = player->posy + perp_wall_dist * ray_dir_y;
      else          wallX = player->posx + perp_wall_dist * ray_dir_x;
      wallX -= floor((wallX));

      double texX = (wallX * (double)(txwidth));
      if(side == 0 && ray_dir_x > 0) texX = txwidth - texX;
      if(side == 1 && ray_dir_y < 0) texX = txwidth - texX;
      texX += (worldMap[map_x][map_y] * 64);
      
      double step = 1.0 * txheight / line_height;
      double texPos = (draw_start - game->window.screen_height / 2 + line_height / 2) * step; 

      //SDL_SetRenderDrawColor(game->window.screen_renderer, r, g, b, a);
      //SDL_RenderDrawLine(game->window.screen_renderer, ray, draw_start, ray, draw_end);

      SDL_Rect dstrect;
      dstrect.x = ray;
      dstrect.y = draw_start;
      dstrect.w = 1;
      dstrect.h = line_height;
      if(ray == 0) {
        printf("line = %d\n", line_height);
      }
      
      SDL_Rect clip = {(int)texX,0,1,txheight};
      SDL_RenderCopy(game->window.screen_renderer, texture, &clip, &dstrect);
    }
    SDL_RenderPresent(game->window.screen_renderer);
    SDL_SetRenderDrawColor(game->window.screen_renderer, 0xFF, 0xFF, 0xFF, 0xFF);
    SDL_RenderClear(game->window.screen_renderer);
  }

  return 0;
}