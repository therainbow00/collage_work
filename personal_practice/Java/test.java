package personal_practice.Java;

import java.util.Random;

public class test {
    public static void main(String[] args) {
        Random rand = new Random();
        TestSomething test = new TestSomething();
        Total total = new Total(rand.nextInt(100));

        SetNumbers(rand, test);
        System.out.printf("The greater number is: %d (Number 1 was: %d | Number 2 was: %d)\n",
                test.Greater(test.GetNum1(), test.GetNum2()), test.GetNum1(), test.GetNum2());
        System.out.println("Total: " + total.GetNum());
    }

    static void SetNumbers(Random rand, TestSomething test) {
        int length = 0;
        length = rand.nextInt(100);
        test.SetNum1(length);
        length = rand.nextInt(100);
        test.SetNum2(length);
    }

}

class TestSomething {
    private int num1;
    private int num2;

    protected int GetNum1() {
        return num1;
    }

    protected int SetNum1(int num) {
        return num1 = num;
    }

    protected int GetNum2() {
        return num2;
    }

    protected int SetNum2(int num) {
        return num2 = num;
    }

    public int PrintNums(int length) {
        int temp = 0;
        for (int i = 0; i < length; i++) {
            temp += i;
        }
        return temp;
    }

    public int Greater(int num1, int num2) {
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

    protected int SetNum(int num) {
        return total = num;
    }

    public Total(int num) {
        SetNum(PrintNums(num));
    }

    public int GetTotal() {
        return GetNum();
    }
}