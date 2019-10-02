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


            grafoLista.InserirVertice(1); //A
            grafoLista.InserirVertice(2); //B
            grafoLista.InserirVertice(3); //C
            grafoLista.InserirVertice(4); //D
            grafoLista.InserirVertice(5); //E
            grafoLista.InserirVertice(6); //F
            grafoLista.InserirVertice(7); //G


            grafoLista.InserirAresta(1, 2);
            grafoLista.InserirAresta(1, 4);
            grafoLista.InserirAresta(1, 3);
            grafoLista.InserirAresta(4, 2);
            grafoLista.InserirAresta(3, 5);
            grafoLista.InserirAresta(3, 6);

            //grafoLista.MostrarVizinhos(3);

            //grafoLista.BuscaLargura(4);
        }
    }
}
