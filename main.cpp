/************************************************************************/
/*  移动小球																*/	
/*	V0.1																*/
/*	实现基本功能：添加、删除、退出、成绩记录、暂停、继续						*/
/*	V0.2																*/
/*	添加功能：导出、导入、显示球数											*/
/*  V0.3																*/
/*  基本修复各种BUG                                                      */
/*  V0.4																*/
/*  增加了对圆角矩形的支持，优化部分代码	    						    */	
/*  V0.5																*/
/*  修复选择球的BUG														*/	
/************************************************************************/

#include "Header.h"

int main()
{
	main_interface();							//绘制界面

	int game_status = 1;						//游戏状态，1为运行，0为暂停

	//玩家信息
	struct player player1;
	player1.score = 0;							//分数初始化为0
	input_player_info(&player1);				//输入玩家信息
	display_player_info(&player1);				//显示玩家信息

	//建立球链表的头结点
	struct node_ball * Head = (node_ball*)calloc(1,sizeof(node_ball)); 
	if (NULL == Head)
	{
		return -1;
	}
	Head->info_ball.number = 0;					//球初始序号为1(头结点不使用)
	Head->next = NULL;
	
	int ball_count = 0;							//球的个数初始化为0
	
	//主循环
	while(1)
	{
		BeginBatchDraw();							//开始批绘制 对应FlushBatchDraw()
		
		button_respond(Head, &ball_count, &player1, &game_status); //按钮响应
		
		display_player_info(&player1);				//更新玩家信息
		display_ball_count(&ball_count);			//更新球数信息
		
		if(ball_count != 0)							//如果有球
		{
			if(game_status)							//如果游戏状态为1时（运行）
			{
				move_ball(Head, &ball_count);		//球的运动
				
				setbkcolor(WHITE);					//用白色清屏
				clearrectangle(22, 122, 798, 578); 	
			}
		}
		else										//没球时刷新一下,避免玩家和球信息闪烁
		{
			FlushBatchDraw();
		}
	}
		
	return 0;
}