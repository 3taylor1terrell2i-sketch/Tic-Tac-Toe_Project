//**************************************************************
// Author: Terrell Taylor
// Date: 07/26/2026
// Description: Assignment 10
// This program should create a 2-player Tic-Tac-Toe game.
//**************************************************************
// Header files
#include <iostream> // Needed for cin and cout
#include <string> // Needed for String Variables
#include <fstream> // Needed for Input and Output files

// using namespaces
using namespace std;

// Start of Main Function
int main()
{
    // Title
    cout << "Welcome to Tic Tac Toe" << endl << endl;

    // Declare variables
    int row;
    int col;
    bool game_over = false;
    bool X_turn = false;
    bool O_turn = false;

    // Declare arrays
    string layer[] = {"+---+---+---+", "\n"};
    string wall[] = {"|"};
    string space[3] = {"   ", " X ", " O "};

    // Create grid visuals
    string grid[7][7] = {{layer[0], layer[1]},
                         {wall[0], space[0], wall[0], space[0], wall[0], space[0], wall[0]}, 
                         {layer[1], layer[0], layer[1]}, 
                         {wall[0], space[0], wall[0], space[0], wall[0], space[0], wall[0]}, 
                         {layer[1], layer[0], layer[1]},
                         {wall[0], space[0], wall[0], space[0], wall[0], space[0], wall[0]},
                         {layer[1], layer[0], layer[1]}};


    // Start game
    while (!game_over == true)
    {
        // Display grid
        for (int i = 0; i < 7; i++)
        {
            for (int o = 0; o < 7; o++)
            {
                cout << grid[i][o];
            }
        }

        // Check if win conditions are met
        if (grid[1][1] == space[1] && grid[1][3] == space[1] && grid[1][5] == space[1] || grid[3][1] == space[1] && grid[3][3] == space[1] && grid[3][5] == space[1] || grid[5][1] == space[1] && grid[5][3] == space[1] && grid[5][5] == space[1] || 
        grid[1][1] == space[1] && grid[3][1] == space[1] && grid[5][1] == space[1] || grid[1][3] == space[1] && grid[3][3] == space[1] && grid[5][3] == space[1] || grid[1][5] == space[1] && grid[3][5] == space[1] && grid[5][5] == space[1] || 
        grid[1][1] == space[1] && grid[3][3] == space[1] && grid[5][5] == space[1] || grid[1][5] == space[1] && grid[3][3] == space[1] && grid[1][5] == space[1])
        {
            cout << endl << "X wins!" << endl << endl;
            game_over = true;
            continue;
        }
        else if (grid[1][1] == space[2] && grid[1][3] == space[2] && grid[1][5] == space[2] || grid[3][1] == space[2] && grid[3][3] == space[2] && grid[3][5] == space[2] || grid[5][1] == space[2] && grid[5][3] == space[2] && grid[5][5] == space[2] || 
        grid[1][1] == space[2] && grid[3][1] == space[2] && grid[5][1] == space[2] || grid[1][3] == space[2] && grid[3][3] == space[2] && grid[5][3] == space[2] || grid[1][5] == space[2] && grid[3][5] == space[2] && grid[5][5] == space[2] || 
        grid[1][1] == space[2] && grid[3][3] == space[2] && grid[5][5] == space[2] || grid[5][1] == space[2] && grid[3][3] == space[2] && grid[1][5] == space[2])
        {
            cout << endl << "O wins!" << endl << endl;
            game_over = true;
            continue;
        }

        cout << "X's Turn" << endl;
        X_turn = true;
        while (X_turn == true)
        {
            cout << "Pick a row (1, 2, 3):  ";
            cin >> row;

            if (row == 2)
            {
                row = 3;
            }
            else if (row == 3)
            {
                row = 5;
            }
            else while (row != 1 && row != 2 && row != 3)
            {
                cout << "Invalid row, try again" << endl;
                cout << "Pick a row (1, 2, 3):  ";
                cin >> row;
            }

            cout << "Pick a column (1, 2, 3):   ";
            cin >> col;

            if (col == 2)
            {
                col = 3;
            }
            else if (col == 3)
            {
                col = 5;
            }
            else while (col != 1 && col != 2 && col != 3)
            {
                cout << "Invalid column, try again" << endl;
                cout << "Pick a column (1, 2, 3):  ";
                cin >> col;
            }

            if (grid[row][col] == space[0])
            {
                grid[row][col] = space[1];
                X_turn = false;
            }
            else
            {
                cout << "Space taken, try again" << endl;
            }
        }

        // Update grid and check win conditions before switching turns

        for (int i = 0; i < 7; i++)
        {
            for (int o = 0; o < 7; o++)
            {
                cout << grid[i][o];
            }
        }

        if (grid[1][1] == space[1] && grid[1][3] == space[1] && grid[1][5] == space[1] || grid[3][1] == space[1] && grid[3][3] == space[1] && grid[3][5] == space[1] || grid[5][1] == space[1] && grid[5][3] == space[1] && grid[5][5] == space[1] || 
        grid[1][1] == space[1] && grid[3][1] == space[1] && grid[5][1] == space[1] || grid[1][3] == space[1] && grid[3][3] == space[1] && grid[5][3] == space[1] || grid[1][5] == space[1] && grid[3][5] == space[1] && grid[5][5] == space[1] || 
        grid[1][1] == space[1] && grid[3][3] == space[1] && grid[5][5] == space[1] || grid[5][1] == space[1] && grid[3][3] == space[1] && grid[1][5] == space[1])
        {
            cout << endl << "X wins!" << endl << endl;
            game_over = true;
            continue;
        }
        else if (grid[1][1] == space[2] && grid[1][3] == space[2] && grid[1][5] == space[2] || grid[3][1] == space[2] && grid[3][3] == space[2] && grid[3][5] == space[2] || grid[5][1] == space[2] && grid[5][3] == space[2] && grid[5][5] == space[2] || 
        grid[1][1] == space[2] && grid[3][1] == space[2] && grid[5][1] == space[2] || grid[1][3] == space[2] && grid[3][3] == space[2] && grid[5][3] == space[2] || grid[1][5] == space[2] && grid[3][5] == space[2] && grid[5][5] == space[2] || 
        grid[1][1] == space[2] && grid[3][3] == space[2] && grid[5][5] == space[2] || grid[5][1] == space[2] && grid[3][3] == space[2] && grid[1][5] == space[2])
        {
            cout << endl << "O wins!" << endl << endl;
            game_over = true;
            continue;
        }
        if (grid[1][1] != space[0] && grid[1][3] != space[0] && grid[1][5] != space[0] && grid[3][1] != space[0] && grid[3][3] != space[0] && grid[3][5] != space[0] && grid[5][1] != space[0] && grid[5][3] != space[0] && grid[5][5] != space[0])
        {
            cout << endl << "It's a draw!" << endl << endl;
            game_over = true;
            continue;
        }

        cout << "O's Turn" << endl;
        O_turn = true;
        while (O_turn == true)
        {
            cout << "Pick a row (1, 2, 3):  ";
            cin >> row;

            if (row == 2)
            {
                row = 3;
            }
            else if (row == 3)
            {
                row = 5;
            }
            else while (row != 1 && row != 2 && row != 3)
            {
                cout << "Invalid row, try again" << endl;
                cout << "Pick a row (1, 2, 3):  ";
                cin >> row;
            }

            cout << "Pick a column (1, 2, 3):   ";
            cin >> col;

            if (col == 2)
            {
                col = 3;
            }
            else if (col == 3)
            {
                col = 5;
            }
            else while (col != 1 && col != 2 && col != 3)
            {
                cout << "Invalid column, try again" << endl;
                cout << "Pick a column (1, 2, 3):  ";
                cin >> col;
            }

            if (grid[row][col] == space[0])
            {
                grid[row][col] = space[2];
                O_turn = false;
            }
            else
            {
                cout << "Space taken, try again" << endl;
            }
        }
    }

    cout << "Game over!" << endl;
    return 0;
} // End Main Function