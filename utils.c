//
// Created by Ezio on 19/04/2024.
//

#include "utils.h"
#include "structs.h"
#include "define.h"
#include <stdio.h>

#include <stdlib.h>
int random(int min, int max) {
    return min + rand() % (max + 1 - min);
}
bool colide(int x, int y, int x1, int y1){
    return (x - x1) * (x - x1) + (y - y1) * (y - y1) <= CIRCLERADIUS * CIRCLERADIUS;
}
void clearScreen(){ //odeio isso
    for (int i = 0; i < 100; i++) {
        printf("\n");
    }
}