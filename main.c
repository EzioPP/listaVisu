//
// Created by Ezio on 29/03/2024.
//
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <SDL2/SDL.h>
#include "structs.h"
#include "init.h"
#include "geometry.h"
#include "define.h"
#include "lista.h"
#include "utils.h"


Lista lista;

int tam;
char str[50];
Point D;
bool click = false;
int th, cont = 0;


int WinMain(int argc, char *argv[]) {
    inicializar(&lista);
    srand(time(NULL));
    bool lunatic = false;
    exibir(&lista);
    printf("Tamanho: %d\n", tamanho(&lista));


    App app = init();

    int KFPS = 1000 / MAX_FPS;

    if (app.window == NULL || app.renderer == NULL) {
        printf("Erro ao criar janela ou renderer: %s\n", SDL_GetError());
        return 1;
    }

    bool running = true;
    SDL_Event event;
    int posicao;
    while (running) {
        tam = tamanho(&lista);
        Point m;
        SDL_GetMouseState(&m.x, &m.y);
        Uint64 start = SDL_GetTicks64();

        while (SDL_PollEvent(&event)) {
            switch (event.type) {
                case SDL_QUIT:
                    running = false;
                    break;

                case SDL_KEYDOWN:
                    switch (event.key.keysym.sym) {
                        case SDLK_ESCAPE:
                            running = false;
                            break;
                        case SDLK_1:
                            sprintf(str, "%d", random(0, 100));
                            inserirPosicao(&lista, "Ezio", str, "ezio@gmail", 1, random(100, SCREEN_WIDTH - 100),
                                           random(100, SCREEN_HEIGHT - 100));
                            break;
                        case SDLK_2:
                            sprintf(str, "%d", random(0, 100));
                            inserirPosicao(&lista, "Ezio", str, "ezio@gmail", random(1, tamanho(&lista) + 1),
                                           random(100, SCREEN_WIDTH - 100),
                                           random(100, SCREEN_HEIGHT - 100));
                            break;
                        case SDLK_3:

                            sprintf(str, "%d", random(0, 100));
                            inserirPosicao(&lista, "Ezio", str, "ezio@gmail", tam + 1, random(100, SCREEN_WIDTH - 100),
                                           random(100, SCREEN_HEIGHT - 100));
                            break;
                        case SDLK_SPACE:
                            exibir(&lista);
                            printf("Tamanho: %d\n", tamanho(&lista));
                            break;
                        case SDLK_q:
                            D = removerInicio(&lista);
                            SDL_SetRenderDrawColor(app.renderer, 0, 255, 0, 0);
                            draw_circle(app.renderer, D.x, D.y, 25);
                            break;
                        case SDLK_w:

                            posicao = random(0, tamanho(&lista));
                            D = removerPosicao(&lista, posicao);
                            printf("Tamanho: %d\n", tamanho(&lista));
                            printf("Posição: %d\n", posicao);
                            SDL_SetRenderDrawColor(app.renderer, 0, 255, 0, 0);
                            draw_circle(app.renderer, D.x, D.y, 25);
                            break;
                        case SDLK_s:
                            th = 0;
                            break;
                        case SDLK_e:
                            D = removerFim(&lista);
                            SDL_SetRenderDrawColor(app.renderer, 0, 255, 5, 0);
                            draw_circle(app.renderer, D.x, D.y, 25);
                            break;
                        case SDLK_l:
                            lunatic = !lunatic;
                            break;
                        case SDLK_b:
                            printf("Digite o nome a ser buscado: ");
                            scanf("%s", str);
                            buscar(&lista, str);

                            break;
                        case SDLK_k:
                            click = !click;
                            break;
                        case SDLK_p:
                            printf("Digite a posição a ser inserida: ");
                            scanf("%d", &posicao);
                            printf("Digite o nome: ");
                            scanf("%s", str);
                            char strE[50];
                            strcpy(strE, str);
                            strcat(strE, "@gmail.com");
                            inserirPosicao(&lista, str, "123", strE, posicao, random(100, SCREEN_WIDTH - 100),
                                      random(100, SCREEN_HEIGHT - 100));
                            break;

                       default:
                            break;
                    }
                case SDL_KEYUP:

                    break;
            }
        }
        if (tamanho(&lista) != tam) {
            printf("Lista alterada\n");
            tam = tamanho(&lista);
        }
        SDL_SetRenderDrawColor(app.renderer, 255, 255, 255, 255);

        ListaElemento *temp = lista.inicio;
        if (lunatic) {
            for (int i = 0; i < random(0, 15); i++) {
                sprintf(str, "%d", random(0, 100));
                inserirPosicao(&lista, "Ezio", str, "ezio@gmail", random(1, tamanho(&lista) + 1),
                               random(100, SCREEN_WIDTH - 100),
                               random(100, SCREEN_HEIGHT - 100));
            }
            for (int i = 0; i < random(0, 15); i++) {
                posicao = random(0, tamanho(&lista));
                D = removerPosicao(&lista, posicao);
                printf("Tamanho: %d\n", tamanho(&lista));
                printf("Posição: %d\n", posicao);
                SDL_SetRenderDrawColor(app.renderer, 0, 255, 0, 0);
                draw_circle(app.renderer, D.x, D.y, 25);
            }
            printf("Lunatic mode!!!: \n");
        }
        while (temp != NULL) {
            cont++;

            int32_t a = temp->x;
            int32_t b = temp->y;
            draw_circle(app.renderer, temp->x, temp->y, 25);
            if (colide(m.x, m.y, a, b) && click){

                printf("============================================\n");
                printf("============================================\n");
                printf("Posição: %d\n", cont);
                printf("Nome: %s\n", temp->nome);
                printf("Telefone: %s\n", temp->telefone);
                printf("Email: %s\n", temp->email);
                printf("Coordenadas: (%d, %d)\n", temp->x, temp->y);
                click = false;
            }




            ListaElemento *prox = temp->prox;
            if (prox != NULL) {
                SDL_SetRenderDrawColor(app.renderer, 255, 0, 0, 0);

                draw_arrow(app.renderer, a, b, prox->x, prox->y);
                SDL_SetRenderDrawColor(app.renderer, 255, 255, 255, 255);


            }

            temp = prox;
        }

        SDL_SetRenderDrawColor(app.renderer, 0, 0, 0, 255);
        SDL_RenderPresent(app.renderer);

        Uint64 end = SDL_GetTicks64();
        if (1) { //placeholder, pq as vezes quero limpar usando tecla
            //printf("Tela limpa\n");
            SDL_RenderClear(app.renderer);
            th = 180; //no caso, a parada roda a 60fps, então é pra se 3 segundos
        }


        Uint64 frameTime = end - start;

        if (frameTime < KFPS) {
            SDL_Delay(KFPS - frameTime);

        }

        cont = 0;
        th--;


    }

    SDL_DestroyWindow(app.window);
    SDL_Quit();

    return 0;
}