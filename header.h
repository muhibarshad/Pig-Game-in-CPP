#include<iostream>
using namespace std;

int currentScore = 0;
int activePlayer = 0;
int score[] = {0, 0};
bool flag = false;
int randG = 0;

void menu();
void roll_dice();
void new_game();
void Pig_Game();


void spacesLine()
{
    for (int i = 0; i < 5; i++)
    {
        cout << endl;
    }
}

void scoresDisplay(int score0, int score1)
{
    for (int i = 0; i < 1; i++)
    {
        cout << "\t\t";
        for (int j = 0; j < 46; j++)
        {
            if (j != 0)
                cout << "_";
            else
                cout << " ";
        }
        cout << endl;
    }
    cout << "\t\t|                                             |" << endl;
    cout << "\t\t| The Total Score the Player 0 :" << score0 << "             |" << endl;
    cout << "\t\t| The Total Score the Player 1 :" << score1 << "             |" << endl;
    cout << "\t\t|                                             |" << endl;
    for (int i = 0; i < 1; i++)
    {
        cout << "\t\t";
        for (int j = 0; j < 46; j++)
        {
            if (j != 0)
                cout << "-";
            else
                cout << " ";
        }
        cout << endl;
    }
}

void displayDice(int random, int activeplayer)
{
    spacesLine();
    cout << "\t\t***Active Palyer is " << activeplayer << " ***" << endl;
    cout << endl;
    cout << "\t\tThe Dice you Rolled is :" << endl;
    cout << endl;
    int k = 0;
    cout << "\t\t\t ---- " << endl;
    for (int i = 0; i < 3; i++)
    {
        cout << "\t\t\t|";
        for (int i = 0; i < 2; i++)
        {
            if (k < random)
                cout << "* ";
            else
                cout << "  ";
            k++;
        }
        cout << "|";
        cout << endl;
    }
    cout << "\t\t\t ---- " << endl;
}

void congtatulations()
{
    cout << "\t\t*******Congratulations**************" << endl;
    spacesLine();
    cout << "\t\t ****Player " << activePlayer << " wins the game:****" << endl;
    spacesLine();
}

void switchPlayer()
{
    currentScore = 0;
    activePlayer = activePlayer == 1 ? 0 : 1;
}

void frontDisplay(int random, int activeplayer)
{
    system("cls");
    menu();
    scoresDisplay(score[0], score[1]);
    displayDice(random, activeplayer);
}

