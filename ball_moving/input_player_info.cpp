/*
* input_player_info.cpp
* ���������Ϣ���û�����
*/

#include "Header.h"

void input_player_info(struct player * point_player)
{
    //��Ϸ˵��
    MessageBox(NULL, _T("ѡ����Ȼ��ɾ�������ϵķ�ֵ�ۼӵ�������")
        , _T("��Ϸ��ʽ"),MB_ICONASTERISK | MB_SYSTEMMODAL);

    //�����û�����InputBox
    InputBox(point_player->playername, 20, _T("�������û�����(10���ַ�����)"),
        _T("by Water Wang"), _T("WYF"), 0, 0, 1);

    return;
}