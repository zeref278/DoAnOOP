#include "Game.h"
#include "structBall.h"
#include "structPad.h"
#include "windows.h"
#include "stdio.h"
#include "stdlib.h"
#include "conio.h"
#include "time.h"
#include "iostream"
#include "math.h"
#include "fstream"
#include "constant.h"
#include "functionConsole.h"

using namespace std;



Game::Game()
{
}
Game::~Game()
{
}

// INPUT:
// OUTPUT:
// Di chuyen ball
void Game::moveBall()
{
	txtPlot(ball.x, ball.y, DARK_YELLOW);
	txtLine(PlayersPad.x, PlayersPad.y, PlayersPad.x, PlayersPad.y + 3, DARK_BLUE);
	txtLine(computersPad.x, computersPad.y, computersPad.x, computersPad.y + 3, DARK_RED);
}

//
// INPUT:
// OUTPUT:
// xoa ball cu
void Game::removeBall()
{
	txtPlot(ball.x, ball.y, 0);
	txtLine(PlayersPad.x, PlayersPad.y, PlayersPad.x, PlayersPad.y + 3, 0);
	txtLine(computersPad.x, computersPad.y, computersPad.x, computersPad.y + 3, 0);
}

//
// INPUT:
// OUTPUT:
// Kiem tra game da ket thuc chua, xu li thang thua
void Game::gameLogic()
{
	
	ball.x += ball.headingX;      //Cap nhat vi tri cua ball
	ball.y += ball.headingY;



	//Kiem tra xem ball da cham tuong tren hoac duoi chua, neu co thi dao nguoc headingY
	if ((ball.y < SCREEN_TOP) || (ball.y > SCREEN_BOTTOM - 2)) 
		ball.headingY = -ball.headingY;

	PlayersPad.LEFT = PlayersPad.y - 3;
	PlayersPad.RIGHT = PlayersPad.y + 5;
	computersPad.LEFT = computersPad.y - 3;
	computersPad.RIGHT = computersPad.y + 5;

	//Kiem tra su va cham cua ball va pad
	if ((ball.y >= PlayersPad.LEFT) && (ball.y <= PlayersPad.RIGHT) && (ball.x == PlayersPad.x))
	{

		ball.headingX = -ball.headingX;
		playersScore += 10;
		count /= 0.9;
	}

	if ((ball.y >= computersPad.LEFT) && (ball.y <= computersPad.RIGHT) && (ball.x == computersPad.x))
	{

		ball.headingX = -ball.headingX;
		computersScore += 10;
	}

	/* if cheat enabled,let player track ball's movement */
	if (isPlayer2 < 0)
	{
		/* let computer track ball's movement */
		if (ball.x > SCREEN_RIGHT - 18) computersPad.y = ball.y;
		if ((ball.x > SCREEN_RIGHT))
		{
			ball.headingX = -ball.headingX;
			computersScore += 10;
		}
	}


	//Kiem tra neu ball khong cham pad
	if (ball.x < SCREEN_LEFT)
	{
		displayYouMissed();
		ball.x = 75;
		ball.y = 15;
		computersScore += 10;

	}
	if (ball.x > SCREEN_RIGHT + 1)
	{
	
		displayYouMissed();
		ball.x = 15;
		ball.y = 15;
		playersScore += 10;
	}
}

// INPUT:
// OUTPUT:
// Khoi tao gia tri mac dinh cho cac bien trong tro choi
void  Game::initGame()
{

	playersScore = 0;
	computersScore = 0;
	ball.x = 15;
	ball.y = 5;
	ball.headingX = 1;
	ball.headingY = 1;
	count = 1;

	PlayersPad.x = 5;
	PlayersPad.y = 12;
	computersPad.x = 75;
	computersPad.y = 12;

	//displayCheatEnabled();

	setTextColor(15);
	clrscr();
	txtLine(6, 0, 74, 0, GREY);
	txtLine(6, 22, 74, 22, GREY);
	txtLine(6, 23, 74, 23, GREY);


	if (isPlayer2 > 0)
	{
		setTextColor(79); gotoXY(62, 23); cout << " 2 Player "; setTextColor(15);
	}
	else
	{
		setTextColor(79); gotoXY(62, 23);  cout << " 1 Player "; setTextColor(15);
	}

}

