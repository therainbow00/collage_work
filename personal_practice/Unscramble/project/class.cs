using System;
using System.Collections.Generic;
using System.Dynamic;
using System.Reflection.Metadata.Ecma335;
using System.Runtime.InteropServices;
using static System.Console;

namespace program
{
    class Changes
    {
        public int add(int num1, int num2)
        {
            return num1 + num2;
        }

        public string changeName(string oldName, string newName)
        {
            return newName;
        }

        protected int delete(int num1, int num2)
        {
            return num1 - num2;
        }

    }

    class House : Changes
    {
        private protected string familyName;
        private int familyMembers;

        protected string FamilyName
        {
            get { return familyName; }
            set { familyName = value; }
        }
        protected int FamilyMembers
        {
            get { return familyMembers; }
            set { familyMembers = value; }
        }
        public House(string familyname, int familymembers)
        {
            familyMembers = familymembers;
            familyName = familyname;
        }

        public void addMember(int Number)
        {
            int temp = 0;
            temp = add(Number, FamilyMembers);
            FamilyMembers = temp;
        }

        public void deleteMember(int Number) 
        {
            int temp = 0;
            temp = delete(FamilyMembers, Number);
            FamilyMembers = temp;
        }

        public void changeFamilyName(string oldName, string newName)
        {
            FamilyName = changeName(oldName, newName);
        }


        public void print()
        {
            WriteLine("family name: " + FamilyName + ", " + " family member count: " + FamilyMembers);
        }
    }
}