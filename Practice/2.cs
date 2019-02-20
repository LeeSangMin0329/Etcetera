using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace com2us2
{
    class Program
    {
        static void ShortestPathUseBFS(int[,] map)
        {
            int row = map.GetLength(0);
            int col = map.GetLength(1);
            int[] offsetY = {1, -1, 0, 0 };
            int[] offsetX = {0, 0, 1, -1 };

            Tuple<int, int> startPos = null, endPos = null;

            for(int i=0; i<row; i++)
            {
                for(int j=0; j<col; j++)
                {
                    if(map[i, j] == 2)
                    {
                        startPos = new Tuple<int, int>(i, j);
                    }
                    else if(map[i, j] == 3)
                    {
                        endPos = new Tuple<int, int>(i, j);
                    }
                }
            }

            if(startPos == null || endPos == null)
            {
                return;
            }

            bool[,] visit = new bool[row, col];
            Tuple<int, int>[,] pathRecord = new Tuple<int, int>[row, col];
            
            Queue<Tuple<int, int>> qu = new Queue<Tuple<int, int>>();
            qu.Enqueue(startPos);
            visit[startPos.Item1, startPos.Item2] = true;
            int shortestPathLength = 1;

            // BFS
            while(qu.Count > 0)  // v^4
            {
                int quCount = qu.Count;
                for(int i=0; i<quCount; i++)
                {
                    Tuple<int, int> cur = qu.Dequeue();

                    // Escape maze.
                    if(cur == endPos)
                    {
                        break;
                    }

                    for(int j=0; j<4; j++) // 0 ~ 4
                    {
                        int y = cur.Item1 + offsetY[j];
                        int x = cur.Item2 + offsetX[j];

                        if (BorderAndVisitCheck(map, visit, y, x))
                        {
                            qu.Enqueue(new Tuple<int, int>(y, x));
                            visit[y, x] = true;
                            pathRecord[y, x] = cur;
                        }
                    }
                }
                shortestPathLength++; // depth
            }

            for(var i=pathRecord[endPos.Item1, endPos.Item2]; i != startPos; i = pathRecord[i.Item1, i.Item2])
            {
                map[i.Item1, i.Item2] = 4;
            }
            map[startPos.Item1, startPos.Item2] = 4;
            map[endPos.Item1, endPos.Item2] = 4;
        }

        static bool BorderAndVisitCheck(int[,] map, bool[,] visit, int y, int x)
        {
            if (y >= map.GetLength(0) || y < 0) return false;
            if (x >= map.GetLength(1) || x < 0) return false;
            if (map[y, x] == 1) return false;
            if (visit[y, x]) return false;

            return true;
        }

        static void Main(string[] args)
        {
            int[,] map = new int[19, 19]
            {   
                {1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1},
                {2,0,1,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,1},
                {1,0,1,0,1,1,1,0,1,1,1,1,1,0,1,0,1,0,1},
                {1,0,1,0,1,0,0,0,1,0,0,0,0,0,1,0,1,0,1},
                {1,0,1,0,1,1,1,0,1,1,1,1,1,1,1,0,1,0,1},
                {1,0,1,0,0,0,1,0,0,0,0,0,1,0,0,0,0,0,1},
                {1,0,1,1,1,0,1,0,1,1,1,0,1,0,1,0,1,0,1},
                {1,0,0,0,0,0,1,0,1,0,1,0,1,0,1,0,1,0,1},
                {1,1,1,1,1,0,1,0,1,0,1,0,1,0,1,0,1,0,1},
                {1,0,0,0,0,0,1,0,1,0,1,0,1,0,1,0,1,0,1},
                {1,0,1,1,1,1,1,0,1,0,1,0,1,0,1,0,1,0,1},
                {1,0,0,0,0,0,0,0,1,0,0,0,1,0,1,1,1,0,1},
                {1,0,1,1,1,1,1,0,1,0,1,1,1,0,1,0,1,0,1},
                {1,0,1,0,0,0,0,0,1,0,0,0,1,0,1,0,1,0,1},
                {1,0,1,0,1,1,1,1,1,1,1,1,1,0,1,0,1,0,1},
                {1,0,1,0,1,0,0,0,0,0,0,0,0,0,1,0,0,0,1},
                {1,0,1,0,1,0,1,1,1,1,1,1,1,1,1,1,0,0,1},
                {1,0,1,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,3},
                {1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1}
            };

            ShortestPathUseBFS(map);

            for(int i=0; i<map.GetLength(0); i++)
            {
                for(int j=0; j<map.GetLength(1); j++)
                {
                    if (map[i, j] == 1) Console.Write("#");
                    else if (map[i, j] == 4) Console.Write("*");
                    else Console.Write(" ");
                }
                Console.WriteLine();
            }
        }
    }
}
