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

            IDistribuicao uniforme = new DistribuicaoUniforme();
            IDistribuicao triangular = new DistribuicaoTriangular();
            IDistribuicao normal = new DistribuicaoNormal();
            IDistribuicao exponencial = new DistribuicaoExponencial();

            var Algo = exponencial.GerarNumeros();

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
