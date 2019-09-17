using System;
using System.Collections.Generic;
using System.Text;
using Grafos_TrabalhoM1_CSharp.Entities.GrafoPackage;

namespace Grafos_TrabalhoM1_CSharp.Entities
{
    class GrafoLista : Grafo
    {
        public GrafoLista(bool direcionado, bool ponderado)
            : base(direcionado, ponderado)
        {

        }

        public override bool InserirVertice()
        {
            throw new NotImplementedException();
        }

        public override void MostrarVizinhos()
        {
            throw new NotImplementedException();
        }

        public override void BuscaLargura()
        {
            throw new NotImplementedException();
        }

        public override void BuscaProfundidade()
        {
            throw new NotImplementedException();
        }

        public override void Djsktra()
        {
            throw new NotImplementedException();
        }

        public override bool GrafoPlanar()
        {
            throw new NotImplementedException();
        }
    }
}
