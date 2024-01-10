#include "globals.h"
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
}

void Game3::displayArray()
{
	for (int i = 1; i < 21; i++)
	{
		for (int j = 1; j < 21; j++)
		{
			cout << arr[i][j] << " ";
		}
		cout << endl;
	}
}

void Game3::displayOutput()
{
	for (int i = 1; i < 21; i++)
	{
		for (int j = 1; j < 21; j++)
		{
			cout << output[i][j] << " ";
		}
		cout << endl;
	}
	for (int i = 0; i < 20; i++)
	{
		output[0][i] = arrChar[i];
		output[i][0] = arrChar[i];
	}
}


int Game3::getNumberByCharacter(char c)
{
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
		revealCount++;
	}

}
