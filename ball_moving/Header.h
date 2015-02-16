/*
* 所有.cpp都包含此文件
*/
#pragma warning(disable:4996) //fscanf_s is a mystery.
#include <stdio.h>
#include <easyx.h>
#include <stdlib.h>
#include <time.h>
#include <tchar.h>
#include <math.h>

//球的声明
struct ball{
    int number;                     //球的序号
    TCHAR figure[4];                //球的分值
    int x;                          //横坐标
    int y;                          //纵坐标
    int x_step;                     //x的变化率
    int y_step;                     //y的变化率
    int shape;                      //球的形状
    int size;                       //球的尺寸
    int select_status;              //是否被选中（1为选中并上色，2为选中但不上色）
};

//储存球信息的链表的声明
struct node_ball {
    ball info_ball;
    node_ball * next;
};

//玩家信息的声明
struct player{
    TCHAR playername[20];
    int score;
};

/******main.cpp中各个函数的原型*********/
void main_interface();                                  //画界面
void button_respond(node_ball * Head
                   , int * ball_count   
                   , struct player * point_player
                   , int * game_status
                   , int * level
                   , bool * time_flag
                   , time_t * initial_time
                   , time_t * current_time);            //可传入头结点 球数 玩家信息 等
void move_ball(node_ball * Head
              , int * ball_count
              , int * level);                           //可传入头结点和球数
void display_player_info(struct player * p);            //显示更新玩家信息
void display_ball_count(int * ball_count);              //更新球数
void input_player_info(struct player * point_player);   //输入玩家信息
void ball_timer(time_t initial_time, time_t * current_time);

/******buffton_respond.cpp中各个函数的原型*******/
void add_ball(node_ball * Head
              , int * ball_count
              , bool * time_flag
              , time_t * initial_time);                 //添加球
void delete_ball(node_ball * Head
                , int * ball_count
                , struct player * point_player
                , time_t current_time);                 //删除球
void select_ball(node_ball * Head
                , int * ball_count
                , MOUSEMSG m
                , struct player * point_player);        //第三个参数是鼠标消息
void exit_game(struct player * point_player
              , struct node_ball * Head);               //退出游戏
int save_game(struct node_ball * Head
             , struct player * point_player
             , int * ball_count
             , time_t current_time);                    //保存游戏状态
int load_game(struct node_ball * Head
             , struct player * point_player
             , int * ball_count
             , time_t * curret_time);                   //读取游戏状态

/******main_interface.cpp中各个函数的原型********/
void main_interface_button();                           //按钮绘制
void main_interface_line();                             //线绘制
void main_interface_button_text();                      //按钮中的文字绘制