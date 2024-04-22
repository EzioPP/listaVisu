//
// Created by Ezio on 31/03/2024.
//

#ifndef A_GEOMETRY_H
#define A_GEOMETRY_H
#include "SDL2/SDL.h"
#include "structs.h"
void draw_circle(SDL_Renderer * renderer, int32_t centreX, int32_t centreY, int32_t radius);
void draw_arrow(SDL_Renderer *renderer, int32_t a, int32_t b, int32_t x, int32_t y);
#endif //A_GEOMETRY_H
