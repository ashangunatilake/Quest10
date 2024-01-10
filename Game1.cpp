#include "Game1.h"
#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>

using namespace std;

Game1::Game1()
{
	revealCount = 0;
	int i = 0;
	for (int i = 0; i < 10; i++)
	{
		for (int j = 0; j < 10; j++)
		{
			arr[i][j] = false;

		}
	}
	srand(static_cast<unsigned int>(time(nullptr)));
	while (i < 12)
	{
		int random_number1 = rand() % 10;
		int random_number2 = rand() % 10;
		if (arr[random_number1][random_number2] == false)
		{
			arr[random_number1][random_number2] = true;
			i++;
		}
	}
	for (int i = 0; i < 11; i++)
	{
		for (int j = 0; j < 11; j++)
		{
			output[i][j] = 'c';
		}
	}
	output[0][0] = ' ';
}

void Game1::displayArray()
{
	for (int i = 0; i < 10; i++)
	{
		for (int j = 0; j < 10; j++)
		{
			cout << arr[i][j] << " ";
		}
		cout << endl;
	}
}


void Game1::displayOutput()
{
	char arrChar[] = { 'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J', 'K', 'L', 'M', 'N', 'O', 'P', 'Q', 'R', 'S', 'T' };

	for (int i = 0; i < 10; i++)
	{
		output[0][i + 1] = arrChar[i];
		output[i + 1][0] = arrChar[i];
	}

	for (int i = 0; i < 11; i++)
	{
		for (int j = 0; j < 11; j++)
		{
			cout << output[i][j] << " ";
		}
		cout << endl;
	}
}

//J.U.P. Jayalath
//21_ENG_047
int Game1::getNumberByCharacter(char c)
{
	char arrChar[] = { 'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J', 'K', 'L', 'M', 'N', 'O', 'P', 'Q', 'R', 'S', 'T' };
	int arrInt[] = { 0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19 };

	int index;
	for (int i = 0; i < 20; i++)
	{
		if (c == arrChar[i])
		{
			index = i;
			break;
		}
	}
	return arrInt[index];
}

//J.U.P. Jayalath
//21_ENG_047
bool Game1::checkLocation(string command)
{
	char rowC = command[0];
	char columnC = command[1];
	int row = getNumberByCharacter(rowC);
	int column = getNumberByCharacter(columnC);

	if (arr[row][column] == true)
	{
		return true;
	}
	else
	{
		return false;
	}
}