//
// INPUT:
// OUTPUT:
// Xu li thua
void Game::displayYouMissed()
{
	clrbox(10, 8, 70, 16, 79);
	char a[] = "You missed";
	box(10, 8, 70, 16, a);

	gotoXY(18, 10); cout << " ";
	gotoXY(18, 11); cout << "The ball has missed the paddle";
	gotoXY(18, 12); cout << "Press SPACE to EXIT";
	gotoXY(18, 13); cout << "Press any key to CONTINUE";
	gotoXY(18, 14); cout << "";
	keypressed = _getch();
	if (keypressed == key_SPACE)
	{
		clrbox(10, 8, 70, 16, 79);

		clrscr();
		exit(0);
	}
	clrbox(10, 8, 75, 21, 0);


}

// INPUT: 
// OUTPUT: 
// Xu li cac phim nhap vao tuong ung voi cac chuc nang
void Game::Keypressed()
{
	if (_kbhit())
	{
		keypressed = _getch();
		switch (keypressed)
		{

		case key_LEFT:

			break;

		case key_RIGHT:

			break;

		case key_UP:
			computersPad.y -= 3; if (computersPad.y < 0)computersPad.y = 0;
			break;

		case key_DOWN:
			computersPad.y += 3; if (computersPad.y > 18) computersPad.y = 18;
			break;

		case key_w:
			PlayersPad.y -= 3; if (PlayersPad.y < 0) PlayersPad.y = 0;
			break;

		case key_s:
			PlayersPad.y += 3; if (PlayersPad.y > 18) PlayersPad.y = 18;
			break;

		case key_W:
			PlayersPad.y -= 3; if (PlayersPad.y < 0) PlayersPad.y = 0;
			break;

		case key_S:
			PlayersPad.y += 3; if (PlayersPad.y > 18) PlayersPad.y = 18;
			break;

		case key_ENTER:
			break;

		case key_SPACE:
			clrscr();
			exit(0);
			break;

		case key_n: 
			initGame();
			break;
		case key_N:
			initGame();
			break;
		case key_TAB:
			isPlayer2 = -isPlayer2;
			if (isPlayer2 > 0)
			{
				setTextColor(79); gotoXY(62, 23); printf("2 Player "); setTextColor(15);
			}
			else
			{
				setTextColor(79); gotoXY(62, 23); printf("1 Player  "); setTextColor(15);
			}

			break;


		}
	}

}

//
// INPUT:
// OUTPUT:
// Xoa console
void Game::clrscr()
{
	COORD coordScreen = { 0, 0 };
	DWORD cCharsWritten;
	CONSOLE_SCREEN_BUFFER_INFO csbi;
	DWORD dwConSize;
	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);

	GetConsoleScreenBufferInfo(hConsole, &csbi);
	dwConSize = csbi.dwSize.X * csbi.dwSize.Y;
	FillConsoleOutputCharacter(hConsole, TEXT(' '), dwConSize, coordScreen, &cCharsWritten);
	GetConsoleScreenBufferInfo(hConsole, &csbi);
	FillConsoleOutputAttribute(hConsole, csbi.wAttributes, dwConSize, coordScreen, &cCharsWritten);
	SetConsoleCursorPosition(hConsole, coordScreen);
	
}

// INPUT:
// OUTPUT:
// tra ra gia tri bien PlayersScore: diem cua nguoi choi
int Game::getPlayersScore()
{
	return playersScore;
}

