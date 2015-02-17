/*
* select_ball.cpp
* 对球进行选中操作
*/

#include "Header.h"

void select_ball(node_ball * Head, int * ball_count, MOUSEMSG m, struct player * point_player)
{
    node_ball * p = Head;

    int flag_select = 0;        //是否选上了一个球

    double distance;            //鼠标的点的距离到圆心的距离

    //此循环：选中某个圆
    int i;
    for (i = 0; i < *ball_count; i++)
    {
        distance = sqrt(powf((float)(p->next->info_ball.x - m.x), 2)
            + powf( (float)(p->next->info_ball.y - m.y), 2 ));

        if (distance < p->next->info_ball.size)
        {
            p->next->info_ball.select_status = 1; //选中，上色
            flag_select = 1;                      //选中标记变为1
            break; //跳出循环，此时的i就是被选为1的球的序号-1
        }
        p = p->next;
    }

    if (0 == flag_select)
    {
        point_player->score -= rand()%3+1;  //如果没选中任何球，减1~3分
        if (point_player->score < 0)
        {
            point_player->score = 0;        //让分数不为负
        }
    }

    //将其他的选中状态变为0
    if (*ball_count > 0)    //还有球
    {
        p = Head;
        int j;
        for (j = 0; j < *ball_count; j++)
        {
            if (i == j)
            {
                p = p->next;
                continue;   //跳过已经设置为1的球
            }
            p->next->info_ball.select_status = 0;
            p = p->next;
        }
    }

    if (*ball_count > 0 && 0 == flag_select)     //如果还有球的话 且 什么球都没选中
    {
        Head->next->info_ball.select_status = 2; //第一个球被选中（不上色）
    }

    return;
}