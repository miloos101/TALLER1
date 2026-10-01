#ifndef RANKING_H
#define RANKING_H

#include "jugador.h"

#define MAX_TOP 3

void inicializar_ranking();
void mostrar_ranking();
int actualizar_ranking(Jugador nuevo_jugador);

#endif