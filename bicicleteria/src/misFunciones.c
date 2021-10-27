#include <stdio.h>
#include <stdlib.h>
#include <stdio_ext.h>
#include "string.h"
#include "bicicleta.h"
#include "misFunciones.h"
#include "servicio.h"
#include "trabajo.h"
#include "informes.h"

int menu(void)
{
    int opcion;

    system("clear");
    printf("           *** ABM Bicicleteria ***\n");
    printf("---------------------------------------------\n");
    printf("1- Alta bicicleta\n");
    printf("2- Modificar bicicleta\n");
    printf("3- Baja bicicleta\n");
    printf("4- Listar bicicletas\n");
    printf("5- Listar tipos\n");
    printf("6- Listar colores\n");
    printf("7- Listar servicios\n");
    printf("8- Alta trabajo\n");
    printf("9- Listar trabajos\n");
    printf("10- Informes\n");
    printf("11- Salir\n");

    printf("\nIngresar opcion: ");
    scanf("%d", &opcion);

    return opcion;
}

int menuInformes(void)
{
	int opcion;

	system("clear");
	printf("                    *** Informes ***\n");
	printf("------------------------------------------------------------\n");

	printf("1- Mostrar bicicletas de un color\n");
	printf("2- Mostrar bicicletas de un tipo\n");
	printf("3- Material mas abundante y su cantidad\n");
	printf("4- Mostrar bicicletas separadas por tipo\n");
	printf("5- Cantidad de bicicletas de un color y tipo seleccionado\n");
	printf("6- Color/es mas elegido/s por los clientes\n");
	printf("7- Mostrar todos los trabajos que se le hicieron a una bicicleta\n");
	printf("8- Suma de los importes de los servicios que se le hicieron a una bicicleta\n");
	printf("9- Mostrar las bicicletas a las que se les realizo un servicio y la fecha\n");
	printf("10- Mostrar los servicios realizados en una fecha\n");

    printf("\nIngresar opcion: ");
    scanf("%d", &opcion);

    return opcion;
}

int informes(eBicicleta lista[], int tam, eTipo tipos[], int tamT, eColor colores[], int tamC, eServicio servicios[], int tamS, eTrabajo trabajos[])
{
	int todoOk = 0;
	if(lista != NULL && tam > 0 && tipos != NULL && tamT > 0 && colores != NULL && tamC > 0 && servicios != NULL && tamS > 0 && trabajos != NULL)
	{
		switch(menuInformes())
		{
		case 1:
			if(!mostrarBicicletasColor(lista, tam, tipos, tamT, colores, tamC))
			{
				printf("Hubo un problema al mostrar las bicicletas por color\n");
			}
			break;
		case 2:
			if(!mostrarBicicletasTipo(lista, tam, tipos, tamT, colores, tamC))
			{
				printf("Hubo un problema al mostra las bicicletas por tipo\n");
			}
			break;
		case 3:
			if(!masCarbonoAluminio(lista, tam))
			{
				printf("Hubo un problema al mostrar de que material hay mayor cantidad de bicicletas\n");
			}
			break;
		case 4:
			if(!mostrarBicicletasSeparadasTipo(lista, tam, tipos, tamT, colores, tamC))
			{
				printf("Hubo un problema al mostrar las bicicletas separadas por tipo\n");
			}
			break;
		case 5:
			if(!contarPorColorYTipo(lista, tam, tipos, tamT, colores, tamC))
			{
				printf("Hubo un problema al contar por color y tipo\n");
			}
			break;
		case 6:
			if(!colorMasElegido(lista, tam, colores, tamC))
			{
				printf("Hubo un problema al mostrar el color mas elegido\n");
			}
			break;
		case 7:
			if(!mostrarTrabajosBicicleta(lista, tam, tipos, tamT, colores, tamC, trabajos, servicios, tamS))
			{
				printf("Hubo un problema al mostrar los trabajos de la bicicleta\n");
			}
			break;
		case 8:
			if(!sumaImporteServicios(lista, tam, tipos, tamT, colores, tamC, trabajos, servicios, tamS))
			{
				printf("Hubo un problema al mostrar la suma de los importes de los servicios\n");
			}
			break;
		case 9:
			if(!mostrarBicicletasServicio(lista, tam, tipos, tamT, colores, tamC, trabajos, servicios, tamS))
			{
				printf("Hubo un problema al mostrar las bicicletas a las que se les realizo el servicio y la fecha\n");
			}
			break;
		case 10:
			if(!mostrarServiciosFecha(lista, tam, tipos, tamT, colores, tamC, trabajos, servicios, tamS))
			{
				printf("Hubo un problema al mostrar los servicios realizados en esa fecha\n");
			}
			break;
		default:
			printf("Opcion invalida\n");
		}
		todoOk = 1;
	}

	return todoOk;
}

int pedirString(char string[], int len, int min)
{
	int todoOk = 0;
	char bufferString[100];

	if(string != NULL && len > 0)
	{
		__fpurge(stdin);
		if(fgets(bufferString, sizeof(bufferString), stdin) != NULL)
		{
			if(bufferString[strnlen(bufferString, sizeof(bufferString)) - 1] == '\n')
			{
				bufferString[strnlen(bufferString, sizeof(bufferString)) - 1] = '\0';
			}
			if(strnlen(bufferString, sizeof(bufferString)) >= min &&
					strnlen(bufferString, sizeof(bufferString)) <= len)
			{
				strncpy(string, bufferString, len);
				todoOk = 1;
			}
		}
	}
	return todoOk;
}

