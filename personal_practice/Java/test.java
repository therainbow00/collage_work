package personal_practice.Java;

import java.util.Random;

public class test 
{
    public static void main(String[] args) 
    {
        Random rand = new Random();
        Nums nums = new Nums();
        NumFunctions numFunctions = new NumFunctions();
        int num = Integer.parseInt(args[0]);
        Total total;

        for (int i = 0; i < num; i++) 
        {
            total = new Total(rand.nextInt(101));
            SetNumbersInt(rand, numFunctions);
            SetNumbersDecimal(rand, numFunctions);
            System.out.printf("The greater number is: %d (Number 1 was: %d | Number 2 was: %d)\n", nums.Greater(numFunctions.GetNum1(), numFunctions.GetNum2()), numFunctions.GetNum1(), numFunctions.GetNum2());
            System.out.println("Total: " + total.GetTotal());
            System.out.printf("The greater number is: %.0f (Number 3 was: %.0f | Number 4 was: %.0f)\n", nums.Greater(numFunctions.GetNum3(), numFunctions.GetNum4()), numFunctions.GetNum3(), numFunctions.GetNum4());
            total = new Total(rand.nextInt(101));
            System.out.println("Total: " + total.GetTotal());
            for (int l = 1; l <= 70; l++) {System.out.print("=");}
            System.out.println();
        }
        System.out.println(nums.Print());
    }

    static void SetNumbersInt(Random rand, NumFunctions numFunctions) 
    {
        int length;
        length = rand.nextInt(100);
        numFunctions.SetNum1Or3(length);
        length = rand.nextInt(100);
        numFunctions.SetNum2Or4(length);
    }

    static void SetNumbersDecimal(Random rand, NumFunctions numFunctions) 
    {
        double length;
        length = rand.nextInt(100);
        numFunctions.SetNum1Or3(length);
        length = rand.nextInt(100);
        numFunctions.SetNum2Or4(length);
    }
}

class Nums extends Done {
    protected int num1;
    protected int num2;

    protected double num3;
    protected double num4;

    protected int PrintNums(int length) 
    {
        int temp = 0;
        for (int i = 0; i < length; i++) {temp += i;}
        return temp;
    }

    protected int Greater(int num1, int num2) {if (num1 < num2) {return num2;} return num1;}

    protected double Greater(double num1, double num2) {if (num1 < num2) {return num2;} return num1;}

    String Print() {return "Done";}
}

class Total extends Nums 
{
    private int total;

    protected int GetTotal() {return total;}

    protected void SetTotal(int num) {total = num;}

    protected Total(int num) {SetTotal(PrintNums(num));}
}

class NumFunctions extends Nums 
{
    protected int GetNum1() {return num1;}

    protected void SetNum1Or3(int num) {num1 = num;}

    protected void SetNum1Or3(double num) {num3 = num;}

    protected int GetNum2() {return num2;}

    protected double GetNum3() {return num3;}

    protected double GetNum4() {return num4;}

    protected void SetNum2Or4(int num) {num2 = num;}

    protected void SetNum2Or4(double num) {num4 = num;}
}

abstract class Done {abstract String Print();}