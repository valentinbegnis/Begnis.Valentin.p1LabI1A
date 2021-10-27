#ifndef MISFUNCIONES_H_
#define MISFUNCIONES_H_

#include "bicicleta.h"
#include "tipo.h"
#include "color.h"
#include "servicio.h"
#include "trabajo.h"

/**
 * @brief Muestra el menu principal y permite elegir una opcion
 * @return Retorna la opcion elegida
 */
int menu(void);

/**
 * @brief Muestra en pantalla el menu de informes
 * @return 0 si hubo error, 1 si no lo hubo
 */
int menuInformes(void);

/**
 *
 * @param lista Lista de bicicletas
 * @param tam Entero que indica el largo de la lista de bicicletas y trabajos
 * @param tipos Lista de tipos
 * @param tamT Entero que indica el largo de la lista de tipos
 * @param colores Lista de colores
 * @param tamC Entero que indica el largo de la lista de colores
 * @param servicios Lista de servicios
 * @param tamS Entero que indica el largo de la lista de servicios
 * @param trabajos Lista de trabajos
 * @return 0 si hubo error, 1 si no lo hubo
 */
int informes(eBicicleta lista[], int tam, eTipo tipos[], int tamT, eColor colores[], int tamC, eServicio servicios[], int tamS, eTrabajo trabajos[]);
/**
 * @bried Permite ingresar un string y valida su largo
 * @param string campo donde se cargara el string
 * @param len largo maximo del string
 * @param min largo minimo del string
 * @return 0 si hubo error, 1 si no lo hubo
 */
int pedirString(char string[], int len, int min);

#endif /* MISFUNCIONES_H_ */
