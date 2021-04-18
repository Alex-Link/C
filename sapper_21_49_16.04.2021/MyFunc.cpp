#pragma once

#include"MyFunc.h"
HANDLE  hConsole = GetStdHandle(STD_OUTPUT_HANDLE); // ��������� ����������� ���������� ������������ ������
COORD position;

void gotoXY(int x, int y) //���������� ������ � ��������� �����
{
	position.X = x; //��������� ���������� X
	position.Y = y;//��������� ���������� Y
	SetConsoleCursorPosition(hConsole, position);
}
void cursorColor(int color) // ��������� ����� �������
{
	SetConsoleTextAttribute(hConsole, color);
}

void cinClear()
{
	if (char(cin.peek()) == '\n')
		cin.ignore();

	if (cin.fail())
	{
		cin.clear();
		cin.ignore(32767, '\n');
	}
}
void timeSec(char* buffer, int sec, int rezhim) // ���������� ���� � ���-�� ������ 
{
	
	time_t seconds = sec;
	tm* timeinfo = localtime(&seconds);
	//char format[] = "%A, %B %d, %Y %I:%M:%S"; // ������ ����
	char format1[] = "%B %d, %Y %I:%M"; // ������ ����
	char format2[] = "%I:%M:%S"; // ������ ����
	switch (rezhim)
	{
	case 1:

		strftime(buffer, 80, format1, timeinfo);
		break;
	
	case 2:
		strftime(buffer, 80, format2, timeinfo);
		break;
	}
	
}