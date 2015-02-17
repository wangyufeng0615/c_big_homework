/*
* save_game.cpp
* ������Ϸ״̬
*/

#include "Header.h"

int save_game(struct node_ball * Head, struct player * point_player, int * ball_count, time_t current_time)
{
    struct node_ball * p = Head;

    //�򿪴浵
    FILE * fp_save;
    if(fopen_s(&fp_save, "save.dat", "w"))
    {
        MessageBox(NULL, _T("�浵�ļ���ʧ�ܣ�"), _T("����"), MB_SYSTEMMODAL);
        return -1;
    }

    if (*ball_count > 0)
    {
        //�ѵ�ǰ��ķ�ֵ��TCHARת��Ϊchar
        char temp_figure[4];
        WideCharToMultiByte(CP_ACP, 0, p->next->info_ball.figure, 4, temp_figure, 4, 0, 0);
    }
    //��������ִ�TCHARת��Ϊchar
    char playername_output[20];
    WideCharToMultiByte(CP_ACP, 0, point_player->playername, 20, playername_output, 20, 0, 0);

    //�������
    fprintf(fp_save, "%d\n", *ball_count);

    //���������ƺͷ���
    fprintf(fp_save, "%s %d %d\n"
            , playername_output
            , point_player->score
            , current_time);

    int i;
    for (i = 0; i < *ball_count; i++)
    {
        //�ѵ�ǰ��ķ�ֵ��TCHARת��Ϊchar
        char temp_figure[4];
        WideCharToMultiByte(CP_ACP, 0, p->next->info_ball.figure, 4, temp_figure, 4, 0, 0);

        //��������ִ�TCHARת��Ϊchar
        char playername_output[20];
        WideCharToMultiByte(CP_ACP, 0, point_player->playername, 20, playername_output, 20, 0, 0);

        fprintf(fp_save, "%d %s %d %d %d %d %d %d %d\n",
            p->next->info_ball.number,
            temp_figure,
            p->next->info_ball.x,
            p->next->info_ball.y,
            p->next->info_ball.x_step,
            p->next->info_ball.y_step,
            p->next->info_ball.shape,
            p->next->info_ball.size,
            p->next->info_ball.select_status);

        p = p->next;
    }

    fclose(fp_save);
    return 0;
}