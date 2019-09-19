using System;
using System.Collections.Generic;

namespace Simulação_GNA.GNAs
{
    class DistribuicaoTriangular : IDistribuicao
    {
        public float LimiteA { get; set; }

        public float LimiteB { get; set; }

        public float Moda { get; set; }

        public int Repeticoes { get; set; }

        private Random _numeroRandom;

        public DistribuicaoTriangular()
        {
            LimiteA = 6;
            LimiteB = 0;
            Moda = 3;
            Repeticoes = 2000;
            _numeroRandom = new Random();
        }

        public DistribuicaoTriangular(float limiteSuperior, float limiteInferior, float moda, int repeticoes)
        {
            LimiteA = limiteSuperior;
            LimiteB = limiteInferior;
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
                n = 0.0;

                double nR = _numeroRandom.NextDouble();


                if (nR < ((Moda - LimiteA) / (LimiteB - LimiteA)))
                    n = (LimiteA) + (Math.Sqrt(nR * (Moda - LimiteA) * (LimiteB - LimiteA)));
                else
                    n = (LimiteB) - (Math.Sqrt((1 - nR) * (LimiteB - Moda) * (LimiteB - LimiteA)));

                listGerada.Add(n);
            }
            return listGerada;
        }
    }
}
