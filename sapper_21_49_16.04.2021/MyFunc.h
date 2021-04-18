#ifndef MyFunc_h
#define MyFunc_h

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
#include <chrono> //��� �������
#include <thread>//��� �������
using namespace std;

template<class T>
void createArr2D(T**& p, int row, int col) // �������� ������ ��� ������������� ������� 2D
{
	p = new T * [row];
	for (size_t i = 0; i < row; i++)
	{
		p[i] = new T[col];
	}
}
template<class T>
void deleteArr2D(T**& p, int row) // �������� ������� �� ������(������������ ������)
{
	for (size_t i = 0; i < row; i++)
	{
		delete[]p[i];
	}
	delete[]p;
	p = nullptr;
}

template <class T>
int scanMiner(T** pole, int poleY, int poleX, int hod[][8], int y, int x) // �������� �� ������ ������ � �� �������� ����� ���
{
	if (x < 0 || x >= poleX || y < 0 || y >= poleY || pole[y][x].open) return 2; // ���� ������� �� ���������� �� ���������� 2
	else if (pole[y][x].mina == 1) return 1;//  ����� ���� �� ��������� ����������� ����, �� ���������� ���� 
	else
	{
		int kolmin = 0; // ���-�� ��� �����
		pole[y][x].open = true; // ��������� ��� ������ �������
		pole[y][x].flag = false;// ���������� ����, ��� ��� ������ ��� ��������
		for (int i = 0; i < 8; i++) //8 �����
		{
			int temp = scanMiner(pole, poleY, poleX, hod, y + hod[1][i], x + hod[0][i]);// ��������
			if (temp == 1) kolmin++; // ���� ����� ���� ���� �� +1 � ��������
		}
		pole[y][x].krugom = kolmin; //����������� ������ �������� ���-�� ��� �����
		return 0;
	}
}

template <class T>
int initPoleK(T** pole, int poleY, int poleX, int slozhnost, int poleYots, int poleXots)//������������� ��� ������ ������� ������
{
	int colMina = 0; //��������� ���������� ��� �������� ���-�� ���
	for (size_t i = 0; i < poleY; i++) //������������� ������ ����
	{
		for (size_t j = 0; j < poleX; j++)
		{
          	pole[i][j].row = i; //��� ������ "��������" � � ��������������
			pole[i][j].col = j; //��� ������ "��������" � � ��������������
			pole[i][j].poleYots = poleYots; // ��������� ������ �� ����
			pole[i][j].poleXots = poleXots; // ��������� ������ �� ����
			pole[i][j].init(slozhnost); //��������������  ������ � ��������� ���������(���-�� ���)
			if (pole[i][j].mina) colMina++; // ���� ���� ���� ����������� �� +1
		}
	}
	return colMina; // ������� ���-�� ��� �� ����
}
template <class T>
bool testAllMina(T** pole, int poleY, int poleX, int colMina) //�������� ���������� ������ � ���
{
	int colSovpadeniy = 0; // ���-�� ���������� ��� � �������
	for (size_t i = 0; i < poleY; i++)
	{
		for (size_t j = 0; j < poleX; j++)
		{
			if (pole[i][j].mina && pole[i][j].flag) colSovpadeniy++; //���� ������������ ���� ��������� � ������������� ����� �� +1 � �������� ����������
		}
	}
	return(colMina == colSovpadeniy) ? true : false; // ���� ��� ���� ������� �� ��������� 1 ����� 0
}
template <class T>
int colAllflag(T** pole, int poleY, int poleX) //�������� ���� ������ ����� �������� ������ ������ ������(����� ����������)
{
	int colFlag = 0; // ���-��  ������
	for (size_t i = 0; i < poleY; i++)
	{
		for (size_t j = 0; j < poleX; j++)
		{
			if (pole[i][j].flag) colFlag++; //���� ���� �� +1 � ��������
		}
	}
	return colFlag; // ���������� ���-�� ������
}
template <class T>
void printAllpole(T** pole, int poleY, int poleX) // ������ ����� ����
{
	for (size_t i = 0; i < poleY; i++)
	{
		for (size_t j = 0; j < poleX; j++)
		{
			pole[i][j].print(0); //������  ������ 0 ��� �������, 1 � ��������
		}
		cout << endl;
	}
	
}

void cursorColor(int); // ��������� ����� �������

void gotoXY(int x, int y); //���������� ������ � ��������� �����

template <class T>
void printMenu_v1(T**& arr, int row, int col, int y, bool sleep=true) //���� � ������������ ���� � ���� ������ ��������� Y, � X ����������
{
	int maxX = 114;// ������ ����������� ����
	for (int k = 0; k < row; k++)
	{
		for (size_t i = 0; i < strlen(*(arr + k)) / 2; i++)
		{
			for (size_t j = 0; j < maxX / 2 - i; j++)
			{
				gotoXY(j, y + k); cout << arr[k][(strlen(*(arr + k)) / 2) - 1 - i]; // ����� �������
				if (j) gotoXY(j - 1, y + k); cout << " "; // ����� �������
				gotoXY(maxX - j - 1, y + k); cout << arr[k][(strlen(*(arr + k)) / 2) + i]; // ����� �������
				if (j) gotoXY(maxX - j, y + k); cout << " "; // ����� �������
				//if(sleep) this_thread::sleep_for(0ms); //��������� ����

			}
		}
	}
}
template <class T>
void printMenu_v2(T**& arr, int row, int col, int y) //���� � ������������ ���� � ���� ������ ��������� Y, � X ����������
{
	int maxX = 114;// ������ ����������� ����
	for (int k = 0; k < row; k++)
	{
		for (size_t i = 0; i < col / 2; i++)
		{
			for (size_t j = 0; j < maxX / 2 - i; j++)
			{
				gotoXY(j, y + k); cout << arr[k][(col / 2) - 1 - i]; // ����� �������
				if (j) gotoXY(j - 1, y + k); cout << " "; // ����� �������
				gotoXY(maxX - j - 1, y + k); cout << arr[k][(col / 2) + i]; // ����� �������
				if (j) gotoXY(maxX - j, y + k); cout << " "; // ����� �������
				this_thread::sleep_for(0ms); //��������� ����

			}
		}
	}
}
void cinClear();

void timeSec(char*, int, int); // ���������� ���� � ���-�� ������ 

#endif