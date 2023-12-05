package personal_practice.Java;

import java.util.Random;

public class test {
    public static void main(String[] args) {
        Random rand = new Random();
        TestSomething test = new TestSomething();
        Total total = new Total(rand.nextInt(100));

        SetNumbersInt(rand, test);
        SetNumbersDecimal(rand, test);
        System.out.printf("The greater number is: %d (Number 1 was: %d | Number 2 was: %d)\n",
                test.Greater(test.GetNum1(), test.GetNum2()), test.GetNum1(), test.GetNum2());
        System.out.println("Total: " + total.GetNum());
        System.out.printf("The greater number is: %f (Number 3 was: %f | Number 4 was: %f)\n",
                test.Greater(test.GetNum3(), test.GetNum4()), test.GetNum3(), test.GetNum4());
    }

    static void SetNumbersInt(Random rand, TestSomething test) {
        int length;
        length = rand.nextInt(100);
        test.SetNum1Or3(length);
        length = rand.nextInt(100);
        test.SetNum2Or4(length);
    }

    static void SetNumbersDecimal(Random rand, TestSomething test) {
        double length;
        length = rand.nextInt(100);
        test.SetNum1Or3(length);
        length = rand.nextInt(100);
        test.SetNum2Or4(length);
    }
}

class TestSomething {
    private int num1;
    private int num2;
    private double num3;
    private double num4;

    protected int GetNum1() {
        return num1;
    }

    protected int SetNum1Or3(int num) {
        return num1 = num;
    }

    protected double SetNum1Or3(double num) {
        return num3 = num;
    }

    protected int GetNum2() {
        return num2;
    }

    protected double GetNum3() {
        return num3;
    }

    protected double GetNum4() {
        return num4;
    }

    protected int SetNum2Or4(int num) {
        return num2 = num;
    }

    protected double SetNum2Or4(double num) {
        return num4 = num;
    }

    protected int PrintNums(int length) {
        int temp = 0;
        for (int i = 0; i < length; i++) {
            temp += i;
        }
        return temp;
    }

    protected int Greater(int num1, int num2) {
        if (num1 < num2) {
            return num2;
        }
        return num1;
    }

    protected double Greater(double num1, double num2) {
        if (num1 < num2) {
            return num2;
        }
        return num1;
    }
}

class Total extends TestSomething {
    private int total;

    protected int GetNum() {
        return total;
    }

    protected int SetTotal(int num) {
        return total = num;
    }

    protected Total(int num) {
        SetTotal(PrintNums(num));
    }

    protected int GetTotal() {
        return GetNum();
    }
}