// INPUT:
// OUTPUT:
// tra ra gia tri bien ComputerScore: diem cua may
int Game::getComputersScore()
{
	return computersScore;
}

// INPUT:
// OUTPUT:
// tra ra so lan va cham cua ball va pad
int Game::getCount()
{
	return count;
}

// INPUT:
// OUTPUT:
// gan gia tri cho bien isPlayer2: chuyen che do player hoac computer
void Game::setIsPlayer2(int data)
{
	isPlayer2 = data;
}

// INPUT:
// OUTPUT:
// tra ra gia tri cho bien isPlayer2: chuyen che do player hoac computer
int Game::getIsPlayer2()
{
	return isPlayer2;
}

// INPUT:
// OUTPUT:
// Tao ra mot hop van ban
void Game::box(int x, int y, int sx, int sy,char text_[])
{
	unsigned i, j, m;
	{

		m = (sx - x);                       //differential
		j = m / 8;                          //adjust
		j = j - 1;                          //more adjustment
		gotoXY(x, y); cout << char(219);       //Top left corner of box
		gotoXY(sx, y); cout << char(219);        //Top right corner of box
		gotoXY(x, sy); cout << char(219);        //Bottom left corner of box
		gotoXY(sx, sy); cout << char(219);     //Bottom right corner of box

		for (i = x + 1; i < sx; i++)
		{
			gotoXY(i, y); cout << char(219);       // Top horizontol line
			gotoXY(i, sy); cout << char(219);     // Bottom Horizontal line
		}

		for (i = y + 1; i < sy; i++)
		{
			gotoXY(x, i); cout << char(219);       //Left Vertical line
			gotoXY(sx, i); cout << char(219);       //Right Vertical Line
		}

		gotoXY(x + j, y); cout << text_;    //put Title
		gotoXY(1, 24);
	}
}

//
// INPUT:
// OUTPUT:
// Xoa hop van ban
void Game::clrbox(unsigned char x1, unsigned char y1, unsigned char x2, unsigned char y2, unsigned char bkcol)
{
	int x, y;
	setTextColor(bkcol);                       //Set to color bkcol

	for (y = y1; y < y2; y++)                    //Fill Y Region Loop
	{
		for (x = x1; x < x2; x++)               //Fill X region Loop
		{
			gotoXY(x, y); cout << " ";          //Draw Solid space
		}
	}
}

//
// INPUT:
// OUTPUT:
// Ve mot ki tu tai mot vi tri truyen vao
//
void Game::txtPlot(unsigned char x, unsigned char y, unsigned char Color)
{
	setTextColor(Color);
	gotoXY(x, y); cout << char(219);
}

//
//
//
void Game::txtLine(int x0, int y0, int x1, int y1, int color)
{
	int pix = color;
	int dy = y1 - y0;
	int dx = x1 - x0;
	int stepx, stepy;

	if (dy < 0) { dy = -dy;  stepy = -1; }
	else { stepy = 1; }
	if (dx < 0) { dx = -dx;  stepx = -1; }
	else { stepx = 1; }
	dy <<= 1;                                                  // dy is now 2*dy
	dx <<= 1;                                                  // dx is now 2*dx

	txtPlot(x0, y0, pix);
	if (dx > dy) {
		int fraction = dy - (dx >> 1);                         // same as 2*dy - dx
		while (x0 != x1) {
			if (fraction >= 0) {
				y0 += stepy;
				fraction -= dx;                                // same as fraction -= 2*dx
			}
			x0 += stepx;
			fraction += dy;                                    // same as fraction -= 2*dy
			txtPlot(x0, y0, pix);
		}
	}
	else {
		int fraction = dx - (dy >> 1);
		while (y0 != y1) {
			if (fraction >= 0) {
				x0 += stepx;
				fraction -= dy;
			}
			y0 += stepy;
			fraction += dx;
			txtPlot(x0, y0, pix);
		}
	}
}
//


