#include"user.h"
#include "student.h"
void Init()
{
	InitUser();
	
	SV_Init();
	MH_Init();
	TC_Init();
}

void Func2(int menu,int type)
{

			switch (menu)
			{
				case 1:
				{
					PRINTGUIDE(GUIDE[3][2]);
					TC_PRINTINFO(6);
				}
				break;
							
			}

			
			Sleep(SLEEPMENU);
			ClearMenuFunFULL();


}
void Func(int menu,int type)
{

PRINTGUIDE(GUIDE[type][menu-1]);
		switch (menu)
		{
		case 1:
			{
				switch(type)
				{
					case 0:/*Select Menu TC*/
					{
						MenuSw(menu);	
					}break;
					case 1:/*Them Lop tin chi*/
					{
						MH_PRINTMH(4);
						TC_Init();
					}break;
					case 2:/*Them SV,them lop*/
					{
						LOP_PRINTINFO(1);
						SV_Init();
					}break;
					case 3:/*Them Mon hoc*/
					{
						MH_ADDNEW();
						MH_Init();
					}break;
					case 4:/*Nhap diem*/
					{
						TC_PRINTINFO(1);
						TC_Init();	
					}break;
				}
				Menu(type,menu);
			}
		
			break;
		case 2:
			{
				switch(type)
				{
					case 0:/*Select Menu Sinh vien*/
					{
					MenuSw(menu);	
					}break;
					case 1:/*Sua va xoa lop TC*/
					{
						TC_PRINTINFO(3)	;
						TC_Init();
					}break;
					case 2:/*Sua va xoa Sinh vien*/
					{
						LOP_PRINTINFO(3);
						SV_Init();
					}break;
					case 3:/*Xoa va sua mon hoc*/
					{
						MH_PRINTMH(3);
						MH_Init();
					}break;
					case 4:/*In bang diem lop tin chi*/
					{
						TC_PRINTINFO(4);
					}break;
				}
				Menu(type,menu);
			}
		
					
			break;
		case 3:
		
			{
			
				switch(type)
				{
					case 0:/*Select Menu MH*/
					{
						MenuSw(menu);
					}break;
					case 1:/*tim lop tin chi*/
					{
						TC_SEARCH();
						TC_Init();
					}break;
					case 2:/*tim sinh vien*/
					{
						SV_SEARCH();
						SV_Init();	
					}break;
					case 3:/*Dang ky mon hoc*/
					{
						TC_PRINTINFO(5);
					}break;
					case 4:/*in Diem trung binh*/
					{
						LOP_PRINTINFO(4);
					}break;
				}
				Menu(type,menu);
			}
		
			break;
		case 4:
			{
				switch(type)
				{
					case 0:/*Select Menu DIEM*/
					{
						MenuSw(menu);
					}break;
					case 1:/*in DSSV lop tc*/
					{
						TC_PRINTINFO(2);	
					}break;
					case 2:/*in DSSV 1 lop*/
					{
						LOP_PRINTINFO(2);
					}break;
					case 3:/*in DS Mon hoc*/
					{
						MH_PRINTMH(2);	
					}break;
					case 4:/*in diem tong ket*/
					{
						LOP_PRINTINFO(5);
					}break;
				}
				Menu(type,menu);
			}break;
		
						
		}
					
PRINTGUIDE(GUIDE[0][menu-1]);
ClearMenuFunFULL();
gotoMenuEX();

}


int main()
{
	resizeConsole(1364,743);
	remove_scrollbar();
	Init();

	//DialogLoginCheck();

	VEKHUNG();
	MenuSw(0);
	return 0;
}

