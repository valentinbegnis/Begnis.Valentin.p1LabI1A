#include <stdio.h>
#include <stdlib.h>
#include <stdio_ext.h>
#include <string.h>
#include <ctype.h>
#include "bicicleta.h"
#include "tipo.h"
#include "color.h"
#include "servicio.h"
#include "trabajo.h"
#include "misFunciones.h"
#include "validaciones.h"
#include "cliente.h"

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
	int stringValido, soloLetras;
	int retornoTipo, retornoColor, retornoMaterial;
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

			printf("Ingrese marca (20 caracteres maximo): ");
			stringValido = pedirString(auxBicicleta.marca, sizeof(auxBicicleta.marca), 1);
			soloLetras = esSoloLetras(auxBicicleta.marca);

			while(!stringValido || !soloLetras)
			{
				printf("Error. Marca invalida, ingrese nuevamente: ");
				stringValido = pedirString(auxBicicleta.marca, tam, 1);
				soloLetras = esSoloLetras(auxBicicleta.marca);
			}

			mostrarTipos(tipos, tamT);
			printf("\nIngrese id del tipo: ");
			retornoTipo = scanf("%d", &auxBicicleta.idTipo);
			validarEntero(retornoTipo, &auxBicicleta.idTipo);

			while(!validarIdTipo(tipos, tamT, auxBicicleta.idTipo))
				{
					printf("Error. Ingrese un id del listado de tipos: ");
					retornoTipo = scanf("%d", &auxBicicleta.idTipo);
					validarEntero(retornoTipo, &auxBicicleta.idTipo);
				}

			mostrarColores(colores, tamC);
			printf("\nIngrese id del color: ");
			retornoColor = scanf("%d", &auxBicicleta.idColor);
			validarEntero(retornoColor, &auxBicicleta.idColor);

			while(!validarIdColor(colores, tamC, auxBicicleta.idColor))
				{
					printf("Error. Ingrese un id del listado de colores: ");
					retornoColor = scanf("%d", &auxBicicleta.idColor);
					validarEntero(retornoColor, &auxBicicleta.idColor);
				}

			printf("\nIngrese material ('c' o 'a'): ");
			__fpurge(stdin);
			retornoMaterial = scanf("%c", &auxBicicleta.material);
			validarCaracter(retornoMaterial, &auxBicicleta.material, 'c', 'a');

			auxBicicleta.isEmpty = 0;
			lista[indice] = auxBicicleta;

			todoOk = 1;
		}
	}
	return todoOk;
}

int mostrarBicicleta(eBicicleta unaBicicleta, eTipo tipos[], int tamT,  eColor colores[], int tamC)
{
	int todoOk = 0;
	char descTipo[10];
	char descColor[10];
	char descMaterial[10];

	if(tipos != NULL && tamT > 0 && colores != NULL && tamC > 0)
	{
		cargarDescripcionTipo(tipos, tamT, unaBicicleta.idTipo, descTipo);
		cargarDescripcionColor(colores, tamC, unaBicicleta.idColor, descColor);
		cargarDescripcionMaterial(unaBicicleta, descMaterial);

		printf("  %d %20s      %8s      %6s     %8s\n",
				unaBicicleta.id,
				unaBicicleta.marca,
				descTipo,
				descColor,
				descMaterial
				);
		todoOk = 1;
	}
	return todoOk;
}

