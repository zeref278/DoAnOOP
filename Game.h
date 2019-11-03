#pragma once

#include "structBall.h"
#include "structPad.h"

class Game
{
private:
	Ball ball;
	Pad  PlayersPad, computersPad, AnotherPlayersPad ;
	int keypressed, isPlayer2, playersScore, computersScore;
	float count;

public:
	Game();
	~Game();
public:
	int getCount();
	int getPlayersScore();
	int getComputersScore();
	void setIsPlayer2(int data);
	int getIsPlayer2();

	void moveBall();
	void initGame();
	void Keypressed();
	void gameLogic();
	void removeBall();
	void displayYouMissed();


	void clrscr();
	void box(int x, int y, int sx, int sy, char text_[]);
	void clrbox(unsigned char x1, unsigned char y1, unsigned char x2, unsigned char y2, unsigned char bkcol);
	void txtPlot(unsigned char x, unsigned char y, unsigned char Color);
	void txtLine(int x0, int y0, int x1, int y1, int color);


};


