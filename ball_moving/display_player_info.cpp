/*
* display_player_info.cpp
* ��ʾ��ҵ����ֺͷ�����Ϣ
*/

#include "Header.h"

void display_player_info(struct player * point_player)
{
    //ˢ�������Ϣ����
    setbkcolor(WHITE);
    clearrectangle(482, 26, 798, 118);

    //������ɫ
    setbkcolor(WHITE);                              //������ɫ
    settextcolor(BLACK);                            //������ɫ
    outtextxy(520, 35, _T("���:"));
    outtextxy(520, 75, point_player->playername);   //��ʾ��ҵ�����

    TCHAR score_display[10];
    _stprintf_s(score_display, _T("%d"), point_player->score); //��int����ת��ΪTCHAR
    outtextxy(660, 35, _T("����:"));
    outtextxy(660, 75, score_display);

    return;
}