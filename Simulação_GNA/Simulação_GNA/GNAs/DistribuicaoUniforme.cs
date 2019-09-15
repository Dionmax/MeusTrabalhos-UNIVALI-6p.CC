using System;
using System.Collections.Generic;

namespace Simulação_GNA.GNAs
{
    class DistribuicaoUniforme
    {
        public int LimiteSuperior { get; set; }

        public int LimiteInferior { get; set; }

        public int Repeticoes { get; set; }

        private Random _numeroRandom;

        public DistribuicaoUniforme()
        {
            LimiteSuperior = 5;
            LimiteInferior = 0;
            Repeticoes = 1000;
            _numeroRandom = new Random();
        }

        public DistribuicaoUniforme(int limiteSuperior, int limiteInferior, int repeticoes)
        {
            LimiteSuperior = limiteSuperior;
            LimiteInferior = limiteInferior;
            Repeticoes = repeticoes;
            _numeroRandom = new Random();
        }

        public List<double> GerarNumeros()
        {
            List<double> listGerada = new List<double>();

            for (int i = 0; i < Repeticoes; i++)
            {
                var n = LimiteSuperior + (LimiteInferior - LimiteSuperior) * _numeroRandom.NextDouble();

                listGerada.Add(n);
            }
            return listGerada;
        }
    }
}
