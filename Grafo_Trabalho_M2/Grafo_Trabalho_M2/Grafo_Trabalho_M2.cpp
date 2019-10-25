#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <list>

#include "Grafo.cpp"
#include "GrafoLista.cpp"
#include "GrafoMatriz.cpp"
#include "Dsatur.h"

using namespace std;

vector<string> split(string str, char delimiter = ' ')
{
	vector<string> ret;

	int start = 0;

	for (int i = 0; i < str.length(); ++i) {
		if (str[i] == delimiter) {
			if (i - start != 0)
				ret.push_back(str.substr(start, i - start));
			start = i + 1;
		}
	}

	if (str.length() - start != 0)
		ret.push_back(str.substr(start, start - str.length()));

	return ret;
}

int main()
{
	//GrafoLista grafo;
	GrafoMatriz grafo;

	string path = "C:/Temp/50vertices25%Arestas.txt";
	ifstream texto(path);

	string line = "";

	int valoresHead[4] = { 0, 0, 0, 0 };
	int valoresBody[3] = { 0 , 0, 0 };

	if (texto.is_open())
	{
		getline(texto, line);

		int i = 0;

		for (auto it : split(line, ' ')) {
			valoresHead[i] = stoi(it);
			i++;
		}

		i = 0;

		//grafo = GrafoLista(valoresHead[0], true && valoresHead[2], true && valoresHead[3]);
		grafo = GrafoMatriz(valoresHead[0], true && valoresHead[2], true && valoresHead[3]);

		while (!texto.eof())
		{
			getline(texto, line);

			for (auto it : split(line, ' ')) {
				valoresBody[i] = stoi(it);
				i++;
			}

			grafo.InserirAresta(valoresBody[0], valoresBody[1], valoresBody[2]);

			i = 0;
		}

		texto.close();
	}
	else
		cout << "Unable to open file";

	grafo.Kruskal();
	//grafo.printarLista();
	//grafo.DesenharMatriz();
}
