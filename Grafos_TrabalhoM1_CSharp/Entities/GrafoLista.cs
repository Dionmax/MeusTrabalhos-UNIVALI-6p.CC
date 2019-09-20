using System;
using System.Linq;
using System.Collections.Generic;
using System.Text;
using Grafos_TrabalhoM1_CSharp.Entities.GrafoPackage;

namespace Grafos_TrabalhoM1_CSharp.Entities
{
    class GrafoLista : Grafo
    {
        private List<Vertice> _listaVertices;

        public GrafoLista() : base(false, false)
        {
            _listaVertices = new List<Vertice>();
        }

        public GrafoLista(bool direcionado, bool ponderado)
            : base(direcionado, ponderado)
        {
            _listaVertices = new List<Vertice>();
        }

        public override bool InserirVertice(int indice)
        {
            if (_listaVertices.Where(x => x.Indice == indice).FirstOrDefault() == null)
                _listaVertices.Add(new Vertice(indice));
            else
                return false;

            return true;
        }

        //Isso não está nada bom
        public override void InserirAresta(int vertice1, int vertice2)
        {
            var v1 = _listaVertices.Where(x => x.Indice == vertice1).FirstOrDefault();
            var v2 = _listaVertices.Where(x => x.Indice == vertice2).FirstOrDefault();

            if (v1 == null || v2 == null)
                throw new Exception("Vertice não encontrada");

            v1.VerticesVizinhas.Add(new Aresta(v2, 0));

            if (!Direcionado)
                v2.VerticesVizinhas.Add(new Aresta(v1, 0));
        }

        //Isso não está nada bom também
        public override void InserirAresta(int vertice1, int vertice2, int peso)
        {
            var v1 = _listaVertices.Where(x => x.Indice == vertice1).FirstOrDefault();
            var v2 = _listaVertices.Where(x => x.Indice == vertice2).FirstOrDefault();

            int pesoAux = (Ponderado == true) ? peso : 0;

            if (v1 == null || v2 == null)
                throw new Exception("Vertice não encontrada");

            v1.VerticesVizinhas.Add(new Aresta(v2, pesoAux));

            if (!Direcionado)
                v2.VerticesVizinhas.Add(new Aresta(v1, pesoAux));
        }

        public override void MostrarVizinhos(int V)
        {
            var vertice = _listaVertices.Where(x => x.Indice == V).FirstOrDefault();

            try
            {
                Console.WriteLine($"\nVizinhos do vertice {V}: ");

                foreach (var item in vertice.VerticesVizinhas)
                {
                    Console.WriteLine(item.ToString());
                }
            }
            catch (Exception e)
            {
                Console.WriteLine($"Vertice não encontrado. \n{e.Message}");
            }

            Console.WriteLine();
        }

        public override void BuscaLargura(int V)
        {
            Stack<Vertice> vizitados = new Stack<Vertice>();
            var vertice = _listaVertices.Where(x => x.Indice == V).FirstOrDefault();

            vizitados.Push(vertice);

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

        public override List<Vertice> ListaVertices()
            => _listaVertices;
    }
}
