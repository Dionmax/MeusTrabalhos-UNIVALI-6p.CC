#pragma once
#include <iostream>
#include <algorithm>
#include <vector>
#include <algorithm>
#include <string.h>

using namespace std;

class Aresta
{
	int vertice1, vertice2, peso;

public:

	Aresta(int v1, int v2, int peso)
	{
		vertice1 = v1;
		vertice2 = v2;
		this->peso = peso;
	}

	int obterVertice1()
	{
		return vertice1;
	}

	int obterVertice2()
	{
		return vertice2;
	}

	int obterPeso()
	{
		return peso;
	}

	// sobrescrita do operador "<"
	bool operator < (const Aresta& aresta2) const
	{
		return (peso < aresta2.peso);
	}
};


class Grafo
{
	//vector<string> vertices;
	vector<Aresta> arestas; // vetor de arestas

	bool ponderado;
	bool direcionado;

public:

	vector<string> vertices;

	Grafo()
	{

	}

	void adicionarVertice(string label)
	{
		vertices.push_back(label);
	}

	// função que adiciona uma aresta
	void adicionarAresta(int v1, int v2, int peso)
	{
		Aresta aresta(v1, v2, peso);
		arestas.push_back(aresta);
	}

	void adicionarAresta(int v1, int v2)
	{
		Aresta aresta(v1, v2, -1);
		arestas.push_back(aresta);
	}

	// função que busca o subconjunto de um elemento "i"
	int buscar(int subset[], int i)
	{
		if (subset[i] == -1)
			return i;
		return buscar(subset, subset[i]);
	}

	// função para unir dois subconjuntos em um único subconjunto
	void unir(int subset[], int v1, int v2)
	{
		int v1_set = buscar(subset, v1);
		int v2_set = buscar(subset, v2);
		subset[v1_set] = v2_set;
	}
};
