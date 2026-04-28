#include <stdio.h>
#include <stdlib.h>
#include "../include/deportista.h"
#include "../include/generacion.h"

int main(void) {
    int opcion;

    while (1) {
        printf("\n=== MENU PRINCIPAL - Sistema de Deportistas ===\n");
        printf("1. Generar datos aleatorios y guardar CSV\n");
        printf("2. Cargar datos desde CSV\n");
        printf("3. Ordenar deportistas\n");
        printf("4. Buscar por ID\n");
        printf("5. Mostrar ranking (mejores N)\n");
        printf("6. Salir\n");
        printf("Seleccione una opcion: ");

        if (scanf("%d", &opcion) != 1) {
            printf("Error: Entrada invalida. Intente nuevamente.\n");
            while (getchar() != '\n');
            continue;
        }

        switch (opcion) {
            case 1: {
                int cantidad;
                Deportista *deportistas;

                printf("Cantidad de deportistas a generar: ");
                if (scanf("%d", &cantidad) != 1 || cantidad <= 0) {
                    printf("Cantidad invalida\n");
                    while (getchar() != '\n');
                    break;
                }

                deportistas = (Deportista *)malloc((size_t)cantidad * sizeof(Deportista));
                if (deportistas == NULL) {
                    printf("No se pudo reservar memoria\n");
                    break;
                }

                generar_deportistas(deportistas, cantidad);
                mostrar_resumen_generado(deportistas, cantidad);
                free(deportistas);
                break;
            }

            case 2:
                printf("-> Cargando CSV...\n");
                break;

            case 3:
                printf("-> Ordenando deportistas...\n");
                break;

            case 4:
                printf("-> Buscando por ID...\n");
                break;

            case 5:
                printf("-> Mostrando ranking...\n");
                break;

            case 6:
                printf("Saliendo del programa...\n");
                return 0;

            default:
                printf("Opcion no valida. Intente nuevamente.\n");
                break;
        }
    }

    return 0;
}