/*
* select_ball.cpp
* �������ѡ�в���
*/

#include "Header.h"

void select_ball(node_ball * Head, int * ball_count, MOUSEMSG m, struct player * point_player)
{
    node_ball * p = Head;

    int flag_select = 0;        //�Ƿ�ѡ����һ����

    double distance;            //���ĵ�ľ��뵽Բ�ĵľ���

    //��ѭ����ѡ��ĳ��Բ
    int i;
    for (i = 0; i < *ball_count; i++)
    {
        distance = sqrt(powf((float)(p->next->info_ball.x - m.x), 2)
            + powf( (float)(p->next->info_ball.y - m.y), 2 ));

        if (distance < p->next->info_ball.size)
        {
            p->next->info_ball.select_status = 1; //ѡ�У���ɫ
            flag_select = 1;                      //ѡ�б�Ǳ�Ϊ1
            break; //����ѭ������ʱ��i���Ǳ�ѡΪ1��������-1
        }
        p = p->next;
    }

    if (0 == flag_select)
    {
        point_player->score -= rand()%3+1;  //���ûѡ���κ��򣬼�1~3��
        if (point_player->score < 0)
        {
            point_player->score = 0;        //�÷�����Ϊ��
        }
    }

    //��������ѡ��״̬��Ϊ0
    if (*ball_count > 0)    //������
    {
        p = Head;
        int j;
        for (j = 0; j < *ball_count; j++)
        {
            if (i == j)
            {
                p = p->next;
                continue;   //�����Ѿ�����Ϊ1����
            }
            p->next->info_ball.select_status = 0;
            p = p->next;
        }
    }

    if (*ball_count > 0 && 0 == flag_select)     //���������Ļ� �� ʲô��ûѡ��
    {
        Head->next->info_ball.select_status = 2; //��һ����ѡ�У�����ɫ��
    }

    return;
}