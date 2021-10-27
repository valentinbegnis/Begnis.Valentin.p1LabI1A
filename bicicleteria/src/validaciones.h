#ifndef VALIDACIONES_H_
#define VALIDACIONES_H_

/**
 * @brief Valida que el dato ingresado sea un string
 * @param str a validar
 * @return 0 si no lo es, 1 si lo es
 */
int esSoloLetras(char str[]);

/**
 * @brief Valida que el dato ingresado sea un numero
 * @param ret Entero retorno del scanf
 * @param number Direccion de memoria del numero a validar
 * @return 0 si no lo es, 1 si lo es
 */
int validarEntero(int ret, int* number);

/**
 * @brief Valida que el caracter ingresado sea igual a charUno o charDos
 * @param ret Entero retorno del scanf
 * @param charIngresado Direccion de memoria del caracter a validar
 * @param charUno Primer caracter con el que se hara la comparacion
 * @param charDos Segundo caracter con el que se hara la comparacion
 * @return 0 si hubo error, 1 si no lo hubo
 */
int validarCaracter(int ret, char* charIngresado, char charUno, char charDos);

/**
 * @brief Valida la fecha ingresada
 * @param ret Entero retorno del scanf
 * @param dia Campo dia de la estructura eFecha
 * @param mes Campo mes de la estructura eFecha
 * @param anio Campo anio de la estructura eFecha
 */
void validarFecha(int ret, int* dia, int* mes, int* anio);

#endif /* VALIDACIONES_H_ */
