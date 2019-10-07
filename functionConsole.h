#pragma once

#define BLACK			0
#define DARK_BLUE		1
#define DARK_GREEN	2
#define DARK_CYAN	3
#define DARK_RED		4
#define DARK_PINK	5
#define DARK_YELLOW	6
#define DARK_WHITE	7
#define GREY			8
#define BLUE			9
#define GREEN			10
#define CYAN			11
#define RED			12
#define PINK			13
#define YELLOW		14
#define WHITE			15

void noCursorType();          //xoa dau nhay console
void setTextColor(int color); //tao mau text
void FixConsoleWindow();      //lam mo nut resize console
void gotoXY(int x, int y);    //di chuyen dau nhay den toa do x,y
int whereX();                 // hoanh do cua dau nhay
int whereY();                 //tung do cua dau nhay

