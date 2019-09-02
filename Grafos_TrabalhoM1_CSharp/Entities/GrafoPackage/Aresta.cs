using System;
using System.Collections.Generic;
using System.Text;

namespace Grafos_TrabalhoM1_CSharp.Entities.GrafoPackage
{
    class Aresta<T>
    {
        public Vertice<T> NodoUm { get; set; }

        public int Peso { get; set; }

        public Vertice<T> NodoDois { get; set; }
    }
}
