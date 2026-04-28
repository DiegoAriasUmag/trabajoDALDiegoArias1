#include <stdio.h>
#include <stdlib.h>
#include "../include/deportista.h"
#include "../include/generacion.h"

int main(void) {
    int opcion;

    while (1) {
        printf("\n=== menu principal - sistema de deportistas ===\n");
        printf("1. generar datos aleatorios y guardar csv\n");
        printf("2. cargar datos desde csv\n");
        printf("3. ordenar deportistas\n");
        printf("4. buscar por id\n");
        printf("5. mostrar ranking (mejores n)\n");
        printf("6. salir\n");
        printf("seleccione una opcion: ");

        if (scanf("%d", &opcion) != 1) {
            printf("entrada invalida\n");
            while (getchar() != '\n');
            continue;
        }

        switch (opcion) {
            case 1: {
                int cantidad;
                Deportista *deportistas;
                int guardado_ok;
                const char *ruta_csv = "data/deportistas_generados.csv";

                printf("cantidad de deportistas a generar: ");
                if (scanf("%d", &cantidad) != 1 || cantidad <= 0) {
                    printf("cantidad invalida\n");
                    while (getchar() != '\n');
                    break;
                }

                deportistas = (Deportista *)malloc((size_t)cantidad * sizeof(Deportista));
                if (deportistas == NULL) {
                    printf("no se pudo reservar memoria\n");
                    break;
                }

                generar_deportistas(deportistas, cantidad);
                mostrar_resumen_generado(deportistas, cantidad);

                guardado_ok = guardar_deportistas_csv(ruta_csv, deportistas, cantidad);
                if (guardado_ok) {
                    printf("csv generado en: %s\n", ruta_csv);
                } else {
                    printf("no se pudo guardar el csv\n");
                }

                free(deportistas);
                break;
            }

            case 2:
                printf("carga csv pendiente\n");
                break;

            case 3:
                printf("ordenamiento pendiente\n");
                break;

            case 4:
                printf("busqueda por id pendiente\n");
                break;

            case 5:
                printf("ranking pendiente\n");
                break;

            case 6:
                printf("saliendo del programa\n");
                return 0;

            default:
                printf("opcion no valida\n");
                break;
        }
    }

    return 0;
}