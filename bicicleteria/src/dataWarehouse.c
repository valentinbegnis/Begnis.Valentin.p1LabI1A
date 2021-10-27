#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "dataWarehouse.h"
#include "bicicleta.h"
#include "trabajo.h"

char marcas[10][20] = {
		"Haro",
		"Raleigh",
		"Santa Cruz",
		"Orbea",
		"Ktm",
		"Trek",
		"Renault",
		"Giant",
		"Shimano",
		"Fuji"
};

int idColores[10] = {5000, 5001, 5004, 5002, 5000, 5004, 5003, 5002, 5001, 5002};

int idTipos[10] = {1000, 1002, 1001, 1002, 1000, 1003, 1000, 1003, 1001, 1003};

char materiales[10] = {'a', 'a', 'c', 'a', 'c', 'c', 'a', 'c', 'a', 'a'};

int hardcodearBicicletas(eBicicleta lista[], int tam, int cant, int* pId)
{
	int cont = -1;

	if(lista != NULL && tam > 0 && cant >= 0 && cant <= tam && pId != NULL)
	{
		cont = 0;
		for(int i = 0 ; i < cant; i++)
		{
			lista[i].id = *pId;
			(*pId)++;
			strcpy(lista[i].marca, marcas[i]);
			lista[i].idColor = idColores[i];
			lista[i].idTipo = idTipos[i];
			lista[i].material = materiales[i];
			lista[i].isEmpty = 0;
			cont++;
		}
	}
	return cont;
}

int idBicicletas[10] = {2000, 2002, 2000, 2000, 2004, 2006, 2009, 2008, 2003, 2001};

int idServicios[10] = {20002, 20000, 20002, 20001, 20003, 20000, 20001, 20003, 20003, 20002};

int idPrecios[10] = {500, 30, 500, 400, 450, 30, 400, 450, 450, 500};

int fechaDia[10] = {25, 14, 4, 7, 30, 18, 27, 3, 17, 4};
int fechaMes[10] = {3, 6, 4, 6, 12, 9, 1, 5, 10, 11};
int fechaAnio[10] = {2021, 2020, 2018, 2019, 2021, 2017, 2020, 2018, 2016, 2019};

int hardcodearTrabajos(eTrabajo trabajos[], int tam, int cant, int* pId)
{
	int cont = -1;

	if(trabajos != NULL && tam > 0 && cant >= 0 && cant <= tam && pId != NULL)
	{
		cont = 0;
		for(int i = 0 ; i < cant; i++)
		{
			trabajos[i].id = *pId;
			(*pId)++;
			trabajos[i].idBicicleta = idBicicletas[i];
			trabajos[i].idServicio = idServicios[i];
			trabajos[i].fecha.dia = fechaDia[i];
			trabajos[i].fecha.mes = fechaMes[i];
			trabajos[i].fecha.anio = fechaAnio[i];
			trabajos[i].isEmpty = 0;
			cont++;
		}
	}
	return cont;
}
