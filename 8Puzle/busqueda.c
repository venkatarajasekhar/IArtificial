/***************************************************************************
* Name:		8Puzle
* FileName:	busqueda.c
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

/********************************************/
/* 				BUSQUEDA.C					*/
/*											*/
/*	Asignatura: Inteligencia Artificial		*/
/*	Grado en Ingenieria Informatica - UCA	*/
/********************************************/

//#include <stdlib.h>
//#include <stdio.h>
//#include <string.h>

#include "busqueda.h"

void dispCamino(tElemento *nodo)
{
   if (nodo->padre==NULL)
   {
      printf("\n\nInicio:\n");
      dispEstado(nodo->estado);
   }
   else
   {
      dispCamino(nodo->padre);
      dispOperador(nodo->operador);
      dispEstado(nodo->estado);
      printf("\n");
   }
}


void dispSolucion(tElemento *nodo)
{
   dispCamino(nodo);
   printf("Profundidad=%d\n",nodo->profundidad);
   printf("Coste=%d\n",nodo->costeCamino);
   printf("Heuristica=%d\n",nodo->valHeuristica);
}


/* Crea el nodo raíz. */
tElemento *nodoInicial()
{
   tElemento *inicial=(tElemento *) malloc(sizeof(tElemento));

   inicial->estado=estadoInicial();
   inicial->padre=NULL;
   inicial->costeCamino=0;
   inicial->profundidad=0;
   return inicial;
}

int esRepetido(tElemento *n, Lista L)
{
    int i = 0;

    if(!ListaVacia(L))
        for(i = L->inicio; i <= L->fin; i++)
            if(iguales(n->estado, L->elementos[i].estado) == 1)
                return 1;
    return 0;
}

int heuristicaPiezasMalColocadas(tEstado *estado, tEstado *objetivo)
{
   int i,j,cont=0;

   for(i = 0; i < N; i++)
        for(j = 0; j < N; j++)
            if(estado->celdas[i][j] != objetivo->celdas[i][j])
                cont++;
    return cont;
}

int heuristicaManhattan(tEstado *estado, tEstado *objetivo)
{
   int i,j,cont=0;

   for(i = 0; i < N; i++)
        for(j = 0; j < N; j++)
            if(estado->celdas[i][j] != objetivo->celdas[i][j])
                cont = cont + abs(estado->fila[i] - objetivo->fila[i]) + abs(estado->col[i] - objetivo->col[i]);
    return cont;
}

int compara(const void * a, const void * b)
{
    struct NodoBusqueda *ia = (struct NodoBusqueda *)a;
    struct NodoBusqueda *ib = (struct NodoBusqueda *)b;
    return (ia->valHeuristica - ib->valHeuristica);
}

Lista Ordenar(Lista A)
{
    qsort(A->elementos, A->Nelem, sizeof(struct NodoBusqueda), compara);
    return A;
}

/* Expande un nodo. */
Lista expandir(tElemento *nodo)
{
    unsigned op;
    Lista sucesores=CrearLista(NUM_OPERADORES);
    //printf("\nLista de Sucesores de Actual: \n");
    for(op=1;op<=NUM_OPERADORES;op++)
    {
        if (esValido(op,nodo->estado))
        {
            tElemento *nuevo=(tElemento *) malloc(sizeof(tElemento));
            tEstado *s=(tEstado *) malloc(sizeof(tEstado));
            s=aplicaOperador(op,nodo->estado);
            nuevo->estado=s;
            nuevo->padre=nodo;
            nuevo->operador=op;
            nuevo->costeCamino=nodo->costeCamino + coste(op,nodo->estado);
            nuevo->profundidad=nodo->profundidad + 1;
            //nuevo->valHeuristica = heuristicaPiezasMalColocadas(nuevo->estado,estadoObjetivo());
            nuevo->valHeuristica = heuristicaManhattan(nuevo->estado,estadoObjetivo()) + nuevo->costeCamino;
            if(!ListaLlena(sucesores))
            {
                InsertarUltimo(nuevo,sucesores);
                //InsertarPrimero(nuevo,sucesores);
                //dispEstado(nuevo->estado);
            }
        }
    }
    return sucesores;
}

int busquedaAnchura()
{
    int objetivo=0, i;
    tElemento *Actual=(tElemento*) malloc(sizeof(tElemento));

    tElemento *Inicial=nodoInicial();
    tEstado *Final=estadoObjetivo();

    Lista Abiertos = (Lista) CrearLista(MAXI);
    Lista Cerrados = (Lista) CrearLista(MAXI);
    Lista Sucesores;

    if(ListaVacia(Abiertos))
        InsertarPrimero(Inicial, Abiertos);

    while(!ListaVacia(Abiertos) && !objetivo)
    {
        Actual=ExtraerPrimero(Abiertos);
        printf("\n ACTUAL: \n");
        dispEstado(Actual->estado);
        if(!ListaLlena(Cerrados) && (esRepetido(Actual, Cerrados) == 0))
        {
            InsertarUltimo(Actual,Cerrados);
            objetivo=testObjetivo(Actual->estado, Final);
            if(!objetivo)
            {
                Sucesores = expandir(Actual);
                EliminarPrimero(Abiertos);
                Abiertos=Concatenar(Abiertos, Sucesores);
                printf("\n ABIERTOS: \n");
                printf("ini: %i\nfin: %i\n\n", Abiertos->inicio, Abiertos->fin);
                for(i = Abiertos->inicio; i <= Abiertos->fin; i++)
                    dispEstado(Abiertos->elementos[i].estado);
                printf("--------- \n");
            }
        }
        else
            EliminarPrimero(Abiertos);
    }
    dispSolucion(Actual);
    return objetivo;
}

