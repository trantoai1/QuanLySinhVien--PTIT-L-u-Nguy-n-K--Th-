#include"..\console\console.h"
#include"menu.h"

void ClearMenuEX()/*xoa bang thong bao*/
{
	Nocursortype();
	for (int i=NumMenu*3+8;i<HKHUNG-NUMHINT-5;i++)
	{
		gotoxy(MENUMAINLEFT+1,i);
		for(int j=1;j<MENUMAINTEXTLEN-2;j++)
		cout << " ";
	}
	Yescursortype();
}
void ClearMenuMain()/*xoa bang chuc nang*/
{
	Nocursortype();
	gotoMenuMain();
	for(int i = getX();i<=NumMenu*3+3;i++)
	{
		gotoxy(MENUMAINLEFT+1,i);
		for(int j=1;j<MENUMAINTEXTLEN-2;j++)
		cout << " ";
	}
	Yescursortype();
}
void ClearDetailTable()/*xoa bang Table*/
{
	Nocursortype();
	gotoxy(MENUMAINTEXTLEN+1,4);
	for(int j=0;j<WKHUNG-1-MENUMAINTEXTLEN;j++)
		{
			cout << " ";
		}
		gotoxy(MENUMAINTEXTLEN+1,6);
	for(int j=0;j<WKHUNG-1-MENUMAINTEXTLEN;j++)
		{
			cout << " ";
		}
		gotoxy(MENUMAINTEXTLEN+1,7);
	for(int j=0;j<WKHUNG-1-MENUMAINTEXTLEN;j++)
		{
			cout << " ";
		}
		Yescursortype();
}
void ClearMenuFun()/*Xoa trang man hinh chuc nang*/
{
	Nocursortype();
	
	int max = getY()+8;
	if (max > HKHUNG-1)
	{
		max = HKHUNG-1;
	}
	
	if ( getX()== MENUMAINTEXTLEN+1&&getY()==1)return;
	
	for(int i=3;i<max;i++)
	{
	gotoxy(MENUMAINTEXTLEN+1,i);
		for(int j=0;j<WKHUNG-1-MENUMAINTEXTLEN;j++)
		{
			cout << " ";
		}
		
	}
	gotoMenuFun();	
	Yescursortype();
}
void ClearMenuFunTABLE()/*Xoa bang man hinh chuc nang*/
{
	Nocursortype();
	for(int i=2+NUMLINETITLE;i<HKHUNG-2;i++)
	{
	gotoxy(MENUMAINTEXTLEN+1,i);
		for(int j=0;j<WKHUNG-1-MENUMAINTEXTLEN;j++)
		{
			cout << " ";
		}
		
	}
		Yescursortype();
}
void ClearMenuFunFULL()/*xoa het menu FUNC*/
{
	Nocursortype();
	for(int i=3;i<HKHUNG-1;i++)
	{
	gotoxy(MENUMAINTEXTLEN+1,i);
		for(int j=0;j<WKHUNG-1-MENUMAINTEXTLEN;j++)
		{
			cout << " ";
		}
		
	}	
	Yescursortype();
}
void ClearTITLE()/*Xoa Title chuc nang*/
{
	Nocursortype();
	
	gotoxy(MENUMAINTEXTLEN+2,2);
	for(int i=0;i<maxwtable-10;i++)
	cout << " ";
	Yescursortype();
}
void DelContent()/*Xoa trang man hinh*/
{
	system("cls");
}

void DialogLogin()/*Hoi thoai login*/
{
	DelContent();
	KHUNGLOGIN();
	
}
void DialogLoginFAIL(int n)/*Hoi thoai Bao loi login*/
{
	int len[2]={13,19};
	gotoxy(LOGINX+WLOGIN/2-len[n+2]/2,LOGINY+8);
	Color(COLORTEXTALERT);
	ERRORLOGINMSG(n);
	Color(COLORDEFAUL);
	
}

