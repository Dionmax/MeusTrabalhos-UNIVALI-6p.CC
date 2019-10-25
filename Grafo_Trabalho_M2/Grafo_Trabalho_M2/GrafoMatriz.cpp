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
	int* parent; //Usado no KrusKal

public:
	GrafoMatriz() : Grafo()
	{
		grafoMatriz = new int* [vertices];

		for (int i = 0; i < vertices; i++)
			grafoMatriz[i] = new int[vertices];

		for (int i = 0; i < vertices; i++)
			for (int j = 0; j < vertices; j++)
				grafoMatriz[i][j] = INT_MAX;
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

		parent = new int[vertices];
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

	void WelshPowell()
	{
		cout << "Not implement" << endl;
	}

	int DSATUR()
	{
		return 0;
	}

	int PesoAresta(int v1, int v2) {
		return grafoMatriz[v1][v2];
	}

	int minKey(int key[], bool mstSet[])
	{
		// Initialize min value  
		int min = INT_MAX, min_index;

		for (int v = 0; v < vertices; v++)
			if (mstSet[v] == false && key[v] < min)
				min = key[v], min_index = v;

		return min_index;
	}

	void Prim()
	{
		// Array to store constructed MST  
		int* parent;
		parent = new int[vertices];

		// Key values used to pick minimum weight edge in cut  
		int* key;
		key = new int[vertices];

		// To represent set of vertices not yet included in MST  
		bool* mstSet;
		mstSet = new bool[vertices];

		// Initialize all keys as INFINITE  
		for (int i = 0; i < vertices; i++)
			key[i] = INT_MAX, mstSet[i] = false;

		// Always include first 1st vertex in MST.  
		// Make key 0 so that this vertex is picked as first vertex.  
		key[0] = 0;
		parent[0] = -1; // First node is always root of MST  

		// The MST will have V vertices  
		for (int count = 0; count < vertices - 1; count++)
		{
			// Pick the minimum key vertex from the  
			// set of vertices not yet included in MST  
			int u = minKey(key, mstSet);

			// Add the picked vertex to the MST Set  
			mstSet[u] = true;

			// Update key value and parent index of  
			// the adjacent vertices of the picked vertex.  
			// Consider only those vertices which are not  
			// yet included in MST  
			for (int v = 0; v < vertices; v++)

				// graph[u][v] is non zero only for adjacent vertices of m  
				// mstSet[v] is false for vertices not yet included in MST  
				// Update the key only if graph[u][v] is smaller than key[v]  
				if (grafoMatriz[u][v] && mstSet[v] == false && grafoMatriz[u][v] < key[v])
					parent[v] = u, key[v] = grafoMatriz[u][v];
		}

		int soma = 0;
		cout << "Edge \tWeight\n";
		for (int i = 1; i < vertices; i++)
		{
			cout << parent[i] << " - " << i << "	" << grafoMatriz[i][parent[i]] << " \n";
			soma += grafoMatriz[i][parent[i]];
		}

		cout << "\n" << "Soma total caminho minimo: " << soma << endl;
	}

	int find(int i)
	{
		while (parent[i] != i)
			i = parent[i];

		return i;
	}

	void union1(int i, int j)
	{
		int a = find(i);
		int b = find(j);
		parent[a] = b;
	}

	void Kruskal()
	{
		int mincost = 0; // Cost of min MST. 

	// Initialize sets of disjoint sets. 
		for (int i = 0; i < vertices; i++)
			parent[i] = i;

		// Include minimum weight edges one by one 
		int edge_count = 0;
		while (edge_count < vertices - 1) {

			int minim = INT_MAX;
			int a = -1;
			int b = -1;

			for (int i = 0; i < vertices; i++) {
				for (int j = 0; j < vertices; j++) {
					if (find(i) != find(j) && grafoMatriz[i][j] < minim) {
						mincost += minim;
						a = i;
						b = j;
					}
				}
			}

			//cout << minim << endl;

			union1(a, b);
			edge_count++;
			mincost += minim;
		}

		cout << "Custo minimo: " << mincost;
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
