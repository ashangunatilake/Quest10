//#include "globals.h"
#include "Game3.h"
#include <iostream>
#include <cstdlib>
#include <ctime>
#include <string>

using namespace std;

Game3::Game3()
{
	revealCount = 0;
	int i = 0;
	for (int i = 0; i < 20; i++)
	{
		for (int j = 0; j < 20; j++)
		{
			arr[i][j] = false;
		}
	}
	srand(static_cast<unsigned int>(time(nullptr)));
	while (i < 24)
	{
		int random_number1 = rand() % 10;
		int random_number2 = rand() % 10;
		if (arr[random_number1][random_number2] == false)
		{
			arr[random_number1][random_number2] = true;
			i++;
		}
	}
	for (int i = 0; i < 21; i++)
	{
		for (int j = 0; j < 21; j++)
		{
			output[i][j] = 'c';
		}
	}
}

void Game3::displayArray()
{
	for (int i = 0; i < 20; i++)
	{
		for (int j = 0; j < 20; j++)
		{
			cout << arr[i][j] << " ";
		}
		cout << endl;
	}
}

void Game3::displayOutput()
{
	char arrChar[] = { 'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J', 'K', 'L', 'M', 'N', 'O', 'P', 'Q', 'R', 'S', 'T' };
	int arrInt[] = { 0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19 };

	for (int i = 0; i < 20; i++)
	{
		output[0][i + 1] = arrChar[i];
		output[i + 1][0] = arrChar[i];
	}

	for (int i = 0; i < 21; i++)
	{
		for (int j = 0; j < 21; j++)
		{
			cout << output[i][j] << " ";
		}
		cout << endl;
	}
}


int Game3::getNumberByCharacter(char c)
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

bool Game3::checkLocation(string command)
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

void Game3::checkNeighBourLocation(string command)
{
	int bombCount = 0;
	int flagCount = 0;
	char rowC = command[0];
	char columnC = command[1];
	int row = getNumberByCharacter(rowC);
	int column = getNumberByCharacter(columnC);

	if (command[2] == 'F')
	{
		if (flagCount < 24)
		{
			output[row][column] = 'F';
			flagCount++;
		}
		else
		{
			cout << "All flags have been used!. Press Enter.";
			cin.get();
			cin.get();
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
			else if ((command[0] == 20) && (command[1] == 1))
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
			else if ((command[0] == 1) && (command[1] == 20))
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
			else if ((command[0] == 20) && (command[1] == 20))
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
			else if (command[0] == 20)
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
			else if (command[1] == 20)
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
			else if ((command[0] == 20) && (command[1] == 1))
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
			else if ((command[0] == 1) && (command[1] == 20))
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
			else if ((command[0] == 20) && (command[1] == 20))
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
			else if (command[0] == 20)
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
			else if (command[1] == 20)
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

void Game3::displayLostOutput()
{
	cout << "Game Over! Mines are shown using M" << endl;
	for (int i = 0; i < 20; i++)
	{
		for (int j = 0; j < 20; j++)
		{
			if (arr[i][j] == true)
			{
				output[i + 1][j + 1] = 'M';
			}
		}
	}
	displayOutput();
}
