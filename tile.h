
#include <random>
using namespace std;
#pragma once

class Tile {
    public:
    int value;
    Tile()
{    
    int x = (rand() % 100) / 100;
    if (x < .51)
    {
        value = 2;
    }
    else if (x < .91){
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