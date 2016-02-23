/***************************************************************************
* Name:		8Puzle
* FileName:	busqueda.h
*
* Author:	Jose M Barba Gonzalez
* Created:	19/02/16 - lun Febrero 19 17:52:48 2016
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
/*				BUSQUEDA.H					*/
/*											*/
/*	Asignatura: Inteligencia Artificial		*/
/*	Grado en Ingenieria Informatica - UCA	*/
/********************************************/

#include "puzle.h"
#include "nodo.h"
#include "listaia.h"

void dispCamino(tElemento *nodo);

void dispSolucion(tElemento *nodo);

tElemento *nodoInicial();

int esRepetido(tElemento *n, Lista L);

//función de evaluación f(n) = función heuristica h(h)
int heuristicaPiezasColocadas(tEstado *estado, tEstado *objetivo);

//función de evaluación f(n) = función heuristica h(h) + coste del camino g(n)
int heuristicaManhattan(tEstado *estado, tEstado *objetivo);

Lista Ordenar(Lista A);

Lista expandir(tElemento *nodo);

int busquedaAnchura();

int busquedaProfundidad();

int busquedaVoraz();

int busquedaAestrella();