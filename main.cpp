#include <iostream>
#include <string>
#include <sstream>
#include <stdlib.h>
#include <ctime>
#include <set>

using namespace std;

class Tile
{
private:
    int value = 0;
    bool active = false;

public:
    bool isActive()
    {
        return active;
    }
    int getValue()
    {
        return value;
    }
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

    void deactivate()
    {
        active = false;
        value = 0;
    }
};

// displays individual values of a tile
string boxValue(int number)
{
    stringstream ans;

    if (number == 0)
    {
        ans << "    ";
    }
    else if (number < 10)
    {
        ans << "  ";
        ans << number;
        ans << " ";
    }
    else if (number < 100)
    {
        ans << " ";
        ans << number;
        ans << " ";
    }
    else if (number < 1000)
    {
        ans << number;
        ans << " ";
    }
    else if (number < 10000)
    {
        ans << number;
    }

    return ans.str();
}

// displays the grid of values
void displayBox(int gridVal[4][4])
{
    std ::cout << " ____ ____ ____ ____ \n"
               << "|" << boxValue(gridVal[0][0]) << "|" << boxValue(gridVal[1][0]) << "|" << boxValue(gridVal[2][0]) << "|" << boxValue(gridVal[3][0]) << "|\n"
               << "|____|____|____|____|\n"
               << "|" << boxValue(gridVal[0][1]) << "|" << boxValue(gridVal[1][1]) << "|" << boxValue(gridVal[2][1]) << "|" << boxValue(gridVal[3][1]) << "|\n"
               << "|____|____|____|____|\n"
               << "|" << boxValue(gridVal[0][2]) << "|" << boxValue(gridVal[1][2]) << "|" << boxValue(gridVal[2][2]) << "|" << boxValue(gridVal[3][2]) << "|\n"
               << "|____|____|____|____|\n"
               << "|" << boxValue(gridVal[0][3]) << "|" << boxValue(gridVal[1][3]) << "|" << boxValue(gridVal[2][3]) << "|" << boxValue(gridVal[3][3]) << "|\n"
               << "|____|____|____|____|\n";
}

// main gameplay loop
void game()
{
    Tile grid[4][4];
    string input;
    int gridVal[4][4] = {0};
    bool gameOver = false;
    bool gameWin = false;
    int activeCount = 0;
    int inactiveCount = -1;
    int inactiveTiles[16][2];
    bool emptySquareFound;
    

    do
    {
        emptySquareFound = false;

        // sets a random inactive member of the grid to active
        if (inactiveCount == -1)
        {
            int rx = rand() % 4;
            int ry = rand() % 4;
            grid[rx][ry].activate();
            gridVal[rx][ry] = grid[rx][ry].getValue();
            cout << gridVal[rx][ry];
        }
        else
        {
            int rz = rand() % inactiveCount;
        }

        displayBox(gridVal);
        cin >> input;

        // Checks in there are no free squares

        activeCount = 0;
        inactiveCount = 0;
        for (int i = 0; i < 16; i++)
        {
            inactiveTiles[i][0] = 0;
            inactiveTiles[i][1] = 0;
        }

        

        for (int x = 0; x < 4; x++)
        {
            for (int y = 0; y < 4; y++)
            {
                if (grid[x][y].isActive())
                {
                    activeCount++;
                }
                else
                {
                    inactiveTiles[inactiveCount][0] = x;
                    inactiveTiles[inactiveCount][1] = y;
                    inactiveCount++;
                }
            }
        }

        if (activeCount >= 16)
            gameOver = true;

    } while (!gameOver || !gameWin);
}

int main()
{
    srand(time(0));
    std ::cout << "Can you get to 2048?\n";
    game();

    return 0;
}
