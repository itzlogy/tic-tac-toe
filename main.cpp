#include <iostream>
#include<windows.h>
using namespace std;
// Initialize the game board
char board[4][4] = { ' ', ' ', ' ', ' ',
                     ' ', ' ', ' ', ' ',
                     ' ', ' ', ' ', ' ',
                     ' ', ' ', ' ', ' ' };

// Check if a player has won
bool isWinner(char player) {
    // Check rows
    for (int i = 0; i < 4; i++) {
        if (board[i][0] == player && board[i][1] == player && board[i][2] == player && board[i][3] == player) {
            return true;
        }
    }

    // Check columns
    for (int i = 0; i < 4; i++) {
        if (board[0][i] == player && board[1][i] == player && board[2][i] == player && board[3][i] == player) {
            return true;
        }
    }

    // Check diagonals
    if (board[0][0] == player && board[1][1] == player && board[2][2] == player && board[3][3] == player) {
        return true;
    }
    if (board[0][3] == player && board[1][2] == player && board[2][1] == player && board[3][0] == player) {
        return true;
    }

    return false;
}

// Check if the board is full
bool isBoardFull() {
    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 4; j++) {
            if (board[i][j] == ' ') {
                return false;
            }
        }
    }
    return true;
}

// Display the game board
void displayBoard() {
    system("cls");
    cout << "   0   1   2   3  " << endl;
    for (int i = 0; i < 4; i++) {
        cout << i;
        for (int j = 0; j < 4; j++) {
            cout << "| "<< board[i][j] << " ";
        }
        cout << "|" << endl;
        if (i != 3)
            cout << " +---+---+---+---+" << endl;
    }

}

int main() {
    char currentPlayer = 'X';

    while (true) {
        // Display the current state of the board
        displayBoard();

        // Get the player's move
        int row, col;
        cout << currentPlayer << "'s turn, enter row (0-3) and column (0-3): ";
        cin >> row >> col;
        if (cin.fail())
        {
            cin.clear(); cin.ignore(512, '\n');
        }
        // Check if the selected position is valid
        if (board[row][col] != ' ') {
            cout << "Invalid move. Please try again." << endl;
            Sleep(1000);
            continue;
        }

        // Place the player's mark on the board
        board[row][col] = currentPlayer;

        // Check if the current player has won
        if (isWinner(currentPlayer)) {
            displayBoard();
            cout << currentPlayer << " wins!" << endl;
            break;
        }

        // Check if the board is full
        if (isBoardFull()) {
            displayBoard();
            cout << "It's a draw!" << endl;
            break;
        }

        // Switch players
        currentPlayer = (currentPlayer == 'X') ? 'O' : 'X';
    }

    // Ask if the players want to play again
    char playAgain;
    cout << "Play again? (y/n): ";
    cin >> playAgain;
    if (playAgain == 'y' || playAgain == 'Y') {
        // Reset the board and start a new game
        for (int i = 0; i < 4; i++) {
            for (int j = 0; j < 4; j++) {
                board[i][j] = ' ';
            }
        }
        // Reset the current player to 'X' and start the game again
        currentPlayer = 'X';
        main();
    }

    return 0;
}
