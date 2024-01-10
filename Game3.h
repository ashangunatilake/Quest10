#pragma once
#include <string>

using namespace std;

class Game3
{
private:
	bool arr[20][20];
	char output[21][21];
public:
	int revealCount;
	Game3();
	int getNumberByCharacter(char c);
	bool checkLocation(string command);
	void checkNeighBourLocation(string command);
	void displayArray();
	void displayOutput();
};

