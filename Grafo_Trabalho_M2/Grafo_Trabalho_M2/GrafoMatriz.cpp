#pragma once
#include <iostream>
#include "Grafo.cpp"
#include <iostream>
#include <list>
#include <algorithm>
#include <stack> 
#include <queue> 
#include <functional>

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
				grafoMatriz[i][j] = INFINITY;
	}

	GrafoMatriz(int vertices, bool direcionado, bool ponderado)
		: Grafo(vertices, direcionado, ponderado)
	{
		grafoMatriz = new int* [vertices];

		for (int i = 0; i < vertices; i++)
			grafoMatriz[i] = new int[vertices];

		for (int i = 0; i < vertices; i++)
			for (int j = 0; j < vertices; j++)
				grafoMatriz[i][j] = INFINITY;
	}

	void InserirAresta(int v1, int v2, int peso)
	{
		if (!ponderado)
			peso = 1;

		if (grafoMatriz[v1][v2] == 0)
		{
			grafoMatriz[v1][v2] = peso;

			if (!direcionado)
				grafoMatriz[v2][v1] = peso;
		}
		else
		{
			cout << "Aresta ja existe" << endl;
		}
	}

	int ObterGrauDeSaida(int v)
	{
		int grau = 0;

		for (int i = 0; i < vertices; i++)
		{
			if (grafoMatriz[v][i] != 0)
			{
				cout << "O vertice " << v << " e vizinho do " << i << endl;
				grau++;
			}
		}

		return grau;
	}

	bool ExisteVizinho(int v1, int v2)
	{
		if (grafoMatriz[v1][v2] != 0)
			return true;

		return false;
	}

	void BuscaProfundidade(int v)
	{
		cout << "DFS " << endl;
		stack<int> pilha;
		bool* visitados; // vetor de visitados
		visitados = new bool[vertices];

		// marca todos como não visitados
		for (int i = 0; i < vertices; i++)
			visitados[i] = false;

		while (true)
		{
			if (!visitados[v])
			{
				cout << "Verificando o " << v << endl;
				for (int j = 0; j < vertices; j++)
				{
					if (grafoMatriz[j][v] != 0)
					{
						cout << "Vizinho: " << j << endl;
						visitados[v] = true; // marca como visitado
						pilha.push(j); // insere na fila
					}
				}

				cout << endl;
			}

			visitados[v] = true; // marca como visitado

			if (pilha.empty())
				break;

			v = pilha.top();

			pilha.pop();
		}
	}

	void BuscaLargura(int v)
	{
		cout << "BFS" << endl;
		queue<int> fila;
		int i = 0;
		bool* visitados; // vetor de visitados
		visitados = new bool[vertices];

		for (int i = 0; i < vertices; i++)
			visitados[i] = false;

		while (true)
		{
			if (!visitados[v])
			{
				cout << "Verificando o " << v << endl;
				for (int j = 0; j < vertices; j++)
				{
					if (grafoMatriz[j][v] != 0)
					{
						cout << "Vizinhos: " << j << endl;
						visitados[v] = true; // marca como visitado
						fila.push(j); // insere na fila
					}
				}

				cout << endl;
			}

			visitados[v] = true; // marca como visitado

			// verifica se a fila NÃO está vazia
			if (!fila.empty())
			{
				v = fila.front(); // obtém o primeiro elemento
				fila.pop(); // remove da fila
			}
			else
				break;
		}
	}

	int Dijkstra(int orig, int dest)
	{
		bool* visitados;
		visitados = new bool[vertices];

		for (int i = 0; i < vertices; i++)
			visitados[i] = false;

		int min = -1;
		int menorValor = 10000;

		for (int i = 1; i < dest; i++)
		{
			min = -1;
			menorValor = 10000;

			for (int j = orig + 1; j < dest; j++)
			{
				if (!visitados[j] && grafoMatriz[j][orig] < menorValor)
				{
					min = j;
					menorValor = grafoMatriz[j][orig];
				}
			}

			visitados[min] = true;

			/*for (int j = orig + 1; j < dest; j++)
			{
				if (grafoMatriz[min][orig] + grafoMatriz[min][j] < grafoMatriz[j][orig])
				{
					grafoMatriz[j][orig] = grafoMatriz[min][orig] + grafoMatriz[min][j];
				}
			}*/
		}

		return menorValor;
	}

	void WelshPowell(int V)
	{
		cout << "Not implement" << endl;
	}

	int PesoAresta(int v1, int v2) {
		return grafoMatriz[v1][v2];
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
