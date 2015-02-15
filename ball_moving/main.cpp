/*�汾������Ϣ��README.md��*/

#include "Header.h"
#define DEFAULT_DIFFICULTY 6                        //Ĭ���Ѷ�(ԽСԽ��)
#define DEFAULT_STATUS 1                            //Ĭ����Ϸ״̬��1���У�0��ͣ

int main()
{
    main_interface();                               //���ƽ���

    int game_status = DEFAULT_STATUS;               //��Ϸ״̬��1���У�0��ͣ

    int level = DEFAULT_DIFFICULTY;                 //Ĭ�ϵ��Ѷ�Ϊ6(Sleep)

    //�����Ϣ
    struct player player1;
    player1.score = 0;                              //������ʼ��Ϊ0
    input_player_info(&player1);                    //���������Ϣ
    display_player_info(&player1);                  //��ʾ�����Ϣ

    //�����������ͷ���
    struct node_ball * Head = (node_ball*)calloc(1,sizeof(node_ball));
    if (NULL == Head)
    {
        return -1;
    }
    Head->info_ball.number = 0;             //���ʼ���Ϊ1(ͷ��㲻ʹ��)
    Head->next = NULL;

    int ball_count = 0;                     //��ĸ�����ʼ��Ϊ0

    //��ѭ��
    while(1)
    {
        BeginBatchDraw(); //��ʼ������ ��ӦFlushBatchDraw()

        button_respond(Head, &ball_count, &player1, &game_status, &level); //��ť��Ӧ

        display_player_info(&player1);      //���������Ϣ
        display_ball_count(&ball_count);    //����������Ϣ

        if(ball_count != 0)                 //�������
        {
            if(game_status)                 //�����Ϸ״̬Ϊ1ʱ�����У�
            {
                move_ball(Head, &ball_count, &level); //����˶�

                setbkcolor(WHITE);          //�ð�ɫ����
                clearrectangle(24, 121, 798, 576);
            }
        }
        else //û��ʱˢ��һ��,������Һ�����Ϣ��˸
        {
            FlushBatchDraw();
        }
    }

    return 0;
}