/*
 *	move_ball.cpp
 *	实现球的移动
 */

#include "Header.h"

void move_ball(node_ball * Head, int * ball_count)
{
	node_ball * p = NULL;					//操作指针

	setfillcolor(RED);						//圆的填充颜色
 	settextcolor(WHITE);					//文字的颜色
	setbkcolor(RED);						//文字的背景颜色
	
//	settextstyle(32, 0, _T("微软雅黑"));     //文字字体

	p = Head->next;							//从第一个球开始
	
	BeginBatchDraw();						//test：批量绘图

	int i;
	for (i = 0; i < *ball_count; i++)		//每个循环把所有球都画一遍
	{
		switch (p->info_ball.shape) 
		{
		case 1 :							//画圆 
			if (p->info_ball.select_status == 1)			
			{
				setfillcolor(BLUE);			//如果是选定状态就画蓝色(除了球序列中最早的那个，虽然被选，但不上色)
			}
			solidcircle(p->info_ball.x, p->info_ball.y, p->info_ball.size);
			setfillcolor(RED);				//颜色还原
			
			//写分值（数字）
			if (p->info_ball.select_status == 1)
			{
				setbkcolor(BLUE);			//如果是选定状态就画蓝色(文字底色)
			}
			outtextxy(p->info_ball.x - 6, p->info_ball.y - 15, p->info_ball.figure); //让数字显示在圆的中央
			setbkcolor(RED);				//颜色还原
			
			//边缘检测
			if		(p->info_ball.x - p->info_ball.size - 4 <= 20)		//碰左边线
			{
				p->info_ball.x_step = p->info_ball.x_step * -1;
			}
			else if (p->info_ball.x + p->info_ball.size + 4 >= 800)		//碰右边线
			{
				p->info_ball.x_step = p->info_ball.x_step * -1;
			}
			else if (p->info_ball.y - p->info_ball.size - 4 <= 120)		//碰上边线
			{
				p->info_ball.y_step = p->info_ball.y_step * -1;
			}
			else if (p->info_ball.y + p->info_ball.size + 4 >= 580)		//碰下边线
			{
				p->info_ball.y_step = p->info_ball.y_step * -1;
			}
			break;
		/*******************其他图形***************************
		case 2 : solidellipse(p->info_ball.x - p->info_ball.size , 
					 p->info_ball.y - p->info_ball.size ,
					 p->info_ball.x + p->info_ball.size ,
					 p->info_ball.y + p->info_ball.size );
			break;
		case 3 : solidrectangle(p->info_ball.x - p->info_ball.size , 
					 p->info_ball.y - p->info_ball.size ,
					 p->info_ball.x + p->info_ball.size ,
					 p->info_ball.y + p->info_ball.size );
			break;
		case 4 : solidroundrect(p->info_ball.x - p->info_ball.size , 
					 p->info_ball.y - p->info_ball.size ,
					 p->info_ball.x + p->info_ball.size ,
					 p->info_ball.y + p->info_ball.size ,
					 10, 10);
			break;
			*************************************************/
		}
		
		//步进（让球动起来）
		p->info_ball.x += p->info_ball.x_step;
		p->info_ball.y += p->info_ball.y_step;
		
		p = p->next;
	}
	FlushBatchDraw();
	Sleep(5);

	setbkcolor(WHITE);
	clearrectangle(22, 122, 798, 578);

	return;
}