using System;
using System.Collections.Generic;
using System.Text;

namespace Grafos_TrabalhoM1_CSharp.ClassLegacy
{
    class Pair<T, U>
    {
        public T First { get; set; }

        public U Second { get; set; }

        public Pair() { }

        //Primeiro valor <T> / Segundo valor <U>
        public Pair(T first, U second)
        {
            First = first;
            Second = second;
        }
    }
}
