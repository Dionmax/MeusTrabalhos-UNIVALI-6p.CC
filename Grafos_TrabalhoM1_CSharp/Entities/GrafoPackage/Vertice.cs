using System;
using System.Collections.Generic;
using System.Text;

namespace Grafos_TrabalhoM1_CSharp.Entities.GrafoPackage
{
    class Vertice
    {
        public int Indice { get; private set; }

        //  public T Dado { get; set; }

        public List<Aresta> VerticesVizinhas { get; set; }

        public Vertice(int indice)
        {
            Indice = indice;
            VerticesVizinhas = new List<Aresta>();
        }

        public override string ToString()
            => Indice.ToString();
    }
}
