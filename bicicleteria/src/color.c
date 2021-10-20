#include <stdio.h>
#include <stdlib.h>
#include <stdio_ext.h>
#include <string.h>
#include "color.h"

void mostrarColor(eColor unColor, int tamC)
{
	if(tamC > 0)
	{
		printf("  %d   %10s\n",
				unColor.id,
				unColor.nombreColor
				);
	}
}

int mostrarColores(eColor colores[], int tamC)
{
	int todoOk = 0;
	int flag = 1;
	if(colores != NULL && tamC > 0)
	{
		system("clear");
		printf("*** Listado de Colores ***\n");
		printf("    Id   Descripcion\n");
	    printf("--------------------------\n");
		for(int i = 0; i < tamC; i++)
		{
			mostrarColor(colores[i], tamC);
			flag = 0;
		}
		if(flag)
		{
			printf("No hay colores para mostrar\n");
		}
		todoOk = 1;
	}
	return todoOk;
}

int validarIdColor(eColor colores[], int tamC, int id)
{
	int existe = 0;
	if(colores != NULL && tamC > 0)
	{
		for(int i = 0;i < tamC; i++)
		{
			if(colores[i].id == id)
			{
				existe = 1;
				break;
			}
		}
	}
	return existe;
}

int cargarDescripcionColor(eColor colores[], int tamC, int idColor , char descripcion[])
{
	int todoOk = 0;
	if(colores != NULL && tamC > 0 && descripcion != NULL)
	{
		for(int i = 0; i < tamC; i++)
		{
			if(colores[i].id == idColor)
			{
				strcpy(descripcion, colores[i].nombreColor);
				break;
			}
		}
		todoOk = 1;
	}
	return todoOk;
}
