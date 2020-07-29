#include <iostream>
#pragma once
#include<vector>
#include "Cell.h"
using namespace std;

//This class models a two dimensional grid for the game Green vs Red
class Grid
{
public:
    Grid(vector<vector<Cell>> newMatrix);

    Cell getCell(int row,int column);
    Color getCellColor(int row, int column);

    bool IsValidCell(const int x, const int y) const;

    //Returns the count of the green neighbors of the cell in the specified row and column
    int getGreenCellNeighborCount(int row,int column);

    //Changes the colors of the cells in the array as if one generation has passed
	void nextGeneration();

    void print();

private:
    vector<vector<Cell>> matrix;
    int rowCount;
	int columnCount;
};