int mostrarBicicletas(eBicicleta lista[], int tam, eTipo tipos[], int tamT, eColor colores[], int tamC)
{
	int todoOk = 0;
	int flag = 1;
	if(lista != NULL && tam > 0 && tipos != NULL && tamT > 0 && colores != NULL && tamC > 0)
	{
		system("clear");
	    printf("                *** Listado de Bicicletas ***\n");
		printf("   Id                Marca          Tipo        Color     Material   \n");
	    printf("---------------------------------------------------------------------\n");
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
    printf("3- Salir\n");

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
	int retornoTipo, retornoMaterial;

	if(lista != NULL && tam > 0 && tipos != NULL && tamT > 0 && colores != NULL && tamC > 0)
	{
		system("clear");
		printf("       		    *** Modificar Bicicleta ***\n");
		printf("------------------------------------------------------------\n");
		mostrarBicicletas(lista, tam, tipos, tamT, colores, tamC);
		printf("\nIngrese id: ");
		scanf("%d", &id);

		indice = buscarBicicletaId(lista, tam, id);

		if(indice == -1)
		{
			printf("\nNo existe una bicicleta con ese id\n");
		}
		else
		{
			printf("Confirmar modificacion ('s' para confirmar): ");
			__fpurge(stdin);
			scanf("%c", &confirma);

			confirma = tolower(confirma);

			if(confirma == 's')
			{
				printf("\n");
				switch(menuModificacion())
				{
				case 1:
					mostrarTipos(tipos, tamT);
					printf("\nIngrese nuevo tipo: ");
					retornoTipo = scanf("%d", &auxIdTipo);
					validarEntero(retornoTipo, &auxIdTipo);

					while(!validarIdTipo(tipos, tamT, auxIdTipo))
					{
						mostrarTipos(tipos, tamT);
						printf("Error. Ingrese un id del listado de tipos: ");
						retornoTipo = scanf("%d", &auxIdTipo);
						validarEntero(retornoTipo, &auxIdTipo);
					}

					lista[indice].idTipo = auxIdTipo;
					todoOk = 1;
					break;
				case 2:
					printf("\nIngrese nuevo material ('c' o 'a'): ");
					__fpurge(stdin);
					retornoMaterial = scanf("%c", &auxMaterial);
					validarCaracter(retornoMaterial, &auxMaterial, 'c', 'a');

					lista[indice].material = auxMaterial;
					todoOk = 1;
					break;
				case 3:
					printf("Saliste\n");
					todoOk = 0;
					break;
				default:
					printf("Opcion invalida\n");
					todoOk = 0;
				}
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
		printf("                  *** Baja Bicicleta ***\n");
		printf("------------------------------------------------------------\n");

		mostrarBicicletas(lista, tam, tipos, tamT, colores, tamC);
		printf("\nIngrese id: ");
		scanf("%d", &id);

		indice = buscarBicicletaId(lista, tam, id);

		if(indice == -1)
		{
			printf("No existe una bicicleta con ese id\n");
		}
		else
		{
			printf("Confirmar baja ('s' para confirmar): ");
			__fpurge(stdin);
			scanf("%c", &confirma);

			if(confirma == 's')
			{
				lista[indice].isEmpty = 1;
				todoOk = 1;
			}
			else
			{
				printf("\nSe ha cancelado la baja \n");
			}
		}
	}
	return todoOk;
}

int ordenarBicicleta(eBicicleta lista[], int tam, eTipo tipos[], int tamT)
{
	int todoOk = 0;
	eBicicleta auxBicicleta;
	char descTipo[9];
	char descTipoDos[9];

	if(lista != NULL && tam > 0)
	{
		for(int i = 0; i < tam - 1; i++)
		{
			for(int j = i + 1; j < tam; j++)
			{
				cargarDescripcionTipo(tipos, tamT, lista[i].idTipo, descTipo);
				cargarDescripcionTipo(tipos, tamT, lista[j].idTipo, descTipoDos);

				if(strcmp(descTipo, descTipoDos) > 0 ||
						(strcmp(descTipo, descTipoDos) == 0 &&
						lista[i].material > lista[j].material))
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

int cargarDescripcionMaterial(eBicicleta unaBicicleta, char descripcion[])
{
	int todoOk = 0;
	if(descripcion != NULL)
	{
		if(unaBicicleta.material == 'c')
		{
			strcpy(descripcion, "Carbono");
			todoOk = 1;
		}
		else if(unaBicicleta.material == 'a')
		{
			strcpy(descripcion, "Aluminio");
			todoOk = 1;
		}
	}
	return todoOk;
}










