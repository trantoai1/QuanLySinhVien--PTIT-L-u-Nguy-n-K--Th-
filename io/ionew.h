#include"..\define\define.h"
#include"md5.h"
#include"..\console\console.h"
#include <io.h>
/*=============== STRUCT ===============*/
	/*Check input*/
#ifndef INPUTSTRSV
#define INPUTSTRSV
#define INPUTMAX 255
#define BACKSPACE 8
struct INPUTSTR{  
	unsigned int n;
	char KEY[INPUTMAX];
};
char *str_2_char(string str,int len=0);
string inNameSTR(int len=0);
void inName(char *NAME,int len=0);
void inNum(int *Num,int len=0);
void inNumSTR(char *Num,int len=0);
void inNumF(float *Num,int len=0);
void inCHUSO(char *NAME,char Type='N',int len=0);
void inCHUSOSTR(string *NAME,char Type='N',int len=0);
void inPASS(char *NAME,int len=0);
void inNumUS(unsigned int *Num,int len=0);
void inDiem(int *Num,int len=0);
void inGender(char *NAME,int len=0);
#endif

void TiengViet(const wchar_t *str);
string i_to_string(int n);
int Randnum();


