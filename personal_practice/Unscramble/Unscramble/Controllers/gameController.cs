using Microsoft.AspNetCore.Http;
using Microsoft.AspNetCore.Mvc;
using Unscramble.Models;

namespace Unscramble.Controllers
{
    public class GameController : Controller
    {
        //public List<char> user { get; set; }
        // GET: gameController
        [HttpGet]
        public ActionResult Index()
        {
            GameModel model = new();
            model.usersWord = new List<char>();
            return View(model);
        }
        [HttpPost]
        public ActionResult Index(List<char> List)
        {
            GameModel model = new();
            model.AddToList(model.Guess, List);
            //model.usersWord.Add(model.Guess[0]);

            return View(model);
        }

        // GET: gameController/Details/5
        public ActionResult Details(int id)
        {
            return View();
        }

        // GET: gameController/Create
        public ActionResult Create()
        {
            return View();
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
