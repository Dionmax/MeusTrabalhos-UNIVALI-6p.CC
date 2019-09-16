using System;
using System.Collections.Generic;
using System.Text;

namespace Simulação_GNA.GNAs
{
    class DistribuicaoExponencial : IDistribuicao
    {
        public float ValorMedio { get; set; }

        public int Variancia { get; set; }

        public int Repeticoes { get; set; }

        private Random _numeroRandom;

        public DistribuicaoExponencial()
        {
            ValorMedio = 5.5F;
            Variancia = 0;
            Repeticoes = 2000;
            _numeroRandom = new Random();
        }

        public DistribuicaoExponencial(float valorMedio, int variancia, int repeticoes)
        {
            ValorMedio = valorMedio;
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

                n = Variancia - (ValorMedio - Variancia) * Math.Log(nR);

                listGerada.Add(n);
            }
            return listGerada;
        }
    }
}
