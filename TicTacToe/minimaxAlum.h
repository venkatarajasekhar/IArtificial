/***************************************************************************
* Name:		TicTacToe
* FileName:	minimaxAlum.h
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
/*				minimaxAlum.h				*/
/*			Estrategia MiniMax				*/
/*											*/
/*	Asignatura: Inteligencia Artificial		*/
/*	Grado en Ingenieria Informatica - UCA	*/
/********************************************/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>

tNodo *jugadaAdversario(tNodo *t);

tNodo *PSEUDOminimax(tNodo *Nodo);

tNodo *MinMax(tNodo *nodo, int jugador);

int valorMin(tNodo *nodo);

int valorMax(tNodo *nodo);

int min(int valor1, int valor2);

int max(int valor1, int valor2);

//heuristica
//Precondiciones: recibe un tNodo de un tablero para
//      comprobar que jugada es la mejor del agente inteligente.
//poscondiciones: devuelve 1 si la mejor jugada es la
//      de maximo, y 0 en caso contrario.
int utilidad(tNodo *nodo);

/***********************************************/

tNodo *poda_ab(tNodo *nodo, int jugador);

int valorMin_ab(tNodo *nodo, int jugador, int prof, int alfa, int beta);

int valorMax_ab(tNodo *nodo, int jugador, int prof, int alfa, int beta);