#ifndef MyStruct_h
#define MyStruct_h

#include"MyFunc.h"

struct Kletka// клетка для сапёра
{
	bool mina; // наличие  в клетке мины
	bool flag; // установлен ли флаг
	bool open; // открыта ли клетка
	int krugom; // значение кол-ва мин вокруг
	int poleYots; // начальный отступ от поля
	int poleXots; // начальный отступ от поля
	int colorK[2][5]{ {132, 64, 132, 112, 2 }, {32, 32, 36, 32, 32} }; //цвета для разных данных в клетках row=0 без курсора, row=1 с курсором
	//  5 значений цвета    (!open && !flag),(!open && flag),(open && mina == 1),(open && krugom>0),(open && krugom<=0 или -2)  
	//                       (цвет мины красный на сером фоне),(цвет значений белый фон + цвета)
	int row;//положение клетки в строке масива, даём клетке "сознание" о её местоположении
	int col;//положение клетки в столбце масива, даём клетке "сознание" о её местоположении
	void init(int); //инициализация
	void print(bool); // вывод
};


struct CursorK // структура курсора
{
	int posY;// координата передвижения игрока
	int posX;// координата передвижения игрока
	int oldPosY; // прежняя позиция
	int oldPosX; // прежняя позиция
	int poleY; // размер поля
	int poleX; // размер поля
	int poleYots; // начальный отступ от поля
	int poleXots; // начальный отступ от поля

	bool up(); // курсор шаг вверх
	bool down(); // курсор шаг вниз
	bool left(); // курсор шаг влево
	bool right(); // курсор шаг вправо

};
struct infP // переменные поля игры
{
	int colMina; // кол-во мин
	int colFlag; // кол-во установленых флагов
	int colTime; //кол-во времени в игре
	int timeStart;//время запуска
	int slozhnost; // сложность игры
	int poleY; // размеры поля
	int poleX; // размеры поля
	
	void init();
	void printHead();

};

struct UkazatelMenu //для печати и перемещения стрелок в меню
{
	int startY; //начальная координата
	int startX; //начальная координата
	int posY; //текущая координата
	int colPos;//кол-во позиций
	int color; // цвет
	int colChar;//кол-во символов в ряду в меню
	bool dual = false; // 0 - одна 1 -2 стрелки
	
	char cursor1 = '>'; // курсор
	char cursor2 = '<'; // курсор

	void print0(); //печать пустого места
	void print00(); //печать пустого места
	void print1(); //печать курсора
	void print2(); //печать курсора
    void up();    //движение вверх
    void down();  //движение вниз
	int space(); // нажатие пробела
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