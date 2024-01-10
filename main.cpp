#include <iostream>
#include <string.h>
#include "Game1.h"
#include "Game2.h"
#include "Game3.h"
using namespace std;

void helpUser();


int fieldSize;
bool play = true;

int getFieldSize()
{
    //L.D.K.Liyanaarachchi 
    //21_ENG_068
    int field=0;
    string fieldString;

    cout << "-------------------------------------------------" << endl;
    cout << "\t\tMine Sweeper Game" << endl;
    cout << "-------------------------------------------------\n\n" << endl;

    cout << "Field Option       Size(grid size)      No. of Mines" << endl;
    cout << "1                  10-by-10             12" << endl;
    cout << "2                  15-by-15             18" << endl;
    cout << "3                  20-by-20             24\n\n" << endl;
    while (true)
    {
        cout << "Select the Field : ";
        cin >> fieldString;
        if( (fieldString != "1") && (fieldString != "3") && (fieldString != "2"))
        {
            cout << "Error! " << endl;
            
        }
        else
        {
            break;
        }
    }
    cout << "\n" << endl;
    field = int(fieldString[0])-48;
    cout << "field "<<field << endl;
    return field;
}

void helpUser()
{
    //L.D.K.Liyanaarachchi 
    //21_ENG_068
    cout << "user can enter three letters in <row letter><column letter><commannd>\n " << endl;
    cout << "\tRow letter-- This is from A, B, and etc." << endl;
    cout << "\tColumn letter - This is also from A, B, and etc." << endl;
    cout << "\tCommand-\n\t\tF - place a flag on the location\n\t\tR - reveal the uncovered location.\n\n" << endl;
    
}

string getInput()
{
    //L.D.K.Liyanaarachchi 
    //21_ENG_068
    string input;
    int error = 0;

    cout << "\nEnter the input : ";
    cin >> input;
    if (input.length()!= 3)
    {
        cout << "Error! " << endl;
        getInput();
    }
    char row = input[0];
    char colum = input[1];
    char command = input[2];

    //character convert to int
    int rowInt = int(row);
    int columInt = int(colum);

    if (rowInt > 96)
    {
        rowInt = rowInt - 32;
    }
   // cout << "row int" << rowInt << endl;

    if (columInt > 96)
    {
        columInt = columInt - 32;
    }
    //cout << "colum int" << columInt << endl;

    if ((command != 'F') and (command != 'f') and (command != 'R') and (command != 'r'))
    {
        error++;
    }
    //cout << "field size" << fieldSize;
    int max;
    if (fieldSize == 1)
    {
        max = 74;//106
    }
    else if (fieldSize == 2)
    {
        max = 79;//111
    }
    else
    {
        max = 84;//116
    }
    //cout << "max" << max << endl;

    //cheack row numbers
    if (max < rowInt)
    {
        error++;
        //cout << "row error!" << endl;
    }
    //cheack colum numbers
    if (max < columInt)
    {
        error++;
       // cout << "colum error" << endl;
    }

    //return walue
    if (error == 0)
    {
        return input;
     }
    else
    {
        cout << "Error! " << endl;
        getInput();
    }   
}


int main()
{
  
   fieldSize= getFieldSize();
   helpUser();
   if (fieldSize == 1)
   {
       string command;
       Game1 game;
       game.displayArray();
       while (play)
       {
           system("CLS");
           game.displayArray();
           game.displayOutput();
           helpUser();
           command = getInput();
           if (game.checkLocation(command) && command[2] == 'R')
           {
               play = false;
               system("CLS");
               game.displayLostOutput();
               break;
           }
           else
           {
               game.checkNeighBourLocation(command);
           }
       }
   }

   if (fieldSize == 2)
   {
       string command;
       Game2 game;
       game.displayArray();
       while (play)
       {
           system("CLS");
           game.displayArray();
           game.displayOutput();
           helpUser();
           command = getInput();
           if (game.checkLocation(command) && command[2] == 'R')
           {
               play = false;
               system("CLS");
               game.displayLostOutput();
               break;
           }
           else
           {
               game.checkNeighBourLocation(command);
           }
       }
   }

   if (fieldSize == 3)
   {
       string command;
       Game3 game;
       //game.displayArray();
       while (play)
       {
           system("CLS");
           game.displayArray();
           game.displayOutput();
           helpUser();
           command = getInput();
           if (game.checkLocation(command) && command[2] == 'R')
           {
               play = false;
               system("CLS");
               game.displayLostOutput();
               break;
           }
           else
           {
               game.checkNeighBourLocation(command);
           }
       }
   }
   return 0;
}