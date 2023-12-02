using Microsoft.AspNetCore.Http;
using Microsoft.AspNetCore.Mvc;
using Unscramble.Models;

namespace Unscramble.Controllers
{
    public class GameController : Controller
    {
        // GET: gameController
        [HttpPost]
        [Route("/Home")]
        public ActionResult Index()
        {
            var model = new string[] { "lion", "Elephant", "tiger", "Giraffe", "kangaroo", "zebra", "cheetah", "Dolphin", "koala", "rhinoceros", "Penguin", "jaguar", "gazelle", "hippopotamus", "leopard", "squirrel", "crocodile", "Eagle", "armadillo", "platypus", "buffalo", "antelope", "Albatross", "gorilla", "otter", "chameleon", "hedgehog", "Mongoose", "parrot", "Panda", "vulture", "seagull", "mongoose", "whale", "koala", "Pangolin", "dolphin", "octopus", "llama", "quokka", "iguana", "cockatoo", "orca", "lemur", "macaw", "sloth", "okapi", "quokka", "yak", "Puffin", "firefly", "giraffe", "robin", "iguana", "meerkat", "humpback", "ostrich", "lynx", "ocelot", "marmoset", "jellyfish", "warthog", "yak", "numbat", "panther", "rabbit", "vulture", "penguin", "Armadillo", "hedgehog", "chameleon", "flamingo", "pelican", "zebu", "llama", "lynx", "narwhal", "rooster", "hamster", "eagle", "toucan", "starling", "woodpecker", "weasel", "quail", "dromedary", "ostrich", "tarsier", "marmoset", "jaguar", "pangolin", "impala", "elephant", "parrot", "dolphin", "antelope", "rhinoceros", "vulture", "yak" };
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
