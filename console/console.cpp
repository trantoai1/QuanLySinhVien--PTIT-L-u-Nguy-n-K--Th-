#include"..\define\define.h"
#include"console.h"
void resizeConsole(int width, int height)
{
	HWND c = GetConsoleWindow();
	DWORD style = GetWindowLong(c , GWL_STYLE);
	RECT r;
	COORD s={width,height};
	GetWindowRect(c, &r);
	MoveWindow(c, 1, 1, width, height, TRUE);
	style &= ~WS_MAXIMIZEBOX ;
	SetWindowLong(c , GWL_STYLE, style);
	SetWindowPos(c , NULL, 1, 1, width, height, SWP_NOSIZE|SWP_NOMOVE|SWP_FRAMECHANGED);
	

}
void remove_scrollbar()
{
	
    HANDLE handle = GetStdHandle(STD_OUTPUT_HANDLE);
    CONSOLE_SCREEN_BUFFER_INFO info;
    GetConsoleScreenBufferInfo(handle, &info);
    COORD new_size = 
    {
        info.srWindow.Right - info.srWindow.Left +1,
        info.srWindow.Bottom - info.srWindow.Top + 1
    };
    SetConsoleScreenBufferSize(handle, new_size);
  	system("color F0");
	string title = ("                                                                                                                                                                     QUAN LY SINH VIEN - SV:TRAN OANH TOAI - N17DCCN155");
	SetConsoleTitle(title.c_str());
}

void gotoxy(int x, int y)
{
  static HANDLE h = NULL;  
  if(!h)
    h = GetStdHandle(STD_OUTPUT_HANDLE);
  COORD c = { x, y };  
  SetConsoleCursorPosition(h,c);
}
int getX()//lay toa do x hien tai cua con tro console.
{
	CONSOLE_SCREEN_BUFFER_INFO csbi;
	if (GetConsoleScreenBufferInfo(GetStdHandle(STD_OUTPUT_HANDLE), &csbi))
		return csbi.dwCursorPosition.X;
	return -1;
}
int getY()
{
	CONSOLE_SCREEN_BUFFER_INFO csbi;
	if (GetConsoleScreenBufferInfo(GetStdHandle(STD_OUTPUT_HANDLE), &csbi))
		return csbi.dwCursorPosition.Y;
	return -1;
}
void Nocursortype()
{
	CONSOLE_CURSOR_INFO Info;
	Info.bVisible = FALSE;
	Info.dwSize = 20;
	SetConsoleCursorInfo(GetStdHandle(STD_OUTPUT_HANDLE), &Info);
}
void Yescursortype()
{
	CONSOLE_CURSOR_INFO Info;
	Info.bVisible = TRUE;Info.dwSize=20;
	SetConsoleCursorInfo (GetStdHandle (STD_OUTPUT_HANDLE), &Info);
}
HANDLE console()
{
	return GetStdHandle(STD_OUTPUT_HANDLE); 
} 
void Color(int num)
{
	SetConsoleTextAttribute(console(), num);
}
