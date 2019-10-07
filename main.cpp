#include "iostream"
#include "windows.h"
#include "fstream"
#include "stdlib.h"
#include "conio.h"
#include "string"
#include "functionConsole.h"

using namespace std;

#define WALL_UP    0
#define WALL_RIGHT 118
#define WALL_LEFT  0
#define WALL_DOWN  29

#define xPointer 70
#define yPointer 15

#define xNewgame 55
#define yNewgame 15

#define xLoadgame 55
#define yLoadgame 17

#define xAbout 55
#define yAbout 19

#define xQuit 55
#define yQuit 21

void draw()
{
	setTextColor(GREY);
	//
	//
	for (int i = WALL_UP; i <= WALL_DOWN; i++)
	{
		gotoXY(WALL_LEFT, i);
		cout << char(219) << char(219);

		gotoXY(WALL_RIGHT, i);
		cout << char(219) << char(219);
	}

	for (int i = WALL_LEFT; i <= WALL_RIGHT; i++)
	{
		gotoXY(i, WALL_UP);
		cout << char(219);
		gotoXY(i, WALL_DOWN);

		cout << char(219);
	}

	for (int i = WALL_LEFT; i <= WALL_RIGHT; i++)
	{
		gotoXY(i, 8);
		cout << char(219);
	}

	for (int i = 45; i <= 77; i++)
	{
		gotoXY(i, 13);
		cout << char(176);

		gotoXY(i, 23);
		cout << char(176);
	}

	for (int i = 14; i <= 22;i++)
	{
		gotoXY(45, i);
		cout << char(176);
		gotoXY(77, i);
		cout << char(176);
	}
	//
	//

	noCursorType();
	FixConsoleWindow();

	ifstream fileTitle("pong.txt", ios::in | ios::out);

	int xTitle = 40;
	int yTitle = 0;
	setTextColor(DARK_YELLOW);

	while (!fileTitle.eof())
	{
		char lineTemp[255] = "";
		fileTitle.getline(lineTemp,255);
		gotoXY(xTitle, yTitle);
		cout << lineTemp << endl;
		yTitle++;
	}
	//
	//
	setTextColor(CYAN);
	gotoXY(xNewgame, yNewgame);
	cout << "NEW GAME";
	setTextColor(PINK);
	gotoXY(xLoadgame, yLoadgame);
	cout << "LOAD GAME";
	setTextColor(GREEN);
	gotoXY(xAbout, yAbout);
	cout << "ABOUT";
	setTextColor(RED);
	gotoXY(xQuit, yQuit);
	cout << "QUIT";
	//
	int  curPosPointer = yPointer;
	char keyPressed;

	while (true)
	{
		setTextColor(DARK_RED);
		gotoXY(70, curPosPointer);
		cout << "<<<";

		keyPressed = _getch();

		if (keyPressed == 'w' || keyPressed == 'W')
			if (curPosPointer != yNewgame)
			{
				gotoXY(xPointer, curPosPointer);
				cout << "   ";
				curPosPointer -=2;
			}

		if (keyPressed == 's' || keyPressed == 'S')
			if (curPosPointer != yQuit)
			{
				gotoXY(xPointer, curPosPointer);
				cout << "   ";
				curPosPointer +=2;
			}

		if (keyPressed == 'e')
			break;
		{
			system("cls");
		}

	}
	
}
void drawPlay()
{

}
int main()
{

	draw();

	return 0;
}
