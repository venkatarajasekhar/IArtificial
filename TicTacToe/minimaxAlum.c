/***************************************************************************
* Name:		TicTacToe
* FileName:	minimaxAlum.c
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
/*				minimaxAlum.c				*/
/*			Estrategia MiniMax				*/
/*											*/
/*	Asignatura: Inteligencia Artificial		*/
/*	Grado en Ingenieria Informatica - UCA	*/
/********************************************/

#include "tictactoe.h"
#include "minimaxAlum.h"

tNodo *PSEUDOminimax(tNodo *t)
{
	int mejorJugada = -1;
	int puntos = -2;
	int i, temp;
	tNodo *intento=malloc(sizeof(tNodo));
	printf("\n Mi turno: \n");

	for(i = 0; i < 9; ++i)
	{
		if(esValida(t,i))
		{
			intento = aplicaJugada(t,1,i); //Intenta jugada
			temp = terminal(intento,-1); // Calcula el valor minimax
			if(temp > puntos)
			{
				puntos = temp;
				mejorJugada = i;
			}
		}
	}
	t = aplicaJugada(t,1,mejorJugada);
	return t;
}

tNodo *jugadaAdversario(tNodo *t)
{
	int jugada = 0;
	printf("\nJugada ([0..8])?: ");
	scanf("%d", &jugada);

	while (!esValida(t,jugada))
	{
		printf("\n Intenta otra posicion del tablero \n");
		printf("\n");
		printf("\nJugada ([0..8])?: ");
		scanf("%d", &jugada);
	}
	t = aplicaJugada(t,-1,jugada);
	return t;
}

tNodo *MinMax(tNodo *nodo, int jugador)
{
	int max, max_actual, jugada, mejorJugada = -1;
	tNodo *intento=malloc(sizeof(tNodo));

	max = -10000;
	for(jugada = 0; jugada < N; jugada++)
	{
		if(esValida(nodo, jugada) == 1)
		{
			intento = aplicaJugada(nodo, jugador, jugada);
			max_actual = valorMin(intento);
			if(max_actual > max)
			{
				max = max_actual;
				mejorJugada = jugada;
			}
		}
	}

	nodo = aplicaJugada(nodo,jugador,mejorJugada);
	return nodo;
}

int valorMin(tNodo *nodo)
{
	int valor_min, jugada, jugador = -1;

	if(terminal(nodo, jugador) == 1)
		valor_min = utilidad(nodo);
	else
	{
		valor_min = 100000;
		for(jugada = 0; jugada < N; jugada++)
			if(esValida(nodo, jugada) == 1)
				valor_min = min(valor_min, valorMax(aplicaJugada(nodo, jugador, jugada)));
	}
	return valor_min;
}

int valorMax(tNodo *nodo)
{
	int valor_max, jugada, jugador = 1;

	if(terminal(nodo, jugador) == 1)
		valor_max = utilidad(nodo);
	else
	{
		valor_max = -10000;
		for(jugada = 0; jugada < N; jugada++)
			if(esValida(nodo, jugada == 1))
				valor_max = max(valor_max, valorMin(aplicaJugada(nodo, jugador, jugada)));
	}
	return valor_max;
}

int min(int valor1, int valor2)
{
	if(valor1 < valor2)
		return valor1;
	else
		return valor2;
}

int max(int valor1, int valor2)
{
	if(valor1 > valor2)
		return valor1;
	else
		return valor2;
}

//heuristica
int utilidad(tNodo *nodo)
{
	int maximo, minimo;

	maximo = valorMax(nodo);
	minimo = valorMin(nodo);

	if(maximo < minimo && (minimo-1) > maximo)
	{
		nodo = MinMax(nodo,minimo);
		return 0;
	}
	else
	{
		nodo = MinMax(nodo,maximo);
		return 1;
	}
}