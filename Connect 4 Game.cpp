#include <iostream>
#include <ctime>
using namespace std;
// connect4 game
void compchoice(char spaces[][7], int row, int column, char marker1, char marker2, int count, int *ptr1, int *ptr2);
void printtable(char spaces[][7], int row, int column);
bool wincheck(char spaces[][7], int row, int column, char marker1, char marker2);

int main()
{
    srand(time(NULL));
    char mark[6][7], empty = ' ', marker1, marker2;
    int i, j;
    for (i = 0; i < 6; i++)
    {
        for (j = 0; j < 7; j++)
        {
            mark[i][j] = empty;
        }
    }
    cout << "******************************************************************************" << endl;
    cout << "Welcome to the 4 in a row game (created by Aditya Y)" << endl;
    printtable(mark,6,7);
    cout<<endl;
    int p, z; // coords the player chooses
    cout << "Choose your marker X or O" << endl;
    cin >> marker1;
    marker1 = toupper(marker1);
    if (marker1 == 'X')
        marker2 = 'O';
    else
        marker2 = 'X';
    cout << "You chose " << marker1 << " The compiler has " << marker2 << endl;

    int count = 0; // to keep track game rounds

    int a1, a2; // comp coords
    int *ptr1 = &a1, *ptr2 = &a2;
    cout << "******************************************************************************" << endl;
    bool user, comp;

    for (i = 0; i < 21; i++)
    {
        cout << "Enter the coordinates (x,y) " << endl;
        if (count == 0)
        {
            p = 5;
            cout << "Enter Y (Y<7). (X is 5 anyway in the beginning)" << endl;
            cin >> z;
        }
        else
            cin >> p >> z;
        while (z > 6 || p > 5)
        {
            cout << "Enter Valid coordinates x<6 & y<7 " << endl;
            cin >> p >> z;
        }
        if (p != 5)
        {
            if (mark[p + 1][z] == ' ')
            {
                while (mark[p + 1][z] == ' ')
                {
                    cout << "******************************************************************************" << endl;

                    cout << "You cannot place your marker on a vacant position.Please Enter Valid Coords" << endl;
                    cin >> p >> z;
                }
            }
        }
        mark[p][z] = marker1;
        cout << "******************************************************************************" << endl;
        cout << "Your Turn is completed" << endl;
        printtable(mark, 6, 7);
        user = wincheck(mark, 6, 7, marker1, marker2);
        if (user == true)
        {
            cout << endl;
            cout << "******************************************************************************" << endl;

            cout << "Congratulations,You Won" << endl;
            cout << "******************************************************************************" << endl;

            break;
        }
        cout << endl;
        cout << "******************************************************************************" << endl;
        cout << "Compiler's Turn is completed" << endl;
        compchoice(mark, 6, 7, marker1, marker2, count, ptr1, ptr2);
        mark[a1][a2] = marker2;
        printtable(mark, 6, 7);
        comp = wincheck(mark, 6, 7, marker1, marker2);
        cout << endl;
        cout << "Compiler placed at (x,y) = " << a1 << "," << a2 << endl;

        cout << endl;
        cout << "******************************************************************************" << endl;
        if (comp == true)
        {
            cout << endl;
            cout << "The Compiler Won" << endl;
            cout << "******************************************************************************" << endl;

            break;
        }

        count++;
    }
    if (count == 21)
    {
        cout << "It's a Tie" << endl;
    }

    cout << "Thanks for playing the game.Hope you liked it" << endl;
    cout << "******************************************************************************" << endl;

    return 0;
}

