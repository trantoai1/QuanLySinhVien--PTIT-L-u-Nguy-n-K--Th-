

#include"ionew.h"


void inCHUSO(char *NAME,char Type,int len)/*Dinh dang nhap chu va so*/
{
	int MAXNHAP = len;
	if (MAXNHAP == 0)MAXNHAP = INPUTMAX;
	
	fflush(stdin);
	INPUTSTR NHAP;	
	NHAP.n = 0;
	while(true)
	{
		char mn=getch();
		
		if (!kbhit()&&!(!((int)mn>=65&&(int)mn<=90)&&!((int)mn>=97&&(int)mn<=122)&&mn!='-'&&!((int)mn>=48&&(int)mn<=57))&&NHAP.n<MAXNHAP)
		{


			if (NHAP.n>0&&NHAP.KEY[NHAP.n-1]=='-'&&mn=='-')
			{
				continue;
			}
			if (!(NHAP.n==0 && mn=='-') )
			{
			if (Type == 'U')mn = toupper(mn);
			else if(Type == 'L')mn = tolower(mn);

			cout << mn;
			NHAP.KEY[NHAP.n]=mn;
			NHAP.n++;
			}
			
		}
		if (mn==ENTER)
		{
			if (NHAP.n>0&&NHAP.KEY[NHAP.n-1]=='-')
			{
			gotoxy(getX()-1,getY());
			cout << " ";
			gotoxy(getX()-1,getY());
				if (NHAP.n > 0) 
				{
					
					NHAP.n--;
				}	
			}
			break;
		}
		else if(mn == 8&& NHAP.n > 0)
		{
			gotoxy(getX()-1,getY());
			cout << " ";
			gotoxy(getX()-1,getY());
		
			NHAP.n--;
			
		}
	}
	for (int i=0;i<NHAP.n;i++)
	{
		NAME[i] = NHAP.KEY[i];
	}
	NAME[NHAP.n] = '\0';
}
void inCHUSOSTR(string *NAME,char Type,int len)/*Dinh dang nhap chu va so*/
{
	int MAXNHAP = len;
	if (MAXNHAP == 0)MAXNHAP = INPUTMAX;
	
	fflush(stdin);
	INPUTSTR NHAP;	
	NHAP.n = 0;
	while(true)
	{
		char mn=getch();
		if (!kbhit()&&!(!((int)mn>=65&&(int)mn<=90)&&!((int)mn>=97&&(int)mn<=122)&&mn!='-'&&!((int)mn>=48&&(int)mn<=57))&&NHAP.n<MAXNHAP)
		{


			if (NHAP.n>0&&NHAP.KEY[NHAP.n-1]=='-'&&mn=='-')
			{
				continue;
			}
			if (!(NHAP.n==0 && mn=='-') )
			{
			if (Type == 'U')mn = toupper(mn);
			else if(Type == 'L')mn = tolower(mn);
			
			cout << mn;
			NHAP.KEY[NHAP.n]=mn;
			NHAP.n++;
			}
			
		}
		if (mn==ENTER)
		{
			if (NHAP.n>0&&NHAP.KEY[NHAP.n-1]=='-')
			{
			gotoxy(getX()-1,getY());
			cout << " ";
			gotoxy(getX()-1,getY());
				if (NHAP.n > 0) 
				{
					//delete NHAP.KEY[NHAP.n];
					NHAP.n--;
				}	
			}
			break;
		}
		else if(mn == 8&& NHAP.n > 0)
		{
			gotoxy(getX()-1,getY());
			cout << " ";
			gotoxy(getX()-1,getY());
		
			NHAP.n--;
			
		}
	}
	for (int i=0;i<NHAP.n;i++)
	{
		NAME = NAME + NHAP.KEY[i];
	}
	
}
void inPASS(char *NAME,int len)/*dinh dang nhap pass*/
{
	int MAXNHAP = len;
	if (MAXNHAP == 0)MAXNHAP = INPUTMAX;
	
	fflush(stdin);
	INPUTSTR NHAP;	
	NHAP.n = 0;
	while(true)
	{
		char mn=getch();
		if (!kbhit()&&!(!((int)mn>=65&&(int)mn<=90)&&!((int)mn>=97&&(int)mn<=122)&&!((int)mn>=48&&(int)mn<=57))&&NHAP.n<MAXNHAP)
		{
			
			cout << "*";
			NHAP.KEY[NHAP.n]=toupper(mn);
			NHAP.n++;
		}
		if (mn==ENTER)
		{
	
			break;
		}
		else if(mn == 8&& NHAP.n > 0)
		{
			gotoxy(getX()-1,getY());
			cout << " ";
			gotoxy(getX()-1,getY());
		
			NHAP.n--;
			
		}
	}
	for (int i=0;i<NHAP.n;i++)
	{
		NAME[i] = NHAP.KEY[i];
	}
	NAME[NHAP.n] = '\0';
	string pass ;
	for (int i=0;i<NHAP.n;i++)
	{
		pass = pass+NAME[i];
	}

	pass = md5(pass);

	for (int i=0;i<32;i++)
	{
		NAME[i] = pass[i];
	}
	NAME[32] = '\0';
	
}
char *str_2_char(string str,int len)/*convert string to char*/
{
	char *newchar;
	if (len == 0)
	len = str.length();

	newchar = new char[len];
	for (int i=0;i<len;i++)
	{
		newchar[i]=str[i];
	}
	newchar[len] = '\0';
	return newchar;
	
}
string i_to_string(int n)/*convert int to string*/
{
	char *intStr;
	intStr = new char [12];
	intStr = 	itoa(n,intStr,10);
	string str = string(intStr);
	delete []intStr;
	return str;
}
void inName(char *NAME,int len)/*Dinh dang nhap ten*/
{
	int MAXNHAP = len;
	if (MAXNHAP == 0)MAXNHAP = INPUTMAX;
	
	fflush(stdin);
	INPUTSTR NHAP;	
	NHAP.n = 0;
	while(true)
	{
		char mn=getch();
		if (!kbhit()&&!(!((int)mn>=65&&(int)mn<=90)&&!((int)mn>=97&&(int)mn<=122)&&mn!=' ')&&NHAP.n<MAXNHAP)
		{
			if (NHAP.n>0&&NHAP.KEY[NHAP.n-1]==' '&&mn==' ')
			{
				continue;
			}
			if (!(NHAP.n==0 && mn==' ') )
			{
			if (NHAP.n==0)
			mn = toupper(mn);
			else 
			{
				if (NHAP.KEY[NHAP.n-1]==' ')mn = toupper(mn);
				else mn = tolower(mn);
			}
			
			
			cout << mn;
			NHAP.KEY[NHAP.n]=mn;
			NHAP.n++;
			}
			
		}
		if (mn==ENTER)
		{
			if (NHAP.n>0&&NHAP.KEY[NHAP.n-1]==' ')
			{
			gotoxy(getX()-1,getY());
			cout << " ";
			gotoxy(getX()-1,getY());
			if (NHAP.n > 0) 
			{
			
				NHAP.n--;
			}
			
			}
			break;
		}
		else if(mn == BACKSPACE && NHAP.n > 0)
		{
			gotoxy(getX()-1,getY());
			cout << " ";
			gotoxy(getX()-1,getY());
				
		
			NHAP.n--;
					
			
		}
	}
	for (int i=0;i<NHAP.n;i++)
	{
		NAME[i] = NHAP.KEY[i];
	}
	NAME[NHAP.n] = '\0';
}
void inGender(char *NAME,int len)/*Dinh dang nhap ten*/
{
	int MAXNHAP = len;
	if (MAXNHAP == 0)MAXNHAP = INPUTMAX;
	
	fflush(stdin);
	INPUTSTR NHAP;	
	NHAP.n = 0;
	while(true)
	{
		char mn=getch();
		if (!kbhit()&&NHAP.n<MAXNHAP&&(mn=='N'||mn=='n'||mn=='a'||mn=='A'||mn=='m'||mn=='M'||mn=='u'||mn=='U'))
		{
			if (NHAP.n>0&&NHAP.KEY[NHAP.n-1]==' '&&mn==' ')
			{
				continue;
			}
			if(NHAP.n==0&&(mn!='n'&&mn!='N'))continue;
			if(NHAP.n==2&&(mn!='M'&&mn!='m'))continue;
			if(NHAP.n==1&&(mn!='a'&&mn!='A'&&mn!='u'&&mn!='U'))continue;
			if(NHAP.n==2&&(NHAP.KEY[1]=='u'||NHAP.KEY[NHAP.n-1]=='U'))
			{
				
				continue;
			}
			if (!(NHAP.n==0 && mn==' ') )
			{
			if (NHAP.n==0)
			mn = toupper(mn);
			else 
			{


				if (NHAP.KEY[NHAP.n-1]==' ')mn = toupper(mn);
				else mn = tolower(mn);
	
			}
			
			cout << mn;
			NHAP.KEY[NHAP.n]=mn;
			NHAP.n++;
			}
			
		}
		if (mn==ENTER)
		{
			if (NHAP.n>0&&NHAP.KEY[NHAP.n-1]==' ')
			{
			gotoxy(getX()-1,getY());
			cout << " ";
			gotoxy(getX()-1,getY());
			if (NHAP.n > 0) 
			{
			//	delete []NHAP.KEY[NHAP.n];
				NHAP.n--;
			}
			
			}
			break;
		}
		else if(mn == BACKSPACE && NHAP.n > 0)
		{
			gotoxy(getX()-1,getY());
			cout << " ";
			gotoxy(getX()-1,getY());
				
		
			NHAP.n--;
					
			
		}
	}
	for (int i=0;i<NHAP.n;i++)
	{
		NAME[i] = NHAP.KEY[i];
	}
	NAME[NHAP.n] = '\0';
}
string inNameSTR(int len)/*Dinh dang nhap ten*/
{
	string NAME;
	int MAXNHAP = len;
	if (MAXNHAP == 0)MAXNHAP = INPUTMAX;
	
	fflush(stdin);
	INPUTSTR NHAP;	
	NHAP.n = 0;
	while(true)
	{
		char mn=getch();
		if (!kbhit()&&!(!((int)mn>=65&&(int)mn<=90)&&!((int)mn>=97&&(int)mn<=122)&&mn!=' '&&!((int)mn>=48&&(int)mn<=57))&&NHAP.n<MAXNHAP)
		{
			if (NHAP.n>0&&NHAP.KEY[NHAP.n-1]==' '&&mn==' ')
			{
				continue;
			}
			if (!(NHAP.n==0 && mn==' ') )
			{
			if (NHAP.n==0)
			mn = toupper(mn);
			else 
			{
				 mn = tolower(mn);
			}
			
			
			cout << mn;
			NHAP.KEY[NHAP.n]=mn;
			NHAP.n++;
			}
			
		}
		if (mn==ENTER)
		{
			if (NHAP.n>0&&NHAP.KEY[NHAP.n-1]==' ')
			{
			gotoxy(getX()-1,getY());
			cout << " ";
			gotoxy(getX()-1,getY());
			if (NHAP.n > 0) 
			{
			//	delete []NHAP.KEY[NHAP.n];
				NHAP.n--;
			}
			
			}
			break;
		}
		else if(mn == BACKSPACE && NHAP.n > 0)
		{
			gotoxy(getX()-1,getY());
			cout << " ";
			gotoxy(getX()-1,getY());
				
		
			NHAP.n--;
					
			
		}
	}
	for (int i=0;i<NHAP.n;i++)
	{
		NAME = NAME +NHAP.KEY[i];
	}
	return NAME;
	
}
void inNum(int *Num,int len)/*Dinh dang nhap so int*/
{
	fflush(stdin);
	INPUTSTR NHAP;
	int MAXNHAP = len;
	if (MAXNHAP == 0)MAXNHAP = INPUTMAX;
	NHAP.n = 0;
	while(true)
	{
		char mn=getch();
		if (NHAP.n<9)
		{
			if (!kbhit()&&!((int)mn<48||(int)mn>57)&&NHAP.n<MAXNHAP)
			{
				
				cout << mn;
				NHAP.KEY[NHAP.n]=mn;
				NHAP.n++;
			}			
		}
		if(mn == BACKSPACE && NHAP.n > 0)
		{
			gotoxy(getX()-1,getY());
			cout << " ";
			gotoxy(getX()-1,getY());
			
		//	delete []NHAP.KEY[NHAP.n];
			NHAP.n--;
					

			
		}
		if (mn == ENTER)
		{
			break;
		}

	}	
	if(NHAP.n==0)return;
	char *NUMNEW;
	NUMNEW = new char[NHAP.n];
	for (int i=0;i<NHAP.n;i++)
	{
		NUMNEW[i] = NHAP.KEY[i];
	}
	NUMNEW[NHAP.n] = '\0';
	*Num = atoi(NUMNEW);
	delete []NUMNEW;
}
void inDiem(int *Num,int len)/*Dinh dang nhap so int*/
{
	fflush(stdin);
	INPUTSTR NHAP;
	int MAXNHAP = len;
	if (MAXNHAP == 0)MAXNHAP = INPUTMAX;
	NHAP.n = 0;
	while(true)
	{
		char mn=getch();
		if (NHAP.n<9)
		{
			if (!kbhit()&&!((int)mn<48||(int)mn>57)&&NHAP.n<MAXNHAP)
			{
				if(NHAP.n==1)
				{
					if(NHAP.KEY[0]=='1'&&mn=='0')
					{
						cout << mn;
						NHAP.KEY[NHAP.n]=mn;
						NHAP.n++;
					}
					else
					{
						continue;
					}
					
				}
				else if (NHAP.n==0)
				{
					cout << mn;
					NHAP.KEY[NHAP.n]=mn;
					NHAP.n++;
				}
				
				else
				{
					continue;
				}
				
			}			
		}
		if(mn == BACKSPACE && NHAP.n > 0)
		{
			gotoxy(getX()-1,getY());
			cout << " ";
			gotoxy(getX()-1,getY());
			
		//	delete []NHAP.KEY[NHAP.n];
			NHAP.n--;
					

			
		}
		if (mn == ENTER)
		{
			break;
		}

	}	
	if (NHAP.n ==0)
	{
		*Num = -2;
		return;
	}
	char *NUMNEW;
	NUMNEW = new char[NHAP.n];
	for (int i=0;i<NHAP.n;i++)
	{
		NUMNEW[i] = NHAP.KEY[i];
	}
	NUMNEW[NHAP.n] = '\0';
	*Num = atoi(NUMNEW);
	delete []NUMNEW;
}
void inNumUS(unsigned int *Num,int len)/*Dinh dang nhap so int*/
{
	fflush(stdin);
	INPUTSTR NHAP;
	int MAXNHAP = len;
	if (MAXNHAP == 0)MAXNHAP = INPUTMAX;
	NHAP.n = 0;
	while(true)
	{
		char mn=getch();
		if (NHAP.n<9)
		{
			if (!kbhit()&&!((int)mn<48||(int)mn>57)&&NHAP.n<MAXNHAP)
			{
				
				cout << mn;
				NHAP.KEY[NHAP.n]=mn;
				NHAP.n++;
			}			
		}
		if(mn == BACKSPACE && NHAP.n > 0)
		{
			gotoxy(getX()-1,getY());
			cout << " ";
			gotoxy(getX()-1,getY());
			
		//	delete []NHAP.KEY[NHAP.n];
			NHAP.n--;
					

			
		}
		if (mn == ENTER)
		{
			break;
		}

	}	
	if (NHAP.n==0) {
		*Num = 0;
		return;
	}
	char *NUMNEW;
	NUMNEW = new char[NHAP.n];
	for (int i=0;i<NHAP.n;i++)
	{
		NUMNEW[i] = NHAP.KEY[i];
	}
	NUMNEW[NHAP.n] = '\0';
	*Num = atoi(NUMNEW);
	delete []NUMNEW;
}
void inNumSTR(char *Num,int len)/*Dinh dang nhap so int*/
{
	fflush(stdin);
	INPUTSTR NHAP;
	int MAXNHAP = len;
	if (MAXNHAP == 0)MAXNHAP = INPUTMAX;
	NHAP.n = 0;
	while(true)
	{
		char mn=getch();
		if (NHAP.n<MAXNHAP)
		{
			if (!kbhit()&&!((int)mn<48||(int)mn>57)&&NHAP.n<MAXNHAP)
			{
			//	NHAP.KEY[NHAP.n] = new char;
				cout << mn;
				NHAP.KEY[NHAP.n]=mn;
				NHAP.n++;
			}			
		}
		if(mn == BACKSPACE && NHAP.n > 0)
		{
			gotoxy(getX()-1,getY());
			cout << " ";
			gotoxy(getX()-1,getY());
			
		//	delete []NHAP.KEY[NHAP.n];
			NHAP.n--;
					

			
		}
		if (mn == ENTER)
		{
			break;
		}

	}	

	for (int i=0;i<NHAP.n;i++)
	{
		Num[i] =  NHAP.KEY[i];
	}
}
void inNumF(float *Num,int len)/*nhap so dang float*/
{
	fflush(stdin);
	INPUTSTR NHAP;
	int MAXNHAP = len;
	if (MAXNHAP == 0)MAXNHAP = INPUTMAX;
	NHAP.n = 0;
	while(true)
	{
		char mn=getch();
		if (NHAP.n<9)
		{
			if (!kbhit()&&!((int)mn<48||(int)mn>57)&&NHAP.n<MAXNHAP||mn=='.')
			{
				
				cout << mn;
				NHAP.KEY[NHAP.n]=mn;
				NHAP.n++;
			}			
		}
		if(mn == BACKSPACE && NHAP.n > 0)
		{
			gotoxy(getX()-1,getY());
			cout << " ";
			gotoxy(getX()-1,getY());
				
			//delete []NHAP.KEY[NHAP.n];
			NHAP.n--;	
			
		}
		if (mn == ENTER)
		{
			break;
		}

	}	
	char *NUMNEW;
	NUMNEW = new char[NHAP.n];
	for (int i=0;i<NHAP.n;i++)
	{
		NUMNEW[i] = NHAP.KEY[i];
	}
	NUMNEW[NHAP.n] = '\0';
	*Num = atof(NUMNEW);
					
	delete []NUMNEW;

}
void TiengViet(const wchar_t *str)/*in tieng viet*/
{
	_setmode(_fileno(stdout), _O_U16TEXT);
	wcout << str;
	_setmode(_fileno(stdout), _O_TEXT);
}

int Randnum()
{
	
	return  rand()%1000 + 1000;
}
