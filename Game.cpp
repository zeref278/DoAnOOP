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

unsigned long   OldTicksPerSecond = GetTickCount(), NewTicksPerSecond = GetTickCount();
unsigned long   PreferredFramesPerSecond;
unsigned int frames = 0;
float fps = 60.0f;
float Refesh;
float InverseFramesPerSecond;
float OneFramePerSecond;


Game::Game()
{
}
Game::~Game()
{
}

void Game::moveBall()
{
	txtPlot(ball.x, ball.y, 15);
	txtLine(PlayersPad.x, PlayersPad.y, PlayersPad.x, PlayersPad.y + 3, 15);
	txtLine(computersPad.x, computersPad.y, computersPad.x, computersPad.y + 3, 15);
}
//
void Game::removeBall()
{
	//Sleep( 9  );
	txtPlot(ball.x, ball.y, 0);
	txtLine(PlayersPad.x, PlayersPad.y, PlayersPad.x, PlayersPad.y + 3, 0);
	txtLine(computersPad.x, computersPad.y, computersPad.x, computersPad.y + 3, 0);
}
//
void Game::gameLogic()
{
	/* update ball's x location */
	ball.x += ball.headingX;
	/* update ball's y location */
	ball.y += ball.headingY;



	/* check if ball's location at top or bottom of screen,if true reverse ball's y heading */
	if ((ball.y < SCREEN_TOP) || (ball.y > SCREEN_BOTTOM - 2)) ball.headingY = -ball.headingY;

	PlayersPad.LEFT = PlayersPad.y - 3;
	PlayersPad.RIGHT = PlayersPad.y + 5;
	computersPad.LEFT = computersPad.y - 3;
	computersPad.RIGHT = computersPad.y + 5;
	/* check if ball lands on pad, if true bounce back */
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


	/* check if ball misses pad, if true display you missed */
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
//
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
	txtLine(6, 0, 74, 0, 1);
	txtLine(6, 22, 74, 22, 1);
	txtLine(6, 23, 74, 23, 1);


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
void Game::displayYouMissed()
{
	clrbox(10, 8, 70, 16, 79);
	//box(10, 8, 70, 16, 31, 79, "You missed");

	gotoXY(18, 10); cout << " ";
	gotoXY(18, 11); cout << "The ball has missed the paddle";
	gotoXY(18, 12); cout << "press press space to continue";
	gotoXY(18, 13); cout << "";
	gotoXY(18, 14); cout << "";
	keypressed = _getch();
	clrbox(10, 8, 75, 21, 0);


}
//
void Game::displayCheatEnabled()
{
	clrbox(10, 8, 70, 16, 79);
	char temp[] = "Player vs. Computer";
	box(10, 8, 70, 16, 31, 79, temp);
	gotoXY(15, 10); cout << "The Cheat' pad will track  ball movement' is enabled";
	gotoXY(15, 11); cout << "press <TAB> to switch between 1 Player and 2 Players mode.";
	gotoXY(15, 13); cout << "press press space to continue";
	gotoXY(18, 14); cout << "";
	gotoXY(18, 14); cout << "";
	keypressed = _getch();
	clrbox(10, 8, 75, 21, 0);


}
//
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
			PlayersPad.y -= 3; if (PlayersPad.y < 0) PlayersPad.y = 0;
			break;

		case key_DOWN:
			PlayersPad.y += 3; if (PlayersPad.y > 18) PlayersPad.y = 18;
			break;

		case 119:
			computersPad.y -= 3; if (computersPad.y < 0) computersPad.y = 0;
			break;

		case 115:
			computersPad.y += 3; if (computersPad.y > 18) computersPad.y = 18;
			break;

		case 87:
			computersPad.y -= 3; if (computersPad.y < 0) computersPad.y = 0;
			break;

		case 83:
			computersPad.y += 3; if (computersPad.y > 18) computersPad.y = 18;
			break;

		case key_ENTER:
			break;

		case key_SPACE:
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
void Game::Render_Game_At_60_Frames_Per_Second()
{
	
	unsigned long DeltaTicksPerSecond = NewTicksPerSecond - OldTicksPerSecond;
	frames++;

	if (DeltaTicksPerSecond >= PreferredFramesPerSecond)
	{


		OldTicksPerSecond = NewTicksPerSecond;
		InverseFramesPerSecond = 1 / ((float)PreferredFramesPerSecond / 1000.0f);
		OneFramePerSecond = (float)frames * InverseFramesPerSecond;
		fps += OneFramePerSecond;
		fps /= 2;
		setTextColor(31); gotoXY(70, 22); printf(" %d FPS ", DeltaTicksPerSecond); setTextColor(15);
		frames = 0;
		Refesh = 60 / fps;
	}
	Sleep(3);
}
//
void Game::setForeGroundAndBackGroundColor(int ForeGroundColor, int BackGroundColor)
{
	int color = 16 * BackGroundColor + ForeGroundColor;
	setTextColor(color);
}
//
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
//
void Game::box(unsigned x, unsigned y, unsigned sx, unsigned sy, unsigned char col, unsigned char col2, char text_[])
{
	unsigned i, j, m;
	{

		m = (sx - x);                       //differential
		j = m / 8;                          //adjust
		j = j - 1;                          //more adjustment
		gotoXY(x, y); cout << "1";       //Top left corner of box
		gotoXY(sx, y); cout << "2";        //Top right corner of box
		gotoXY(x, sy); cout << "3";        //Bottom left corner of box
		gotoXY(sx, sy); cout << "4";     //Bottom right corner of box

		for (i = x + 1; i < sx; i++)
		{
			gotoXY(i, y); cout << "5";       // Top horizontol line
			gotoXY(i, sy); cout << "5";     // Bottom Horizontal line
		}

		for (i = y + 1; i < sy; i++)
		{
			gotoXY(x, i); cout << "6";       //Left Vertical line
			gotoXY(sx, i); cout << "6";       //Right Vertical Line
		}

		gotoXY(x + j, y); cout << text_;    //put Title
		gotoXY(1, 24);
	}
}
//
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
void Game::putbox(unsigned x, unsigned y, unsigned sx, unsigned sy,
	unsigned char col, unsigned char col2, unsigned char bkcol, char text_[])
{
	clrbox(x, y, sx, sy, bkcol);
	box(x, y, sx, sy, col, col2, text_);
}
//
void Game::txtPlot(unsigned char x, unsigned char y, unsigned char Color)
{
	setTextColor(Color);
	gotoXY(x, y); cout << char(219);
}
//
void  Game::txtSwap(int first, int second)
{
	int  temp;


	temp = first;
	first = second;
	second = temp;
}
//
void Game::txtCircle(int X, int Y, int rad, int col)
{
	float deg = 0;
	do {
		X = (int)(rad * cos(deg));
		Y = (int)(rad * sin(deg));
		txtPlot(40 + X, 12 + Y, col);
		deg += 0.005;
	} while (deg <= 6.4);
}
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
void Game::delay(unsigned int milliseconds)
{
	clock_t ticks1, ticks2;
	unsigned int tic1 = 0, tic2 = 0, tick = 0;

	ticks1 = clock();
	while (tick < milliseconds)
	{
		ticks2 = clock();
		tic1 = ticks2 / CLOCKS_PER_SEC - ticks1;
		tic2 = ticks1 / CLOCKS_PER_SEC;
		tick = ticks2 - ticks1;
	}
	ticks2 = clock();
}

