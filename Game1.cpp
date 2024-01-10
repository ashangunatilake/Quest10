#include "Game1.h"
#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>

using namespace std;

Game1::Game1()
{
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
	for (int i = 0; i < 10; i++)
	{
		for (int j = 0; j < 10; j++)
		{
			output[i][j] = 'c';
		}
	}
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
	for (int i = 0; i < 10; i++)
	{
		for (int j = 0; j < 10; j++)
		{
			cout << output[i][j] << " ";
		}
		cout << endl;
	}
}


int Game1::getNumberByCharacter(char c)
{
	int index;
	char arrChar[] = { 'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J', 'K', 'L', 'M', 'N', 'O', 'P', 'Q', 'R', 'S', 'T' };
	int arrInt[] = { 0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19 };

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

void Game1::checkNeighBourLocation1(string command)
{
	//bool arr3[3], arr5[5], arr8[8];

	int bombCount = 0;
	char rowC = command[0];
	char columnC = command[1];
	int row = getNumberByCharacter(rowC);
	int column = getNumberByCharacter(columnC);

	if (command[2] == 'F')
	{
		output[row][column] = 'F';
	}
	else if (command[2] == 'R')
	{
		if ((row == 0) && (column == 0))
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
				output[row][column] = '.';
			}
			else
			{
				output[row][column] = static_cast<char>(bombCount);
			}
			
		}
		else if ((command[0] == 9) && (command[1] == 0))
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
				output[row][column] = '.';
			}
			else
			{
				output[row][column] = static_cast<char>(bombCount);
			}
		}
		else if ((command[0] == 0) && (command[1] == 9))
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
				output[row][column] = '.';
			}
			else
			{
				output[row][column] = static_cast<char>(bombCount);
			}
		}
		else if ((command[0] == 9) && (command[1] == 9))
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
				output[row][column] = '.';
			}
			else
			{
				output[row][column] = static_cast<char>(bombCount);
			}
		}
		else if (command[0] == 0)
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
				output[row][column] = '.';
			}
			else
			{
				output[row][column] = static_cast<char>(bombCount);
			}
		}
		else if (command[1] == 0)
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
				output[row][column] = '.';
			}
			else
			{
				output[row][column] = static_cast<char>(bombCount);
			}
		}
		else if (command[0] == 9)
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
				output[row][column] = '.';
			}
			else
			{
				output[row][column] = static_cast<char>(bombCount);
			}
		}
		else if (command[1] == 9)
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
				output[row][column] = '.';
			}
			else
			{
				output[row][column] = static_cast<char>(bombCount);
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
				output[row][column] = '.';
			}
			else
			{
				cout << bombCount << endl;
				output[row][column] = char(bombCount + 48);
				cout << output[row][column] << endl;
			}
		}
	}

}