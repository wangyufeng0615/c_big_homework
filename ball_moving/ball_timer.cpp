/*
*  ball_timer.cpp 
*  ��ʱģ��
*/

#include "Header.h"

void ball_timer(time_t initial_time, time_t * current_time)
{
    *current_time = time(NULL) - initial_time;

    TCHAR ball_timer_display[10];
    _stprintf_s(ball_timer_display, _T("%d"), *current_time); //��int��ת��ΪTCHAR

    outtextxy(900, 475, ball_timer_display);

    return;
}