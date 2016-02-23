/***************************************************************************
* Name:		8Puzle
* FileName:	puzle.c
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
/*					PUZLE.C					*/
/*											*/
/*	Asignatura: Inteligencia Artificial		*/
/*	Grado en Ingenieria Informatica - UCA	*/
/********************************************/

//#include <stdio.h>
//#include <stdlib.h>
//#include <string.h>
#include "puzle.h"

tEstado *crearEstado(int celdas[N][N])
{
	tEstado *estado;
	if((estado = (tEstado *) malloc(sizeof(tEstado))) == NULL)
		ERROR("CrearEstado: No hay memoria");

	int i, j, ficha;

	for (i=0;i<N;i++)
		for (j=0;j<N;j++)
		{
			ficha=celdas[i][j];
			estado->celdas[i][j]=ficha;
			estado->fila[ficha]=i;
			estado->col[ficha]=j;
		}
	return estado;
}


tEstado *estadoInicial()
{
	return crearEstado(puzle_inicial);
}


tEstado *estadoObjetivo()
{
	return crearEstado(puzle_final);
}

int coste(unsigned op, tEstado *estado)
{
	return 1;
}

/* VISUALIZACIÓN DE ESTADOS Y OPERADORES*/


void dispEstado(tEstado *estado)
{
	int i,j;

	for (i=0; i<N; i++)
	{
		for (j=0; j<N; j++)
			printf("%d",estado->celdas[i][j]);
		printf("\n");
	}
	printf("\n");
}


void dispOperador(unsigned op)
{
	switch(op)
	{
		case ARRIBA:
			printf("Movimiento ARRIBA:\n");
			break;
		case ABAJO:
			printf("Movimiento ABAJO:\n");
			break;
		case IZQUIERDA:
			printf("Movimiento IZQUIERDA:\n");
			break;
		case DERECHA:
			printf("Movimiento DERECHA:\n");
			break;
		default:
			printf("Movimiento no Válido");
			break;
	}
}

// FUNCIONES QUE SE HAN DE IMPLEMENTAR EN LA PRACTICA 1
int iguales(tEstado *s, tEstado *t)
{
	//COMPLETAR
	int i,j;

	for (i=0; i<N; i++)
	{
		for (j=0; j<N; j++)
			if(s->celdas[i][j] != t->celdas[i][j])
				return 0;
	}
	return 1;
}


int testObjetivo(tEstado *estado, tEstado *objetivo)
{
	//COMPLETAR
	if(iguales(estado,objetivo) == 0)
		return 0;
	else
		return 1;
}


int esValido(unsigned op, tEstado *estado)
{
	//COMPLETAR
	switch(op)
	{
		case ARRIBA:
		{
			if(estado->fila[0] == 0)
				return 0;
			else
				return 1;
		}
		case ABAJO:
		{
			if(estado->fila[0] == N-1)
				return 0;
			else
				return 1;
		}
		case IZQUIERDA:
		{
			if(estado->col[0] == 0)
				return 0;
			else
				return 1;
		}
		case DERECHA:
		{
			if(estado->col[0] == N-1)
				return 0;
			else
				return 1;
		}
		default: return 0;
	}
}

//tEstado *CopiaEstado(tEstado *nuevo, tEstado *anterior)

tEstado *aplicaOperador(unsigned op, tEstado *anterior)
{
	//COMPLETAR
	int aux, auxf, auxc;//variables para el intercambio de posiciones.
	tEstado *nuevo;
	if((nuevo = (tEstado *) malloc(sizeof(tEstado))) == NULL)
		ERROR("CrearEstado: No hay memoria");

	switch(op)
	{
		case ARRIBA:
		{
			if(esValido(op,anterior) == 1)
			{
				nuevo = crearEstado(anterior->celdas);
				aux = anterior->celdas[anterior->fila[0]-1][anterior->col[0]];
				nuevo->celdas[anterior->fila[0]-1][anterior->col[0]] = 0;
				nuevo->celdas[anterior->fila[0]][anterior->col[0]] = aux;
				auxf = anterior->fila[aux];
				nuevo->fila[aux] = anterior->fila[0];
				nuevo->fila[0] = auxf;
				break;
			}
			else
			{
				printf("Movimiento no Valido\n");return anterior;
				break;
			}
		}
		case ABAJO:
		{
			if(esValido(op,anterior) == 1)
			{
				nuevo = crearEstado(anterior->celdas);
				aux = anterior->celdas[anterior->fila[0]+1][anterior->col[0]];
				nuevo->celdas[anterior->fila[0]+1][anterior->col[0]] = 0;
				nuevo->celdas[anterior->fila[0]][anterior->col[0]] = aux;
				auxf = anterior->fila[aux];
				nuevo->fila[aux] = anterior->fila[0];
				nuevo->fila[0] = auxf;
				break;
			}
			else
			{
				printf("Movimiento no Valido\n");return anterior;
				break;
			}
		}
		case IZQUIERDA:
		{
			if(esValido(op,anterior) == 1)
			{
				nuevo = crearEstado(anterior->celdas);
				aux = anterior->celdas[anterior->fila[0]][anterior->col[0]-1];
				nuevo->celdas[anterior->fila[0]][anterior->col[0]-1] = 0;
				nuevo->celdas[anterior->fila[0]][anterior->col[0]] = aux;
				auxc = anterior->col[aux];
				nuevo->col[aux] = anterior->col[0];
				nuevo->col[0] = auxc;
				break;
			}
			else
			{
				printf("Movimiento no Valido\n");return anterior;
				break;
			}
		}
		case DERECHA:
		{
			if(esValido(op,anterior) == 1)
			{
				nuevo = crearEstado(anterior->celdas);
				aux = anterior->celdas[anterior->fila[0]][anterior->col[0]+1];
				nuevo->celdas[anterior->fila[0]][anterior->col[0]+1] = 0;
				nuevo->celdas[anterior->fila[0]][anterior->col[0]] = aux;
				auxc = anterior->col[aux];
				nuevo->col[aux] = anterior->col[0];
				nuevo->col[0] = auxc;
				break;
			}
			else
			{
				printf("Movimiento no Valido\n");return anterior;
				break;
			}
		}
		default:
		{
			printf("Movimiento no Valido\n");
			return anterior;
		}
	}

	return nuevo;
}