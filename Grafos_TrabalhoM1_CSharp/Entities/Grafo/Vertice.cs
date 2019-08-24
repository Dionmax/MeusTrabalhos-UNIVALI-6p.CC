using System;
using System.Collections.Generic;
using System.Text;

namespace Grafos_TrabalhoM1_CSharp.Entities.Grafo
{
    class Vertice<T>
    {
        public int Indice { get; set; }

        public int Peso { get; set; }

        public T Dado { get; set; }
    }
}
