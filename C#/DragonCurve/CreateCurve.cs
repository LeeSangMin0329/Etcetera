using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace DragonCurve
{
    class CreateCurve
    {
        private string mDragon = "FX";
        public int mGeneration = 0;
        public string mName;

        public CreateCurve(string name)
        {
            mName = name;
        }

        public void EvolutionString()
        {
            mDragon = mDragon.Replace("Y", "*");
            mDragon = mDragon.Replace("X", "X+YF");
            mDragon = mDragon.Replace("*", "FX-Y");
            mGeneration++;
        }

        public string DragonString()
        {
            return mDragon;
        }
    }
}
