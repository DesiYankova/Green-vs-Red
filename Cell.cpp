#include "Cell.h"


Cell::Cell(Color newColor)
{
    eColor = newColor;
}

Color Cell::getColor()const
{
    return eColor;
}

void Cell::setColor(Color newColor)
{
    eColor = newColor;
}

char* Cell::getEnumString()
{
    switch(eColor)
    {
    case green:
        return "green";
        break;
    case red:
        return "red";
        break;
    }
}
