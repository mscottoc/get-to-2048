#include <iostream>
#include <string>
#include <sstream>
#include <stdlib.h>
#include <ctime>

using namespace std;

class Tile
{
private:
    int value = 0;
    bool active = false;
    bool combined = false;

public:
    bool isCombined()
    {
        return combined;
    }
    void reset()
    {
        combined = false;
    }
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
        combined = true;
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
void displayBox(Tile grid[4][4])
{
    std ::cout << " ____ ____ ____ ____ \n"
               << "|" << boxValue(grid[0][0].getValue()) << "|" << boxValue(grid[1][0].getValue()) << "|" << boxValue(grid[2][0].getValue()) << "|" << boxValue(grid[3][0].getValue()) << "|\n"
               << "|____|____|____|____|\n"
               << "|" << boxValue(grid[0][1].getValue()) << "|" << boxValue(grid[1][1].getValue()) << "|" << boxValue(grid[2][1].getValue()) << "|" << boxValue(grid[3][1].getValue()) << "|\n"
               << "|____|____|____|____|\n"
               << "|" << boxValue(grid[0][2].getValue()) << "|" << boxValue(grid[1][2].getValue()) << "|" << boxValue(grid[2][2].getValue()) << "|" << boxValue(grid[3][2].getValue()) << "|\n"
               << "|____|____|____|____|\n"
               << "|" << boxValue(grid[0][3].getValue()) << "|" << boxValue(grid[1][3].getValue()) << "|" << boxValue(grid[2][3].getValue()) << "|" << boxValue(grid[3][3].getValue()) << "|\n"
               << "|____|____|____|____|\n";
}

void moveTiles(Tile grid[4][4], char &input)
{
    if (input == 'w') // moves tiles up
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
                        // only combine if they are the same value and they have not been combined yet this turn.
                        if (grid[x][y - i].isActive())
                        {
                            if (grid[x][y - i].getValue() == grid[x][y].getValue() && !grid[x][y - i].isCombined())
                            {
                                // combines tiles
                                grid[x][y - i].doubleValue();
                                grid[x][y].deactivate();
                                i = 100;
                            }
                            else if (i != 1) // does not move if adjacent to the next active tile
                            {
                                // moves tile to the next empty space
                                grid[x][y - i + 1] = grid[x][y];
                                grid[x][y].deactivate();
                                i = 100;
                            }
                            else
                            {
                                // ends iteration without changing tile.
                                i = 100;
                            }
                        }
                        else if (y - i == 0)
                        {
                            // moves to the first empty space
                            grid[x][0] = grid[x][y];
                            grid[x][y].deactivate();
                            i = 100;
                        }
                    }
                }
            }
        }
    }
    else if (input == 's') // moves tiles down
    {
        // searches for active tiles
        for (int x = 0; x < 4; x++)
        {
            for (int y = 2; y > -1; y--)
            {
                if (grid[x][y].isActive())
                {
                    // checks tiles in same row/column and moves, deactivates, or increases them accordingly
                    for (int i = 1; i + y < 4; i++)
                    {
                        if (grid[x][y + i].isActive())
                        {
                            // only combine if they are the same value and they have not been combined yet this turn.
                            if (grid[x][y + i].getValue() == grid[x][y].getValue() && !grid[x][y + i].isCombined())
                            {
                                // combines tiles
                                grid[x][y + i].doubleValue();
                                grid[x][y].deactivate();
                                i = 100;
                            }
                            else if (i != 1) // does not move if adjacent to the next active tile
                            {
                                // moves tile to the next empty space
                                grid[x][y + i - 1] = grid[x][y];
                                grid[x][y].deactivate();
                                i = 100;
                            }
                            else
                            {
                                // ends iteration without changing tile.
                                i = 100;
                            }
                        }
                        else if (y + i == 3)
                        {
                            // moves to the first empty space
                            grid[x][3] = grid[x][y];
                            grid[x][y].deactivate();
                            i = 100;
                        }
                    }
                }
            }
        }
    }
    else if (input == 'a') // moves tiles left
    {
        // searches for active tiles
        for (int y = 0; y < 4; y++)
        {
            for (int x = 1; x < 4; x++)
            {
                if (grid[x][y].isActive())
                {
                    // checks tiles in same row/column and moves, deactivates, or increases them accordingly
                    for (int i = 1; i <= x; i++)
                    {
                        if (grid[x - i][y].isActive())
                        {
                            // only combine if they are the same value and they have not been combined yet this turn.
                            if (grid[x - i][y].getValue() == grid[x][y].getValue() && !grid[x - i][y].isCombined())
                            {
                                // combines tiles
                                grid[x - i][y].doubleValue();
                                grid[x][y].deactivate();
                                i = 100;
                            }
                            else if (i != 1) // does not move if adjacent to the next active tile
                            {
                                // moves tile to the next empty space
                                grid[x - i + 1][y] = grid[x][y];
                                grid[x][y].deactivate();
                                i = 100;
                            }
                            else
                            {
                                // ends iteration without changing tile.
                                i = 100;
                            }
                        }
                        else if (x - i == 0)
                        {
                            // moves to the first empty space
                            grid[0][y] = grid[x][y];
                            grid[x][y].deactivate();
                            i = 100;
                        }
                    }
                }
            }
        }
    }
    else if (input == 'd') // moves tiles right
    {
        for (int y = 0; y < 4; y++)
        {
            for (int x = 2; x > -1; x--)
            {
                if (grid[x][y].isActive())
                {
                    // checks tiles in same row/column and moves, deactivates, or increases them accordingly
                    for (int i = 1; i + x < 4; i++)
                    {
                        // only combine if they are the same value and they have not been combined yet this turn.
                        if (grid[x + i][y].isActive())
                        {
                            if (grid[x + i][y].getValue() == grid[x][y].getValue() && !grid[x + i][y].isCombined())
                            {
                                // combines tiles
                                grid[x + i][y].doubleValue();
                                grid[x][y].deactivate();
                                i = 100;
                            }
                            else if (i != 1) // does not move if adjacent to the next active tile
                            {
                                // moves tile to the next empty space
                                grid[x + i - 1][y] = grid[x][y];
                                grid[x][y].deactivate();
                                i = 100;
                            }
                            else
                            {
                                // ends iteration without changing tile.
                                i = 100;
                            }
                        }
                        else if (x + i == 3)
                        {
                            // moves to the first empty space
                            grid[3][y] = grid[x][y];
                            grid[x][y].deactivate();
                            i = 100;
                        }
                    }
                }
            }
        }
    }
}

