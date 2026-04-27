#ifndef DEPORTISTA_H
#define DEPORTISTA_H

#define NOMBRE_MAX 50
#define EQUIPO_MAX 50

typedef struct {
    int id;
    char nombre[NOMBRE_MAX];
    char equipo[EQUIPO_MAX];
    float puntaje;
    int competencias;
} Deportista;

#endif
