#include "fecha.h"
#include "bicicleta.h"
#include "tipo.h"
#include "color.h"
#include "servicio.h"

#ifndef TRABAJO_H_
#define TRABAJO_H_

typedef struct {
	int id;
	int idBicicleta;
	int idServicio;
	eFecha fecha;
	int isEmpty;
} eTrabajo;

#endif /* TRABAJO_H_ */

int inicializarTrabajo(eTrabajo trabajos[], int tam);
int buscarLibreTrabajo(eTrabajo trabajos[], int tam);
int altaTrabajos(eTrabajo trabajos[], eBicicleta lista[], int tam, eTipo tipos[], int tamT, eColor colores[], int tamC, eServicio servicios[], int tamS, int* pId);
void mostrarTrabajo(eTrabajo unTrabajo, eBicicleta lista[], int tam,  eServicio servicios[], int tamS);
int mostrarTrabajos(eTrabajo trabajos[], int tam, eBicicleta lista[],  eServicio servicios[], int tamS);
