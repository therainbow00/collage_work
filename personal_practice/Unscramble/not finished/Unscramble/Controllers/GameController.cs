using Microsoft.AspNetCore.Http;
using Microsoft.AspNetCore.Mvc;
using Microsoft.AspNetCore.Mvc.Formatters;
using Microsoft.EntityFrameworkCore.Metadata.Internal;
using System.Diagnostics.Metrics;
using System.Drawing.Text;
using Unscramble.Models;

namespace Unscramble.Controllers
{
    public class GameController : Controller
    {
        private static GameModel model = new();
        private static List<char> list = new List<char>();
        private static int correct = 0;

        // GET: gameController
        [Route("/Game/Index")]
        public ActionResult Index()
        {
            //GameModel model = new();
            //model.usersWord = new List<char>(3);
            //list = new List<char>();

            return View(model);
        }
        [HttpPost]
        [Route("/Game/Add")]
        public ActionResult Add(string guess)
        {
            if (string.IsNullOrWhiteSpace(guess))
            {
                return RedirectToAction("error", new { message = "Must guess a character" });
            }
            model.Guess = guess;
            model.guessLength = guess.Length;

            if (model.Guess.Any(char.IsDigit))
            {
                return RedirectToAction("error", new { message = "Guess must be a letter" });
            }

            if (model.Guess == "quit")
            {
                //_model.usersWord.Add(_model.Guess[0]);
                return Redirect("~/Home/Index");
            }
            else if (model.guessLength < 2)
            {
                if (model.count != model.Word.Length) model.count++;

                model.game.checkingTheLetter(model.Word, model.Guess[0], model.usersWord, ref correct);
                model.correct = correct;

                list.Add(model.Guess[0]);
            }
            else
            {
                if (model.guessLength > 1)
                {
                    return RedirectToAction("Error", new { message = "Guess only one character" });
                }
                list = new List<char>();
                model.usersWord = new List<char>();
                model.Word = model.game.GameStart();
                model.wordScrambled = model.game.shuffleWord(model.Word);
            }
            model.result = ((model.correct / Convert.ToDecimal(model.Word.Length)) * 100).ToString("0");
            model.resultInt = (int)((model.correct / Convert.ToDecimal(model.Word.Length)) * 100);
            if (model.count == model.Word.Length) return RedirectToAction("done");
            /*if (_model == null)
            {
                _model = new GameModel();
                _model.usersWord = new List<char>();
            }*/

            return RedirectToAction("index");
        }

        [Route("/Game/Rules")]
        // GET: gameController/Details/5
        public ActionResult Rules()
        {
            return View();
        }

        // GET: gameController/Create
        [Route("/Game/Create")]
        public ActionResult Create()
        {
            model.Word = model.game.GameStart();
            model.wordScrambled = model.game.shuffleWord(model.Word);
            model.usersWord = new List<char>();
            model.result = string.Empty;
            model.resultInt = 0;
            model.guessLength = 0;
            model.count = 0;
            model.correct = 0;
            model.errorMessage = string.Empty;
            correct = 0;
            return RedirectToAction("Index");
        }

        // POST: gameController/Create
        [Route("/Game/Error")]
        public ActionResult Error(string message)
        {
            model.errorMessage = message;
            return View(model);
        }

        // GET: gameController/Edit/5
        [Route("/Game/Done")]
        public ActionResult Done()
        {
            return View(model);
        }

        // POST: gameController/Edit/5
        [HttpPost]
        [ValidateAntiForgeryToken]
        public ActionResult Edit(int id, IFormCollection collection)
        {
            try
            {
                return RedirectToAction(nameof(Index));
            }
            catch
            {
                return View();
            }
        }

        // GET: gameController/Delete/5
        public ActionResult Delete(int id)
        {
            return View();
        }

        // POST: gameController/Delete/5
        [HttpPost]
        [ValidateAntiForgeryToken]
        public ActionResult Delete(int id, IFormCollection collection)
        {
            try
            {
                return RedirectToAction(nameof(Index));
            }
            catch
            {
                return View();
            }
        }
    }
}
