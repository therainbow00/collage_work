using Numbers;
using System;
using System.Collections.Generic;
using static System.Console;

namespace Numbers
{
    public class NumberStuff
    {
        public static void main(string[] args)
        {
            Random rand = new Random();
            Nums nums = new Nums();
            NumFunctions numFunctions = new NumFunctions();
            int num = int.Parse(args[0]);
            Total total;

            for (int i = 1; i <= num; i++)
            {
                total = new(rand.Next(101));
                SetNumbersInt(rand, numFunctions);
                SetNumbersDecimal(rand, numFunctions);
                PrintStuff(numFunctions, total, rand, i);
            }
            WriteLine(nums.Print());
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
            length = rand.Next(100);
            numFunctions.SetNum1Or3(length);
            length = rand.Next(100);
            numFunctions.SetNum2Or4(length);
        }

        static void PrintStuff(NumFunctions numFunctions, Total total, Random rand, int index)
        {
            for (int l = 1; l <= 33; l++) { System.out.print("="); }
            System.out.printf(" %d ", index);

            if (index > 9) for (int l = 1; l <= 33; l++) { System.out.print("="); }
            else for (int l = 1; l <= 34; l++) { System.out.print("="); }

            System.out.println();

            System.out.printf("The greater number is: %d (Number 1 was: %d | Number 2 was: %d)\n", numFunctions.Greater(numFunctions.GetNum1(), numFunctions.GetNum2()), numFunctions.GetNum1(), numFunctions.GetNum2());

            System.out.println("Total: " + total.GetTotal());
            System.out.printf("The greater number is: %.0f (Number 3 was: %.0f | Number 4 was: %.0f)\n", numFunctions.Greater(numFunctions.GetNum3(), numFunctions.GetNum4()), numFunctions.GetNum3(), numFunctions.GetNum4());

            total = new Total(rand.nextInt(101));
            System.out.println("Total: " + total.GetTotal());

            for (int l = 1; l <= 70; l++) { System.out.print("="); }

            System.out.println();
        }
    }

    public class Nums : Done
    {
        protected int num1;
        protected int num2;

        protected double num3;
        protected double num4;

        public override string Print() { return "Done"; }
    }

    public class Total : Nums
    {
        private int totalNumber;

        public Total(int num) { SetTotal(PrintNums(num)); }

        protected int TotalNumber { get; set; }

        protected void SetTotal(int num) { TotalNumber = num; }
        protected int PrintNums(int length)
        {
            int temp = 0;
            for (int i = 0; i < length; i++) temp += i;
            return temp;
        }
    }

    public class NumFunctions : Nums
    {
        protected int Num1 { get; set; }
        protected int Num2 { get; set; }
        protected double Num3 { get; set; }
        protected double Num4 { get; set; }

        public void SetNum1Or3(int num) { Num1 = num; }
        public void SetNum1Or3(double num) { Num3 = num; }

        public void SetNum2Or4(int num) { Num2 = num; }
        public void SetNum2Or4(double num) { Num4 = num; }

        protected int Greater(int num1, int num2) { if (num1 < num2) return num2; return num1; }
        protected double Greater(double num1, double num2) { if (num1 < num2) return num2; return num1; }
    }


    abstract class Done { protected abstract string Print(); }
}