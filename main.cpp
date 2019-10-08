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


void newgame()
{
	setTextColor(GREY);
	//delete console
	for (int x = 2; x <= WALL_RIGHT - 1; x++)
	{
		for (int y = 9; y <= WALL_DOWN-1; y++)
		{
			gotoXY(x, y);
			cout << " ";
		}
	}
	for (int i = 8; i <= WALL_DOWN; i++)
	{
		gotoXY(WALL_RIGHT / 2 + 2, i);
		cout << char(219);
	}
	//2players

	setTextColor(BLUE);
	for (int i = 10; i <= 15; i++)
	{
		gotoXY(10, i);
		cout << char(219);
	}
	for (int i = 15; i <= 20; i++)
	{
		gotoXY(50, i);
		cout << char(219);
	}
	setTextColor(DARK_RED);
	gotoXY(20, 15);
	cout << "O";
	setTextColor(GREEN);
	gotoXY(25, 25);
	cout << "2 PLAYERS";
	//1player

	setTextColor(BLUE);
	for (int i = 10; i <= 15; i++)
	{
		gotoXY(70, i);
		cout << char(219);
	}
	setTextColor(DARK_RED);
	for (int i = 15; i <= 20; i++)
	{
		gotoXY(110, i);
		cout << char(219);
	}
	setTextColor(DARK_RED);
	gotoXY(80, 15);
	cout << "O";
	gotoXY(85, 25);
	setTextColor(GREEN);
	cout << "1 PLAYER";
	getchar();
}
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

	for (int i = 14; i <= 22; i++)
	{
		gotoXY(45, i);
		cout << char(176);
		gotoXY(77, i);
		cout << char(176);
	}

	for (int i = 8; i <= 12; i++)
	{
		gotoXY(WALL_RIGHT / 2 + 2, i);
		cout << char(219);
	}
	for (int i = 24; i <= WALL_DOWN; i++)
	{
		gotoXY(WALL_RIGHT / 2 + 2, i);
		cout << char(219);
	}
	//
	//
	setTextColor(DARK_RED);
	for (int i = 10; i <= 15; i++)
	{
		gotoXY(10, i);
		cout << char(219);
	}
	for (int i = 15; i <= 20; i++)
	{
		gotoXY(110, i);
		cout << char(219);
	}
	setTextColor(GREY);
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
		fileTitle.getline(lineTemp, 255);
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

	int xBall = 20;
	int yBall = 10;
	bool flag = true;
	while (flag)
	{
		setTextColor(DARK_RED);
		gotoXY(70, curPosPointer);
		cout << "<<<";

		

		gotoXY(xBall, yBall);
		cout << "O";

		keyPressed = _getch();

		if (keyPressed == 'w' || keyPressed == 'W')
			if (curPosPointer != yNewgame)
			{
				gotoXY(xPointer, curPosPointer);
				cout << "   ";
				curPosPointer -= 2;
			}

		if (keyPressed == 's' || keyPressed == 'S')
			if (curPosPointer != yQuit)
			{
				gotoXY(xPointer, curPosPointer);
				cout << "   ";
				curPosPointer += 2;
			}
		if (int(keyPressed) == 13)
		{
			if (curPosPointer == yNewgame)
			{
				flag = false;
				newgame();
			}
		}
		if (keyPressed == 'e')
		{
			system("cls");
			break;

		}

	}

}
int main()
{

	draw();

	return 0;
}
