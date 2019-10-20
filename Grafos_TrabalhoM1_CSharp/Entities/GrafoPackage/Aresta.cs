using System;
using System.Collections.Generic;
using System.Text;

namespace Grafos_TrabalhoM1_CSharp.Entities.GrafoPackage
{
    class Aresta
    {
        public Vertice Nodo { get; set; }

        public int Peso { get; set; }

        public Aresta(Vertice nodo, int peso)
        {
            Nodo = nodo;
            Peso = peso;
        }

        public override string ToString()
        {
            return $"Vertice {Nodo.Indice} - Peso: {Peso}";
        }
    }
}
