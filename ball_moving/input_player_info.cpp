/*
* input_player_info.cpp
* ���������Ϣ���û�����
*/

#include "Header.h"

void input_player_info(struct player * point_player)
{
    //��Ϸ˵��
    MessageBox(NULL, _T("�����ַ�ʽȡ��ʤ����ͨ��ɾ����\n\
1���������ôﵽ50��\n\
2����������������20��\n\
���û�㵽���۷�~\n\
��\"���\"��ʼ��ʱ\n\
Խ��Խ���ޣ����ͣ�^^")
        , _T("��Ϸ��ʽ"),MB_ICONASTERISK | MB_SYSTEMMODAL);

    //�����û�����InputBox
    InputBox(point_player->playername, 20, _T("�������û�����(10���ַ�����)"),
        _T("by Tony Wang"), _T("Player"), 0, 0, 1);

    return;
}