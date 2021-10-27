#ifndef SERVICIO_H_
#define SERVICIO_H_

typedef struct {
	int id;
	char descripcion[25];
	int precio;
} eServicio;

#endif /* SERVICIO_H_ */

/**
 * @brief Muestra en pantalla los datos de un servicio
 * @param unServicio estructura eServicio a mostrar
 */
void mostrarServicio(eServicio unServicio);

/**
 * @brief Muestra en pantalla los datos de la lista servicios
 * @param servicios Lista de servicios
 * @param tamS Entero que indica el largo de la lista de servicios
 * @return 0 si hubo error, 1 si no lo hubo
 */
int mostrarServicios(eServicio servicios[], int tamS);

/**
 * @brief Verifica si el id ingresado existe o no
 * @param Lista de servicios
 * @param tamS Entero que indica el largo de la lista de servicios
 * @param id a validar
 * @return 1 si existe, 0 si no existe
 */
int validarIdServicio(eServicio servicios[], int tamS, int id);

/**
 * @brief carga en un string la descripcion correspondiente al id de la bicicleta
 * @param servicios Lista de servicios
 * @param tamS Entero que indica el largo de la lista de servicios
 * @param idServicio id del servicio
 * @param descripcion string donde se copiara la descripcion de la bicicleta
 * @return 0 si hubo error, 1 si no lo hubo
 */
int cargarDescripcionServicio(eServicio servicios[], int tamS, int idServicio , char descripcion[]);

/**
 * @brief Verifica si el id ingresado por el usuario
 * @param servicios Lista de servicios
 * @param tamS Entero que indica el largo de la lista de servicios
 * @param id Id ingresado
 * @return El indice donde se encuentra ese Id, -1 si no existe
 */
int buscarServicioId(eServicio servicios[], int tamS, int id);
