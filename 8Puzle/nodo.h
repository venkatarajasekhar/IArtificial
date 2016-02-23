/***************************************************************************
* Name:		8Puzle
* FileName:	nodo.h
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
/*					NODO.H					*/
/*											*/
/*	Asignatura: Inteligencia Artificial		*/
/*	Grado en Ingenieria Informatica - UCA	*/
/********************************************/

#include "puzle.h"

#ifndef _tElemento_
#define _tElemento_
	typedef struct NodoBusqueda
	{
		tEstado *estado;
		struct NodoBusqueda *padre;
		unsigned operador;
		int costeCamino;
		int profundidad;
		int valHeuristica;
	}tNodoBusqueda;

	typedef tNodoBusqueda tElemento;
#endif