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
	int** grafoMatriz;

public:
	GrafoMatriz() : Grafo()
	{
		grafoMatriz = new int* [vertices];

		for (int i = 0; i < vertices; i++)
			grafoMatriz[i] = new int[vertices];

		for (int i = 0; i < vertices; i++)
			for (int j = 0; j < vertices; j++)
				grafoMatriz[i][j] = 0;
	}

	GrafoMatriz(int vertices, bool direcionado, bool ponderado)
		: Grafo(vertices, direcionado, ponderado)
	{
		grafoMatriz = new int* [vertices];

		for (int i = 0; i < vertices; i++)
			grafoMatriz[i] = new int[vertices];

		for (int i = 0; i < vertices; i++)
			for (int j = 0; j < vertices; j++)
				grafoMatriz[i][j] = 0;
	}

	void InserirAresta(int v1, int v2, int peso)
	{
		grafoMatriz[v1][v2] = peso;

		if (!direcionado)
			grafoMatriz[v2][v1] = peso;
	}

	void DesenharMatriz()
	{
		for (int i = 0; i < vertices; i++) {
			for (int j = 0; j < vertices; j++)
				cout << "  " << grafoMatriz[i][j] << "	|";

			cout << "\n";
		}
	}
};
