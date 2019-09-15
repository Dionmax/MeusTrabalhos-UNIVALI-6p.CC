
using System;
using System.Collections.Generic;
using System.Text;

namespace Simulação_GNA.GNAs.ExceptionGNA
{
    class DistribuicaoException : ApplicationException, IDistribuicao
    {
        public DistribuicaoException(string exception) : base(exception) { }

        public List<double> GerarNumeros()
        {
            throw new NotImplementedException("Não implementado!");
        }
    }
}
