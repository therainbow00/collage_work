using Numbers;
using System;
using System.Collections.Generic;
using static System.Console;

namespace Numbers
{
    internal class NumberStuff
    {
        internal static void Main(string[] args)
        {
            Random rand = new();
            Nums nums = new();
            NumFunctions numFunctions = new();
            Write("Number of loops: ");
            string? input = ReadLine();
            int num = 0;
            if (input == "")
            {
                input = "1";
                num = int.Parse(input);
            }
            else num = int.Parse(input);

            for (int i = 1; i <= num; i++)
            {
                SetNumbersInt(rand, numFunctions);
                SetNumbersDecimal(rand, numFunctions);
                PrintStuff(numFunctions, rand, i);
            }
            ReadLine();
        }

        static void SetNumbersInt(Random rand, NumFunctions numFunctions)
        {
            int length;
            length = rand.Next(100);
            numFunctions.SetNum1Or3(length);
            length = rand.Next(100);
            numFunctions.SetNum2Or4(length);
        }

        static void SetNumbersDecimal(Random rand, NumFunctions numFunctions)
        {
            double length;
            string setNumber;
            double newNumber;
            length = rand.Next(100);
            setNumber = $".{rand.Next(100)}";
            newNumber = Convert.ToDouble(setNumber) + length;
            numFunctions.SetNum1Or3(length + newNumber);
            length = rand.Next(100);
            setNumber = $".{rand.Next(100)}";
            newNumber = Convert.ToDouble(setNumber) + length;
            numFunctions.SetNum2Or4(length + newNumber);
        }

        static void PrintStuff(NumFunctions numFunctions, Random rand, int index)
        {
            Total total;
            for (int l = 1; l <= 33; l++) Write("=");
            Write($" {index} ");

            if (index > 9) for (int l = 1; l <= 33; l++) Write("=");
            else for (int l = 1; l <= 34; l++) Write("=");

            WriteLine();

            WriteLine($"The greater number is: {numFunctions.Greater(numFunctions.Num1, numFunctions.Num2)}, the two number were [{numFunctions.Num1} and {numFunctions.Num2}]");

            total = new(numFunctions.Num1, numFunctions.Num2);
            WriteLine(numFunctions.Num1 + " + " + numFunctions.Num2 + " = " + total.TotalNumberInt);


            WriteLine($"The greater number is: {numFunctions.Greater(numFunctions.Num3, numFunctions.Num4).ToString("0.00")} the two number were [{numFunctions.Num3.ToString("0.00")} and {numFunctions.Num4.ToString("0.00")}]");

            total = new(numFunctions.Num3, numFunctions.Num4);
            WriteLine(numFunctions.Num3.ToString("0.00") + " + " + numFunctions.Num4.ToString("0.00") + " = " + total.TotalNumberDouble.ToString("0.00"));

            for (int l = 1; l <= 70; l++) Write("=");

            WriteLine();
        }
    }

    internal class Nums
    {
        protected int num1;
        protected int num2;

        protected double num3;
        protected double num4;
    }

    internal class Total : Nums
    {
        private int totalNumberInt;
        private double totalNumberDouble;

        public Total(int num1, int num2) { TotalNumberInt = AddNums(num1, num2); }
        public Total(double num1, double num2) { TotalNumberDouble = AddNums(num1, num2); }

        public int TotalNumberInt
        {
            get { return totalNumberInt; }
            set { totalNumberInt = value; }
        }
        public double TotalNumberDouble
        {
            get { return totalNumberDouble; }
            set { totalNumberDouble = value; }
        }

        private int AddNums(int num1, int num2) { return num1 + num2; }
        private double AddNums(double num1, double num2) { return num1 + num2; }
    }

    internal class NumFunctions : Nums
    {
        public int Num1
        {
            get { return num1; }
            set { num1 = value; }
        }
        public int Num2
        {
            get { return num2; }
            set { num2 = value; }
        }
        public double Num3
        {
            get { return num3; }
            set { num3 = value; }
        }
        public double Num4
        {
            get { return num4; }
            set { num4 = value; }
        }

        public void SetNum1Or3(int num) { Num1 = num; }
        public void SetNum1Or3(double num) { Num3 = num; }

        public void SetNum2Or4(int num) { Num2 = num; }
        public void SetNum2Or4(double num) { Num4 = num; }

        public int Greater(int num1, int num2) { if (num1 < num2) return num2; return num1; }
        public double Greater(double num1, double num2) { if (num1 < num2) return num2; return num1; }
    }
}