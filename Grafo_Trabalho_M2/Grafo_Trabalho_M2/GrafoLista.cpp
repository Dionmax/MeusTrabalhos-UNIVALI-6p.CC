#pragma once
#include <iostream>
#include "Grafo.cpp"
#include <iostream>
#include <list>
#include <algorithm>
#include <stack> 
#include <queue> 
#include <functional>

#define INFINITO 10000000


using namespace std;

class GrafoLista : public Grafo
{
public:

	list<pair<int, int>>* ListaAdj;
	list<pair<int, pair<int, int>>>* ListaAdjPairPair;
	int* parent;

	GrafoLista() : Grafo()
	{
		ListaAdj = new list<pair<int, int>>[0];

	}

	GrafoLista(int vertices, bool direcionado, bool ponderado)
		: Grafo(vertices, direcionado, ponderado)
	{
		ListaAdj = new list<pair<int, int>>[vertices];
		ListaAdjPairPair = new list<pair<int, pair<int, int>>>[vertices];
		parent = new int[vertices];

		for (int i = 0; i < vertices; i++)
			parent[i] = i;

	}

	void InserirAresta(int v1, int v2, int peso)
	{
		ListaAdj[v1].push_back(make_pair(v2, peso));

		if (!direcionado)
			ListaAdj[v2].push_back(make_pair(v1, peso));

		ListaAdjPairPair->push_back({ peso, { v1,v2 } });
	}

	int ObterGrauDeSaida(int v)
	{
		return ListaAdj[v].size();
	}

	void OrdenarGrauSaida()
	{
		for (int i = 0; i < ListaAdj->size() - 1; i++)
		{
			if (ObterGrauDeSaida(i) < ObterGrauDeSaida(i + 1))
			{
				list<pair<int, int>> aux = ListaAdj[i];
				ListaAdj[i] = ListaAdj[i + 1];
				ListaAdj[i + 1] = aux;
			}
		}
	}

	bool ExisteVizinho(int v1, int v2)
	{
		list<pair<int, int> >::iterator it;

		for (it = ListaAdj[v1].begin(); it != ListaAdj[v1].end(); it++)
			if (it->first == v2)
				return true;

		return false;
	}

	void BuscaProfundidade(int v)
	{
		stack<int> pilha;
		bool* visitados; // vetor de visitados
		visitados = new bool[vertices];

		// marca todos como n�o visitados
		for (int i = 0; i < vertices; i++)
			visitados[i] = false;

		while (true)
		{
			cout << "Verificando o " << v << endl;
			if (!visitados[v])
			{
				cout << "Vizinhos: " << v << endl;
				visitados[v] = true; // marca como visitado
				pilha.push(v); // insere "v" na pilha
			}

			bool achou = false;
			list<pair<int, int> >::iterator it;

			// busca por um vizinho n�o visitado
			for (it = ListaAdj[v].begin(); it != ListaAdj[v].end(); it++)
			{
				if (!visitados[it->first])
				{
					achou = true;
					break;
				}
			}

			if (achou)
				v = it->first; // atualiza o "v"
		//	else
			{
				// se todos os vizinhos est�o visitados ou n�o existem vizinhos
				// remove da pilha
				pilha.pop();
				// se a pilha ficar vazia, ent�o terminou a busca
				if (pilha.empty())
					break;
				// se chegou aqui, � porque pode pegar elemento do topo
				v = pilha.top();
			}
		}
	}

	void BuscaLargura(int v)
	{
		queue<int> fila;
		bool* visitados; // vetor de visitados
		visitados = new bool[vertices];

		for (int i = 0; i < vertices; i++)
			visitados[i] = false;

		visitados[v] = true; // marca como visitado

		while (true)
		{
			cout << "Verificando o " << v << "\n";

			list<pair<int, int> >::iterator it;

			for (it = ListaAdj[v].begin(); it != ListaAdj[v].end(); it++)
			{
				if (!visitados[it->first])
				{
					cout << "Visitando vertice " << it->first << " ... \n";
					visitados[it->first] = true; // marca como visitado
					fila.push(it->first); // insere na fila
				}
			}

			cout << endl;

			// verifica se a fila N�O est� vazia
			if (!fila.empty())
			{
				v = fila.front(); // obt�m o primeiro elemento
				fila.pop(); // remove da fila
			}
			else
				break;
		}
	}

