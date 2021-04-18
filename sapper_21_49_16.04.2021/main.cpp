// ----------------------------------������ 3 ������� ������� ���� ����� ���������-----------

#define _CRT_SECURE_NO_WARNINGS // ��� �������� ��� ������ strcpy(st2, st1)
#include <string.h>
#include<iostream>
#include<ctime>
#include<iomanip>
#include<typeinfo>

#include<string.h> // ���������� ��� ������ �� ��������
#include<string>
#include <windows.h> // WinApi
#include <conio.h> // ��� getche()
#include "MyStruct.h"
#include <fstream>

using namespace std;

int main()
{
	setlocale(LC_ALL, ""); //��������� ���� �����
	//-------------------- ������ -----------------------
	HANDLE  hConsole = GetStdHandle(STD_OUTPUT_HANDLE); // ��������� ����������� ���������� ������������ ������
	COORD position;
	//
	// --------------------------------------------------������ ������ ��������� -----------------
	CONSOLE_CURSOR_INFO structCursorInfo;
    GetConsoleCursorInfo(hConsole, &structCursorInfo);
	structCursorInfo.bVisible = FALSE;
	SetConsoleCursorInfo(hConsole, &structCursorInfo);
	//============================================================================================

	int menu = -1; // ���������� ������ ���� -1
	infP infPole;  //�������� � ���������� ����
	infPole.init(); //������ ������� ����������
	int centerY =15, centerX = 59; // ����� ����
	Kletka** poleK = nullptr; // ��������� ���������
	createArr2D(poleK, infPole.poleY, infPole.poleX); // ��������� ������������ ������ ��� 2D ������ ����������� �������� (��� ����) 
	CursorK cursor; //��������� ����� ��������� cursor
	cursor = { infPole.poleY / 2, infPole.poleX / 2, infPole.poleY / 2, infPole.poleX / 2, infPole.poleY, infPole.poleX, centerY - infPole.poleY / 2, centerX - infPole.poleX }; //�������������� ��������� � ��� �� ��������� ����
	infPole.colMina  = initPoleK(poleK, infPole.poleY, infPole.poleX, infPole.slozhnost, centerY - infPole.poleY / 2, centerX - infPole.poleX); // ������������� ������ ���� ������, � ��������� ���-�� ��� �� ����
	int posYtime = 0, posXtime = 80; // ������� �������
	int timeMem = 0;//��������� ���������� ��� �������
	int hod[2][8] = { {-1,0,+1,+1,+1,0,-1,-1}, // x ���������� ��� �������� ������
					  {-1,-1,-1,0,+1,+1,+1,0} };// y ���������� ��� �������� ������
	
	//----------------------------------- ������������� �������� ���� ----------------------------
	char str00[] = "                               * *          ";
	char str01[] = " *****       **      *******  *****  ****** ";
	char str02[] = "*     *     *  *     *     *  *      *     *";
	char str03[] = "*          ******    *     *  ****   ****** ";
	char str04[] = "*     *   *      *   *     *  *      *      ";
	char str05[] = " *****   *        *  *     *  *****  *      ";

	char** menu1a = nullptr; //���������� ���������
	createArr2D(menu1a, 6, 45); // �������� ������
	menu1a[0] = str00; // ����������� ������(������) �������
	menu1a[1] = str01; // ����������� ������(������) �������
	menu1a[2] = str02; // ����������� ������(������) �������
	menu1a[3] = str03; // ����������� ������(������) �������
	menu1a[4] = str04; // ����������� ������(������) �������
	menu1a[5] = str05; // ����������� ������(������) �������

	char str0[] = "***** ���� *****";
	char str1[] = "�����           ";
	char str2[] = "���������       ";
	char str3[] = "������� ��������";
	char str4[] = "� ������        ";
	char str5[] = "�����           ";

	char** menu1 = nullptr; //���������� ���������
	createArr2D(menu1, 7, 17); // �������� ������
	menu1[0] = str0; // ����������� ������(������) �������
	menu1[1] = str1; // ����������� ������(������) �������
	menu1[2] = str2; // ����������� ������(������) �������
	menu1[3] = str3; // ����������� ������(������) �������
	menu1[4] = str4; // ����������� ������(������) �������
	menu1[5] = str5; // ����������� ������(������) �������

	int posYmenu1 = 10; //Y ���������� ������ ���� 1
	UkazatelMenu menu1u = {posYmenu1+1,48,posYmenu1 + 1,5,4,17 }; //�������������� ��������� ���� 1 �������
	
	//----------------------------------- ������������� �� ������ ----------------------------
	char str6[] = "        ���������� �������� ���               ";
	char str7[] = "������.................................���011 ";
	char str8[] = "�������..������ ���������������� �� ����� �++ ";
	char str9[] = "�������������....��������� ������ ����������� ";
	char str10[] = "�����������......��������� ��������� �������� ";
	char str11[] = "����...............................17.04.2021 ";

	char** menu3 = nullptr; //���������� ���������
	createArr2D(menu3, 6, 47); // �������� ������
	menu3[0] = str6; // ����������� ������(������) �������
	menu3[1] = str7; // ����������� ������(������) �������
	menu3[2] = str8; // ����������� ������(������) �������
	menu3[3] = str9; // ����������� ������(������) �������
	menu3[4] = str10; // ����������� ������(������) �������
	menu3[5] = str11; // ����������� ������(������) �������
	//----------------------------------------------------------������������� �������� --------------
    char str20[] = "*****���������******";
	char str21[] = "������ ���� :       ";
	char str22[] = "Y(2-27)...........  ";
	char str23[] = "X(2-57)...........  ";
	char str24[] = "���������(10-90)..  ";
	char str25[] = "����� � ������� ����";

	char** menu2 = nullptr; //���������� ���������
	createArr2D(menu2, 6, 21); // �������� ������
	menu2[0] = str20; // ����������� ������(������) �������
	menu2[1] = str21; // ����������� ������(������) �������
	menu2[2] = str22; // ����������� ������(������) �������
	menu2[3] = str23; // ����������� ������(������) �������
	menu2[4] = str24; // ����������� ������(������) �������
	menu2[5] = str25; // ����������� ������(������) �������
	UkazatelMenu menu2u = { posYmenu1 + 2,46,posYmenu1 + 2,4,4,21 }; //�������������� ��������� ���� 1 �������
	//--------------------------------------------------------------------------------------------
	
	score* records = new score[10]; // �������� ������ ��� 10 ������������
	for (size_t i = 0; i < 10; i++)
	{
		records[i].init(); //������������� 
	}

    while (1) { // ����������� ����
		
		//------------------------------------- ������� ���� --------------------------------------
		if (menu == -1)
		{
			cursorColor(1); // ��������� ����� �������
			system("cls"); //�������� �����
			//printMenu_v1(menu1a, 6, 45, posYmenu1-7,false);
			cursorColor(4); // ��������� ����� �������
			for (int i = 0; i < 6; i++) // ������ ������� ����
			{
				gotoXY(centerX - 23, posYmenu1 - 7 + i); // ���������� �������
				cout << *(menu1a + i) << endl; // ����� ������
			}
			cursorColor(9); // ��������� ����� �������
			printMenu_v1(menu1, 6, 17, posYmenu1);
			menu1u.print2();
			cursorColor(9);              //���� �������
			gotoXY(25, 29);// ��������� ���������� �������
			cout << " ��� ��������� �� ���� ����������� \"������\", � ��� ������ \"������\"  ";
		}
		while (menu==-1)// �������� ����
		{
			if (GetAsyncKeyState(VK_UP))//���� ������ ������� �����
			{
				keybd_event(VK_UP, 0, KEYEVENTF_KEYUP, 0);//�������� ������
				menu1u.up();//������� �������� �� ���� �����
			}
			if (GetAsyncKeyState(VK_DOWN))//���� ������ ������� ����
			{
				keybd_event(VK_DOWN, 0, KEYEVENTF_KEYUP, 0);//�������� ������
				menu1u.down();//������� �������� �� ���� ����
			}

			if (GetAsyncKeyState(0x20))// ���� ����� ������
			{
				keybd_event(0x20, 0, KEYEVENTF_KEYUP, 0);//�������� ������
				
				menu = menu1u.space();// ��������� �� ���� ������� ��������
				if (menu==4) return 0;// ���� ����� �����, ��  ����� �� ���������
				
            }
		}
	
		while (menu==0) //---------------------------------------------���� 0 ����� ------------------------------------- 
		{
			system("cls"); //�������� �����
			//infPole.colFlag = 0; //�������� ������� ������
			//infPole.colTime = 0;//�������� ������� �������
			createArr2D(poleK, infPole.poleY, infPole.poleX); // ��������� ������������ ������ ��� 2D ������ ����������� �������� (��� ����) 
			cursor = { infPole.poleY / 2, infPole.poleX / 2, infPole.poleY / 2, infPole.poleX / 2, infPole.poleY, infPole.poleX, centerY - infPole.poleY / 2, centerX - infPole.poleX }; //�������������� ��������� � ��� �� ��������� ����
			
			infPole.colMina = initPoleK(poleK, infPole.poleY, infPole.poleX, infPole.slozhnost, centerY - infPole.poleY / 2, centerX - infPole.poleX); // ������������� ������ ���� ������, � ��������� ���-�� ��� �� ����
			infPole.colFlag = colAllflag(poleK, infPole.poleY, infPole.poleX); //�������� ���� ������ ����� �������� ������ ������ ������(����� ����������)
			infPole.printHead();// ������ ����� ��� �����
			printAllpole(poleK, infPole.poleY, infPole.poleX);//������� �� ���� �� �����
			infPole.timeStart = time(0);// ���������� ����� ������
			poleK[cursor.posY][cursor.posX].print(1);//������ ������� �� ������
		
			while (menu == 0) //-------------------------------------Start Game---------------------------------------
			{
				if (time(0) != timeMem) // ������� ������ �������
				{
					
					infPole.colTime = time(0) - infPole.timeStart;
					cursorColor(11);              //���� �������
					gotoXY(posXtime, posYtime);// ��������� ���������� �������
					cout << "�����: " << infPole.colTime << "  " << endl << endl;//
					timeMem = time(0); // ��������� ������� �������� �������
				}

				//-----------------------------------------���������� ��������� -------------------------------------
				if (GetAsyncKeyState(VK_UP))//���� ������ ������� �����
				{
					keybd_event(VK_UP, 0, KEYEVENTF_KEYUP, 0);//�������� ������
					if (cursor.up()) // ���� ���� �����������, ��
					{
						poleK[cursor.oldPosY][cursor.oldPosX].print(0); //������ ������ ��� ������� ("�������� ������ �� ������ ����������")
						poleK[cursor.posY][cursor.posX].print(1);//������ ������� �� ������
					}
				}

				if (GetAsyncKeyState(VK_DOWN))//���� ������ ������� ����
				{
					keybd_event(VK_DOWN, 0, KEYEVENTF_KEYUP, 0);//�������� ������
					if (cursor.down()) // ���� ���� �����������, ��
					{
						poleK[cursor.oldPosY][cursor.oldPosX].print(0);//������ ������ ��� ������� ("�������� ������ �� ������ ����������")
						poleK[cursor.posY][cursor.posX].print(1);//������ ������� �� ������
					}
				}

				if (GetAsyncKeyState(VK_LEFT))//���� ������ ������� �����
				{
					keybd_event(VK_LEFT, 0, KEYEVENTF_KEYUP, 0);//�������� ������
					if (cursor.left())// ���� ���� �����������, ��
					{
						poleK[cursor.oldPosY][cursor.oldPosX].print(0);//������ ������ ��� ������� ("�������� ������ �� ������ ����������")
						poleK[cursor.posY][cursor.posX].print(1);//������ ������� �� ������
					}
                }


				if (GetAsyncKeyState(VK_RIGHT))//���� ������ ������� ������
				{
					keybd_event(VK_RIGHT, 0, KEYEVENTF_KEYUP, 0);//�������� ������
					if (cursor.right())// ���� ���� �����������, ��
					{
						poleK[cursor.oldPosY][cursor.oldPosX].print(0);//������ ������ ��� ������� ("�������� ������ �� ������ ����������")
						poleK[cursor.posY][cursor.posX].print(1);//������ ������� �� ������
					}
				}

				if (GetAsyncKeyState(0x46))//F  ��������� � ������ �����
				{
					keybd_event(0x46, 0, KEYEVENTF_KEYUP, 0);//�������� ������
					if (poleK[cursor.posY][cursor.posX].flag) // ���� ���� ���������� ��� �������
					{
						poleK[cursor.posY][cursor.posX].flag = false; // �� ����� ���� 
						infPole.colFlag--; // � ��������� ������� ������ �� 1
						infPole.printHead();// ������ ����� ��� �����
					}
					else //����� ( ���� ���� �� ��� ����������)
					{
						if (!poleK[cursor.posY][cursor.posX].open && infPole.colFlag < infPole.colMina) // ���� ������  ������� � ������ ������ ��� ���
						{
							poleK[cursor.posY][cursor.posX].flag = true; //�� ��������� ����
							infPole.colFlag++; // �������� ������� ������
							infPole.printHead();// ������ ����� ��� �����
							if (infPole.colFlag == infPole.colMina && testAllMina(poleK, infPole.poleY, infPole.poleX, infPole.colMina)) // ���� ������ = ���  �  ��� ������� ��
							{
								poleK[cursor.posY][cursor.posX].print(1);//������ ������� �� ������
								cursorColor(36);              //���� �������
								gotoXY(10, 29);// ��������� ���������� �������
								cout << "�� ��������!!!"; // 
								//--------------------------------------- ������� ��� ------------------------
								cursorColor(30);              //���� �������
								for (size_t i = 0; i < 4; i++)
								{
									gotoXY(35, 10+i);// ��������� ���������� �������
									cout << "              ";
								}
								cursorColor(36);              //���� �������
								gotoXY(36, 11);// ��������� ���������� �������
								cout << "������� ���:";
								gotoXY(36, 12);// ��������� ���������� �������
								cout << "            ";
								int xPos = 36, yPos = 12, colNameChar = 0;
								records[0].enable = true;
								records[0].data = time(0);
								records[0].slozhnost = infPole.slozhnost;
								records[0].poleY = infPole.poleY;
								records[0].poleX = infPole.poleX;
								records[0].colTime = infPole.colTime;
								records[0].name[10] = '\0';

								while (colNameChar < 10) //���� ����� � ������
								{
									
									if (GetAsyncKeyState(0x0D))//Enter ��������� ������
									{
										for (size_t i = 0; i < 10-colNameChar; i++)//�������� ���������
										{
											records[0].name[colNameChar+i] = ' '; //�������� ���������
										}
										keybd_event(0x0D, 0, KEYEVENTF_KEYUP, 0);//�������� ������
										colNameChar = 10;// ��������� �������� ��� �� ����� �� while
										break;
									}
									else
									{
                                    	FlushConsoleInputBuffer(GetStdHandle(STD_INPUT_HANDLE)); // ������� ������
										gotoXY(36 + colNameChar, 12);// ��������� ���������� �������
										cout << ""; // ������������� ������
										records[0].name[colNameChar] = _getche(); //������� ������
										colNameChar++; // ��������� �� 1
									}
								}
								/// ----------------------- ������ � ���� �� ������� -----------------------------------

								ofstream out; // ������ ������ ������ �� ������
								out.open("records.txt"); // ��������� ���� ��� ������ , ���� ���� ���������� �� ��� �����������, ���� ��� ��� �� �������� ����� ����
								for (size_t i = 0; i < 10; i++)
								{

									if (records[i].enable == true)
									{
										//out << i << endl;
										out << records[i].name << endl; // ��������� ���
										out << records[i].data << " " << records[i].slozhnost << " " << records[i].poleX << " " << records[i].poleY << " " << records[i].colTime << endl; // ��������� ������
									}
																																													  //for (size_t i = 0; i < 5; i++) // ���������� ������
			   //                     {
				  //               	out << a[i] << " ";
								//    }
	                             }
	                            out.close();
								// ================================= ������ � ���� �� ������� ======================================

								menu = -1; // ���������� ���� ����� � ������� ����
								//======================================= ������� ��� ========================
								//while (menu == 0)
								//{
								//	if (GetAsyncKeyState(0x20))// ������
								//	{
								//		keybd_event(0x20, 0, KEYEVENTF_KEYUP, 0);//�������� ������
								//		menu = -1; // ���������� ���� ����� � ������� ����
								//	}
								//}
							}
						}
					}
					poleK[cursor.posY][cursor.posX].print(1);//������ ������� �� ������

				}

				if (GetAsyncKeyState(0x1B))// ���� ����� Esc
				{
					keybd_event(0x1B, 0, KEYEVENTF_KEYUP, 0);//�������� ������
					menu = -1;//����� � �������� ����
				
				}

				if (GetAsyncKeyState(0x20))// ������
				{
					keybd_event(0x20, 0, KEYEVENTF_KEYUP, 0);//�������� ������
					if (poleK[cursor.posY][cursor.posX].mina == false) // ��������� ������ �� ������� ����
					{
						scanMiner(poleK, infPole.poleY, infPole.poleX, hod, cursor.posY, cursor.posX);
						infPole.colFlag = colAllflag(poleK, infPole.poleY, infPole.poleX); //�������� ���� ������ ����� �������� ������ ������ ������(����� ����������)
						printAllpole(poleK, infPole.poleY, infPole.poleX); // ������� �� ����
						poleK[cursor.posY][cursor.posX].print(1);//������ ������� �� ������
						infPole.printHead();// ������ ����� ��� �����
					}
					else
					{
						for (int i = 0; i < infPole.poleY; i++) // ���������� �����
						{
							for (int j = 0; j < infPole.poleX; j++)
							{
								if (poleK[i][j].mina) poleK[i][j].open = true; // ���� ���� ���� �� ������� ������
							}
						}
						printAllpole(poleK, infPole.poleY, infPole.poleX); // ������� �� ����
						poleK[cursor.posY][cursor.posX].print(1);//������ ������� �� ������
						cursorColor(78);              //���� �������
						gotoXY(5, 29);// ��������� ���������� �������
						cout << "�� ��������!!!   ";
						//system("pause"); // ����� ����� �������
						while (menu == 0)
						{
							if (GetAsyncKeyState(0x20))// ������
							{
								keybd_event(0x20, 0, KEYEVENTF_KEYUP, 0);//�������� ������
								menu = -1; // ���������� ���� ����� � ������� ����
							}
						}
					}
				}

			}//==============================================End Game =========================================
		}
		
		if (menu == 1) //---------------------------------------------���� 1 ��������� ------------------------------------- 
		{
			cursorColor(1); // ��������� ����� �������
			system("cls"); //�������� �����
			//printMenu_v1(menu1a, 6, 45, posYmenu1-7,false);
			cursorColor(4); // ��������� ����� �������
			for (int i = 0; i < 6; i++) // ������ ������� ����
			{
				gotoXY(centerX - 23, posYmenu1 - 7 + i); // ���������� �������
				cout << *(menu1a + i) << endl; // ����� ������
			}
			cursorColor(9); // ��������� ����� �������
			printMenu_v1(menu2, 6, 21, posYmenu1); // ������� ����
			menu2u.print2(); // ������� ������� ������ ����
			cursorColor(4); // ��������� ����� �������
			gotoXY(65, posYmenu1 + 2); //������ �� ���������� 
			cout << infPole.poleY; // ����� ����������
			if (infPole.poleY < 10) cout << " ";// �������� ������
			gotoXY(65, posYmenu1 + 3);//������ �� ����������
			cout << infPole.poleX;// ����� ����������
			if (infPole.poleX < 10) cout << " ";// �������� ������
			gotoXY(65, posYmenu1 + 4);//������ �� ����������
			cout << infPole.slozhnost;// ����� ����������
			cursorColor(9);              //���� �������
			gotoXY(25, 29);// ��������� ���������� �������
			cout << " ��� ��������� �� ���� ����������� \"������\", � ��� ������ \"������\"  ";
		}

		while (menu == 1) //---------------------------------------------���� 1 ��������� ------------------------------------- 
		{
			while (menu == 1)// �������� ����
			{
				if (GetAsyncKeyState(VK_UP))//���� ������ ������� �����
				{
					keybd_event(VK_UP, 0, KEYEVENTF_KEYUP, 0);//�������� ������
					menu2u.up();//������� �������� �� ���� �����
					//if(menu2u.posY- menu2u.startY == 0) menu2u.up();//������� �������� �� ���� �����
				}
				if (GetAsyncKeyState(VK_DOWN))//���� ������ ������� ����
				{
					keybd_event(VK_DOWN, 0, KEYEVENTF_KEYUP, 0);//�������� ������
					menu2u.down();//������� �������� �� ���� ����
				}

				if (GetAsyncKeyState(0x20))// ���� ����� ������
				{
					keybd_event(0x20, 0, KEYEVENTF_KEYUP, 0);//�������� ������

					if (menu2u.space()==3) menu = -1;// ���� ������� 3-� ������� �� ������� � ������� ����
					
				}

				if (GetAsyncKeyState(VK_LEFT))//���� ������ ������� �����
				{
					keybd_event(VK_LEFT, 0, KEYEVENTF_KEYUP, 0);//�������� ������
					
					switch (menu2u.posY - menu2u.startY)// ��������� ��������� �������
					{
					case 0:
						if (infPole.poleY < 3) infPole.poleY = 27; // ���� �������� ������� ��������� �� ������� �������� � �����
						else infPole.poleY--; // ����� ��������� �� 1
						cursorColor(4); // ��������� ����� �������
						gotoXY(65, menu2u.posY); //������ �� ����������
						cout << infPole.poleY; // ����� ����������
						if (infPole.poleY < 10) cout << " ";// �������� ������
						break;
					case 1:
						if (infPole.poleX < 3) infPole.poleX = 57; // ���� �������� ������� ��������� �� ������� �������� � �����
						else infPole.poleX--;// ����� ��������� �� 1
						cursorColor(4); // ��������� ����� �������
						gotoXY(65, menu2u.posY);//������ �� ����������
						cout << infPole.poleX;// ����� ����������
						if (infPole.poleX < 10) cout << " ";// �������� ������
						break;
					case 2:
						if (infPole.slozhnost < 11) infPole.slozhnost = 90; // ���� �������� ������� ��������� �� ������� �������� � �����
						else infPole.slozhnost--;// ����� ��������� �� 1
						cursorColor(4); // ��������� ����� �������
						gotoXY(65, menu2u.posY);//������ �� ����������
						cout << infPole.slozhnost;// ����� ����������
						break;
					}
				}


				if (GetAsyncKeyState(VK_RIGHT))//���� ������ ������� ������
				{
					keybd_event(VK_RIGHT, 0, KEYEVENTF_KEYUP, 0);//�������� ������
					
					    switch (menu2u.posY - menu2u.startY)// ��������� ��������� �������
						{
						case 0:
							if (infPole.poleY > 26) infPole.poleY = 2;// ���� �������� ������� ��������� �� ������� �������� � ������
							else infPole.poleY++;// ����� ��������� �� 1
							cursorColor(4); // ��������� ����� �������
							gotoXY(65,menu2u.posY);//������ �� ����������
							cout << infPole.poleY;// ����� ����������
							if(infPole.poleY<10) cout << " ";// �������� ������
							break;
						case 1:
							if (infPole.poleX > 56) infPole.poleX = 2;// ���� �������� ������� ��������� �� ������� �������� � ������
							else infPole.poleX++;// ����� ��������� �� 1
							cursorColor(4); // ��������� ����� �������
							gotoXY(65, menu2u.posY);//������ �� ����������
							cout << infPole.poleX;// ����� ����������
							if (infPole.poleX < 10) cout << " ";// �������� ������
							break;
						case 2:
							if (infPole.slozhnost > 89) infPole.slozhnost = 10;// ���� �������� ������� ��������� �� ������� �������� � ������
							else infPole.slozhnost++;// ����� ��������� �� 1
							cursorColor(4); // ��������� ����� �������
							gotoXY(65, menu2u.posY);//������ �� ����������
							cout << infPole.slozhnost;// ����� ����������
							break;
						}
					
				}

			}

		}
		while (menu == 2) //---------------------------------------------���� 2 ������� �������� ----------------------------------------
		{
			system("cls"); //�������� �����
			cursorColor(11); //���� �������
			gotoXY(48, 0);// ��������� ���������� �������
			cout << "*** ���� ���� ***";

			cursorColor(11);  //���� �������
			gotoXY(38, 28);// ��������� ���������� �������
			cout << "��� ������ � ���� - ������� ������";
			//records.printHead(); //������ �����
			//------------------------------------------- ������ �� ����� ----------------------------------------------------------------
			int dat[5];
			ifstream in; // ������ ������ ������ �� ������
	        in.open("records.txt"); // ��������� ���� �� ������
	        if (in.is_open())
	          {
				int i = 0;// ���������� ��� �������� ��������
				//int i2 = 0;//��������� ��� ������ ��������
				
					//in >> i2;// ��������� ���������� �����
					
					in.getline(records[i].name, 11); //������� � in � st ��� ������ �� ������� �������� ������
					in >> records[i].data >> records[i].slozhnost >> records[i].poleX >> records[i].poleY >> records[i].colTime; // ������ ������
					records[i].enable = true; //������� ��� ������ �������
					i++; //��������� �� 1
				
	        	in.close(); //������� ����
	          }

			//=========================================== ������ �� ����� ================================================================
			records->printHead(); // ������ ���������
			for (size_t i = 0; i < 10; i++)
			{
				//gotoXY(25, 10+i);// ���������� ������������ �������
				if(records[i].enable ==1) records[i].print(25,10+i); //���� ������ ����, �� �������
			}

            while (menu == 2)
			{
				if (GetAsyncKeyState(0x20))// ������
				{
					keybd_event(0x20, 0, KEYEVENTF_KEYUP, 0);//�������� ������
					menu = -1; // ���������� ������� ����� � ������� ����
				}
            }

		}//=========================================== ���� 2 ������� ��������=========================================

		while (menu==3) //---------------------------------------------���� 3 �� ������ ----------------------------------------
		{
			system("cls"); //�������� �����
			cursorColor(11); //���� �������
			gotoXY(48, 0);// ��������� ���������� �������
			cout << "*** ���� ���� ***";

			cursorColor(11);  //���� �������
			gotoXY(38, 28);// ��������� ���������� �������
			cout << "��� ������ � ���� - ������� ������";
			printMenu_v1(menu3, 6, 46, posYmenu1); // ������� ���� �� ������
			
			while (menu == 3)
			{
				if (GetAsyncKeyState(0x20))// ������
				{
					keybd_event(0x20, 0, KEYEVENTF_KEYUP, 0);//�������� ������
					menu = -1; // ���������� ������� ����� � ������� ����
				}
            }
		}//===========================================�� ������=========================================
	
		
    }
	//---------------------- �����-----------------------
	cout << endl; //������� ������
	system("pause"); // ����� ����� �������
}
