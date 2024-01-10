#pragma once
#include <string>

using namespace std;

class Game1
{
private:
	bool arr[10][10];
	char output[11][11];

public:
	int revealCount;
	Game1();
	int getNumberByCharacter(char c);
	bool checkLocation(string command);
	void checkNeighBourLocation1(string command);
	void displayArray();
	void displayOutput();
};

