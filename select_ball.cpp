/*
 *	select_ball.cpp
 *	对球进行选中操作
 */

#include "Header.h"

void select_ball(node_ball * Head, int * ball_count, MOUSEMSG m)
{
	node_ball * p = Head;

	if(*ball_count > 0) //如果还有球的话
	{
		Head->next->info_ball.select_status = 2; //如果点到空白，那么第一个球被选中（不上色）
	}

	double distance; //鼠标的点的距离到圆心的距离

	//此循环：选中某个圆
	int i;
	for (i = 0; i < *ball_count; i++) 
	{
		distance = sqrt(powf((float)(p->next->info_ball.x - m.x), 2) + powf( (float)(p->next->info_ball.y - m.y), 2 ));
		if (distance < p->next->info_ball.size)
		{
			p->next->info_ball.select_status = 1;
			break;
		}
		p = p->next;
	}

	//将其他的选中状态变为0
	if (i != *ball_count && *ball_count > 0) //如果没点中任何点的话
	{
		p = Head;
		int j;
		for (j = 0; j < *ball_count; j++)
		{
			if (i == j)
			{
				p = p->next;
				continue; //跳过已经设置为1的球
			}
			p->next->info_ball.select_status = 0;
			p = p->next;
		}
	}
	

	return;
}