#include"user.h"
USER NEWUSER;
void InitUser()
{
	strcpy(NEWUSER.username,"");
	strcpy(NEWUSER.password,"");
	ifstream loaduser;
	loaduser.open("DATA\\USER\\list.data");

	if(!loaduser.is_open())
	{
		char file[]="DATA\\USER\\list.data";
		string DATA= "ADMIN\t827ccb0eea8a706c4c34a16891f84e7b";
		CREATFILE(file,&DATA);
		InitUser();
		return;
	}
	loaduser>>NEWUSER.username>>NEWUSER.password;

	loaduser.close();
}
int CHECKLOGIN (char *userlogin,char *passlogin)
{
	if (strcmp(userlogin,"")==0||strcmp(passlogin,"")==0)return -1;
	
	if (strcmp(NEWUSER.username,userlogin)==0)
	{
		if (strcmp(NEWUSER.password,passlogin)==0)
		return 1;
		return -2;
	} 

	 return -1;
	
}
