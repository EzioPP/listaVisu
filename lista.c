//
// Created by Ezio on 17/04/2024.
//
#include <stdio.h>
#include "structs.h"
#include "lista.h"
#include <stdlib.h>
#include <string.h>
#include "geometry.h"
int inicializar(Lista *lista) {
    lista->inicio = NULL;
    lista->fim = NULL;
    return 0;
}

int tamanho(Lista *lista) {
    int tamanho = 0;
    ListaElemento *temp = lista->inicio;
    while (temp != NULL) {
        tamanho++;
        temp = temp->prox;
    }
    return tamanho;
}


int inserirPosicao(Lista *lista, char *nome, char *telefone, char *email, int posicao, int coordx, int coordy) {
    int tam = tamanho(lista);
    printf("Tamanho: %d\n", tamanho(lista));
    ListaElemento *novo;
    novo = (ListaElemento *) malloc(sizeof(ListaElemento));
    if (novo == NULL) {
        printf("Erro ao alocar");
        return 1;
    }
    if (posicao == 0 || posicao > tamanho(lista) + 1) {
        printf("Posição inválida");
        return 1;
    }


    strcpy(novo->nome, nome);
    strcpy(novo->telefone, telefone);
    strcpy(novo->email, email);
    novo->x = coordx;
    novo->y = coordy;
    novo->prox = NULL;
    if(tamanho(lista) == 0){
        lista->inicio = novo;
        lista->fim = novo;
        return 0;
    }



    if (posicao == 1) {
        printf("Inserindo no início\n");
        novo->prox = lista->inicio;
        lista->inicio = novo;
        if (lista->fim == NULL) {
            lista->fim = novo;
        }
        return 0;
    }

    if (posicao == tam + 1) {
        printf("Inserindo no fim\n");
        printf("Tamanho: %d\n", tamanho(lista));
        printf("Posiçao: %d", posicao);
        if(lista->fim == NULL){
            lista->fim = novo;
            return 0;
        }
        lista->fim->prox = novo;
        lista->fim = novo;
        if (lista->inicio == NULL) {
            lista->inicio = novo;
        }
        return 0;
    }
    printf("Inserindo no meio\n");
    ListaElemento *temp = lista->inicio;
    for (int i = 0; i < posicao - 1; i++) {
        temp = temp->prox;
    }
    novo->prox = temp->prox;
    temp->prox = novo;

    printf("Inserido!!!");
    return 0;
}

Point removerInicio(Lista *lista) {
    Point p;
    ListaElemento *temp;
    if (lista->inicio == NULL) {
        printf("Lista vazia");
        p.x, p.y = -10;
        return p;
    }
    temp = lista->inicio;
    lista->inicio = temp->prox;
    printf("Removido nome: %s\n", temp->nome);
    printf("Removido telefone: %s\n", temp->telefone);
    printf("Removido email: %s\n", temp->email);
    p.x = temp->x;
    p.y = temp->y;
    free(temp);
    return p;
}

Point removerPosicao(Lista *lista, int posicao){
    Point p;
    ListaElemento *temp;
    ListaElemento *anterior;

    if (posicao < 0 || posicao > tamanho(lista)) {
        printf("Posição inválida");
        p.x, p.y = -10;
        return p;
    }
    if (posicao == 1) {
        return removerInicio(lista);
    }
    if (lista->inicio == NULL) {
        printf("Lista vazia");
        p.x, p.y = -10;
        return p;
    }
    temp = lista->inicio;
    anterior = NULL;
    for (int i = 0; i < posicao - 1; i++) {
        anterior = temp;
        temp = temp->prox;
    }
    if (anterior != NULL) {
        anterior->prox = temp->prox;
    } else {
        lista->inicio = temp->prox;
    }
    if (temp == lista->fim) {
        lista->fim = anterior;
    }
    printf("Removido nome: %s\n", temp->nome);
    printf("Removido telefone: %s\n", temp->telefone);
    printf("Removido email: %s\n", temp->email);
    p.x = temp->x;
    p.y = temp->y;
    free(temp);



    return p;

}

Point removerFim(Lista *lista) {
    Point p;
    ListaElemento *temp, *anterior;
    if (lista->inicio == NULL) {
        printf("Lista vazia");
        p.x, p.y = -10;
        return p;
    }
    temp = lista->inicio;
    anterior = NULL;
    while (temp->prox != NULL) {
        anterior = temp;
        temp = temp->prox;
    }
    printf("Removido nome: %s\n", temp->nome);
    printf("Removido telefone: %s\n", temp->telefone);
    printf("Removido email: %s\n", temp->email);
    p.x = temp->x;
    p.y = temp->y;
    free(temp);
    if (anterior != NULL) {
        anterior->prox = NULL;
        lista->fim = anterior;
    } else {
        lista->inicio = NULL;
        lista->fim = NULL;
    }
    return p;
}
int atualizar(Lista *lista, char *nome, char *telefone, char *email, int posicao, int x, int y) {
    ListaElemento *temp = lista->inicio;
    if (posicao == 0 || posicao > tamanho(lista)) {
        printf("Posição inválida");
        return 1;
    }
    for (int i = 0; i < posicao; i++) {
        temp = temp->prox;
    }
    strcpy(temp->nome, nome);
    strcpy(temp->telefone, telefone);
    strcpy(temp->email, email);
    temp->x = x;
    temp->y = y;
    return 0;
}

int buscar(Lista *lista, char *nome) {
    ListaElemento *temp = lista->inicio;
    int i = 1;
    while (temp != NULL) {

        if (strcmp(temp->nome, nome) == 0) {
            printf("Posição: %d\n", i);
            printf("Nome: %s\n", temp->nome);
            printf("Telefone: %s\n", temp->telefone);
            printf("Email: %s\n", temp->email);
            printf("Coordenadas: (%d, %d)\n", temp->x, temp->y);
            return 0;
        }
        temp = temp->prox;
        i++;
    }
    printf("Nome não encontrado\n");
    return 1;
}

int exibir(Lista *lista) {
    ListaElemento *temp = lista->inicio;
    int i = 1;
    while (temp != NULL) {
        printf("============================================\n");
        printf("============================================\n");
        printf("Posição: %d\n", i++);
        printf("Nome: %s\n", temp->nome);
        printf("Telefone: %s\n", temp->telefone);
        printf("Email: %s\n", temp->email);
        printf("Coordenadas: (%d, %d)\n", temp->x, temp->y);
        temp = temp->prox;
    }
    return 0;
}