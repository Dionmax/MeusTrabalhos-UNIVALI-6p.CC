using System;
using System.Collections.Generic;

namespace Simulação_GNA.GNAs
{
    class DistribuicaoExponencial : IDistribuicao
    {
        public float ValorMedio { get; set; }

        public int ValorMinimo { get; set; }

        public int Repeticoes { get; set; }

        private Random _numeroRandom;

        public DistribuicaoExponencial()
        {
            ValorMedio = 5.5F;
            ValorMinimo = 0;
            Repeticoes = 2000;
            _numeroRandom = new Random();
        }

        public DistribuicaoExponencial(float valorMedio, int variancia, int repeticoes)
        {
            ValorMedio = valorMedio;
            ValorMinimo = variancia;
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

                n = ValorMinimo - (ValorMedio - ValorMinimo) * Math.Log(nR);

                listGerada.Add(n);
            }
            return listGerada;
        }
    }
}
