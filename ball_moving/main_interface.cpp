/*
* main_interface.cpp
* 绘制界面
*/

#include "Header.h"

void main_interface()
{
    initgraph(1000, 600);           //初始化
    setbkcolor(WHITE);              //背景色白色
    cleardevice();                  //清空

    setlinecolor(BLACK);            //设置线条黑色
    setlinestyle(PS_SOLID, 8);      //宽度8
    rectangle(20, 20, 980, 580);    //画大边框
    setlinestyle(PS_SOLID, 3);      //宽度还原

    main_interface_button();        //画各个按钮边框
    main_interface_line();          //画横竖两条线
    main_interface_button_text();   //写各个按钮的文字

    return;
}

void main_interface_button()
{
    rectangle(40, 40, 160, 100);    //增加
    rectangle(200, 40, 320, 100);   //删除
    rectangle(360, 40, 480, 100);   //退出
    rectangle(830, 40, 950, 100);   //导出状态
    rectangle(830, 140, 950, 200);  //导入状态
    rectangle(830, 240, 950, 300);  //暂停
    rectangle(830, 340, 950, 400);  //继续

    return;
}

void main_interface_line()
{
    setlinestyle(PS_SOLID, 2);      //线宽
    setlinecolor(BLUE);             //蓝色
    line(20, 120, 800, 120);        //画横线
    line(800, 20, 800, 580);        //画竖线

    return;
}

void main_interface_button_text()
{
    LOGFONT ball_text;              //设置字体
    gettextstyle(&ball_text);
    _tcscpy(ball_text.lfFaceName, _T("黑体"));
    ball_text.lfHeight = 32;
    ball_text.lfQuality = ANTIALIASED_QUALITY;
    settextstyle(&ball_text);
    settextcolor(BLACK);            //文字黑色

    outtextxy(75  - 5, 53,  _T("添加"));
    outtextxy(235 - 5, 53,  _T("删除"));
    outtextxy(395 - 5, 53,  _T("退出"));
    outtextxy(865 - 5, 253, _T("暂停"));
    outtextxy(865 - 5, 353, _T("继续"));
    outtextxy(865 - 5, 53,  _T("导出"));
    outtextxy(865 - 5, 153, _T("导入"));
    
    //ball_text.lfHeight = 10;
    outtextxy(820,     420, _T("速度"));
    //ball_text.lfHeight = 10;
    outtextxy(895,     422, _T("+"));
    outtextxy(935,     422, _T("-"));

    outtextxy(820,     475, _T("用时:"));

    setlinecolor(BLACK);            //设置线条黑色
    rectangle(890, 425, 915, 450);  //难度增加
    rectangle(930, 425, 955, 450);  //难度减小

    outtextxy(820, 530, _T("球数:"));

    return;
}