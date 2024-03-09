using System;
using System.Collections;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Data.SqlClient;
using System.Linq;
using System.Text;
using System.Threading;
using System.Threading.Tasks;
using static System.Console;

namespace SQL_stuff
{
    internal class Program
    {
        static void Main(string[] args)
        {
            GetAllTables();
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

        static void GetAllTables()
        {
            string connectionString = "Server=localhost\\sqlexpress;Database=data;Trusted_Connection=True;TrustServerCertificate=true;";

            List<string> tables = new List<string>();
            List<string> data = new List<string>();

            using (SqlConnection connection = new SqlConnection(connectionString))
            {
                connection.Open();
                using (SqlCommand command = new SqlCommand("select table_name from information_schema.tables", connection)) using (SqlDataReader reader = command.ExecuteReader()) while (reader.Read()) tables.Add(reader["table_name"].ToString());

                foreach (var item in tables) using (SqlCommand command1 = new SqlCommand($"select count(*) as count from {item}", connection)) using (SqlDataReader reader1 = command1.ExecuteReader()) while (reader1.Read()) data.Add(reader1["count"].ToString());

                for (int i = 0; i < data.Count; i++) WriteLine(tables[i] + ": " + data[i]);
                ReadKey();
                connection.Close();
            }
        }
    }
}
