using System;
using Simulação_GNA.GNAs;
using System.IO;
using System.Text;
using System.Globalization;

namespace Simulação_GNA
{
    class Program
    {
        static void Main(string[] args)
        {
            string path = "C:\\Temp\\Saida.txt";

            DistribuicaoUniforme uniforme = new DistribuicaoUniforme();
            DistribuicaoTriangular triangular = new DistribuicaoTriangular();
            DistribuicaoNormal normal = new DistribuicaoNormal();

            var Algo = normal.GerarNumeros();

            try
            {
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
