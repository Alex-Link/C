// ----------------------------------версия 3 Попытка анализа поля сапёра рекурсией-----------

#define _CRT_SECURE_NO_WARNINGS // доп параметр для команд strcpy(st2, st1)
#include <string.h>
#include<iostream>
#include<ctime>
#include<iomanip>
#include<typeinfo>

#include<string.h> // библиотека для работы со строками
#include<string>
#include <windows.h> // WinApi
#include <conio.h> // для getche()
#include "MyStruct.h"
#include <fstream>

using namespace std;

int main()
{
	setlocale(LC_ALL, ""); //поддержка русс языка
	//-------------------- начало -----------------------
	HANDLE  hConsole = GetStdHandle(STD_OUTPUT_HANDLE); // Получение дескриптора устройства стандартного вывода
	COORD position;
	//
	// --------------------------------------------------делаем курсор невидимым -----------------
	CONSOLE_CURSOR_INFO structCursorInfo;
    GetConsoleCursorInfo(hConsole, &structCursorInfo);
	structCursorInfo.bVisible = FALSE;
	SetConsoleCursorInfo(hConsole, &structCursorInfo);
	//============================================================================================

	int menu = -1; // переменная выбора меню -1
	infP infPole;  //структур а переменных игры
	infPole.init(); //Инициа лизация переменных
	int centerY =15, centerX = 59; // центр поля
	Kletka** poleK = nullptr; // объявляем указатель
	createArr2D(poleK, infPole.poleY, infPole.poleX); // Выделение динамической памяти под 2D массив структурных значений (под поле) 
	CursorK cursor; //объявляем новую структуру cursor
	cursor = { infPole.poleY / 2, infPole.poleX / 2, infPole.poleY / 2, infPole.poleX / 2, infPole.poleY, infPole.poleX, centerY - infPole.poleY / 2, centerX - infPole.poleX }; //Инициализируем структуру а так же центровка поля
	infPole.colMina  = initPoleK(poleK, infPole.poleY, infPole.poleX, infPole.slozhnost, centerY - infPole.poleY / 2, centerX - infPole.poleX); // инициализация целого поля клеток, а результат кол-во мин на поле
	int posYtime = 0, posXtime = 80; // позиция времени
	int timeMem = 0;//временная переменная для времени
	int hod[2][8] = { {-1,0,+1,+1,+1,0,-1,-1}, // x координата для проверок вокруг
					  {-1,-1,-1,0,+1,+1,+1,0} };// y координата для проверок вокруг
	
	//----------------------------------- Инициализация главного меню ----------------------------
	char str00[] = "                               * *          ";
	char str01[] = " *****       **      *******  *****  ****** ";
	char str02[] = "*     *     *  *     *     *  *      *     *";
	char str03[] = "*          ******    *     *  ****   ****** ";
	char str04[] = "*     *   *      *   *     *  *      *      ";
	char str05[] = " *****   *        *  *     *  *****  *      ";

	char** menu1a = nullptr; //объявление указателя
	createArr2D(menu1a, 6, 45); // выделяем память
	menu1a[0] = str00; // присваиваем массив(строку) массиву
	menu1a[1] = str01; // присваиваем массив(строку) массиву
	menu1a[2] = str02; // присваиваем массив(строку) массиву
	menu1a[3] = str03; // присваиваем массив(строку) массиву
	menu1a[4] = str04; // присваиваем массив(строку) массиву
	menu1a[5] = str05; // присваиваем массив(строку) массиву

	char str0[] = "***** Меню *****";
	char str1[] = "Старт           ";
	char str2[] = "Настройки       ";
	char str3[] = "Таблица рекордов";
	char str4[] = "О авторе        ";
	char str5[] = "Выход           ";

	char** menu1 = nullptr; //объявление указателя
	createArr2D(menu1, 7, 17); // выделяем память
	menu1[0] = str0; // присваиваем массив(строку) массиву
	menu1[1] = str1; // присваиваем массив(строку) массиву
	menu1[2] = str2; // присваиваем массив(строку) массиву
	menu1[3] = str3; // присваиваем массив(строку) массиву
	menu1[4] = str4; // присваиваем массив(строку) массиву
	menu1[5] = str5; // присваиваем массив(строку) массиву

	int posYmenu1 = 10; //Y координата начала меню 1
	UkazatelMenu menu1u = {posYmenu1+1,48,posYmenu1 + 1,5,4,17 }; //инициализируем структуру меню 1 курсора
	
	//----------------------------------- Инициализация Об Авторе ----------------------------
	char str6[] = "        Компютерна Академия ШАГ               ";
	char str7[] = "Группа.................................СБУ011 ";
	char str8[] = "Экзамен..Основы программирования на языке С++ ";
	char str9[] = "Преподаватель....Гололобов Сергей Анатольевич ";
	char str10[] = "Исполнитель......Михальчук Александр Иванович ";
	char str11[] = "Дата...............................17.04.2021 ";

	char** menu3 = nullptr; //объявление указателя
	createArr2D(menu3, 6, 47); // выделяем память
	menu3[0] = str6; // присваиваем массив(строку) массиву
	menu3[1] = str7; // присваиваем массив(строку) массиву
	menu3[2] = str8; // присваиваем массив(строку) массиву
	menu3[3] = str9; // присваиваем массив(строку) массиву
	menu3[4] = str10; // присваиваем массив(строку) массиву
	menu3[5] = str11; // присваиваем массив(строку) массиву
	//----------------------------------------------------------Инициализация настроек --------------
    char str20[] = "*****Настройка******";
	char str21[] = "Размер поля :       ";
	char str22[] = "Y(2-27)...........  ";
	char str23[] = "X(2-57)...........  ";
	char str24[] = "Сложность(10-90)..  ";
	char str25[] = "Выход в главное меню";

	char** menu2 = nullptr; //объявление указателя
	createArr2D(menu2, 6, 21); // выделяем память
	menu2[0] = str20; // присваиваем массив(строку) массиву
	menu2[1] = str21; // присваиваем массив(строку) массиву
	menu2[2] = str22; // присваиваем массив(строку) массиву
	menu2[3] = str23; // присваиваем массив(строку) массиву
	menu2[4] = str24; // присваиваем массив(строку) массиву
	menu2[5] = str25; // присваиваем массив(строку) массиву
	UkazatelMenu menu2u = { posYmenu1 + 2,46,posYmenu1 + 2,4,4,21 }; //инициализируем структуру меню 1 курсора
	//--------------------------------------------------------------------------------------------
	
	score* records = new score[10]; // Выделяем память под 10 рекордсменов
	for (size_t i = 0; i < 10; i++)
	{
		records[i].init(); //инициализация 
	}

    while (1) { // бесконечный цикл
		
		//------------------------------------- главное меню --------------------------------------
		if (menu == -1)
		{
			cursorColor(1); // Установка цвета курсора
			system("cls"); //очистить экран
			//printMenu_v1(menu1a, 6, 45, posYmenu1-7,false);
			cursorColor(4); // Установка цвета курсора
			for (int i = 0; i < 6; i++) // печать надписи Сапёр
			{
				gotoXY(centerX - 23, posYmenu1 - 7 + i); // координата курсора
				cout << *(menu1a + i) << endl; // вывод строки
			}
			cursorColor(9); // Установка цвета курсора
			printMenu_v1(menu1, 6, 17, posYmenu1);
			menu1u.print2();
			cursorColor(9);              //Цвет курсора
			gotoXY(25, 29);// Установка координаты курсора
			cout << " Для навигации по меню используйте \"стелки\", а для выбора \"пробел\"  ";
		}
		while (menu==-1)// основное меню
		{
			if (GetAsyncKeyState(VK_UP))//если нажата стрелка вверх
			{
				keybd_event(VK_UP, 0, KEYEVENTF_KEYUP, 0);//Отжимаем кнопку
				menu1u.up();//двигаем курсором по меню вверх
			}
			if (GetAsyncKeyState(VK_DOWN))//если нажата стрелка вниз
			{
				keybd_event(VK_DOWN, 0, KEYEVENTF_KEYUP, 0);//Отжимаем кнопку
				menu1u.down();//двигаем курсором по меню вниз
			}

			if (GetAsyncKeyState(0x20))// если нажат пробел
			{
				keybd_event(0x20, 0, KEYEVENTF_KEYUP, 0);//Отжимаем кнопку
				
				menu = menu1u.space();// указываем на меню нажатое пробелом
				if (menu==4) return 0;// если нажат выход, то  Выход из программы
				
            }
		}
	
		while (menu==0) //---------------------------------------------меню 0 Старт ------------------------------------- 
		{
			system("cls"); //очистить экран
			//infPole.colFlag = 0; //сбросить счётчик флагов
			//infPole.colTime = 0;//сбросить счётчик времени
			createArr2D(poleK, infPole.poleY, infPole.poleX); // Выделение динамической памяти под 2D массив структурных значений (под поле) 
			cursor = { infPole.poleY / 2, infPole.poleX / 2, infPole.poleY / 2, infPole.poleX / 2, infPole.poleY, infPole.poleX, centerY - infPole.poleY / 2, centerX - infPole.poleX }; //Инициализируем структуру а так же центровка поля
			
			infPole.colMina = initPoleK(poleK, infPole.poleY, infPole.poleX, infPole.slozhnost, centerY - infPole.poleY / 2, centerX - infPole.poleX); // инициализация целого поля клеток, а результат кол-во мин на поле
			infPole.colFlag = colAllflag(poleK, infPole.poleY, infPole.poleX); //пересчёт всех флагов после рекурсии поиска пустых клеток(флаги затираются)
			infPole.printHead();// печать шапки над полем
			printAllpole(poleK, infPole.poleY, infPole.poleX);//вывести всё поле на экран
			infPole.timeStart = time(0);// запоминаем время старта
			poleK[cursor.posY][cursor.posX].print(1);//печать курсора на клетке
		
			while (menu == 0) //-------------------------------------Start Game---------------------------------------
			{
				if (time(0) != timeMem) // срботка каждую секунду
				{
					
					infPole.colTime = time(0) - infPole.timeStart;
					cursorColor(11);              //Цвет курсора
					gotoXY(posXtime, posYtime);// Установка координаты курсора
					cout << "Время: " << infPole.colTime << "  " << endl << endl;//
					timeMem = time(0); // сохраняем текущее значение времени
				}

				//-----------------------------------------управление клавишами -------------------------------------
				if (GetAsyncKeyState(VK_UP))//если нажата стрелка вверх
				{
					keybd_event(VK_UP, 0, KEYEVENTF_KEYUP, 0);//Отжимаем кнопку
					if (cursor.up()) // если было перемещение, то
					{
						poleK[cursor.oldPosY][cursor.oldPosX].print(0); //печать клетки без курсора ("затираем курсор на старой координате")
						poleK[cursor.posY][cursor.posX].print(1);//печать курсора на клетке
					}
				}

				if (GetAsyncKeyState(VK_DOWN))//если нажата стрелка вниз
				{
					keybd_event(VK_DOWN, 0, KEYEVENTF_KEYUP, 0);//Отжимаем кнопку
					if (cursor.down()) // если было перемещение, то
					{
						poleK[cursor.oldPosY][cursor.oldPosX].print(0);//печать клетки без курсора ("затираем курсор на старой координате")
						poleK[cursor.posY][cursor.posX].print(1);//печать курсора на клетке
					}
				}

				if (GetAsyncKeyState(VK_LEFT))//если нажата стрелка влево
				{
					keybd_event(VK_LEFT, 0, KEYEVENTF_KEYUP, 0);//Отжимаем кнопку
					if (cursor.left())// если было перемещение, то
					{
						poleK[cursor.oldPosY][cursor.oldPosX].print(0);//печать клетки без курсора ("затираем курсор на старой координате")
						poleK[cursor.posY][cursor.posX].print(1);//печать курсора на клетке
					}
                }


				if (GetAsyncKeyState(VK_RIGHT))//если нажата стрелка вправо
				{
					keybd_event(VK_RIGHT, 0, KEYEVENTF_KEYUP, 0);//Отжимаем кнопку
					if (cursor.right())// если было перемещение, то
					{
						poleK[cursor.oldPosY][cursor.oldPosX].print(0);//печать клетки без курсора ("затираем курсор на старой координате")
						poleK[cursor.posY][cursor.posX].print(1);//печать курсора на клетке
					}
				}

				if (GetAsyncKeyState(0x46))//F  установка и снятия флага
				{
					keybd_event(0x46, 0, KEYEVENTF_KEYUP, 0);//Отжимаем кнопку
					if (poleK[cursor.posY][cursor.posX].flag) // если флаг установлен при нажатии
					{
						poleK[cursor.posY][cursor.posX].flag = false; // то снять флаг 
						infPole.colFlag--; // и уменьшить счётчик флагов на 1
						infPole.printHead();// печать шапки над полем
					}
					else //иначе ( если флаг не был установлен)
					{
						if (!poleK[cursor.posY][cursor.posX].open && infPole.colFlag < infPole.colMina) // если клетка  закрыта и флагов меньше чем мин
						{
							poleK[cursor.posY][cursor.posX].flag = true; //то установим флаг
							infPole.colFlag++; // увеличим счётчик флагов
							infPole.printHead();// печать шапки над полем
							if (infPole.colFlag == infPole.colMina && testAllMina(poleK, infPole.poleY, infPole.poleX, infPole.colMina)) // если флагов = мин  и  все совпали то
							{
								poleK[cursor.posY][cursor.posX].print(1);//печать курсора на клетке
								cursorColor(36);              //Цвет курсора
								gotoXY(10, 29);// Установка координаты курсора
								cout << "Вы выиграли!!!"; // 
								//--------------------------------------- Введите имя ------------------------
								cursorColor(30);              //Цвет курсора
								for (size_t i = 0; i < 4; i++)
								{
									gotoXY(35, 10+i);// Установка координаты курсора
									cout << "              ";
								}
								cursorColor(36);              //Цвет курсора
								gotoXY(36, 11);// Установка координаты курсора
								cout << "Введите имя:";
								gotoXY(36, 12);// Установка координаты курсора
								cout << "            ";
								int xPos = 36, yPos = 12, colNameChar = 0;
								records[0].enable = true;
								records[0].data = time(0);
								records[0].slozhnost = infPole.slozhnost;
								records[0].poleY = infPole.poleY;
								records[0].poleX = infPole.poleX;
								records[0].colTime = infPole.colTime;
								records[0].name[10] = '\0';

								while (colNameChar < 10) //ввод имени в строку
								{
									
									if (GetAsyncKeyState(0x0D))//Enter закончить запись
									{
										for (size_t i = 0; i < 10-colNameChar; i++)//добиваем пробелами
										{
											records[0].name[colNameChar+i] = ' '; //добиваем пробелами
										}
										keybd_event(0x0D, 0, KEYEVENTF_KEYUP, 0);//Отжимаем кнопку
										colNameChar = 10;// указываем максимум что бы выйти из while
										break;
									}
									else
									{
                                    	FlushConsoleInputBuffer(GetStdHandle(STD_INPUT_HANDLE)); // очистка буфера
										gotoXY(36 + colNameChar, 12);// Установка координаты курсора
										cout << ""; // устанавливаем курсор
										records[0].name[colNameChar] = _getche(); //считать символ
										colNameChar++; // увеличить на 1
									}
								}
								/// ----------------------- Запись в файл из массива -----------------------------------

								ofstream out; // создаём объект потока на запись
								out.open("records.txt"); // открываем файл для записи , если файл существует то его перезапишут, если его нет то создатся новый файл
								for (size_t i = 0; i < 10; i++)
								{

									if (records[i].enable == true)
									{
										//out << i << endl;
										out << records[i].name << endl; // сохраняем имя
										out << records[i].data << " " << records[i].slozhnost << " " << records[i].poleX << " " << records[i].poleY << " " << records[i].colTime << endl; // сохраняем данные
									}
																																													  //for (size_t i = 0; i < 5; i++) // перебираем массив
			   //                     {
				  //               	out << a[i] << " ";
								//    }
	                             }
	                            out.close();
								// ================================= Запись в файл из массива ======================================

								menu = -1; // переменная меню Выход в главное меню
								//======================================= Введите имя ========================
								//while (menu == 0)
								//{
								//	if (GetAsyncKeyState(0x20))// пробел
								//	{
								//		keybd_event(0x20, 0, KEYEVENTF_KEYUP, 0);//Отжимаем кнопку
								//		menu = -1; // переменная меню Выход в главное меню
								//	}
								//}
							}
						}
					}
					poleK[cursor.posY][cursor.posX].print(1);//печать курсора на клетке

				}

				if (GetAsyncKeyState(0x1B))// Если нажат Esc
				{
					keybd_event(0x1B, 0, KEYEVENTF_KEYUP, 0);//Отжимаем кнопку
					menu = -1;//Выйти в основное меню
				
				}

				if (GetAsyncKeyState(0x20))// пробел
				{
					keybd_event(0x20, 0, KEYEVENTF_KEYUP, 0);//Отжимаем кнопку
					if (poleK[cursor.posY][cursor.posX].mina == false) // проверяем клетку на наличие мины
					{
						scanMiner(poleK, infPole.poleY, infPole.poleX, hod, cursor.posY, cursor.posX);
						infPole.colFlag = colAllflag(poleK, infPole.poleY, infPole.poleX); //пересчёт всех флагов после рекурсии поиска пустых клеток(флаги затираются)
						printAllpole(poleK, infPole.poleY, infPole.poleX); // Вывести всё поле
						poleK[cursor.posY][cursor.posX].print(1);//печать курсора на клетке
						infPole.printHead();// печать шапки над полем
					}
					else
					{
						for (int i = 0; i < infPole.poleY; i++) // перебераем карту
						{
							for (int j = 0; j < infPole.poleX; j++)
							{
								if (poleK[i][j].mina) poleK[i][j].open = true; // если есть мина то открыть клетку
							}
						}
						printAllpole(poleK, infPole.poleY, infPole.poleX); // Вывести всё поле
						poleK[cursor.posY][cursor.posX].print(1);//печать курсора на клетке
						cursorColor(78);              //Цвет курсора
						gotoXY(5, 29);// Установка координаты курсора
						cout << "Вы програли!!!   ";
						//system("pause"); // пауза перед выходом
						while (menu == 0)
						{
							if (GetAsyncKeyState(0x20))// пробел
							{
								keybd_event(0x20, 0, KEYEVENTF_KEYUP, 0);//Отжимаем кнопку
								menu = -1; // переменная меню Выход в главное меню
							}
						}
					}
				}

			}//==============================================End Game =========================================
		}
		
		if (menu == 1) //---------------------------------------------меню 1 Настройки ------------------------------------- 
		{
			cursorColor(1); // Установка цвета курсора
			system("cls"); //очистить экран
			//printMenu_v1(menu1a, 6, 45, posYmenu1-7,false);
			cursorColor(4); // Установка цвета курсора
			for (int i = 0; i < 6; i++) // печать надписи Сапёр
			{
				gotoXY(centerX - 23, posYmenu1 - 7 + i); // координата курсора
				cout << *(menu1a + i) << endl; // вывод строки
			}
			cursorColor(9); // Установка цвета курсора
			printMenu_v1(menu2, 6, 21, posYmenu1); // вывести меню
			menu2u.print2(); // Вывести курсоры выбора меню
			cursorColor(4); // Установка цвета курсора
			gotoXY(65, posYmenu1 + 2); //курсор по координате 
			cout << infPole.poleY; // вывод переменной
			if (infPole.poleY < 10) cout << " ";// затираем символ
			gotoXY(65, posYmenu1 + 3);//курсор по координате
			cout << infPole.poleX;// вывод переменной
			if (infPole.poleX < 10) cout << " ";// затираем символ
			gotoXY(65, posYmenu1 + 4);//курсор по координате
			cout << infPole.slozhnost;// вывод переменной
			cursorColor(9);              //Цвет курсора
			gotoXY(25, 29);// Установка координаты курсора
			cout << " Для навигации по меню используйте \"стелки\", а для выбора \"пробел\"  ";
		}

		while (menu == 1) //---------------------------------------------меню 1 Настройки ------------------------------------- 
		{
			while (menu == 1)// основное меню
			{
				if (GetAsyncKeyState(VK_UP))//если нажата стрелка вверх
				{
					keybd_event(VK_UP, 0, KEYEVENTF_KEYUP, 0);//Отжимаем кнопку
					menu2u.up();//двигаем курсором по меню вверх
					//if(menu2u.posY- menu2u.startY == 0) menu2u.up();//двигаем курсором по меню вверх
				}
				if (GetAsyncKeyState(VK_DOWN))//если нажата стрелка вниз
				{
					keybd_event(VK_DOWN, 0, KEYEVENTF_KEYUP, 0);//Отжимаем кнопку
					menu2u.down();//двигаем курсором по меню вниз
				}

				if (GetAsyncKeyState(0x20))// если нажат пробел
				{
					keybd_event(0x20, 0, KEYEVENTF_KEYUP, 0);//Отжимаем кнопку

					if (menu2u.space()==3) menu = -1;// Если выбрана 3-я позиция то перейти в главное меню
					
				}

				if (GetAsyncKeyState(VK_LEFT))//если нажата стрелка влево
				{
					keybd_event(VK_LEFT, 0, KEYEVENTF_KEYUP, 0);//Отжимаем кнопку
					
					switch (menu2u.posY - menu2u.startY)// проверяем положение курсора
					{
					case 0:
						if (infPole.poleY < 3) infPole.poleY = 27; // если значения выходит запределы то сделать значения с конца
						else infPole.poleY--; // иначе уменьшить на 1
						cursorColor(4); // Установка цвета курсора
						gotoXY(65, menu2u.posY); //курсор по координате
						cout << infPole.poleY; // вывод переменной
						if (infPole.poleY < 10) cout << " ";// затираем символ
						break;
					case 1:
						if (infPole.poleX < 3) infPole.poleX = 57; // если значения выходит запределы то сделать значения с конца
						else infPole.poleX--;// иначе уменьшить на 1
						cursorColor(4); // Установка цвета курсора
						gotoXY(65, menu2u.posY);//курсор по координате
						cout << infPole.poleX;// вывод переменной
						if (infPole.poleX < 10) cout << " ";// затираем символ
						break;
					case 2:
						if (infPole.slozhnost < 11) infPole.slozhnost = 90; // если значения выходит запределы то сделать значения с конца
						else infPole.slozhnost--;// иначе уменьшить на 1
						cursorColor(4); // Установка цвета курсора
						gotoXY(65, menu2u.posY);//курсор по координате
						cout << infPole.slozhnost;// вывод переменной
						break;
					}
				}


				if (GetAsyncKeyState(VK_RIGHT))//если нажата стрелка вправо
				{
					keybd_event(VK_RIGHT, 0, KEYEVENTF_KEYUP, 0);//Отжимаем кнопку
					
					    switch (menu2u.posY - menu2u.startY)// проверяем положение курсора
						{
						case 0:
							if (infPole.poleY > 26) infPole.poleY = 2;// если значения выходит запределы то сделать значения с начала
							else infPole.poleY++;// иначе увеличить на 1
							cursorColor(4); // Установка цвета курсора
							gotoXY(65,menu2u.posY);//курсор по координате
							cout << infPole.poleY;// вывод переменной
							if(infPole.poleY<10) cout << " ";// затираем символ
							break;
						case 1:
							if (infPole.poleX > 56) infPole.poleX = 2;// если значения выходит запределы то сделать значения с начала
							else infPole.poleX++;// иначе увеличить на 1
							cursorColor(4); // Установка цвета курсора
							gotoXY(65, menu2u.posY);//курсор по координате
							cout << infPole.poleX;// вывод переменной
							if (infPole.poleX < 10) cout << " ";// затираем символ
							break;
						case 2:
							if (infPole.slozhnost > 89) infPole.slozhnost = 10;// если значения выходит запределы то сделать значения с начала
							else infPole.slozhnost++;// иначе увеличить на 1
							cursorColor(4); // Установка цвета курсора
							gotoXY(65, menu2u.posY);//курсор по координате
							cout << infPole.slozhnost;// вывод переменной
							break;
						}
					
				}

			}

		}
		while (menu == 2) //---------------------------------------------меню 2 Таблица рекордов ----------------------------------------
		{
			system("cls"); //очистить экран
			cursorColor(11); //Цвет курсора
			gotoXY(48, 0);// Установка координаты курсора
			cout << "*** Игра Сапёр ***";

			cursorColor(11);  //Цвет курсора
			gotoXY(38, 28);// Установка координаты курсора
			cout << "Для выхода в Меню - нажмите Пробел";
			//records.printHead(); //печать шапки
			//------------------------------------------- чтение из файла ----------------------------------------------------------------
			int dat[5];
			ifstream in; // создаём объект потока на чтение
	        in.open("records.txt"); // открываем файл на чтение
	        if (in.is_open())
	          {
				int i = 0;// переменная для счётчика рекордов
				//int i2 = 0;//временная для поиска значения
				
					//in >> i2;// считываем порядковый номер
					
					in.getline(records[i].name, 11); //считать с in в st всю строку до символа перевода строки
					in >> records[i].data >> records[i].slozhnost >> records[i].poleX >> records[i].poleY >> records[i].colTime; // читаем данные
					records[i].enable = true; //указать что запись активна
					i++; //увеличить на 1
				
	        	in.close(); //закрыть файл
	          }

			//=========================================== чтение из файла ================================================================
			records->printHead(); // печать заголовка
			for (size_t i = 0; i < 10; i++)
			{
				//gotoXY(25, 10+i);// координата расположения курсора
				if(records[i].enable ==1) records[i].print(25,10+i); //если запись есть, то вывести
			}

            while (menu == 2)
			{
				if (GetAsyncKeyState(0x20))// пробел
				{
					keybd_event(0x20, 0, KEYEVENTF_KEYUP, 0);//Отжимаем кнопку
					menu = -1; // переменная подменю Выход в главное меню
				}
            }

		}//=========================================== меню 2 Таблица рекордов=========================================

		while (menu==3) //---------------------------------------------меню 3 Об авторе ----------------------------------------
		{
			system("cls"); //очистить экран
			cursorColor(11); //Цвет курсора
			gotoXY(48, 0);// Установка координаты курсора
			cout << "*** Игра Сапёр ***";

			cursorColor(11);  //Цвет курсора
			gotoXY(38, 28);// Установка координаты курсора
			cout << "Для выхода в Меню - нажмите Пробел";
			printMenu_v1(menu3, 6, 46, posYmenu1); // выводим инфу об авторе
			
			while (menu == 3)
			{
				if (GetAsyncKeyState(0x20))// пробел
				{
					keybd_event(0x20, 0, KEYEVENTF_KEYUP, 0);//Отжимаем кнопку
					menu = -1; // переменная подменю Выход в главное меню
				}
            }
		}//===========================================Об авторе=========================================
	
		
    }
	//---------------------- конец-----------------------
	cout << endl; //перевод строки
	system("pause"); // пауза перед выходом
}
