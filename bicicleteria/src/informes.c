#include "informes.h"
#include "bicicleta.h"
#include "trabajo.h"
#include "tipo.h"
#include "color.h"
#include "validaciones.h"
#include "fecha.h"
#include <stdio.h>
#include <stdlib.h>
#include <stdio_ext.h>

int mostrarBicicletasColor(eBicicleta lista[], int tam, eTipo tipos[], int tamT, eColor colores[], int tamC)
{
	int todoOk = 0;
	int idColor;
	int flag = 1;
	int retornoColor;

	if(lista != NULL && tam > 0 && tipos != NULL && tamT > 0 && colores != NULL && tamC > 0)
	{
		system("clear");

		mostrarColores(colores, tamC);
		printf("\nIngrese el id de color: ");
		retornoColor = scanf("%d", &idColor);

		validarEntero(retornoColor, &idColor);
		while(!validarIdColor(colores, tamC, idColor))
		{
			printf("Error. Ingrese un id del listado de colores: ");
			retornoColor = scanf("%d", &idColor);
			validarEntero(retornoColor, &idColor);
		}

	    printf("\n             *** Listado de Bicicletas por color***\n");
		printf("   Id                Marca          Tipo        Color     Material   \n");
	    printf("---------------------------------------------------------------------\n");

		for(int i = 0; i < tam; i++)
		{
			if(lista[i].isEmpty == 0 && lista[i].idColor == idColor)
			{
				mostrarBicicleta(lista[i], tipos, tamT, colores, tamC);
				flag = 0;
			}
		}
		if(flag)
		{
			printf("No hay bicicletas de ese color para mostrar\n");
		}
		todoOk = 1;
	}
	return todoOk;
}

int mostrarBicicletasTipo(eBicicleta lista[], int tam, eTipo tipos[], int tamT, eColor colores[], int tamC)
{
	int todoOk = 0;
	int idTipo;
	int flag = 1;
	int retornoTipo;

	if(lista != NULL && tam > 0 && tipos != NULL && tamT > 0 && colores != NULL && tamC > 0)
	{
		system("clear");

		mostrarTipos(tipos, tamT);
		printf("\nIngrese el id del tipo que quiere: ");
		retornoTipo = scanf("%d", &idTipo);

		validarEntero(retornoTipo, &idTipo);
		while(!validarIdTipo(tipos, tamT, idTipo))
		{
			printf("Error. Ingrese un id del listado de tipos: ");
			retornoTipo = scanf("%d", &idTipo);
			validarEntero(retornoTipo, &idTipo);
		}

	    printf("\n              *** Listado de Bicicletas por tipo***\n");
		printf("   Id                Marca          Tipo        Color     Material   \n");
	    printf("---------------------------------------------------------------------\n");

		for(int i = 0; i < tam; i++)
		{
			if(lista[i].isEmpty == 0 && lista[i].idTipo == idTipo)
			{
				mostrarBicicleta(lista[i], tipos, tamT, colores, tamC);
				flag = 0;
			}
		}
		if(flag)
		{
			printf("No hay bicicletas de esa marca para mostrar\n");
		}
		todoOk = 1;
	}
	return todoOk;
}

int masCarbonoAluminio(eBicicleta lista[], int tam)
{
	int todoOk = 0;
	int contadorCarbono = 0;
	int contadorAluminio = 0;

	if(lista != NULL && tam > 0)
	{
		system("clear");
		printf("\n       *** Informe mayor cantidad de carbono o aluminio***\n");
		printf("---------------------------------------------------------------------\n");

		for(int i = 0; i < tam; i++)
		{
			if(lista[i].isEmpty == 0 && lista[i].material == 'c')
			{
				contadorCarbono++;
			}
			else if(lista[i].isEmpty == 0 && lista[i].material == 'a')
			{
				contadorAluminio++;
			}
		}
		if(contadorCarbono > contadorAluminio)
		{
			printf("\nHay mas bicicletas de carbono que de aluminio. Cantidad de carbono: %d\n", contadorCarbono);
		}
		else
		{
			printf("\nHay mas bicicletas de alumninio que de carbono. Cantidad de aluminio: %d\n", contadorAluminio);
		}
		todoOk = 1;
	}
	return todoOk;
}

