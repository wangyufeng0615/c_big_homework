/*
* delete_ball.cpp
* 删除一个球
*/

#include "Header.h"

void update_score(int add_score, struct player * point_player);

void delete_ball(node_ball * Head, int * ball_count, struct player * point_player)
{
    struct node_ball * p = Head;            //当前指针指向头结点
    struct node_ball * temp;                //用于free被删除的球

    //检测哪个球被选上了，如果被选上，就删除
    int i;
    for (i = 0; i < *ball_count; i++)
    {
        if (1 == p->next->info_ball.select_status || 2 == p->next->info_ball.select_status) //如果被选中
        {
            temp = p->next;
            if (p->next->next != NULL) //如果要删除这个节点后还有别的节点的话
            {
                p->next= p->next->next;
            }
            else
            {
                p->next = NULL;
            }

            //增加分数
            int add_score;
            add_score = _wtoi(temp->info_ball.figure);
            update_score(add_score, point_player);

            //更新玩家信息
            setbkcolor(WHITE);
            //clearrectangle(482, 23, 778, 118);
            clearrectangle(482, 26, 798, 118);
            display_player_info(point_player);

            free(temp);                             //释放被删除球的空间

            (*ball_count)--;                        //球数量-1

            if (Head->next != NULL) //当有球的时候，删除一个球后将最早生成的球被选中
            {
                Head->next->info_ball.select_status = 2; //2是被选中，但是不上色
            }
            else //一个球也不剩了
            {
                setfillcolor(WHITE);
                //solidrectangle(22, 122, 798, 578);  //用白色清屏
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
    point_player->score += add_score;               //累加玩家得分

    return;
}