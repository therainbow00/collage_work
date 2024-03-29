from cgitb import reset
import string
from flask import Flask, render_template, request

app = Flask(__name__, template_folder="index")


@app.route("/")
def index():
    return render_template("index.html")


@app.route("/game", methods=["POST", "GET"])
def check():
    if request.method == "POST":
        try:
            guess = request.form["guess"]

            result = guess
            return render_template("index.html", result=result)

        except ValueError:
            return "Invalid input! Please enter a valid character."
    if request.method == "GET":
        return render_template("index.html")


if __name__ == "__main__":
    app.run("localhost", 2580, debug=True)