/*
* add_ball.cpp
* 增加一个新的球
*/

#include "Header.h"

void add_ball(node_ball * Head, int * ball_count, bool * time_flag, time_t * initial_time)
{
    if (0 == *time_flag)
    {
        *initial_time = time(NULL);                         //若第一次增加球，初始化时间
    }
    *time_flag = true;                                         //开始计时

    srand(clock());                                         //种子更新的速度比time()快（得多）

    node_ball * p = Head;                                   //当前指针指向头结点

    int i;
    for (i = 0; i < *ball_count; i++)
    {
        p = p->next;
    }

    node_ball * s = (node_ball*)malloc(sizeof(node_ball));  //新生成的结点
    if (s == NULL)
    {
        return;
    }
    s->next = NULL;                                         //新生成的球的*next赋NULL

    //为新申请的球赋各种数据
    s->info_ball.select_status = 0;                         //默认是未选中状态

    _stprintf_s(s->info_ball.figure, _T("%d"), rand()% 9 + 1); //随机的分数，1~9

    s->info_ball.number = p->info_ball.number + 1;          //球的序号（方便调试，没有使用）

    s->info_ball.x = 100;                                   //初始位置（固定）
    s->info_ball.y = 400;

    s->info_ball.x_step = rand() % 7 - 3;                   //随机生成的步进
    s->info_ball.y_step = rand() % 7 - 3;
    while (!s->info_ball.x_step)                            //确保有方向，而不是0
    {
        s->info_ball.x_step = rand() % 7 - 3;
    }
    while (!s->info_ball.y_step)
    {
        s->info_ball.y_step = rand() % 7 - 3;
    }

    s->info_ball.shape = rand() % 2 + 1;                    //随机形状
    //s->info_ball.shape = 1;                               //临时调试,只生成圆形

    s->info_ball.size = rand() % 30 + 20;                   //随机大小

    //如果生成的是第一个球，就让第一个球的“被选择”状态为2
    //因为如果不选择球的话，要删除最早的球
    if(0 == *ball_count)
    {
        s->info_ball.select_status = 2;
    }

    p->next = s;
    p = s;

    (*ball_count)++;                                        //球的数量增加1

    return;
}