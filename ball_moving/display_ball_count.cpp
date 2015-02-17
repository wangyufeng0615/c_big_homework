/*
* display_ball_count.cpp
* 实时显示球的数量
*/

#include "Header.h"

void display_ball_count(int * ball_count)
{
    setbkcolor(WHITE);
    clearrectangle(890, 535, 960, 560);                     //刷新球数区域

    settextcolor(BLACK);
    setbkcolor(WHITE);

    TCHAR ball_count_display[10];
    _stprintf_s(ball_count_display, _T("%d"), *ball_count); //将int型转换为TCHAR

    outtextxy(890, 530, ball_count_display);

    return;
}