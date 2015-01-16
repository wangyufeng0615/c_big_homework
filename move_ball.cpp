/*
 *	move_ball.cpp
 *	ʵ������ƶ�
 */

#include "Header.h"

void move_ball(node_ball * Head, int * ball_count)
{
	node_ball * p = NULL;					//����ָ��

	setfillcolor(RED);						//Բ�������ɫ
 	settextcolor(WHITE);					//���ֵ���ɫ
	setbkcolor(RED);						//���ֵı�����ɫ
	
//	settextstyle(32, 0, _T("΢���ź�"));     //��������

	p = Head->next;							//�ӵ�һ����ʼ
	
	BeginBatchDraw();						//test��������ͼ

	int i;
	for (i = 0; i < *ball_count; i++)		//ÿ��ѭ���������򶼻�һ��
	{
		switch (p->info_ball.shape) 
		{
		case 1 :							//��Բ 
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
				p->info_ball.x_step = p->info_ball.x_step * -1;
			}
			else if (p->info_ball.x + p->info_ball.size + 4 >= 800)		//���ұ���
			{
				p->info_ball.x_step = p->info_ball.x_step * -1;
			}
			else if (p->info_ball.y - p->info_ball.size - 4 <= 120)		//���ϱ���
			{
				p->info_ball.y_step = p->info_ball.y_step * -1;
			}
			else if (p->info_ball.y + p->info_ball.size + 4 >= 580)		//���±���
			{
				p->info_ball.y_step = p->info_ball.y_step * -1;
			}
			break;
		/*******************����ͼ��***************************
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
		
		//����������������
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