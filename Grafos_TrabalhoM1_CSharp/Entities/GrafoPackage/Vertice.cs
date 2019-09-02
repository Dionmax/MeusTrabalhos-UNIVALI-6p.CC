using System;
using System.Collections.Generic;
using System.Text;

namespace Grafos_TrabalhoM1_CSharp.Entities.GrafoPackage
{
    class Vertice<T>
    {
        public int Indice { get; set; }

        public T Dado { get; set; }

        public List<Vertice<T>> VerticesVizinhas { get; set; }
    }
}
