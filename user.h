#include"define\define.h"
#include"io\FILE\file.h"

#ifndef USERSV
#define USERSV
struct USER{
	char username[15];
	char password[32];
};

#endif

void InitUser();
int CHECKLOGIN(char *userlogin,char *passlogin);
