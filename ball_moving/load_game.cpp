/*
* road_game.cpp
* ��ȡ��Ϸ״̬
*/

#include "Header.h"

int load_game(struct node_ball * Head, struct player * point_player, int * ball_count, time_t * curret_time)
{
    struct node_ball * p;
    p = Head;

    //�򿪴浵
    FILE * fp_read;
    if(fopen_s(&fp_read, "save.dat", "r"))
    {
        MessageBox(NULL, _T("�浵�ļ���ʧ�ܣ�"), _T("����"), MB_SYSTEMMODAL);
        return -1;
    }

    //��������
    fscanf(fp_read, "%d\n", ball_count); //��ȡ����

    char temp_figure[4];
    char playername_input[20] = {0};

    //��������� ���� ��ʱ
    fscanf(fp_read, "%s %d %d\n", playername_input, &(point_player->score), curret_time);

    //��������ִ�charתΪTCHAR
    MultiByteToWideChar(CP_ACP, 0, playername_input, 20, point_player->playername, 20);

    //�ڶ�ȡ״̬֮ǰ������ȷ���и�save.dat������һ��������
    struct node_ball * s; //�½ڵ�
    int j;
    for (j = 0; j < *ball_count; j++)
    {
        if (NULL == p->next)
        {
            s = (struct node_ball *)malloc(sizeof(node_ball));
            s->next = NULL;

            p->next = s;
        }
        p = p->next;
    }

    p = Head;
    int i;
    for (i = 0; i < *ball_count; i++)
    {
        fscanf(fp_read, "%d %s %d %d %d %d %d %d %d\n",
            &p->next->info_ball.number,
            temp_figure,
            &p->next->info_ball.x,
            &p->next->info_ball.y,
            &p->next->info_ball.x_step,
            &p->next->info_ball.y_step,
            &p->next->info_ball.shape,
            &p->next->info_ball.size,
            &p->next->info_ball.select_status);

        MultiByteToWideChar(CP_ACP, 0, temp_figure, 4, p->next->info_ball.figure, 4);

        p = p->next;
    }

    fclose(fp_read);
    display_player_info(point_player); //����ɹ���ˢ��һ�������Ϣ
    clearrectangle(917, 480, 960, 510); //ˢ��ʱ�����򣬱��������λ��
    return 0;
}