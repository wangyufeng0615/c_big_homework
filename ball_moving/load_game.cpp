/*
* road_game.cpp
* 读取游戏状态
*/

#include "Header.h"

int load_game(struct node_ball * Head, struct player * point_player, int * ball_count, time_t * curret_time)
{
    struct node_ball * p;
    p = Head;

    //打开存档
    FILE * fp_read;
    if(fopen_s(&fp_read, "save.dat", "r"))
    {
        MessageBox(NULL, _T("存档文件打开失败！"), _T("错误"), MB_SYSTEMMODAL);
        return -1;
    }

    //读入球数
    fscanf(fp_read, "%d\n", ball_count); //读取球数

    char temp_figure[4];
    char playername_input[20] = {0};

    //读玩家名字 分数 用时
    fscanf(fp_read, "%s %d %d\n", playername_input, &(point_player->score), curret_time);

    //把玩家名字从char转为TCHAR
    MultiByteToWideChar(CP_ACP, 0, playername_input, 20, point_player->playername, 20);

    //在读取状态之前，得先确保有跟save.dat中球数一样多个球的
    struct node_ball * s; //新节点
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
    display_player_info(point_player); //导入成功后刷新一次玩家信息
    clearrectangle(917, 480, 960, 510); //刷新时间区域，避免残留个位数
    return 0;
}