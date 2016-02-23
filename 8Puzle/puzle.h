/***************************************************************************
* Name:		8Puzle
* FileName:	puzle.h
*
* Author:	Jose M Barba Gonzalez
* Created:	19/02/16 - vie febrero 19 17:52:48 2016
* License:	GPL version 3
* Copyright (C) 2016 Jose M Barba Gonzalez
* <zerokullneo@wordpress.com>
****************************************************************************/
/*
* 
*
* Copyright (C) 2016 - Jose M Barba Gonzalez
*
* This program is free software; you can redistribute it and/or modify
* it under the terms of the GNU General Public License as published by
* the Free Software Foundation; either version 3 of the License, or
* (at your option) any later version.
*
* This program is distributed in the hope that it will be useful,
* but WITHOUT ANY WARRANTY; without even the implied warranty of
* MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
* GNU General Public License for more details.
*
* You should have received a copy of the GNU General Public License
* along with this program. If not, see <http://www.gnu.org/licenses/>.
*/

/********************************************/
/*					PUZLE.H					*/
/*											*/
/*	Asignatura: Inteligencia Artificial		*/
/*	Grado en Ingenieria Informatica - UCA	*/
/********************************************/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define ARRIBA 1
#define ABAJO 2
#define IZQUIERDA 3
#define DERECHA 4
#define NUM_OPERADORES 4
#define N 3

#define ERROR(s) printf("%s\n", s);

#ifndef _tEstado_
#define _tEstado_
	typedef struct
	{
		int celdas[N][N];
		int fila[N*N], col[N*N];
	}tEstado;
#endif

#ifndef _PUZLE_INICIAL_
#define _PUZLE_INICIAL_
static int puzle_inicial[N][N]=
{
	{1,7,3},
	{6,2,4},
	{8,5,0}
};
/*static int puzle_inicial[N][N]=
{
	{0,1},
	{3,2}
};*/
#endif

#ifndef _PUZLE_FINAL_
#define _PUZLE_FINAL_
static int puzle_final[N][N]=
{
	{1,2,3},
	{8,0,4},
	{7,6,5}
};
/*static int puzle_final[N][N]=
{
	{1,2},
	{0,3}
};*/
#endif

/* A partir de una configuración de fichas construye un estado válido para el problema
  de acuerdo al tipo de datos tEstado. */
tEstado *crearEstado(int celdas[N][N]);

/* Genera el estado inicial a partir de crearEstado y puzle_inicial. */
tEstado *estadoInicial();

/* Genera el estado final a partir de crearEstado y puzle_final. */
tEstado *estadoObjetivo();

/* Devuelve 1 si dos estados son iguales y 0 en caso contrario. */
int iguales(tEstado *s, tEstado *t);

/* Devuelve 1 si un estado es igual al estado objetivo. */
int testObjetivo(tEstado *estado, tEstado *objetivo);

/* Comprueba si es posible aplicar un operador a una configuración determinada para el puzle.
  Devuelve 1 si el movimiento es válido y 0 en otro caso. */
int esValido(unsigned op, tEstado* estado);

/* Aplica un operador a una configuración concreta del puzle.
  Devuelve la nueva configuración del tablero tras el movimiento. */
tEstado *aplicaOperador(unsigned op, tEstado *estado);

/* Devuelve el coste de aplicar el operador. */
int coste(unsigned op, tEstado *estado);

/* Muestra el contenido del puzle. */
void dispEstado(tEstado *estado);

/* Muestra el nombre de cada operador: Arriba, Abajo, Izquierda, Derecha. */
void dispOperador(unsigned op);