int mostrarBicicletasSeparadasTipo(eBicicleta lista[], int tam, eTipo tipos[], int tamT, eColor colores[], int tamC)
{
	int todoOk = 0;
	int flag = 1;

	if(lista != NULL && tam > 0 && tipos != NULL && tamT > 0 && colores != NULL && tamC > 0)
	{
		system("clear");
		printf("\n         *** Listado de Bicicletas separadas por tipo***\n");
		printf("---------------------------------------------------------------------\n");

		for(int i = 0; i < tamT; i++)
		{
			printf("Tipo: %s\n\n", tipos[i].descripcion);
			for(int j = 0; j < tam; j++)
			{
				if(lista[j].isEmpty == 0 && lista[j].idTipo == tipos[i].id)
				{
					mostrarBicicleta(lista[j], tipos, tamT, colores, tamC);
					flag = 0;
					printf("\n");
				}
			}
		}
		if(flag)
		{
			printf("No hay bicicletas de ese tipo para mostrar\n");
		}
		todoOk = 1;
	}
	return todoOk;
}

int contarPorColorYTipo(eBicicleta lista[], int tam, eTipo tipos[], int tamT, eColor colores[], int tamC)
{
	int todoOk = 0;
	int idColor;
	int idTipo;
	int contador = 0;
	char descColor[10];
	char descTipo[10];
	int retornoColor;
	int retornoTipo;

	if(lista != NULL && tam > 0 && tipos != NULL && tamT > 0 && colores != NULL && tamC > 0)
	{
		system("clear");

		mostrarColores(colores, tamC);
		printf("\nIngrese el id de color: ");
		retornoColor = scanf("%d", &idColor);

		validarEntero(retornoColor, &idColor);
		while(!validarIdColor(colores, tamC, idColor))
		{
			printf("Error. Ingrese un id del listado de colores: ");
			retornoColor = scanf("%d", &idColor);
			validarEntero(retornoColor, &idColor);
		}

		printf("\n");

		mostrarTipos(tipos, tamT);
		printf("\nIngrese el id de tipo: ");
		retornoTipo = scanf("%d", &idTipo);

		validarEntero(retornoTipo, &idTipo);
		while(!validarIdTipo(tipos, tamT, idTipo))
		{
			printf("Error. Ingrese un id del listado de tipos: ");
			retornoTipo = scanf("%d", &idTipo);
			validarEntero(retornoTipo, &idTipo);
		}

		printf("\n  *** Informe cantidad de bicicletas de color y tipo elegido***\n");
		printf("---------------------------------------------------------------------\n");

		for(int i = 0; i < tam; i++)
		{
			if(lista[i].isEmpty == 0 && lista[i].idColor == idColor && lista[i].idTipo == idTipo)
			{
				contador++;
			}
		}

		cargarDescripcionColor(colores, tamC, idColor, descColor);
		cargarDescripcionTipo(tipos, tamT, idTipo, descTipo);

		printf("\nCantidad de bicicletas de color %s y tipo %s: %d\n", descColor, descTipo, contador);

		todoOk = 1;
	}
	return todoOk;
}

