/*
* display_ball_count.cpp
* ʵʱ��ʾ�������
*/

#include "Header.h"

void display_ball_count(int * ball_count)
{
    setbkcolor(WHITE);
    clearrectangle(860, 530, 960, 560);                     //ˢ����������

    settextcolor(BLACK);
    setbkcolor(WHITE);

    TCHAR ball_count_display[10];
    _stprintf_s(ball_count_display, _T("%d"), *ball_count); //��int��ת��ΪTCHAR

    outtextxy(820, 530, _T("����:"));
    outtextxy(890, 530, ball_count_display);

    return;
}