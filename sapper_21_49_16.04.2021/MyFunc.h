#ifndef MyFunc_h
#define MyFunc_h

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
#include <chrono> //для времени
#include <thread>//для времени
using namespace std;

template<class T>
void createArr2D(T**& p, int row, int col) // выделяем память для динамического массива 2D
{
	p = new T * [row];
	for (size_t i = 0; i < row; i++)
	{
		p[i] = new T[col];
	}
}
template<class T>
void deleteArr2D(T**& p, int row) // удаление массива из памяти(освобождение памяти)
{
	for (size_t i = 0; i < row; i++)
	{
		delete[]p[i];
	}
	delete[]p;
	p = nullptr;
}

template <class T>
int scanMiner(T** pole, int poleY, int poleX, int hod[][8], int y, int x) // рекурсия по поиску клеток и их значений возле мин
{
	if (x < 0 || x >= poleX || y < 0 || y >= poleY || pole[y][x].open) return 2; // если выходим за координаты то возвращаем 2
	else if (pole[y][x].mina == 1) return 1;//  иначе если по указанным координатам мина, то возвращаем мину 
	else
	{
		int kolmin = 0; // кол-во мин рядом
		pole[y][x].open = true; // указываем что клетку открыли
		pole[y][x].flag = false;// сбрасываем флаг, так как клетка уже открытая
		for (int i = 0; i < 8; i++) //8 ходов
		{
			int temp = scanMiner(pole, poleY, poleX, hod, y + hod[1][i], x + hod[0][i]);// рекурсия
			if (temp == 1) kolmin++; // если рядом была мина то +1 к счётчику
		}
		pole[y][x].krugom = kolmin; //присваеваем клетки значения кол-ва мин рядом
		return 0;
	}
}

template <class T>
int initPoleK(T** pole, int poleY, int poleX, int slozhnost, int poleYots, int poleXots)//Инициализация для целого массива клеток
{
	int colMina = 0; //временная переменная для подсчёта кол-ва мин
	for (size_t i = 0; i < poleY; i++) //инициализация клеток поля
	{
		for (size_t j = 0; j < poleX; j++)
		{
          	pole[i][j].row = i; //даём клетке "сознание" о её местоположении
			pole[i][j].col = j; //даём клетке "сознание" о её местоположении
			pole[i][j].poleYots = poleYots; // начальный отступ от поля
			pole[i][j].poleXots = poleXots; // начальный отступ от поля
			pole[i][j].init(slozhnost); //инициализируем  клетки с указанием сложности(кол-ва мин)
			if (pole[i][j].mina) colMina++; // если мина была установлена то +1
		}
	}
	return colMina; // возврат кол-во мин на поле
}
template <class T>
bool testAllMina(T** pole, int poleY, int poleX, int colMina) //проверка совпадения флагов и мин
{
	int colSovpadeniy = 0; // кол-во совпадений мин с флагами
	for (size_t i = 0; i < poleY; i++)
	{
		for (size_t j = 0; j < poleX; j++)
		{
			if (pole[i][j].mina && pole[i][j].flag) colSovpadeniy++; //если расположение мины совпадает с расположением флага то +1 к счётчику совпадений
		}
	}
	return(colMina == colSovpadeniy) ? true : false; // если все мины совпали то возвращем 1 иначе 0
}
template <class T>
int colAllflag(T** pole, int poleY, int poleX) //пересчёт всех флагов после рекурсии поиска пустых клеток(флаги затираются)
{
	int colFlag = 0; // кол-во  флагов
	for (size_t i = 0; i < poleY; i++)
	{
		for (size_t j = 0; j < poleX; j++)
		{
			if (pole[i][j].flag) colFlag++; //если флаг то +1 к счётчику
		}
	}
	return colFlag; // возвращаем кол-во флагов
}
template <class T>
void printAllpole(T** pole, int poleY, int poleX) // печать всего поля
{
	for (size_t i = 0; i < poleY; i++)
	{
		for (size_t j = 0; j < poleX; j++)
		{
			pole[i][j].print(0); //печать  клетки 0 без курсора, 1 с курсором
		}
		cout << endl;
	}
	
}

void cursorColor(int); // Установка цвета курсора

void gotoXY(int x, int y); //установить курсор в указанном месте

template <class T>
void printMenu_v1(T**& arr, int row, int col, int y, bool sleep=true) //меню с приближением букв с двух сторон указываем Y, а X центруется
{
	int maxX = 114;// длинна консольного окна
	for (int k = 0; k < row; k++)
	{
		for (size_t i = 0; i < strlen(*(arr + k)) / 2; i++)
		{
			for (size_t j = 0; j < maxX / 2 - i; j++)
			{
				gotoXY(j, y + k); cout << arr[k][(strlen(*(arr + k)) / 2) - 1 - i]; // левые символы
				if (j) gotoXY(j - 1, y + k); cout << " "; // левые символы
				gotoXY(maxX - j - 1, y + k); cout << arr[k][(strlen(*(arr + k)) / 2) + i]; // левые символы
				if (j) gotoXY(maxX - j, y + k); cout << " "; // левые символы
				//if(sleep) this_thread::sleep_for(0ms); //замедляем цикл

			}
		}
	}
}
template <class T>
void printMenu_v2(T**& arr, int row, int col, int y) //меню с приближением букв с двух сторон указываем Y, а X центруется
{
	int maxX = 114;// длинна консольного окна
	for (int k = 0; k < row; k++)
	{
		for (size_t i = 0; i < col / 2; i++)
		{
			for (size_t j = 0; j < maxX / 2 - i; j++)
			{
				gotoXY(j, y + k); cout << arr[k][(col / 2) - 1 - i]; // левые символы
				if (j) gotoXY(j - 1, y + k); cout << " "; // левые символы
				gotoXY(maxX - j - 1, y + k); cout << arr[k][(col / 2) + i]; // левые символы
				if (j) gotoXY(maxX - j, y + k); cout << " "; // левые символы
				this_thread::sleep_for(0ms); //замедляем цикл

			}
		}
	}
}
void cinClear();

void timeSec(char*, int, int); // возвращает дату с кол-ва секунд 

#endif