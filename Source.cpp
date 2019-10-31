#include "iostream"
#include "Game.h"
#include "fstream"
#include "stdlib.h"
#include "string"
#include "windows.h"
#include "conio.h"
#include "constant.h"
#include "functionConsole.h"

using namespace std;

Game game;
void draw();

void drawPlay()
{
	game.clrscr();
	game.initGame();

	char keyPressed;
	keyPressed = _getch();
	while (keyPressed != key_ESCAPE)
	{
		game.Keypressed();
		game.gameLogic();
		game.moveBall();
		Sleep(50/game.count);
		gotoXY(85, 10);
		cout << "UP : up pad player 1";
		gotoXY(85, 11);
		cout << "DOWN : down pad player 1";
		gotoXY(85, 12);
		cout << "W : up pad player 2";
		gotoXY(85, 13);
		cout << "S : up pad player 2";
		gotoXY(85, 14);
		cout << "TAB : switch between the mode";
		gotoXY(45, 15);
		game.removeBall();
		setTextColor(31); gotoXY(7, 22); cout << "ball  X=%d,Y=%d " << game.ball.x << game.ball.y; setTextColor(15);
		setTextColor(31); gotoXY(7, 23); cout << "pad   X=%d,Y=%d " << game.PlayersPad.x << game.PlayersPad.y; setTextColor(15);
		setTextColor(31); gotoXY(32, 22); cout << "Your Score:       %d " << game.playersScore; setTextColor(15);
		setTextColor(79); gotoXY(32, 23); cout << "Computers Score:  %d " << game.computersScore; setTextColor(15);
	}
}
void newgame()
{
	setTextColor(GREY);
	//delete console
	for (int x = 2; x <= WALL_RIGHT - 1; x++)
	{
		for (int y = 9; y <= WALL_DOWN - 1; y++)
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
	setTextColor(WHITE);
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
	setTextColor(WHITE);
	gotoXY(80, 15);
	cout << "O";
	gotoXY(85, 25);
	setTextColor(GREEN);
	cout << "1 PLAYER";
	int curPosPointer = 100;
	while (true)
	{
		setTextColor(DARK_RED);
		gotoXY(curPosPointer, 25);
		cout << "<<<";

		char keyPressed = _getch();

		if (keyPressed == 'a' || keyPressed == 'A' || int(keyPressed) == 75) //left
		{
			curPosPointer = 40;
			gotoXY(100, 25);
			cout << "   ";
		}

		if (keyPressed == 'd' || keyPressed == 'D' || int(keyPressed) == 77) //right
		{
			curPosPointer = 100;
			gotoXY(40, 25);
			cout << "   ";
		}
		if (int(keyPressed) == 13)  //enter
		{
			if (curPosPointer == 40) {
				game.isPlayer2 = 1;
			}
			else game.isPlayer2 = -1;
			drawPlay();
		}
		if (keyPressed == 'e' || int(keyPressed) == 27) //esc
		{
			system("cls");
			break;

		}

	}
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
	setTextColor(BLUE);
	for (int i = 10; i <= 15; i++)
	{
		gotoXY(10, i);
		cout << char(219);
	}
	setTextColor(DARK_RED);
	for (int i = 15; i <= 20; i++)
	{
		gotoXY(110, i);
		cout << char(219);
	}

	setTextColor(WHITE);
	gotoXY(20, 10);
	cout << "O";
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
	setTextColor(RED);
	gotoXY(xQuit, yQuit);
	cout << "QUIT";
	//
	int  curPosPointer = yPointer;
	char keyPressed;


	bool flag = true;
	bool choose = true;
	while (flag)
	{
		if (choose == true)
		{
			setTextColor(DARK_RED);
			gotoXY(70, curPosPointer);
			cout << "<<<";
		}


		keyPressed = _getch();

		if (keyPressed == 'w' || keyPressed == 'W' || int(keyPressed) == 72) //up
			if (curPosPointer != yNewgame)
			{
				gotoXY(xPointer, curPosPointer);
				cout << "   ";
				curPosPointer -= 2;
			}

		if (keyPressed == 's' || keyPressed == 'S' || int(keyPressed) == 80) //down
			if (curPosPointer != yQuit)
			{
				gotoXY(xPointer, curPosPointer);
				cout << "   ";
				curPosPointer += 2;
			}
		if (int(keyPressed) == 13)  //enter
		{
			if (curPosPointer == yNewgame)
			{
				flag = false;
				newgame();
			}
			if (curPosPointer == yLoadgame) {}
			if (curPosPointer == yQuit) 
			{
				system("cls");
				break;
			}
		}
		if (int(keyPressed) == 27) //esc
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