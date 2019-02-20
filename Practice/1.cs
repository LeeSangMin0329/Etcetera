using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace com2us1
{
    class Program
    {
        static void BlockDown(int[,] map)
        {
            List<int> fullLines = new List<int>();

            bool isCurBlockLines = false;
            
            // Find filled line. N*M(Current Block Height)
            for (int i=map.GetLength(0) - 1; i>=0; i--)
            {
                bool fullFlag = true;
                bool curBlockFlag = false;
                for(int j=0; j<map.GetLength(1); j++)
                {
                    // find full lines
                    if(map[i, j] == 0)
                    {
                        fullFlag = false;
                    }
                    else if(map[i,j] == 2)
                    {
                        isCurBlockLines = true;
                        curBlockFlag = true;
                    }
                }

                // Line number 'i' is full.
                if(fullFlag)
                {
                    fullLines.Add(i);
                }

                // Line check is not required, after current block line.
                if(isCurBlockLines && !curBlockFlag)
                {
                    break;
                }
            }

            if(fullLines.Count <= 0)
            {
                return;
            }

            // Block Down. N * N
            int requiredFill = fullLines[0];
            int index = 1;
            for(int cursor=fullLines[0] - 1; cursor >= 0; cursor--)
            {
                while(fullLines[index] != cursor && cursor >= 0)
                {
                    CopyRow(map, cursor, requiredFill);
                    requiredFill--;
                    cursor--;
                }

                if(index < fullLines.Count - 1)
                {
                    index++;
                }
            }

            // Fill extra space with empty space
            for(int i=requiredFill; i>=0; i--)
            {
                FillBlank(map, i);
            }
        }

        static void FillBlank(int[,] map, int row)
        {
            for(int i=0; i<map.GetLength(1); i++)
            {
                map[row, i] = 0;
            }
        }

        static void CopyRow(int[,] map, int source, int dest)
        {
            for(int i=0; i<map.GetLength(1); i++)
            {
                map[dest, i] = map[source, i];
            }
        }


        static void Main(string[] args)
        {
            int[,] map = new int[7, 6]
            {
                { 0,0,0,0,0,0 },
                { 0,0,0,0,0,0 },
                { 1,1,0,0,0,1 },
                { 1,1,2,2,1,1 },
                { 1,1,1,2,0,1 },
                { 1,1,1,2,1,1 },
                { 1,1,1,0,1,0 },
            };
            
            BlockDown(map);

            for (int i=0; i<map.GetLength(0); i++)
            {
                for(int j=0; j<map.GetLength(1); j++)
                {
                    System.Console.Write(map[i, j] + " ");
                }
                System.Console.WriteLine();
            }
        }
    }
}
