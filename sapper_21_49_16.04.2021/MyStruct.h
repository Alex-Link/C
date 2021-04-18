#ifndef MyStruct_h
#define MyStruct_h

#include"MyFunc.h"

struct Kletka// ������ ��� �����
{
	bool mina; // �������  � ������ ����
	bool flag; // ���������� �� ����
	bool open; // ������� �� ������
	int krugom; // �������� ���-�� ��� ������
	int poleYots; // ��������� ������ �� ����
	int poleXots; // ��������� ������ �� ����
	int colorK[2][5]{ {132, 64, 132, 112, 2 }, {32, 32, 36, 32, 32} }; //����� ��� ������ ������ � ������� row=0 ��� �������, row=1 � ��������
	//  5 �������� �����    (!open && !flag),(!open && flag),(open && mina == 1),(open && krugom>0),(open && krugom<=0 ��� -2)  
	//                       (���� ���� ������� �� ����� ����),(���� �������� ����� ��� + �����)
	int row;//��������� ������ � ������ ������, ��� ������ "��������" � � ��������������
	int col;//��������� ������ � ������� ������, ��� ������ "��������" � � ��������������
	void init(int); //�������������
	void print(bool); // �����
};


struct CursorK // ��������� �������
{
	int posY;// ���������� ������������ ������
	int posX;// ���������� ������������ ������
	int oldPosY; // ������� �������
	int oldPosX; // ������� �������
	int poleY; // ������ ����
	int poleX; // ������ ����
	int poleYots; // ��������� ������ �� ����
	int poleXots; // ��������� ������ �� ����

	bool up(); // ������ ��� �����
	bool down(); // ������ ��� ����
	bool left(); // ������ ��� �����
	bool right(); // ������ ��� ������

};
struct infP // ���������� ���� ����
{
	int colMina; // ���-�� ���
	int colFlag; // ���-�� ������������ ������
	int colTime; //���-�� ������� � ����
	int timeStart;//����� �������
	int slozhnost; // ��������� ����
	int poleY; // ������� ����
	int poleX; // ������� ����
	
	void init();
	void printHead();

};

struct UkazatelMenu //��� ������ � ����������� ������� � ����
{
	int startY; //��������� ����������
	int startX; //��������� ����������
	int posY; //������� ����������
	int colPos;//���-�� �������
	int color; // ����
	int colChar;//���-�� �������� � ���� � ����
	bool dual = false; // 0 - ���� 1 -2 �������
	
	char cursor1 = '>'; // ������
	char cursor2 = '<'; // ������

	void print0(); //������ ������� �����
	void print00(); //������ ������� �����
	void print1(); //������ �������
	void print2(); //������ �������
    void up();    //�������� �����
    void down();  //�������� ����
	int space(); // ������� �������
};

struct score
{
	bool enable;
	char name[11];
	int data;
	int slozhnost;
	int poleY;
	int poleX;
	int colTime;
	void init();
	void print(int,int);
	void printHead();
	void add(char* , int, int, int, int);
};

#endif