/*
* add_ball.cpp
* ����һ���µ���
*/

#include "Header.h"

void add_ball(node_ball * Head, int * ball_count, bool * time_flag, time_t * initial_time)
{
    if (0 == *time_flag)
    {
        *initial_time = time(NULL);                         //����һ�������򣬳�ʼ��ʱ��
    }
    *time_flag = true;                                         //��ʼ��ʱ

    srand(clock());                                         //���Ӹ��µ��ٶȱ�time()�죨�öࣩ

    node_ball * p = Head;                                   //��ǰָ��ָ��ͷ���

    int i;
    for (i = 0; i < *ball_count; i++)
    {
        p = p->next;
    }

    node_ball * s = (node_ball*)malloc(sizeof(node_ball));  //�����ɵĽ��
    if (s == NULL)
    {
        return;
    }
    s->next = NULL;                                         //�����ɵ����*next��NULL

    //Ϊ��������򸳸�������
    s->info_ball.select_status = 0;                         //Ĭ����δѡ��״̬

    _stprintf_s(s->info_ball.figure, _T("%d"), rand()% 9 + 1); //����ķ�����1~9

    s->info_ball.number = p->info_ball.number + 1;          //�����ţ�������ԣ�û��ʹ�ã�

    s->info_ball.x = 100;                                   //��ʼλ�ã��̶���
    s->info_ball.y = 400;

    s->info_ball.x_step = rand() % 7 - 3;                   //������ɵĲ���
    s->info_ball.y_step = rand() % 7 - 3;
    while (!s->info_ball.x_step)                            //ȷ���з��򣬶�����0
    {
        s->info_ball.x_step = rand() % 7 - 3;
    }
    while (!s->info_ball.y_step)
    {
        s->info_ball.y_step = rand() % 7 - 3;
    }

    s->info_ball.shape = rand() % 2 + 1;                    //�����״
    //s->info_ball.shape = 1;                               //��ʱ����,ֻ����Բ��

    s->info_ball.size = rand() % 30 + 20;                   //�����С

    //������ɵ��ǵ�һ���򣬾��õ�һ����ġ���ѡ��״̬Ϊ2
    //��Ϊ�����ѡ����Ļ���Ҫɾ���������
    if(0 == *ball_count)
    {
        s->info_ball.select_status = 2;
    }

    p->next = s;
    p = s;

    (*ball_count)++;                                        //�����������1

    return;
}