	virtual int Dijkstra(int orig, int dest)
	{
		// vetor de dist�ncias
		int* dist;
		dist = new int[vertices];

		/*
		vetor de visitados serve para caso o v�rtice j� tenha sido
		expandido (visitado), n�o expandir mais
		*/
		int* visitados;
		visitados = new int[vertices];

		// fila de prioridades de pair (distancia, v�rtice)
		priority_queue < pair<int, int>,
			vector<pair<int, int> >, greater<pair<int, int> > > pq;

		// inicia o vetor de dist�ncias e visitados
		for (int i = 0; i < vertices; i++)
		{
			dist[i] = INFINITO;
			visitados[i] = false;
		}

		// a dist�ncia de orig para orig � 0
		dist[orig] = 0;

		// insere na fila
		pq.push(make_pair(dist[orig], orig));

		// loop do algoritmo
		while (!pq.empty())
		{
			pair<int, int> p = pq.top(); // extrai o pair do topo
			int u = p.second; // obt�m o v�rtice do pair
			pq.pop(); // remove da fila

					  // verifica se o v�rtice n�o foi expandido
			if (visitados[u] == false)
			{
				// marca como visitado
				visitados[u] = true;

				list<pair<int, int> >::iterator it;

				// percorre os v�rtices "v" adjacentes de "u"
				for (it = ListaAdj[u].begin(); it != ListaAdj[u].end(); it++)
				{
					// obt�m o v�rtice adjacente e o custo da aresta
					int v = it->first;
					int custo_aresta = it->second;

					// relaxamento (u, v)
					if (dist[v] > (dist[u] + custo_aresta))
					{
						// atualiza a dist�ncia de "v" e insere na fila
						dist[v] = dist[u] + custo_aresta;
						pq.push(make_pair(dist[v], v));
					}
				}
			}
		}

		// retorna a dist�ncia m�nima at� o destino
		return dist[dest];
	}

	void WelshPowell()
	{
		int* resultado;
		resultado = new int[vertices];
		int maiorCor = 0;

		queue<int> proximo;

		// Inicializa os v�rtices V-1 restantes como n�o atribu�dos
		for (int u = 0; u < vertices; u++)
			resultado[u] = -1;  // no color is assigned to u 

		// Uma array tempor�ria para armazenar as cores dispon�veis. Verdadeiro
		// valor de [cr] dispon�vel significaria que a cor cr �
		// atribu�do a um de seus v�rtices adjacentes
		bool* available;
		available = new bool[vertices];
		for (int cr = 0; cr < vertices; cr++)
			available[cr] = false;

		//achar o maior grau e botar na fila pra verificacao
		int grauVertice = ObterGrauDeSaida(0);
		int primeiro = 0;
		for (int i = 0; i < vertices; i++)
		{
			if (grauVertice < ObterGrauDeSaida(i)) {
				grauVertice = ObterGrauDeSaida(i);
				proximo.push(i);
			}
		}
		grauVertice--;

		for (int j = 0; j < vertices; j++)
		{
			for (int i = 0; i < vertices; i++)
			{

				if (grauVertice == ObterGrauDeSaida(i)) {

					//maiorGrau = ObterGrauDeSaida(i);
					proximo.push(i);
				}

			}
			if (proximo.size() == vertices)
				break;
			grauVertice--;
		}

		// Atribui a primeira cor ao de maior grau
		resultado[proximo.front()] = 0;
		proximo.pop();

		// Atribuir cores aos restantes v�rtices 
		for (int u = 0; u < vertices; u++)
		{
			if (proximo.empty())
				break;

			int atual = proximo.front();
			proximo.pop();
			// Processa todos os v�rtices adjacentes e sinaliza suas cores
			// como indispon�vel 
			list<pair<int, int> >::iterator it;
			for (it = ListaAdj[atual].begin(); it != ListaAdj[atual].end(); ++it) {
				if (resultado[it->first] != -1) {
					available[resultado[it->first]] = true;
				}
			}

			// Encontre a primeira cor dispon�vel
			for (int cr = 0; cr < vertices; cr++)
				if (available[cr] == false) {
					resultado[atual] = cr;// Atribua a cor encontrada
					break;
				}

			// Redefina os valores novamente para false para a pr�xima itera��o
			for (it = ListaAdj[atual].begin(); it != ListaAdj[atual].end(); ++it)
				if (resultado[it->first] != -1)
					available[resultado[it->first]] = false;
		}

		// Mostra o resultado
		for (int u = 0; u < vertices; u++)
			cout << "Vertice " << u << " --->  Cor "
			<< resultado[u] << endl;

		cout << endl;

		for (int i = 0; i < vertices; i++)
		{
			if (resultado[i] > maiorCor)
			{
				maiorCor = resultado[i];
			}
		}

		cout << endl << "Maior cor usada: " << maiorCor << endl;
	}

	int GrauSaturacao(int saturacao[], int vertices) {
		int daVez = 0;
		for (int j = 0; j < vertices; j++)
		{
			for (int i = 0; i < vertices; i++)
			{
				if (saturacao[i] > daVez) {

					daVez = saturacao[i];
				}
			}
		}
		return daVez;
	}

	int DSATUR()
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

			for (auto it : ListaAdj[daVez])
			{
				if (resultado[it.first] != -1)
				{
					available[resultado[it.first]] = true;
				}
			}

