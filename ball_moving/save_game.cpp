/*
* save_game.cpp
* 保存游戏状态
*/

#include "Header.h"

int save_game(struct node_ball * Head, struct player * point_player, int * ball_count, time_t current_time)
{
    struct node_ball * p = Head;

    //打开存档
    FILE * fp_save;
    if(fopen_s(&fp_save, "save.dat", "w"))
    {
        MessageBox(NULL, _T("存档文件打开失败！"), _T("错误"), MB_SYSTEMMODAL);
        return -1;
    }

    if (*ball_count > 0)
    {
        //把当前球的分值从TCHAR转换为char
        char temp_figure[4];
        WideCharToMultiByte(CP_ACP, 0, p->next->info_ball.figure, 4, temp_figure, 4, 0, 0);
    }
    //把玩家名字从TCHAR转换为char
    char playername_output[20];
    WideCharToMultiByte(CP_ACP, 0, point_player->playername, 20, playername_output, 20, 0, 0);

    //输出球数
    fprintf(fp_save, "%d\n", *ball_count);

    //输出玩家名称和分数
    fprintf(fp_save, "%s %d %d\n"
            , playername_output
            , point_player->score
            , current_time);

    int i;
    for (i = 0; i < *ball_count; i++)
    {
        //把当前球的分值从TCHAR转换为char
        char temp_figure[4];
        WideCharToMultiByte(CP_ACP, 0, p->next->info_ball.figure, 4, temp_figure, 4, 0, 0);

        //把玩家名字从TCHAR转换为char
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