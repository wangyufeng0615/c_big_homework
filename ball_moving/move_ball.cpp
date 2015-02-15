/*
* move_ball.cpp
* 实现球的移动
*/

#include "Header.h"
#define DIM 1000                        //模糊用的参数

void move_ball(node_ball * Head, int * ball_count, int * level)
{
    node_ball * p = NULL;               //操作指针
    p = Head->next;                     //从第一个球开始

    setfillcolor(RED);                  //圆的填充颜色
    settextcolor(WHITE);                //文字的颜色
    setbkcolor(RED);                    //文字的背景颜色

    int i;
    for (i = 0; i < *ball_count; i++)   //每个循环把所有球都画一遍
    {
        switch (p->info_ball.shape)
        {
            //圆
        case 1 :
            if (p->info_ball.select_status == 1)
            {
                setfillcolor(BLUE); //如果是选定状态就画蓝色(除了球序列中最早的那个，虽然被选，但不上色)
            }
            solidcircle(p->info_ball.x, p->info_ball.y, p->info_ball.size);
            setfillcolor(RED);   //颜色还原

            //写分值（数字）
            if (p->info_ball.select_status == 1)
            {
                setbkcolor(BLUE); //如果是选定状态就画蓝色(文字底色)
            }
            outtextxy(p->info_ball.x - 6, p->info_ball.y - 15, p->info_ball.figure); //让数字显示在圆的中央
            setbkcolor(RED);   //颜色还原

            //边缘检测
            if (p->info_ball.x - p->info_ball.size - 6 <= 20)       //碰左边线
            {
                p->info_ball.x = 20 + p->info_ball.size + 6;
                p->info_ball.x_step = p->info_ball.x_step * -1;
            }
            else if (p->info_ball.x + p->info_ball.size + 4 >= 800) //碰右边线
            {
                p->info_ball.x = 800 - p->info_ball.size - 4;
                p->info_ball.x_step = p->info_ball.x_step * -1;
            }
            else if (p->info_ball.y - p->info_ball.size - 4 <= 120) //碰上边线
            {
                p->info_ball.y = 120 + p->info_ball.size + 4;
                p->info_ball.y_step = p->info_ball.y_step * -1;
            }
            else if (p->info_ball.y + p->info_ball.size + 6 >= 580) //碰下边线
            {
                p->info_ball.y = 580 - p->info_ball.size - 6;
                p->info_ball.y_step = p->info_ball.y_step * -1;
            }
            break;

            //圆角矩形
        case 2 :
            if (p->info_ball.select_status == 1)
            {
                setfillcolor(BLUE); //如果是选定状态就画蓝色(除了球序列中最早的那个，虽然被选，但不上色)
            }
            solidroundrect(p->info_ball.x - p->info_ball.size,
                p->info_ball.y - p->info_ball.size,
                p->info_ball.x + p->info_ball.size,
                p->info_ball.y + p->info_ball.size,
                10, 10);
            setfillcolor(RED); //颜色还原

            //写分值（数字）
            if (p->info_ball.select_status == 1)
            {
                setbkcolor(BLUE); //如果是选定状态就画蓝色(文字底色)
            }
            outtextxy(p->info_ball.x - 6, p->info_ball.y - 15, p->info_ball.figure); //让数字显示在圆的中央
            setbkcolor(RED); //颜色还原

            //边缘检测
            if (p->info_ball.x - p->info_ball.size - 6 <= 20)       //碰左边线
            {
                p->info_ball.x = 20 + p->info_ball.size + 6;
                p->info_ball.x_step = p->info_ball.x_step * -1;
            }
            else if (p->info_ball.x + p->info_ball.size + 4 >= 800) //碰右边线
            {
                p->info_ball.x = 800 - p->info_ball.size - 4;
                p->info_ball.x_step = p->info_ball.x_step * -1;
            }
            else if (p->info_ball.y - p->info_ball.size - 4 <= 120) //碰上边线
            {
                p->info_ball.y = 120 + p->info_ball.size + 4;
                p->info_ball.y_step = p->info_ball.y_step * -1;
            }
            else if (p->info_ball.y + p->info_ball.size + 6 >= 580) //碰下边线
            {
                p->info_ball.y = 580 - p->info_ball.size - 6;
                p->info_ball.y_step = p->info_ball.y_step * -1;
            }
            break;
        }

        //步进（让球动起来）
        p->info_ball.x += p->info_ball.x_step;
        p->info_ball.y += p->info_ball.y_step;

        p = p->next;
    }

    ////全屏模糊
    //DWORD* pMem = GetImageBuffer();
    //for(int i = DIM; i < DIM * 599; i++)
    //{
    //    pMem[i] = RGB(
    //        (GetRValue(pMem[i]) + GetRValue(pMem[i - DIM]) + GetRValue(pMem[i - 1]) + GetRValue(pMem[i + 1]) + GetRValue(pMem[i + DIM])) / 5,
    //        (GetGValue(pMem[i]) + GetGValue(pMem[i - DIM]) + GetGValue(pMem[i - 1]) + GetGValue(pMem[i + 1]) + GetGValue(pMem[i + DIM])) / 5,
    //        (GetBValue(pMem[i]) + GetBValue(pMem[i - DIM]) + GetBValue(pMem[i - 1]) + GetBValue(pMem[i + 1]) + GetBValue(pMem[i + DIM])) / 5);
    //}
    
    FlushBatchDraw(); //一次画全部的球，避免闪烁
   
    Sleep(*level);         //难度控制（单位毫秒）

    return;
}