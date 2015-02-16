/*
* ����.cpp���������ļ�
*/
#pragma warning(disable:4996) //fscanf_s is a mystery.
#include <stdio.h>
#include <easyx.h>
#include <stdlib.h>
#include <time.h>
#include <tchar.h>
#include <math.h>

//�������
struct ball{
    int number;                     //������
    TCHAR figure[4];                //��ķ�ֵ
    int x;                          //������
    int y;                          //������
    int x_step;                     //x�ı仯��
    int y_step;                     //y�ı仯��
    int shape;                      //�����״
    int size;                       //��ĳߴ�
    int select_status;              //�Ƿ�ѡ�У�1Ϊѡ�в���ɫ��2Ϊѡ�е�����ɫ��
};

//��������Ϣ�����������
struct node_ball {
    ball info_ball;
    node_ball * next;
};

//�����Ϣ������
struct player{
    TCHAR playername[20];
    int score;
};

/******main.cpp�и���������ԭ��*********/
void main_interface();                                  //������
void button_respond(node_ball * Head
                   , int * ball_count   
                   , struct player * point_player
                   , int * game_status
                   , int * level
                   , bool * time_flag
                   , time_t * initial_time
                   , time_t * current_time);            //�ɴ���ͷ��� ���� �����Ϣ ��
void move_ball(node_ball * Head
              , int * ball_count
              , int * level);                           //�ɴ���ͷ��������
void display_player_info(struct player * p);            //��ʾ���������Ϣ
void display_ball_count(int * ball_count);              //��������
void input_player_info(struct player * point_player);   //���������Ϣ
void ball_timer(time_t initial_time, time_t * current_time);

/******buffton_respond.cpp�и���������ԭ��*******/
void add_ball(node_ball * Head
              , int * ball_count
              , bool * time_flag
              , time_t * initial_time);                 //�����
void delete_ball(node_ball * Head
                , int * ball_count
                , struct player * point_player
                , time_t current_time);                 //ɾ����
void select_ball(node_ball * Head
                , int * ball_count
                , MOUSEMSG m
                , struct player * point_player);        //�����������������Ϣ
void exit_game(struct player * point_player
              , struct node_ball * Head);               //�˳���Ϸ
int save_game(struct node_ball * Head
             , struct player * point_player
             , int * ball_count
             , time_t current_time);                    //������Ϸ״̬
int load_game(struct node_ball * Head
             , struct player * point_player
             , int * ball_count
             , time_t * curret_time);                   //��ȡ��Ϸ״̬

/******main_interface.cpp�и���������ԭ��********/
void main_interface_button();                           //��ť����
void main_interface_line();                             //�߻���
void main_interface_button_text();                      //��ť�е����ֻ���