//J.U.P. Jayalath
//21_ENG_047
void Game1::checkNeighBourLocation(string command)
{
	int bombCount = 0;
	int flagCount = 0;
	char rowC = command[0];
	char columnC = command[1];
	int row = getNumberByCharacter(rowC);
	int column = getNumberByCharacter(columnC);

	if (command[2] == 'F')
	{
		if (flagCount < 12)
		{
			output[row + 1][column + 1] = 'F';
			flagCount++;
		}
		else
		{
			cout << "All flags have been used!";
		}
	}
	else if (command[2] == 'R')
	{
		if (arr[row][column] == 'F')
		{
			if ((row == 1) && (column == 1))
			{
				bool arr3[] = { arr[row][column + 1], arr[row + 1][column + 1], arr[row + 1][column] };
				for (int element : arr3)
				{
					if (element == true)
					{
						bombCount++;
					}
				}
				if (bombCount == 0)
				{
					output[row + 1][column + 1] = '.';
				}
				else
				{
					output[row + 1][column + 1] = char(bombCount + 48);;
				}

			}
			else if ((command[0] == 10) && (command[1] == 1))
			{
				bool arr3[] = { arr[row - 1][column], arr[row][column + 1], arr[row - 1][column + 1] };
				for (int element : arr3)
				{
					if (element == true)
					{
						bombCount++;
					}
				}
				if (bombCount == 0)
				{
					output[row + 1][column + 1] = '.';
				}
				else
				{
					output[row + 1][column + 1] = char(bombCount + 48);
				}
			}
			else if ((command[0] == 1) && (command[1] == 10))
			{
				bool arr3[] = { arr[row][column - 1], arr[row + 1][column - 1], arr[row + 1][column] };
				for (int element : arr3)
				{
					if (element == true)
					{
						bombCount++;
					}
				}
				if (bombCount == 0)
				{
					output[row + 1][column + 1] = '.';
				}
				else
				{
					output[row + 1][column + 1] = char(bombCount + 48);
				}
			}
			else if ((command[0] == 10) && (command[1] == 10))
			{
				bool arr3[] = { arr[row][column - 1], arr[row - 1][column - 1], arr[row][column - 1] };
				for (int element : arr3)
				{
					if (element == true)
					{
						bombCount++;
					}
				}
				if (bombCount == 0)
				{
					output[row + 1][column + 1] = '.';
				}
				else
				{
					output[row + 1][column + 1] = char(bombCount + 48);
				}
			}
			else if (command[0] == 1)
			{
				bool arr5[] = { arr[row][column - 1], arr[row][column + 1], arr[row + 1][column - 1], arr[row + 1][column + 1], arr[row + 1][column] };
				for (int element : arr5)
				{
					if (element == true)
					{
						bombCount++;
					}
				}
				if (bombCount == 0)
				{
					output[row + 1][column + 1] = '.';
				}
				else
				{
					output[row + 1][column + 1] = char(bombCount + 48);
				}
			}
			else if (command[1] == 1)
			{
				bool arr5[] = { arr[row - 1][column], arr[row + 1][column], arr[row - 1][column + 1], arr[row + 1][column + 1], arr[row][column + 1] };
				for (int element : arr5)
				{
					if (element == true)
					{
						bombCount++;
					}
				}
				if (bombCount == 0)
				{
					output[row + 1][column] = '.';
				}
				else
				{
					output[row + 1][column + 1] = char(bombCount + 48);
				}
			}
			else if (command[0] == 10)
			{
				bool arr5[] = { arr[row][column - 1], arr[row][column + 1], arr[row - 1][column - 1], arr[row - 1][column], arr[row - 1][column + 1] };
				for (int element : arr5)
				{
					if (element == true)
					{
						bombCount++;
					}
				}
				if (bombCount == 0)
				{
					output[row + 1][column + 1] = '.';
				}
				else
				{
					output[row + 1][column + 1] = char(bombCount + 48);
				}
			}
			else if (command[1] == 10)
			{
				bool arr5[] = { arr[row - 1][column], arr[row + 1][column], arr[row - 1][column - 1], arr[row][column - 1], arr[row + 1][column - 1] };
				for (int element : arr5)
				{
					if (element == true)
					{
						bombCount++;
					}
				}
				if (bombCount == 0)
				{
					output[row + 1][column + 1] = '.';
				}
				else
				{
					output[row + 1][column + 1] = char(bombCount + 48);
				}
			}
			else
			{
				bool arr8[] = { arr[row - 1][column], arr[row + 1][column], arr[row][column - 1], arr[row][column + 1], arr[row - 1][column - 1], arr[row - 1][column + 1], arr[row + 1][column - 1], arr[row + 1][column + 1] };
				for (int element : arr8)
				{
					if (element == true)
					{
						bombCount++;
					}
				}
				if (bombCount == 0)
				{
					output[row + 1][column + 1] = '.';
				}
				else
				{
					output[row + 1][column + 1] = char(bombCount + 48);
				}
			}
			flagCount--;
		}
		else
		{
			if ((row == 1) && (column == 1))
			{
				bool arr3[] = { arr[row][column + 1], arr[row + 1][column + 1], arr[row + 1][column] };
				for (int element : arr3)
				{
					if (element == true)
					{
						bombCount++;
					}
				}
				if (bombCount == 0)
				{
					output[row + 1][column + 1] = '.';
				}
				else
				{
					output[row + 1][column + 1] = char(bombCount + 48);;
				}

			}
			else if ((command[0] == 10) && (command[1] == 1))
			{
				bool arr3[] = { arr[row - 1][column], arr[row][column + 1], arr[row - 1][column + 1] };
				for (int element : arr3)
				{
					if (element == true)
					{
						bombCount++;
					}
				}
				if (bombCount == 0)
				{
					output[row + 1][column + 1] = '.';
				}
				else
				{
					output[row + 1][column + 1] = char(bombCount + 48);
				}
			}
			else if ((command[0] == 1) && (command[1] == 10))
			{
				bool arr3[] = { arr[row][column - 1], arr[row + 1][column - 1], arr[row + 1][column] };
				for (int element : arr3)
				{
					if (element == true)
					{
						bombCount++;
					}
				}
				if (bombCount == 0)
				{
					output[row + 1][column + 1] = '.';
				}
				else
				{
					output[row + 1][column + 1] = char(bombCount + 48);
				}
			}
			else if ((command[0] == 10) && (command[1] == 10))
			{
				bool arr3[] = { arr[row][column - 1], arr[row - 1][column - 1], arr[row][column - 1] };
				for (int element : arr3)
				{
					if (element == true)
					{
						bombCount++;
					}
				}
				if (bombCount == 0)
				{
					output[row + 1][column + 1] = '.';
				}
				else
				{
					output[row + 1][column + 1] = char(bombCount + 48);
				}
			}
			else if (command[0] == 1)
			{
				bool arr5[] = { arr[row][column - 1], arr[row][column + 1], arr[row + 1][column - 1], arr[row + 1][column + 1], arr[row + 1][column] };
				for (int element : arr5)
				{
					if (element == true)
					{
						bombCount++;
					}
				}
				if (bombCount == 0)
				{
					output[row + 1][column + 1] = '.';
				}
				else
				{
					output[row + 1][column + 1] = char(bombCount + 48);
				}
			}
			else if (command[1] == 1)
			{
				bool arr5[] = { arr[row - 1][column], arr[row + 1][column], arr[row - 1][column + 1], arr[row + 1][column + 1], arr[row][column + 1] };
				for (int element : arr5)
				{
					if (element == true)
					{
						bombCount++;
					}
				}
				if (bombCount == 0)
				{
					output[row + 1][column] = '.';
				}
				else
				{
					output[row + 1][column + 1] = char(bombCount + 48);
				}
			}
			else if (command[0] == 10)
			{
				bool arr5[] = { arr[row][column - 1], arr[row][column + 1], arr[row - 1][column - 1], arr[row - 1][column], arr[row - 1][column + 1] };
				for (int element : arr5)
				{
					if (element == true)
					{
						bombCount++;
					}
				}
				if (bombCount == 0)
				{
					output[row + 1][column + 1] = '.';
				}
				else
				{
					output[row + 1][column + 1] = char(bombCount + 48);
				}
			}
			else if (command[1] == 10)
			{
				bool arr5[] = { arr[row - 1][column], arr[row + 1][column], arr[row - 1][column - 1], arr[row][column - 1], arr[row + 1][column - 1] };
				for (int element : arr5)
				{
					if (element == true)
					{
						bombCount++;
					}
				}
				if (bombCount == 0)
				{
					output[row + 1][column + 1] = '.';
				}
				else
				{
					output[row + 1][column + 1] = char(bombCount + 48);
				}
			}
			else
			{
				bool arr8[] = { arr[row - 1][column], arr[row + 1][column], arr[row][column - 1], arr[row][column + 1], arr[row - 1][column - 1], arr[row - 1][column + 1], arr[row + 1][column - 1], arr[row + 1][column + 1] };
				for (int element : arr8)
				{
					if (element == true)
					{
						bombCount++;
					}
				}
				if (bombCount == 0)
				{
					output[row + 1][column + 1] = '.';
				}
				else
				{
					output[row + 1][column + 1] = char(bombCount + 48);
				}
			}
		}
		revealCount++;
	}

}

void Game1::displayLostOutput()
{
	cout << "Game Over! Mines are shown using M." << endl;
	for (int i = 0; i < 10; i++)
	{
		for (int j = 0; j < 10; j++)
		{
			if (arr[i][j] == true)
			{
				output[i + 1][j + 1] = 'M';
			}
		}
	}
	displayOutput();
}