int busquedaProfundidad()
{
    int objetivo=0, i;
    tElemento *Actual=(tElemento*) malloc(sizeof(tElemento));

    tElemento *Inicial=nodoInicial();
    tEstado *Final=estadoObjetivo();

    Lista Abiertos = (Lista) CrearLista(MAXI);
    Lista Cerrados = (Lista) CrearLista(MAXI);
    Lista Sucesores;

    if(ListaVacia(Abiertos))
        InsertarPrimero(Inicial, Abiertos);

    while(!ListaVacia(Abiertos) && !objetivo)
    {
        Actual=ExtraerPrimero(Abiertos);
        printf("\n ACTUAL: \n");
        dispEstado(Actual->estado);
        if(!ListaLlena(Cerrados) && (esRepetido(Actual, Cerrados) == 0))
        {
            InsertarUltimo(Actual,Cerrados);
            objetivo=testObjetivo(Actual->estado, Final);
            if(!objetivo)
            {
                Sucesores = expandir(Actual);
                EliminarPrimero(Abiertos);
                Abiertos=Concatenar(Sucesores,Abiertos);
                printf("\n ABIERTOS: \n");
                printf("ini: %i\nfin: %i\n\n", Abiertos->inicio, Abiertos->fin);
                for(i = Abiertos->inicio; i <= Abiertos->fin; i++)
                    dispEstado(Abiertos->elementos[i].estado);
                printf("--------- \n");
            }
        }
        else
            EliminarPrimero(Abiertos);
    }
    dispSolucion(Actual);
    return objetivo;
}

int busquedaVoraz()
{
    int objetivo=0, i;
    tElemento *Actual=(tElemento*) malloc(sizeof(tElemento));

    tElemento *Inicial=nodoInicial();
    tEstado *Final=estadoObjetivo();

    Lista Abiertos = (Lista) CrearLista(MAXI);
    Lista Cerrados = (Lista) CrearLista(MAXI);
    Lista Sucesores;

    if(ListaVacia(Abiertos))
        InsertarPrimero(Inicial, Abiertos);

    while(!ListaVacia(Abiertos) && !objetivo)
    {
        Actual=ExtraerPrimero(Abiertos);
        printf("\n ACTUAL: \n");
        dispEstado(Actual->estado);
        if(!ListaLlena(Cerrados) && (esRepetido(Actual, Cerrados) == 0))
        {
            InsertarUltimo(Actual,Cerrados);
            objetivo=testObjetivo(Actual->estado, Final);
            if(!objetivo)
            {
                Sucesores = expandir(Actual);
                EliminarPrimero(Abiertos);
                Abiertos=Concatenar(Abiertos,Sucesores);
                Abiertos = Ordenar(Abiertos);
                printf("\n ABIERTOS: \n");
                printf("ini: %i\nfin: %i\n\n", Abiertos->inicio, Abiertos->fin);
                for(i = Abiertos->inicio; i <= Abiertos->fin; i++)
                    dispEstado(Abiertos->elementos[i].estado);
                printf("--------- \n");
            }
        }
        else
            EliminarPrimero(Abiertos);
    }
    dispSolucion(Actual);
    return objetivo;
}

int busquedaAestrella()
{
    int objetivo=0, i;
    tElemento *Actual=(tElemento*) malloc(sizeof(tElemento));

    tElemento *Inicial=nodoInicial();
    tEstado *Final=estadoObjetivo();

    Lista Abiertos = (Lista) CrearLista(MAXI);
    Lista Cerrados = (Lista) CrearLista(MAXI);
    Lista Sucesores;

    if(ListaVacia(Abiertos))
        InsertarPrimero(Inicial, Abiertos);

    while(!ListaVacia(Abiertos) && !objetivo)
    {
        Actual=ExtraerPrimero(Abiertos);
        printf("\n ACTUAL: \n");
        dispEstado(Actual->estado);
        if(!ListaLlena(Cerrados) && (esRepetido(Actual, Cerrados) == 0))
        {
            InsertarUltimo(Actual,Cerrados);
            objetivo=testObjetivo(Actual->estado, Final);
            if(!objetivo)
            {
                Sucesores = expandir(Actual);
                EliminarPrimero(Abiertos);
                Abiertos=Concatenar(Abiertos,Sucesores);
                Abiertos = Ordenar(Abiertos);
                printf("\n ABIERTOS: \n");
                printf("ini: %i\nfin: %i\n\n", Abiertos->inicio, Abiertos->fin);
                for(i = Abiertos->inicio; i <= Abiertos->fin; i++)
                    dispEstado(Abiertos->elementos[i].estado);
                printf("--------- \n");
            }
        }
        else
            EliminarPrimero(Abiertos);
    }
    dispSolucion(Actual);
    return objetivo;
}