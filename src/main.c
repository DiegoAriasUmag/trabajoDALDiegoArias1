#include <stdio.h>
#include "../include/deportista.h"

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
            while (getchar() != '\n');  // Limpiar buffer
            continue;
        }

        switch (opcion) {
            case 1:
                printf("-> Generando datos...\n");
                // TODO: Llamar a función generar_datos()
                break;

            case 2:
                printf("-> Cargando CSV...\n");
                // TODO: Llamar a función cargar_csv()
                break;

            case 3:
                printf("-> Ordenando deportistas...\n");
                // TODO: Menú de ordenamiento (por puntaje, nombre, id, etc.)
                break;

            case 4:
                printf("-> Buscando por ID...\n");
                // TODO: Implementar búsqueda por ID
                break;

            case 5:
                printf("-> Mostrando ranking...\n");
                // TODO: Mostrar mejores N por puntaje
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