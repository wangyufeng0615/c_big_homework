/*
 *	move_ball.cpp
 *	ʵ������ƶ�
 */

#include "Header.h"

void move_ball(node_ball * Head, int * ball_count)
{
	node_ball * p = NULL;					//����ָ��
	p = Head->next;							//�ӵ�һ����ʼ

	setfillcolor(RED);						//Բ�������ɫ
 	settextcolor(WHITE);					//���ֵ���ɫ
	setbkcolor(RED);						//���ֵı�����ɫ
	
	int i;
	for (i = 0; i < *ball_count; i++)		//ÿ��ѭ���������򶼻�һ��
	{
		switch (p->info_ball.shape) 
		{
		//Բ
		case 1 :							 
			if (p->info_ball.select_status == 1)			
			{
				setfillcolor(BLUE);			//�����ѡ��״̬�ͻ���ɫ(������������������Ǹ�����Ȼ��ѡ��������ɫ)
			}
			solidcircle(p->info_ball.x, p->info_ball.y, p->info_ball.size);
			setfillcolor(RED);				//��ɫ��ԭ
			
			//д��ֵ�����֣�
			if (p->info_ball.select_status == 1)
			{
				setbkcolor(BLUE);			//�����ѡ��״̬�ͻ���ɫ(���ֵ�ɫ)
			}
			outtextxy(p->info_ball.x - 6, p->info_ball.y - 15, p->info_ball.figure); //��������ʾ��Բ������
			setbkcolor(RED);				//��ɫ��ԭ
			
			//��Ե���
			if		(p->info_ball.x - p->info_ball.size - 4 <= 20)		//�������
			{
				p->info_ball.x = 20 + p->info_ball.size + 4;
				p->info_ball.x_step = p->info_ball.x_step * -1;
			}
			else if (p->info_ball.x + p->info_ball.size + 4 >= 800)		//���ұ���
			{
				p->info_ball.x = 800 - p->info_ball.size - 4; 
				p->info_ball.x_step = p->info_ball.x_step * -1;
			}
			else if (p->info_ball.y - p->info_ball.size - 4 <= 120)		//���ϱ���
			{
				p->info_ball.y = 120 + p->info_ball.size + 4;
				p->info_ball.y_step = p->info_ball.y_step * -1;
			}
			else if (p->info_ball.y + p->info_ball.size + 4 >= 580)		//���±���
			{
				p->info_ball.y = 580 - p->info_ball.size - 4;
				p->info_ball.y_step = p->info_ball.y_step * -1;
			}
			break;
		
		//Բ�Ǿ���
		case 2 : 
			if (p->info_ball.select_status == 1)
			{
				setfillcolor(BLUE);			//�����ѡ��״̬�ͻ���ɫ(������������������Ǹ�����Ȼ��ѡ��������ɫ)
			}
			solidroundrect(p->info_ball.x - p->info_ball.size,
				p->info_ball.y - p->info_ball.size,
				p->info_ball.x + p->info_ball.size,
				p->info_ball.y + p->info_ball.size,
				10, 10);
			setfillcolor(RED);				//��ɫ��ԭ

											//д��ֵ�����֣�
			if (p->info_ball.select_status == 1)
			{
				setbkcolor(BLUE);			//�����ѡ��״̬�ͻ���ɫ(���ֵ�ɫ)
			}
			outtextxy(p->info_ball.x - 6, p->info_ball.y - 15, p->info_ball.figure); //��������ʾ��Բ������
			setbkcolor(RED);				//��ɫ��ԭ

											//��Ե���
			if (p->info_ball.x - p->info_ball.size - 4 <= 20)		//�������
			{
				p->info_ball.x = 20 + p->info_ball.size + 4;
				p->info_ball.x_step = p->info_ball.x_step * -1;
			}
			else if (p->info_ball.x + p->info_ball.size + 4 >= 800)		//���ұ���
			{
				p->info_ball.x = 800 - p->info_ball.size - 4;
				p->info_ball.x_step = p->info_ball.x_step * -1;
			}
			else if (p->info_ball.y - p->info_ball.size - 4 <= 120)		//���ϱ���
			{
				p->info_ball.y = 120 + p->info_ball.size + 4;
				p->info_ball.y_step = p->info_ball.y_step * -1;
			}
			else if (p->info_ball.y + p->info_ball.size + 4 >= 580)		//���±���
			{
				p->info_ball.y = 580 - p->info_ball.size - 4;
				p->info_ball.y_step = p->info_ball.y_step * -1;
			}


			break;
		}
		
		//����������������
		p->info_ball.x += p->info_ball.x_step;
		p->info_ball.y += p->info_ball.y_step;
		
		p = p->next;
	}
	FlushBatchDraw();						//һ�λ�ȫ�����򣬱�����˸
	Sleep(5);

	setbkcolor(WHITE);
	clearrectangle(22, 122, 798, 578);

	return;
}