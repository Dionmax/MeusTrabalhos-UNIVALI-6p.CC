#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <list>

#include "CaixeiroMetodos.cpp"

using namespace std;

int main()
{
	BuscaExaustiva be = BuscaExaustiva(5);
	BuscaVizinhoProximo bvp = BuscaVizinhoProximo(5);

	be.inserirAresta(0, 1, 185);
	be.inserirAresta(0, 2, 119);
	be.inserirAresta(0, 3, 152);
	be.inserirAresta(0, 4, 133);

	be.inserirAresta(1, 2, 121);
	be.inserirAresta(1, 3, 150);
	be.inserirAresta(1, 4, 200);

	be.inserirAresta(2, 3, 174);
	be.inserirAresta(2, 4, 120);

	be.inserirAresta(3, 4, 199);

	bvp.inserirAresta(0, 1, 185);
	bvp.inserirAresta(0, 2, 119);
	bvp.inserirAresta(0, 3, 152);
	bvp.inserirAresta(0, 4, 133);

	bvp.inserirAresta(1, 2, 121);
	bvp.inserirAresta(1, 3, 150);
	bvp.inserirAresta(1, 4, 200);

	bvp.inserirAresta(2, 3, 174);
	bvp.inserirAresta(2, 4, 120);

	bvp.inserirAresta(3, 4, 199);

	//be.mostrarVizinhos(0);

	//cout << be.encontrarMenorCaminho(0);

	//be.BuscaProfundidade(0);

	cout << "Menor custo ";
	bvp.CustoMinimo(0);
	cout << endl;
	cout << "Menor custo pelo caminho: " << bvp.custo << endl;

	//bvp.DesenharMatriz();

	cout << endl;
}
