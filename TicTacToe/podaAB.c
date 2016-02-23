/***************************************************************************
* Name:		TicTacToe
* FileName:	podaAB.c
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
/*				podaAB.c					*/
/*			Estrategia Poda a-b				*/
/*											*/
/*	Asignatura: Inteligencia Artificial		*/
/*	Grado en Ingenieria Informatica - UCA	*/
/********************************************/

#include "tictactoe.h"
#include "minimaxAlum.h"
#define LIMITE 3

tNodo *poda_ab(tNodo *nodo, int jugador)
{
	int alfa = INT_MIN, beta = INT_MAX;
	int max_actual = 0, jugada = 0, mejorJugada, prof = 1, v;
	tNodo *intento = malloc(sizeof(tNodo));

	while(jugada < N)
	{
		if(esValida(nodo,jugada) == 1)
		{
			intento = aplicaJugada(nodo, jugador, jugada);
			v = valorMin_ab(intento, jugador * (-1),prof+1, alfa, beta);
			max_actual = valorMax_ab(nodo,jugador,prof,alfa,beta);

			if((v > alfa) && (alfa <= max_actual))
			{
				alfa = v;
				mejorJugada = jugada;
			}
		}
		jugada++;
	}
	if(esValida(nodo, mejorJugada) == 1)
		intento = aplicaJugada(nodo, jugador, mejorJugada);

	return intento;
}

int valorMin_ab(tNodo *nodo, int jugador, int prof, int alfa, int beta)
{
	int vmin,jugada;
	tNodo *intento = malloc(sizeof(tNodo));

	if(terminal(nodo,jugador) == 1)
		vmin = utilidad(nodo);
	else
		if(prof == LIMITE)
			vmin = utilidad(nodo);
		else
		{
			while((jugada < N) && (alfa < beta))
			{
				if(esValida(nodo,jugada) == 1)
				{
					intento = aplicaJugada(nodo,jugador,jugada);
					beta = min(beta,valorMax_ab(intento,jugador,prof,alfa,beta));
				}
				jugada++;
			}
			vmin = beta;
		}

	return vmin;
}

int valorMax_ab(tNodo *nodo, int jugador, int prof, int alfa, int beta)
{
	int vmax,jugada;
	tNodo *intento = malloc(sizeof(tNodo));

	if(terminal(nodo,jugador) == 1)
		vmax = utilidad(nodo);
	else
		if(prof == LIMITE)
			vmax = utilidad(nodo);
		else
		{
			while((jugada < N) && (alfa < beta))
			{
				if(esValida(nodo,jugada) == 1)
				{
					intento = aplicaJugada(nodo,jugador,jugada);
					alfa = max(alfa,valorMin_ab(intento,jugador,prof,alfa,beta));
				}
				jugada++;
			}
			vmax = alfa;
		}

	return vmax;
}