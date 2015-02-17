/*
* input_player_info.cpp
* 输入玩家信息（用户名）
*/

#include "Header.h"

void input_player_info(struct player * point_player)
{
    //游戏说明
    MessageBox(NULL, _T("有两种方式取得胜利：通过删除球\n\
1、分数正好达到50分\n\
2、分数等于球数的20倍\n\
如果没点到球会扣分~\n\
点\"添加\"后开始计时\n\
越快越好噢，加油！^^")
        , _T("游戏方式"),MB_ICONASTERISK | MB_SYSTEMMODAL);

    //输入用户名的InputBox
    InputBox(point_player->playername, 20, _T("请输入用户名：(10个字符以内)"),
        _T("by Tony Wang"), _T("Player"), 0, 0, 1);

    return;
}