void DRAWTABLE(int sodong,MAXCOT NEWCOT)/*Ve bang Function*/
{
	
	if (sodong > NUMLINETABLE+1)
	{
		sodong = NUMLINETABLE +1;
	}else if(sodong < NUMLINETABLE +1)
	{
	ClearMenuFunTABLE();	
	}
	Nocursortype();
	char firstchar,midchar,lastchar,degreechar;
	gotoMenuFun();
	const int x=getX()+2,y = getY()+1+NUMLINETITLE;
		int currentx,currenty;
	gotoxy(x,y);
	for (int j=0;j<2*sodong+1;j++)
	{
		gotoxy(x,y+j);
		if (j==0)
		{
			firstchar = char(218);
			midchar = char(196);
			lastchar = char(191);
			degreechar = char(194);
		}
		else if (j==2*sodong)
		{
			firstchar = char(192);
			midchar = char(196);
			lastchar = char(217);
			degreechar = char(193);
		}
		else if (j%2==0)
		{
			firstchar = char(195);
			midchar = char(196);
			lastchar = char(180);
			degreechar = char(197);
			
		}
			else 
		{
			firstchar = char(179);
			midchar = char(179);
			lastchar = char(179);
			degreechar = char(197);
		}
		cout << firstchar;
		if (j%2==0)
		{
			for (int i=0;i<WKHUNG-6-MENUMAINTEXTLEN;i++)
			{
				cout << midchar;
			}
			gotoxy(x+1,getY());
			
			for (int i=0;i<NEWCOT.SOLUONGCOT;i++)
			{
			gotoxy(getX()+NEWCOT.INFOCOT[i]->WCOT,getY());
			if (i!=NEWCOT.SOLUONGCOT-1)
			cout << degreechar;
			}
		}
		else if (j==1) {
			
			for (int i=0;i<NEWCOT.SOLUONGCOT;i++)
			{
			currentx=getX();
			currenty=getY();
			for(int k=0;k<NEWCOT.INFOCOT[i]->WCOT;k++) cout <<" ";
			gotoxy(currentx+NEWCOT.INFOCOT[i]->WCOT/2-wcslen(NEWCOT.INFOCOT[i]->TENCOT)/2,currenty);
			TiengViet(NEWCOT.INFOCOT[i]->TENCOT);
			
			gotoxy(currentx+NEWCOT.INFOCOT[i]->WCOT,currenty);
			if (i!=NEWCOT.SOLUONGCOT-1)
			cout << midchar;
			}
		}
		else
		{
			for (int i=0;i<NEWCOT.SOLUONGCOT;i++)
			{
			currentx=getX();
			currenty=getY();
			
			for(int k=0;k<NEWCOT.INFOCOT[i]->WCOT;k++) cout <<" ";
		
			if (i!=NEWCOT.SOLUONGCOT-1)
			cout << midchar;
			}
		}
		cout << lastchar;
	
	
	}

	Yescursortype();

	
}
void DRAWINSERTTABLE(const int x,int y,MAXCOT NEWCOT)/*Ve bang Function*/
{
	Nocursortype();
	int currentx,currenty;
	gotoxy(x,y-1);
		cout << char(195);

			for (int i=0;i<WKHUNG-6-MENUMAINTEXTLEN;i++)
			{
				cout << char(196);
			}
			gotoxy(x+1,getY());
			
			for (int i=0;i<NEWCOT.SOLUONGCOT;i++)
			{
			gotoxy(getX()+NEWCOT.INFOCOT[i]->WCOT,getY());
			if (i!=NEWCOT.SOLUONGCOT-1)
			cout << char(197);
			}
		
		cout <<  char(180);
	
	gotoxy(x,y);

			cout << char(179);

			for (int i=0;i<NEWCOT.SOLUONGCOT;i++)
			{
			currentx=getX();
			currenty=getY();
			
			
			gotoxy(currentx+NEWCOT.INFOCOT[i]->WCOT,currenty);
			if (i!=NEWCOT.SOLUONGCOT-1)
			cout << char(179);
			}
		
		cout <<  char(179);
	gotoxy(x,y+1);
	cout << char(192);

			for (int i=0;i<WKHUNG-6-MENUMAINTEXTLEN;i++)
			{
				cout << char(196);
			}
			gotoxy(x+1,getY());
			
			for (int i=0;i<NEWCOT.SOLUONGCOT;i++)
			{
			gotoxy(getX()+NEWCOT.INFOCOT[i]->WCOT,getY());
			if (i!=NEWCOT.SOLUONGCOT-1)
			cout << char(193);
			}
		
		cout <<  char(217);
		Yescursortype();
}


void ERRORLOGINMSG(int n)/*Bao loi login*/
{	
	switch (n)
	{
		case -1:
		{
			TiengViet(L"T\u00E0i kho\u1EA3n kh\u00F4ng t\u1ED3n t\u1EA1i");
		}break;
		case -2:
		{
			TiengViet(L"Sai mật khẩu!");
		}break;
	}
	
}

