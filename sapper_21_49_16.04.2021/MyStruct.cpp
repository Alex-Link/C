#pragma once
#define _CRT_SECURE_NO_WARNINGS // доп параметр для команд strcpy(st2, st1)
#include <string.h>
#include<iostream>
#include<ctime>
#include<iomanip>
#include<typeinfo>
#include<string.h> // библиотека для работы со строками
#include<string>
#include <windows.h>   // WinApi
#include <conio.h> // для getche()
#include "MyStruct.h"
using namespace std;




void Kletka::init(int slozhnost = 30) // инициализация структурных данных 0-100 сложность( вероятность мин)
	{
		//srand(time(0)); // константа рандома
		//mina = rand()% 100; // случайная мина
		(rand() % 100 < slozhnost) ? mina = true : mina = false; //вероятность мины в зависимости от выбранной сложности
		flag = false; // флаг не установлен
		open = false; // клетка закрыта
		krugom = 0; // значение в клетке -2  - значение не определено

	}

void Kletka::print(bool cursor = false) // вывод клетки на экран в зависимости от состояния
	{
	   gotoXY(col * 2 + poleXots, row + poleYots);// Установка координаты курсора
		
		if (!open && !flag)  //если клетка не открыта и не стоит флаг на ней, то
		{
			cursorColor(colorK[cursor][0]); //Цвет курсора
			cout << setw(2) << " "; // печатать пустое место цветом закрытая клетка
		}
		else if (!open && flag) // иначе если клетка закрыта и флаг стоит, то
		{
			cursorColor(colorK[cursor][1]);//цвет курсора
			cout << setw(2) << "f"; // печатаем флаг
		}
		else if (open && mina) // если клетка открытая и там мина, то
		{
			cursorColor(colorK[cursor][2]);//цвет курсора
			cout << setw(2) << "*"; // печатать мину
		}
		else if (open && krugom > 0) // иначе если клетка открыта и значение клетки больше за 0, то
		{
			cursorColor(colorK[cursor][3] + krugom + !(krugom % 7));
            cout << setw(2) << krugom; // печатаем значения кол-ва мин вокруг
		}
		else                         // иначе
		{
			cursorColor(colorK[cursor][3]); //цвет курсора
			cout << setw(2) << " "; // печатаем пустую клетку цвета открытой клетки
		}
	}


	bool CursorK::up() // курсор шаг вверх
	{
		if (posY > 0)// проверяем перед перемещением наличие преграды
		{
			oldPosY = posY;//сохраняем старую координату расположения
			oldPosX = posX;//сохраняем старую координату расположения
			posY--; // сдвигаем вверх на 1 позицию
			return 1; //возвращаем что операция успешная
		}
		else return 0; // иначе возвращаем что операция не удалась
	}
	bool CursorK::down() // курсор шаг вниз
	{
		if (posY < poleY - 1)// проверяем перед перемещением наличие преграды
		{
			oldPosY = posY;//сохраняем старую координату расположения
			oldPosX = posX;//сохраняем старую координату расположения
			posY++; // сдвигаем вниз на 1 позицию
			return 1;//возвращаем что операция успешная
		}
		else return 0;// иначе возвращаем что операция не удалась

	}
	bool CursorK::left() // курсор шаг влево
	{
		if (posX > 0)// проверяем перед перемещением наличие преграды
		{
			oldPosY = posY;//сохраняем старую координату расположения
			oldPosX = posX;//сохраняем старую координату расположения
			posX--; // сдвигаем вниз на 1 позицию
			return 1;//возвращаем что операция успешная
		}
		else return 0;// иначе возвращаем что операция не удалась
	}
	bool CursorK::right() // курсор шаг вправо
	{
		if (posX < poleX - 1)// проверяем перед перемещением наличие преграды
		{
			oldPosY = posY;//сохраняем старую координату расположения
			oldPosX = posX;//сохраняем старую координату расположения
			posX++; // сдвигаем вниз на 1 позицию
			return 1;//возвращаем что операция успешная
		}
		else return 0;// иначе возвращаем что операция не удалась
	}
	
	void infP::init() //Инициализация переменных
	{
		colMina = 0; //кол-во мин. стартовое значение 0,  во время инициализации
		colFlag = 0; //кол-во флагов. стартовое значение 0
		colTime = 0;//инициализируем переменные
		timeStart = 0;//инициализируем переменные
		slozhnost = 69; //уровень сложности (10-60) но можно 0-100
		poleY = 2; // размер поля Ymax=27 
		poleX = 2; // размер поля Xmax=57
	}
	void infP::printHead() //печать верхную шапку
	{
		cursorColor(11);              //Цвет курсора
		gotoXY(48, 0);// Установка координаты курсора
		cout << "*** Игра Сапёр ***";
		
		cursorColor(11);              //Цвет курсора
		gotoXY(25, 29);// Установка координаты курсора
		cout << " Выход в Меню - нажмите Esc;     Количество мин: "<< colMina-colFlag<<"          ";
	}

	void UkazatelMenu::print0()//печать пустого места меню
	{
		cursorColor(color);              //Цвет курсора
		gotoXY(startX, posY);// Установка координаты курсора
		cout << " ";
	}
	void UkazatelMenu::print00()//печать пустогоместа меню
	{
		cursorColor(color);              //Цвет курсора
		gotoXY(startX, posY);// Установка координаты курсора
		cout << " ";
		gotoXY(startX + colChar, posY);// Установка координаты курсора
		cout << " ";
	}
	void UkazatelMenu::print1()//печать курсора меню
    {
        cursorColor(color);              //Цвет курсора
		gotoXY(startX, posY);// Установка координаты курсора
		cout << ">";
	}	
	void UkazatelMenu::print2()//печать 2-х курсоров
	{
		cursorColor(color);              //Цвет курсора
		gotoXY(startX, posY);// Установка координаты курсора
		cout << cursor1;
		gotoXY(startX+colChar, posY);// Установка координаты курсора
		cout << cursor2;
	}
	void UkazatelMenu::up()    //движение вверх курсора по меню
	{
		if (posY <= startY) // если позиция на стартовом месте или случайно выше его, то
		{
			print00();//печать пустого места
			posY = startY + colPos-1; // перенести позицию в самый низ
			print2();//печать 2-х курсоров
		}
		else
		{
			print00();//печать пустого места
			posY--; // шаг вниз
			print2();//печать 2-х курсоров
		}
	}
	void UkazatelMenu::down()  //движение вниз курсора по меню
	{
		if (posY >= startY+ colPos-1) // если позиция в последнем пункте или случайно ниже, то
		{
			print00();//печать пустого места
			posY = startY; // перенести позицию на самый вверх
			print2();//печать 2-х курсоров
		}
		else
		{
			print00();//печать пустого места
			posY++; //шаг вверх
			print2(); //печать 2 - х курсоров
		}
	}
	int UkazatelMenu::space() // нажатие пробела в меню
	{
		return posY - startY; // возвращаем положение курсоров меню
	}

	void score::init()
	{
		bool enable = false; // флаг что есть запись
		char name[11] = {""}; // имя победителя
		int data= time(0); // сохраняем текущее время
		int slozhnost = 10; // уровень сложности
		
	}
	void score::print(int x ,int y)
	{
		cursorColor(11); //цвет курсора
		//gotoXY(10, 10);// координата расположения
		//cout <<setw(11)<< name << endl;
		gotoXY(x,y);// координата расположения
		//for (size_t i = 0; i < 11; i++)
		//{
		//	cout << name[i]; // вывод посимвольно
		//}
		cout << name; // вывод

		char buffer[80]; //создаём буфер для даты и времени
		timeSec(buffer, data, 1); // вызвать функцию вычесление даты с секунд
		gotoXY(x + 14, y);// координата расположения
		cout << buffer; //вывести дату с буфера
		gotoXY(x + 43, y);// координата расположения
		cout << slozhnost;
		gotoXY(x + 55, y);// координата расположения
		cout << poleX << "x" << poleY; // формируем строку рекорда
		gotoXY(x + 67, y);// координата расположения
		int h, m, sec; //переменные для времени
		
		h = colTime / 3600;  // Секунды в часы
	    m = (colTime - h * 3600) / 60;  // секунды в минуты
	    sec = colTime - h * 3600 - m * 60;  // остаток секунд
		cout << h <<":"<<m<<":"<<sec;// формируем строку рекорда

	}
	void score::printHead()
	{
		cursorColor(11); //цвет курсора
		gotoXY(25, 8);// координата расположения
		cout << "--------------------------- Таблица рекордов ---------------------------";
		gotoXY(25, 9);// координата расположения
		cout << "Имя                    Дата            Сложность   Размер поля     Время";

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