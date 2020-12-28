#include"file.h"

void CREATFILE(char *filename,string *data)
{
	ofstream file;

	file.open(filename,ios::out|ios::trunc);
	file<<*data;
	file.close();
	
}
