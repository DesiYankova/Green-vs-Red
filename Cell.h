#include <iostream>
#pragma once
using namespace std;

//Enum type for possible colors or the cell
enum Color
{
    red,
    green,
};


//Describes a cell with specific color
class Cell
{
public:
    Cell(Color newColor);

    Color getColor()const;
    void setColor(Color newColor);


    char* getEnumString();

private:
    Color eColor;
};
