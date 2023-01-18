#include<vector>
#include <iostream>
using namespace std;

class WinnerChecker {
    // winningConditions variable holds the indexes that user has to occupy to win
    vector<vector<int>> winningConditions{
            // Horizontal win
            vector<int>{0, 1, 2},
            vector<int>{3, 4, 5},
            vector<int>{6, 7, 8},
            // Vertical win
            vector<int>{0, 3, 6},
            vector<int>{1, 4, 7},
            vector<int>{2, 5, 8},
            // Diagonal win
            vector<int>{0, 4, 8},
            vector<int>{2, 4, 6},
    };

public:
    string getWinner(vector<string> fields) {
        // Check all the winning conditions
        for (int i = 0; i < winningConditions.size(); ++i) {
            // Save the winning condition to check
            vector<int> winningCondition = winningConditions[i];

            // Check if all the fields are occupied by the same player
            if (playerOccupiesWinningFields(fields, winningCondition)) {
                // Return winning player
                return fields[winningCondition[0]];
            }
        }

        // No player won
        return "";
    }

    static bool playerOccupiesWinningFields(const vector<string>& fields, const vector<int>& winningCondition) {
        return fields[winningCondition[0]] == fields[winningCondition[1]] &&
               fields[winningCondition[1]] == fields[winningCondition[2]];
    }
};