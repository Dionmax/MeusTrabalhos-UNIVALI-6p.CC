#pragma once
#include <iostream>
#include "Grafo.cpp"
#include <iostream>
#include <list>
#include <algorithm>
#include <stack> 
#include <queue> 
#include <functional>

#define INFINITO 10000000

using namespace std;

class GrafoMatriz : public Grafo
{
public:
	GrafoMatriz() : Grafo()
	{

	}

	GrafoMatriz(int vertices, bool direcionado, bool ponderado)
		: Grafo(vertices, direcionado, ponderado)
	{

	}

}
