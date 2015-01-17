/*
 *	exit_game.cpp
 *	�˳���Ϸ�����������Ϣ
 */

#include "Header.h"

void exit_game(struct player * point_player, struct node_ball * Head)
{
	//����ʱ��
	time_t t = time(0);
	char time_temp[64];
	struct tm lt;
	localtime_s(&lt, &t);
	strftime(time_temp, sizeof(time_temp), "%Y/%m/%d %X", &lt);
	
	//�ļ�ָ��
	FILE * fp_result;
	if (fopen_s(&fp_result, "player_info.txt", "a+"))
	{
		MessageBox(NULL, _T("�����¼�ļ���ʧ�ܣ�"), _T("����"), MB_SYSTEMMODAL); 
		return;
	}
	
	//TCHAR*תchar*
	char playername_output[20];						
	WideCharToMultiByte(CP_ACP, 0, point_player->playername, 20, playername_output, 20, 0, 0);
	fprintf(fp_result, "%s\t\t�û���:%s\t\t\t����:%d\n", time_temp, 
			playername_output, point_player->score);
	fclose(fp_result);

	//������ʾ��Ϣ
	MessageBox(NULL,_T("�û����ͷ����Ѿ�������player_info.txt"), _T("�ݰ�~"), MB_SYSTEMMODAL | MB_ICONASTERISK);

	free(Head);							//�ͷ���
	closegraph();						
	exit(0);
}