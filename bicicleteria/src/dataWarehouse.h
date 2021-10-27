#ifndef DATAWAREHOUSE_H_
#define DATAWAREHOUSE_H_

#include "bicicleta.h"
#include "trabajo.h"

/**
 * @brief Hardcodeo de bicicletas para testear el programa rapidamente
 * @param lista Array de tipo eBicicleta
 * @param tam Tamaño del array
 * @param cant Cantidad de bicicletas a hardcodear
 * @param pId Puntero entero al id de bicicletas
 * @return -1 si hubo error, (x) Cantidad de bicicletas hardcodeadas si no hubo error
 */
int hardcodearBicicletas(eBicicleta lista[], int tam, int cant, int* pId);

/**
 * @brief Hardcodeo de trabajos para testear el programa rapidamente
 * @param trabajos Array de tipo eTrabajo
 * @param tam Tamaño del array
 * @param cant Cantidad de trabajos a hardcodear
 * @param pId Puntero entero al id de trabajos
 * @return -1 si hubo error, (x) Cantidad de trabajos hardcodeadas si no hubo error
 */
int hardcodearTrabajos(eTrabajo trabajos[], int tam, int cant, int* pId);

#endif /* DATAWAREHOUSE_H_ */
