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
// INPUT:
// OUTPUT:
// Vong lap chinh cua game
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
		Sleep(50/game.getCount());

		setTextColor(DARK_YELLOW);
		ifstream fileTitle("pong.txt", ios::in | ios::out);
		int xTitle = SCREEN_RIGHT + 1;
		int yTitle = 0;
		while (!fileTitle.eof())
		{
			char lineTemp[255] = "";
			fileTitle.getline(lineTemp, 255);
			gotoXY(xTitle, yTitle);
			cout << lineTemp << endl;
			yTitle++;
		}
		

		setTextColor(DARK_CYAN);
		gotoXY(85, 10);
		cout << "W : up pad player 1";
		gotoXY(85, 11);
		cout << "S : down pad player 1";
		gotoXY(85, 13);
		cout << "UP : up pad player 2";
		gotoXY(85, 14);
		cout << "DOWN : up pad player 2";
		gotoXY(85, 16);
		cout << "TAB : switch between the mode";
		gotoXY(85, 17);
		cout << "N: new game";
		gotoXY(45, 15);
		game.removeBall();

		
		if (game.getIsPlayer2() == -1)
		{
			gotoXY(20, 22);
			cout << "                       ";
			gotoXY(20, 23);
			cout << "                       ";
			setTextColor(31); gotoXY(20, 22); cout << "Your Score:             " << game.getPlayersScore(); setTextColor(15);
			setTextColor(79); gotoXY(20, 23); cout << "Computers Score:        " << game.getComputersScore(); setTextColor(15);
		}
		else
		{
			gotoXY(20, 22);
			cout << "                        ";
			gotoXY(20, 23);
			cout << "                        ";
			setTextColor(31); gotoXY(20, 22); cout << "Player1 Score:          " << game.getPlayersScore(); setTextColor(15);
			setTextColor(79); gotoXY(20, 23); cout << "Player2 Score:          " << game.getComputersScore(); setTextColor(15);
		}
	}
}

//
// INPUT:
// OUTPUT:
// ve man hinh NEWGAME, goi cac ham tuong ung voi cac lua chon 1 PLAYER hoac 2 PLAYERS
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
				game.setIsPlayer2(1);
			}
			else game.setIsPlayer2(-1);
			drawPlay();
		}
		if (keyPressed == 'e' || int(keyPressed) == 27) //esc
		{
			system("cls");
			break;

		}

	}
}


// INPUT:
// OUTPUT:
// ve man hinh khoi dau cua game, goi cac ham tuong ung voi cac lua chon
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