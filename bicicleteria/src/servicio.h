#ifndef SERVICIO_H_
#define SERVICIO_H_

typedef struct {
	int id;
	char descripcion[25];
	int precio;
} eServicio;

#endif /* SERVICIO_H_ */

void mostrarServicio(eServicio unServicio, int tamS);
int mostrarServicios(eServicio servicios[], int tamS);
int validarIdServicio(eServicio servicios[], int tamS, int id);
int cargarDescripcionServicio(eServicio servicios[], int tamS, int idServicio , char descripcion[]);
