using System;
using System.Collections.Generic;
using System.Text;

namespace Grafos_TrabalhoM1_CSharp.Entities.GrafoPackage
{
    abstract class Grafo
    {
        public bool Direcionado { get; private set; }

        public bool Ponderado { get; private set; }

        public Grafo() { }

        public Grafo(bool direcionado, bool ponderado)
        {
            Direcionado = direcionado;
            Ponderado = ponderado;
        }

        abstract public bool InserirVertice(int indice);

        // abstract public bool InserirVertice<T>(int indice, T dado);

        abstract public void InserirAresta(int vertice1, int vertice2);

        abstract public void InserirAresta(int vertice1, int vertice2, int peso);

        abstract public void MostrarVizinhos(int vertice);

        abstract public void BuscaLargura(int V);

        abstract public void BuscaProfundidade();

        abstract public void Djsktra();

        abstract public bool GrafoPlanar(); // Depois 

        abstract public List<Vertice> ListaVertices();
    }
}