void gotoMenuFun()/*Nhay toi toa do man hinh chuc nang*/
{
	gotoxy(MENUMAINTEXTLEN+1,1);
}
void gotoMenuMain()/*Nhay toi toa do chuc nang*/
{
	gotoxy(3,1);
}
void gotoquest()/*Nhay toi toa do tim kiem*/
{
	gotoxy(MIDTABLE-17,YNPOSY+5);
}
void gotoMenuEX()/*Nhay toi toa do man hinh phu*/
{
	gotoxy(MENUMAINLEFT+2,NumMenu*3+8);
}
void gotouserlogin()/*Nhay toi toa do username*/
{
	gotoxy(LOGINX+WLOGIN/2-1,LOGINY+3);
}
void gotopasslogin()/*Nhay toi toa do password*/
{
	gotoxy(LOGINX+WLOGIN/2-1,LOGINY+6);
}
void KHUNGLOGIN()/*Ve khung dang nhap*/
{
	Nocursortype();
	Color(COLORKHUNG);
	char firstchar,midchar,lastchar ;
	for(int i=0;i<HLOGIN;i++)
	{
		gotoxy(LOGINX,LOGINY+i);
		if (i==0)
		{
			firstchar = char(topchar);
			midchar = char(topchar);
			lastchar = char(topchar);
		}
		else if(i==HLOGIN-1)
		{
			firstchar = char(floorchar);
			midchar = char(floorchar);
			lastchar = char(floorchar);
		}
		else
		{
			firstchar = char(columchar);
			midchar = ' ';
			lastchar = char(columchar);
		}
		cout << firstchar;
		for(int j=1;j<WLOGIN-1;j++)
		{
			cout << midchar;
		}
		cout << lastchar<<endl;
	
	}
	Color(COLORDEFAUL);
	
	gotoxy(LOGINX+WLOGIN/2-2,LOGINY+2);
	cout<<char(218);for(int i=1;i<WLOGIN/2-2;i++)cout<<char(196);cout<<char(191);
	gotoxy(LOGINX+WLOGIN/2-16,LOGINY+3);
	TiengViet(L"Tên \u0111\u0103ng nhập");
	cout << ' ';
	cout<<char(179);for(int i=1;i<WLOGIN/2-2;i++)cout<<' ';cout<<char(179);
	gotoxy(LOGINX+WLOGIN/2-2,LOGINY+4);
	cout<<char(192);for(int i=1;i<WLOGIN/2-2;i++)cout<<char(196);cout<<char(217);
	gotoxy(LOGINX+WLOGIN/2-2,LOGINY+5);
	cout<<char(218);for(int i=1;i<WLOGIN/2-2;i++)cout<<char(196);cout<<char(191);
	gotoxy(LOGINX+WLOGIN/2-11,LOGINY+6);
	TiengViet(L"Mật khẩu");
	cout << ' ';
	cout<<char(179);for(int i=1;i<WLOGIN/2-2;i++)cout<<' ';cout<<char(179);
	gotoxy(LOGINX+WLOGIN/2-2,LOGINY+7);
	cout<<char(192);for(int i=1;i<WLOGIN/2-2;i++)cout<<char(196);cout<<char(217);
	gotouserlogin();
	Yescursortype();
}
void KHUNGYESNO(int len)/*Ve khung YN*/
{
	Nocursortype();
	Color(COLORKHUNG);
	char firstchar,midchar,lastchar ;
	for(int i=0;i<HLOGIN;i++)
	{
		gotoxy(MIDTABLE-len/2-YNPADDINGLR,YNPOSY+i);
		if (i==0)
		{
			firstchar = char(topchar);
			midchar = char(topchar);
			lastchar = char(topchar);
		}
		else if(i==HLOGIN-1)
		{
			firstchar = char(floorchar);
			midchar = char(floorchar);
			lastchar = char(floorchar);
		}
		else
		{
			firstchar = char(columchar);
			midchar = ' ';
			lastchar = char(columchar);
		}
		cout << firstchar;
		for(int j=1;j<WLOGIN-1;j++)
		{
			cout << midchar;
		}
		cout << lastchar<<endl;
	
	}
	Color(COLORDEFAUL);
	Yescursortype();
}
void PRINTMAINMENU(const wchar_t MN[][MENUMAINTEXTLEN-MENUMAINPADDINGLEFT],int MAX,int cur,int type,int flag,int old)/*in Main Menu*/
{
	
	if(flag==1) ClearMenuMain();
	Nocursortype();
	for(int i=0;i<MAX;i++)
	{
		if(i==cur-1)
		{
			gotoxy(3+type*2,i*3+4);	
			if(type==0)Color(COLORMAIN);else Color(COLORMAINSUB);
			for (int k=1;k<MENUMAINTEXTLEN-3-type*4;k++)cout << char(topchar);	
			gotoxy(3+type*2,i*3+5);
			cout << char(columchar);
			if(type==0)Color(COLORMAINR);else Color(COLORMAINRSUB);
			for(int k=0;k<MENUMAINTEXTLEN-6-type*4;k++)cout<<' ';
			Color(COLORDEFAUL);
			gotoxy(MENUMAINTEXTLEN-2-type*2,i*3+5);
			if(type==0)Color(COLORMAIN);else Color(COLORMAINSUB);
			cout << char(columchar);
			gotoxy(3+type*2,i*3+6);
			for (int k=1;k<MENUMAINTEXTLEN-3-type*4;k++)cout << char(floorchar);
			gotoxy(MENUMAINTEXTLEN/2 - wcslen(MN[i])/2+2,i*3+5);
			if(type==0)Color(COLORMAINR);else Color(COLORMAINRSUB);
			TiengViet(MN[i]);
			Color(COLORDEFAUL);	
		}
		else if(i==old-1)
		{
			gotoxy(3+type*2,i*3+4);
			cout << char(218);
			for (int k=1;k<MENUMAINTEXTLEN-5-type*4;k++)cout << char(196);	
			cout<<char(191);
			gotoxy(3+type*2,i*3+5);
			cout << char(179);
			Color(COLORDEFAUL);
			for(int k=0;k<MENUMAINTEXTLEN-6-type*4;k++)cout<<' ';
		
			gotoxy(MENUMAINTEXTLEN-2-type*2,i*3+5);
			cout << char(179);
			gotoxy(3+type*2,i*3+6);
			cout<<char(192);
			for (int k=1;k<MENUMAINTEXTLEN-5-type*4;k++)cout << char(196);
			cout<<char(217);
			gotoxy(MENUMAINTEXTLEN/2 - wcslen(MN[i])/2+2,i*3+5);
		
			TiengViet(MN[i]);
		
		}
		else
		{
			if(old==0)
			{
			gotoxy(3+type*2,i*3+4);
			cout << char(218);
			for (int k=1;k<MENUMAINTEXTLEN-5-type*4;k++)cout << char(196);	
			cout<<char(191);
			gotoxy(3+type*2,i*3+5);
			cout << char(179);
			Color(COLORDEFAUL);
			for(int k=0;k<MENUMAINTEXTLEN-6-type*4;k++)cout<<' ';
		
			gotoxy(MENUMAINTEXTLEN-2-type*2,i*3+5);
			cout << char(179);
			gotoxy(3+type*2,i*3+6);
			cout<<char(192);
			for (int k=1;k<MENUMAINTEXTLEN-5-type*4;k++)cout << char(196);
			cout<<char(217);
			gotoxy(MENUMAINTEXTLEN/2 - wcslen(MN[i])/2+2,i*3+5);
			
			TiengViet(MN[i]);
			
			}
		}
		
	}
	Yescursortype();
}
void Menu(int type,int menu)/*In menu chinh*/
{
	
	
	
	int sub = 0;
	PRINTTITLE(menu,type);
	if(type!=0) sub=1;
	PRINTMAINMENU(MenuName[type],NumMenu,menu,sub,1);
	gotoMenuEX();
}
void Menu2(int type,int menu)/*In menu chinh*/
{
	int sub = 0;
	PRINTTITLE(3,3);
	if(type!=0) sub=1;
	PRINTMAINMENU(MenuName2,NumMenu2,menu,sub,1);
	gotoMenuEX();
}
void MenuSw2(int type)/*Menu chuyen doi*/
{

	/*khai bao bien o day*/
	int sub = 0;
	if(type!=0) sub=1;
	int menu = 1;
	int menuold = 0;
	Menu2(type,menu);

  	 bool repeat = true;

	while(repeat)
	{	
		int mn = getch();
		 if(mn == 224)
		{
			int mn_val = getch();
			
			if (mn_val == UP)/*up*/
				{
					if (menu>1)
					{	
						menuold = menu;
						menu--;
					}
					else
					continue;
				}
				
			else if(mn_val == DOWN)/*down*/
				{
					if (menu < NumMenu2 )
					{	
						menuold = menu;
						menu++;
					}
					else
					continue;
				}
		
			
			PRINTTITLE(3,3);
			PRINTMAINMENU(MenuName2,NumMenu2,menu,sub,0,menuold);
			
			gotoMenuEX();
		}
		else if(mn==ESC) repeat = false;
		else if(mn==ENTER) Func2(menu,type);
		/* end if*/
	}/* end while*/	


}
void MenuSw(int type)/*Menu chuyen doi*/
{
	/*khai bao bien o day*/
	int sub = 0;
	if(type!=0) sub=1;
	int menu = 1;
	int menuold = 0;
	Menu(type,menu);

  	 bool repeat = true;

	while(repeat)
	{	
		int mn = getch();
		 if(mn == 224)
		{
			int mn_val = getch();
			
			if (mn_val == UP)/*up*/
				{
					if (menu>1)
					{	
						menuold = menu;
						menu--;
					}
					else
					continue;
				}
				
			else if(mn_val == DOWN)/*down*/
				{
					if (menu < NumMenu )
					{	
						menuold = menu;
						menu++;
					}
					else
					continue;
				}
			else
			continue;
			
			
			PRINTTITLE(menu,type);
			
			PRINTMAINMENU(MenuName[type],NumMenu,menu,sub,0,menuold);
			
			gotoMenuEX();
		}
		else if(mn==ESC) 
		{
			if(type==0)
			{
				char op = MsgYN(L"B\u1EA1n c\u00F3 ch\u1EAFc mu\u1ED1n \u0111\u0103ng xu\u1EA5t");
				if(op == YES)

				repeat = false;
				else
				{
					ClearMenuFunTABLE();
				continue;	
				}
				
			}
			else
			repeat = false;
		}
		else if(mn==ENTER) Func(menu,type);
		/* end if*/
	}/* end while*/	

}
void Msg(const wchar_t *str,int type)/*hien thi thong bao*/
{
	
  	int COLORTYPE[3]={COLORTEXTALERT,COLORDEFAUL,COLORTITLETEXT};
	int curX=getX(),curY=getY();
	ClearMenuEX();
	gotoMenuEX();
	Nocursortype();
	Color(COLORTYPE[type+1]);
	TiengViet(str);
	Color(COLORDEFAUL);
	Sleep(SLEEPMSG);
	Yescursortype();
	ClearMenuEX();
	gotoxy(curX,curY);
}
char MsgGender(int len)/*Hien thi lua chon gioi tinh*/
{

	int curX=getX(),curY=getY();
	char ans = MALE;
	Color(COLORSELECT);
	TiengViet(C_CHECKEDBOX);
	Color(COLORRDEFAUL);
	cout << " Nam ";
	Color(COLORDEFAUL);	
	for(int i =0;i<3+len;i++)cout << " ";
	TiengViet(C_UNCHECKBOX);
	TiengViet(L" Nữ ");
	gotoxy(curX,curY);
	while(true)
	{
		int select = getch();
		if (select == 224)
		{
			gotoxy(curX,curY);
			int select_val = getch();
			if (select_val==LEFT)
			{
				ans = MALE;
				Color(COLORSELECT);
				TiengViet(C_CHECKEDBOX);
				Color(COLORRDEFAUL);
				cout << " Nam ";
				Color(COLORDEFAUL);	
				for(int i =0;i<3+len;i++)cout << " ";
				TiengViet(C_UNCHECKBOX);
				TiengViet(L" Nữ ");
			}
			else if(select_val == RIGHT)
			{
				ans = FEMALE;
				TiengViet(C_UNCHECKBOX);
				cout << " Nam ";
				for(int i =0;i<3+len;i++)cout << " ";
				Color(COLORSELECT);
				TiengViet(C_CHECKEDBOX);
				Color(COLORRDEFAUL);
				TiengViet(L" Nữ ");
				Color(COLORDEFAUL);		
			}
			
			gotoxy(curX,curY);
		}else if( (char) select == ENTER)
		{
			gotoxy(curX,curY);
			return ans;
		}
	
		
		
	}
	
}
void MsgSearch(const wchar_t *quest)/*Hien thi bang tim kiem*/
{
	int len = wcslen(quest);
	
	KHUNGYESNO(30);
	gotoxy(MIDTABLE-len/2,YNPOSY+2);
	TiengViet(quest);
	gotoxy(MIDTABLE-18,YNPOSY+4);
	cout<<char(218);for(int j=1;j<35;j++)cout<<char(196);cout<<char(191);
	gotoxy(MIDTABLE-18,YNPOSY+5);
	cout<<char(179);for(int j=1;j<35;j++)cout<<' ';cout<<char(179);	
	gotoxy(MIDTABLE-18,YNPOSY+6);
	cout<<char(192);for(int j=1;j<35;j++)cout<<char(196);cout<<char(217);
	gotoquest();
}
char MsgYN(const wchar_t *str,int func)/*hien thi dialog YESNO*/
{
	Nocursortype();
	int curX=getX(),curY=getY();
	
	
	int len = wcslen(str);
	
	KHUNGYESNO(len);
	gotoxy(MIDTABLE-len/2,YNPOSY+2);
	TiengViet(str);
	gotoxy(MIDTABLE-11,YNPOSY+3);
	Color(COLORDISABLE2);
	TiengViet(L"(di chuy\u1EC3n \u2190 \u2192 \u0111\u1EC3 chọn)");
	Color(COLORDEFAUL);
	char ans = YES;
	if (func==0)
	{
		SELECTYN(ans);
	}
	else if (func==1)
	{
		SELECTADD(ans);
	}
	else if (func==2)
	{
		SELECTEDIT(ans);
	}
	else if (func==3)
	{
		SELECTSV(ans);
	}
	
	gotoxy(curX,curY);
	while(true)
	{
		int select = getch();
		if (select == 224)
		{
			int select_val = getch();
			if (select_val==LEFT)
			{
				ans = YES;
			}
			else if(select_val == RIGHT)
			{
				ans = NO;
			}
			if (func==0)
			{
				SELECTYN(ans);
			}
			else if (func==1)
			{
				SELECTADD(ans);
			}
			else if (func==2)
			{
				SELECTEDIT(ans);
			}
			else if (func==3)
			{
				SELECTSV(ans);
			}
			gotoxy(curX,curY);
		}else if( (char) select == ENTER)
		{
			gotoxy(curX,curY);
			Yescursortype();
			return ans;
		}
		
		
		
	}
	
}
void CLEARGUIDE()/*xoa vung huong dan*/
{
	Nocursortype();
	for(int j = 0;j<NUMHINT;j++)
	{
		gotoxy(MENUMAINLEFT+MENUMAINPADDINGLEFT,HKHUNG-1-NUMHINT+j);
		for (int i=0;i<MENUMAINTEXTLEN-4;i++)
		cout << " ";
	}
	Yescursortype();
}
void PRINTGUIDE(const wchar_t HuongDan[][MENUMAINTEXTLEN-MENUMAINPADDINGLEFT])/*In huong dan*/
{
	
	CLEARGUIDE();
	
	for (int i = 0; i < NUMHINT; i++)
	{
			gotoxy(MENUMAINLEFT+MENUMAINPADDINGLEFT,HKHUNG-1-NUMHINT+i);
		
			TiengViet(HuongDan[i] );
			
		
	
	}
}
void PRINTTITLE(int menu,int type)/*IN tieu de*/
{
	int curX=getX(),curY=getY();
	ClearTITLE();
	gotoxy(MIDTABLE-wcslen(MenuTITLE[type][menu-1])/2,2);
	Color(COLORTITLETEXT);
	TiengViet(MenuTITLE[type][menu-1]);
	Color(COLORDEFAUL);
	gotoxy(curX,curY);
}

