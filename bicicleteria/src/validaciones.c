#include <stdio.h>
#include <stdlib.h>
#include <stdio_ext.h>
#include "validaciones.h"

int esSoloLetras(char str[])
{
   int i = 0;
   while(str[i] != '\0')
   {
       if((str[i] != ' ') && (str[i] < 'a' || str[i] > 'z') && (str[i] < 'A' || str[i] > 'Z'))
           return 0;
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
			printf("Ingrese un valor numerico: ");
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


