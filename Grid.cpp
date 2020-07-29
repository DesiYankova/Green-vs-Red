#include "Grid.h"
#include <cstring>

Grid::Grid(vector<vector<Cell>> newMatrix)
{
    matrix = newMatrix;
    rowCount = newMatrix.size();
    columnCount = newMatrix[0].size();
}

Cell Grid::getCell(int row,int column)
{
    return matrix[row][column];
}

//Check if the coordinates (x, y) are valid coordinates of a cell in the grid
Color Grid::getCellColor(int row, int column)
{
    return matrix[row][column].getColor();
}

//Check if the cell is valid
bool Grid::IsValidCell(const int x, const int y) const
{
	return x >= 0 && x < columnCount && y >= 0 && y < rowCount;
}

int Grid::getGreenCellNeighborCount(int rowY,int columnX)
{
    size_t greenCount = 0;

	//Check each of the possible neighbours
	for (int row = -1; row <= 1; row++)
	{
		for (int col = -1; col <= 1; col++)
		{
		    //Skipping the specific cell with coordinates(columnX, rowY)
			if (row == 0 && col == 0)
			{
				continue;
			}

			//We check if the cell is valid.
            //The cells in the corners have 3 neighbors, and those on the sides that are not in the corner have 5 neighbors.
            //All other cells have 8 neighbors
			if (IsValidCell(columnX + col, rowY + row))
			{
				if(matrix[rowY + row][columnX + col].getColor() == green)
				{
					greenCount++;
				}
			}
		}
	}

	return greenCount;
}

//Generate next generation
void Grid::nextGeneration()
{
    vector<vector<Cell>> nextGen = matrix;

    for(int i=0;i<rowCount;i++)
    {
        for(int j=0;j<columnCount;j++)
        {
            if(nextGen[i][j].getColor() == green)
            {
                switch(getGreenCellNeighborCount(i,j))
                {
                    case 0:
                    case 1:
                    case 4:
                    case 5:
                    case 7:
                    case 8:
                        nextGen[i][j].setColor(red);
                        break;
                    case 2:
                    case 3:
                    case 6:
                        //do nothing
                        break;
                }
            }
            //red
            else
            {
                switch(getGreenCellNeighborCount(i,j))
                {
                    case 3:
                    case 6:
                        nextGen[i][j].setColor(green);
                    case 0:
                    case 1:
                    case 2:
                    case 4:
                    case 5:
                    case 7:
                    case 8:
                        //do nothing
                        break;
                }
            }
        }
    }
    matrix = nextGen;
}

void Grid::print()
{
    for(int i = 0;i < rowCount; i++)
    {
        for(int j = 0;j < columnCount; j++)
        {
            cout << matrix[i][j].getColor();
        }
        cout << endl;
    }
}
