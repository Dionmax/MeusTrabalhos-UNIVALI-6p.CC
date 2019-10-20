#pragma once
#include <iostream>
#include <iostream>
#include <list>
#include <algorithm>
#include <stack> 
#include <queue> 
#include <functional>

using namespace std;

class BuscaExaustiva
{
public:
	int** grafoMatriz;
	int vertices = 0;

	BuscaExaustiva(int v)
	{
		vertices = v;

		grafoMatriz = new int* [vertices];

		for (int i = 0; i < vertices; i++)
			grafoMatriz[i] = new int[vertices];

		for (int i = 0; i < vertices; i++)
			for (int j = 0; j < vertices; j++)
				grafoMatriz[i][j] = INFINITY;
	}

	void inserirAresta(int v1, int v2, int peso)
	{
		if (grafoMatriz[v1][v2] == 0)
		{
			grafoMatriz[v1][v2] = peso;

			grafoMatriz[v2][v1] = peso;
		}
		else
		{
			cout << "Aresta ja existe" << endl;
		}
	}

	void DesenharMatriz()
	{
		for (int i = 0; i < vertices; i++) {
			for (int j = 0; j < vertices; j++)
				cout << "  " << grafoMatriz[i][j] << "	|";

			cout << "\n";
		}
	}

	int encontrarMenorCaminho(int v) 
	{
		vector<int> vetorPesos;

		for (int i = 0; i < vertices; i++)
			if (i != v)
				vetorPesos.push_back(i);

		int menorCaminho = INT_MAX;
		do {

			int custoMenorCaminhoAtual = 0;

			int k = v;

			for (int i = 0; i < vetorPesos.size(); i++) {
				custoMenorCaminhoAtual += grafoMatriz[k][vetorPesos[i]];
				k = vetorPesos[i];
			}
			custoMenorCaminhoAtual += grafoMatriz[k][v];

			menorCaminho = min(menorCaminho, custoMenorCaminhoAtual);

		} while (next_permutation(vetorPesos.begin(), vetorPesos.end()));

		return menorCaminho;
	}
};

class BuscaVizinhoProximo
{
public:
	int** grafoMatriz;
	int vertices = 0;
	int cidadesVizitadas[5];
	int custo = 0;

	BuscaVizinhoProximo(int v)
	{
		vertices = v;

		grafoMatriz = new int* [vertices];

		for (int i = 0; i < vertices; i++)
			grafoMatriz[i] = new int[vertices];

		for (int i = 0; i < vertices; i++)
			for (int j = 0; j < vertices; j++)
				grafoMatriz[i][j] = INFINITY;
	}

	void inserirAresta(int v1, int v2, int peso)
	{
		if (grafoMatriz[v1][v2] == 0)
		{
			grafoMatriz[v1][v2] = peso;

			grafoMatriz[v2][v1] = peso;
		}
		else
		{
			cout << "Aresta ja existe" << endl;
		}
	}

	void DesenharMatriz()
	{
		for (int i = 0; i < vertices; i++) {
			for (int j = 0; j < vertices; j++)
				cout << "  " << grafoMatriz[i][j] << "	|";

			cout << "\n";
		}
	}

	void CustoMinimo(int v)
	{
		int CidadeProxima;
		cidadesVizitadas[v] = 1;

		cout << v + 1 << " ";
		CidadeProxima = encontrarMenorCaminho(v);

		if (CidadeProxima == 999)
		{
			CidadeProxima = 0;
			cout << CidadeProxima + 1 << " ";
			custo = custo + grafoMatriz[v][CidadeProxima];
			return;
		}
		CustoMinimo(CidadeProxima);

		cout << custo << " ";
	}

	int encontrarMenorCaminho(int v)
	{
		int contador;
		int cidadeProxima = 999;
		int mini = 999;
		int temp;

		for (contador = 0; contador < vertices; contador++)
		{
			if ((grafoMatriz[v][contador] != 0) && (cidadesVizitadas[contador] == 0))
			{
				if (grafoMatriz[v][contador] < mini)
				{
					mini = grafoMatriz[contador][0] + grafoMatriz[v][contador];
				}
				temp = grafoMatriz[v][contador];
				cidadeProxima = contador;
			}
		}
		if (mini != 999)
			custo = custo + temp;

		return cidadeProxima;
	}
};
