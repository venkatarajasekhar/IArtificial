/***************************************************************************
* Name:		TicTacToe
* FileName:	main.c
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

#include <stdio.h>
#include <stdlib.h>
#include "tictactoe.h"
#include "minimaxAlum.h"

int main(int argc, char **argv)
{
	printf("Ejercicio TicTacToe.\n");
	int jugador;  //+1 o -1
	int primero,ganador;
	tNodo *juego = crearNodo(tablero_inicial);
	dispNodo(juego);

	printf("El Agente Inteligente juega con X \n El Jugador Humano con O \n Elige el turno 1:Primero o 2:Segundo ");
	scanf("%d",&primero);
	printf("\n");

	if(primero == 1)
		jugador = -1; //Turno de Min
	else
		jugador = 1; //Turno de Max

	ganador = terminal(juego,jugador);

	while(juego->vacias > 0 && ganador == 0)
	{
		if(jugador == 1)
			juego = (tNodo *) PSEUDOminimax(juego);
		else
			juego = (tNodo *) jugadaAdversario(juego);

		dispNodo(juego);
		ganador = terminal(juego,jugador);
		jugador = opuesto(jugador);//turno del adversario
	}

	switch(ganador)
	{
		case 100:
			printf("\n HE GANADOOOO\n");
			break;
		case 0:
			printf("\n EMPATE\n");
			break;
		case -100:
			printf("\n Increible pero has ganado tu :(( \n\n");
			break;
		default: printf("\n algo ha salido mal en el juego ..\n");
	}
	return 0;
}