#pragma once
class Grafo
{
public:

	int vertices = 0;
	bool direcionado = false;
	bool ponderado = false;

	Grafo() {}

	Grafo(int vertices, bool direcionado, bool ponderado)
	{
		this->vertices = vertices;
		this->direcionado = direcionado;
		this->ponderado = ponderado;
	}

	virtual ~Grafo() {}

	int getNumeroVertices() { return vertices; }

	virtual void InserirAresta(int v1, int v2, int peso) = 0;
	//virtual int ObterGrauDeSaida(int v) = 0;
	//virtual bool ExisteVizinho(int v1, int v2) = 0;
	//virtual void BuscaProfundidade(int v) = 0;
	//virtual void BuscaLargura(int v) = 0;
	//virtual int Dijkstra(int orig, int dest) = 0;
	//virtual int VerificarPlanaridade() = 0;
	//virtual int Welsh() = 0;
	//virtual int Powell() = 0;
	//virtual int DSATUR() = 0;
};
