#include"menu/menu.h"
#include"io/ionew.h"

void Func(int menu,bool *repeat)
{
	/*Khai bao bien o day */
	
	
	/*---------------------*/
	switch (menu)
						{
						case 1:
							DelContent();
							char *Name = input('N');
							break;
						case 2:
							DelContent();
							
							break;
						case 3:
							DelContent();
							
							break;
						case 4:
							DelContent();
							break;
						case 5:
							DelContent();
							break;

						case NumMenu:
				
							*repeat = false;
							break;
						default:
							DelContent();
							_setmode(_fileno(stdout), _O_U16TEXT);
							wcout << L"Ch\u1ecdn không hợp l\u1ec7, vui lòng chọn lại"<<endl;
							_setmode(_fileno(stdout), _O_TEXT);
							system("pause");
							
							break;
						}
}
int main()
{


	MenuSw();

	return 0;
}
