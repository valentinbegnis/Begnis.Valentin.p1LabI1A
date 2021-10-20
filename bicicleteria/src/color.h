#ifndef COLOR_H_
#define COLOR_H_

typedef struct {
	int id;
	char nombreColor[20];
} eColor;

#endif /* COLOR_H_ */

void mostrarColor(eColor unColor, int tamC);
int mostrarColores(eColor colores[], int tamC);
int validarIdColor(eColor colores[], int tamC, int id);
int cargarDescripcionColor(eColor colores[], int tamC, int idColor , char descripcion[]);
