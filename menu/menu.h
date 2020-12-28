#include "..\io\ionew.h"
#include"..\define\define.h"
#include "..\user.h"
#include "..\io\lang.h"

#ifndef MENU
#define MENU
#define NUMLINETITLE 6 /*so dong Tieu de bang*/
#define maxwtable 127 /*do dai toi da cua bang*/
#define NUMLINETABLE 15 /*so dong toi da cua bang*/
#define MENUMAINLEFT 2 //MENU chinh cach le trai
#define MENUCOLOR 46
#define columchar 219 //mã ASCII Cot doc
#define floorchar 223 //mã ASCII gach duoi
#define topchar 220 //mã ASCII gach tren
#define WKHUNG 164
#define HKHUNG 43
#define DEFAULT -1
#define PRINT 2
#define EDITSVX 100
#define EDITSVY 11
#define EDITSVW 60
#define EDITSVH 30
#define INPUTEDITW 40

#define	LOGINX 63
#define LOGINY 15
#define WLOGIN 40
#define HLOGIN 10
#define POSTC 5
#define WYESNO 7
#define SPACEYESNO 6
#define LEFTYN 5
#define YNPADDINGTOP 1
#define YNPADDINGLR 5
#define MIDTABLE 100
#define YNPOSY 14

#define F1 59
#define F2 60
#define F3 61
#define F4 62
#define F5 63
#define ESC 27
#define UP 72
#define DOWN 80
#define LEFT 75
#define RIGHT 77
#define PAGEUP 73
#define PAGEDOWN 81
#define HOME 71
#define YES 'y'
#define NO 'n'
#define NONE '-'
#define DEL 83

#define MALE 'm'
#define FEMALE 'f'

#define SLEEPMSG 1400
#define SLEEPLOGIN 600
#define SLEEPMENU 500

struct COT{
	unsigned int WCOT;/*% be rong cot*/
	const wchar_t *TENCOT;
};
struct MAXCOT{
	unsigned int SOLUONGCOT;
	COT *INFOCOT[10];
};

void Msg(const wchar_t *str,int type=0);
char MsgYN(const wchar_t *str,int func=0);
char MsgGender(int len=0);
void SELECTSV(char ans,int h=0);
void SELECTYN(char ans,int h=0);
void SELECTADD(char ans,int h=0);
void SELECTEDIT(char ans,int h=0);
void PRINTMAINMENU(const wchar_t MN[][MENUMAINTEXTLEN-MENUMAINPADDINGLEFT],int MAX,int cur,int type,int flag,int old=0);
#endif

void ClearMenuEX();
void ClearMenuFun();/*xoa khung Lenh*/
void ClearMenuMain();
void ClearMenuFunFULL();
void ClearMenuFunTABLE();
void ClearDetailTable();
void ClearTITLE();
void DelContent();/*xoa trang console*/

void DialogLogin();/*Hoi thoai dang nhap*/
void DialogLoginFAIL(int n);

void DRAWINSERTTABLE(const int x,int y,MAXCOT NEWCOT);
void DRAWTABLE(int sodong,MAXCOT NEWCOT);

void ERRORLOGINMSG(int n);

void Func(int menu,int type);
void Func2(int menu,int type);

void Menu(int type,int menu);
void Menu2(int type,int menu);
void MenuSw2(int type);
void MenuSw(int type);
void MsgSearch(const wchar_t *quest);

void gotoMenuFun();/*di toi khung Lenh*/
void gotoMenuEX();
void gotoMenuMain();
void gotoquest();
void gotouserlogin();/*nhay toi toa do nhap username*/
void gotopasslogin();/*nhay toi toa do nhap pass*/

void KHUNGYESNO(int len);
void KHUNGLOGIN();/*Ve khung chuong trinh*/


void PRINTTITLE(int menu,int type);

void VEKHUNG();
void PRINTGUIDE(const wchar_t HuongDan[][MENUMAINTEXTLEN-MENUMAINPADDINGLEFT]);
void CLEARGUIDE();





