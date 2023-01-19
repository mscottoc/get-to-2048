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
void displayBox(Tile gridVal[4][4])
{
    std ::cout << " ____ ____ ____ ____ \n"
               << "|" << boxValue(gridVal[0][0].getValue()) << "|" << boxValue(gridVal[1][0].getValue()) << "|" << boxValue(gridVal[2][0].getValue()) << "|" << boxValue(gridVal[3][0].getValue()) << "|\n"
               << "|____|____|____|____|\n"
               << "|" << boxValue(gridVal[0][1].getValue()) << "|" << boxValue(gridVal[1][1].getValue()) << "|" << boxValue(gridVal[2][1].getValue()) << "|" << boxValue(gridVal[3][1].getValue()) << "|\n"
               << "|____|____|____|____|\n"
               << "|" << boxValue(gridVal[0][2].getValue()) << "|" << boxValue(gridVal[1][2].getValue()) << "|" << boxValue(gridVal[2][2].getValue()) << "|" << boxValue(gridVal[3][2].getValue()) << "|\n"
               << "|____|____|____|____|\n"
               << "|" << boxValue(gridVal[0][3].getValue()) << "|" << boxValue(gridVal[1][3].getValue()) << "|" << boxValue(gridVal[2][3].getValue()) << "|" << boxValue(gridVal[3][3].getValue()) << "|\n"
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
    int activeCount = 0;
    int inactiveCount = -1;
    int inactiveTiles[16][2];
    int turns = 0;

    // sets a random inactive member of the grid to active to initiate
    int rx = rand() % 4;
    int ry = rand() % 4;
    grid[rx][ry].activate();
    gridVal[rx][ry] = grid[rx][ry].getValue();
    int rz; // a surprize tool that will help us later;

    do
    {

        displayBox(grid);
        std::cout << "Q|quit\tw|up\ts|down\ta|left\td|right\n";
        cin >> input;
        turns++;

        // TODO: ADJUST NON UP OPTIONS
        if (input == 'Q')
        {
            gameOver = true;
        }
        else if (input == 'w')
        {
            // searches for active tiles
            for (int x = 0; x < 4; x++)
            {
                for (int y = 1; y < 4; y++)
                {
                    if (grid[x][y].isActive())
                    {
                        // checks tiles in same row/column and moves, deactivates, or increases them accordingly
                        for (int i = 1; i <= y; i++)
                        {
                            if (grid[x][y - i].isActive())
                            {
                                if (grid[x][y - i].getValue() == grid[x][y].getValue())
                                {
                                    grid[x][y - i].doubleValue();
                                    grid[x][y].deactivate();
                                    i = 100;
                                }
                                else if (i != 1)
                                {
                                    grid[x][y - i + 1] = grid[x][y];
                                    grid[x][y].deactivate();
                                    i = 100;
                                }
                            }
                            else if (y - i == 0)
                            {
                                grid[x][0] = grid[x][y];
                                grid[x][y].deactivate();
                                i = 100;
                            }
                        }
                    }
                }
            }
        }
        else if (input == 's')
        {
            // searches for active tiles
            for (int x = 0; x < 4; x++)
            {
                for (int y = 2; y > -1; y--)
                {
                    if (grid[x][y].isActive())
                    {
                        // checks tiles in same row/column and moves, deactivates, or increases them accordingly
                        for (int i = 1; i <= y; i++)
                        {
                            if (grid[x][y - i].isActive())
                            {
                                if (grid[x][y - i].getValue() == grid[x][y].getValue())
                                {
                                    grid[x][y - i].doubleValue();
                                    grid[x][y].deactivate();
                                    i = 100;
                                }
                                else if (i != 1)
                                {
                                    grid[x][y - i + 1] = grid[x][y];
                                    grid[x][y].deactivate();
                                    i = 100;
                                }
                            }
                            else if (y - i == 0)
                            {
                                grid[x][0] = grid[x][y];
                                grid[x][y].deactivate();
                                i = 100;
                            }
                        }
                    }
                }
            }
        }
        else if (input == 'a')
        {
            // searches for active tiles
            for (int x = 0; x < 4; x++)
            {
                for (int y = 1; y < 4; y++)
                {
                    if (grid[x][y].isActive())
                    {
                        // checks tiles in same row/column and moves, deactivates, or increases them accordingly
                        for (int i = 1; i <= y; i++)
                        {
                            if (grid[x][y - i].isActive())
                            {
                                if (grid[x][y - i].getValue() == grid[x][y].getValue())
                                {
                                    grid[x][y - i].doubleValue();
                                    grid[x][y].deactivate();
                                    i = 100;
                                }
                                else if (i != 1)
                                {
                                    grid[x][y - i + 1] = grid[x][y];
                                    grid[x][y].deactivate();
                                    i = 100;
                                }
                            }
                            else if (y - i == 0)
                            {
                                grid[x][0] = grid[x][y];
                                grid[x][y].deactivate();
                                i = 100;
                            }
                        }
                    }
                }
            }
        }
        else if (input == 'd')
        {
            // searches for active tiles
            for (int x = 0; x < 4; x++)
            {
                for (int y = 1; y < 4; y++)
                {
                    if (grid[x][y].isActive())
                    {
                        // checks tiles in same row/column and moves, deactivates, or increases them accordingly
                        for (int i = 1; i <= y; i++)
                        {
                            if (grid[x][y - i].isActive())
                            {
                                if (grid[x][y - i].getValue() == grid[x][y].getValue())
                                {
                                    grid[x][y - i].doubleValue();
                                    grid[x][y].deactivate();
                                    i = 100;
                                }
                                else if (i != 1)
                                {
                                    grid[x][y - i + 1] = grid[x][y];
                                    grid[x][y].deactivate();
                                    i = 100;
                                }
                            }
                            else if (y - i == 0)
                            {
                                grid[x][0] = grid[x][y];
                                grid[x][y].deactivate();
                                i = 100;
                            }
                        }
                    }
                }
            }
        }

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

        // sets a random inactive member of the grid to active
        rz = rand() % inactiveCount;
        grid[inactiveTiles[rz][0]][inactiveTiles[rz][1]].activate();

        if (activeCount >= 16)
            gameOver = true;

    } while (!gameOver && !gameWin);

    if (gameOver)
    {
        std::cout << "too bad so sad\n";
    }
    else if (gameWin)
    {
        std::cout << "\tCongratulations! you did it in " << turns << " turns!\n";
    }
}

int main()
{
    srand(time(0));
    std ::cout << "Can you get to 2048?\n";
    game();

    return 0;
}
