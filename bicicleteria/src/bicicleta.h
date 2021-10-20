#include "tipo.h"
#include "color.h"

#ifndef BICICLETA_H_
#define BICICLETA_H_

typedef struct {
	int id;
	char marca[20];
	int idTipo;
	int idColor;
	char material;
	int isEmpty;
} eBicicleta;

#endif /* BICICLETA_H_ */

int inicializarBicicleta(eBicicleta lista[], int tam);
int buscarLibreBicicleta(eBicicleta lista[], int tam);
int altaBicicleta(eBicicleta lista[], int tam, eTipo tipos[], int tamT, eColor colores[], int tamC, int* pId);
void mostrarBicicleta(eBicicleta unaBicicleta, eTipo tipos[], int tamT,  eColor colores[], int tamC);
int mostrarBicicletas(eBicicleta lista[], int tam, eTipo tipos[], int tamT, eColor colores[], int tamC);
int menuModificacion();
int modificarBicicleta(eBicicleta lista[], int tam, eTipo tipos[], int tamT, eColor colores[], int tamC);
int buscarBicicletaId(eBicicleta lista[], int tam, int id);
int bajaBicicleta(eBicicleta lista[], int tam, eTipo tipos[], int tamT, eColor colores[], int tamC);
int ordenarBicicleta(eBicicleta lista[], int tam);
int validarIdBicicleta(eBicicleta lista[], int tam, int id);
int cargarDescripcionBicicleta(eBicicleta lista[], int tam, int idBicicleta , char descripcion[]);
