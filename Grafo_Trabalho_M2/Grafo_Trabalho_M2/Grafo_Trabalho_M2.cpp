#include <iostream>
#include "Grafo.cpp"
#include "GrafoLista.cpp"

using namespace std;

int main()
{
	GrafoLista grafolista = GrafoLista(5, false, false);

	grafolista.InserirAresta(0, 1, 3);
	grafolista.InserirAresta(0, 2, 5);
	grafolista.InserirAresta(0, 3, 6);
	grafolista.InserirAresta(0, 4, 8);
	grafolista.InserirAresta(1, 3, 2);
	grafolista.InserirAresta(1, 4, 11);
	grafolista.InserirAresta(2, 4, 2);
	grafolista.InserirAresta(3, 4, 1);

	//cout << graforlista.ObterGrauDeSaida(0) << endl;
	//cout << graforlista.ExisteVizinho(1, 3) << endl;
	//cout << endl;
	//graforlista.BuscaLargura(2);
	//cout << endl;
	//graforlista.BuscaProfundidade(0);
	//cout << endl;
	cout << grafolista.Dijkstra(3, 0) << endl;
}
