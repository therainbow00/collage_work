using System;
using static System.Console;

class hello_there
{
    public class program
    {
        static void Main(string[] args, int argv)
        {
            /*Write("Enter name: ");
            string name = ReadLine();*/
            WriteLine("hello there, " + args[1] + '!');
            WriteLine("hello there, {0}!", args[1]);
            WriteLine($"hello there, {args[1]}!");

            var rand = new Random();
            int[] array = new int[10];
            for (int i = 0; i < array.Length; i++)
            {
                WriteLine(rand.Next(1, 100));
            }

            Person person = new Person();

            person.Name = ReadLine("Enter name: ");
            person.Age = ReadLine("Enter age: ");

            WriteLine("Name = " + person.Name + ", Age = " + person.Age);
        }

        public class Person
        {
            string name;
            int age;
        }
    }
}