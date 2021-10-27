#include <stdio.h>
#include <stdlib.h>
#include <stdio_ext.h>
#include <ctype.h>
#include "validaciones.h"
#include "misFunciones.h"

int esSoloLetras(char str[])
{
	int i = 0;
	while(str[i] != '\0')
	{
		if((str[i] != ' ') && (str[i] < 'a' || str[i] > 'z') && (str[i] < 'A' || str[i] > 'Z'))
		{
		   return 0;
		}
		i++;
	}
	return 1;
}

int validarEntero(int ret, int* number)
{
	int todoOk = 0;

	if(number != NULL)
	{
		while(ret != 1)
		{
			printf("Error. Ingrese un valor numerico: ");
			__fpurge(stdin);
			ret = scanf("%d", number);
		}
		if(ret == 1)
		{
			todoOk = 1;
		}
	}
	return todoOk;
}

int validarCaracter(int ret, char* charIngresado, char charUno, char charDos)
{
	int todoOk = 0;

	if(charIngresado != NULL)
	{
		charUno = tolower(charUno);
		charDos = tolower(charDos);

		while(ret != 1)
		{
			printf("Error. Ingrese un caracter: ");
			__fpurge(stdin);
			ret = scanf("%c", charIngresado);
		}

		if(ret == 1)
		{
			*charIngresado = tolower(*charIngresado);

			while(*charIngresado != charUno && *charIngresado != charDos)
			{
				printf("Error. Ingrese un caracter correcto '%c' o '%c': ", charUno, charDos);
				__fpurge(stdin);
				scanf("%c", charIngresado);
				*charIngresado = tolower(*charIngresado);
			}
			todoOk = 1;
		}
	}
	return todoOk;
}

void validarFecha(int ret, int* dia, int* mes, int* anio)
{
	while(ret != 3 ||
			(*dia < 1 || *dia > 31) ||
			(*mes < 1 || *mes > 12) ||
			(*anio < 0 || *anio > 2021))
	{
		printf("Error. Ingrese una fecha valida: ");
		__fpurge(stdin);
		ret = scanf("%d/%d/%d", dia, mes, anio);
	}
}
