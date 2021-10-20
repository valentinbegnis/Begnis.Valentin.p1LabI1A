#include <stdio.h>
#include <stdlib.h>
#include <stdio_ext.h>
#include "trabajo.h"
#include "bicicleta.h"

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
	int stringValido;
	int retornoBicicleta;
	int retornoServicio;
	eTrabajo auxTrabajo;

	if(trabajos != NULL && lista != NULL && tam > 0 && tipos != NULL && tamT > 0 && colores != NULL && tamC > 0 && servicios != NULL && tamS > 0 && pId != NULL)
	{
		system("clear");
	    printf("            *** Alta Trabajo ***              \n");
	    printf("---------------------------------------------\n");

		indice = buscarLibreTrabajo(trabajos, tam);
		if(indice == -1)
		{
			printf("No hay lugar en el sistema\n");
		}
		else
		{
			auxTrabajo.id = *pId;
			(*pId)++;


			printf("Ingrese id de la bicicleta: ");
			retornoBicicleta = scanf("%d", &auxTrabajo.idBicicleta);
			//validarEntero(retornoTipo, &auxBicicleta.idTipo);

			while(!validarIdBicicleta(lista, tam, auxTrabajo.idBicicleta))
				{
					mostrarBicicletas(lista, tam, tipos, tamT, colores, tamC);
					printf("Error. Ingrese un id de tipo valido: ");
					retornoBicicleta = scanf("%d", &auxTrabajo.idBicicleta);
				}

			mostrarServicios(servicios, tamS);
			printf("Ingrese id del servicio: ");
			retornoServicio = scanf("%d", &auxTrabajo.idServicio);
			//validarEntero(retornoColor, &auxBicicleta.idColor);

			while(!validarIdServicio(servicios, tamS, auxTrabajo.idServicio))
				{
					mostrarServicios(servicios, tamS);
					printf("Error. Ingrese un id de servicio valido: ");
					retornoServicio = scanf("%d", &auxTrabajo.idServicio);
				}

			printf("Ingrese fecha: ");
			__fpurge(stdin);
			scanf("%d/%d/%d", &auxTrabajo.fecha.dia, &auxTrabajo.fecha.mes, &auxTrabajo.fecha.anio);

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

	cargarDescripcionBicicleta(lista, tam, unTrabajo.idBicicleta, descBicicleta);
	cargarDescripcionServicio(servicios, tamS, unTrabajo.idServicio, descServicio);

	printf("  %d    %10s   %10s   %d/%d/%d\n",
			unTrabajo.id,
			descBicicleta,
			descServicio,
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
	    printf("       *** Listado de Trabajos ***      \n");
		printf("   Id   Bicicleta   Servicio   Fecha\n");
	    printf("---------------------------------------\n");
		for(int i = 0; i < tam; i++)
		{
			if(lista[i].isEmpty == 0)
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
