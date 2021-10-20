#include <stdio.h>
#include <stdlib.h>
#include <stdio_ext.h>
#include "tipo.h"

void mostrarTipo(eTipo unTipo, int tamT)
{
	if(tamT > 0)
	{
		printf("  %d   %10s\n",
				unTipo.id,
				unTipo.descripcion
				);
	}
}

int mostrarTipos(eTipo tipos[], int tamT)
{
	int todoOk = 0;
	int flag = 1;
	if(tipos != NULL && tamT > 0)
	{
		system("clear");
		printf(" *** Listado de Tipos ***\n");
		printf("   Id   Descripcion\n");
	    printf("----------------------------\n");
		for(int i = 0; i < tamT; i++)
		{
			mostrarTipo(tipos[i], tamT);
			flag = 0;
		}
		if(flag)
		{
			printf("No hay tipos para mostrar\n");
		}
		todoOk = 1;
	}
	return todoOk;
}

int validarIdTipo(eTipo tipos[], int tamT, int id)
{
	int existe = 0;
	if(tipos != NULL && tamT > 0)
	{
		for(int i = 0;i < tamT; i++)
		{
			if(tipos[i].id == id)
			{
				existe = 1;
				break;
			}
		}
	}
	return existe;
}

int cargarDescripcionTipo(eTipo tipos[], int tamT, int idTipo , char descripcion[])
{
	int todoOk = 0;
	if(tipos != NULL && tamT > 0 && descripcion != NULL)
	{
		for(int i = 0; i < tamT; i++)
		{
			if(tipos[i].id == idTipo)
			{
				strcpy(descripcion, tipos[i].descripcion);
				break;
			}
		}
		todoOk = 1;
	}
	return todoOk;
}
