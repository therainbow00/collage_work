using System;
using System.Collections.Generic;
using System.Data.SqlClient;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using static System.Console;

namespace SQL_stuff
{
    internal class Program
    {
        static void Main(string[] args)
        {
            GetAllUsers(3);
        }

        static void GetAllUsers(int id)
        {
            string connectionString = "Server=localhost\\sqlexpress;Database=data;Trusted_Connection=True;TrustServerCertificate=true;";

            using (SqlConnection connection = new SqlConnection(connectionString))
            {
                connection.Open();
                string query = $"select userfirstname, usermiddlename, userlastname from users where userid = {id}";

                using (SqlCommand command = new SqlCommand(query, connection))
                {
                    using (SqlDataReader dataReader = command.ExecuteReader())
                    {
                        for (int i = 0; i < dataReader.FieldCount; i++)
                        {
                            if (i == (dataReader.FieldCount - 1)) Write($"{dataReader.GetName(i)}");
                            else Write($"{dataReader.GetName(i)}, ");
                        }
                        while (dataReader.Read())
                        {
                            WriteLine();
                            for (int i = 0; i < dataReader.FieldCount; i++)
                            {
                                if (i == (dataReader.FieldCount - 1)) Write($"{dataReader[i]}");
                                else Write($"{dataReader[i]}, ");
                            }
                            WriteLine();
                        }

                        ReadKey();
                    }
                }
                connection.Close();
            }
        }
    }
}
