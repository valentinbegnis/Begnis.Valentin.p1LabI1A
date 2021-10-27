#ifndef TIPO_H_
#define TIPO_H_

typedef struct {
	int id;
	char descripcion[20];
} eTipo;

#endif /* TIPO_H_ */

/**
 * @brief Muestra en pantalla los datos de un tipo
 * @param unTipo Estructura eTipo a mostrar
 */
void mostrarTipo(eTipo unTipo);

/**
 *
 * @param tipos Lista de tipos
 * @param tamT Entero que indica el largo de la lista de tipos
 * @return 0 si hubo error, 1 si no lo hubo
 */
int mostrarTipos(eTipo tipos[], int tamT);

/**
 * @brief Verifica si el id ingresado existe o no
 * @param tipos Lista de tipos
 * @param tamT Entero que indica el largo de la lista de tipos
 * @param id a validar
 * @return 1 si existe, 0 si no existe
 */
int validarIdTipo(eTipo tipos[], int tamT, int id);

/**
 * @brief carga en un string la descripcion correspondiente al id del tipo
 * @param tipos Lista de tipos
 * @param tamT Entero que indica el largo de la lista de tipos
 * @param idTipo id del tipo
 * @param descripcion string donde se copiara la descripcion del tipo
 * @return 0 si hubo error, 1 si no lo hubo
 */
int cargarDescripcionTipo(eTipo tipos[], int tamT, int idTipo , char descripcion[]);