void handleInput(Tile grid[4][4], bool gameOver)
{
    bool validIn = false;
    char input;
    do // loops input until a valid input is selected
    {
        std::cout << "Q|quit\tw|up\ts|down\ta|left\td|right\n";
        cin >> input;

        switch (input)
        {
        case 'Q':
            validIn = true;
            gameOver = true;
            break;
        case 'w':
        case 's':
        case 'a':
        case 'd':
            validIn = true;
            moveTiles(grid, input);
            break;
        default:
            std::cout << "\tInvalid Input. Please try again.\n";
            break;
        }

    } while (!validIn);
}

void getInactiveTiles(int inactiveTiles[16][2], int &inactiveCount, Tile grid[4][4])
{
    for (int i = 0; i < 16; i++)
    {
        inactiveTiles[i][0] = 0;
        inactiveTiles[i][1] = 0;
    }

    for (int x = 0; x < 4; x++)
    {
        for (int y = 0; y < 4; y++)
        {
            if (!grid[x][y].isActive())
            {
                inactiveCount++;
                inactiveTiles[inactiveCount - 1][0] = x;
                inactiveTiles[inactiveCount - 1][1] = y;
            }
        }
    }
}

// the cpu response to the current board
void computeResponse(Tile grid[4][4], bool &gameOver, bool &gameWin, int turns)
{
    int inactiveCount = 0;
    int inactiveTiles[16][2];
    // Checks if there are no free squares

    getInactiveTiles(inactiveTiles, inactiveCount, grid);

    // sets a random inactive member of the grid to active
    if (inactiveCount > 0)
    {
        int rz = rand() % inactiveCount;
        grid[inactiveTiles[rz][0]][inactiveTiles[rz][1]].activate();
    }
    else
        gameOver = true;

    for (int x = 0; x < 4; x++)
    {
        for (int y = 0; y < 4; y++)
        {
            if (grid[x][y].getValue() == 2048)
            {
                gameWin = true;
            }
            grid[x][y].reset();
        }
    }
}

int main()
{
    srand(time(0));
    std::cout << "Can you get to 2048?\n";
    Tile grid[4][4];
    int turns = 0;
    bool gameOver = false;
    bool gameWin = false;

    // sets a random inactive member of the grid to active to initiate
    int rx = rand() % 4;
    int ry = rand() % 4;
    grid[rx][ry].activate();

    do
    {
        displayBox(grid);
        turns++;
        handleInput(grid, gameOver);
        computeResponse(grid, gameOver, gameWin, turns);
    } while (!gameOver && !gameWin);

    if (gameWin)
    {
        displayBox(grid);

        std::cout << "Congratulations! you did it in " << turns << " turns!\n";
    }
    else if (gameOver)
    {
        displayBox(grid);

        std::cout << "too bad so sad\n";
    }
    return 0;
}