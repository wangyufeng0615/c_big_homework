/*
* delete_ball.cpp
* 删除一个球
* 触发获胜条件+输出信息
*/

#include "Header.h"

void update_score(int add_score, struct player * point_player); //刷新玩家分数

void delete_ball(node_ball * Head, int * ball_count, struct player * point_player, time_t current_time)
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
            if (1 == temp->info_ball.select_status)         //若球是未选中状态下被删除，不加分
            {
                int add_score;
                add_score = _wtoi(temp->info_ball.figure);
                update_score(add_score, point_player);
            }

            //更新玩家信息
            setbkcolor(WHITE);
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
                clearrectangle(24, 121, 798, 576);  //用白色清屏
            }

            break; //!!!
        }
        else
        {
            p = p->next;
        }
    }

    //获胜条件触发：
    if ((point_player->score == (*ball_count) * 20 && *ball_count != 0) || point_player->score == 50)
    {
        int temp_level = 2;                 //临时的level条件，为了让球的状态刷新一次
        display_ball_count(ball_count);     //更新球数信息
        move_ball(Head, ball_count, &temp_level); //球的运动

        if (point_player->score == (*ball_count) * 20 && *ball_count != 0)
        {
            MessageBox(NULL, _T("你赢啦！分数等于球数的20倍！"), _T("Win!"),MB_ICONASTERISK | MB_SYSTEMMODAL);
        }
        if (point_player->score == 50)
        {
            MessageBox(NULL, _T("你赢啦！分数定格在50！"), _T("Win!"),MB_ICONASTERISK | MB_SYSTEMMODAL);
        }

        //设置时间
        time_t t = time(0);
        char time_temp[64];
        struct tm lt;
        localtime_s(&lt, &t);
        //strftime(time_temp, sizeof(time_temp), "%Y/%m/%d %X", &lt); 可输出年月日小时分秒
        strftime(time_temp, sizeof(time_temp), "%m/%d", &lt);
        
        //文件指针
        FILE * fp_result;
        if (fopen_s(&fp_result, "player_info.csv", "a+"))
        {
            MessageBox(NULL, _T("成绩记录文件打开失败！"), _T("错误"), MB_SYSTEMMODAL);
            return;
        }

        //TCHAR*转char*
        char playername_output[20];
        WideCharToMultiByte(CP_ACP, 0, point_player->playername, 20, playername_output, 20, 0, 0);
        fprintf(fp_result, "%s,%s,%d\n"
                         , time_temp
                         , playername_output
                         , current_time);
        fclose(fp_result);

        //弹出提示消息
        MessageBox(NULL,_T("用户名和用时等信息已保存至 player_info.csv (用Excel打开)"), _T("拜拜~"), MB_SYSTEMMODAL | MB_ICONASTERISK);
        
        exit_game(point_player, Head);
    }



    return;
}

void update_score(int add_score, struct player * point_player)
{
    point_player->score += add_score;               //累加玩家得分

    return;
}