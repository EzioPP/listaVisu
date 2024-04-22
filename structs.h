//
// Created by Ezio on 31/03/2024.
//

#ifndef A_STRUCTS_H
#define A_STRUCTS_H
#include "SDL2/SDL.h"
typedef struct {
    SDL_Renderer *renderer;
    SDL_Window *window;
} App;

typedef struct {
    int32_t x;
    int32_t y;
} Point;

typedef struct {
    char nome[50];
    char telefone[15];
    char email[50];
    int32_t x;
    int32_t y;
    struct ListaElemento *prox;
} ListaElemento;

typedef struct {
    ListaElemento *inicio;
    ListaElemento *fim;
} Lista;


#endif //A_STRUCTS_H
