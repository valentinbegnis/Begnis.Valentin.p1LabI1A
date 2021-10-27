#include <stdio.h>
#include <stdlib.h>
#include <stdio_ext.h>
#include "trabajo.h"
#include "bicicleta.h"
#include "validaciones.h"

int inicializarTrabajo(eTrabajo trabajos[], int tam)
{
	int todoOk = 0;
	if(trabajos != NULL && tam > 0)
	{
		for(int i = 0; i < tam; i++)
		{
			trabajos[i].isEmpty = 1;
		}
		todoOk = 1;
	}
	return todoOk;
}

int buscarLibreTrabajo(eTrabajo trabajos[], int tam)
{
	int indice = -1;
	if(trabajos != NULL && tam > 0)
	{
		for(int i = 0; i < tam; i++)
		{
			if(trabajos[i].isEmpty == 1)
			{
				indice = i;
				break;
			}
		}
	}
	return indice;
}

int altaTrabajos(eTrabajo trabajos[], eBicicleta lista[], int tam, eTipo tipos[], int tamT, eColor colores[], int tamC, eServicio servicios[], int tamS, int* pId)
{
	int todoOk = 0;
	int indice;
	int retornoBicicleta, retornoServicio, retornoFecha;
	eTrabajo auxTrabajo;

	if(trabajos != NULL && lista != NULL && tam > 0 && tipos != NULL && tamT > 0 && colores != NULL && tamC > 0 && servicios != NULL && tamS > 0 && pId != NULL)
	{
		system("clear");
	    printf("                   *** Alta Trabajo ***\n");
	    printf("------------------------------------------------------------\n");

		indice = buscarLibreTrabajo(trabajos, tam);
		if(indice == -1)
		{
			printf("No hay lugar en el sistema\n");
		}
		else
		{
			auxTrabajo.id = *pId;
			(*pId)++;

			mostrarBicicletas(lista, tam, tipos, tamT, colores, tamC);
			printf("\nIngrese id de la bicicleta: ");
			retornoBicicleta = scanf("%d", &auxTrabajo.idBicicleta);
			validarEntero(retornoBicicleta, &auxTrabajo.idBicicleta);

			while(!validarIdBicicleta(lista, tam, auxTrabajo.idBicicleta))
				{
					printf("Error. Ingrese un id valido: ");
					retornoBicicleta = scanf("%d", &auxTrabajo.idBicicleta);
					validarEntero(retornoBicicleta, &auxTrabajo.idBicicleta);
				}

			mostrarServicios(servicios, tamS);
			printf("\nIngrese id del servicio: ");
			retornoServicio = scanf("%d", &auxTrabajo.idServicio);
			validarEntero(retornoServicio, &auxTrabajo.idServicio);

			while(!validarIdServicio(servicios, tamS, auxTrabajo.idServicio))
				{
					printf("Error. Ingrese un id valido: ");
					retornoServicio = scanf("%d", &auxTrabajo.idServicio);
					validarEntero(retornoServicio, &auxTrabajo.idServicio);
				}

			printf("\nIngrese fecha: ");
			__fpurge(stdin);
			retornoFecha = scanf("%d/%d/%d", &auxTrabajo.fecha.dia, &auxTrabajo.fecha.mes, &auxTrabajo.fecha.anio);
			validarFecha(retornoFecha, &auxTrabajo.fecha.dia, &auxTrabajo.fecha.mes, &auxTrabajo.fecha.anio);

			auxTrabajo.isEmpty = 0;

			trabajos[indice] = auxTrabajo;
		}
		todoOk = 1;
	}
	return todoOk;
}

void mostrarTrabajo(eTrabajo unTrabajo, eBicicleta lista[], int tam,  eServicio servicios[], int tamS)
{
	char descBicicleta[20];
	char descServicio[20];
	int indiceBicicleta, indiceServicio;

	indiceBicicleta = buscarBicicletaId(lista, tam, unTrabajo.idBicicleta);
	indiceServicio = buscarServicioId(servicios, tamS, unTrabajo.idServicio);

	cargarDescripcionBicicleta(lista, tam, unTrabajo.idBicicleta, descBicicleta);
	cargarDescripcionServicio(servicios, tamS, unTrabajo.idServicio, descServicio);

	printf("      %d      %d     %10s       %8s      %3d   %d/%d/%d\n",
			unTrabajo.id,
			lista[indiceBicicleta].id,
			descBicicleta,
			descServicio,
			servicios[indiceServicio].precio,
			unTrabajo.fecha.dia,
			unTrabajo.fecha.mes,
			unTrabajo.fecha.anio
			);
}

int mostrarTrabajos(eTrabajo trabajos[], int tam, eBicicleta lista[],  eServicio servicios[], int tamS)
{
	int todoOk = 0;
	int flag = 1;
	if(trabajos != NULL && tam > 0 && lista != NULL && servicios != NULL && tamS > 0)
	{
		system("clear");
	    printf("                     *** Listado de Trabajos ***                      \n");
		printf("   Id Trabajo    Id        Bicicleta      Servicio    Precio    Fecha\n");
	    printf("------------------------------------------------------------------------\n");
		for(int i = 0; i < tam; i++)
		{
			if(trabajos[i].isEmpty == 0)
			{
				mostrarTrabajo(trabajos[i], lista, tam, servicios, tamS);
				flag = 0;
			}
		}
		if(flag)
		{
			printf("No hay trabajos para mostrar\n");
		}
		todoOk = 1;
	}
	return todoOk;
}
