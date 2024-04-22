//
// Created by Ezio on 31/03/2024.
//

#include "geometry.h"
#include "SDL2/SDL.h"
#include <math.h>
#include <stdio.h> //todo remover, só pra testar



void draw_circle(SDL_Renderer *renderer, int32_t centreX, int32_t centreY, int32_t radius) {
    const int32_t diameter = (radius * 2);

    int32_t x = (radius - 1);
    int32_t y = 0;
    int32_t tx = 1;
    int32_t ty = 1;
    int32_t error = (tx - diameter);

    while (x >= y) {
        //  Each of the following renders an octant of the circle
        // Render horizontal lines instead of individual points
        SDL_RenderDrawLine(renderer, centreX - x, centreY - y, centreX + x, centreY - y);
        SDL_RenderDrawLine(renderer, centreX - x, centreY + y, centreX + x, centreY + y);
        SDL_RenderDrawLine(renderer, centreX - y, centreY - x, centreX + y, centreY - x);
        SDL_RenderDrawLine(renderer, centreX - y, centreY + x, centreX + y, centreY + x);

        if (error <= 0) {
            ++y;
            error += ty;
            ty += 2;
        }

        if (error > 0) {
            --x;
            tx += 2;
            error += (tx - diameter);
        }
    }
}

void draw_arrow(SDL_Renderer *renderer, int32_t a, int32_t b, int32_t x, int32_t y) {
    double radius = 25;
    double theta = atan2(y - b, x - a) + M_PI;
    double x0 = x;
    double y0 = y;
    double j, k;
    j = x0 + radius * cos(theta);
    k = y0 + radius * sin(theta);
    SDL_RenderDrawLine(renderer, a, b, x, y);
    draw_circle(renderer, j, k, 6);
}
