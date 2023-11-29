from flask import Flask, render_template, request

app = Flask(__name__, template_folder="index")


@app.route("/")
def index():
    return render_template("index.html")


@app.route("/calculate", methods=["POST"])
def calculate():
    if request.method == "POST":
        try:
            num1 = float(request.form["num1"])
            num2 = float(request.form["num2"])
            operation = request.form["operation"]

            if operation == "add":
                result = num1 + num2
            elif operation == "subtract":
                result = num1 - num2
            elif operation == "multiply":
                result = num1 * num2
            elif operation == "divide":
                if num2 != 0:
                    result = num1 / num2
                else:
                    return "Cannot divide by zero!"

            return render_template("index.html", result=result)

        except ValueError:
            return "Invalid input! Please enter valid numbers."


if __name__ == "__main__":
    app.run(debug=True)