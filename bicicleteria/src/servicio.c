#include <stdio.h>
#include <stdlib.h>
#include "servicio.h"

void mostrarServicio(eServicio unServicio, int tamS)
{
	if(tamS > 0)
	{
		printf("  %d   %10s   %d\n",
				unServicio.id,
				unServicio.descripcion,
				unServicio.precio
				);
	}
}

int mostrarServicios(eServicio servicios[], int tamS)
{
	int todoOk = 0;
	int flag = 1;
	if(servicios != NULL && tamS > 0)
	{
		system("clear");
		printf("  *** Listado de Servicios ***\n");
		printf("  Id     Descripcion    Precio\n");
	    printf("----------------------------\n");
		for(int i = 0; i < tamS; i++)
		{
			mostrarServicio(servicios[i], tamS);
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
