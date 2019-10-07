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

int GrauSaturacao(int saturacao[], int vertices) {
	int daVez = 0;
	//eu nem o que isso faz, mas...
	for (int j = 0; j < vertices; j++)
	{
		for (int i = 0; i < vertices; i++)
		{

			if (saturacao[i] > daVez) {

				daVez = saturacao[i];
				//maiorGrau = ObterGrauDeSaida(i);

			}

		}
	}
	return daVez;
}
int DSATUR(int vertices, list<pair<int, int>> ListaAdj[])
{
	int* resultado;
	resultado = new int[vertices];

	int* saturacao;
	saturacao = new int[vertices];

	bool* available;
	available = new bool[vertices];

	int daVez = 0;

	// Inicializa os v�rtices V-1 restantes como n�o atribu�dos
	for (int u = 0; u < vertices; u++)
		resultado[u] = -1;

	for (int cr = 0; cr < vertices; cr++)
		available[cr] = false;

	// Atribuir cores aos restantes v�rtices 
	//list<pair<int, int> >::iterator it;
	for (int i = 0; i < vertices; i++)
	{
		// Processa todos os v�rtices adjacentes e sinaliza suas cores
		// como indispon�vel 
		//list<pair<int, int> >::iterator it;

		/*for (auto it : ListaAdj[daVez])
		{
			if (resultado[it.first] != -1)
			{
				available[resultado[it.first]] = true;
			}
			cout << "a";
		}
*/
		// Encontre a primeira cor dispon�vel
		for (int cr = 0; cr < vertices; cr++) {
			if (available[cr] == false) {
				resultado[daVez] = cr;// Atribua a cor encontrada
				/*break;*/
			}
			cout << "b";
		}



		//aumentando a saturacao
		//list<pair<int, int>>::iterator it;
		for (auto it : ListaAdj[daVez])
		{
			if (resultado[it.first] != resultado[daVez]) {
				saturacao[it.first]++;
			}
			cout << "o";
		}

		for (auto a : ListaAdj[0])
		{
			if (resultado[a.first] != resultado[daVez]) {
				saturacao[a.first]++;
			}
			cout << "c";
		}

		// Redefina os valores novamente para false para a pr�xima itera��o
		for (auto it : ListaAdj[daVez]) {

			if (resultado[it.first] != -1) {
				available[resultado[it.first]] = false;
			}
			cout << "d";
		}

		daVez = GrauSaturacao(resultado, vertices);

		
	}

	return 0;
}

