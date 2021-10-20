#include <stdio.h>
#include <stdlib.h>
#include <stdio_ext.h>
#include <string.h>
#include <ctype.h>
#include "bicicleta.h"
#include "tipo.h"
#include "color.h"
#include "misFunciones.h"
#include "validaciones.h"

int inicializarBicicleta(eBicicleta lista[], int tam)
{
	int todoOk = 0;
	if(lista != NULL && tam > 0)
	{
		for(int i = 0; i < tam; i++)
		{
			lista[i].isEmpty = 1;
		}
		todoOk = 1;
	}
	return todoOk;
}

int buscarLibreBicicleta(eBicicleta lista[], int tam)
{
	int indice = -1;
	if(lista != NULL && tam > 0)
	{
		for(int i = 0; i < tam; i++)
		{
			if(lista[i].isEmpty == 1)
			{
				indice = i;
				break;
			}
		}
	}
	return indice;
}

int altaBicicleta(eBicicleta lista[], int tam, eTipo tipos[], int tamT, eColor colores[], int tamC, int* pId)
{
	int todoOk = 0;
	int indice;
	int stringValido;
	int retornoTipo;
	int retornoColor;
	eBicicleta auxBicicleta;

	if(lista != NULL && tam > 0 && tipos != NULL && tamT > 0 && colores != NULL && tamC > 0 && pId != NULL)
	{
		system("clear");
	    printf("            *** Alta Bicicleta ***              \n");
	    printf("---------------------------------------------\n");

		indice = buscarLibreBicicleta(lista, tam);
		if(indice == -1)
		{
			printf("No hay lugar en el sistema\n");
		}
		else
		{
			auxBicicleta.id = *pId;
			(*pId)++;

			printf("Ingrese marca: ");
			myGetsStruct(&auxBicicleta, sizeof(auxBicicleta.marca));
			stringValido = esSoloLetras(auxBicicleta.marca);

			while(!stringValido)
			{
				printf("Ingrese marca: ");
				myGetsStruct(&auxBicicleta, sizeof(auxBicicleta.marca));
				stringValido = esSoloLetras(auxBicicleta.marca);
			}

			mostrarTipos(tipos, tamT);
			printf("Ingrese id del tipo: ");
			retornoTipo = scanf("%d", &auxBicicleta.idTipo);
			//validarEntero(retornoTipo, &auxBicicleta.idTipo);

			while(!validarIdTipo(tipos, tamT, auxBicicleta.idTipo))
				{
					mostrarTipos(tipos, tamT);
					printf("Error. Ingrese un id de tipo valido: ");
					retornoTipo = scanf("%d", &auxBicicleta.idTipo);
				}

			mostrarColores(colores, tamC);
			printf("Ingrese id del color: ");
			retornoColor = scanf("%d", &auxBicicleta.idColor);
			//validarEntero(retornoColor, &auxBicicleta.idColor);

			while(!validarIdColor(colores, tamC, auxBicicleta.idColor))
				{
					mostrarColores(colores, tamC);
					printf("Error. Ingrese un id de color valido: ");
					retornoColor = scanf("%d", &auxBicicleta.idColor);
				}

			printf("Ingrese material ('c' o 'a'): ");
			__fpurge(stdin);
			scanf("%c", &auxBicicleta.material);

			auxBicicleta.isEmpty = 0;

			lista[indice] = auxBicicleta;
		}
		todoOk = 1;
	}
	return todoOk;
}

void mostrarBicicleta(eBicicleta unaBicicleta, eTipo tipos[], int tamT,  eColor colores[], int tamC)
{
	char descTipo[20];
	char descColor[20];

	cargarDescripcionTipo(tipos, tamT, unaBicicleta.idTipo, descTipo);
	cargarDescripcionColor(colores, tamC, unaBicicleta.idColor, descColor);

	printf("  %d    %10s   %10s   %10s   %c    \n",
			unaBicicleta.id,
			unaBicicleta.marca,
			descTipo,
			descColor,
			unaBicicleta.material
			);
}

int mostrarBicicletas(eBicicleta lista[], int tam, eTipo tipos[], int tamT, eColor colores[], int tamC)
{
	int todoOk = 0;
	int flag = 1;
	if(lista != NULL && tam > 0)
	{
		system("clear");
	    printf("       *** Listado de Bicicletas ***      \n");
		printf("   Id   Marca    Tipo   Color   Material\n");
	    printf("--------------------------------------------\n");
		for(int i = 0; i < tam; i++)
		{
			if(lista[i].isEmpty == 0)
			{
				mostrarBicicleta(lista[i], tipos, tamT, colores, tamC);
				flag = 0;
			}
		}
		if(flag)
		{
			printf("No hay bicicletas para mostrar\n");
		}
		todoOk = 1;
	}
	return todoOk;
}

