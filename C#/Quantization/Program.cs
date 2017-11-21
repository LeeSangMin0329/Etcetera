using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Quantization
{
    class Program
    {

        

   
        static void Main(string[] args)
        {
            int[] a = new int[] { 1, 3, 5, 7 };
            Quantize aq = new Quantize(a, 2);
            aq.QuantizeOnPivot(0, 1);
            aq.CachePrint();
            System.Console.Write( aq.BlockAverage(0, 2));

        }
    }
}
