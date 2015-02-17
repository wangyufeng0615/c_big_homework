/*
* button_respond.cpp
* 负责对按钮点击的响应
*/

#include "Header.h"

static time_t time_pause;                   //实现暂停时不计时的功能（思路：initial_time += 暂停用时）
static bool difficulty_message_flag = true; //第一次调速时进行提示

void button_respond(struct node_ball * Head, int * ball_count
                    , struct player * point_player, int * game_status
                    , int * level, bool * time_flag, time_t * initial_time, time_t * current_time)
{
    MOUSEMSG m;

    while(MouseHit())
    {
        m = GetMouseMsg();
        if (m.uMsg == WM_LBUTTONDOWN)
        {
            if(1 == *game_status)                                        //只有当游戏处于运行状态时能按的键
            {                
                if (m.x >= 40 && m.x <= 160 && m.y <= 100 && m.y >= 40)  //添加
                {
                    add_ball(Head, ball_count, time_flag, initial_time);
                }
               
                if (m.x >= 200 && m.x <= 320 && m.y <= 100 && m.y >= 40) //删除
                {
                    delete_ball(Head, ball_count, point_player, *current_time);
                }
                
                if (m.x >= 20 && m.x <= 800 && m.y >= 120 && m.y <= 580) //选择球区里的球
                {
                    select_ball(Head, ball_count, m, point_player);
                }
                
                if (m.x <= 950 && m.x >= 830 && m.y >= 240 && m.y <= 300) //暂停
                {
                    *game_status = 0;
                    time_pause = time(NULL);                      
                }
                
                if (m.x >= 890 && m.x <= 915 && m.y >= 425 && m.y <= 450) //难度增加
                {
                    if(difficulty_message_flag)
                    {
                        MessageBox(NULL, _T("调速仅供调试，不是游戏的一部分，请在默认速度下挑战游戏~\n此信息只显示一次"), _T("关于速度调节"),MB_ICONASTERISK | MB_SYSTEMMODAL);
                        difficulty_message_flag = false;
                    }

                    if (*level >= 0 && *level <= 12)
                    {
                        *level -= 2;
                        if (0 > *level)
                        {
                            *level = 0;     //最快速度
                        }
                    }
                }
                
                if (m.x >= 930 && m.x <= 955 && m.y >= 425 && m.y <= 450) //难度减小
                {
                    if(difficulty_message_flag)
                    {
                        MessageBox(NULL, _T("调速仅供调试，不是游戏的一部分，请在默认速度下挑战游戏~\n此信息只显示一次"), _T("关于速度调节"),MB_ICONASTERISK | MB_SYSTEMMODAL);
                        difficulty_message_flag = false;
                    }

                    if (*level >= 0 && *level <= 12)
                    {
                        *level += 2;
                        if (12 < *level)
                        {
                            *level = 12;    //最慢速度
                        }
                    }
                }
            }
            else if (0 == *game_status)                                   //只有当处于暂停时，才能按继续
            {
                if (m.x <= 950 && m.x >= 830 && m.y >= 340 && m.y <= 400) //继续
                {
                    *game_status = 1;
                    *initial_time += (time(NULL) - time_pause);           //令计时器正常工作
                }
            }
            
            if (1 == *game_status || 0 == *game_status)              //无论什么游戏状态下，都可以按的键
            {
                if (m.x >= 360 && m.x <= 480 && m.y >= 40 && m.y <= 100) //退出
                {
                    MessageBox(NULL,_T("拜拜~~"), _T("特别好玩吧！"), MB_SYSTEMMODAL | MB_ICONASTERISK);
                    exit_game(point_player, Head);
                }
                
                if (m.x >= 830 && m.x <= 950 && m.y >= 40 && m.y <= 100)  //保存状态
                {
                    if(!save_game(Head, point_player, ball_count, *current_time))
                    {
                        MessageBox(NULL, _T("保存状态至 save.dat 成功！"), _T("提示"),
                            MB_SYSTEMMODAL | MB_ICONASTERISK);
                    }
                }

                if (m.x >= 830 && m.x <= 950 && m.y <= 200 && m.y >= 140) //导入状态
                {
                    if(!load_game(Head, point_player, ball_count, current_time))
                    {
                        *time_flag = true;                                //恢复计时状态
                        *game_status = true;                              //恢复游戏进行状态
                        *initial_time = time(NULL) - *current_time;       //导入时间，继续计时
                        MessageBox(NULL, _T("从 save.dat 读取状态成功！"), _T("提示"),
                            MB_SYSTEMMODAL | MB_ICONASTERISK);
                    }
                }
            }
        }
    }

    return;
}