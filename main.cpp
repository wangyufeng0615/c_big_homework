/************************************************************************/
/*  C�����V0.1  														*/
/*	ʵ�ֻ������ܣ���ӡ�ɾ�����˳����ɼ���¼����ͣ��������					*/
/************************************************************************/

#include "Header.h"

int main()
{
	main_interface();							//���ƽ���

	int game_status = 1;						//��Ϸ״̬��1Ϊ���У�0Ϊ��ͣ

	//�����Ϣ
	struct player player1;
	player1.score = 0;							//������ʼ��Ϊ0
	input_player_info(&player1);

	//�����������ͷ���
	struct node_ball * Head = (node_ball*)calloc(1,sizeof(node_ball)); 
	if (NULL == Head)
	{
		return -1;
	}
	Head->info_ball.number = 0;					//���ʼ���Ϊ0
	Head->next = NULL;
	
	int ball_count = 0;							//��ĸ�����ʼ��Ϊ0

	display_player_info(&player1);				//������ʾ�����Ϣ
	
	while(1)
	{
		button_respond(Head, &ball_count, &player1, &game_status); //��ť��Ӧ
		if(ball_count != 0)						//�������
		{
			if(game_status)						//�����Ϸ״̬Ϊ1ʱ�����У�
			{
				move_ball(Head, &ball_count);	//����˶�
				setbkcolor(WHITE);				//�ð�ɫ����
				clearrectangle(22, 122, 798, 578); 
				display_player_info(&player1);  //���������Ϣ	
			}
		}
		else //û��ˢ��һ��
		{
			EndBatchDraw();
		}
	}
		
	return 0;
}