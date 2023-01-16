#include <iostream>
#include <string>
#include <stdlib.h>
#include <ctime>

using namespace std;

class Tile {
    public:
    int value;
    Tile()
{    
    int x = rand() % 100;
    cout << x << endl;
    if (x < 50)
    {
        value = 2;
    }
    else if (x < 90){
        value = 4;
    }
    else{
        value = 8;
    }
};
    void doubleValue()
{
    value = value * 2;
};
};

void displayBox() {
    std :: cout << " ___ ___ ___ ___ \n"
                << "|   |   |   |   |\n"
                << " ___ ___ ___ ___ \n"
                << "|   |   |   |   |\n"
                << " ___ ___ ___ ___ \n"
                << "|   |   |   |   |\n"
                << " ___ ___ ___ ___ \n"
                << "|   |   |   |   |\n"
                << " ___ ___ ___ ___ \n";
}

int main() {
    srand(time(0));
    std :: cout << "Can you get to 2048?\n";
    displayBox();
    Tile Bob;
    std :: cout << Bob.value << "did it work?";

    return 0;
}
