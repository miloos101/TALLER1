#include <stdio.h>
#include <string.h>
#include "ranking.h"

static Jugador top_ranking[MAX_TOP];

void inicializar_ranking() {
    for (int i = 0; i < MAX_TOP; i++) {
        strcpy(top_ranking[i].iniciales, "---");
        top_ranking[i].puntaje = -1; 
    }
}

void mostrar_ranking() {
    printf("\n===================================\n");
    printf("   TOP 3 - RANKING HISTORICO (GTA VI) \n");
    printf("===================================\n");
    for (int i = 0; i < MAX_TOP; i++) {
        if (top_ranking[i].puntaje == -1) {
            printf("%d. %s - 0 pts\n", i + 1, top_ranking[i].iniciales);
        } else {
            printf("%d. %s - %d pts\n", i + 1, top_ranking[i].iniciales, top_ranking[i].puntaje);
        }
    }
    printf("===================================\n");
}

int actualizar_ranking(Jugador nuevo_jugador) {
    int posicion = -1;

    for (int i = 0; i < MAX_TOP; i++) {
        if (nuevo_jugador.puntaje > top_ranking[i].puntaje) {
            posicion = i;
            break;
        }
    }

    if (posicion != -1) {
        for (int i = MAX_TOP - 1; i > posicion; i--) {
            top_ranking[i] = top_ranking[i - 1];
        }
        top_ranking[posicion] = nuevo_jugador;
        return 1; 
    }

    return 0; 
}