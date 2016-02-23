/***************************************************************************
* Name:		8Puzle
* FileName:	main.c
*
* Author:	Jose M Barba Gonzalez
* Created:	19/02/16 - lun abril 20 17:52:48 2015
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



/**
 * @brief 
 * @param argc
 * @param argv
 * @return 
 */
//#include <stdio.h>
////#include <stdlib.h>
#include "puzle.h"
#include "busqueda.h"

int main(int argc, char **argv)
{
	printf("Ejercicio 8 Puzle.\n");
	int i=0, obj=0;
	tEstado *puzleI, *puzleF;
	//tElemento *actual;

	puzleI = estadoInicial();
	puzleF = estadoObjetivo();
	//actual = nodoInicial();

	printf("\nInicial\n\n");

	dispEstado(puzleI);

	printf("{");
	for(i = 0; i < N*N; i++) printf("%d,",puzleI->fila[i]);
	printf("}\n{");
	for(i = 0; i < N*N; i++) printf("%d,",puzleI->col[i]);
	printf("}\n");

	printf("\n-----------------------\n\n");

	//dispEstado(actual->estado);
	//while(busqueda() != 1)
		obj = busquedaAestrella();

	printf("\n-- %i --\n",obj);

	//printf("Puzle Actual\n");
	//dispEstado(puzleI);
	printf("Puzle Final\n");
	dispEstado(puzleF);
	if(obj == 1)
		printf("\nAmbos puzles son iguales\n");
	else
		printf("\nLos puzles son distintos\n");

	printf("\n-----------------------\n\n");

	return 0;
	/*
	dispOperador(ARRIBA);
	puzleI = aplicaOperador(ARRIBA, puzleI);
	dispEstado(puzleI);
	printf("{");
	for(i = 0; i < N*N; i++) printf("%d,",puzleI->fila[i]);
	printf("}\n{");
	for(i = 0; i < N*N; i++) printf("%d,",puzleI->col[i]);
	printf("}\n\n");

	dispOperador(ARRIBA);
	puzleI = aplicaOperador(ARRIBA, puzleI);
	dispEstado(puzleI);
	printf("{");
	for(i = 0; i < N*N; i++) printf("%d,",puzleI->fila[i]);
	printf("}\n{");
	for(i = 0; i < N*N; i++) printf("%d,",puzleI->col[i]);
	printf("}\n\n");
	//-------------------------------------------------------
	dispOperador(ARRIBA);
	puzleI = aplicaOperador(ARRIBA, puzleI);
	dispEstado(puzleI);
	printf("{");
	for(i = 0; i < N*N; i++) printf("%d,",puzleI->fila[i]);
	printf("}\n{");
	for(i = 0; i < N*N; i++) printf("%d,",puzleI->col[i]);
	printf("}\n\n");
	//-------------------------------------------------------
	dispOperador(DERECHA);
	puzleI = aplicaOperador(ARRIBA, puzleI);
	dispEstado(puzleI);
	printf("{");
	for(i = 0; i < N*N; i++) printf("%d,",puzleI->fila[i]);
	printf("}\n{");
	for(i = 0; i < N*N; i++) printf("%d,",puzleI->col[i]);
	printf("}\n\n");

	dispOperador(IZQUIERDA);
	puzleI = aplicaOperador(IZQUIERDA, puzleI);
	dispEstado(puzleI);
	printf("{");
	for(i = 0; i < N*N; i++) printf("%d,",puzleI->fila[i]);
	printf("}\n{");
	for(i = 0; i < N*N; i++) printf("%d,",puzleI->col[i]);
	printf("}\n\n");

	dispOperador(ABAJO);
	puzleI = aplicaOperador(ABAJO, puzleI);
	dispEstado(puzleI);
	printf("{");
	for(i = 0; i < N*N; i++) printf("%d,",puzleI->fila[i]);
	printf("}\n{");
	for(i = 0; i < N*N; i++) printf("%d,",puzleI->col[i]);
	printf("}\n");

	printf("\n-----------------------\n\n");
	return 0;*/
}