void SELECTADD(char ans,int h)/*Chon Xem, Sua*/
{
	switch(ans)
	{
	case YES:
		{
			gotoxy(MIDTABLE-SPACEYESNO/2-WYESNO,YNPOSY+4+YNPADDINGTOP+h);
			Color(COLORSWSELECT);cout<<char(topchar);for(int i=0;i<WYESNO;i++)cout<<char(topchar);cout<<char(topchar);Color(COLORDEFAUL);
			gotoxy(MIDTABLE+SPACEYESNO/2+4,YNPOSY+4+YNPADDINGTOP+h);
			cout<<char(218);for(int i=0;i<WYESNO;i++)cout<<char(196);cout<<char(191);
			gotoxy(MIDTABLE-SPACEYESNO/2-WYESNO,YNPOSY+4+YNPADDINGTOP+1+h);
			Color(COLORSWSELECT);cout<<char(columchar);Color(COLORRDEFAUL);for(int i=0;i<WYESNO;i++)cout<<' ';Color(COLORSWSELECT);cout<<char(columchar);Color(COLORDEFAUL);
			gotoxy(MIDTABLE+SPACEYESNO/2+4,YNPOSY+4+YNPADDINGTOP+1+h);
			cout<<char(179);for(int i=0;i<WYESNO;i++)cout<<' ';cout<<char(179);
			gotoxy(MIDTABLE-SPACEYESNO/2-WYESNO,YNPOSY+4+YNPADDINGTOP+2+h);
			Color(COLORSWSELECT);cout<<char(floorchar);for(int i=0;i<WYESNO;i++)cout<<char(floorchar);cout<<char(floorchar);Color(COLORDEFAUL);
			gotoxy(MIDTABLE+SPACEYESNO/2+4,YNPOSY+4+YNPADDINGTOP+2+h);
			cout<<char(192);for(int i=0;i<WYESNO;i++)cout<<char(196);cout<<char(217);
			gotoxy(MIDTABLE-SPACEYESNO/2-WYESNO+3,YNPOSY+4+YNPADDINGTOP+1+h);
			Color(COLORRDEFAUL);
			TiengViet(L"Xem");
			Color(COLORDEFAUL);
			gotoxy(MIDTABLE+SPACEYESNO/2+7,YNPOSY+4+YNPADDINGTOP+1+h);
			TiengViet(L"Sửa");
		}break;
	case NO:
		{
			gotoxy(MIDTABLE-SPACEYESNO/2-WYESNO,YNPOSY+4+YNPADDINGTOP+h);
			cout<<char(218);for(int i=0;i<WYESNO;i++)cout<<char(196);cout<<char(191);			
			gotoxy(MIDTABLE+SPACEYESNO/2+4,YNPOSY+4+YNPADDINGTOP+h);
			Color(COLORSWSELECT);cout<<char(topchar);for(int i=0;i<WYESNO;i++)cout<<char(topchar);cout<<char(topchar);Color(COLORDEFAUL);
			gotoxy(MIDTABLE-SPACEYESNO/2-WYESNO,YNPOSY+4+YNPADDINGTOP+1+h);
			cout<<char(179);for(int i=0;i<WYESNO;i++)cout<<' ';cout<<char(179);
			gotoxy(MIDTABLE+SPACEYESNO/2+4,YNPOSY+4+YNPADDINGTOP+1+h);
			Color(COLORSWSELECT);cout<<char(columchar);Color(COLORRDEFAUL);for(int i=0;i<WYESNO;i++)cout<<' ';Color(COLORSWSELECT);cout<<char(columchar);Color(COLORDEFAUL);
			gotoxy(MIDTABLE-SPACEYESNO/2-WYESNO,YNPOSY+4+YNPADDINGTOP+2+h);
			cout<<char(192);for(int i=0;i<WYESNO;i++)cout<<char(196);cout<<char(217);
			gotoxy(MIDTABLE+SPACEYESNO/2+4,YNPOSY+4+YNPADDINGTOP+2+h);
			Color(COLORSWSELECT);cout<<char(floorchar);for(int i=0;i<WYESNO;i++)cout<<char(floorchar);cout<<char(floorchar);Color(COLORDEFAUL);
			gotoxy(MIDTABLE-SPACEYESNO/2-WYESNO+3,YNPOSY+4+YNPADDINGTOP+1+h);
			TiengViet(L"Xem");
			
			gotoxy(MIDTABLE+SPACEYESNO/2+7,YNPOSY+4+YNPADDINGTOP+1+h);
			Color(COLORRDEFAUL);
			TiengViet(L"Sửa");
			Color(COLORDEFAUL);
		}
	
	
	
	}
}
void SELECTEDIT(char ans,int h)/*Chon Them-EDIT*/
{
	switch(ans)
	{
	case YES:
		{
			gotoxy(MIDTABLE-SPACEYESNO/2-WYESNO,YNPOSY+4+YNPADDINGTOP+h);
			Color(COLORSWSELECT);cout<<char(topchar);for(int i=0;i<WYESNO;i++)cout<<char(topchar);cout<<char(topchar);Color(COLORDEFAUL);
			gotoxy(MIDTABLE+SPACEYESNO/2+4,YNPOSY+4+YNPADDINGTOP+h);
			cout<<char(218);for(int i=0;i<WYESNO;i++)cout<<char(196);cout<<char(191);
			gotoxy(MIDTABLE-SPACEYESNO/2-WYESNO,YNPOSY+4+YNPADDINGTOP+1+h);
			Color(COLORSWSELECT);cout<<char(columchar);Color(COLORRDEFAUL);for(int i=0;i<WYESNO;i++)cout<<' ';Color(COLORSWSELECT);cout<<char(columchar);Color(COLORDEFAUL);
			gotoxy(MIDTABLE+SPACEYESNO/2+4,YNPOSY+4+YNPADDINGTOP+1+h);
			cout<<char(179);for(int i=0;i<WYESNO;i++)cout<<' ';cout<<char(179);
			gotoxy(MIDTABLE-SPACEYESNO/2-WYESNO,YNPOSY+4+YNPADDINGTOP+2+h);
			Color(COLORSWSELECT);cout<<char(floorchar);for(int i=0;i<WYESNO;i++)cout<<char(floorchar);cout<<char(floorchar);Color(COLORDEFAUL);
			gotoxy(MIDTABLE+SPACEYESNO/2+4,YNPOSY+4+YNPADDINGTOP+2+h);
			cout<<char(192);for(int i=0;i<WYESNO;i++)cout<<char(196);cout<<char(217);
			gotoxy(MIDTABLE-SPACEYESNO/2-WYESNO+3,YNPOSY+4+YNPADDINGTOP+1+h);
			Color(COLORRDEFAUL);
			TiengViet(L"Thêm");
			Color(COLORDEFAUL);
			gotoxy(MIDTABLE+SPACEYESNO/2+7,YNPOSY+4+YNPADDINGTOP+1+h);
			TiengViet(L"Sửa");
		}break;
	case NO:
		{
			gotoxy(MIDTABLE-SPACEYESNO/2-WYESNO,YNPOSY+4+YNPADDINGTOP+h);
			cout<<char(218);for(int i=0;i<WYESNO;i++)cout<<char(196);cout<<char(191);			
			gotoxy(MIDTABLE+SPACEYESNO/2+4,YNPOSY+4+YNPADDINGTOP+h);
			Color(COLORSWSELECT);cout<<char(topchar);for(int i=0;i<WYESNO;i++)cout<<char(topchar);cout<<char(topchar);Color(COLORDEFAUL);
			gotoxy(MIDTABLE-SPACEYESNO/2-WYESNO,YNPOSY+4+YNPADDINGTOP+1+h);
			cout<<char(179);for(int i=0;i<WYESNO;i++)cout<<' ';cout<<char(179);
			gotoxy(MIDTABLE+SPACEYESNO/2+4,YNPOSY+4+YNPADDINGTOP+1+h);
			Color(COLORSWSELECT);cout<<char(columchar);Color(COLORRDEFAUL);for(int i=0;i<WYESNO;i++)cout<<' ';Color(COLORSWSELECT);cout<<char(columchar);Color(COLORDEFAUL);
			gotoxy(MIDTABLE-SPACEYESNO/2-WYESNO,YNPOSY+4+YNPADDINGTOP+2+h);
			cout<<char(192);for(int i=0;i<WYESNO;i++)cout<<char(196);cout<<char(217);
			gotoxy(MIDTABLE+SPACEYESNO/2+4,YNPOSY+4+YNPADDINGTOP+2+h);
			Color(COLORSWSELECT);cout<<char(floorchar);for(int i=0;i<WYESNO;i++)cout<<char(floorchar);cout<<char(floorchar);Color(COLORDEFAUL);
			gotoxy(MIDTABLE-SPACEYESNO/2-WYESNO+3,YNPOSY+4+YNPADDINGTOP+1+h);
			TiengViet(L"Thêm");
			
			gotoxy(MIDTABLE+SPACEYESNO/2+7,YNPOSY+4+YNPADDINGTOP+1+h);
			Color(COLORRDEFAUL);
			TiengViet(L"Sửa");
			Color(COLORDEFAUL);
		}
	
	
	
	}
}
void SELECTSV(char ans,int h)/*Chon,Nhap*/
{
	switch(ans)
	{
	case YES:
		{
			gotoxy(MIDTABLE-SPACEYESNO/2-WYESNO,YNPOSY+4+YNPADDINGTOP+h);
			Color(COLORSWSELECT);cout<<char(topchar);for(int i=0;i<WYESNO;i++)cout<<char(topchar);cout<<char(topchar);Color(COLORDEFAUL);
			gotoxy(MIDTABLE+SPACEYESNO/2+4,YNPOSY+4+YNPADDINGTOP+h);
			cout<<char(218);for(int i=0;i<WYESNO;i++)cout<<char(196);cout<<char(191);
			gotoxy(MIDTABLE-SPACEYESNO/2-WYESNO,YNPOSY+4+YNPADDINGTOP+1+h);
			Color(COLORSWSELECT);cout<<char(columchar);Color(COLORRDEFAUL);for(int i=0;i<WYESNO;i++)cout<<' ';Color(COLORSWSELECT);cout<<char(columchar);Color(COLORDEFAUL);
			gotoxy(MIDTABLE+SPACEYESNO/2+4,YNPOSY+4+YNPADDINGTOP+1+h);
			cout<<char(179);for(int i=0;i<WYESNO;i++)cout<<' ';cout<<char(179);
			gotoxy(MIDTABLE-SPACEYESNO/2-WYESNO,YNPOSY+4+YNPADDINGTOP+2+h);
			Color(COLORSWSELECT);cout<<char(floorchar);for(int i=0;i<WYESNO;i++)cout<<char(floorchar);cout<<char(floorchar);Color(COLORDEFAUL);
			gotoxy(MIDTABLE+SPACEYESNO/2+4,YNPOSY+4+YNPADDINGTOP+2+h);
			cout<<char(192);for(int i=0;i<WYESNO;i++)cout<<char(196);cout<<char(217);
			gotoxy(MIDTABLE-SPACEYESNO/2-WYESNO+3,YNPOSY+4+YNPADDINGTOP+1+h);
			Color(COLORRDEFAUL);
			TiengViet(L"Chọn");
			Color(COLORDEFAUL);
			gotoxy(MIDTABLE+SPACEYESNO/2+7,YNPOSY+4+YNPADDINGTOP+1+h);
			TiengViet(L"Nhập");
		}break;
	case NO:
		{
			gotoxy(MIDTABLE-SPACEYESNO/2-WYESNO,YNPOSY+4+YNPADDINGTOP+h);
			cout<<char(218);for(int i=0;i<WYESNO;i++)cout<<char(196);cout<<char(191);			
			gotoxy(MIDTABLE+SPACEYESNO/2+4,YNPOSY+4+YNPADDINGTOP+h);
			Color(COLORSWSELECT);cout<<char(topchar);for(int i=0;i<WYESNO;i++)cout<<char(topchar);cout<<char(topchar);Color(COLORDEFAUL);
			gotoxy(MIDTABLE-SPACEYESNO/2-WYESNO,YNPOSY+4+YNPADDINGTOP+1+h);
			cout<<char(179);for(int i=0;i<WYESNO;i++)cout<<' ';cout<<char(179);
			gotoxy(MIDTABLE+SPACEYESNO/2+4,YNPOSY+4+YNPADDINGTOP+1+h);
			Color(COLORSWSELECT);cout<<char(columchar);Color(COLORRDEFAUL);for(int i=0;i<WYESNO;i++)cout<<' ';Color(COLORSWSELECT);cout<<char(columchar);Color(COLORDEFAUL);
			gotoxy(MIDTABLE-SPACEYESNO/2-WYESNO,YNPOSY+4+YNPADDINGTOP+2+h);
			cout<<char(192);for(int i=0;i<WYESNO;i++)cout<<char(196);cout<<char(217);
			gotoxy(MIDTABLE+SPACEYESNO/2+4,YNPOSY+4+YNPADDINGTOP+2+h);
			Color(COLORSWSELECT);cout<<char(floorchar);for(int i=0;i<WYESNO;i++)cout<<char(floorchar);cout<<char(floorchar);Color(COLORDEFAUL);
			gotoxy(MIDTABLE-SPACEYESNO/2-WYESNO+3,YNPOSY+4+YNPADDINGTOP+1+h);
			TiengViet(L"Chọn");
			
			gotoxy(MIDTABLE+SPACEYESNO/2+7,YNPOSY+4+YNPADDINGTOP+1+h);
			Color(COLORRDEFAUL);
			TiengViet(L"Nhập");
			Color(COLORDEFAUL);
		}
	
	
	
	}
}
void SELECTYN(char ans,int h)/* YES - NO*/
{
	switch(ans)
	{
	case YES:
		{
			gotoxy(MIDTABLE-SPACEYESNO/2-WYESNO,YNPOSY+4+YNPADDINGTOP+h);
			Color(COLORSWSELECT);cout<<char(topchar);for(int i=0;i<WYESNO;i++)cout<<char(topchar);cout<<char(topchar);Color(COLORDEFAUL);
			gotoxy(MIDTABLE+SPACEYESNO/2,YNPOSY+4+YNPADDINGTOP+h);
			cout<<char(218);for(int i=0;i<WYESNO;i++)cout<<char(196);cout<<char(191);
			gotoxy(MIDTABLE-SPACEYESNO/2-WYESNO,YNPOSY+4+YNPADDINGTOP+1+h);
			Color(COLORSWSELECT);cout<<char(columchar);Color(COLORRDEFAUL);for(int i=0;i<WYESNO;i++)cout<<' ';Color(COLORSWSELECT);cout<<char(columchar);Color(COLORDEFAUL);
			gotoxy(MIDTABLE+SPACEYESNO/2,YNPOSY+4+YNPADDINGTOP+1+h);
			cout<<char(179);for(int i=0;i<WYESNO;i++)cout<<' ';cout<<char(179);
			gotoxy(MIDTABLE-SPACEYESNO/2-WYESNO,YNPOSY+4+YNPADDINGTOP+2+h);
			Color(COLORSWSELECT);cout<<char(floorchar);for(int i=0;i<WYESNO;i++)cout<<char(floorchar);cout<<char(floorchar);Color(COLORDEFAUL);
			gotoxy(MIDTABLE+SPACEYESNO/2,YNPOSY+4+YNPADDINGTOP+2+h);
			cout<<char(192);for(int i=0;i<WYESNO;i++)cout<<char(196);cout<<char(217);
			gotoxy(MIDTABLE-SPACEYESNO/2-WYESNO+4,YNPOSY+4+YNPADDINGTOP+1+h);
			Color(COLORRDEFAUL);
			TiengViet(L"Có");
			Color(COLORDEFAUL);
			gotoxy(MIDTABLE+SPACEYESNO/2+2,YNPOSY+4+YNPADDINGTOP+1+h);
			TiengViet(L"Không");
		}break;
	case NO:
		{
			gotoxy(MIDTABLE-SPACEYESNO/2-WYESNO,YNPOSY+4+YNPADDINGTOP+h);
			cout<<char(218);for(int i=0;i<WYESNO;i++)cout<<char(196);cout<<char(191);			
			gotoxy(MIDTABLE+SPACEYESNO/2,YNPOSY+4+YNPADDINGTOP+h);
			Color(COLORSWSELECT);cout<<char(topchar);for(int i=0;i<WYESNO;i++)cout<<char(topchar);cout<<char(topchar);Color(COLORDEFAUL);
			gotoxy(MIDTABLE-SPACEYESNO/2-WYESNO,YNPOSY+4+YNPADDINGTOP+1+h);
			cout<<char(179);for(int i=0;i<WYESNO;i++)cout<<' ';cout<<char(179);
			gotoxy(MIDTABLE+SPACEYESNO/2,YNPOSY+4+YNPADDINGTOP+1+h);
			Color(COLORSWSELECT);cout<<char(columchar);Color(COLORRDEFAUL);for(int i=0;i<WYESNO;i++)cout<<' ';Color(COLORSWSELECT);cout<<char(columchar);Color(COLORDEFAUL);
			gotoxy(MIDTABLE-SPACEYESNO/2-WYESNO,YNPOSY+4+YNPADDINGTOP+2+h);
			cout<<char(192);for(int i=0;i<WYESNO;i++)cout<<char(196);cout<<char(217);
			gotoxy(MIDTABLE+SPACEYESNO/2,YNPOSY+4+YNPADDINGTOP+2+h);
			Color(COLORSWSELECT);cout<<char(floorchar);for(int i=0;i<WYESNO;i++)cout<<char(floorchar);cout<<char(floorchar);Color(COLORDEFAUL);
			gotoxy(MIDTABLE-SPACEYESNO/2-WYESNO+4,YNPOSY+4+YNPADDINGTOP+1+h);
			TiengViet(L"Có");
			
			gotoxy(MIDTABLE+SPACEYESNO/2+2,YNPOSY+4+YNPADDINGTOP+1+h);
			Color(COLORRDEFAUL);
			TiengViet(L"Không");
			Color(COLORDEFAUL);
		}break;
	case NONE:
		{
			gotoxy(MIDTABLE-SPACEYESNO/2-WYESNO,YNPOSY+4+YNPADDINGTOP+h);
			cout<<char(218);for(int i=0;i<WYESNO;i++)cout<<char(196);cout<<char(191);			
			gotoxy(MIDTABLE+SPACEYESNO/2,YNPOSY+4+YNPADDINGTOP+h);
			cout<<char(218);for(int i=0;i<WYESNO;i++)cout<<char(196);cout<<char(191);	
			gotoxy(MIDTABLE-SPACEYESNO/2-WYESNO,YNPOSY+4+YNPADDINGTOP+1+h);
			cout<<char(179);for(int i=0;i<WYESNO;i++)cout<<' ';cout<<char(179);
			gotoxy(MIDTABLE+SPACEYESNO/2,YNPOSY+4+YNPADDINGTOP+1+h);
			cout<<char(179);for(int i=0;i<WYESNO;i++)cout<<' ';cout<<char(179);
			gotoxy(MIDTABLE-SPACEYESNO/2-WYESNO,YNPOSY+4+YNPADDINGTOP+2+h);
			cout<<char(192);for(int i=0;i<WYESNO;i++)cout<<char(196);cout<<char(217);
			gotoxy(MIDTABLE+SPACEYESNO/2,YNPOSY+4+YNPADDINGTOP+2+h);
			cout<<char(192);for(int i=0;i<WYESNO;i++)cout<<char(196);cout<<char(217);
			gotoxy(MIDTABLE-SPACEYESNO/2-WYESNO+4,YNPOSY+4+YNPADDINGTOP+1+h);
			TiengViet(L"Có");
			
			gotoxy(MIDTABLE+SPACEYESNO/2+2,YNPOSY+4+YNPADDINGTOP+1+h);
		
			TiengViet(L"Không");
		
		}break;
	
	
	}
}

