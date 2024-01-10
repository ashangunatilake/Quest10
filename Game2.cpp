#include "Game2.h"
#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

Game2::Game2()
{
	int i = 0;
	for (int i = 0; i < 15; i++)
	{
		for (int j = 0; j < 15; j++)
		{
			gameArray[i][j] = false;
		}
	}
	srand(static_cast<unsigned int>(time(nullptr)));
	while (i < 18)
	{
		int random_number1 = rand() % 10;
		int random_number2 = rand() % 10;
		if (gameArray[random_number1][random_number2] == false)
		{
			gameArray[random_number1][random_number2] = true;
			i++;
		}
	}
}

