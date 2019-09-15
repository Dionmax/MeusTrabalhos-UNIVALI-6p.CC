using System;
using System.Collections.Generic;

namespace Simulação_GNA.GNAs
{
    class DistribuicaoTriangular : IDistribuicao
    {
        public int LimiteSuperior { get; set; }

        public int LimiteInferior { get; set; }

        public int Moda { get; set; }

        public int Repeticoes { get; set; }

        private Random _numeroRandom;

        public DistribuicaoTriangular()
        {
            LimiteSuperior = 6;
            LimiteInferior = 0;
            Moda = 3;
            Repeticoes = 2000;
            _numeroRandom = new Random();
        }

        public DistribuicaoTriangular(int limiteSuperior, int limiteInferior, int moda, int repeticoes)
        {
            LimiteSuperior = limiteSuperior;
            LimiteInferior = limiteInferior;
            Moda = moda;
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

                if (nR < ((Moda - LimiteSuperior) / (LimiteInferior - LimiteSuperior)))
                    n = Math.Abs(LimiteSuperior + (Math.Sqrt(nR * (Moda - LimiteSuperior) * (LimiteInferior - LimiteSuperior))));
                else
                    n = Math.Abs(LimiteInferior - (Math.Sqrt((1 - nR) * (LimiteInferior - Moda) * (LimiteInferior - LimiteSuperior))));

                listGerada.Add(n);
            }
            return listGerada;
        }
    }
}