int menuModificacion()
{
    int opcion;

    printf("1- Tipo\n");
    printf("2- Material\n");

    printf("\nIngresar opcion: ");
    scanf("%d", &opcion);

    return opcion;
}

int modificarBicicleta(eBicicleta lista[], int tam, eTipo tipos[], int tamT, eColor colores[], int tamC)
{
	int todoOk = 0;
	int id;
	int indice;
	char confirma;
	int auxIdTipo;
	char auxMaterial;

	if(lista != NULL && tam > 0 && tipos != NULL && tamT > 0 && colores != NULL && tamC > 0)
	{
		system("clear");
		printf("       *** Modificar Bicicleta ***      \n");
		printf("----------------------------------\n");

		printf("Ingrese id: ");
		scanf("%d", &id);

		indice = buscarBicicletaId(lista, tam, id);

		if(indice == -1)
		{
			printf("No existe una bicicleta con ese id: %d\n", id);
		}
		else
		{
			mostrarBicicleta(lista[indice], tipos, tamT, colores, tamC);
			printf("¿Confirmar modificacion? ('s' para confirmar)\n");
			__fpurge(stdin);
			scanf("%c", &confirma);

			confirma = tolower(confirma);

			if(confirma == 's')
			{
				switch(menuModificacion())
				{
				case 1:
					mostrarTipos(tipos, tamT);
					printf("\nIngrese nuevo tipo: ");
					scanf("%d", &auxIdTipo);
					lista[indice].idTipo = auxIdTipo;
					break;
				case 2:
					printf("\nIngrese nuevo material ('c' o 'a'): ");
					__fpurge(stdin);
					scanf("%c", &auxMaterial);
					lista[indice].material = auxMaterial;
					break;
				}
				todoOk = 1;
			}
			else
			{
				printf("\nSe ha cancelado la modificacion \n");
			}
		}
	}
	return todoOk;
}

int buscarBicicletaId(eBicicleta lista[], int tam, int id)
{
	int indice = -1;
	if(lista != NULL && tam > 0)
	{
		for(int i = 0; i < tam; i++)
		{
			if(lista[i].isEmpty == 0 && lista[i].id == id)
			{
				indice = i;
				break;
			}
		}
	}
	return indice;
}

int bajaBicicleta(eBicicleta lista[], int tam, eTipo tipos[], int tamT, eColor colores[], int tamC)
{
	int todoOk = 0;
	int id;
	int indice;
	char confirma;

	if(lista != NULL && tam > 0 && tipos != NULL && tamT > 0 && colores != NULL && tamC > 0)
	{
		system("clear");
		printf("       *** Baja Bicicleta ***      \n");
		printf("----------------------------------\n");

		printf("Ingrese id: ");
		scanf("%d", &id);

		indice = buscarBicicletaId(lista, tam, id);

		if(indice == -1)
		{
			printf("No existe una bicicleta con ese id: %d\n", id);
		}
		else
		{
			mostrarBicicleta(lista[indice], tipos, tamT, colores, tamC);
			printf("Confirma baja? \n");
			__fpurge(stdin);
			scanf("%c", &confirma);

			if(confirma == 's')
			{
				lista[indice].isEmpty = 1;
				todoOk = 1;
			}
			else
			{
				printf("Se ha cancelado la baja \n");
			}
		}
	}
	return todoOk;
}

int ordenarBicicleta(eBicicleta lista[], int tam)
{
	int todoOk = 0;
	eBicicleta auxBicicleta;
	if(lista != NULL && tam > 0)
	{
		for(int i = 0; i < tam - 1; i++)
		{
			for(int j = i + 1; j < tam; j++)
			{
				if(lista[i].idTipo > lista[j].idTipo ||
						(lista[i].idTipo == lista[j].idTipo &&
						lista[i].material > lista[j].material) > 0)
				{
					auxBicicleta = lista[i];
					lista[i] = lista[j];
					lista[j] = auxBicicleta;
				}
			}
		}
		todoOk = 1;
	}
	return todoOk;
}

int validarIdBicicleta(eBicicleta lista[], int tam, int id)
{
	int existe = 0;
	if(lista != NULL && tam > 0)
	{
		for(int i = 0;i < tam; i++)
		{
			if(lista[i].id == id)
			{
				existe = 1;
				break;
			}
		}
	}
	return existe;
}

int cargarDescripcionBicicleta(eBicicleta lista[], int tam, int idBicicleta , char descripcion[])
{
	int todoOk = 0;
	if(lista != NULL && tam > 0 && descripcion != NULL)
	{
		for(int i = 0; i < tam; i++)
		{
			if(lista[i].id == idBicicleta)
			{
				strcpy(descripcion, lista[i].marca);
				break;
			}
		}
		todoOk = 1;
	}
	return todoOk;
}