int colorMasElegido(eBicicleta lista[], int tam, eColor colores[], int tamC)
{
	int todoOk = 0;
	int contadores[5] = {0};
	int contadorMayor;
	int flagMayor = 1;

	if(lista != NULL && tam > 0 && colores != NULL && tamC > 0)
	{
		system("clear");
		printf("*** Color o colores mas elegidos por los clientes ***\n");
		printf("-----------------------------------------------------\n");

		for(int i = 0; i < tamC; i++)
		{
			for(int j = 0; j < tam; j++)
			{
				if(lista[j].isEmpty == 0 && lista[j].idColor  == colores[i].id)
				{
					contadores[i]++;
				}
			}
		}
		for(int i = 0; i < tamC; i++)
		{
			if(flagMayor || contadores[i] > contadorMayor)
			{
				contadorMayor = contadores[i];
				flagMayor = 0;
			}
		}
		for(int i = 0; i < tamC; i++)
		{
			if(contadores[i] == contadorMayor)
			{
				printf("%s\n", colores[i].nombreColor);
			}
		}
		todoOk = 1;
	}
	return todoOk;
}

int mostrarTrabajosBicicleta(eBicicleta lista[], int tam, eTipo tipos[], int tamT, eColor colores[], int tamC, eTrabajo trabajos[], eServicio servicios[], int tamS)
{
	int todoOk = 0;
	int idBicicleta;
	int retornoBicicleta;
	int flag = 1;

	if(lista != NULL && tam > 0 && tipos != NULL && tamT > 0 && colores != NULL && tamC > 0 && trabajos != NULL && servicios != NULL && tamS > 0)
	{
		system("clear");

		mostrarBicicletas(lista, tam, tipos, tamT, colores, tamC);
		printf("\nIngrese el id de la bicicleta: ");
		retornoBicicleta = scanf("%d", &idBicicleta);

		validarEntero(retornoBicicleta, &idBicicleta);

		while(!validarIdBicicleta(lista, tam, idBicicleta))
		{
			mostrarTipos(tipos, tamT);
			printf("Error. Ingrese un id del listado de bicicletas: ");
			retornoBicicleta = scanf("%d", &idBicicleta);
			validarEntero(retornoBicicleta, &idBicicleta);
		}

		printf("\n                *** Listado de trabajos***\n");
		printf("\n Id Trabajo    Id        Bicicleta      Servicio    Precio    Fecha\n");
	    printf("------------------------------------------------------------------------\n");

		for(int i = 0; i < tam; i++)
		{
			if(trabajos[i].isEmpty == 0 && trabajos[i].idBicicleta == idBicicleta)
			{
				mostrarTrabajo(trabajos[i], lista, tam, servicios, tamS);
				flag = 0;
			}
		}
		if(flag)
		{
			printf("No hay trabajos para mostrar de esa bicicleta\n");
		}
		todoOk = 1;
	}
	return todoOk;
}

int sumaImporteServicios(eBicicleta lista[], int tam, eTipo tipos[], int tamT, eColor colores[], int tamC, eTrabajo trabajos[], eServicio servicios[], int tamS)
{
	int todoOk = 0;
	int idBicicleta;
	int retornoBicicleta;
	int acumuladorImporte = 0;

	if(lista != NULL && tam > 0 && tipos != NULL && tamT > 0 && colores != NULL && tamC > 0 && trabajos != NULL && servicios != NULL && tamS > 0)
	{
		system("clear");

		mostrarBicicletas(lista, tam, tipos, tamT, colores, tamC);
		printf("\nIngrese el id de la bicicleta: ");
		retornoBicicleta = scanf("%d", &idBicicleta);

		validarEntero(retornoBicicleta, &idBicicleta);

		while(!validarIdBicicleta(lista, tam, idBicicleta))
		{
			mostrarTipos(tipos, tamT);
			printf("Error. Ingrese un id del listado de bicicletas: ");
			retornoBicicleta = scanf("%d", &idBicicleta);
			validarEntero(retornoBicicleta, &idBicicleta);
		}

		printf("\n    *** Informe de suma de los importes de los servicios***\n");
		printf("---------------------------------------------------------------------\n");

		for(int i = 0; i < tam; i++)
		{
			if(trabajos[i].isEmpty == 0 && trabajos[i].idBicicleta == idBicicleta)
			{
				for(int j = 0; j < tamS; j++)
				{
					if(servicios[j].id == trabajos[i].idServicio)
					{
						acumuladorImporte += servicios[j].precio;
					}
				}
			}
		}
		printf("\nSuma total de los importes de los servicios: %d\n", acumuladorImporte);
		todoOk = 1;
	}
	return todoOk;
}

