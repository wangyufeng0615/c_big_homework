/*
* input_player_info.cpp
* 输入玩家信息（用户名）
*/

#include "Header.h"

void input_player_info(struct player * point_player)
{
    //游戏说明
    MessageBox(NULL, _T("选中球，然后删掉，球上的分值累加到分数。")
        , _T("游戏方式"),MB_ICONASTERISK | MB_SYSTEMMODAL);

    //输入用户名的InputBox
    InputBox(point_player->playername, 20, _T("请输入用户名：(10个字符以内)"),
        _T("by Water Wang"), _T("WYF"), 0, 0, 1);

    return;
}