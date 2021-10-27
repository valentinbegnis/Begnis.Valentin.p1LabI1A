/*
 ============================================================================
 Name        : bicicleteria.c
 Author      : Begnis Valentin
 Description : Parcial 1 - Laboratorio I
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include <stdio_ext.h>
#include "bicicleta.h"
#include "trabajo.h"
#include "tipo.h"
#include "color.h"
#include "servicio.h"
#include "misFunciones.h"
#include "dataWarehouse.h"
#include "cliente.h"

#define TAM 10
#define TAM_T 4
#define TAM_C 5
#define TAM_S 4

int main(void) {

    char seguir = 's';
    int nextIdBicicleta = 2000;
    int nextIdTrabajo = 3000;
    int flag = 1;

    eBicicleta lista[TAM];
    eTipo tipos[TAM_T] = {
    		{1000, "Rutera"},
			{1001, "Carrera"},
			{1002, "Mountain"},
			{1003, "Bmx"}
    };
    eColor colores[TAM_C] = {
    		{5000, "Gris"},
			{5001, "Blanco"},
			{5002, "Azul"},
			{5003, "Negro"},
			{5004, "Rojo"}
    };
    eServicio servicios[TAM_S] = {
    		{20000, "Limpieza", 30},
    		{20001, "Parche", 400},
    		{20002, "Centrado", 500},
    		{20003, "Cadena", 450}
    };
    eTrabajo trabajos[TAM];

    /*
    eCliente clientes[TAM] = {
    		{10, "Juan", 'm'},
    		{11, "Maria", 'f'},
    		{12, "Ana", 'f'},
    		{13, "Lucio", 'm'},
    		{14, "Martin", 'm'},
    		{15, "Jacinta", 'f'},
    		{16, "Ramon", 'm'},
    		{17, "Carlos", 'm'},
    		{18, "Claudia", 'f'},
    		{19, "Juano", 'm'},
    };
    */

    if(!inicializarBicicleta(lista, TAM))
    {
    	printf("Ocurrio un problema al inicializar las bicicletas\n");
    }
    if(!inicializarTrabajo(trabajos, TAM))
    {
    	printf("Ocurrio un problema al inicializar los trabajos\n");
    }

    //hardcodearBicicletas(lista, TAM, 9, &nextIdBicicleta);
    //hardcodearTrabajos(trabajos, TAM, 9, &nextIdTrabajo);

    do
    {
        switch(menu())
        {
            case 1:
                if(altaBicicleta(lista, TAM, tipos, TAM_T, colores, TAM_C, &nextIdBicicleta))
                {
                	flag = 0;
                	printf("\nAlta exitosa\n");
                }
                else
                {
                	printf("Hubo un problema al dar de alta\n");
                }
                break;
            case 2:
            	if(!flag)
            	{
            		if(modificarBicicleta(lista, TAM, tipos, TAM_T, colores, TAM_C))
					{
					printf("\nModificacion exitosa\n");
					}
					else
					{
					printf("Hubo un problema al modificar\n");
					}
            	}
            	else
            	{
					printf("Debe dar de alta por lo menos una bicicleta primero\n");
            	}
            	break;
			case 3:
				if(!flag)
				{
	                if(bajaBicicleta(lista, TAM, tipos, TAM_T, colores, TAM_C))
	                {
	                	printf("\nBaja exitosa\n");
	                }
	                else
	                {
	                	printf("Hubo un problema al dar de baja\n");
	                }
				}
                else
                {
					printf("Debe dar de alta por lo menos una bicicleta primero\n");
                }
				break;
			case 4:
				if(!flag)
				{
					if(!ordenarBicicleta(lista, TAM, tipos, TAM_T))
					{
						printf("Hubo un problema al ordenar\n");
					}
					if(!mostrarBicicletas(lista, TAM, tipos, TAM_T, colores, TAM_C))
					{
						printf("Hubo un problema al mostrar\n");
					}
				}
				else
				{
					printf("Debe dar de alta por lo menos una bicicleta primero\n");
				}
				break;
			case 5:
	            if(!mostrarTipos(tipos, TAM_T))
				{
					printf("Hubo un problema al mostrar\n");
				}
				break;
			case 6:
	            if(!mostrarColores(colores, TAM_C))
					{
						printf("Hubo un problema al mostrar\n");
					}
	            break;
			case 7:
	            if(!mostrarServicios(servicios, TAM_S))
					{
						printf("Hubo un problema al mostrar\n");
					}
	            break;
			case 8:
				if(!flag)
				{
				   if(altaTrabajos(trabajos, lista, TAM, tipos, TAM_T, colores, TAM_C, servicios, TAM_S, &nextIdTrabajo))
					{
						printf("\nAlta exitosa\n");
					}
					else
					{
						printf("Hubo un problema al dar de alta\n");
					}
				}
				else
				{
					printf("Debe dar de alta por lo menos una bicicleta primero\n");
				}
				break;
			case 9:
	            if(!mostrarTrabajos(trabajos, TAM, lista, servicios, TAM_S))
					{
						printf("Hubo un problema al mostrar\n");
					}
	            break;
	        //Informes
			case 10:
				if(!flag)
				{
					if(!informes(lista, TAM, tipos, TAM_T, colores, TAM_C, servicios, TAM_S, trabajos))
					{
						printf("Hubo un problema al mostrar los informes\n");
					}
				}
				else
				{
					printf("Debe dar de alta por lo menos una bicicleta primero\n");
				}
				break;
			case 11:
				printf("Saliste\n");
				seguir = 'n';
				break;
            default:
                 printf("Opcion invalida\n");
        }
        printf("\nPresione cualquier tecla para continuar...\n");
        __fpurge(stdin);
        getchar();
    }while(seguir == 's');

	return EXIT_SUCCESS;
}
