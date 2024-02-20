using System;
using System.Collections.Generic;
using System.Diagnostics.Metrics;
using System.Linq;
using System.Text;
using System.Text.RegularExpressions;
using System.Threading.Tasks;
using static System.Console;

namespace Unscramble.Models
{
    public class GameModel
    {
        public string Guess { get; set; } = string.Empty;
        public int guessLength { get; set; }
        public List<char> usersWord { get; set; } = new List<char>();
        public string wordScrambled { get; set; } = string.Empty;
        public Game game = new Game();
        public string Word { get; set; } = string.Empty;
        public string result { get; set; } = string.Empty;
        public int resultInt { get; set; }
        public int count { get; set; }
        public decimal correct { get; set; }
        public string errorMessage { get; set; } = string.Empty;
    }

    public class Game
    {
        public string GameStart()
        {
            Random rand = new Random();
            string[] animals_name = new string[] { "lion", "Elephant", "tiger", "Giraffe", "kangaroo", "zebra", "cheetah", "Dolphin", "koala", "rhinoceros", "Penguin", "jaguar", "gazelle", "hippopotamus", "leopard", "squirrel", "crocodile", "Eagle", "armadillo", "platypus", "buffalo", "antelope", "Albatross", "gorilla", "otter", "chameleon", "hedgehog", "Mongoose", "parrot", "Panda", "vulture", "seagull", "mongoose", "whale", "koala", "Pangolin", "dolphin", "octopus", "llama", "quokka", "iguana", "cockatoo", "orca", "lemur", "macaw", "sloth", "okapi", "quokka", "yak", "Puffin", "firefly", "giraffe", "robin", "iguana", "meerkat", "humpback", "ostrich", "lynx", "ocelot", "marmoset", "jellyfish", "warthog", "yak", "numbat", "panther", "rabbit", "vulture", "penguin", "Armadillo", "hedgehog", "chameleon", "flamingo", "pelican", "zebu", "llama", "lynx", "narwhal", "rooster", "hamster", "eagle", "toucan", "starling", "woodpecker", "weasel", "quail", "dromedary", "ostrich", "tarsier", "marmoset", "jaguar", "pangolin", "impala", "elephant", "parrot", "dolphin", "antelope", "rhinoceros", "vulture", "yak" };
            int animalIndex = rand.Next(animals_name.Length);
            string answer = animals_name[animalIndex];
            string word = answer;
            return word;
        }

        public string shuffleWord(string word)
        {
            Random rand = new Random();
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

        public void checkingTheLetter(string word, char character, List<char> list, ref int correct)
        {
            list.Add(character);
            for (int i = 0; i < word.Length; i++) if (character == word[i]) correct++;
        }

        public bool alreadyGuessed(List<char> list, string input, ref bool found)
        {
            foreach (char c in list) if (input[0] == c) found = true;
            return found;
        }
    }
}
