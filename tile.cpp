#include "tile.h"
using namespace std;


Tile::Tile()
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
}

void Tile::doubleValue()
{
    value = value * 2;
}