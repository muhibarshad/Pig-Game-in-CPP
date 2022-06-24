#include <iostream>
#include <conio.h>
#include <cstdlib>
#include <ctime>
#include"header.h"
using namespace std;


void menu();
void roll_dice();
void new_game();
void Pig_Game();


int main()
{
    Pig_Game();

    return 0;
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
    if (score[activePlayer] >= 30)
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