using System;
using System.Collections.Generic;
using System.Linq;
using System.Runtime.InteropServices;
using System.Text;
using System.Threading.Tasks;
using static System.Console;

namespace project
{
    class Cup : IEquatable<Cup>
    {
        int cupID;
        public Cup(int id)
        {
            cupID = id;
        }

        public bool Equals(Cup other) 
        {
            if (this.cupID == other.cupID)
            {
                return true;
            }
            return false;
        }
    }
}
