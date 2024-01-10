#pragma once
#include <string>

using namespace std;

class Game2
{
private:
	bool arr[15][15];
	char output[16][16];
public:
	int revealCount;
	Game2();
	int getNumberByCharacter(char c);
	bool checkLocation(string command);
	void checkNeighBourLocation(string command);
	void displayArray();
	void displayOutput();
};

