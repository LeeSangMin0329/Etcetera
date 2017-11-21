using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Quantization
{
    class Quantize
    {
        private int[] mDataArray;
        private int mNumOfQuantize;
        private int[] mPartIndexSum;
        private int[] mPartIndexSquareSum;
        private int CATEGORIZEOVER = 9999999;

        
        
        private int[,] cache;

        public Quantize(int[] dataArray, int numberOfQuantize)
        {
            
            mDataArray = (int[])dataArray.Clone();

            mNumOfQuantize = numberOfQuantize;
            Array.Sort(mDataArray);

            cache = new int[dataArray.Length, numberOfQuantize];

            mPartIndexSum = new int[mDataArray.Length];
            mPartIndexSum[0] = mDataArray[0];
            mPartIndexSquareSum = new int[mDataArray.Length];
            mPartIndexSquareSum[0] = mDataArray[0] * mDataArray[0];
            for (int i=1; i<mDataArray.Length; i++)
            {
                mPartIndexSum[i] = mPartIndexSum[i - 1] + mDataArray[i];
                mPartIndexSquareSum[i] = mPartIndexSquareSum[i - 1] + mDataArray[i] * mDataArray[i];
            }
  
        }

        
        public unsafe int QuantizeOnPivot(int start, int quantizecount)
        {
            if (start == mDataArray.Length - 1)
                return 0;
            if (quantizecount == 0)
                return CATEGORIZEOVER;

            
            cache[start,quantizecount] = CATEGORIZEOVER;

            for(int partsize = 1; start+partsize <= mDataArray.Length -1; partsize++)
            {
                cache[start, quantizecount] = Math.Min(cache[start, quantizecount],
                    BlockAverage(start, start + partsize - 1) + QuantizeOnPivot(start + partsize, quantizecount - 1));
            }

            return cache[start, quantizecount];
            
            
        }

        public int BlockAverage(int from, int to)
        { 
            
            int sum = mPartIndexSum[to] - (from == 0 ? 0 : mPartIndexSum[from - 1]);
            int squareSum = mPartIndexSquareSum[to] - (from == 0 ? 0 : mPartIndexSquareSum[from - 1]);

            int averageRounding = (int)((0.5 + (double)sum) / (to - from + 1));

            int squareError = squareSum - 2 * averageRounding * sum + averageRounding * averageRounding * (to - from + 1);

            return squareError;
            
        }
       
        public void CachePrint()
        {
            for(int i=0; i< mNumOfQuantize; i++)
            {
                for(int j=0; j< mDataArray.Length; j++)
                {
                    System.Console.Write(cache[j, i] + " ");
                }
                System.Console.WriteLine("");
            }
            
        }
    }
}
