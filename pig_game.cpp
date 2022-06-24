#include <iostream>
#include <conio.h>
#include <cstdlib>
#include <ctime>
using namespace std;

int currentScore = 0;
int activePlayer = 0;
int score[] = {0, 0};
bool flag = false;
int randG = 0;

void spacesLine()
{
    for (int i = 0; i < 5; i++)
    {
        cout << endl;
    }
}
void congtatulations()
{
    cout << "\t\t*******Congratulations**************" << endl;
    spacesLine();
    cout << "\t\t ****Player " << activePlayer << " wins the game:****" << endl;
    spacesLine();
}
void menu()
{
    spacesLine();
    if (flag == false)
    {
        cout << "\t\tEnter the R to Roll the Dice:" << endl;
        cout << "\t\tEnter the H to hold :" << endl;
        cout << "\t\tEnter the N to start the new game:" << endl;
        cout << "\t\tEnter the q to quit the game:" << endl;
    }
    else
    {
        congtatulations();
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

void frontDisplay(int random, int activeplayer)
{
    system("cls");
    menu();
    scoresDisplay(score[0], score[1]);
    displayDice(random, activeplayer);
}

void switchPlayer()
{
    currentScore = 0;
    activePlayer = activePlayer == 1 ? 0 : 1;
}
void roll_dice()
{
    int x = time(0);
    srand(x);
    int random = (rand() % 6) + 1;
    randG = random;
    if (random != 1)
    {
        currentScore += random;
    }
    if (random == 1)
    {
        switchPlayer();
    }
    frontDisplay(random, activePlayer);
    cout << "\t\tThe current score of the Player " << activePlayer << " : " << currentScore << endl;
}
void hold_dice()
{

    score[activePlayer] += currentScore;
    if (score[activePlayer] >= 100)
    {
        flag = true;
        frontDisplay(randG, activePlayer);
    }
    else
    {
        switchPlayer();
        cout << endl;
        cout << "\t\t***Player is switched to the " << activePlayer << " : " << endl;
        cout << "\t\t***Now its player  " << activePlayer << "  turns : " << endl;
        cout << endl;
        flag = false;
    }
}
void new_game()
{
    currentScore = 0;
    activePlayer = 0;
    score[0] = 0;
    score[1] = 0;
    flag = false;
    randG = 0;
    frontDisplay(0, activePlayer);
}
void Pig_Game()
{

    frontDisplay(0, activePlayer);
    char ch;
    do
    {
        ch = getch();
        ch = tolower(ch);
        switch (ch)
        {
        case 'r':
        {
            roll_dice();
            break;
        }
        case 'h':
        {
            hold_dice();
            break;
        }
        case 'n':
        {
            new_game();
            break;
        }
        case 'q':
        {
            cout << "Quiting.............." << endl;
            flag = true;
            break;
        }
        }
    } while (flag == false);
}

int main()
{
    Pig_Game();

    return 0;
}
