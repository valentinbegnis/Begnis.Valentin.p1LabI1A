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
/**
 * @brief Inicializa el campo isEmpty en 1 en todas sus posiciones
 * @param trabajos Lista de trabajos
 * @param tam Entero que indica el largo de la lista
 * @return 0 si hubo error, 1 si no lo hubo
 */
int inicializarTrabajo(eTrabajo trabajos[], int tam);

/**
 * @brief Busca el primer espacio libre en la lista de trabajos
 * @param trabajos Lista de trabajos
 * @param tam Entero que indica el largo de la lista
 * @return Retorna la posicion del primer espacio libre que encuentra, -1 en caso de error
 */
int buscarLibreTrabajo(eTrabajo trabajos[], int tam);

/**
 * @brief Da de alta una estructura en la primera posicion disponible
 * @param trabajos Lista de trabajos
 * @param lista Lista de bicicletas
 * @param tam Entero que indica el largo de la lista de trabajos y bicicletas
 * @param tipos Lista de tipos
 * @param tamT Entero que indica el largo de la lista de tipos
 * @param colores Lista de colores
 * @param tamC Entero que indica el largo de la lista de colores
 * @param servicios Lista de servicios
 * @param tamS Entero que indica el largo de la lista de servicios
 * @param pId Puntero entero al id de trabajos
 * @return 0 si hubo error, 1 si no lo hubo
 */
int altaTrabajos(eTrabajo trabajos[], eBicicleta lista[], int tam, eTipo tipos[], int tamT, eColor colores[], int tamC, eServicio servicios[], int tamS, int* pId);

/**
 * @brief Muestra en pantalla los datos de un trabajo
 * @param unTrabajo estructura eTrabajo a mostrar
 * @param lista lista de bicicletas
 * @param tam Entero que indica el largo de la lista de bicicletas
 * @param servicios Lista de servicios
 * @param tamS Entero que indica el largo de la lista de servicios
 */
void mostrarTrabajo(eTrabajo unTrabajo, eBicicleta lista[], int tam,  eServicio servicios[], int tamS);

/**
 * @brief Muestra en pantalla los datos de la lista de trabajos
 * @param trabajos Lista de trabajos
 * @param tam Entero que indica el largo de la lista de trabajos y bicicletas
 * @param lista Lista de bicicletas
 * @param servicios Lista de servicios
 * @param tamS Entero que indica el largo de la lista de servicios
 * @return 0 si hubo error, 1 si no lo hubo
 */
int mostrarTrabajos(eTrabajo trabajos[], int tam, eBicicleta lista[],  eServicio servicios[], int tamS);


