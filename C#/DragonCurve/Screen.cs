using System;
using System.Collections;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;

namespace DragonCurve
{
    public partial class Screen : Form
    {
        private CreateCurve mCurve;

        private Pen mPen = new Pen(Color.Black);
        private float mLineLength = 10;
        private int mDirection = 180;
        private PointF mTempPoint = new Point();
        private Graphics g;
        private List<int> mOrderQueue = new List<int>();
        private string mViewName;
        private int mViewGene;
        private Button mGeneButton = new Button();
        
        public PointF mCurPoint;
        private PointF mStartPoint;
        
        public Screen(int startposX, int startPosY)
        {


            InitializeComponent();
            Invalidate();

            mCurve = new CreateCurve("DragonCurve");
            mViewGene = mCurve.mGeneration;
            mViewName = mCurve.mName;


            mCurPoint = new Point(startposX, startPosY);
            mTempPoint = mCurPoint;
            mStartPoint = mCurPoint;
            g = this.CreateGraphics();

            mGeneButton.Name = "GeneButton";
            mGeneButton.Parent = this;
            mGeneButton.Size = new Size(100, 50);
            mGeneButton.Text = "Evolution";
            mGeneButton.Location = new Point(600, 0);
            mGeneButton.Click += new EventHandler(But_Clicked);

        }

        private void But_Clicked(object sender, EventArgs e)
        {
            EvolutionCurve();
            Invalidate();
        }

        public void EvolutionCurve()
        {
            System.Console.WriteLine(mCurve.DragonString());
            mCurve.EvolutionString();
            mDirection = 180;
            mCurPoint = mStartPoint;
            mTempPoint = mStartPoint;
            mLineLength *= 0.9f;
            ViewGene(mCurve.mGeneration);
            DrawDragon();
        }

        public bool DrawDragon()
        {

            for (int i = 0; i < mCurve.DragonString().Length; i++)
            {
                string compareString = mCurve.DragonString()[i].ToString();

                if (compareString == "X" || compareString == "Y")
                {
                    continue;
                }
                else if (compareString == "F")
                {
                    AddDrewOrder(1);
                }
                else if (compareString == "+")
                {
                    AddDrewOrder(2);
                }
                else if (compareString == "-")
                {
                    AddDrewOrder(3);
                }
            }


            return true;
        }

        public void ViewName(string name)
        {
            mViewName = name;
        }
        public void ViewGene(int gene)
        {
            mViewGene = gene;
        }

        public void Run()
        {
            Application.Run(this);
        }

        private void DrawOrder(int order)
        {
            
            switch (order)
            {
                case 1:
                    if (mDirection == 90)
                        mTempPoint.X += mLineLength;
                    else if (mDirection == 180)
                        mTempPoint.Y -= mLineLength;
                    else if (mDirection == 270)
                        mTempPoint.X -= mLineLength;
                    else if (mDirection == 0)
                        mTempPoint.Y += mLineLength;
                    else
                    {
                        System.Console.WriteLine("wrong direction");
                        Application.Exit();
                    }
                    
                    g.DrawLine(mPen, mCurPoint, mTempPoint);

                    mCurPoint = mTempPoint;

                    break;
                case 2:
                    if (mDirection == 270)
                        mDirection = 0;
                    else
                        mDirection += 90;
                    break;
                case 3:
                    if (mDirection == 0)
                        mDirection = 270;
                    else
                        mDirection -= 90;
                    break;
                case 4:
                    break;
                default:
                    break;
            }
        }

        public void AddDrewOrder(int order)
        {
            mOrderQueue.Add(order);
        }

        protected override void OnPaint(PaintEventArgs e)
        {
            base.OnPaint(e);

            g.DrawString(mViewName, new Font("Arial", 16), new SolidBrush(Color.Red), new Point(0, 0));
            g.DrawString("Generation : " + mViewGene, new Font("Arial", 16), new SolidBrush(Color.Red), new Point(400, 0));
            
            if(mOrderQueue.Count != 0)
            {
                foreach(int one in mOrderQueue)
                {
                    DrawOrder(one);
                }
                mOrderQueue.Clear();
            }
            
           
        }

        
    }

}
