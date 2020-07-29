#include <iostream>
#pragma once
#include "Grid.h"
using namespace std;


//Function that splits string into vector of string by delimeter
vector<string> split(const string& inputStr, const string& delimeter)
{
    vector<string> result;

    size_t found = inputStr.find(delimeter);
    size_t startIndex = 0;

    while(found != string::npos)
    {
        string temp(inputStr.begin()+startIndex, inputStr.begin()+found);
        result.push_back(temp);
        startIndex = found + delimeter.size();
        found = inputStr.find(delimeter, startIndex);
    }
    if(startIndex != inputStr.size())
        result.push_back(string(inputStr.begin()+startIndex, inputStr.end()));
    return result;
}

class GridParser
{
public:
	static Grid * parse()
	{
		int rows, columns;


        string WidthAndHeight;
        cout << "Enter width and height [width, height]" << endl;
        cout << "Width <= Height < 1000" << endl;
        getline(cin, WidthAndHeight);

        vector<string> splittedWH = split(WidthAndHeight, ", ");
        columns =  stoi(splittedWH[0]);
        rows = stoi(splittedWH[1]);

        if((columns > rows) || (columns > 999) || (columns < 2))
        {
            cout << "Width must be <= than height and in the interval [2,999]!" << endl;
            do
            {
                cout << "Enter new width" << endl;
                cin >> columns;
                if(columns >= 1000 || columns < 2)
                {
                    cout << "Width must be < 1000" << endl;
                }

            }while(columns <= 1 || columns >= 1000);
        }

        if(rows > 999 || rows < 2)
        {
            do
            {
                cout << "The height should in the interval [2,999]" << endl;
                cout << "Enter new height" << endl;
                cin >> rows;
                if(rows >= 1000 || rows < 2)
                {
                cout << "Width must be < 1000" << endl;
                }

            }while(rows <= 1 || rows >= 1000);
        }



		vector<vector<Cell>> matrix;
		string tempStrRows;

        cout << "Enter Generation Zero: " << endl;

        for(int i = 0; i < rows; i++)
        {
            for(int j = 0; j < columns; j++)
            {
                cin >> tempStrRows[j];
            }
            vector<Cell> row;
            char c;
            for(int k = 0; k < columns; k++)
            {
                c = tempStrRows[k];
                if(c=='1')
                    {
                        row.push_back(green);
                    }
                    else if(c=='0')
                    {
                        row.push_back(red);
                    }
                    else
                    {
					cout << "Invalid Input" << endl;
                    }

            }
                matrix.push_back(row);
        }
        Grid * result = new Grid(matrix);
        return result;
    }
};
