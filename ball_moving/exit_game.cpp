/*
* exit_game.cpp
* �˳���Ϸ�����������Ϣ
*/

#include "Header.h"

void exit_game(struct player * point_player, struct node_ball * Head)
{
    //�˴��������˳�ʱ������ҷ����Ĺ���
    //�Ѹ�Ϊ��ʤ��������ʱ����

    free(Head);     //�ͷ���
    closegraph();
    exit(0);
}