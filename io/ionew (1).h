#include <string>
#include<iostream>
#include <cstring>
#include<windows.h>
#include<stdio.h>
#include<stdlib.h>
#include<conio.h>
#define INPUTMAX 255
using namespace std;

struct INPUTSTR{
	int n=0;
	char *KEY[INPUTMAX];
};

string ErrorInput(char *in,char type)
{
		string Error ="";
		switch (type)
	{

		case 'N':
			{
				for(int i =0;i<strlen(in);i++)
				{
					if(!((int)in[i]>=65&&(int)in[i]<=90)&&!((int)in[i]>=97&&(int)in[i]<=122)&&in[i]!=' ')
					{
							return Error ="Ten ban nhap khong hop le";
					}
				}
		
				
			}break;
		
		case 'I':
			{
				for(int i =0;i<strlen(in);i++)
				{
					if((int)in[i]<48||(int)in[i]>57)
				return Error ="So ban nhap khong hop le";
						
				}
			
				
			}break;
	
		
	}
	return Error;
}

char *input(char type)
{
	fflush(stdin);
	INPUTSTR NHAP;
	string Error = "Sai";
	char *in;
	switch (type)
		{
	
		case 'N':
			{
				while(true)
				{
					char mn=getch();
					if (!kbhit()&&!(!((int)mn>=65&&(int)mn<=90)&&!((int)mn>=97&&(int)mn<=122)&&mn!=' '))
					{
						NHAP.KEY[NHAP.n] = new char;
						cout << mn;
						*NHAP.KEY[NHAP.n]=mn;
						NHAP.n++;
					}
					else
					break;
					
				}
				//Error =  ErrorInput(in,type);
			}break;
	
		case 'I':
			{
					//cin.getline(in,255);
			//	Error =  ErrorInput(in,type);
			}
			break;
		//getch();
		case 'P':
			{
		
				while(!kbhit())
				{
					char mn=getch();
					if (mn!='\r')
					{
						cout << "*";
					//	in[i]=mn;
						//i++;
					}
					else
					break;
					
				}
				//Error =  ErrorInput(in,type);	
				
			}break;
		}
		cout << Error;
	in = new char[255];
	return in;
}


