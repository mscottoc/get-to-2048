#include <iostream>
#include <string>
#include <stdlib.h>
#include <ctime>

using namespace std;

class Tile
{
public:
    int value = 0;
    bool active = false;
    void doubleValue()
    {
        value = value * 2;
    };
    void activate()
    {
        int rdm = rand() % 100;
        if (rdm < 50)
        {
            value = 2;
        }
        else if (rdm < 90)
        {
            value = 4;
        }
        else
        {
            value = 8;
        }

        active = true;
    }
};

// displays individual values of a tile
string boxValue(int number)
{
    string ans;

    if (number == 0)
    {
        cout << "    ";
    }
    else if (number < 10)
    {
        cout << "  ";
        cout << number;
        cout << " ";
    }
    else if (number < 100)
    {
        cout << " ";
        cout << number;
        cout << " ";
    }
    else if (number < 1000)
    {
        cout << number;
        cout << " ";
    }
    else if (number < 10000)
    {
        cout << number;
    }

    return "";
}

// displays the grid of values
void displayBox(int grid[4][4])
{
    std ::cout << " ____ ____ ____ ____ \n"
               << "|" << boxValue(grid[0][0]) << "|" << boxValue(grid[1][0]) << "|" << boxValue(grid[2][0]) << "|" << boxValue(grid[3][0]) << "|\n"
               << "|____|____|____|____|\n"
               << "|" << boxValue(grid[0][1]) << "|" << boxValue(grid[1][1]) << "|" << boxValue(grid[2][1]) << "|" << boxValue(grid[3][1]) << "|\n"
               << "|____|____|____|____|\n"
               << "|" << boxValue(grid[0][2]) << "|" << boxValue(grid[1][2]) << "|" << boxValue(grid[2][2]) << "|" << boxValue(grid[3][2]) << "|\n"
               << "|____|____|____|____|\n"
               << "|" << boxValue(grid[0][3]) << "|" << boxValue(grid[1][3]) << "|" << boxValue(grid[2][3]) << "|" << boxValue(grid[3][3]) << "|\n"
               << "|____|____|____|____|\n";
}

// main gameplay loop
void game()
{
    Tile grid[4][4];
    char input;
    int gridVal[4][4] = {0};
    bool gameOver = false;
    bool gameWin = false;

    do{
        
        do
        {
            /* code */
        } while ();
        
        displayBox(gridVal);
        cin >> input; 

        
        // Checks in there are no free squares
        

        for (int x = 0; x < 4; x++)
        {
            for (int y = 0; y < 4; y++)
            {
                if (grid[x][y].active)
                {

                }
            }
            
        }
    }while (!gameOver || !gameWin);
}

int main()
{
    srand(time(0));
    std ::cout << "Can you get to 2048?\n";
    game();

    return 0;
}
