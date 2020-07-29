#include <iostream>
#include "GridParser.h"
using namespace std;

int main()
{


    Grid * gameGrid = GridParser::parse();
    int col1, row1, generationCount, result = 0;

    string ColRowGen;
    cout << "Enter col1, row1, generationCount" << endl;

    cin.ignore();
    getline(cin, ColRowGen);

    vector<string> splittedColRowGen = split(ColRowGen, ", ");

    col1 = stoi(splittedColRowGen[0]);
    row1 = stoi(splittedColRowGen[1]);
    generationCount = stoi(splittedColRowGen[2]);

    for(int i = 0; i <= generationCount; i++)
    {
		if(gameGrid -> getCell(row1,col1).getColor() == green)
		{
			result++;
		}

		gameGrid -> nextGeneration();
	}
	cout << "The cell on position ["<< col1 << ", " << row1 << "] becomes green " <<result << " times for " << generationCount << " generations" << endl;

	//cleaning up dynamic memory
	delete gameGrid;

	return 0;
}
