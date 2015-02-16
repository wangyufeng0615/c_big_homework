/*
* exit_game.cpp
* 退出游戏，保存玩家信息
*/

#include "Header.h"

void exit_game(struct player * point_player, struct node_ball * Head)
{
    //此处曾经有退出时保存玩家分数的功能
    //已改为获胜条件触发时保存

    free(Head);     //释放球
    closegraph();
    exit(0);
}