/*版本更新信息在README.md中*/

#include "Header.h"
#define DEFAULT_DIFFICULTY 6                        //默认难度(越小越快)
#define DEFAULT_STATUS 1                            //默认游戏状态，1运行，0暂停

int main()
{
    main_interface();                               //绘制界面

    int game_status = DEFAULT_STATUS;               //游戏状态，1运行，0暂停

    int level = DEFAULT_DIFFICULTY;                 //默认的难度为6(Sleep)

    time_t initial_time;                            //初始时间
    time_t current_time = 0;                        //已用时间
    bool time_flag = false;                         //为1时进行计时，未添加球时不计时

    //玩家信息
    struct player player1;
    player1.score = 0;                              //分数初始化为0
    input_player_info(&player1);                    //输入玩家信息
    display_player_info(&player1);                  //显示玩家信息

    //建立球链表的头结点
    struct node_ball * Head = (node_ball*)calloc(1,sizeof(node_ball));
    if (NULL == Head)
    {
        return -1;
    }
    Head->info_ball.number = 0;             //球初始序号为1(头结点不使用)
    Head->next = NULL;

    int ball_count = 0;                     //球的个数初始化为0

    //主循环
    while(1)
    {
        BeginBatchDraw(); //开始批绘制 对应FlushBatchDraw()

        button_respond(Head, &ball_count, &player1, &game_status, &level, &time_flag, &initial_time, &current_time); //按钮响应

        display_player_info(&player1);      //更新玩家信息
        display_ball_count(&ball_count);    //更新球数信息

        if(ball_count != 0)                 //如果有球
        {
            if(game_status)                 //如果游戏状态为1时（运行）
            {
                if (time_flag)              //增加球后且未暂停时计时
                {
                    ball_timer(initial_time, &current_time);       
                }

                move_ball(Head, &ball_count, &level); //球的运动

                setbkcolor(WHITE);          //用白色清屏
                clearrectangle(24, 121, 798, 576);
            }
        }
        else //没球时刷新一下,避免玩家和球信息闪烁
        {
            FlushBatchDraw();
        }
    }

    return 0;
}