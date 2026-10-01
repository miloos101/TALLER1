#include <stdio.h>
#include "jugador.h"
#include "ranking.h"

void limpiar_buffer() {
    int c;
    while ((c = getchar()) != '\n' && c != EOF);
}

int main() {
    int opcion = 0;
    inicializar_ranking();

    do {
        printf("\n*** MENU DE INTERFAZ - ARCADE MINIGAMES ***\n");
        printf("1. Registrar nuevo puntaje\n");
        printf("2. Ver Ranking Oficial\n");
        printf("3. Salir del programa\n");
        printf("Seleccione una opcion: ");
        
        if (scanf("%d", &opcion) != 1) {
            printf("\n[Error]: Entrada invalida.\n");
            limpiar_buffer();
            continue;
        }
        limpiar_buffer();

        switch (opcion) {
            case 1: {
                Jugador nuevo;
                printf("\nIngrese las 3 iniciales del jugador: ");
                scanf("%3s", nuevo.iniciales);
                limpiar_buffer();

                printf("Ingrese el puntaje obtenido: ");
                while (scanf("%d", &nuevo.puntaje) != 1 || nuevo.puntaje < 0) {
                    printf("[Error]: Ingrese un puntaje valido: ");
                    limpiar_buffer();
                }
                limpiar_buffer();

                if (actualizar_ranking(nuevo)) {
                    printf("\n¡NUEVO RECORD! %s entro al ranking.\n", nuevo.iniciales);
                } else {
                    printf("\nPuntaje insuficiente para el Top 3.\n");
                }
                break;
            }
            case 2:
                mostrar_ranking();
                break;
            case 3:
                printf("\nSaliendo del sistema...\n");
                break;
            default:
                printf("\n[Error]: Opcion no valida.\n");
        }
    } while (opcion != 3);

    return 0;
}