bool wincheck(char spaces[][7], int row, int column, char marker1, char marker2)
{
    // horizontal check
    int i, j;
    for (i = 0; i < 6; i++)
    {
        for (j = 0; j < 4; j++)
        {
            if (spaces[i][j] == marker1 && spaces[i][j] == spaces[i][j + 1] && spaces[i][j + 1] == spaces[i][j + 2] && spaces[i][j + 2] == spaces[i][j + 3])
                return true;
            else if (spaces[i][j] == marker2 && spaces[i][j] == spaces[i][j + 1] && spaces[i][j + 1] == spaces[i][j + 2] && spaces[i][j + 2] == spaces[i][j + 3])
                return true;
        }
    }
    // vertical check
    for (j = 0; j < 7; j++)
    {
        for (i = 0; i < 3; i++)
        {
            if (spaces[i][j] == marker1 && spaces[i][j] == spaces[i + 1][j] && spaces[i + 1][j] == spaces[i + 2][j] && spaces[i + 2][j] == spaces[i + 3][j])
                return true;
            else if (spaces[i][j] == marker2 && spaces[i][j] == spaces[i + 1][j] && spaces[i + 1][j] == spaces[i + 2][j] && spaces[i + 2][j] == spaces[i + 3][j])
                return true;
        }
    }
    // check for diagonal wins starting from the top left corner
    for (i = 0; i < row - 3; i++)
    {
        for (j = 0; j < column - 3; j++)
        {
            if (spaces[i][j] == marker1 && spaces[i + 1][j + 1] == marker1 && spaces[i + 2][j + 2] == marker1 && spaces[i + 3][j + 3] == marker1)
            {
                return true;
            }
            if (spaces[i][j] == marker2 && spaces[i + 1][j + 1] == marker2 && spaces[i + 2][j + 2] == marker2 && spaces[i + 3][j + 3] == marker2)
            {
                return true;
            }
        }
    }

    // check for diagonal wins starting from the top right corner
    for (i = 0; i < row - 3; i++)
    {
        for (j = column - 1; j >= 3; j--)
        {
            if (spaces[i][j] == marker1 && spaces[i + 1][j - 1] == marker1 && spaces[i + 2][j - 2] == marker1 && spaces[i + 3][j - 3] == marker1)
            {
                return true;
            }
            if (spaces[i][j] == marker2 && spaces[i + 1][j - 1] == marker2 && spaces[i + 2][j - 2] == marker2 && spaces[i + 3][j - 3] == marker2)
            {
                return true;
            }
        }
    }

    return false;
}
void compchoice(char spaces[][7], int row, int column, char marker1, char marker2, int count, int *ptr1, int *ptr2)
{

    int i = rand() % 6, j = rand() % 7, a, count1 = 0;

    for (a = 0; a < 7; a++)
    {
        if (spaces[5][a] == ' ')
            count1++;
    }
    if (count1 != 0)
    {
        if (count == 0 || i == 5)
        {

            i = 5;
            if (spaces[i][j] != ' ')
            {
                while (spaces[i][j] != ' ')
                {
                    j = rand() % 7;
                }
            }

            *ptr1 = i;
            *ptr2 = j;
            return;
        }
    }
    if (i == 5)
    {
        if (count1 == 0)
        {
            for (a = 0; a < 100; a++)
            {
                i = rand() % 5;
                j = rand() % 7;
                if (spaces[i][j] == ' ' && spaces[i + 1][j] != ' ')
                {
                    *ptr1 = i;
                    *ptr2 = j;
                    return;
                }
            }
        }
    }
    if (spaces[i + 1][j] != ' ' && spaces[i][j] == ' ')
    {

        *ptr1 = i;
        *ptr2 = j;
        return;
    }
    else
    {
        for (a = 0; a < 100; a++)
        {
            i = rand() % 6;
            j = rand() % 7;

            if (i != 5)
            {
                if (spaces[i][j] == ' ' && spaces[i + 1][j] != ' ')
                {
                    *ptr1 = i;
                    *ptr2 = j;
                    return;
                }
            }
            else if (spaces[i][j] == ' ')
            {
                *ptr1 = i;
                *ptr2 = j;
                return;
            }
        }
    }
}

void printtable(char spaces[][7], int row, int column)
{

    cout << "  "
         << "_0__"
         << "_1_"
         << "_2_"
         << "_3_"
         << "_4_"
         << "_5_"
         << "_6_" << endl;

    cout << " 0"
         << "|" << spaces[0][0] << " |" << spaces[0][1] << " |" << spaces[0][2] << " |" << spaces[0][3] << " |" << spaces[0][4] << " |" << spaces[0][5] << " |" << spaces[0][6] << " |" << endl;
    cout << "  "
         << "|"
         << "__|"
         << "__|"
         << "__|"
         << "__|"
         << "__|"
         << "__|"
         << "__|" << endl;
    cout << " 1"
         << "|" << spaces[1][0] << " |" << spaces[1][1] << " |" << spaces[1][2] << " |" << spaces[1][3] << " |" << spaces[1][4] << " |" << spaces[1][5] << " |" << spaces[1][6] << " |" << endl;
    cout << "  "
         << "|"
         << "__|"
         << "__|"
         << "__|"
         << "__|"
         << "__|"
         << "__|"
         << "__|" << endl;

    cout << " 2"
         << "|" << spaces[2][0] << " |" << spaces[2][1] << " |" << spaces[2][2] << " |" << spaces[2][3] << " |" << spaces[2][4] << " |" << spaces[2][5] << " |" << spaces[2][6] << " |" << endl;
    cout << "  "
         << "|"
         << "__|"
         << "__|"
         << "__|"
         << "__|"
         << "__|"
         << "__|"
         << "__|" << endl;

    cout << " 3"
         << "|" << spaces[3][0] << " |" << spaces[3][1] << " |" << spaces[3][2] << " |" << spaces[3][3] << " |" << spaces[3][4] << " |" << spaces[3][5] << " |" << spaces[3][6] << " |" << endl;
    cout << "  "
         << "|"
         << "__|"
         << "__|"
         << "__|"
         << "__|"
         << "__|"
         << "__|"
         << "__|" << endl;

    cout << " 4"
         << "|" << spaces[4][0] << " |" << spaces[4][1] << " |" << spaces[4][2] << " |" << spaces[4][3] << " |" << spaces[4][4] << " |" << spaces[4][5] << " |" << spaces[4][6] << " |" << endl;
    cout << "  "
         << "|"
         << "__|"
         << "__|"
         << "__|"
         << "__|"
         << "__|"
         << "__|"
         << "__|" << endl;

    cout << " 5"
         << "|" << spaces[5][0] << " |" << spaces[5][1] << " |" << spaces[5][2] << " |" << spaces[5][3] << " |" << spaces[5][4] << " |" << spaces[5][5] << " |" << spaces[5][6] << " |" << endl;
    cout << "  "
         << "|"
         << "__|"
         << "__|"
         << "__|"
         << "__|"
         << "__|"
         << "__|"
         << "__|" << endl;
}