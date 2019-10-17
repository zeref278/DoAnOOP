#pragma once

#include "structBall.h"
#include "structPad.h"

class Game
{
public:
	Ball ball;
	Pad  PlayersPad, computersPad, AnotherPlayersPad ;
	int keypressed, isPlayer2, playersScore, computersScore;


public:
	Game();
	~Game();
public:
	void moveBall();
	void initGame();
	void Keypressed();
	void gameLogic();
	void removeBall();
	void displayYouMissed();
	void displayCheatEnabled();
	void Render_Game_At_60_Frames_Per_Second();
	void setForeGroundAndBackGroundColor(int ForeGroundColor, int BackGroundColor);
	void clrscr();
	void box(unsigned x, unsigned y, unsigned sx, unsigned sy, unsigned char col, unsigned char col2, char text_[]);
	void clrbox(unsigned char x1, unsigned char y1, unsigned char x2, unsigned char y2, unsigned char bkcol);
	void putbox(unsigned x, unsigned y, unsigned sx, unsigned sy, unsigned char col, unsigned char col2, unsigned char bkcol, char text_[]);
	void txtPlot(unsigned char x, unsigned char y, unsigned char Color);
	void txtSwap(int first, int second);
	void txtCircle(int X, int Y, int rad, int col);
	void txtLine(int x0, int y0, int x1, int y1, int color);
	void delay(unsigned int milliseconds);

};


