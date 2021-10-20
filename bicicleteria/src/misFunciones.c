#include <stdio.h>
#include <stdlib.h>
#include <stdio_ext.h>
#include "string.h"
#include "bicicleta.h"
#include "misFunciones.h"

int menu(void)
{
    int opcion;

    system("clear");
    printf("            *** ABM Bicicleteria ***              \n");
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
    printf("10- Salir\n");

    printf("\nIngresar opcion: ");
    scanf("%d", &opcion);

    return opcion;
}

int myGets(char auxBicicleta[], int tam)
{
	int todoOk = 0;
	char bufferString[50];

	if(auxBicicleta != NULL && tam > 0)
	{
		__fpurge(stdin);
		if(fgets(bufferString, sizeof(bufferString), stdin) != NULL)
		{
			if(bufferString[strnlen(bufferString, sizeof(bufferString)) - 1] == '\n')
			{
				bufferString[strnlen(bufferString, sizeof(bufferString)) - 1] = '\0';
			}
			if(strnlen(bufferString, sizeof(bufferString)) <= tam)
			{
				strncpy(auxBicicleta, bufferString, tam);
				todoOk = 1;
			}
		}
	}
	return todoOk;
}

int myGetsStruct(eBicicleta* auxBicicleta, int tam)
{
	int todoOk = 0;
	char bufferString[50];

	if(auxBicicleta != NULL && tam > 0)
	{
		__fpurge(stdin);
		if(fgets(bufferString, sizeof(bufferString), stdin) != NULL)
		{
			if(bufferString[strnlen(bufferString, sizeof(bufferString)) - 1] == '\n')
			{
				bufferString[strnlen(bufferString, sizeof(bufferString)) - 1] = '\0';
			}
			if(strnlen(bufferString, sizeof(bufferString)) <= tam)
			{
				strncpy(auxBicicleta->marca, bufferString, tam);
				todoOk = 1;
			}
		}
	}
	return todoOk;
}


