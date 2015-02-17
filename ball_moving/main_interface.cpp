/*
* main_interface.cpp
* ���ƽ���
*/

#include "Header.h"

void main_interface()
{
    initgraph(1000, 600);           //��ʼ��
    setbkcolor(WHITE);              //����ɫ��ɫ
    cleardevice();                  //���

    setlinecolor(BLACK);            //����������ɫ
    setlinestyle(PS_SOLID, 8);      //���8
    rectangle(20, 20, 980, 580);    //����߿�
    setlinestyle(PS_SOLID, 3);      //��Ȼ�ԭ

    main_interface_button();        //��������ť�߿�
    main_interface_line();          //������������
    main_interface_button_text();   //д������ť������

    return;
}

void main_interface_button()
{
    rectangle(40, 40, 160, 100);    //����
    rectangle(200, 40, 320, 100);   //ɾ��
    rectangle(360, 40, 480, 100);   //�˳�
    rectangle(830, 40, 950, 100);   //����״̬
    rectangle(830, 140, 950, 200);  //����״̬
    rectangle(830, 240, 950, 300);  //��ͣ
    rectangle(830, 340, 950, 400);  //����

    return;
}

void main_interface_line()
{
    setlinestyle(PS_SOLID, 2);      //�߿�
    setlinecolor(BLUE);             //��ɫ
    line(20, 120, 800, 120);        //������
    line(800, 20, 800, 580);        //������

    return;
}

void main_interface_button_text()
{
    LOGFONT ball_text;              //��������
    gettextstyle(&ball_text);
    _tcscpy(ball_text.lfFaceName, _T("����"));
    ball_text.lfHeight = 32;
    ball_text.lfQuality = ANTIALIASED_QUALITY;
    settextstyle(&ball_text);
    settextcolor(BLACK);            //���ֺ�ɫ

    outtextxy(75  - 5, 53,  _T("���"));
    outtextxy(235 - 5, 53,  _T("ɾ��"));
    outtextxy(395 - 5, 53,  _T("�˳�"));
    outtextxy(865 - 5, 253, _T("��ͣ"));
    outtextxy(865 - 5, 353, _T("����"));
    outtextxy(865 - 5, 53,  _T("����"));
    outtextxy(865 - 5, 153, _T("����"));
    
    //ball_text.lfHeight = 10;
    outtextxy(820,     420, _T("�ٶ�"));
    //ball_text.lfHeight = 10;
    outtextxy(895,     422, _T("+"));
    outtextxy(935,     422, _T("-"));

    outtextxy(820,     475, _T("��ʱ:"));

    setlinecolor(BLACK);            //����������ɫ
    rectangle(890, 425, 915, 450);  //�Ѷ�����
    rectangle(930, 425, 955, 450);  //�Ѷȼ�С

    outtextxy(820, 530, _T("����:"));

    return;
}