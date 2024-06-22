#include <iostream>
using namespace std;

const int SIZE = 3;
string board[SIZE][SIZE] = {{" ", " ", " "}, {" ", " ", " "}, {" ", " ", " "}};
string currentSymbol = "X";
int winsX = 0;
int winsO = 0;

void drawOneRow(int rowNumber) {
    cout << " " << board[rowNumber][0] << " | " << board[rowNumber][1] << " | " << board[rowNumber][2] << " " << endl;
}

void drawBoard() {
    drawOneRow(0);
    cout << "---|---|---" << endl;
    drawOneRow(1);
    cout << "---|---|---" << endl;
    drawOneRow(2);
}

bool isPositionValid(int x, int y) {
    return x >= 0 && x < SIZE && y >= 0 && y < SIZE && board[x][y] == " ";
}

string checkWinner() {
    // Check rows
    for (int i = 0; i < SIZE; i++) {
        if (board[i][0] == board[i][1] && board[i][1] == board[i][2] && board[i][0] != " ")
            return board[i][0];
    }
    // Check columns
    for (int j = 0; j < SIZE; j++) {
        if (board[0][j] == board[1][j] && board[1][j] == board[2][j] && board[0][j] != " ")
            return board[0][j];
    }
    // Check diagonals
    if (board[0][0] == board[1][1] && board[1][1] == board[2][2] && board[0][0] != " ")
        return board[0][0];
    if (board[0][2] == board[1][1] && board[1][1] == board[2][0] && board[0][2] != " ")
        return board[0][2];
    return "";
}

void endGame(string winner) {
    cout << "Winner is " << winner << "!" << endl;
    if (winner == "X") winsX++;
    if (winner == "O") winsO++;
    cout << "Score X: " << winsX << " - O: " << winsO << endl;
    // Reset the board
    for (int i = 0; i < SIZE; i++)
        for (int j = 0; j < SIZE; j++)
            board[i][j] = " ";
}

int main() {
    while (true) {
        drawBoard();
        int x, y;
        cout << "Enter row and column (0, 1, or 2) for " << currentSymbol << ": ";
        cin >> x >> y;
        if (isPositionValid(x, y)) {
            board[x][y] = currentSymbol;
            string winner = checkWinner();
            if (winner != "") {
                drawBoard();
                endGame(winner);
            }
            currentSymbol = (currentSymbol == "X") ? "O" : "X";
        } else {
            cout << "Invalid move. Try again." << endl;
        }
    }
    return 0;
}
