#include <iostream>
#include "Grafo.cpp"
#include "GrafoLista.cpp"
#include "GrafoMatriz.cpp"

using namespace std;

int main()
{
	GrafoMatriz grafo = GrafoMatriz(5, false, true);
	//GrafoLista grafo = GrafoLista(5, false, false);


	grafo.InserirAresta(0, 1, 3);
	grafo.InserirAresta(0, 2, 5);
	grafo.InserirAresta(0, 3, 6);
	grafo.InserirAresta(0, 4, 8);
	grafo.InserirAresta(1, 3, 2);
	grafo.InserirAresta(1, 4, 11);
	grafo.InserirAresta(2, 4, 2);
	grafo.InserirAresta(3, 4, 1);

	//cout << grafo.PesoAresta(0, 1);
	//grafo.BuscaLargura(0);
	//grafo.BuscaProfundidade(0);
	//cout << grafo.ExisteVizinho(2, 0);
	//cout << grafo.ObterGrauDeSaida(0);
	cout << grafo.Dijkstra(2, 4) << endl;
	grafo.DesenharMatriz();
}
