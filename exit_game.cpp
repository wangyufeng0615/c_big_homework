/*
 *	exit_game.cpp
 *	退出游戏，保存玩家信息
 */

#include "Header.h"

void exit_game(struct player * point_player, struct node_ball * Head)
{
	//设置时间
	time_t t = time(0);
	char time_temp[64];
	struct tm lt;
	localtime_s(&lt, &t);
	strftime(time_temp, sizeof(time_temp), "%Y/%m/%d %X", &lt);
	
	//文件指针
	FILE * fp_result;
	if (fopen_s(&fp_result, "player_info.txt", "a+"))
	{
		MessageBox(NULL, _T("结果记录文件打开失败！"), _T("错误"), MB_SYSTEMMODAL); 
		return;
	}
	
	//TCHAR*转char*
	char playername_output[20];						
	WideCharToMultiByte(CP_ACP, 0, point_player->playername, 20, playername_output, 20, 0, 0);
	fprintf(fp_result, "%s\t\t用户名:%s\t\t\t分数:%d\n", time_temp, 
			playername_output, point_player->score);
	fclose(fp_result);

	//弹出提示消息
	MessageBox(NULL,_T("用户名和分数已经保存至player_info.txt"), _T("拜拜~"), MB_SYSTEMMODAL | MB_ICONASTERISK);

	free(Head);							//释放球
	closegraph();						
	exit(0);
}