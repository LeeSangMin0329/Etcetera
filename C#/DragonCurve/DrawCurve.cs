using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;

namespace DragonCurve
{
    class DrawCurve
    {
        private CreateCurve mCurve;
        private Screen mScreenInstense;

        public DrawCurve(int startPosX, int startPosY)
        {
            mCurve = new CreateCurve("DragonCurve");
            mScreenInstense = new Screen(startPosX, startPosY);

            mScreenInstense.ViewName(mCurve.mName);
            mScreenInstense.ViewGene(mCurve.mGeneration);
        }

        public void EvolutionCurve()
        {
            mCurve.EvolutionString();
            mScreenInstense.ViewGene(mCurve.mGeneration);
        }

        
        public bool DrawDragon()
        {
            
            for (int i=0; i<mCurve.DragonString().Length; i++)
            {
                string compareString = mCurve.DragonString()[i].ToString();

                if (compareString == "X" || compareString == "Y")
                {
                    continue;
                }
                else if (compareString == "F")
                {
                    mScreenInstense.AddDrewOrder(1);
                }
                else if (compareString == "+")
                {
                    mScreenInstense.AddDrewOrder(2);
                }
                else if (compareString == "-")
                {
                    mScreenInstense.AddDrewOrder(3);
                }
            }

            
            return true;
        }

        public void Run()
        {
            Application.Run(mScreenInstense);
        }
    }
}
