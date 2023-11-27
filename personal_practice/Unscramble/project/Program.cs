using static System.Console;
using System;
using System.Globalization;
using System.Runtime.InteropServices;
using project;
using System.Xml.Serialization;
using Microsoft.Data.SqlClient;
using static System.Runtime.InteropServices.JavaScript.JSType;

namespace program
{
    class Data
    {
        static void Main(string[] args)
        {
            /*House house = new("some", 5);
            Random rand = new Random();*/

            /*house.print();
            house.addMember(rand.Next(1, 5));
            house.print();
            house.changeFamilyName("some", "good");
            house.print();
            house.deleteMember(rand.Next(1, 3));
            house.print();*/
            Game.Main(args);
            //Add add = new(1, "some", 5);

            //add.Print();
            //house.print();
            // This is the file with the main function: Program.cs using System;
        }
    }
}