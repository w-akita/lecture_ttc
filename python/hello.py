from flask import Flask, jsonify

# --- クラス定義
class Asan:
    def __init__(self, x, y):
        self.x = x
        self.y = y

    def moveRight(self):
        self.x += 1.0

class Bsan:
    def __init__(self, x, y):
        self.x = x
        self.y = y

    def moveRight(self):
        self.x += 1.5

a_san = Asan(50, 100)
b_san = Bsan(0, 100)
# ---

app = Flask(__name__)


@app.route('/')
def hello_world():
    return jsonify({'a_san': (a_san.x, a_san.y), 'b_san': (b_san.x, b_san.y)})

@app.route('/moved')
def moved():
    a_san.moveRight()
    b_san.moveRight()
    return jsonify({'a_san': (a_san.x, a_san.y), 'b_san': (b_san.x, b_san.y)})

@app.route('/test')
def test():
    return "Game over!! Have a nice day!"


if __name__ == '__main__':
    app.run(debug=True)