			// Encontre a primeira cor dispon�vel
			for (int cr = 0; cr < vertices; cr++) {
				if (available[cr] == false) {
					resultado[daVez] = cr;// Atribua a cor encontrada
					continue; // Era um Break
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
			}

			for (auto a : ListaAdj[0])
			{
				if (resultado[a.first] != resultado[daVez]) {
					saturacao[a.first]++;
				}
			}

			// Redefina os valores novamente para false para a pr�xima itera��o
			for (auto it : ListaAdj[daVez]) {

				if (resultado[it.first] != -1) {
					available[resultado[it.first]] = false;
				}
			}

			daVez = GrauSaturacao(resultado, vertices);
		}

		return 0;
	}

	void Prim()
	{
		priority_queue< pair<int, int>, vector <pair<int, int>>, greater<pair<int, int>> > pq;

		int src = 0; // Taking vertex 0 as source 

		// Create a vector for keys and initialize all 
		// keys as infinite (INF) 
		vector<int> key(vertices, INFINITO);

		// To store parent array which in turn store MST 
		vector<int> parent(vertices, -1);

		// To keep track of vertices included in MST 
		vector<bool> inMST(vertices, false);

		// Insert source itself in priority queue and initialize 
		// its key as 0. 
		pq.push(make_pair(0, src));
		key[src] = 0;

		/* Looping till priority queue becomes empty */
		while (!pq.empty())
		{

			int u = pq.top().second;
			pq.pop();

			inMST[u] = true;  // Include vertex in MST 

			// 'i' is used to get all adjacent vertices of a vertex 
			list< pair<int, int> >::iterator i;
			for (i = ListaAdj[u].begin(); i != ListaAdj[u].end(); ++i)
			{
				// Get vertex label and weight of current adjacent 
				// of u. 
				int v = (*i).first;
				int weight = (*i).second;

				//  If v is not in MST and weight of (u,v) is smaller 
				// than current key of v 
				if (inMST[v] == false && key[v] > weight)
				{
					// Updating key of v 
					key[v] = weight;
					pq.push(make_pair(key[v], v));
					parent[v] = u;
				}
			}
		}

		// Print edges of MST using parent array 
		int result = 0;
		for (int i = 1; i < vertices; ++i) {
			result += parent[i];
		}
		cout << "Resultado: " << result;
	}

	void union_set(int u, int v) {
		parent[u] = parent[v];
	}

	int find_set(int i) {
		while (parent[i] != i)
			i = parent[i];

		return i;
	}


	// To represent Disjoint Sets 
	struct DisjointSets
	{
		int* parent, * rnk;
		int n;

		// Constructor. 
		DisjointSets(int n)
		{
			// Allocate memory 
			this->n = n;
			parent = new int[n + 1];
			rnk = new int[n + 1];

			// Initially, all vertices are in 
			// different sets and have rank 0. 
			for (int i = 0; i <= n; i++)
			{
				rnk[i] = 0;

				//every element is parent of itself 
				parent[i] = i;
			}
		}

		// Find the parent of a node 'u' 
		// Path Compression 
		int find(int u)
		{
			/* Make the parent of the nodes in the path
			   from u--> parent[u] point to parent[u] */
			if (u != parent[u])
				parent[u] = find(parent[u]);
			return parent[u];
		}

		// Union by rank 
		void merge(int x, int y)
		{
			x = find(x), y = find(y);

			/* Make tree with smaller height
			   a subtree of the other tree  */
			if (rnk[x] > rnk[y])
				parent[y] = x;
			else // If rnk[x] <= rnk[y] 
				parent[x] = y;

			if (rnk[x] == rnk[y])
				rnk[y]++;
		}
	};

	list<pair<int, int>>* T = new list<pair<int, int>>[vertices];
	//list<int>* T = new list<int>[vertices];
	typedef  pair<int, int> iPair;
	vector< pair<int, iPair> > edges;

	void Kruskal()
	{
		int mst_wt = 0; // Initialize result 

	// Sort edges in increasing order on basis of cost 
		sort(edges.begin(), edges.end());

		// Create disjoint sets 
		DisjointSets ds(vertices);

		// Iterate through all sorted edges 
		list< pair<int, pair<int, int>>>::iterator it;
		for (it = ListaAdjPairPair->begin(); it != ListaAdjPairPair->end(); it++)
		{
			int u = it->second.first;
			int v = it->second.second;

			int set_u = ds.find(u);
			int set_v = ds.find(v);

			// Check if the selected edge is creating 
			// a cycle or not (Cycle is created if u 
			// and v belong to same set) 
			if (set_u != set_v)
			{
				// Current edge will be in the MST 
				// so print it 
				cout << u << " - " << v << endl;

				// Update MST weight 
				mst_wt += it->first;

				// Merge two sets 
				ds.merge(set_u, set_v);
			}
		}

		cout << mst_wt;
	}

	list<pair<int, int>> getLista()
	{
		return *ListaAdj;
	}

	void printarLista()
	{
		int soma = 0;

		for (int i = 0; i < vertices; i++)
		{
			for (auto it : ListaAdj[i])
			{
				cout << "Vertice: " << it.first << " Peso: " << it.second << endl;
				soma += it.second;
			}
		}

		cout << soma;
	}
};
