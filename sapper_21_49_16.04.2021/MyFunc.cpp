#pragma once

#include"MyFunc.h"
HANDLE  hConsole = GetStdHandle(STD_OUTPUT_HANDLE); // Получение дескриптора устройства стандартного вывода
COORD position;

void gotoXY(int x, int y) //установить курсор в указанном месте
{
	position.X = x; //установка координаты X
	position.Y = y;//установка координаты Y
	SetConsoleCursorPosition(hConsole, position);
}
void cursorColor(int color) // Установка цвета курсора
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
void timeSec(char* buffer, int sec, int rezhim) // возвращает дату с кол-ва секунд 
{
	
	time_t seconds = sec;
	tm* timeinfo = localtime(&seconds);
	//char format[] = "%A, %B %d, %Y %I:%M:%S"; // формат даты
	char format1[] = "%B %d, %Y %I:%M"; // формат даты
	char format2[] = "%I:%M:%S"; // формат даты
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