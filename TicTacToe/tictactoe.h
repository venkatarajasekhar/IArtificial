/***************************************************************************
* Name:		TicTacToe
* FileName:	tictactoe.h
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

/*******************************************/
/* 		    tictactoe.h                    */
/*       Estrategia MiniMax                */
/*						                   */
/* Asignatura: Inteligencia Artificial     */
/* Grado en Ingenieria Informatica - UCA   */
/*******************************************/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define N 9

typedef struct tNodo
{
	int celdas[N];//cada posición de celdas está asociada a una posición en una matriz 3x3
	int vacias;//contador de las posiciones vacías en el tablero
}tNodo;

static int tablero_inicial[N] = {0,0,0,0,0,0,0,0,0};

// las posiciones serán numeradas de 0 a 8 de la siguiente forma:
//0 1 2
//3 4 5
//6 7 8

//precondiciones: recibe un tablero con una jugada inicializada
//Postcondiciones: devuelve el nodo creado con las 9 celdas vacias.
tNodo *crearNodo(int celdas[N]);

//postcondiciones: devuelve el tablero inicial, todos las celdas vacías, valores a 0
tNodo *estadoInicial();


/*tNodo *aplicaJugada(tNodo *actual, int jugador, int jugada)
 actual: es el tablero actual,
 jugador: la marca del jugador que tiene el turno
 jugada: indica en qué posición del tablero pondrá la marca
 devuelve: el nuevo Nodo tras aplicar la jugada */
tNodo *aplicaJugada(tNodo *actual, int jugador, int jugada);

//precondiciones: recibe un tNodo de un tablero y una jugada para comprobar si la casilla está libre
//postcondiciones: devuelve 1 si es válida y 0 en caso contrario
int esValida(tNodo *actual, int jugada);

// funcion que determina si un nodo es terminal, ha ganado MAX o MIN.
// actual: tablero actual.
// jugador: 1 si es Max -1 si es Min
//devuelve:  si ha gando MAX 100, si ha ganado MIN -100, empate 0
// si no es terminal tambien devuelve 0.
int terminal(tNodo *actual, int jugador);

//precondiciones: recibe un tNodo de un tablero para visualizar su estado.
void dispNodo(tNodo *s);

//precondiciones: recibe la marca del jugador que tiene el turno.
//postcondiciones: devuelve la marca opuesta a la introducida,
//si es 1 devuelve -1, y si el -1 devuelve 1.
int opuesto( int jugador);

//Precondiciones: recibe un tNodo de un tablero para comprobar si está completo.
//poscondiciones: devuelve 1 si el tablero está lleno, y 0 en caso contrario.
int lleno(tNodo *s);