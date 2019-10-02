#include <iostream>
#include "Grafo.cpp"
#include "GrafoLista.cpp"
#include "GrafoMatriz.cpp"

using namespace std;

int main()
{
	GrafoMatriz grafo = GrafoMatriz(5, false, false);


	grafo.InserirAresta(0, 1, 3);
	grafo.InserirAresta(0, 2, 5);
	grafo.InserirAresta(0, 3, 6);
	grafo.InserirAresta(0, 4, 8);
	grafo.InserirAresta(1, 3, 2);
	grafo.InserirAresta(1, 4, 11);
	grafo.InserirAresta(2, 4, 2);
	grafo.InserirAresta(3, 4, 1);

	grafo.DesenharMatriz();

	//cout << graforlista.ObterGrauDeSaida(0) << endl;
	//cout << graforlista.ExisteVizinho(1, 3) << endl;
	//cout << endl;
	//graforlista.BuscaLargura(2);
	//cout << endl;
	//graforlista.BuscaProfundidade(0);
	//cout << endl;
	//cout << grafo.Dijkstra(3, 0) << endl;
}
