/*
* delete_ball.cpp
* ɾ��һ����
* ������ʤ����+�����Ϣ
*/

#include "Header.h"

void update_score(int add_score, struct player * point_player); //ˢ����ҷ���

void delete_ball(node_ball * Head, int * ball_count, struct player * point_player, time_t current_time)
{
    struct node_ball * p = Head;            //��ǰָ��ָ��ͷ���
    struct node_ball * temp;                //����free��ɾ������

    //����ĸ���ѡ���ˣ������ѡ�ϣ���ɾ��
    int i;
    for (i = 0; i < *ball_count; i++)
    {
        if (1 == p->next->info_ball.select_status || 2 == p->next->info_ball.select_status) //�����ѡ��
        {
            temp = p->next;
            if (p->next->next != NULL) //���Ҫɾ������ڵ���б�Ľڵ�Ļ�
            {
                p->next= p->next->next;
            }
            else
            {
                p->next = NULL;
            }

            //���ӷ���
            if (1 == temp->info_ball.select_status)         //������δѡ��״̬�±�ɾ�������ӷ�
            {
                int add_score;
                add_score = _wtoi(temp->info_ball.figure);
                update_score(add_score, point_player);
            }

            //���������Ϣ
            setbkcolor(WHITE);
            clearrectangle(482, 26, 798, 118);
            display_player_info(point_player);

            free(temp);                             //�ͷű�ɾ����Ŀռ�

            (*ball_count)--;                        //������-1

            if (Head->next != NULL) //�������ʱ��ɾ��һ������������ɵ���ѡ��
            {
                Head->next->info_ball.select_status = 2; //2�Ǳ�ѡ�У����ǲ���ɫ
            }
            else //һ����Ҳ��ʣ��
            {
                setfillcolor(WHITE);
                clearrectangle(24, 121, 798, 576);  //�ð�ɫ����
            }

            break; //!!!
        }
        else
        {
            p = p->next;
        }
    }

    //��ʤ����������
    if ((point_player->score == (*ball_count) * 20 && *ball_count != 0) || point_player->score == 50)
    {
        int temp_level = 2;                 //��ʱ��level������Ϊ�������״̬ˢ��һ��
        display_ball_count(ball_count);     //����������Ϣ
        move_ball(Head, ball_count, &temp_level); //����˶�

        if (point_player->score == (*ball_count) * 20 && *ball_count != 0)
        {
            MessageBox(NULL, _T("��Ӯ������������������20����"), _T("Win!"),MB_ICONASTERISK | MB_SYSTEMMODAL);
        }
        if (point_player->score == 50)
        {
            MessageBox(NULL, _T("��Ӯ��������������50��"), _T("Win!"),MB_ICONASTERISK | MB_SYSTEMMODAL);
        }

        //����ʱ��
        time_t t = time(0);
        char time_temp[64];
        struct tm lt;
        localtime_s(&lt, &t);
        //strftime(time_temp, sizeof(time_temp), "%Y/%m/%d %X", &lt); �����������Сʱ����
        strftime(time_temp, sizeof(time_temp), "%m/%d", &lt);
        
        //�ļ�ָ��
        FILE * fp_result;
        if (fopen_s(&fp_result, "player_info.csv", "a+"))
        {
            MessageBox(NULL, _T("�ɼ���¼�ļ���ʧ�ܣ�"), _T("����"), MB_SYSTEMMODAL);
            return;
        }

        //TCHAR*תchar*
        char playername_output[20];
        WideCharToMultiByte(CP_ACP, 0, point_player->playername, 20, playername_output, 20, 0, 0);
        fprintf(fp_result, "%s,%s,%d\n"
                         , time_temp
                         , playername_output
                         , current_time);
        fclose(fp_result);

        //������ʾ��Ϣ
        MessageBox(NULL,_T("�û�������ʱ����Ϣ�ѱ����� player_info.csv (��Excel��)"), _T("�ݰ�~"), MB_SYSTEMMODAL | MB_ICONASTERISK);
        
        exit_game(point_player, Head);
    }



    return;
}

void update_score(int add_score, struct player * point_player)
{
    point_player->score += add_score;               //�ۼ���ҵ÷�

    return;
}