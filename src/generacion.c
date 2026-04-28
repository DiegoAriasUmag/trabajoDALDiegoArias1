#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include "../include/generacion.h"

static int semilla_inicializada = 0;

static void inicializar_semilla(void) {
    if (!semilla_inicializada) {
        srand((unsigned int)time(NULL));
        semilla_inicializada = 1;
    }
}

static void generar_nombre_aleatorio(char *destino, int maximo) {
    int largo_minimo = 4;
    int rango = 8;
    int largo = largo_minimo + (rand() % rango);
    int i;

    if (largo >= maximo) {
        largo = maximo - 1;
    }

    destino[0] = (char)('A' + (rand() % 26));
    for (i = 1; i < largo; i++) {
        destino[i] = (char)('a' + (rand() % 26));
    }
    destino[largo] = '\0';
}

void generar_deportistas(Deportista *deportistas, int cantidad) {
    const char *equipos[] = {
        "redbull", "ferrari", "mercedes", "mclaren", "alpine",
        "aston", "williams", "haas", "sauber", "racingbulls"
    };
    int total_equipos = (int)(sizeof(equipos) / sizeof(equipos[0]));
    int i;

    if (deportistas == NULL || cantidad <= 0) {
        return;
    }

    inicializar_semilla();

    for (i = 0; i < cantidad; i++) {
        deportistas[i].id = i + 1;
        generar_nombre_aleatorio(deportistas[i].nombre, NOMBRE_MAX);
        strncpy(deportistas[i].equipo, equipos[rand() % total_equipos], EQUIPO_MAX - 1);
        deportistas[i].equipo[EQUIPO_MAX - 1] = '\0';
        deportistas[i].puntaje = (float)(rand() % 1001) / 10.0f;
        deportistas[i].competencias = 1 + (rand() % 60);
    }
}

void mostrar_resumen_generado(const Deportista *deportistas, int cantidad) {
    int limite;
    int i;

    if (deportistas == NULL || cantidad <= 0) {
        printf("no hay datos generados\n");
        return;
    }

    limite = cantidad < 5 ? cantidad : 5;

    printf("\nregistros generados: %d\n", cantidad);
    printf("id,nombre,equipo,puntaje,competencias\n");

    for (i = 0; i < limite; i++) {
        printf("%d,%s,%s,%.1f,%d\n",
               deportistas[i].id,
               deportistas[i].nombre,
               deportistas[i].equipo,
               deportistas[i].puntaje,
               deportistas[i].competencias);
    }
}
