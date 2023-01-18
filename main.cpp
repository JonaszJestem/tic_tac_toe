#include <iostream>
#include<vector>
#include "WinnerCheckerLibrary.h"

using namespace std;

enum Player {
    Player_X = 'X', Player_O = 'O'
};

class GameBoard {
public:
    // Declare all the fields
    vector<string> fields{
            "₁", "₂", "₃",
            "₄", "₅", "₆",
            "₇", "₈", "₉",
    };

    bool placePlayer(int field, Player player) {
        // If place is already taken by some player return failure
        if (fields[field] == string(1, (char) Player_O) || fields[field] == string(1, (char) Player_X)) {
            return false;
        }

        fields[field] = player;
        // Return move successful
        return true;
    }

    void displayBoard() {
        // For each row
        for (int row = 0; row < 3; ++row) {
            // For each field in a row
            for (int fieldInRow = 0; fieldInRow < 3; ++fieldInRow) {
                // Display proper field in a current row
                string valueToDisplay = fields[row * 3 + fieldInRow];
                cout << "|" << valueToDisplay << "|";
            }
            // Next row line
            cout << endl;
        }
    }

    string getWinner() {
        return (new WinnerChecker())->getWinner(fields);
    }
};

int main() {
    auto *gameBoard = new GameBoard();
    Player currentPlayer = Player_O;

    while (true) {
        // If winner is found finish the game
        if (!gameBoard->getWinner().empty()) {
            break;
        }

        // Start of move
        move:

        gameBoard->displayBoard();
        // Read the field from the keyboard input
        int field;
        cout << "Podaj pole na które ma ruszyc się gracz " << currentPlayer << ": " << endl;
        cin >> field;

        // Place player marker on proper field
        bool success = gameBoard->placePlayer(field - 1, currentPlayer);

        if(!success) {
            cout << "Miejsce jest juz zajęte!" << endl;
            // If place is already taken allow to make move again
            goto move;
        }

        // Change to next player
        if (currentPlayer == Player_O) {
            currentPlayer = Player_X;
        } else if (currentPlayer == Player_X) {
            currentPlayer = Player_O;
        }
    }

    cout << "Wygral gracz: " << gameBoard->getWinner() << endl;
}
