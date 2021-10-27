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
	int idCliente;
} eBicicleta;

#endif /* BICICLETA_H_ */

/**
 * @brief Inicializa el campo isEmpty en 1 en todas sus posiciones
 * @param lista Lista de bicicletas
 * @param tam Entero que indica el largo de la lista
 * @return 0 si hubo error, 1 si no lo hubo
 */
int inicializarBicicleta(eBicicleta lista[], int tam);

/**
 * @brief Busca el primer espacio libre en la lista de bicicletas
 * @param lista Lista de bicicletas
 * @param tam Entero que indica el largo de la lista
 * @return Retorna la posicion del primer espacio libre que encuentra, -1 en caso de error
 */
int buscarLibreBicicleta(eBicicleta lista[], int tam);

/**
 * @brief Da de alta una estructura en la primera posicion disponible
 * @param lista Lista de bicicletas
 * @param tam Entero que indica el largo de la lista de bicicletas
 * @param tipos Lista de tipos
 * @param tamT Entero que indica el largo de la lista de tipos
 * @param colores Lista de colores
 * @param tamC Entero que indica el largo de la lista de colores
 * @param pId Puntero entero al id de bicicletas
 * @return 0 si hubo error, 1 si no lo hubo
 */
int altaBicicleta(eBicicleta lista[], int tam, eTipo tipos[], int tamT, eColor colores[], int tamC, int* pId);

/**
 * @brief Muestra en pantalla los datos de una bicicleta
 * @param unaBicicleta estructura eBicicleta a mostrar
 * @param tipos Lista de tipos
 * @param tamT Entero que indica el largo de la lista de tipos
 * @param colores Lista de colores
 * @param tamC tamC Entero que indica el largo de la lista de colores
 * @return 0 si hubo error, 1 si no lo hubo
 */
int mostrarBicicleta(eBicicleta unaBicicleta, eTipo tipos[], int tamT,  eColor colores[], int tamC);

/**
 * @brief Muestra en pantalla los datos de la lista de bicicletas
 * @param lista Lista de bicicletas
 * @param tam Entero que indica el largo de la lista de bicicletas
 * @param tipos Lista de tipos
 * @param tamT Entero que indica el largo de la lista de tipos
 * @param colores Lista de colores
 * @param tamC Entero que indica el largo de la lista de colores
 * @return 0 si hubo error, 1 si no lo hubo
 */
int mostrarBicicletas(eBicicleta lista[], int tam, eTipo tipos[], int tamT, eColor colores[], int tamC);

/**
 * @brief Muestra en pantalla el menu de modificaciones y permite elegir una opcion
 * @return Opcion elegida
 */
int menuModificacion();

/**
 * @brief Permite la modificacion de un dato que elije el usuario
 * @param lista Lista de bicicletas
 * @param tam Entero que indica el largo de la lista de bicicletas
 * @param tipos Lista de tipos
 * @param tamT Entero que indica el largo de la lista de tipos
 * @param colores Lista de colores
 * @param tamC Entero que indica el largo de la lista de colores
 * @return 0 si hubo error, 1 si no lo hubo
 */
int modificarBicicleta(eBicicleta lista[], int tam, eTipo tipos[], int tamT, eColor colores[], int tamC);

/**
 * @brief Verifica si el id ingresado por el usuario
 * @param lista Lista de bicicletas
 * @param tam Entero que indica el largo de la lista de bicicletas
 * @param id Id ingresado
 * @return El indice donde se encuentra ese Id, -1 si no existe
 */
int buscarBicicletaId(eBicicleta lista[], int tam, int id);

/**
 * @brief Da de baja una bicicleta seleccionada por el usuario mediante el id
 * @param lista Lista de bicicletas
 * @param tam Entero que indica el largo de la lista de bicicletas
 * @param tipos Lista de tipos
 * @param tamT Entero que indica el largo de la lista de tipos
 * @param colores Lista de colores
 * @param tamC Entero que indica el largo de la lista de colores
 * @return 0 si hubo error, 1 si no lo hubo
 */
int bajaBicicleta(eBicicleta lista[], int tam, eTipo tipos[], int tamT, eColor colores[], int tamC);

/**
 * @brief Ordena la lista de bicicletas por tipo y material
 * @param lista Lista de bicicletas
 * @param tam Entero que indica el largo de la lista de bicicletas
 * @param tipos Lista de tipos
 * @param tamT Entero que indica el largo de la lista de tipos
 * @return 0 si hubo error, 1 si no lo hubo
 */
int ordenarBicicleta(eBicicleta lista[], int tam, eTipo tipos[], int tamT);

/**
 * @brief Verifica si el id ingresado existe o no
 * @param lista Lista de bicicletas
 * @param tam Entero que indica el largo de la lista de bicicletas
 * @param id a validar
 * @return 1 si existe, 0 si no existe
 */
int validarIdBicicleta(eBicicleta lista[], int tam, int id);

/**
 * @brief carga en un string la descripcion correspondiente al id de la bicicleta
 * @param lista Lista de bicicletas
 * @param tam Entero que indica el largo de la lista de bicicletas
 * @param idBicicleta id de la bicicleta
 * @param descripcion string donde se copiara la descripcion de la bicicleta
 * @return 0 si hubo error, 1 si no lo hubo
 */
int cargarDescripcionBicicleta(eBicicleta lista[], int tam, int idBicicleta , char descripcion[]);

/**
 * @brief carga en un string la descripcion correspondiente al id del material
 * @param unaBicicleta estructura eBicicleta
 * @param descripcion string donde se copiara la descripcion del material
 * @return 0 si hubo error, 1 si no lo hubo
 */
int cargarDescripcionMaterial(eBicicleta unaBicicleta, char descripcion[]);


