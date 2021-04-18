#pragma once
#define _CRT_SECURE_NO_WARNINGS // ��� �������� ��� ������ strcpy(st2, st1)
#include <string.h>
#include<iostream>
#include<ctime>
#include<iomanip>
#include<typeinfo>
#include<string.h> // ���������� ��� ������ �� ��������
#include<string>
#include <windows.h>   // WinApi
#include <conio.h> // ��� getche()
#include "MyStruct.h"
using namespace std;




void Kletka::init(int slozhnost = 30) // ������������� ����������� ������ 0-100 ���������( ����������� ���)
	{
		//srand(time(0)); // ��������� �������
		//mina = rand()% 100; // ��������� ����
		(rand() % 100 < slozhnost) ? mina = true : mina = false; //����������� ���� � ����������� �� ��������� ���������
		flag = false; // ���� �� ����������
		open = false; // ������ �������
		krugom = 0; // �������� � ������ -2  - �������� �� ����������

	}

void Kletka::print(bool cursor = false) // ����� ������ �� ����� � ����������� �� ���������
	{
	   gotoXY(col * 2 + poleXots, row + poleYots);// ��������� ���������� �������
		
		if (!open && !flag)  //���� ������ �� ������� � �� ����� ���� �� ���, ��
		{
			cursorColor(colorK[cursor][0]); //���� �������
			cout << setw(2) << " "; // �������� ������ ����� ������ �������� ������
		}
		else if (!open && flag) // ����� ���� ������ ������� � ���� �����, ��
		{
			cursorColor(colorK[cursor][1]);//���� �������
			cout << setw(2) << "f"; // �������� ����
		}
		else if (open && mina) // ���� ������ �������� � ��� ����, ��
		{
			cursorColor(colorK[cursor][2]);//���� �������
			cout << setw(2) << "*"; // �������� ����
		}
		else if (open && krugom > 0) // ����� ���� ������ ������� � �������� ������ ������ �� 0, ��
		{
			cursorColor(colorK[cursor][3] + krugom + !(krugom % 7));
            cout << setw(2) << krugom; // �������� �������� ���-�� ��� ������
		}
		else                         // �����
		{
			cursorColor(colorK[cursor][3]); //���� �������
			cout << setw(2) << " "; // �������� ������ ������ ����� �������� ������
		}
	}


	bool CursorK::up() // ������ ��� �����
	{
		if (posY > 0)// ��������� ����� ������������ ������� ��������
		{
			oldPosY = posY;//��������� ������ ���������� ������������
			oldPosX = posX;//��������� ������ ���������� ������������
			posY--; // �������� ����� �� 1 �������
			return 1; //���������� ��� �������� ��������
		}
		else return 0; // ����� ���������� ��� �������� �� �������
	}
	bool CursorK::down() // ������ ��� ����
	{
		if (posY < poleY - 1)// ��������� ����� ������������ ������� ��������
		{
			oldPosY = posY;//��������� ������ ���������� ������������
			oldPosX = posX;//��������� ������ ���������� ������������
			posY++; // �������� ���� �� 1 �������
			return 1;//���������� ��� �������� ��������
		}
		else return 0;// ����� ���������� ��� �������� �� �������

	}
	bool CursorK::left() // ������ ��� �����
	{
		if (posX > 0)// ��������� ����� ������������ ������� ��������
		{
			oldPosY = posY;//��������� ������ ���������� ������������
			oldPosX = posX;//��������� ������ ���������� ������������
			posX--; // �������� ���� �� 1 �������
			return 1;//���������� ��� �������� ��������
		}
		else return 0;// ����� ���������� ��� �������� �� �������
	}
	bool CursorK::right() // ������ ��� ������
	{
		if (posX < poleX - 1)// ��������� ����� ������������ ������� ��������
		{
			oldPosY = posY;//��������� ������ ���������� ������������
			oldPosX = posX;//��������� ������ ���������� ������������
			posX++; // �������� ���� �� 1 �������
			return 1;//���������� ��� �������� ��������
		}
		else return 0;// ����� ���������� ��� �������� �� �������
	}
	
	void infP::init() //������������� ����������
	{
		colMina = 0; //���-�� ���. ��������� �������� 0,  �� ����� �������������
		colFlag = 0; //���-�� ������. ��������� �������� 0
		colTime = 0;//�������������� ����������
		timeStart = 0;//�������������� ����������
		slozhnost = 69; //������� ��������� (10-60) �� ����� 0-100
		poleY = 2; // ������ ���� Ymax=27 
		poleX = 2; // ������ ���� Xmax=57
	}
	void infP::printHead() //������ ������� �����
	{
		cursorColor(11);              //���� �������
		gotoXY(48, 0);// ��������� ���������� �������
		cout << "*** ���� ���� ***";
		
		cursorColor(11);              //���� �������
		gotoXY(25, 29);// ��������� ���������� �������
		cout << " ����� � ���� - ������� Esc;     ���������� ���: "<< colMina-colFlag<<"          ";
	}

	void UkazatelMenu::print0()//������ ������� ����� ����
	{
		cursorColor(color);              //���� �������
		gotoXY(startX, posY);// ��������� ���������� �������
		cout << " ";
	}
	void UkazatelMenu::print00()//������ ������������ ����
	{
		cursorColor(color);              //���� �������
		gotoXY(startX, posY);// ��������� ���������� �������
		cout << " ";
		gotoXY(startX + colChar, posY);// ��������� ���������� �������
		cout << " ";
	}
	void UkazatelMenu::print1()//������ ������� ����
    {
        cursorColor(color);              //���� �������
		gotoXY(startX, posY);// ��������� ���������� �������
		cout << ">";
	}	
	void UkazatelMenu::print2()//������ 2-� ��������
	{
		cursorColor(color);              //���� �������
		gotoXY(startX, posY);// ��������� ���������� �������
		cout << cursor1;
		gotoXY(startX+colChar, posY);// ��������� ���������� �������
		cout << cursor2;
	}
	void UkazatelMenu::up()    //�������� ����� ������� �� ����
	{
		if (posY <= startY) // ���� ������� �� ��������� ����� ��� �������� ���� ���, ��
		{
			print00();//������ ������� �����
			posY = startY + colPos-1; // ��������� ������� � ����� ���
			print2();//������ 2-� ��������
		}
		else
		{
			print00();//������ ������� �����
			posY--; // ��� ����
			print2();//������ 2-� ��������
		}
	}
	void UkazatelMenu::down()  //�������� ���� ������� �� ����
	{
		if (posY >= startY+ colPos-1) // ���� ������� � ��������� ������ ��� �������� ����, ��
		{
			print00();//������ ������� �����
			posY = startY; // ��������� ������� �� ����� �����
			print2();//������ 2-� ��������
		}
		else
		{
			print00();//������ ������� �����
			posY++; //��� �����
			print2(); //������ 2 - � ��������
		}
	}
	int UkazatelMenu::space() // ������� ������� � ����
	{
		return posY - startY; // ���������� ��������� �������� ����
	}

	void score::init()
	{
		bool enable = false; // ���� ��� ���� ������
		char name[11] = {""}; // ��� ����������
		int data= time(0); // ��������� ������� �����
		int slozhnost = 10; // ������� ���������
		
	}
	void score::print(int x ,int y)
	{
		cursorColor(11); //���� �������
		//gotoXY(10, 10);// ���������� ������������
		//cout <<setw(11)<< name << endl;
		gotoXY(x,y);// ���������� ������������
		//for (size_t i = 0; i < 11; i++)
		//{
		//	cout << name[i]; // ����� �����������
		//}
		cout << name; // �����

		char buffer[80]; //������ ����� ��� ���� � �������
		timeSec(buffer, data, 1); // ������� ������� ���������� ���� � ������
		gotoXY(x + 14, y);// ���������� ������������
		cout << buffer; //������� ���� � ������
		gotoXY(x + 43, y);// ���������� ������������
		cout << slozhnost;
		gotoXY(x + 55, y);// ���������� ������������
		cout << poleX << "x" << poleY; // ��������� ������ �������
		gotoXY(x + 67, y);// ���������� ������������
		int h, m, sec; //���������� ��� �������
		
		h = colTime / 3600;  // ������� � ����
	    m = (colTime - h * 3600) / 60;  // ������� � ������
	    sec = colTime - h * 3600 - m * 60;  // ������� ������
		cout << h <<":"<<m<<":"<<sec;// ��������� ������ �������

	}
	void score::printHead()
	{
		cursorColor(11); //���� �������
		gotoXY(25, 8);// ���������� ������������
		cout << "--------------------------- ������� �������� ---------------------------";
		gotoXY(25, 9);// ���������� ������������
		cout << "���                    ����            ���������   ������ ����     �����";

	}
	void score::add(char *n,int slozh, int poY, int poX,int coT)
	{
		bool enable=true;
		char name=*n;
		int data= time(0);
		int slozhnost = slozh;
		int poleY=poY;
		int poleX=poX;
		int colTime= coT;
	}