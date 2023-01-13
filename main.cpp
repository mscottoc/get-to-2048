#include <iostream>
#include <string>


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
    std :: cout << "Can you get to 2048?\n";
    displayBox();
    return 0;
}