void VEKHUNG()/*Ve khung chinh cua chuong trinh*/
{	Nocursortype();
	gotoxy(0,0);
	char firstchar,midchar,lastchar ;
		
		Color(COLORKHUNG);
	for(int i=0;i<HKHUNG;i++)
	{
	
		if (i==0)
		{
			firstchar = char(topchar);
			midchar = char(topchar);
			lastchar = char(topchar);
			cout << " "<<firstchar;
			for(int j=1;j<WKHUNG-1;j++)
			{
				cout << midchar;
			}
			cout << lastchar<<endl;
		}
		else if(i==HKHUNG-1)
		{
			firstchar = char(floorchar);
			midchar = char(floorchar);
			lastchar = char(floorchar);
			cout << " "<<firstchar;
			for(int j=1;j<WKHUNG-1;j++)
			{
				cout << midchar;
			}
			cout << lastchar<<endl;
		}
		else
		{
			firstchar = char(columchar);
			
			lastchar = char(columchar);
			cout << " "<<firstchar;
			gotoxy(WKHUNG,i);

				cout << lastchar<<endl;
		}
	
	
	}
	gotoxy(2,HKHUNG-1-NUMHINT-4);
	for (int i=1;i<MENUMAINTEXTLEN;i++)
	cout << char(205);
	for(int i=1;i<HKHUNG-1;i++)
	{
		gotoxy(MENUMAINTEXTLEN,i);
		cout << char(columchar);
	}
	Color(COLORDEFAUL);
	gotoxy(MENUMAINLEFT+MENUMAINPADDINGLEFT+7,2);
	
	Color(MENUCOLOR);
	TiengViet(L"  CHỨC N\u0102NG  ");
	Color(COLORDEFAUL);
	gotoxy(2,NumMenu*3+4);
	Color(COLORKHUNG);
	for (int i=1;i<MENUMAINTEXTLEN-1;i++)cout << char(205);
	Color(COLORDEFAUL);
	gotoxy(MENUMAINLEFT+MENUMAINPADDINGLEFT+7,NumMenu*3+6);
	Color(COLORTEXTALERT);
	TiengViet(L"  TH\u00d4NG BÁO  ");
	Color(COLORDEFAUL);
	gotoxy(MENUMAINLEFT+MENUMAINPADDINGLEFT+7,HKHUNG-1-NUMHINT-2);
	
	Color(MENUCOLOR);
	TiengViet(L"  HU\u1edaNG DẪN  ");
	Color(COLORDEFAUL);
	cout << endl;
	for (int i = 0; i < NUMHINT; i++)
	{
		gotoxy(MENUMAINLEFT+MENUMAINPADDINGLEFT,HKHUNG-1-NUMHINT+i);
			TiengViet(MenuHINT[i] );
		
	}
	Yescursortype();
}


