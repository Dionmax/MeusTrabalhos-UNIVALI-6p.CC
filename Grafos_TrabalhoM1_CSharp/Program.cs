using System;
using System.Linq;
using System.Collections.Generic;
using Grafos_TrabalhoM1_CSharp.Entities;
using Grafos_TrabalhoM1_CSharp.Entities.GrafoPackage;

namespace Grafos_TrabalhoM1_CSharp
{
    class Program
    {
        static void Main(string[] args)
        {
            Grafo grafoLista = new GrafoLista();


            
            grafoLista.InserirVertice(2);
            grafoLista.InserirVertice(3);
            grafoLista.InserirVertice(4);
            grafoLista.InserirVertice(5);
            grafoLista.InserirVertice(1);


            grafoLista.InserirAresta(2, 3);
            grafoLista.InserirAresta(2, 4);
            grafoLista.InserirAresta(2, 5);

            //grafoLista.MostrarVizinhos(2);
            //grafoLista.MostrarVizinhos(26);
            //grafoLista.MostrarVizinhos(3);

            grafoLista.BuscaLargura(2);
        }
    }
}
