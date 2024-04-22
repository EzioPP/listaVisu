//
// Created by Ezio on 17/04/2024.
//
#include "structs.h"

#ifndef A_LISTA_H
#define A_LISTA_H

int inicializar(Lista *lista);

int tamanho(Lista *lista);


int inserirPosicao(Lista *lista, char *nome, char *telefone, char *email, int posicao, int x, int y);





Point removerPosicao(Lista *lista, int posicao);
Point removerInicio(Lista *lista);
Point removerFim(Lista *lista);



int atualizar(Lista *lista, char *nome, char *telefone, char *email, int posicao, int x, int y);

int buscar(Lista *lista, char *nome);

int exibir(Lista *lista);

#endif //A_LISTA_H
