using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;

namespace DragonCurve
{
    class Program
    {
        
        static void Main(string[] args)
        {
            Screen manager = new Screen(400, 300);

            
            if (manager.DrawDragon())
                manager.Run();
        }
    }
}
