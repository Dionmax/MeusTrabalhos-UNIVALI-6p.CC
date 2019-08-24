using System;
using System.Collections.Generic;
using System.Text;

namespace Grafos_TrabalhoM1_CSharp.Entities.Grafo
{
    abstract class Grafo
    {
        public bool Direcionado { get; private set; }

        public bool Ponderado { get; private set; }

        public Grafo(bool direcionado, bool ponderado)
        {
            Direcionado = direcionado;
            Ponderado = ponderado;
        }

        //Djsktra, Profundidade, Largura
    }
}
