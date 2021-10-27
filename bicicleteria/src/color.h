#ifndef COLOR_H_
#define COLOR_H_

typedef struct {
	int id;
	char nombreColor[20];
} eColor;

#endif /* COLOR_H_ */

/**
 * @brief Muestra en pantalla los datos de un color
 * @param unColor estructura eColor a mostrar
 */
void mostrarColor(eColor unColor);

/**
 * @brief Muestra en pantalla los datos de la lista color
 * @param colores Lista de colores
 * @param tamC Entero que indica el largo de la lista de colores
 * @return
 */
int mostrarColores(eColor colores[], int tamC);

/**
 * @brief Verifica si el id ingresado existe o no
 * @param colores Lista de colores
 * @param tamC Entero que indica el largo de la lista de colores
 * @param id a validar
 * @return 1 si existe, 0 si no existe
 */
int validarIdColor(eColor colores[], int tamC, int id);

/**
 * @brief carga en un string la descripcion correspondiente al id del color
 * @param colores Lista de colores
 * @param tamC Entero que indica el largo de la lista de colores
 * @param idColor id del color
 * @param descripcion string donde se copiara la descripcion del color
 * @return 0 si hubo error, 1 si no lo hubo
 */
int cargarDescripcionColor(eColor colores[], int tamC, int idColor , char descripcion[]);
