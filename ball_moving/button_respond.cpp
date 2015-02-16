/*
* button_respond.cpp
* 负责对按钮点击的响应
*/

#include "Header.h"

void button_respond(struct node_ball * Head, int * ball_count,
struct player * point_player, int * game_status, int * level, bool * time_flag)
{
    MOUSEMSG m;

    while(MouseHit())
    {
        m = GetMouseMsg();
        if (m.uMsg == WM_LBUTTONDOWN)
        {
            if(1 == *game_status)        //如果游戏处于暂停状态（0），只有“继续”可以按
            {
                if (m.x >= 360 && m.x <= 480 && m.y >= 40 && m.y <= 100) //退出
                {
                    exit_game(point_player, Head);
                }
                if (m.x >= 40 && m.x <= 160 && m.y <= 100 && m.y >= 40)  //添加
                {
                    add_ball(Head, ball_count, time_flag);
                }
                if (m.x >= 200 && m.x <= 320 && m.y <= 100 && m.y >= 40) //删除
                {
                    delete_ball(Head, ball_count, point_player);
                }
                if (m.x >= 20 && m.x <= 800 && m.y >= 120 && m.y <= 580) //选择球区里的球
                {
                    select_ball(Head, ball_count, m, point_player);
                }
                if (m.x <= 950 && m.x >= 830 && m.y >= 240 && m.y <= 300) //暂停
                {
                    *game_status = 0;
                }
                if (m.x >= 830 && m.x <= 950 && m.y >= 40 && m.y <= 100)  //保存状态
                {
                    if(!save_game(Head, point_player, ball_count))
                    {
                        MessageBox(NULL, _T("保存状态至save.txt成功！"), _T("提示"),
                            MB_SYSTEMMODAL | MB_ICONASTERISK);
                    }
                }
                if (m.x >= 830 && m.x <= 950 && m.y <= 200 && m.y >= 140) //导入状态
                {
                    if(!load_game(Head, point_player, ball_count))
                    {
                        MessageBox(NULL, _T("从save.txt读取状态成功！"), _T("提示"),
                            MB_SYSTEMMODAL | MB_ICONASTERISK);
                    }
                }
                if (m.x >= 890 && m.x <= 915 && m.y >= 425 && m.y <= 450) //难度增加
                {
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
            else if (0 == *game_status)         //当处于暂停时，只能按继续
            {
                if (m.x <= 950 && m.x >= 830 && m.y >= 340 && m.y <= 400) //继续
                {
                    *game_status = 1;
                }
            }
        }
    }

    return;
}