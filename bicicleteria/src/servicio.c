#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "servicio.h"

void mostrarServicio(eServicio unServicio)
{
	printf("  %d     %8s       %3d\n",
			unServicio.id,
			unServicio.descripcion,
			unServicio.precio
			);

}

int mostrarServicios(eServicio servicios[], int tamS)
{
	int todoOk = 0;
	int flag = 1;
	if(servicios != NULL && tamS > 0)
	{
		system("clear");
		printf("   *** Listado de Servicios ***\n");
		printf("   Id     Descripcion     Precio\n");
	    printf("----------------------------------\n");
		for(int i = 0; i < tamS; i++)
		{
			mostrarServicio(servicios[i]);
			flag = 0;
		}
		if(flag)
		{
			printf("No hay servicios para mostrar\n");
		}
		todoOk = 1;
	}
	return todoOk;
}

int validarIdServicio(eServicio servicios[], int tamS, int id)
{
	int existe = 0;
	if(servicios != NULL && tamS > 0)
	{
		for(int i = 0;i < tamS; i++)
		{
			if(servicios[i].id == id)
			{
				existe = 1;
				break;
			}
		}
	}
	return existe;
}

int cargarDescripcionServicio(eServicio servicios[], int tamS, int idServicio , char descripcion[])
{
	int todoOk = 0;
	if(servicios != NULL && tamS > 0 && descripcion != NULL)
	{
		for(int i = 0; i < tamS; i++)
		{
			if(servicios[i].id == idServicio)
			{
				strcpy(descripcion, servicios[i].descripcion);
				break;
			}
		}
		todoOk = 1;
	}
	return todoOk;
}

int buscarServicioId(eServicio servicios[], int tamS, int id)
{
	int indice = -1;
	if(servicios != NULL && tamS > 0)
	{
		for(int i = 0; i < tamS; i++)
		{
			if(servicios[i].id == id)
			{
				indice = i;
				break;
			}
		}
	}
	return indice;
}
