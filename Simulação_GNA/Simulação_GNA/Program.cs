using System;
using Simulação_GNA.GNAs;
using System.IO;
using System.Collections.Generic;
using System.Globalization;

namespace Simulação_GNA
{
    class Program
    {
        static void Main(string[] args)
        {
            IDistribuicao distribuicao;

            var Algo = new List<double>();

            Console.WriteLine("Escolha o tipo de distribuição que desejas: \n");
            Console.WriteLine(" 1 - Distribuição Uniforme.");
            Console.WriteLine(" 2 - Distribuição Triangular.");
            Console.WriteLine(" 3 - Distribuição Exponencial.");
            Console.WriteLine(" 4 - Distribuição Normal. \n");

            Console.Write(" Opção: ");
            int opcao = int.Parse(Console.ReadLine());
            Console.Clear();

            try
            {
                switch (opcao)
                {
                    case 1:
                        Console.WriteLine("Distribuição Uniforme.");

                        Console.Write("Limite Superior: ");
                        var v1 = int.Parse(Console.ReadLine());

                        Console.Write("Limite inferior: ");
                        var v2 = int.Parse(Console.ReadLine());

                        Console.Write("Repetições: ");
                        var repeticoes = int.Parse(Console.ReadLine());

                        distribuicao = new DistribuicaoUniforme(v1, v2, repeticoes);
                        Algo = distribuicao.GerarNumeros();
                        break;

                    case 2:
                        Console.WriteLine("Distribuição Triangular.");

                        Console.Write("Limite Superior: ");
                        v1 = int.Parse(Console.ReadLine());

                        Console.Write("Limite inferior: ");
                        v2 = int.Parse(Console.ReadLine());

                        Console.Write("Moda: ");
                        var v3 = int.Parse(Console.ReadLine());

                        Console.Write("Repetições: ");
                        repeticoes = int.Parse(Console.ReadLine());

                        distribuicao = new DistribuicaoTriangular(v1, v2, v3, repeticoes);
                        Algo = distribuicao.GerarNumeros();
                        break;

                    case 3:
                        Console.WriteLine("Distribuição Exponencial.");

                        Console.Write("Valor Médio: ");
                        var v5 = float.Parse(Console.ReadLine());

                        Console.Write("Valor minimo (0 para nenhum): ");
                        v1 = Math.Abs(int.Parse(Console.ReadLine()));

                        Console.Write("Repetições: ");
                        repeticoes = int.Parse(Console.ReadLine());

                        distribuicao = new DistribuicaoExponencial(v5, v1, repeticoes);
                        Algo = distribuicao.GerarNumeros();
                        break;

                    case 4:
                        Console.WriteLine("Distribuição Normal. \n");

                        Console.Write("Média: ");
                        v1 = int.Parse(Console.ReadLine());

                        Console.Write("Variancia: ");
                        v2 = int.Parse(Console.ReadLine());

                        Console.Write("Repetições: ");
                        repeticoes = int.Parse(Console.ReadLine());

                        distribuicao = new DistribuicaoNormal(v1, v2, repeticoes);
                        Algo = distribuicao.GerarNumeros();
                        break;

                    default:
                        Console.WriteLine("Opção inválida");
                        break;
                }
            }
            catch (FormatException e)
            {
                Console.WriteLine("Entradas de dados invalida: " + e.Message);
            }

            try
            {
                string path = "C:\\Temp\\Saida.txt";

                using (StreamWriter sw = File.AppendText(path))
                {
                    foreach (var line in Algo)
                    {
                        sw.WriteLine(line.ToString(CultureInfo.InvariantCulture));
                    }
                }
            }
            catch (IOException e)
            {
                throw new IOException(e.Message);
            }
        }
    }
}
