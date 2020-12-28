#include <iostream>
#include <iomanip>
#include <cstdlib>
#include <ctime>
#include <string>
#include <string.h>
#include<stdio.h>
#include<stdlib.h>
#include<conio.h>
#include<windows.h>
#include <io.h>
#include <fcntl.h>

using namespace std;
HANDLE console = GetStdHandle(STD_OUTPUT_HANDLE); 
void Menu();
void MenuSw();
void Func(int menu, bool *repeat);


const int NumMenu = 6;
	string MenuName[NumMenu] = {

	"1.Nhap Ten",
	"2.Nhap so",
	"3.Nhap mat khau",
	"4.",
	"5.",
	// "6.",
	// "7.",
	// "8.",
	// "9.",
	// "10.",
	"ESC.Ket Thuc[Nhan ESC]"
	};
void DelContent()
{
	system("cls");
}


void gotoxy(int x, int y)
{
  static HANDLE h = NULL;  
  if(!h)
    h = GetStdHandle(STD_OUTPUT_HANDLE);
  COORD c = { x, y };  
  SetConsoleCursorPosition(h,c);
}

void Menu()
{

	DelContent();
	cout << setw(19) << "" << "********************************************************************************" << endl;
	cout << setw(20) << "*"  ;
	_setmode(_fileno(stdout), _O_U16TEXT);
	gotoxy(30,1);
	wcout << L"Chức n\u0103ng:\u2191 lên,\u2193 xu\u1ed1ng,ENTER chọn,ESC Thoát";
	/*co*/ _setmode(_fileno(stdout), _O_TEXT);
	cout << setw(25) << right << "*" << endl;
	for (int i = 0; i < NumMenu; i++)
	{
		if (i==0){
		cout << setw(20) << "*" << setw(10) << "";
		SetConsoleTextAttribute(console, 240);
		cout << MenuName[i] ;
		SetConsoleTextAttribute(console, 15);
		cout << setw(69 - MenuName[i].length()) << right << "*" << endl;

		}
		else
		{
				cout << setw(20) << "*" << setw(10) << "" << MenuName[i] << setw(69 - MenuName[i].length()) << right << "*" << endl;
		}
	
	}
	cout << setw(19) << "" << "********************************************************************************" << endl;

	cout << setw(20) << "" ;
	_setmode(_fileno(stdout), _O_U16TEXT);
	gotoxy(20,NumMenu+3);
	wcout << L"Mời bạn chọn chức n\u0103ng:";
	/*co*/ _setmode(_fileno(stdout), _O_TEXT);
	gotoxy(43,NumMenu+3);

	cout << 1;
	
	cout << endl << endl;
	gotoxy(29,2);
	_setmode(_fileno(stdout), _O_U16TEXT);
	wcout << L"\u2192";
	_setmode(_fileno(stdout), _O_TEXT);
	gotoxy(0,NumMenu+4);
}
void MenuSw()
{
	/*khai bao bien o day*/
	
	int menu = 1;
	Menu();

  	 bool repeat = true;

	while(repeat)
	{	
		int mn = getch();
		 if(mn == 224)
		{
			int mn_val = getch();
			if (mn_val == 72)
				{
						if (menu>1)
						{	gotoxy(29,menu+1);
							cout << " ";
							SetConsoleTextAttribute(console, 15);
							cout << MenuName[menu-1] ;
						
							menu--;
						}
				}
				
			else if(mn_val == 80)
				{
					if (menu < NumMenu )
					{	gotoxy(29,menu+1);
						cout << " ";
						SetConsoleTextAttribute(console, 15);
						cout << MenuName[menu-1] ;
						

						menu++;
						}
				}
			gotoxy(43,NumMenu+3);
			if(menu>=NumMenu)
			{	
			
			cout <<"ESC";
			menu = NumMenu;
			}
			else
			{
				cout << menu <<"  ";
			}
			gotoxy(29,menu+1);
			_setmode(_fileno(stdout), _O_U16TEXT);
			wcout << L"\u2192";
			

			_setmode(_fileno(stdout), _O_TEXT);
			SetConsoleTextAttribute(console, 240);
			cout << MenuName[menu-1] ;
			SetConsoleTextAttribute(console, 15);
			gotoxy(0,NumMenu+4);	
		}
		else
		{
			
			switch ((char) mn)
			{
			case 27:
				{
				repeat = false;
				break;
				
				}
			case '\r':
				{
				Func(menu,&repeat);
				menu = 1;
				Menu();
				gotoxy(0,NumMenu+4);	
			};/* end case \r */
				default: continue;
			}/*enc switch 1*/
				
		}/* end if*/
	}/* end while*/
	
	DelContent();
}