int mostrarBicicletasServicio(eBicicleta lista[], int tam, eTipo tipos[], int tamT, eColor colores[], int tamC, eTrabajo trabajos[], eServicio servicios[], int tamS)
{
	int todoOk = 0;
	int idServicio;
	int retornoServicio;
	int flag = 1;

	if(lista != NULL && tam > 0 && tipos != NULL && tamT > 0 && colores != NULL && tamC > 0 && trabajos != NULL && servicios != NULL && tamS > 0)
	{
		system("clear");

		mostrarServicios(servicios, tamS);
		printf("\nIngrese el id del servicio: ");
		retornoServicio = scanf("%d", &idServicio);

		validarEntero(retornoServicio, &idServicio);

		while(!validarIdServicio(servicios, tamS, idServicio))
		{
			mostrarTipos(tipos, tamT);
			printf("Error. Ingrese un id del listado de bicicletas: ");
			retornoServicio = scanf("%d", &idServicio);
			validarEntero(retornoServicio, &idServicio);
		}

		printf("\n            *** Listado de Bicicletas por servicio***\n");
		printf("\n   Id Trabajo    Id        Bicicleta      Servicio    Precio    Fecha\n");
		printf("-----------------------------------------------------------------------------\n");

		for(int i = 0; i < tam; i++)
		{
			if(trabajos[i].isEmpty == 0 && trabajos[i].idServicio == idServicio)
			{
				mostrarTrabajo(trabajos[i], lista, tam, servicios, tamS);
				flag = 0;
			}
		}
		if(flag)
		{
			printf("No hay bicicletas a las que se les haya realizado ese servicio\n");
		}
		todoOk = 1;
	}
	return todoOk;
}

int mostrarServiciosFecha(eBicicleta lista[], int tam, eTipo tipos[], int tamT, eColor colores[], int tamC, eTrabajo trabajos[], eServicio servicios[], int tamS)
{
	int todoOk = 0;
	int retornoFecha;
	eFecha fecha;
	char descServicio[25];
	int flag = 1;

	if(lista != NULL && tam > 0 && tipos != NULL && tamT > 0 && colores != NULL && tamC > 0 && trabajos != NULL && servicios != NULL && tamS > 0)
	{
		system("clear");

		mostrarTrabajos(trabajos, tam, lista, servicios, tamS);
		printf("\nIngrese la fecha para mostrar los servicios realizados: ");
		__fpurge(stdin);
		retornoFecha = scanf("%d/%d/%d", &fecha.dia, &fecha.mes, &fecha.anio);
		validarFecha(retornoFecha, &fecha.dia, &fecha.mes, &fecha.anio);

		printf("\n              *** Listado de servicios por fecha***\n");
		printf("\n   Id Trabajo    Id        Bicicleta      Servicio    Precio    Fecha\n");
		printf("-----------------------------------------------------------------------------\n");

		for(int i = 0; i < tam; i++)
		{
			if(trabajos[i].isEmpty == 0 && lista[i].isEmpty == 0 &&
					trabajos[i].fecha.dia == fecha.dia &&
					trabajos[i].fecha.dia == fecha.mes &&
					trabajos[i].fecha.dia == fecha.anio)
			{
				cargarDescripcionServicio(servicios, tamS, trabajos[i].idServicio, descServicio);
				printf("%10s  %d/%d/%d\n", descServicio, fecha.dia, fecha.mes, fecha.anio);
				flag = 0;
			}
		}
		if(flag)
		{
			printf("No hay servicios realizados en esa fecha\n");
		}
		todoOk = 1;
	}
	return todoOk;
}
