/************************************************************************/
/*  �ƶ�С��																*/	
/*	V0.1																*/
/*	ʵ�ֻ������ܣ���ӡ�ɾ�����˳����ɼ���¼����ͣ������						*/
/*	V0.2																*/
/*	��ӹ��ܣ����������롢��ʾ����											*/
/*  V0.3																*/
/*  �����޸�����BUG                                                      */
/*  V0.4																*/
/*  �����˶�Բ�Ǿ��ε�֧�֣��Ż����ִ���	    						    */	
/*  V0.5																*/
/*  �޸�ѡ�����BUG														*/	
/************************************************************************/

#include "Header.h"

int main()
{
	main_interface();							//���ƽ���

	int game_status = 1;						//��Ϸ״̬��1Ϊ���У�0Ϊ��ͣ

	//�����Ϣ
	struct player player1;
	player1.score = 0;							//������ʼ��Ϊ0
	input_player_info(&player1);				//���������Ϣ
	display_player_info(&player1);				//��ʾ�����Ϣ

	//�����������ͷ���
	struct node_ball * Head = (node_ball*)calloc(1,sizeof(node_ball)); 
	if (NULL == Head)
	{
		return -1;
	}
	Head->info_ball.number = 0;					//���ʼ���Ϊ1(ͷ��㲻ʹ��)
	Head->next = NULL;
	
	int ball_count = 0;							//��ĸ�����ʼ��Ϊ0
	
	//��ѭ��
	while(1)
	{
		BeginBatchDraw();							//��ʼ������ ��ӦFlushBatchDraw()
		
		button_respond(Head, &ball_count, &player1, &game_status); //��ť��Ӧ
		
		display_player_info(&player1);				//���������Ϣ
		display_ball_count(&ball_count);			//����������Ϣ
		
		if(ball_count != 0)							//�������
		{
			if(game_status)							//�����Ϸ״̬Ϊ1ʱ�����У�
			{
				move_ball(Head, &ball_count);		//����˶�
				
				setbkcolor(WHITE);					//�ð�ɫ����
				clearrectangle(22, 122, 798, 578); 	
			}
		}
		else										//û��ʱˢ��һ��,������Һ�����Ϣ��˸
		{
			FlushBatchDraw();
		}
	}
		
	return 0;
}