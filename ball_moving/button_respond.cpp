/*
* button_respond.cpp
* ����԰�ť�������Ӧ
*/

#include "Header.h"

static time_t time_pause;                   //ʵ����ͣʱ����ʱ�Ĺ��ܣ�˼·��initial_time += ��ͣ��ʱ��
static bool difficulty_message_flag = true; //��һ�ε���ʱ������ʾ

void button_respond(struct node_ball * Head, int * ball_count
                    , struct player * point_player, int * game_status
                    , int * level, bool * time_flag, time_t * initial_time, time_t * current_time)
{
    MOUSEMSG m;

    while(MouseHit())
    {
        m = GetMouseMsg();
        if (m.uMsg == WM_LBUTTONDOWN)
        {
            if(1 == *game_status)                                        //ֻ�е���Ϸ��������״̬ʱ�ܰ��ļ�
            {                
                if (m.x >= 40 && m.x <= 160 && m.y <= 100 && m.y >= 40)  //���
                {
                    add_ball(Head, ball_count, time_flag, initial_time);
                }
               
                if (m.x >= 200 && m.x <= 320 && m.y <= 100 && m.y >= 40) //ɾ��
                {
                    delete_ball(Head, ball_count, point_player, *current_time);
                }
                
                if (m.x >= 20 && m.x <= 800 && m.y >= 120 && m.y <= 580) //ѡ�����������
                {
                    select_ball(Head, ball_count, m, point_player);
                }
                
                if (m.x <= 950 && m.x >= 830 && m.y >= 240 && m.y <= 300) //��ͣ
                {
                    *game_status = 0;
                    time_pause = time(NULL);                      
                }
                
                if (m.x >= 890 && m.x <= 915 && m.y >= 425 && m.y <= 450) //�Ѷ�����
                {
                    if(difficulty_message_flag)
                    {
                        MessageBox(NULL, _T("���ٽ������ԣ�������Ϸ��һ���֣�����Ĭ���ٶ�����ս��Ϸ~\n����Ϣֻ��ʾһ��"), _T("�����ٶȵ���"),MB_ICONASTERISK | MB_SYSTEMMODAL);
                        difficulty_message_flag = false;
                    }

                    if (*level >= 0 && *level <= 12)
                    {
                        *level -= 2;
                        if (0 > *level)
                        {
                            *level = 0;     //����ٶ�
                        }
                    }
                }
                
                if (m.x >= 930 && m.x <= 955 && m.y >= 425 && m.y <= 450) //�Ѷȼ�С
                {
                    if(difficulty_message_flag)
                    {
                        MessageBox(NULL, _T("���ٽ������ԣ�������Ϸ��һ���֣�����Ĭ���ٶ�����ս��Ϸ~\n����Ϣֻ��ʾһ��"), _T("�����ٶȵ���"),MB_ICONASTERISK | MB_SYSTEMMODAL);
                        difficulty_message_flag = false;
                    }

                    if (*level >= 0 && *level <= 12)
                    {
                        *level += 2;
                        if (12 < *level)
                        {
                            *level = 12;    //�����ٶ�
                        }
                    }
                }
            }
            else if (0 == *game_status)                                   //ֻ�е�������ͣʱ�����ܰ�����
            {
                if (m.x <= 950 && m.x >= 830 && m.y >= 340 && m.y <= 400) //����
                {
                    *game_status = 1;
                    *initial_time += (time(NULL) - time_pause);           //���ʱ����������
                }
            }
            
            if (1 == *game_status || 0 == *game_status)              //����ʲô��Ϸ״̬�£������԰��ļ�
            {
                if (m.x >= 360 && m.x <= 480 && m.y >= 40 && m.y <= 100) //�˳�
                {
                    MessageBox(NULL,_T("�ݰ�~~"), _T("�ر����ɣ�"), MB_SYSTEMMODAL | MB_ICONASTERISK);
                    exit_game(point_player, Head);
                }
                
                if (m.x >= 830 && m.x <= 950 && m.y >= 40 && m.y <= 100)  //����״̬
                {
                    if(!save_game(Head, point_player, ball_count, *current_time))
                    {
                        MessageBox(NULL, _T("����״̬�� save.dat �ɹ���"), _T("��ʾ"),
                            MB_SYSTEMMODAL | MB_ICONASTERISK);
                    }
                }

                if (m.x >= 830 && m.x <= 950 && m.y <= 200 && m.y >= 140) //����״̬
                {
                    if(!load_game(Head, point_player, ball_count, current_time))
                    {
                        *time_flag = true;                                //�ָ���ʱ״̬
                        *game_status = true;                              //�ָ���Ϸ����״̬
                        *initial_time = time(NULL) - *current_time;       //����ʱ�䣬������ʱ
                        MessageBox(NULL, _T("�� save.dat ��ȡ״̬�ɹ���"), _T("��ʾ"),
                            MB_SYSTEMMODAL | MB_ICONASTERISK);
                    }
                }
            }
        }
    }

    return;
}