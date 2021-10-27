#include "bicicleta.h"
#include "trabajo.h"
#include "tipo.h"
#include "color.h"
#include "servicio.h"

#ifndef INFORMES_H_
#define INFORMES_H_

//Informes

/**
 * @brief Muestra las bicicletas de un color elegido por el usuario
 * @param lista Lista de bicicletas
 * @param tam Entero que indica el largo de la lista de bicicletas
 * @param tipos Lista de tipos
 * @param tamT Entero que indica el largo de la lista de tipos
 * @param colores Lista de colores
 * @param tamC Entero que indica el largo de la lista de colores
 * @return 0 si hubo error, 1 si no lo hubo
 */
int mostrarBicicletasColor(eBicicleta lista[], int tam, eTipo tipos[], int tamT, eColor colores[], int tamC);

/**
 * @brief Muestra las bicicletas de un tipo elegido por el usuario
 * @param lista Lista de bicicletas
 * @param tam Entero que indica el largo de la lista de bicicletas
 * @param tipos Lista de tipos
 * @param tamT Entero que indica el largo de la lista de tipos
 * @param colores Lista de colores
 * @param tamC Entero que indica el largo de la lista de colores
 * @return 0 si hubo error, 1 si no lo hubo
 */
int mostrarBicicletasTipo(eBicicleta lista[], int tam, eTipo tipos[], int tamT, eColor colores[], int tamC);

/**
 * @brief Informa si hay mas bicicletas de carbono o de aluminio y muestra la cantidad.
 * @param lista Lista de bicicletas
 * @param tam Entero que indica el largo de la lista de bicicletas
 * @return 0 si hubo error, 1 si no lo hubo
 */
int masCarbonoAluminio(eBicicleta lista[], int tam);

/**
 * @brief Muestra un listado de las bicicletas separadas por tipo
 * @param lista Lista de bicicletas
 * @param tam Entero que indica el largo de la lista de bicicletas
 * @param tipos Lista de tipos
 * @param tamT Entero que indica el largo de la lista de tipos
 * @param colores Lista de colores
 * @param tamC Entero que indica el largo de la lista de colores
 * @return 0 si hubo error, 1 si no lo hubo
 */
int mostrarBicicletasSeparadasTipo(eBicicleta lista[], int tam, eTipo tipos[], int tamT, eColor colores[], int tamC);
int contarPorColorYTipo(eBicicleta lista[], int tam, eTipo tipos[], int tamT, eColor colores[], int tamC);
int colorMasElegido(eBicicleta lista[], int tam, eColor colores[], int tamC);

//Informes bonus
int mostrarTrabajosBicicleta(eBicicleta lista[], int tam, eTipo tipos[], int tamT, eColor colores[], int tamC, eTrabajo trabajos[], eServicio servicios[], int tamS);
int sumaImporteServicios(eBicicleta lista[], int tam, eTipo tipos[], int tamT, eColor colores[], int tamC, eTrabajo trabajos[], eServicio servicios[], int tamS);
int mostrarBicicletasServicio(eBicicleta lista[], int tam, eTipo tipos[], int tamT, eColor colores[], int tamC, eTrabajo trabajos[], eServicio servicios[], int tamS);
int mostrarServiciosFecha(eBicicleta lista[], int tam, eTipo tipos[], int tamT, eColor colores[], int tamC, eTrabajo trabajos[], eServicio servicios[], int tamS);

#endif /* INFORMES_H_ */
