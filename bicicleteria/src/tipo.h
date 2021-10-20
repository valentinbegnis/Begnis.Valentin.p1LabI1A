#ifndef TIPO_H_
#define TIPO_H_

typedef struct {
	int id;
	char descripcion[20];
} eTipo;

#endif /* TIPO_H_ */

void mostrarTipo(eTipo unTipo, int tamT);
int mostrarTipos(eTipo tipos[], int tamT);
int validarIdTipo(eTipo tipos[], int tamT, int id);
int cargarDescripcionTipo(eTipo tipos[], int tamT, int idTipo , char descripcion[]);
