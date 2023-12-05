using System;
using System.Collections.Generic;
using System.Diagnostics.Metrics;
using System.Linq;
using System.Text;
using System.Text.RegularExpressions;
using System.Threading.Tasks;
using static System.Console;
using Microsoft.IdentityModel.Tokens;

namespace program
{
    class Game
    {
        public static void Main(string[] args)
        {
            WriteLine("Welcome to Scramble, ENJOY!");
            WriteLine("An animal word has been scrambled, unscramble it and win game.");
            WriteLine("If you guess the same letter twice, the game ends");
            WriteLine("Each input must only be 1 character");
            WriteLine("You must type a character or the game ends");
            WriteLine("All names are case sensitive.");

            Random rand = new Random();
            string[] animals_name = new string[] { "lion", "Elephant", "tiger", "Giraffe", "kangaroo", "zebra", "cheetah", "Dolphin", "koala", "rhinoceros", "Penguin", "jaguar", "gazelle", "hippopotamus", "leopard", "squirrel", "crocodile", "Eagle", "armadillo", "platypus", "buffalo", "antelope", "Albatross", "gorilla", "otter", "chameleon", "hedgehog", "Mongoose", "parrot", "Panda", "vulture", "seagull", "mongoose", "whale", "koala", "Pangolin", "dolphin", "octopus", "llama", "quokka", "iguana", "cockatoo", "orca", "lemur", "macaw", "sloth", "okapi", "quokka", "yak", "Puffin", "firefly", "giraffe", "robin", "iguana", "meerkat", "humpback", "ostrich", "lynx", "ocelot", "marmoset", "jellyfish", "warthog", "yak", "numbat", "panther", "rabbit", "vulture", "penguin", "Armadillo", "hedgehog", "chameleon", "flamingo", "pelican", "zebu", "llama", "lynx", "narwhal", "rooster", "hamster", "eagle", "toucan", "starling", "woodpecker", "weasel", "quail", "dromedary", "ostrich", "tarsier", "marmoset", "jaguar", "pangolin", "impala", "elephant", "parrot", "dolphin", "antelope", "rhinoceros", "vulture", "yak" };
            int animalIndex = rand.Next(animals_name.Length);
            string answer = animals_name[animalIndex];
            string word = answer;
            string scrambledWord = ShuffleWord(answer, rand);

            foreach (int index in scrambledWord) Write("- ");

            List<char> usersWord = new List<char>();
            decimal correct = 0m;
            int count = 1;

            Write("\nGuess a letter: ");
            string? guess = ReadLine();
            string? letter = guess;
            while (!string.IsNullOrWhiteSpace(letter) && letter != "quit")
            {
                if (letter.Length > 1) CharacterCount(correct, word);

                else if (letter.Any(char.IsDigit))
                {
                    WriteLine(new string('-', 50));
                    WriteLine($" Guess must be a letter. You lost, score {correct}/{word.Length}");
                    WriteLine(new string('-', 50));
                    Environment.Exit(0);
                }
                else if (usersWord.Count > 0) AlreadyGuessed(usersWord, letter);
                char character = letter[0];
                CheckingTheLetter(word, character, usersWord, ref correct);

                if (count == word.Length) break;
                else count++;
                Write("Guess a letter: ");
                guess = ReadLine();
                letter = guess;
            }

            decimal wordLength = word.Length;
            string percent = ((correct / wordLength) * 100).ToString("0") + '%';
            WriteLine("\n==========================");
            WriteLine($" Your score: {correct}/{word.Length} --- {percent}");

            if (usersWord.Count > 0)
            {
                Write(" Guessed letters: ");
                foreach (char charcharter in usersWord) Write(charcharter);
                WriteLine($"\n Word: {word}");
                WriteLine("==========================");
            }
            else if (usersWord.Count == 0)
            {
                WriteLine($" Word: {word}");
                WriteLine("==========================");
            }

            WriteLine("Type anything to exit...");
            ReadLine();
        }

        static string ShuffleWord(string word, Random rand)
        {
            char[] charArray = word.ToCharArray();

            for (int i = charArray.Length - 1; i > 0; i--)
            {
                int j = rand.Next(0, i + 1);
                char temp = charArray[i];
                charArray[i] = charArray[j];
                charArray[j] = temp;
            }

            return new string(charArray);
        }

        static void CheckingTheLetter(string word, char character, List<char> list, ref decimal correct)
        {
            list.Add(character);
            for (int i = 0; i < word.Length; i++) if (character == word[i]) correct++;
        }

        static void CharacterCount(decimal correct, string word)
        {
            WriteLine(new string('-', 50));
            WriteLine($" Guess only one character. You lost, score {correct}/{word.Length}");
            WriteLine(new string('-', 50));
            Environment.Exit(0);
        }

        static void AlreadyGuessed(List<char> list, string input)
        {
            for (int num = 0; num < list.Count; num++)
            {
                if (input[0] == list[num])
                {
                    WriteLine(new string('-', 30));
                    WriteLine(" Letter already guessed");
                    WriteLine(new string('-', 30));
                    Environment.Exit(0);
                }
            }
        }
    }
}
