/*
* delete_ball.cpp
* ɾ��һ����
*/

#include "Header.h"

void update_score(int add_score, struct player * point_player);

void delete_ball(node_ball * Head, int * ball_count, struct player * point_player)
{
    struct node_ball * p = Head;            //��ǰָ��ָ��ͷ���
    struct node_ball * temp;                //����free��ɾ������

    //����ĸ���ѡ���ˣ������ѡ�ϣ���ɾ��
    int i;
    for (i = 0; i < *ball_count; i++)
    {
        if (1 == p->next->info_ball.select_status || 2 == p->next->info_ball.select_status) //�����ѡ��
        {
            temp = p->next;
            if (p->next->next != NULL) //���Ҫɾ������ڵ���б�Ľڵ�Ļ�
            {
                p->next= p->next->next;
            }
            else
            {
                p->next = NULL;
            }

            //���ӷ���
            int add_score;
            add_score = _wtoi(temp->info_ball.figure);
            update_score(add_score, point_player);

            //���������Ϣ
            setbkcolor(WHITE);
            //clearrectangle(482, 23, 778, 118);
            clearrectangle(482, 26, 798, 118);
            display_player_info(point_player);

            free(temp);                             //�ͷű�ɾ����Ŀռ�

            (*ball_count)--;                        //������-1

            if (Head->next != NULL) //�������ʱ��ɾ��һ������������ɵ���ѡ��
            {
                Head->next->info_ball.select_status = 2; //2�Ǳ�ѡ�У����ǲ���ɫ
            }
            else //һ����Ҳ��ʣ��
            {
                setfillcolor(WHITE);
                //solidrectangle(22, 122, 798, 578);  //�ð�ɫ����
                clearrectangle(24, 121, 798, 576);
            }

            break; //!!!
        }
        else
        {
            p = p->next;
        }
    }

    return;
}

void update_score(int add_score, struct player * point_player)
{
    point_player->score += add_score;               //�ۼ���ҵ÷�

    return;
}