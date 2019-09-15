using System;
using System.Collections.Generic;
using System.Text;

namespace Simulação_GNA.GNAs
{
    class DistribuicaoNormal : IDistribuicao
    {
        public float Media { get; set; }

        public float Variancia { get; set; }

        public int Repeticoes { get; set; }

        private Random _numeroRandom;

        public DistribuicaoNormal()
        {
            Media = 5.5F;
            Variancia = 2.1F;
            Repeticoes = 2000;
            _numeroRandom = new Random();
        }

        public DistribuicaoNormal(float media, float variancia, int repeticoes)
        {
            Media = media;
            Variancia = variancia;
            Repeticoes = repeticoes;
            _numeroRandom = new Random();
        }

        public List<double> GerarNumeros()
        {
            List<double> listGerada = new List<double>();

            var n = 0.0;

            for (int i = 0; i < Repeticoes; i++)
            {
                double nR = _numeroRandom.NextDouble();
                double nR2 = _numeroRandom.NextDouble();

                var z = Math.Sqrt(-2 * Math.Log(nR)) * Math.Sin(2 * Math.PI * nR2);

                n = Media + Variancia * z;

                listGerada.Add(n);
            }

            return listGerada;
        }
    }
}
