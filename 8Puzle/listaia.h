/***************************************************************************
* Name:		8Puzle
* FileName:	listaia.h
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

/************************************************************/
/*						LISTAIA.C							*/
/*															*/
/*	Asignatura: Inteligencia Artificial						*/
/*	Funciones para manejar listas estáticas de acuerdo		*/
/*	a las necesidades de la estrategia de busqueda			*/
/************************************************************/

#include "nodo.h"
#define MAXI 5000
/*
#ifndef _tElemento_
#define _tElemento_
   typedef int tElemento;
#endif
*/
#define ERROR(s) printf("%s\n", s);

#ifndef _LISTAIA_H_
#define _LISTAIA_H_
	typedef struct
	{
		tElemento *elementos;
		int Lmax;  //longitud máxima de la lista
		int Nelem; //número de elmentos
		int inicio, fin;
	}tLista;

	typedef tLista *Lista;

	Lista CrearLista(int TamMax);
	int ListaVacia (Lista C);
	int ListaLlena(Lista C);

	//Pre: Lista C no está llena
	//Post:Devuelve el elemento primero de la lista
	void InsertarPrimero(tElemento *e, Lista C);

	//Pre: Lista C no está llena
	//Post:Devuelve el ultimo elemento de la lista
	void InsertarUltimo(tElemento *e, Lista C);

	//Pre: Lista C no está vacía, i: es un índice entre 0 y Lmax
	//Post:Devuelve el elemento i-ésimo de la lista C
	tElemento *ExtraerElem(Lista C,int i);

	//Pre: Lista C no está vacía
	//Post:Devuelve el primer elemento de la lista C
	tElemento *ExtraerPrimero(Lista C);

	//Pre: Lista L1 no está vacía
	//Post: Devuelve L1=L1+L2
	Lista Concatenar(Lista L1,Lista L2);

	void EliminarPrimero(Lista C);

	void DestruirLista(Lista C);
#endif