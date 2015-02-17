/*
* display_player_info.cpp
* 显示玩家的名字和分数信息
*/

#include "Header.h"

void display_player_info(struct player * point_player)
{
    //刷新玩家信息区域
    setbkcolor(WHITE);
    clearrectangle(482, 26, 798, 118);

    //调整颜色
    setbkcolor(WHITE);                              //背景颜色
    settextcolor(BLACK);                            //文字颜色
    outtextxy(520, 35, _T("玩家:"));
    outtextxy(520, 75, point_player->playername);   //显示玩家的名字

    TCHAR score_display[10];
    _stprintf_s(score_display, _T("%d"), point_player->score); //将int分数转换为TCHAR
    outtextxy(660, 35, _T("分数:"));
    outtextxy(660, 75, score_display);

    return;
}