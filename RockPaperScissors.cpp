/*
*   Raina Wan
*   Purpose: Play a game of Rock, Paper, Scissors.
*   Objectives: Demonstrate my understanding of nested, multi-way branches
*               including while loops, do-while loops, and switch statements.
*/

#include <iostream>
using namespace std;

int main()
{
    char ans, player1, player2;
    cout << "Let's play Rock, Paper, Scissors.\n";

    do
    {
        cout << "\nPlayer 1, pick your poison: ";
        cin >> player1;
        cout << "Player 2, pick your poison: ";
        cin >> player2;

        switch (player1)
        {
        case 'r': //execute if player 1 chooses rock
        case 'R':
            cout << "Rock v. ";
            switch (player2)
            {
            case 'r': //execute if player 2 chooses rock
            case 'R':
                cout << "Rock\n" << "It's a TIE\n";
                break;
            case 'p':
            case 'P':
                cout << "Paper\n" << "Player 2 wins\n";
                break;
            case 's':
            case 'S':
                cout << "Scissors\n" << "Player 1 wins\n";
                break;
            default:
                cout << "[ERROR: " << player2 << " not a valid move.]\n";
                break;
            }
            break;

        case 'p':
        case 'P':
            cout << "Paper v. ";
            switch (player2)
            {
            case 'r':
            case 'R':
                cout << "Rock\n" << "Player 1 wins\n";
                break;
            case 'p':
            case 'P':
                cout << "Paper\n" << "It's a TIE\n";
                break;
            case 's':
            case 'S':
                cout << "Scissors\n" << "Player 2 wins\n";
                break;
            default:
                cout << "[ERROR: " << player2 << " not a valid move.]\n";
                break;
            }
            break;

        case 's':
        case 'S':
            cout << "Scissors v. ";
            switch (player2)
            {
            case 'r':
            case 'R':
                cout << "Rock\n" << "Player 2 wins\n";
                break;
            case 'p':
            case 'P':
                cout << "Paper\n" << "Player 1 wins\n";
                break;
            case 's':
            case 'S':
                cout << "Scissors\n" << "It's a TIE\n";
                break;
            default:
                cout << "[ERROR: " << player2 << " not a valid move.]\n";
                break;
            }
            break;
        default:
            cout << "[Error: " << player1 << " not a valid move.]\n";
            break;
        }
        cout << endl << "again? ";
        cin >> ans;

    } while (ans == 'y' || ans == 'Y');

    cout << endl << "Nice game!";

    return 0;
}