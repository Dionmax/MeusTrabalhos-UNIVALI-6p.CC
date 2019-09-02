#include <iostream>
#include <vector>
#include "Grafo.h"

using namespace std;

int main()
{
	Grafo grf;

	grf.adicionarVertice("adsds 1");
	grf.adicionarVertice("adsds 2");
	grf.adicionarVertice("adsds 3");
	grf.adicionarVertice("adsds 4");

	cout << grf.vertices[3] << "\n";
}
