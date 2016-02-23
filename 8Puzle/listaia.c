/***************************************************************************
* Name:		8Puzle
* FileName:	listaia.c
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

#include <stdlib.h>
#include <stdio.h>
#include "listaia.h"

Lista CrearLista (int TamMax)
{
	Lista C;
	C = (Lista) malloc(sizeof(tLista));
	if(C == NULL)
		{ERROR("CrearLista: No hay memoria");}
	else
	{
		C->elementos = (tElemento *)malloc(TamMax*sizeof(tElemento));
		if(C->elementos == NULL)
			{ERROR("CrearLista: No hay memoria para los elementos");}
		else
		{
			C->Lmax = TamMax;
			C->Nelem = 0;
			C->inicio = 0;
			C->fin =0;
		}
	}
	return C;
}

//Post:Devuelve 1 como valor verdadero si la lista esta vacia.
int ListaVacia (Lista C)
{
	return (C->Nelem==0);
}

//Post:Devuelve 1 como valor verdadero si la lista esta llena.
int ListaLlena (Lista C)
{
	return (C->Nelem==C->Lmax);
}

//Pre: Lista C no está vacía
//Post:Devuelve el primer elemento de la lista C
tElemento *ExtraerPrimero(Lista C)
{
	if(ListaVacia(C))
		ERROR("ExtraerPrimero: No hay elementos");
	//SE AÑADE UNA VARIABLE DE RETORNO, PUESTO QUE return PUEDE PROVOCAR PÉRDIDA EN LA CONVERSIÓN DE TIPOS
	tElemento *retorno=(tElemento*) malloc(sizeof(tNodoBusqueda));
	*retorno = (C->elementos[C->inicio]);
	return retorno;// (tElemento*) (C->elementos[C->inicio]);
}

//Pre: Lista C no está vacía, i: es un índice entre 0 y TamMax
//Post:Devuelve el elemento i-ésimo de la lista C (no lo elimina de la lista)
tElemento *ExtraerElem(Lista C,int i)
{
	if(ListaVacia(C))
		ERROR("ExtraerPrimero: No hay elementos");
	//SE AÑADE UNA VARIABLE DE RETORNO, PUESTO QUE return PUEDE PROVOCAR PÉRDIDA EN LA CONVERSIÓN DE TIPOS
	tElemento *retorno=(tElemento*) malloc(sizeof(tNodoBusqueda));
	*retorno = (C->elementos[i]);
	return retorno;//(tElemento *)(C->elementos[i]);
}

// Elimina el primer elemento de la lista
void EliminarPrimero(Lista C)
{
	if (!ListaVacia(C))
	{
		C->inicio =(C->inicio+1) % C->Lmax;
		C->Nelem=C->Nelem-1;
	}
}

//Pre: Lista C no está llena
//Post:Devuelve el elemento primero de la lista
void InsertarPrimero(tElemento *e, Lista C)
{
	//si inicio == fin estamos en el caso del primer nodo de la lista
	if(((C->inicio == 0) && (C->fin == 0)) && (ListaVacia(C)))
	{
		C->elementos[C->inicio] = *e;//(tElemento) e;
		C->Nelem=C->Nelem+1;
	}
	else
	{
		if(C->inicio>=0 && (C->inicio < C->Lmax-1))
			C->inicio = (C->inicio-1) % C->Lmax; //inserta antes que el primero
		if(C->inicio == C->fin)
			C->inicio = C->inicio-1;
		else
			C->inicio=C->Lmax-1;

		C->elementos[C->inicio] = *e;//(tElemento) e;
		C->Nelem=C->Nelem+1;
	}
}

//Pre: Lista C no está llena
//Post:Devuelve el ultimo elemento de la lista
void InsertarUltimo(tElemento *e, Lista C)
{
	//si inicio == fin estamos en el caso del primer nodo de la lista
	if(((C->fin == 0) && (C->inicio == 0)) && (ListaVacia(C)))
		InsertarPrimero(e,C);
	else
	{
		if(C->fin == C->Lmax-1)
			C->fin=0;
		else
			C->fin = (C->fin+1) % C->Lmax;

		C->elementos[C->fin] =  *e;//(tElemento) e;
		C->Nelem=C->Nelem+1;
	}
}

//Pre: Lista L1 no está vacía
//Post: Devuelve L1+L2
Lista Concatenar(Lista L1, Lista L2)
{
	//tElemento *e=(tElemento*) malloc(sizeof(tElemento));

	//if(!ListaVacia(L1))
		while(!ListaVacia(L2) && (!ListaLlena(L1)))
		{
			//e=(tElemento*) ExtraerPrimero(L2);
			InsertarUltimo(ExtraerPrimero(L2),L1);
			EliminarPrimero(L2);
		}
	return L1;
}

void DestruirLista(Lista C)
{
	free(C->elementos);
	free(C);
}