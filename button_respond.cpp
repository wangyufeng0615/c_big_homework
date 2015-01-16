/*
 *	button_respond.cpp
 *	����԰�ť�������Ӧ
 */

#include "Header.h"

static MOUSEMSG m;

void button_respond(struct node_ball * Head, int * ball_count, struct player * point_player, int * game_status)
{
	while(MouseHit())
	{
		m = GetMouseMsg();
		if (m.uMsg == WM_LBUTTONDOWN)
		{
			if(1 == *game_status)			//�����Ϸ������ͣ״̬��ֻ�С����������԰�
			{
				if (m.x >= 360 && m.x <= 480 && m.y >= 40 && m.y <= 100)	//�˳�
				{
					exit_game(point_player, Head);
				}
				if (m.x >= 40 && m.x <= 160 && m.y <= 100 && m.y >= 40)		//���
				{
					add_ball(Head, ball_count);
				}
				if (m.x >= 200 && m.x <= 320 && m.y <= 100 && m.y >= 40)	//ɾ��
				{
					delete_ball(Head, ball_count, point_player);
				}
				if (m.x >= 20 && m.x <= 800 && m.y >= 120 && m.y <= 580)	//ѡ�����������
				{
					select_ball(Head, ball_count, m);
				}
				if (m.x <= 950 && m.x >= 830 && m.y >= 240 && m.y <= 300)	//��ͣ
				{
					*game_status = 0;
				}
				if (m.x >= 830 && m.x <= 950 && m.y >= 40 && m.y <= 100)	//����״̬
				{
					if(!save_game(Head, point_player, ball_count))			//����ɹ�
					{
						MessageBox(NULL, _T("����״̬��save.txt�ɹ���"), _T("��ʾ"), MB_SYSTEMMODAL | MB_ICONASTERISK);
					}
				}
				if (m.x >= 830 && m.x <= 950 && m.y <= 200 && m.y >= 140)	//����״̬
				{
					if(!read_game(Head, point_player, ball_count))
					{
						MessageBox(NULL, _T("��save.txt��ȡ״̬�ɹ���"), _T("��ʾ"), MB_SYSTEMMODAL | MB_ICONASTERISK);
					}
				}

			}
			else if (0 == *game_status)  //��������ͣʱ��ֻ�ܰ�����
			{
				if (m.x <= 950 && m.x >= 830 && m.y >= 340 && m.y <= 400)	//����
				{
					*game_status = 1;
				}
			}
		}
	}

	return;
}
