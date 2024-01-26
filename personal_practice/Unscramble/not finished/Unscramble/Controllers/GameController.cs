using Microsoft.AspNetCore.Http;
using Microsoft.AspNetCore.Mvc;
using Microsoft.AspNetCore.Mvc.Formatters;
using Microsoft.EntityFrameworkCore.Metadata.Internal;
using Unscramble.Models;

namespace Unscramble.Controllers
{
    public class GameController : Controller
    {
        private static GameModel model = new();
        private static List<char> list = new List<char>();

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
            if (model.usersWord.Count < 1 && guess == null)
            {
                model.Word = model.game.GameStart();
                model.wordScrambled = model.game.shuffleWord(model.Word);
            }
            model.Guess = guess;
            model.guessLength = guess.Length;
            if (guess == "quit")
            {
                //_model.usersWord.Add(_model.Guess[0]);
                return Redirect("~/Home/Index");
            }
            else if (guess.Length < 2)
            {
                list.Add(model.Guess[0]);
                model.usersWord.Add(model.Guess[0]);
            }
            else
            {
                list = new List<char>();
                model.usersWord = new List<char>();
                model.Word = model.game.GameStart();
                model.wordScrambled = model.game.shuffleWord(model.Word);
            }
            /*if (_model == null)
            {
                _model = new GameModel();
                _model.usersWord = new List<char>();
            }*/

            return RedirectToAction("Index");
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
            return RedirectToAction("Index");
        }

        // POST: gameController/Create
        [HttpPost]
        [ValidateAntiForgeryToken]
        public ActionResult Create(IFormCollection collection)
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

        // GET: gameController/Edit/5
        public ActionResult Edit(int id)
        {
            return View();
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
