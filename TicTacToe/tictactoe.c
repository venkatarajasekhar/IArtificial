/***************************************************************************
* Name:		TicTacToe
* FileName:	tictactoe.c
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

#include "tictactoe.h"

tNodo *estadoInicial()
{
	return crearNodo(tablero_inicial);
}

tNodo *crearNodo(int celdas[N])//celdas[N] se refiere a una jugada empezada.
{
	tNodo *Nodo = (tNodo *) malloc(sizeof(tNodo));
	int i, c;
	Nodo->vacias = 0;
	for(i = 0; i < N; i++)
	{
		c = celdas[i];
		Nodo->celdas[i] = c;
		if(c == 0)//si lee un 0 indica que hay una posicion más vacía en el tablero
			Nodo->vacias = Nodo->vacias+1;
	}
	return Nodo;
}

tNodo *aplicaJugada(tNodo *actual, int jugador, int jugada)
{
	tNodo *nuevo = (tNodo *) malloc(sizeof(tNodo));
	memcpy(nuevo,actual,sizeof(tNodo));
	nuevo->celdas[jugada] = jugador;
	nuevo->vacias--;  //marca la posición que indica pone la marca del jugador
	return nuevo;
}

int esValida(tNodo *actual, int jugada)
{
	//si está vacía la posición, la jugada es válido
	return (jugada >= 0 && jugada < 9 && actual->celdas[jugada] == 0);
}

int opuesto(int jugador)
{
	return (jugador * -1);//Jugador 1 y Jugador -1
}

int lleno(tNodo *tablero)
{
	return (tablero->vacias != 0);
}

int terminal(tNodo *Nodo, int jugador)
{
	unsigned opciones[8][3] = {{0,1,2},{3,4,5},{6,7,8},{0,3,6},{1,4,7},{2,5,8},{0,4,8},{2,4,6}};
	int i = 0, res = 0;

	while (res == 0 && i < 8)
	{
		if(Nodo->celdas[opciones[i][0]] != 0 && Nodo->celdas[opciones[i][0]] == Nodo->celdas[opciones[i][1]] && Nodo->celdas[opciones[i][0]] == Nodo->celdas[opciones[i][2]])
			res = Nodo->celdas[opciones[i][2]];//indica que jugador ocupa las casillas ganadoras
		i++;
	}
	return res*100;
}

////////////////////////////////////////
//  VISUALIZACIÓN DE NodoS
////////////////////////////////////////

char marca(int i)
{
	switch(i)
	{
		case 1:
			return 'X';
		case 0:
			return ' ';
		case -1:
			return 'O';
		default: return ' ';
	}
}

void dispNodo(tNodo *b)
{
	printf("---+---+---\n");
	printf(" %c | %c | %c\n",marca(b->celdas[0]),marca(b->celdas[1]),marca(b->celdas[2]));
	printf("---+---+---\n");
	printf(" %c | %c | %c\n",marca(b->celdas[3]),marca(b->celdas[4]),marca(b->celdas[5]));
	printf("---+---+---\n");
	printf(" %c | %c | %c\n",marca(b->celdas[6]),marca(b->celdas[7]),marca(b->celdas[8]));
	printf("---+---+---\n\n");
}