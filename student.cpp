#include"student.h"

DSLOP LISTLOP;/*Quan ly danh sach lop*/
MNSV QLSV;/*Tao Quan ly con tro dau va cuoi*/


LISTSV FIRSTSV = NULL;
DSLOPTINCHI LISTTC;
TREE root = NULL;


int DANGKYMON[MAXLOPTINCHI];
int MONCODIEM[MAXLOPTINCHI];
int TONGTC = 0;
int TONGMH = 0;
string SESSIONUSER = "";
void DialogLoginCheck()/*Kiem tra dang nhap*/
{

	while(true)
	{
		SESSIONUSER ="";
		
		char *userlogin;
		userlogin = new char[15];
		char *passlogin;
		passlogin = new char[32];
		//cout << "aaaaa"; getch();
		DialogLogin();
		inCHUSO(userlogin,'U',15);
		//cout << userlogin << getch();
		gotopasslogin();
		inPASS(passlogin,15);
		if (CHECKLOGIN(userlogin,passlogin) == 0||SV_CHECKLOGINSV(userlogin,passlogin)>0) 
		{
			DelContent();
			if(SV_CHECKLOGINSV(userlogin,passlogin)>0)
			SESSIONUSER = (string)userlogin;
			VEKHUNG();
			if (CHECKLOGIN(userlogin,passlogin)>0)
			MenuSw(0);
			else
			MenuSw2(0);
		}
		else if((CHECKLOGIN(userlogin,passlogin) == -2&&SV_CHECKLOGINSV(userlogin,passlogin)==-1) ||(CHECKLOGIN(userlogin,passlogin) == -1&&SV_CHECKLOGINSV(userlogin,passlogin)==-2))
			DialogLoginFAIL(-2);
	
		else
			DialogLoginFAIL(-1);
		delete []userlogin;
		delete []passlogin;		
		Sleep(SLEEPLOGIN);
	}
}
/*==========================================================================*/
/*=======================Phan xu ly Sinh vien===============================*/
/*==========================================================================*/

void LOP_CAPNHATDANHSACHLOP(char *TENLOP)/*Them Lop moi vao danh sach list.data*/
{
	if(strcmp(TENLOP,"")==0) 
	{
		Msg(L"Tên l\u1EDBp không \u0111úng!",-1);
		return;
	}
	string DATA =i_to_string(++LISTLOP.SOLUONG);
	DATA = DATA + "\n";
	for(int i=0;i<LISTLOP.SOLUONG-1;i++)/*Nhap danh sach lop*/
	{
		DATA = DATA + LISTLOP.MALOP[i] +"\n";
	}
	DATA = DATA + string(TENLOP);
	char filelist[] = "DATA\\DSSV\\list.data";
	CREATFILE(filelist,&DATA);
}

int SV_CHECKLOGINSV (char *userlogin,char *passlogin)/*Kiem tra dang nhap bang Ma sinh vien*/
{
	if (strcmp(userlogin,"")==0||strcmp(passlogin,"")==0)return -1;
	string user = (string)userlogin;
	
	string pass = (string)passlogin;
	LISTSV p;
	for (p = QLSV.FIRST;  p  != NULL ; p=p->next ) 
	{
	
		if (p->SV.MASV==user)
		{
			if (p->SV.pass==pass)
			return 1;
			return -2;
		 } 
	}
    
	 return -1;
	
}

void SV_Clearlist(LISTSV &FIRSTSV)/*Xoa het DSSV*/
{  
	if (SV_Empty(FIRSTSV))
    	return;
   	LISTSV p;  
  	while(FIRSTSV != NULL)
   	{
     	p = FIRSTSV;
      	FIRSTSV = FIRSTSV->next;
      
     	delete p;
  	}
   	QLSV.FIRST=NULL;
   	QLSV.LAST=NULL;
}

int SV_Delete_First (LISTSV  &FIRSTSV)/*Xoa FIRST*/
{ 
   	if (SV_Empty(FIRSTSV))
    	return 0;
    LISTSV p;
    p = FIRSTSV;    // nut can xoa la nut dau
    FIRSTSV = p->next;
    QLSV.FIRST = FIRSTSV;
    delete p; 
    return 1;
}
int  SV_Delete_after(LISTSV p)/*Xoa sau 1 phan tu*/
{   
   	if((p == NULL) || (p->next == NULL))	
      return 0;
    LISTSV q;
    q = p->next;  // q chi nut can xoa
    p->next = q->next;
    if(p->next==NULL)
    	QLSV.LAST = p;
    delete q;
    return 1;
}
int SV_Delete_info(LISTSV &FIRSTSV,STUDENT x)/*Xoa SV theo info*/
{  
  	if (FIRSTSV==NULL ) return 0;
  	LISTSV p=FIRSTSV;
  	if (FIRSTSV->SV.MASV ==x.MASV ) {
     	p=FIRSTSV;
	 	FIRSTSV = p->next ;
	 	QLSV.FIRST = FIRSTSV;
	 	delete p ; return 1;
  	}
    
	for ( p=FIRSTSV; p->next!=NULL && p->next->SV.MASV != x.MASV; p=p->next) ;
	if (p->next!= NULL ) {
		LISTSV q=p->next; 
		p->next=q->next;
		if (p->next==NULL)
		QLSV.LAST = p;
		delete q; return 1;
	}
     return 0;
}
MAXCOT SV_NEWCOT()/*Dinh nghia cot DSSV*/
{
	MAXCOT NEWCOT;
	NEWCOT.SOLUONGCOT = 6;
	for(int i=0;i<NEWCOT.SOLUONGCOT;i++)
	{
		NEWCOT.INFOCOT[i] = new COT;
	}
	NEWCOT.INFOCOT[0]->WCOT = 5;
	NEWCOT.INFOCOT[0]->TENCOT = L"STT";
	NEWCOT.INFOCOT[1]->WCOT = 20;
	NEWCOT.INFOCOT[1]->TENCOT = L"Mã sinh viên";
	NEWCOT.INFOCOT[2]->WCOT = 40;
	NEWCOT.INFOCOT[2]->TENCOT = L"Họ";
	NEWCOT.INFOCOT[3]->WCOT = 23;
	NEWCOT.INFOCOT[3]->TENCOT = L"Tên";
	NEWCOT.INFOCOT[4]->WCOT = 14;
	NEWCOT.INFOCOT[4]->TENCOT = L"Phái";
	NEWCOT.INFOCOT[5]->WCOT = 15;
	NEWCOT.INFOCOT[5]->TENCOT = L"S\u0110T";
	
	return NEWCOT;
}
void SV_DRAWTABLENHAPSV(int sodong,char *TENLOP,int type)/*Ve bang nhap sinh vien*/
{

	MAXCOT NEWCOT = SV_NEWCOT();
	if (type == 1)
	{
	DRAWTABLE(2,NEWCOT);	
	}
	

	SV_PRINTINFO(sodong,NEWCOT,TENLOP,type);
}

int SV_Empty(LISTSV FIRSTSV)/*Kiem tra firstsv=NULL*/
{
   return(FIRSTSV == NULL);
}

void SV_Initialize(LISTSV &FIRSTSV)
{
   FIRSTSV = NULL;
}

void SV_Init()/*LOAD du lieu ban dau sinh vien*/
{
	if(!SV_Empty(FIRSTSV))
	SV_Clearlist(FIRSTSV);
	
	STUDENT SV_NEW;
	LISTLOP.SOLUONG = 0;
	ifstream loadlist;
	ifstream openlop;
	int soluongsinhvien = 0;
	loadlist.open(LISTDATA);
	if (!loadlist.is_open())
	{
		string DATA = "0";
		CREATFILE(str_2_char(LISTDATA),&DATA);
		TiengViet(L"File không t\u1ed3n tại");
		return;
	}
	loadlist>>LISTLOP.SOLUONG;
	
	for(int i=0;i<LISTLOP.SOLUONG;i++)/*Nhap danh sach lop*/
	{
		soluongsinhvien =0;
		char filename[50] = FOLDERDATA;
		loadlist>>LISTLOP.MALOP[i];
		strcat(filename,LISTLOP.MALOP[i]);
		openlop.open(filename);
		if(!openlop.is_open())
		{
			string DATA = "0";
			CREATFILE(filename,&DATA);
		}
		openlop>>soluongsinhvien;
		openlop.ignore(1);
		for(int j=0;j<soluongsinhvien;j++)/*Nhap danh sach sinhvien*/
		{
				
				getline(openlop,SV_NEW.MASV,'\t');
				getline(openlop,SV_NEW.pass,'\t');
				getline(openlop,SV_NEW.HO,'\t');
				getline(openlop,SV_NEW.TEN,'\t');
				getline(openlop, SV_NEW.PHAI,'\t');
				getline(openlop,SV_NEW.SDT,'\t');
				openlop.getline(SV_NEW.MALOP,50);
	
			if (FIRSTSV==NULL )
			{
				FIRSTSV = SV_Newnode();
				SV_Insert_First(FIRSTSV,SV_NEW);
			}else
			{
				SV_Insert_after(QLSV.LAST,SV_NEW);
			}
		}
		openlop.close();
		
	}
	loadlist.close();
	SV_SELECTION_SORT(FIRSTSV);
	
}

void SV_Insert_after(LISTSV p, STUDENT x)/*Them vao sau 1 phan tu*/
{
   if(x.MASV=="")return;
   if(p == NULL)
   {
   		Msg(L"Kh\u00F4ng th\u1EC3 th\u00EAm v\u00E0o danh s\u00E1ch",-1);

   }
	
   else
   {
   		LISTSV q;
   	 	q =new node;
      	q->SV = x;
     	q->next = p->next;
     	p->next = q;
      	QLSV.LAST=q;
   }
   
}
void SV_Insert_First(LISTSV &FIRSTSV, STUDENT x)/*Them vao FIRSTSV*/
{
	if(x.MASV=="")return;
   LISTSV p;
   p = new node;
   p->SV = x;
   p->next = NULL;
   FIRSTSV = p;
   	QLSV.FIRST=FIRSTSV;
	QLSV.LAST=FIRSTSV;

}
void LOP_BUBBLE_SORT(DSLOP LISTLOP)/*Sap xep DS LOP*/
{	
	if(LISTLOP.SOLUONG==0)return;
	int i,j;
	char temp[15];
	for (i=1; i<LISTLOP.SOLUONG; i++)
		for (j=LISTLOP.SOLUONG-1;j>=i; j--)
			if (strcmp(LISTLOP.MALOP[j-1],LISTLOP.MALOP[j])>0)
			{
				strcpy(temp,LISTLOP.MALOP[j-1]);
			
				strcpy(LISTLOP.MALOP[j-1],LISTLOP.MALOP[j]);
			
				strcpy(LISTLOP.MALOP[j],temp);
			
			}
}
void LOP_Insertion_sort(DSLOP LISTLOP)/*Sap xep DSLOP*/
{
	if(LISTLOP.SOLUONG==0)return;
	char x[15];
	int i,j;
	for (i=1; i< LISTLOP.SOLUONG; i++)
	{
		strcpy(x,LISTLOP.MALOP[i]);
		for (j=i-1; j>=0 && strcmp(x,LISTLOP.MALOP[j])<0; j--)
			strcpy(LISTLOP.MALOP[j+1],LISTLOP.MALOP[j]);
		strcpy(LISTLOP.MALOP[j+1],x);
	}

}
void SV_KHUNGEDITSV(MAXCOT NEWCOT,LISTSV p,int type)/*Ve khung chinh sua sinh vien*/
{
	if(p==NULL)
	{
		Msg(L"L\u1ED7i dữ li\u1EC7u sinh viên",-1);
		return;
	}	
	Color(COLORKHUNG);
	char firstchar,midchar,lastchar ;
	for(int i=0;i<EDITSVH;i++)
	{
		gotoxy(EDITSVX-EDITSVW/2,EDITSVY+i);
		if (i==0)
		{
			firstchar = char(topchar);
			midchar = char(topchar);
			lastchar = char(topchar);
		}
		else if(i==EDITSVH-1)
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
		for(int j=1;j<EDITSVW-1;j++)
		{
			cout << midchar;
		}
		cout << lastchar<<endl;
	
	}
	Color(COLORDEFAUL);
	gotoxy(EDITSVX-11,EDITSVY+2);
	Color(COLORTITLETEXT);
	if(type==0)
	TiengViet(L"  CH\u1EC8NH SỬA SINH VI\u00CAN  ");
	else
	TiengViet(L"  XEM TH\u00D4NG TIN SINH VI\u00CAN  ");
	Color(COLORDEFAUL);
	for(int i = 1;i<NEWCOT.SOLUONGCOT;i++)
	{
		if(i!=4)
		{
		
		gotoxy(EDITSVX-14,EDITSVY+1+4*i);
		cout<<char(218);for(int j=1;j<INPUTEDITW;j++)cout<<char(196);cout<<char(191);
		gotoxy(EDITSVX-15-wcslen(NEWCOT.INFOCOT[i]->TENCOT),EDITSVY+2+4*i);
		TiengViet(NEWCOT.INFOCOT[i]->TENCOT);
		cout << ' ';
		cout<<char(179);for(int j=1;j<INPUTEDITW;j++)cout<<' ';cout<<char(179);
		gotoxy(EDITSVX-14,EDITSVY+3+4*i);
		cout<<char(192);for(int j=1;j<INPUTEDITW;j++)cout<<char(196);cout<<char(217);
		gotoxy(EDITSVX-13,EDITSVY+2+4*i);
		}
		else
		{
			gotoxy(EDITSVX-15-wcslen(NEWCOT.INFOCOT[i]->TENCOT),EDITSVY+2+4*i);
			TiengViet(NEWCOT.INFOCOT[i]->TENCOT);
			cout <<"  "	;
		}
		if (i==1)
		{
			if(type!=0)
			Color(COLORDISABLE);
			cout<< p->SV.MASV;
			Color(COLORDEFAUL);
		}
		
		else if (i==2)
		{
			if(type!=0)
			Color(COLORDISABLE);
			cout<< p->SV.HO;
			Color(COLORDEFAUL);
		}
		
		else if (i==3)
		{
			if(type!=0)
			Color(COLORDISABLE);
			cout<< p->SV.TEN;
			Color(COLORDEFAUL);
		}
		
		else if (i==4)
		{
			if(p->SV.PHAI=="Nam")
			{
				Color(COLORSELECT);
				TiengViet(C_CHECKEDBOX);
				Color(COLORRDEFAUL);
				cout << " Nam ";
				Color(COLORDEFAUL);	
				for(int i =0;i<6;i++)cout << " ";
				TiengViet(C_UNCHECKBOX);
				TiengViet(L" Nữ ");
			}
			else
			{
				TiengViet(C_UNCHECKBOX);
				cout << " Nam ";
				for(int i =0;i<6;i++)cout << " ";
				Color(COLORSELECT);
				TiengViet(C_CHECKEDBOX);
				Color(COLORRDEFAUL);
				TiengViet(L" Nữ ");
				Color(COLORDEFAUL);	
			}
		}
		
		else if (i==5)
		{
			
			if(type!=0)
			Color(COLORDISABLE);
				if (p->SV.SDT=="-1")
				{
					TiengViet(L"Không");
				
				}else
				cout<< p->SV.SDT;
			Color(COLORDEFAUL);
			
			
		}
	}
}

LISTSV SV_Newnode(void)/*Tao node moi*/
{
	LISTSV p = new node;
	return p;
}
int SV_GETCOUNTSV(char *MALOP)/*Dem so sinh vien cua 1 ma lop*/
{
	if(strcmp(MALOP,"")==0) return 0;
	char filename[50] = FOLDERDATA ;
	strcat(filename,MALOP);
	int soluongsinhvien=0;
	ifstream file;
	file.open(filename);
	if(!file.is_open())return 0;
	file>>soluongsinhvien;
	file.close();
	
	return soluongsinhvien;

}
void LOP_SEARCH_ADD(int type)/*Nhap va Tim kiem Tenlop*/
{
	
	MsgSearch(L"Nh\u1EADp t\u00EAn l\u1EDBp c\u1EA7n t\u00ECm");
	char TENLOP[15];
	inCHUSO(TENLOP,'U',15);
	if (strcmp(TENLOP,"")==0)
	{
		Msg(L"Tên l\u1edbp không hợp l\u1ec7!",-1);
		return;
	}
	char filename[50] = FOLDERDATA ;
	strcat(filename,TENLOP);
	if (!LOP_SEARCH(TENLOP))
	{
		if(type == 1)
		{
		char option = MsgYN(L"L\u1edbp nh\u1EADp không t\u1ed3n tại,tạo m\u1edbi?");
			if (option == YES)
			{
				string DATA = "0";
				CREATFILE(filename,&DATA);
				LOP_CAPNHATDANHSACHLOP(TENLOP);
				Msg(L"Tạo l\u1edbp m\u1edbi thành công",1);
				LOP_RELOADLIST();
			}
			
			else if (option == NO)
			return;	
		}
		else
		{
			Msg(L"Tên l\u1edbp không t\u1ED3n tại!",-1);
			return;
		}

	}
	int soluongsinhvien=0;
	ifstream file;
	file.open(filename);
	if(!file.is_open())
	{
		string DATA = "0";
		CREATFILE(filename,&DATA);
	}
	file>>soluongsinhvien;
	file.close();
	if(type==4||type==5)
	{
		TK_PRINTINFO(soluongsinhvien,TENLOP,type);
	}
	else
	SV_DRAWTABLENHAPSV(soluongsinhvien,TENLOP,type);
	
}

void SV_PRINTINFODETAIL(int sodong,MAXCOT NEWCOT,char *Tenlop,LISTSV &p,int curentpage,int x,int y,int type)/*In chi tiet nhieu sinh vien*/
{
	if(p==NULL)return;
	DRAWTABLE(sodong,NEWCOT);
	if (sodong-1 > NUMLINETABLE)
		sodong = NUMLINETABLE +1;
	gotoxy(x,y);
	int currentx,currenty;
	int i=0;
		for (p;p!=NULL;p=p->next)
			{
			if(strcmp(p->SV.MALOP,Tenlop)==0)
				{
			
				gotoxy(x,y+i*2);
				if(strcmp(p->SV.MALOP,Tenlop)==0&&p!=NULL)
				{
					for (int j=0;j<NEWCOT.SOLUONGCOT;j++)
					{
					currentx=getX();
					currenty=getY();
			switch (j)
			{
			case 0:
				{
					gotoxy(getX()+2,getY());
					if(type==3)
					{
						if(i==0)
						{
						Color(COLORSELECT);
						TiengViet(SELECTPOITER);
						Color(COLORDEFAUL);	
						}

					}
					else if(type==DEFAULT)
					{
					}
					else if (type == PRINT)
					cout<< (curentpage-1)*NUMLINETABLE+i+1;
					gotoxy(getX()-2,getY());
				}
		
			break;
			case 1:
			cout<< p->SV.MASV;
			break;
			case 2:
			cout<< p->SV.HO;
			break;
			case 3:
			cout<< p->SV.TEN;
			break;
			case 4:
			cout<< p->SV.PHAI;
			break;
			case 5:
				if (p->SV.SDT=="-1")
				{
					TiengViet(L"Không");
				}
				else
				cout<< p->SV.SDT;
				break;
			
			}
			gotoxy(currentx+NEWCOT.INFOCOT[j]->WCOT+1,currenty);
	
			}
		}
		i++;
		if (p->next==NULL||i==sodong-1)break;
			
	}
	}/*end for*/
	gotoMenuEX();
}
LISTSV SV_SEARCH_POS_IN_CLASS(char *Tenlop,int edit)/*Tim Phan tu o vi tri trong lop*/
{
	LISTSV p;
	int i=1;
	for (p = FIRSTSV;  p  != NULL ; p=p->next ) 
	{
		if(i==edit&&strcmp(p->SV.MALOP,Tenlop)==0) return p;
		
		if (strcmp(p->SV.MALOP,Tenlop)==0) i++;
	}
    	
	return NULL;
	
}
void SV_PRINTINFO(int sodong,MAXCOT NEWCOT,char *Tenlop,int type)/*in thong tin sinh vien*/
{
	ClearDetailTable();
	gotoxy(90,4);
	TiengViet(L"Mã l\u1edbp: ");
	cout << Tenlop;
	gotoxy(85,6);
	TiengViet(L"S\u1ed1 sinh viên của l\u1edbp này là:");
	cout << sodong;
	if(FIRSTSV==NULL&&type!=1)
	{
		Msg(L"Không có sinh viên!",-1);
		return;
		
	}
	if(sodong==0&&type!=1) 
	{
		Msg(L"L\u1EDBp không có sinh viên!",-1);
		return;
	}
	int TOTALNUM = sodong;
	int MAXPAGE = (int)ceil((double)sodong/NUMLINETABLE);
	int curentpage = 1,cureditpage=1;
	int mod = sodong % NUMLINETABLE;
	gotoMenuFun();
	const int x=getX()+3,y = getY()+4+NUMLINETITLE;
	int currentx,currenty;
	gotoxy(x,y);
	switch (type)
	
	{
		case 1:/*Nhap sinh vien cau c*/
			{
				int EMP = SV_Empty(FIRSTSV);
				LISTSV CURENTP = QLSV.LAST;
				if(CURENTP==NULL&&!EMP)return;
				int i = 0,count = 0,edit=1,editold=0,moveedit=1;
				bool rep = true;
				while(rep)
				{
					gotoxy(131,y+i*2);
					Color(COLORSELECT);
					TiengViet(C_CHECKEDBOX);
					Color(COLORRDEFAUL);
					cout << " Nam ";
					Color(COLORDEFAUL);	
					cout << "   ";
					TiengViet(C_UNCHECKBOX);
					TiengViet(L" Nữ ");
					if (count >=(curentpage)*NUMLINETABLE)
					{
						i = 0;
						curentpage++;
						ClearMenuFunTABLE();
						DRAWTABLE(2,NEWCOT);
						gotoxy(x,y);
					}
					STUDENT SV_NEW;
					char MSSV[15]="",HO[40]="",TEN[20]="",PHAI[3]="",SDT[11]="";
					gotoxy(x,y+i*2);
					for (int j=0;j<NEWCOT.SOLUONGCOT;j++)
					{
						currentx=getX();
						currenty=getY();
						switch (j)
						{
							case 0:
							cout<< (curentpage-1)*NUMLINETABLE+i+1;
							break;
							case 1:
							{
			
								int curX=getX(),curY=getY(),nX;
								inCHUSO(MSSV,'U',15);
								
								nX=getX();
			
								while(SV_SEARCH_INFO_MSSV(QLSV.FIRST,(string)MSSV)!=NULL&&strcmp(MSSV,"")!=0)
								{
									gotoxy(curX,curY);
									for(int nI=curX;nI<=nX;nI++)
									{
										cout << " ";
									}
									gotoxy(curX,curY);
									Msg(L"Mã sinh viên \u0111ã t\u1ed3n tại!",-1);
									
									gotoxy(curX,curY);
									strcpy(MSSV,"");
									inCHUSO(MSSV,'U',15);
									nX=getX();
								}
			
								SV_NEW.MASV =(string) MSSV;
								if (strcmp(MSSV,"")==0)
								{
									if (count !=0)
									{
										char option = MsgYN(L"B\u1ea1n có mu\u1ed1n s\u1EEDa SV v\u1eeba nh\u1eadp?");
										if (option==YES)
										{
											LISTSV p;
											if(EMP) p = FIRSTSV;
											else
											p = CURENTP->next;
											if (p==NULL) return;
											MAXPAGE = (int)ceil((double)count/NUMLINETABLE);
											mod = count % NUMLINETABLE;
											SV_PRINTINFODETAIL(count+1,NEWCOT,Tenlop,p,1,x,y,3);
											while(true)
											{
												int select = getch();
												if (select == 224)
												{
													int select_val = getch();
		
													if (select_val==UP)
													{
														if (edit>1)
														{
															edit--;
															editold = 1;
														}else continue;
														if (edit %NUMLINETABLE==0 )
														{
															cureditpage--;sodong = NUMLINETABLE;
															if(EMP) p = FIRSTSV;
															else
																p = CURENTP->next;
															if (p==NULL) return;
															if (cureditpage!= 1)
															{
																for(int w=0;w<NUMLINETABLE*(cureditpage-1);w++)
																p=p->next;
															}
															if (p==NULL) return;
															SV_PRINTINFODETAIL(NUMLINETABLE+1,NEWCOT,Tenlop,p,cureditpage,x,y,DEFAULT);
														}
														gotoxy(x+2,y+((edit-1)%NUMLINETABLE+editold)*2);
														cout << " ";
														gotoxy(x+2,y+((edit-1)%NUMLINETABLE)*2);
														Color(COLORSELECT);
														TiengViet(SELECTPOITER);
														Color(COLORDEFAUL);	gotoMenuEX();
													}
													else if (select_val==DOWN)
													{
														if (edit<count)
														{
															edit++;
															editold = -1;
														}else continue;
														if (edit %NUMLINETABLE==1 )
														{
															if (edit >NUMLINETABLE)
															{
																cureditpage++;
																editold=0;
															}
				
															if(cureditpage < MAXPAGE||mod==0)
															{
																sodong = NUMLINETABLE;
															}else
															{															
																sodong = mod;
															}
			
															p=p->next;
															if (p==NULL) return;
															SV_PRINTINFODETAIL(sodong+1,NEWCOT,Tenlop,p,curentpage,x,y,3);
														}
														gotoxy(x+2,y+((edit-1)%NUMLINETABLE+editold)*2);
														cout << " ";
														gotoxy(x+2,y+((edit-1)%NUMLINETABLE)*2);
														Color(COLORSELECT);
														TiengViet(SELECTPOITER);
														Color(COLORDEFAUL);	gotoMenuEX();
													}
													else if (select_val==DEL)/*Xoa phan tu*/
													{
														option = MsgYN(L"B\u1ea1n có mu\u1ed1n xóa SV này?");
														if (option == YES)
														{
															if(EMP) p = FIRSTSV;
															else
															p = CURENTP->next;
															if (p==NULL) return;
															for(int w=0;w<edit-1;w++)
															p=p->next;
															if (p==NULL) return;
															if(SV_Delete_info(FIRSTSV,p->SV))
															{
																Msg(L"Xóa thành công!!",1);
																count--;
																if(edit>1)
																{
																	edit--;	editold=1;
																}
															
																if(edit%NUMLINETABLE==0&&cureditpage>1)cureditpage--;
																
															}
															else
															{
																Msg(L"Xóa thất bại!!",-1);
															}
														
														}
														if(EMP) p = FIRSTSV;
														else
														p = CURENTP->next;
														if (p==NULL) return;
														if(cureditpage>1)
														for(int s=0;s<(cureditpage-1)*NUMLINETABLE;s++)
														p=p->next;
														if (p==NULL) return;
														MAXPAGE = (int)ceil((double)count/NUMLINETABLE);
														mod = count % NUMLINETABLE;
														if (cureditpage < MAXPAGE||mod==0)
														sodong = NUMLINETABLE;
														else
														sodong = mod;
														SV_PRINTINFODETAIL(sodong+1,NEWCOT,Tenlop,p,1,x,y,DEFAULT);
														gotoxy(x+2,y+((edit-1)%NUMLINETABLE+editold)*2);
														cout << " ";
														gotoxy(x+2,y+((edit-1)%NUMLINETABLE)*2);
														Color(COLORSELECT);
														TiengViet(SELECTPOITER);
														Color(COLORDEFAUL);	gotoMenuEX();
													}	
												}
												else if (select==F2)/*chinh sua 1 sinh vien*/
												{		
													int flag[5]={0,0,0,0,0};
													strcpy(MSSV,"");strcpy(HO,"");strcpy(TEN,"");strcpy(PHAI,"");strcpy(SDT,"");
													moveedit = 1;
													if(EMP) p = FIRSTSV;
													else
													p = CURENTP->next;
													if (p==NULL) return;
													for(int w=0;w<edit-1;w++)
													p=p->next;
													if (p==NULL) return;
													SV_KHUNGEDITSV(NEWCOT,p);
													gotoxy(EDITSVX-13,EDITSVY+6);
													int curX=getX(),curY=getY();
													while(true)
													{
														int select1 = getch(),select_val1;
														if (select1 == 224)
														{
															select_val1=getch();
															if(select_val1==UP)
															{
																if (moveedit >1)
																{
																	moveedit --;
																}else continue;
																gotoxy(EDITSVX-13,EDITSVY+2+moveedit*4);
																curX=getX();curY=getY();
															}
															else if(select_val1==DOWN)
															{
																if (moveedit <5)
																{
																	moveedit ++;
																}else continue;
																gotoxy(EDITSVX-13,EDITSVY+2+moveedit*4);
																curX=getX();curY=getY();
															}
														}
														else if(select1==ENTER||select1 == BACKSPACE)
														{
															for(int nI=0;nI<39;nI++)cout<<" ";
															gotoxy(EDITSVX-13,EDITSVY+2+moveedit*4);

															if (moveedit==1)
															{
																inCHUSO(MSSV,'U',15);
																while(SV_SEARCH_INFO_MSSV_EX(QLSV.FIRST,(string)MSSV,p)!=NULL||strcmp(MSSV,"")==0)
																{
																	gotoxy(curX,curY);
																	for(int nI=0;nI<15;nI++)cout<<" ";
																	gotoxy(curX,curY);
																	if (SV_SEARCH_INFO_MSSV_EX(QLSV.FIRST,(string)MSSV,p)!=NULL)
																	Msg(L"Mã sinh viên \u0111ã t\u1ed3n tại!",-1);
																	else if(strcmp(MSSV,"")==0)
																	Msg(L"Mã sinh viên không th\u1EC3 tr\u1ED1ng!",-1);
																	gotoxy(curX,curY);
																	strcpy(MSSV,"");
																	inCHUSO(MSSV,'U',15);
																}
																
															}
															else if(moveedit==2)
															{
																inName(HO,40);
																while(strcmp(HO,"")==0)
																{
																
																Msg(L"Họ không th\u1ec3 \u0111\u1ec3 tr\u1ed1ng!",-1);
																
																
																gotoxy(curX,curY);
																inName(HO,40);
																}
																
															}
															else if(moveedit==3)
															{
																inName(TEN,20);
																while(strcmp(TEN,"")==0)
																{
																	
																	Msg(L"Tên không th\u1ec3 \u0111\u1ec3 tr\u1ed1ng!",-1);
																	
																	
																	gotoxy(curX,curY);
																	inName(TEN,20);
																}
															}
															else if(moveedit==4)
															{
																
																char Gender = MsgGender(3);
																if (Gender == MALE)
																{
																	strcpy(PHAI,"Nam");
																}
																else
																strcpy(PHAI,"Nu");	
															}
															else if(moveedit==5)
															{
																inNumSTR(SDT,11);
																if (strcmp(SDT,"")==0)
																strcpy(SDT,"-1");
															
															}
															flag[moveedit-1]=1;
															gotoxy(curX,curY);
														}
														else if(select1==F4)
														{
															if(EMP) p = FIRSTSV;
															else
															p = CURENTP->next;
															if (p==NULL) return;
															for(int w=0;w<edit-1;w++)
															p=p->next;
															if (p==NULL) return;
															option = MsgYN(L"B\u1ea1n có mu\u1ed1n lưu SV v\u1eeba sửa?");
															if (option==YES)
															{
																if (flag[0]==1)
																p->SV.MASV = (string)MSSV;
																if(flag[1]==1)
																p->SV.HO = (string) HO;
																if(flag[2]==1)
																p->SV.TEN = (string) TEN;
																if(flag[3]==1)
																p->SV.PHAI = (string) PHAI;
																if(flag[4]==1)
																p->SV.SDT = (string) SDT;
															}
															break;
														}
														else if(select1==ESC) break;
													}
													if(EMP) p = FIRSTSV;
													else
														p = CURENTP->next;
													if (p==NULL) return;
													if(cureditpage>1)
													for(int s=0;s<(cureditpage-1)*NUMLINETABLE;s++)
													p=p->next;
													if (p==NULL) return;
													MAXPAGE = (int)ceil((double)count/NUMLINETABLE);
													mod = count % NUMLINETABLE;
													if (cureditpage < MAXPAGE||mod==0)
													sodong = NUMLINETABLE;
													else
													sodong = mod;
													SV_PRINTINFODETAIL(sodong+1,NEWCOT,Tenlop,p,1,x,y,DEFAULT);
													gotoxy(x+2,y+((edit-1)%NUMLINETABLE+editold)*2);
													cout << " ";
													gotoxy(x+2,y+((edit-1)%NUMLINETABLE)*2);
													Color(COLORSELECT);
													TiengViet(SELECTPOITER);
													Color(COLORDEFAUL);	gotoMenuEX();
												}
												else if (select==F4||select==ESC)/*Luu*/
												{
													break;
												}
	
											}
										}
										option = MsgYN(L"B\u1ea1n có mu\u1ed1n lưu SV v\u1eeba nh\u1eadp?");
										if (option==YES)
										{
											SV_SAVEFILE(Tenlop);
											Msg(L"L\u01B0u sinh vi\u00EAn th\u00E0nh c\u00F4ng!!",1);
										}	
										SV_SELECTION_SORT(FIRSTSV);
									}
									Msg(L"Thoát nhập sinh viên!",1);
					
									rep = false;
								}

							}break;
							case 2:
							{
								int curX=getX(),curY=getY();
								inName(HO,40);
								while(strcmp(HO,"")==0)
								{
									Msg(L"Họ không th\u1ec3 \u0111\u1ec3 tr\u1ed1ng!",-1);
									gotoxy(curX,curY);
									inName(HO,40);
								}
				
								SV_NEW.HO =(string) HO;
							}break;
							case 3:
							{
								int curX=getX(),curY=getY();
								inName(TEN,20);
								while(strcmp(TEN,"")==0)
								{

									Msg(L"Tên không th\u1ec3 \u0111\u1ec3 tr\u1ed1ng!",-1);
									gotoxy(curX,curY);
									inName(TEN,20);
								}
								SV_NEW.TEN =(string) TEN;
							}break;
							case 4:
							{
								int curX=getX(),curY=getY();
								char Gender = MsgGender();
								if (Gender == MALE)
								{
									SV_NEW.PHAI = "Nam";
								}
								else
								SV_NEW.PHAI = "Nu";
			
								
							}break;
							case 5:
							{
								inNumSTR(SDT,11);
								if (strcmp(SDT,"")==0)
								strcpy(SDT,"-1");
								SV_NEW.SDT = (string)SDT;	
							}break;
			
						}
						if (rep==false)
						{
							break;	
						}
						else
						{
							gotoxy(currentx+NEWCOT.INFOCOT[j]->WCOT+1,currenty);
							DRAWINSERTTABLE(x-1,getY(),NEWCOT);
							
							gotoxy(currentx+NEWCOT.INFOCOT[j]->WCOT+1,currenty);
						}
				
					}/*end for*/
					strcpy(SV_NEW.MALOP,Tenlop);
						if(SV_Empty(FIRSTSV))SV_Insert_First(FIRSTSV,SV_NEW);
						else
						SV_Insert_after(QLSV.LAST, SV_NEW);
						i++;
						count++;
				}/*endwhile*/
			}break;
		case 2:/*in sinh vien cau d*/
			{
				LISTSV p = FIRSTSV;
				if (p==NULL) return;
		//---------
				SV_PRINTINFODETAIL(sodong+1,NEWCOT,Tenlop,p,curentpage,x,y);
				while (true)
				{
					

		
					int swpage = getch();
					if(swpage == 224)
					{
						int swpage_val = getch();
						if (swpage_val == PAGEDOWN)/*pagedown*/
						{
							if (curentpage< MAXPAGE)
							{	
	
							curentpage++;
							}
							else continue;
							if (curentpage == MAXPAGE)
							{
								if (mod!=0)
								sodong = mod;
							}
							else
							{
								sodong = NUMLINETABLE;
							}
							p=p->next;
							if (p==NULL) return;
							SV_PRINTINFODETAIL(sodong+1,NEWCOT,Tenlop,p,curentpage,x,y);
						}
						else if(swpage_val == PAGEUP)/*down*/
						{
	
				
							if (curentpage>1)
							{	
	
								curentpage--;
							}
							else continue;
							sodong = NUMLINETABLE;
							p = SV_SEARCH_POS_IN_CLASS(Tenlop,(curentpage-1)*NUMLINETABLE+1);
							if (p==NULL) return;
						

							if (curentpage == MAXPAGE)
							{
								if (mod!=0)
								sodong = mod;
							}
							else
							{
								sodong = NUMLINETABLE;
							}
							SV_PRINTINFODETAIL(sodong+1,NEWCOT,Tenlop,p,curentpage,x,y);
						}
				

					}
					else
					{
			
						if ((char) swpage == ESC)
						{

							break;
						}
	      
					}

				}/*end while*/
			}break;/*end case2*/
		case 3:/*Sua va xoa sinh vien cau d2,d3*/
			{
				int edit=1,editold=0,moveedit=1;
				LISTSV p = FIRSTSV;
				if (p==NULL) return;
				SV_PRINTINFODETAIL(sodong+1,NEWCOT,Tenlop,p,1,x,y,3);
				while(true)
				{
					int select = getch();
					if (select == 224)
					{
						int select_val = getch();
		
						if (select_val==UP)
						{
							if (edit>1)
							{
								edit--;
								editold = 1;
							}else continue;
							if (edit %NUMLINETABLE==0 )
							{
								
								cureditpage--;sodong = NUMLINETABLE;
								p = SV_SEARCH_POS_IN_CLASS(Tenlop,(cureditpage-1)*NUMLINETABLE+1);
								if (p==NULL) return;
								SV_PRINTINFODETAIL(NUMLINETABLE+1,NEWCOT,Tenlop,p,cureditpage,x,y,DEFAULT);
							}
							gotoxy(x+2,y+((edit-1)%NUMLINETABLE+editold)*2);
							cout << " ";
							gotoxy(x+2,y+((edit-1)%NUMLINETABLE)*2);
							Color(COLORSELECT);
							TiengViet(SELECTPOITER);
							Color(COLORDEFAUL);	gotoMenuEX();

						}
						else if (select_val==DOWN)
						{
							if (edit<TOTALNUM)
							{
								edit++;
								editold = -1;
							}else continue;
							if (edit %NUMLINETABLE==1 )
							{
								if (edit >NUMLINETABLE)
								{
									cureditpage++;editold=0;
								}
								
								if(cureditpage < MAXPAGE)
								{
									sodong = NUMLINETABLE;
								}else
								{
									if (mod!=0)
									sodong = mod;
								}
							
								p=p->next;
								if (p==NULL) return;
								SV_PRINTINFODETAIL(sodong+1,NEWCOT,Tenlop,p,curentpage,x,y,3);
							}
							gotoxy(x+2,y+((edit-1)%NUMLINETABLE+editold)*2);
							cout << " ";
							gotoxy(x+2,y+((edit-1)%NUMLINETABLE)*2);
							Color(COLORSELECT);
							TiengViet(SELECTPOITER);
							Color(COLORDEFAUL);	gotoMenuEX();
						}
						else if (select_val==DEL)/*Xoa phan tu*/
						{
							char option = MsgYN(L"B\u1ea1n có mu\u1ed1n xóa SV này?");
							if (option == YES)
							{
								p = SV_SEARCH_POS_IN_CLASS(Tenlop,edit);
								if (p==NULL) return;
							
								if(SV_Delete_info(FIRSTSV,p->SV))
								{
									Msg(L"Xóa thành công!!",1);
									TOTALNUM--;
									for(int s=0;s<LISTTC.SOLUONG;s++)
									{
									if(DK_DELETE_INFO_MSSV(LISTTC.LOP[s]->SV,p->SV.MASV));
									
									}
									if(edit>1){
											edit--;editold = 1;
									}
								
									if(edit%NUMLINETABLE==0&&cureditpage>1)cureditpage--; 
									
									SV_SAVEFILE(Tenlop);
									TC_RESAVEDK();
									Msg(L"L\u01B0u sinh vi\u00EAn th\u00E0nh c\u00F4ng!!",1);
								}
								else
								{
									Msg(L"Xóa thất bại!!",-1);
								}
			
							}
							p = SV_SEARCH_POS_IN_CLASS(Tenlop,(cureditpage-1)*NUMLINETABLE+1);
							if (p==NULL) {
								SV_SAVEFILE(Tenlop);
								TC_RESAVEDK();
								
								break;	
							}
							MAXPAGE = (int)ceil((double)TOTALNUM/NUMLINETABLE);
							mod = TOTALNUM % NUMLINETABLE;
							if (cureditpage < MAXPAGE||mod==0)
							sodong = NUMLINETABLE;
							else
							sodong = mod;
							SV_PRINTINFODETAIL(sodong+1,NEWCOT,Tenlop,p,1,x,y,DEFAULT);
							gotoxy(x+2,y+((edit-1)%NUMLINETABLE+editold)*2);
							cout << " ";
							gotoxy(x+2,y+((edit-1)%NUMLINETABLE)*2);
							Color(COLORSELECT);
							TiengViet(SELECTPOITER);
							Color(COLORDEFAUL);	gotoMenuEX();
						}
					}
					else if (select==F3)/*tim kiem 1 sinh vien*/
					{
						SV_SEARCH();
						p = SV_SEARCH_POS_IN_CLASS(Tenlop,(cureditpage-1)*NUMLINETABLE+1);
						TOTALNUM = SV_GETCOUNTSV(Tenlop);
						if (p==NULL) return;
						MAXPAGE = (int)ceil((double)TOTALNUM/NUMLINETABLE);
						mod = TOTALNUM % NUMLINETABLE;
						if (cureditpage < MAXPAGE||mod ==0)
						sodong = NUMLINETABLE;
						else
						sodong = mod;
						SV_PRINTINFODETAIL(sodong+1,NEWCOT,Tenlop,p,1,x,y,DEFAULT);
						gotoxy(x+2,y+((edit-1)%NUMLINETABLE+editold)*2);
						cout << " ";
						gotoxy(x+2,y+((edit-1)%NUMLINETABLE)*2);
						Color(COLORSELECT);
						TiengViet(SELECTPOITER);
						Color(COLORDEFAUL);	gotoMenuEX();
						
					}
					else if (select==F2)/*chinh sua 1 sinh vien*/
					{		
						char MSSV[15]="",HO[40]="",TEN[20]="",PHAI[3]="",SDT[11]="";
						int flag[5]={0,0,0,0,0};
						
						moveedit = 1;
						p = SV_SEARCH_POS_IN_CLASS(Tenlop,edit);
						string oldMSSV = p->SV.MASV;
						if (p==NULL) return;
						SV_KHUNGEDITSV(NEWCOT,p);
						gotoxy(EDITSVX-13,EDITSVY+6);
						int curX=getX(),curY=getY();
						while(true)
						{
							int select1 = getch(),select_val1;
							if (select1 == 224)
							{
								select_val1=getch();
								if(select_val1==UP)
								{
									if (moveedit >1)
									{
										moveedit --;
									}else continue;
									
									gotoxy(EDITSVX-13,EDITSVY+2+moveedit*4);
									curX=getX();curY=getY();
								}
								else if(select_val1==DOWN)
								{
									if (moveedit <5)
									{
										moveedit ++;
									}else continue;
								
									gotoxy(EDITSVX-13,EDITSVY+2+moveedit*4);
									curX=getX();curY=getY();
								}

							}
							else if(select1==ENTER||select1== BACKSPACE)
							{
								for(int nI=0;nI<39;nI++)cout<<" ";
								gotoxy(EDITSVX-13,EDITSVY+2+moveedit*4);

								if (moveedit==1)
								{
									inCHUSO(MSSV,'U',15);
									while(SV_SEARCH_INFO_MSSV_EX(QLSV.FIRST,(string)MSSV,p)!=NULL||strcmp(MSSV,"")==0)
									{
										gotoxy(curX,curY);
										for(int nI=0;nI<15;nI++)cout<<" ";
										gotoxy(curX,curY);
										if (SV_SEARCH_INFO_MSSV_EX(QLSV.FIRST,(string)MSSV,p)!=NULL)
										Msg(L"Mã sinh viên \u0111ã t\u1ed3n tại!",-1);
										else if(strcmp(MSSV,"")==0)
										Msg(L"Mã sinh viên không th\u1EC3 tr\u1ED1ng!",-1);
										
										
										gotoxy(curX,curY);
										
										strcpy(MSSV,"");
										inCHUSO(MSSV,'U',15);
									}
	
								}
								else if(moveedit==2)
								{
									inName(HO,40);
									while(strcmp(HO,"")==0)
									{
									
									Msg(L"Họ không th\u1ec3 \u0111\u1ec3 tr\u1ed1ng!",-1);
									
									
									gotoxy(curX,curY);
									inName(HO,40);
									}
	
								}
								else if(moveedit==3)
								{
									inName(TEN,20);
									while(strcmp(TEN,"")==0)
									{
										
										Msg(L"Tên không th\u1ec3 \u0111\u1ec3 tr\u1ed1ng!",-1);
										
										
										gotoxy(curX,curY);
										inName(TEN,20);
									}
								}
								else if(moveedit==4)
								{
									
									char Gender = MsgGender(3);
									if (Gender == MALE)
									{
										strcpy(PHAI,"Nam");
									}
									else
									 strcpy(PHAI,"Nu");
								}
								else if(moveedit==5)
								{
									inNumSTR(SDT,11);
									if (strcmp(SDT,"")==0)
									strcpy(SDT,"-1");
								
								}
								flag[moveedit-1]=1;
								
								gotoxy(curX,curY);
							}
							else if(select1==F4)
							{
								p = SV_SEARCH_POS_IN_CLASS(Tenlop,edit);if (p==NULL) return;
								char option = MsgYN(L"B\u1ea1n có mu\u1ed1n lưu SV v\u1eeba sửa?");
								if (option==YES)
								{
									if (flag[0]==1)
									{
										p->SV.MASV = (string)MSSV;
										for(int s=0;s<LISTTC.SOLUONG;s++)
										{
											DK_CHANGEINFO(LISTTC.LOP[s]->SV,oldMSSV,p->SV.MASV);
									
										}	
									}
									
									if(flag[1]==1)
									p->SV.HO = (string) HO;
									if(flag[2]==1)
									p->SV.TEN = (string) TEN;
									if(flag[3]==1)
									p->SV.PHAI = (string) PHAI;
									if(flag[4]==1)
									p->SV.SDT = (string) SDT;
									SV_SAVEFILE(Tenlop);
									TC_RESAVEDK();
									Msg(L"L\u01B0u sinh vi\u00EAn th\u00E0nh c\u00F4ng!!",1);
								}
								break;
							}else if(select1==ESC) break;
						}
						p = SV_SEARCH_POS_IN_CLASS(Tenlop,(cureditpage-1)*NUMLINETABLE+1);
						if (p==NULL) return;
						MAXPAGE = (int)ceil((double)TOTALNUM/NUMLINETABLE);
						mod = TOTALNUM % NUMLINETABLE;
						if (cureditpage < MAXPAGE||mod ==0)
						sodong = NUMLINETABLE;
						else
						sodong = mod;
						SV_PRINTINFODETAIL(sodong+1,NEWCOT,Tenlop,p,1,x,y,DEFAULT);
						gotoxy(x+2,y+((edit-1)%NUMLINETABLE+editold)*2);
						cout << " ";
						gotoxy(x+2,y+((edit-1)%NUMLINETABLE)*2);
						Color(COLORSELECT);
						TiengViet(SELECTPOITER);
						Color(COLORDEFAUL);	gotoMenuEX();
					}
					else if (select==F4)/*Luu*/
					{
						char option = MsgYN(L"B\u1ea1n có mu\u1ed1n lưu những thay \u0111\u1ED5i?");
						if (option==YES)
						{
							SV_SAVEFILE(Tenlop);
							TC_RESAVEDK();
							Msg(L"L\u01B0u sinh vi\u00EAn th\u00E0nh c\u00F4ng!!",1);
						}	
						
					
						Msg(L"Thoát sửa sinh viên!",1);
						break;
					}
					else if(select==ESC) 
					{
					
					break;	
					}
	
				}
			}break;
	
	}/*end switch*/
}
void LOP_PRINTINFODETAIL(int sodong,int *p,int curentpage,int x,int y,int type)/*In chi tiet danh sach lop*/
{
	DRAWTABLE(sodong,LOP_NEWCOT());
	if (sodong-1 > NUMLINETABLE)
		sodong = NUMLINETABLE +1;
	gotoxy(x,y);
	int currentx,currenty;
		for (int i=0;i<sodong-1;i++)
			{

			
				gotoxy(x,y+i*2);
				if(*p<LISTLOP.SOLUONG)
				{
					for (int j=0;j<LOP_NEWCOT().SOLUONGCOT;j++)
					{
					currentx=getX();
					currenty=getY();
					switch (j)
					{
						case 0:
						{
							gotoxy(getX()+2,getY());
					
							if(type==3)
							{
								if(i==0)
								{
								Color(COLORSELECT);
								TiengViet(SELECTPOITER);
								Color(COLORDEFAUL);	
								}

							}
							else if(type==DEFAULT)
							{
							}else if (type == PRINT)
							cout<< (curentpage-1)*NUMLINETABLE+i+1;
							gotoxy(getX()-2,getY());
						}
		
						break;
						case 1:
						cout<< LISTLOP.MALOP[*p];
						break;
						case 2:
						cout<< SV_GETCOUNTSV(LISTLOP.MALOP[*p]);
						break;
						

			
					}
					gotoxy(currentx+LOP_NEWCOT().INFOCOT[j]->WCOT+1,currenty);
			
				}
			}
			(*p)++;
			
			
			
	}/*end for*/gotoMenuEX();
}
void LOP_PRINTINFO(int type)/*in danh sach lop*/
{
	ClearDetailTable();
	int sodong = LISTLOP.SOLUONG;
	int TOTALNUM = sodong;
	if(sodong==0&&type!=1) 
	{
		Msg(L"Không có l\u1EDBp trong d\u1EEF li\u1EC7u!",-1);
		return;
	}
	else if(LISTLOP.SOLUONG==0&&type==1)
	{
		LOP_SEARCH_ADD(type);	
		sodong=LISTLOP.SOLUONG;
	}
	int MAXPAGE = (int)ceil((double)sodong/NUMLINETABLE);
	int curentpage = 1,cureditpage=1;
	int mod = sodong % NUMLINETABLE;
	gotoMenuFun();
	const int x=getX()+3,y = getY()+4+NUMLINETITLE;
	int currentx,currenty;
	gotoxy(x,y);

	int edit=1,editold=0,moveedit=1;
	int p = 0;
	
	
	
					
	LOP_PRINTINFODETAIL(sodong+1,&p,cureditpage,x,y,3);
	int select ;
	while(true)
	{
		select = getch();
		if (select == 224)
		{
			int select_val = getch();
		
			if (select_val==UP)
			{
	
				if (edit>1)
				{
					edit--;
					editold = 1;
				}else continue;
				if (edit %NUMLINETABLE==0 )
				{
				
					cureditpage--;sodong = NUMLINETABLE;
					p = 0;
					if (LISTLOP.SOLUONG==0) return;
					if (cureditpage!= 1)
					{

						for(p=0;p<(cureditpage-1)*NUMLINETABLE;p++);
					}
					if (LISTLOP.SOLUONG==0) return;
					LOP_PRINTINFODETAIL(sodong+1,&p,cureditpage,x,y,DEFAULT);
				}
				gotoxy(x+2,y+((edit-1)%NUMLINETABLE+editold)*2);
				cout << " ";
				gotoxy(x+2,y+((edit-1)%NUMLINETABLE)*2);
				Color(COLORSELECT);
				TiengViet(SELECTPOITER);
				Color(COLORDEFAUL);	gotoMenuEX();
			}
			else if (select_val==DOWN)
			{
			
				if (edit<TOTALNUM)
				{
					edit++;
					editold = -1;
				}else continue;
				if (edit %NUMLINETABLE==1 )
				{
					if (edit > NUMLINETABLE)
					{
					cureditpage++;editold=0;	
					}
					if(cureditpage < MAXPAGE)
					{
						sodong = NUMLINETABLE;
					}else
					{
						if (mod!=0)
						sodong = mod;
					}
			

					if (LISTLOP.SOLUONG==0) return;
				
					LOP_PRINTINFODETAIL(sodong+1,&p,cureditpage,x,y,3);
				}
				gotoxy(x+2,y+((edit-1)%NUMLINETABLE+editold)*2);
				cout << " ";
				gotoxy(x+2,y+((edit-1)%NUMLINETABLE)*2);
				Color(COLORSELECT);
				TiengViet(SELECTPOITER);
				Color(COLORDEFAUL);	gotoMenuEX();
			}

		
		
		}
		else if (select==F3)
		{
			LOP_SEARCH_ADD(type);
			p = 0;
			if (LISTLOP.SOLUONG==0) return;
			TOTALNUM = LISTLOP.SOLUONG;
			MAXPAGE = (int)ceil((double)TOTALNUM/NUMLINETABLE);
			mod = TOTALNUM % NUMLINETABLE;
			if(cureditpage>1)
			for(p=0;p<(cureditpage-1)*NUMLINETABLE;p++);
			if (cureditpage < MAXPAGE||mod==0)
			sodong = NUMLINETABLE;
			else
			sodong = mod;
			LOP_PRINTINFODETAIL(sodong+1,&p,cureditpage,x,y,DEFAULT);
			gotoxy(x+2,y+((edit-1)%NUMLINETABLE+editold)*2);
			cout << " ";
			gotoxy(x+2,y+((edit-1)%NUMLINETABLE)*2);
			Color(COLORSELECT);
			TiengViet(SELECTPOITER);
			Color(COLORDEFAUL);	gotoMenuEX();
		}
		else if (select==ENTER)/*In danh sach*/
		{
			p = 0;
			if (LISTLOP.SOLUONG==0) return;
			for(p=0;p<edit-1;p++);

			
			if (type==4)
			TK_PRINTINFO(SV_GETCOUNTSV(LISTLOP.MALOP[p]),LISTLOP.MALOP[p],type);
			else if(type==5)
			TK_PRINTINFO(SV_GETCOUNTSV(LISTLOP.MALOP[p]),LISTLOP.MALOP[p],type);
			else
			SV_DRAWTABLENHAPSV(SV_GETCOUNTSV(LISTLOP.MALOP[p]),LISTLOP.MALOP[p],type);
			ClearDetailTable();
			p = 0;
			if (LISTLOP.SOLUONG==0) return;
			MAXPAGE = (int)ceil((double)TOTALNUM/NUMLINETABLE);
			mod = TOTALNUM % NUMLINETABLE;
			if(cureditpage>1)
			for(p=0;p<(cureditpage-1)*NUMLINETABLE;p++);
			if (cureditpage < MAXPAGE||mod==0)
			sodong = NUMLINETABLE;
			else
			sodong = mod;
			LOP_PRINTINFODETAIL(sodong+1,&p,cureditpage,x,y,DEFAULT);
			gotoxy(x+2,y+((edit-1)%NUMLINETABLE+editold)*2);
			cout << " ";
			gotoxy(x+2,y+((edit-1)%NUMLINETABLE)*2);
			Color(COLORSELECT);
			TiengViet(SELECTPOITER);
			Color(COLORDEFAUL);	gotoMenuEX();
		}
		else if(select==ESC) break;
			
	}
	
}


void LOP_RELOADLIST()/*Load lai danh sach lop*/
{
	LISTLOP.SOLUONG = 0;
	ifstream loadlist;
	loadlist.open(LISTDATA);
	if (!loadlist.is_open())
	{
		string DATA = "0";
		CREATFILE(str_2_char(LISTDATA),&DATA);
		TiengViet(L"File không t\u1ed3n tại");
		return;
	}
	loadlist>>LISTLOP.SOLUONG;
	
	for(int i=0;i<LISTLOP.SOLUONG;i++)/*Nhap danh sach lop*/
	{
		loadlist>>LISTLOP.MALOP[i];
				
	}
	loadlist.close();
	
}
void SV_SEARCH()/*tim kiem sinh vien theo MSSV*/
{
	MsgSearch(L"Nh\u1EADp m\u00E3 sinh vi\u00EAn c\u1EA7n t\u00ECm");
	char MSSV[15]="";
	inCHUSO(MSSV,'U',15);
	LISTSV p = NULL;
	p = SV_SEARCH_INFO_MSSV(FIRSTSV,(string)MSSV);
	while(p == NULL)
	{
		if(strcmp(MSSV,"")==0)
		{
			Msg(L"Tho\u00E1t t\u00ECm ki\u1EBFm!",1);
			return;
		}
		Msg(L"M\u00E3 sinh vi\u00EAn kh\u00F4ng t\u1ED3n t\u1EA1i!",-1);
		MsgSearch(L"Nh\u1EADp m\u00E3 sinh vi\u00EAn c\u1EA7n t\u00ECm");
		strcpy(MSSV,"");
		inCHUSO(MSSV,'U',15);
		p = SV_SEARCH_INFO_MSSV(FIRSTSV,(string)MSSV);		
	}
	
	SV_KHUNGEDITSV(SV_NEWCOT(),p,1);
	gotoMenuEX();
	char Tenlop[15] ;
	strcpy(Tenlop,p->SV.MALOP);
	while (true)
	{
		int select = getch();
		if (select == 224)
		{
			int select_val = getch();
			if (select_val==DEL)/*Xoa phan tu*/
			{
				char option = MsgYN(L"B\u1ea1n có mu\u1ed1n xóa SV này?");
				if (option == YES)
				{
					if (p==NULL) return;
					if(SV_Delete_info(FIRSTSV,p->SV))
					{
						Msg(L"Xóa thành công!!",1);
						
						for(int s=0;s<LISTTC.SOLUONG;s++)
						{
							if(DK_DELETE_INFO_MSSV(LISTTC.LOP[s]->SV,p->SV.MASV));
									
						}
						SV_SAVEFILE(Tenlop);
						TC_RESAVEDK();
						Msg(L"L\u01B0u sinh vi\u00EAn th\u00E0nh c\u00F4ng!!",1);
						break;
					}
					else
					{
						Msg(L"Xóa thất bại!!",-1);
					}
			
				}
				else
				{
					continue;
				}
	
			}/*end DEL*/
		}
		else if (select==F2)/*chinh sua 1 sinh vien*/
		{		
			char MSSV[15]="",HO[40]="",TEN[20]="",PHAI[3]="",SDT[11]="";
			int flag[5]={0,0,0,0,0};
			int moveedit = 1;
			string oldMSSV = p->SV.MASV;
			if (p==NULL) return;
			SV_KHUNGEDITSV(SV_NEWCOT(),p);
			gotoxy(EDITSVX-13,EDITSVY+6);
			int curX=getX(),curY=getY();
			while(true)
			{
				int select1 = getch(),select_val1;
				if (select1 == 224)
				{
					select_val1=getch();
					if(select_val1==UP)
					{
						if (moveedit >1)
						{
							moveedit --;
						}else continue;
						gotoxy(EDITSVX-13,EDITSVY+2+moveedit*4);
						curX=getX();curY=getY();
					}
					else if(select_val1==DOWN)
					{
						if (moveedit <5)
						{
							moveedit ++;
						}else continue;
								
						gotoxy(EDITSVX-13,EDITSVY+2+moveedit*4);
						curX=getX();curY=getY();
					}

				}
				else if(select1==ENTER||select1== BACKSPACE)
				{
					for(int nI=0;nI<39;nI++)cout<<" ";
					gotoxy(EDITSVX-13,EDITSVY+2+moveedit*4);

					if (moveedit==1)
					{
						inCHUSO(MSSV,'U',15);
						while(SV_SEARCH_INFO_MSSV_EX(QLSV.FIRST,(string)MSSV,p)!=NULL||strcmp(MSSV,"")==0)
						{
							gotoxy(curX,curY);
							for(int nI=0;nI<15;nI++)cout<<" ";
							gotoxy(curX,curY);
							if (SV_SEARCH_INFO_MSSV_EX(QLSV.FIRST,(string)MSSV,p)!=NULL)
							Msg(L"Mã sinh viên \u0111ã t\u1ed3n tại!",-1);
							else if(strcmp(MSSV,"")==0)
							Msg(L"Mã sinh viên không th\u1EC3 tr\u1ED1ng!",-1);
										
							
							gotoxy(curX,curY);
										
							strcpy(MSSV,"");
							inCHUSO(MSSV,'U',15);
						}
	
					}
					else if(moveedit==2)
					{
						inName(HO,40);
						while(strcmp(HO,"")==0)
						{
									
							Msg(L"Họ không th\u1ec3 \u0111\u1ec3 tr\u1ed1ng!",-1);
									
							
							gotoxy(curX,curY);
							inName(HO,40);
						}
	
					}
					else if(moveedit==3)
					{
						inName(TEN,20);
						while(strcmp(TEN,"")==0)
						{
										
							Msg(L"Tên không th\u1ec3 \u0111\u1ec3 tr\u1ed1ng!",-1);
							gotoxy(curX,curY);
							inName(TEN,20);
						}
					}
					else if(moveedit==4)
					{
		
						char Gender = MsgGender(3);
						if (Gender == MALE)
						{
							strcpy(PHAI,"Nam");
						}
						else
							strcpy(PHAI,"Nu");
					}
					else if(moveedit==5)
					{
						inNumSTR(SDT,11);
						if (strcmp(SDT,"")==0)
						strcpy(SDT,"-1");
								
					}
					flag[moveedit-1]=1;
					gotoxy(curX,curY);
				}
				else if(select1==F4)
				{
								
					char option = MsgYN(L"B\u1ea1n có mu\u1ed1n lưu SV v\u1eeba sửa?");
					if (option==YES)
					{
						if (flag[0]==1)
						{
							p->SV.MASV = (string)MSSV;
							for(int s=0;s<LISTTC.SOLUONG;s++)
							{
								DK_CHANGEINFO(LISTTC.LOP[s]->SV,oldMSSV,p->SV.MASV);
									
							}	
						}
									
						if(flag[1]==1)
						p->SV.HO = (string) HO;
						if(flag[2]==1)
						p->SV.TEN = (string) TEN;
						if(flag[3]==1)
						p->SV.PHAI = (string) PHAI;
						if(flag[4]==1)
						p->SV.SDT = (string) SDT;
						string DATA = "";
						int num =0;
						for(LISTSV q = FIRSTSV;q!=NULL;q=q->next)
						{
							if(strcmp(q->SV.MALOP,Tenlop)==0)
							{
								DATA = DATA + q->SV.MASV +"\t"+ md5(q->SV.MASV)+ "\t" +q->SV.HO +"\t"+q->SV.TEN+"\t"+q->SV.PHAI+"\t"+q->SV.SDT+"\t"+ (string) q->SV.MALOP +"\n";
								num++;
							}
						}
						DATA = i_to_string(num) +"\n"+DATA;
						char filename[50] = FOLDERDATA;
						strcat(filename,Tenlop);
						CREATFILE(filename,&DATA);
						TC_RESAVEDK();
					return;				
					}
					break;
				}else if(select1==ESC) break;
			}break;				
		}else if(select==ESC) break;
	}
}
bool LOP_SEARCH(char *TENLOP)/*Tim kiem ten lop co trong danh sach chua*/
{
	if (LISTLOP.SOLUONG == 0)
	return false;
		for (int i=0;i<LISTLOP.SOLUONG;i++)
		{
			if (strcmp(LISTLOP.MALOP[i],TENLOP)==0)
			return true;
		}
	return false;	
}
LISTSV SV_SEARCH_INFO(LISTSV FIRSTSV, STUDENT x)
{  
	LISTSV p;
	for (p = FIRSTSV;  p  != NULL ; p=p->next ) 
    	if (p->SV.MASV==x.MASV) return p;
	return NULL;
}

LISTSV SV_SEARCH_INFO_CLASS(LISTSV FIRSTSV, char *Tenlop)
{  
	LISTSV p;
	for (p = FIRSTSV;  p  != NULL ; p=p->next ) 
        if (strcmp(p->SV.MALOP,Tenlop)==0) return p;
	return NULL;
}
LISTSV SV_SEARCH_INFO_MSSV(LISTSV FIRSTSV, string MSSV)
{  
	LISTSV p;
	for (p = FIRSTSV;  p  != NULL ; p=p->next ) 
        if (MSSV==p->SV.MASV) return p;
	return NULL;
}
LISTSV SV_SEARCH_INFO_MSSV_EX(LISTSV FIRSTSV, string MSSV,LISTSV p)
{  
	LISTSV q;
	for (q = FIRSTSV;  q  != NULL&&q!=p ; q=q->next ) 
        if (MSSV==q->SV.MASV) return q;
	return NULL;
}

void SV_SELECTION_SORT(LISTSV &FIRSTSV)
{ 
	if(SV_Empty(FIRSTSV))return;
	LISTSV p, q, pmin;
	STUDENT min;
	for(p = FIRSTSV; p->next != NULL; p = p->next)
	{ 
		min = p->SV;
		pmin = p;
		for(q = p->next; q != NULL; q = q->next)
		if(strcmp(str_2_char(q->SV.TEN),str_2_char(min.TEN))<0 )
		{
			min = q->SV;
			pmin = q;
		}
		else if(strcmp(str_2_char(q->SV.TEN),str_2_char(min.TEN))==0)
		{
			if(strcmp(str_2_char(q->SV.HO),str_2_char(min.HO))<0 )
			{
			min = q->SV;
			pmin = q;
			}
		}
// hoan doi truong info cua hai nut p va pmin
		pmin->SV = p->SV;
		p->SV = min;
	}
}


/*==========================================================================*/
/*================================END XULY SINH VIEN========================*/
/*==========================================================================*/





/*==========================================================================*/
/*=======================Phan xu ly MON HOC  ===============================*/
/*==========================================================================*/
MONHOC MH_CREAT()
{
	MONHOC p;
	int MMH = Randnum();
	while(MH_SEARCH_NODE(root,MMH)!=NULL)
		MMH = Randnum();
	char *s;
	s = new char[10];
	strcpy(p.MAMH,itoa(MMH,s,10));
	p.STCLT = 0;
	p.STCTH = 0;
	p.TENMH = "";
	return p;
}
int MH_EMPTY(TREE root)
{
	return(root == NULL ? TRUE : FALSE);
}

void MH_FREETEMP(TREE &TEMP)
{

	
	while(TEMP!=NULL)
	{
		TREE p;
		p=TEMP;
		TEMP = TEMP->right;
		delete p;
	}
}
void MH_Init()
{
	ifstream file;
	
	file.open("DATA\\MONHOC\\listMH.data");
	MONHOC NEWMH;
	if (!file.is_open())
	{
		string DATA = "";
		char filelist[] = "DATA\\MONHOC\\listMH.data";
		
		CREATFILE(filelist,&DATA);
		TiengViet(L"File không t\u1ed3n tại");
		return;
	}
	while (!file.eof())
	{
		NEWMH= MH_CREAT();
		file>>NEWMH.MAMH>>NEWMH.STCLT>>NEWMH.STCTH;
		
		file.ignore(1);
		getline(file,NEWMH.TENMH,'\n');
		if (NEWMH.TENMH=="")break;
		MH_INSERT_NODE(root,NEWMH);
	}
	file.close();
}
void MH_INSERT_NODE(TREE &p, MONHOC a)
{
	if(p == NULL) // n�t p hi?n t?i s? l� n�t l�
	{
		p = MH_NEWNODE();
		p->MH = a;
		p->left = NULL; p->right = NULL;
	}
	else
		if(atoi(a.MAMH) < atoi(p->MH.MAMH ))
		MH_INSERT_NODE(p->left, a);
		else if(atoi(a.MAMH) > atoi(p->MH.MAMH ) ) MH_INSERT_NODE(p->right, a);
}
void MH_KHUNGEDITMH(MAXCOT NEWCOT,TREE p,int type)/*Ve khung chinh sua sinh vien*/
{
	if(p==NULL)return;
	Color(COLORKHUNG);
	char firstchar,midchar,lastchar ;
	for(int i=0;i<EDITSVH-4;i++)
	{
		gotoxy(EDITSVX-EDITSVW/2,EDITSVY+i);
		if (i==0)
		{
			firstchar = char(topchar);
			midchar = char(topchar);
			lastchar = char(topchar);
		}
		else if(i==EDITSVH-5)
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
		for(int j=1;j<EDITSVW-1;j++)
		{
			cout << midchar;
		}
		cout << lastchar<<endl;
	
	}
	Color(COLORDEFAUL);
	gotoxy(EDITSVX-8,EDITSVY+2);
	Color(COLORTITLETEXT);
	if(type==0)
	TiengViet(L"  S\u1EECA M\u00D4N H\u1ECCC  ");
	else
	TiengViet(L"XEM M\u00D4N H\u1ECCC");
	Color(COLORDEFAUL);
	for(int i = 1;i<NEWCOT.SOLUONGCOT;i++)
	{
		
		gotoxy(EDITSVX-14,EDITSVY+1+4*i);
		cout<<char(218);for(int j=1;j<INPUTEDITW;j++)cout<<char(196);cout<<char(191);
		gotoxy(EDITSVX-15-wcslen(NEWCOT.INFOCOT[i]->TENCOT),EDITSVY+2+4*i);
		TiengViet(NEWCOT.INFOCOT[i]->TENCOT);
		cout << ' ';
		cout<<char(179);for(int j=1;j<INPUTEDITW;j++)cout<<' ';cout<<char(179);
		gotoxy(EDITSVX-14,EDITSVY+3+4*i);
		cout<<char(192);for(int j=1;j<INPUTEDITW;j++)cout<<char(196);cout<<char(217);
		gotoxy(EDITSVX-13,EDITSVY+2+4*i);
		if (i==1)
		{
			Color(COLORDISABLE);
			cout<< p->MH.MAMH;
			Color(COLORDEFAUL);
		}
		
		else if (i==2)
		{
			if(type!=0)
			Color(COLORDISABLE);
			cout<< p->MH.TENMH;
			Color(COLORDEFAUL);
		}
		
		else if (i==3)
		{
			if(type!=0)
			Color(COLORDISABLE);
			cout<< p->MH.STCLT;
			Color(COLORDEFAUL);
		}
		
		else if (i==4)
		{
			if(type!=0)
			Color(COLORDISABLE);
			cout<< p->MH.STCTH;
			Color(COLORDEFAUL);
		}
		
		
	}


}
void MH_KHUNGNHAP(MAXCOT NEWCOT)/*Ve khung Nhap MH*/
{
		Color(COLORKHUNG);
	char firstchar,midchar,lastchar ;
	for(int i=0;i<EDITSVH-4;i++)
	{
		gotoxy(EDITSVX-EDITSVW/2,EDITSVY+i);
		if (i==0)
		{
			firstchar = char(topchar);
			midchar = char(topchar);
			lastchar = char(topchar);
		}
		else if(i==EDITSVH-5)
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
		for(int j=1;j<EDITSVW-1;j++)
		{
			cout << midchar;
		}
		cout << lastchar<<endl;
	
	}
	Color(COLORDEFAUL);
	gotoxy(EDITSVX-8,EDITSVY+2);
	Color(COLORTITLETEXT);
	TiengViet(L"  NHẬP M\u00D4N H\u1ECCC  ");
	Color(COLORDEFAUL);
	for(int i = 1;i<NEWCOT.SOLUONGCOT;i++)
	{
		
		gotoxy(EDITSVX-14,EDITSVY+1+4*i);
		cout<<char(218);for(int j=1;j<INPUTEDITW;j++)cout<<char(196);cout<<char(191);
		gotoxy(EDITSVX-15-wcslen(NEWCOT.INFOCOT[i]->TENCOT),EDITSVY+2+4*i);
		TiengViet(NEWCOT.INFOCOT[i]->TENCOT);
		cout << ' ';
		cout<<char(179);for(int j=1;j<INPUTEDITW;j++)cout<<' ';cout<<char(179);
		gotoxy(EDITSVX-14,EDITSVY+3+4*i);
		cout<<char(192);for(int j=1;j<INPUTEDITW;j++)cout<<char(196);cout<<char(217);
		gotoxy(EDITSVX-13,EDITSVY+2+4*i);
		
	}
	

}
MAXCOT MH_NEWCOT()
{
	MAXCOT NEWCOT;
	NEWCOT.SOLUONGCOT = 5;
	for(int i=0;i<NEWCOT.SOLUONGCOT;i++)
	{
		NEWCOT.INFOCOT[i] = new COT;
	}
	NEWCOT.INFOCOT[0]->WCOT = 5;
	NEWCOT.INFOCOT[0]->TENCOT = L"STT";
	NEWCOT.INFOCOT[1]->WCOT = 14;
	NEWCOT.INFOCOT[1]->TENCOT = L"Mã môn học";
	NEWCOT.INFOCOT[2]->WCOT = 55;
	NEWCOT.INFOCOT[2]->TENCOT = L"Tên môn học";
	NEWCOT.INFOCOT[3]->WCOT = 22;
	NEWCOT.INFOCOT[3]->TENCOT = L"TC Lý thuyết";
	NEWCOT.INFOCOT[4]->WCOT = 22;
	NEWCOT.INFOCOT[4]->TENCOT = L"TC thực hành";
	return NEWCOT;
}
MAXCOT LOP_NEWCOT()
{
	MAXCOT NEWCOT;
	NEWCOT.SOLUONGCOT = 3;
	for(int i=0;i<NEWCOT.SOLUONGCOT;i++)
	{
		NEWCOT.INFOCOT[i] = new COT;
	}
	NEWCOT.INFOCOT[0]->WCOT = 5;
	NEWCOT.INFOCOT[0]->TENCOT = L"STT";
	NEWCOT.INFOCOT[1]->WCOT = 60;
	NEWCOT.INFOCOT[1]->TENCOT = L"Tên l\u1EDBp học";
	NEWCOT.INFOCOT[2]->WCOT = 55;
	NEWCOT.INFOCOT[2]->TENCOT = L"S\u1ED1 sinh viên hi\u1EC7n tại của l\u1EDBp";

	return NEWCOT;
}
TREE MH_NEWNODE()
{
	TREE p;
	p = new NODEMH;
	return p;
}
void MH_ADDNEW()
{
	srand(time(NULL));
	int STCLT =0, STCTH = 0;
	MONHOC NEWMH =MH_CREAT();
	MH_KHUNGNHAP(MH_NEWCOT());
	char ans = NONE;
	SELECTYN(ans,13);
	gotoxy(EDITSVX-13,EDITSVY+6);
	cout << NEWMH.MAMH;
	gotoxy(EDITSVX-13,EDITSVY+10);
	NEWMH.TENMH= inNameSTR(40);
	while(NEWMH.TENMH=="")
	{
		gotoxy(EDITSVX-13,EDITSVY+10);
					
		Msg(L"Tên môn học không th\u1EC3 tr\u1ED1ng!",-1);
		
		gotoxy(EDITSVX-13,EDITSVY+10);
		NEWMH.TENMH= inNameSTR(40);
			
	}
	gotoxy(EDITSVX-13,EDITSVY+14);
	inNum(&STCLT,2);
	NEWMH.STCLT = STCLT;
	gotoxy(EDITSVX-13,EDITSVY+18);
	inNum(&STCTH,2);
	NEWMH.STCTH = STCTH;
	ans = YES ;
	SELECTYN(ans,13);
	gotoMenuEX();
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
			SELECTYN(ans,13);
			gotoMenuEX();
		}else if( (char) select == ENTER)
		{
			break;
		
		}
		
		
		
	}
	if (ans == YES)
	{
		MH_INSERT_NODE(root,NEWMH);
		MH_SAVENEWFILE();
		Msg(L"Lưu môn học thành công!!",1);
	}
	else if(ans == NO)
	{
		Msg(L"Lưu môn học thất bại!!",-1);
	}
}

void MH_SAVEFILE (TREE p)
{ 
	if(p != NULL)
	{ 
		ofstream file;
		file.open("DATA\\MONHOC\\listMH.data",ios::out|ios::app);
		file<<p->MH.MAMH<<"\t"<<p->MH.STCLT<< "\t" <<p->MH.STCTH <<"\t" << p->MH.TENMH << endl;
		
		file.close();
		MH_SAVEFILE(p->left);	
		MH_SAVEFILE (p->right);
	}
}
void MH_RECOUNTTC (TREE p)
{ 
	if(p != NULL)
	{ 
		TONGTC=TONGTC+p->MH.STCLT+p->MH.STCTH;
		TONGMH++;
		MH_RECOUNTTC(p->left);	
		MH_RECOUNTTC (p->right);
	}
}
void MH_LOADTENMH (TREE p,char **DULIEUTENMH,int *TINCHI)
{ 
	if(p != NULL)
	{ 
		TINCHI[TONGMH] = p->MH.STCLT+p->MH.STCTH;
		strcpy(DULIEUTENMH[TONGMH],p->MH.MAMH);
		TONGMH++;
		MH_LOADTENMH(p->left,DULIEUTENMH,TINCHI);	
		MH_LOADTENMH (p->right,DULIEUTENMH,TINCHI);
	}
}
void MH_PRINTMH(int type)
{
	TREE ROOTTEMP = NULL,p;
	int sodong = 0;
	if(MH_EMPTY(root)) 
	{
		Msg(L"Không có môn học trong dữ li\u1EC7u!",-1);
		return;
	}
	
	while(!MH_EMPTY(root))
	{
		sodong++;
		MH_INSERT_NODE(ROOTTEMP,MH_SEARCH_MIN()->MH);
		MH_REMOVE_NODE(atoi(MH_SEARCH_MIN()->MH.MAMH),root);
	}
	MH_Init();
	MH_SELECTION_SORT(ROOTTEMP);
	MH_PRINTINFO(sodong,type,ROOTTEMP);
	if(root!=NULL)
	MH_FREETEMP(ROOTTEMP);

}
void MH_PRINTINFODETAIL(int sodong,TREE &p,int curentpage,int x,int y,int type)
{
	if(p==NULL)return;
	DRAWTABLE(sodong,MH_NEWCOT());
	if (sodong-1 > NUMLINETABLE)
		sodong = NUMLINETABLE +1;
	gotoxy(x,y);
	int currentx,currenty;
	int i=0;
		for (p;p!=NULL;p=p->right)
			{

			
				gotoxy(x,y+i*2);
				if(p!=NULL)
				{
					for (int j=0;j<MH_NEWCOT().SOLUONGCOT;j++)
					{
					currentx=getX();
					currenty=getY();
					switch (j)
					{
						case 0:
						{
							gotoxy(getX()+2,getY());
							if(type==3||type==4)
							{
								if(i==0)
								{
								Color(COLORSELECT);
								TiengViet(SELECTPOITER);
								Color(COLORDEFAUL);	
								}

							}
							else if(type==DEFAULT)
							{
							}
							else if (type == PRINT)
								cout<< (curentpage-1)*NUMLINETABLE+i+1;
								gotoxy(getX()-2,getY());
						}
		
						break;
						case 1:
						cout<< p->MH.MAMH;
						break;
						case 2:
						cout<< p->MH.TENMH;
						break;
						case 3:
						cout<< p->MH.STCLT;
						break;
						case 4:
						cout<< p->MH.STCTH;
						break;

			
					}
					gotoxy(currentx+MH_NEWCOT().INFOCOT[j]->WCOT+1,currenty);
	
				}
			}
			i++;
			if (p->right==NULL||i==sodong-1)break;
			
			
	}/*end for*/gotoMenuEX();
}
int MH_DELETE_INFO(TREE &ROOTTEMP,char *x)
{  
	TREE p=ROOTTEMP;
  	if (ROOTTEMP==NULL ) return 0;
  	if (strcmp(ROOTTEMP->MH.MAMH ,x)==0 ) {
     p=ROOTTEMP;
	 ROOTTEMP = p->right ;
	 
	 delete p ; return 1;
  }
    
	for ( p=ROOTTEMP; p->right!=NULL && strcmp(p->right->MH.MAMH,x)!=0; p=p->right) ;
	if (p->right!= NULL ) {
		TREE q=p->right; 
		p->right=q->right;
		if (p->right==NULL)
		
		delete q; return 1;
	}
     return 0;
}

void MH_PRINTINFO(int sodong,int type,TREE ROOTTEMP)
{
	ClearDetailTable();
	int TOTALNUM = sodong;
	if(sodong==0) 
	{
		Msg(L"Không có môn học!",-1);
		return;
	}
	int MAXPAGE = (int)ceil((double)sodong/NUMLINETABLE);
	int curentpage = 1,cureditpage=1;
	int mod = sodong % NUMLINETABLE;
	gotoMenuFun();
	const int x=getX()+3,y = getY()+4+NUMLINETITLE;
	int currentx,currenty;
	gotoxy(x,y);
	switch (type)
	
	{

		case 2:/*in danh sach mon hoc*/
		{
			
			TREE p = ROOTTEMP;
			if (p==NULL) return;
			MH_PRINTINFODETAIL(sodong+1,p,curentpage,x,y,type);
			while (true)
			{
				int swpage = getch();
				if(swpage == 224)
				{
					int swpage_val = getch();
					if (swpage_val == PAGEDOWN)/*pagedown*/
					{
						if (curentpage< MAXPAGE)
						{	
			
						curentpage++;
						}
						else continue;
						if (curentpage == MAXPAGE)
						{
								if (mod!=0)
							sodong = mod;
						}
						else
						{
							sodong = NUMLINETABLE;
						}
						p=	p->right;
						if (p==NULL) return;
						MH_PRINTINFODETAIL(sodong+1,p,curentpage,x,y,type);
					}
					else if(swpage_val == PAGEUP)/*down*/
					{
	
				
						if (curentpage>1)
						{	
	
						curentpage--;
						}
						else continue;
						sodong = NUMLINETABLE;
						p = ROOTTEMP;
						if (p==NULL) return;
						if (curentpage!= 1)
						{
							for(int z=1;z<curentpage;z++)
							{
								for(int w=0;w<sodong;w++)
								p=p->right;
							}
						}
				
						if (p==NULL) return;
						if (curentpage == MAXPAGE)
						{
							if (mod!=0)
							sodong = mod;
						}
						else
						{
							sodong = NUMLINETABLE;
						}
						MH_PRINTINFODETAIL(sodong+1,p,curentpage,x,y,type);
					}
				

				}
				else
				{
			
					if ((char) swpage == ESC)
					{

						break;
	
					
					}
	      
				}

			}/*end while*/
				
				
		}break;/*end case 2*/
		case 3:/*Xoa va sua danh sach mon hoc*/
		{
			
			int edit=1,editold=0,moveedit=1;
			TREE p = ROOTTEMP;
			if (p==NULL) return;
			MH_PRINTINFODETAIL(sodong+1,p,cureditpage,x,y,type);
			int select ;
			while(true)
			{
				select = getch();
				if (select == 224)
				{
					int select_val = getch();
		
					if (select_val==UP)
					{
		

						if (edit>1)
						{
							edit--;
							editold = 1;
						}else continue;
						if (edit %NUMLINETABLE==0 )
						{
							
							cureditpage--;sodong = NUMLINETABLE;
							p = ROOTTEMP;
							if (p==NULL) return;
							if (cureditpage!= 1)
							{
			
								for(int w=0;w<NUMLINETABLE*(cureditpage-1);w++)
								p=p->right;
							
							}
							if (p==NULL) return;
							
							MH_PRINTINFODETAIL(sodong+1,p,cureditpage,x,y,DEFAULT);
						}
						gotoxy(x+2,y+((edit-1)%NUMLINETABLE+editold)*2);
						cout << " ";
						gotoxy(x+2,y+((edit-1)%NUMLINETABLE)*2);
						Color(COLORSELECT);
						TiengViet(SELECTPOITER);
						Color(COLORDEFAUL);	gotoMenuEX();
					}
					else if (select_val==DOWN)
					{
						if (edit<TOTALNUM)
						{
							edit++;
							editold = -1;
						}else continue;
						if (edit %NUMLINETABLE==1 )
						{
							if (edit > NUMLINETABLE)
							{
							cureditpage++;editold=0;	
							}
							
							if(cureditpage < MAXPAGE)
							{
								sodong = NUMLINETABLE;
							}else
							{
								if (mod!=0)
								sodong = mod;
							}
						
							p=p->right;
							if (p==NULL) return;
							MH_PRINTINFODETAIL(sodong+1,p,cureditpage,x,y,type);
						}
						gotoxy(x+2,y+((edit-1)%NUMLINETABLE+editold)*2);
						cout << " ";
						gotoxy(x+2,y+((edit-1)%NUMLINETABLE)*2);
						Color(COLORSELECT);
						TiengViet(SELECTPOITER);
						Color(COLORDEFAUL);	gotoMenuEX();
					}
					else if (select_val==DEL)/*Xoa phan tu*/
					{
						char option = MsgYN(L"B\u1ea1n có mu\u1ed1n xóa MH này?");
						if (option == YES)
						{
							p = ROOTTEMP;
							if (p==NULL) return;
							for(int w=0;w<edit-1;w++)
							p=p->right;
							if(TC_CHECKSV(p->MH.MAMH))
							{
								Msg(L"MH có SV ĐK,không th\u1EC3 xóa",-1);
								break;
							}
							if (p==NULL) return;
							if(MH_DELETE_INFO(ROOTTEMP,p->MH.MAMH))
							{
								MH_REMOVE_NODE(atoi(p->MH.MAMH),root);
								
								while(TC_SEARCH_INFO(p->MH.MAMH)!=-1)
								{
									TC_DELETE_ITEM(TC_SEARCH_INFO(p->MH.MAMH));
								}
								Msg(L"Xóa MH thành công!!",1);
								ClearMenuFunTABLE();
								TOTALNUM--;
								if(edit>1){edit--;editold=1;}
								
								if(edit%NUMLINETABLE==0&&cureditpage>1)cureditpage--; 
								MH_SAVENEWFILE();
								TC_SAVEFILE();
								Msg(L"Lưu môn học thành công!!",1);
							}
							else
							{
								Msg(L"Xóa thất bại!!!",-1);
							}
							
							
							
						
						}
						
						p = ROOTTEMP;
						if (p==NULL) {
						MH_SAVENEWFILE();	
						TC_SAVEFILE();
						return;
						}
						if(cureditpage>1)
						for(int s=0;s<(cureditpage-1)*NUMLINETABLE;s++)
						p=p->right;
						MAXPAGE = (int)ceil((double)TOTALNUM/NUMLINETABLE);
						mod = TOTALNUM % NUMLINETABLE;
						if (cureditpage < MAXPAGE||mod==0)
						sodong = NUMLINETABLE;
						else
						sodong = mod;
						MH_PRINTINFODETAIL(sodong+1,p,cureditpage,x,y,DEFAULT);
						gotoxy(x+2,y+((edit-1)%NUMLINETABLE+editold)*2);
						cout << " ";
						gotoxy(x+2,y+((edit-1)%NUMLINETABLE)*2);
						Color(COLORSELECT);
						TiengViet(SELECTPOITER);
						Color(COLORDEFAUL);	gotoMenuEX();
					}

		
		
				}
				else if(select==F3)
				{
					
					MH_SEARCH(ROOTTEMP);
					MH_RECOUNTTC(root);
					
					p = ROOTTEMP;		
					for(int s=0;s<(cureditpage-1)*NUMLINETABLE;s++)
					p=p->right;
					if (p==NULL) return;
					TOTALNUM = TONGMH;
					MAXPAGE = (int)ceil((double)TOTALNUM/NUMLINETABLE);
					mod = TOTALNUM % NUMLINETABLE;
					if (cureditpage < MAXPAGE||mod==0)
					sodong = NUMLINETABLE;
					else
					sodong = mod;
					MH_PRINTINFODETAIL(sodong+1,p,cureditpage,x,y,DEFAULT);
					gotoxy(x+2,y+((edit-1)%NUMLINETABLE+editold)*2);
					cout << " ";
					gotoxy(x+2,y+((edit-1)%NUMLINETABLE)*2);
					Color(COLORSELECT);
					TiengViet(SELECTPOITER);
					Color(COLORDEFAUL);	gotoMenuEX();
				}
				else if (select==F2)/*chinh sua 1 sinh vien*/
				{		
					string TENMH="";
					int STCLT =0,STCTH=0;
					int flag[3]={0,0,0};
					moveedit = 1;
					p = ROOTTEMP;
					if (p==NULL) return;
					for(int w=0;w<edit-1;w++)
						p=p->right;
						if (p==NULL) return;
					MH_KHUNGEDITMH(MH_NEWCOT(),p);
					gotoxy(EDITSVX-13,EDITSVY+10);
					int curX=getX(),curY=getY();
					while(true)
					{
						int select1 = getch(),select_val1;
						if (select1 == 224)
						{
							select_val1=getch();
							if(select_val1==UP)
							{
								if (moveedit >1)
								{
									moveedit --;
								}else continue;
								
								gotoxy(EDITSVX-13,EDITSVY+6+moveedit*4);
								curX=getX();curY=getY();
							}
							else if(select_val1==DOWN)
							{
								if (moveedit <3)
								{
									moveedit ++;
								}else continue;
							
								gotoxy(EDITSVX-13,EDITSVY+6+moveedit*4);
								curX=getX();curY=getY();
							}

						}
						else if(select1==ENTER||select1== BACKSPACE)
						{
							for(int nI=0;nI<39;nI++)cout<<" ";
							gotoxy(EDITSVX-13,EDITSVY+6+moveedit*4);

							if (moveedit==1)
							{
								TENMH= inNameSTR(40);
								while(TENMH=="")
								{
										
									gotoxy(curX,curY);
									for(int nI=0;nI<40;nI++)cout<<" ";
									gotoxy(curX,curY);
													
									Msg(L"Tên môn học không th\u1EC3 tr\u1ED1ng!",-1);

									gotoxy(curX,curY);
									
									TENMH= inNameSTR(40);
								}
									
							}
							else if(moveedit==2)
							{
								inNum(&STCLT,2);
									
									
							}
							else if(moveedit==3)
							{
								inNum(&STCTH,2);
								
							}
					
							flag[moveedit-1]=1;
							gotoxy(curX,curY);
						}
						else if(select1==F4)
						{
							p = ROOTTEMP;
				
							if (p==NULL) return;
							for(int w=0;w<edit-1;w++)
							p=p->right;
							TREE q = MH_SEARCH_NODE(root,atoi(p->MH.MAMH));
							
							if (p==NULL||q==NULL) return;
							char option = MsgYN(L"B\u1ea1n có mu\u1ed1n lưu MH v\u1eeba sửa?");
							if (option==YES)
							{
								if (flag[0]==1)
								{
									q->MH.TENMH = TENMH;
									p->MH.TENMH = TENMH;
								}
								if(flag[1]==1)
								{
									p->MH.STCLT = STCLT;
									q->MH.STCLT = STCLT;
								}
								
								if(flag[2]==1)
								{
									p->MH.STCTH = STCTH;
									q->MH.STCTH = STCTH;
								}
								
							MH_SAVENEWFILE();
							TC_SAVEFILE();	
							Msg(L"Lưu môn học thành công!!",1);
							}
							break;
						}
						else if(select1==ESC) break;
					}
					p = ROOTTEMP;		
					for(int s=0;s<(cureditpage-1)*NUMLINETABLE;s++)
					p=p->right;
					if (p==NULL) return;
					MH_PRINTINFODETAIL(sodong+1,p,cureditpage,x,y,DEFAULT);
					gotoxy(x+2,y+((edit-1)%NUMLINETABLE+editold)*2);
					cout << " ";
					gotoxy(x+2,y+((edit-1)%NUMLINETABLE)*2);
					Color(COLORSELECT);
					TiengViet(SELECTPOITER);
					Color(COLORDEFAUL);	gotoMenuEX();
				}
				else if (select==F4)/*Luu*/
				{
					char option = MsgYN(L"B\u1ea1n có mu\u1ed1n lưu những thay \u0111\u1ED5i?");
					if (option==YES)
					{
						MH_SAVENEWFILE();
						TC_SAVEFILE();
						Msg(L"Lưu môn học thành công!!",1);


					}
					else
					{
						MH_Init();
					}	
					
					Msg(L"Thoát sửa môn học!",1);
					break;
				}
				else if(select==ESC) break;
				
			}
			
		}break;/*end case 3*/
		case 4:/*Mo lop tin chi theo mon hoc*/
		{
			
			int edit=1,editold=0,moveedit=1;
			TREE p = ROOTTEMP;
			if (p==NULL) return;
			MH_PRINTINFODETAIL(sodong+1,p,cureditpage,x,y,type);
			int select;
			while(true)
			{
				select = getch();
				if (select == 224)
				{
					int select_val = getch();
		
					if (select_val==UP)
					{
						if (edit>1)
						{
							edit--;
							editold = 1;
						}else continue;
						if (edit %NUMLINETABLE==0 )
						{
				
							cureditpage--;sodong = NUMLINETABLE;
							p = ROOTTEMP;
							if (p==NULL) return;
							if (cureditpage!= 1)
							{
			
								for(int w=0;w<NUMLINETABLE*(cureditpage-1);w++)
								p=p->right;
							
							}
							if (p==NULL) return;
							MH_PRINTINFODETAIL(sodong+1,p,cureditpage,x,y,DEFAULT);
						}
						gotoxy(x+2,y+((edit-1)%NUMLINETABLE+editold)*2);
						cout << " ";
						gotoxy(x+2,y+((edit-1)%NUMLINETABLE)*2);
						Color(COLORSELECT);
						TiengViet(SELECTPOITER);
						Color(COLORDEFAUL);	gotoMenuEX();
					}
					else if (select_val==DOWN)
					{
			
						if (edit<TOTALNUM)
						{
							edit++;
							editold = -1;
						}else continue;
						if (edit %NUMLINETABLE==1 )
						{
							if (edit > NUMLINETABLE)
							{
							cureditpage++;editold=0;	
							}
							if(cureditpage < MAXPAGE)
							{
								sodong = NUMLINETABLE;
							}else
							{
								if (mod!=0)
								sodong = mod;
							}
						
							p=p->right;
							if (p==NULL) return;
							MH_PRINTINFODETAIL(sodong+1,p,cureditpage,x,y,type);
						}
						gotoxy(x+2,y+((edit-1)%NUMLINETABLE+editold)*2);
						cout << " ";
						gotoxy(x+2,y+((edit-1)%NUMLINETABLE)*2);
						Color(COLORSELECT);
						TiengViet(SELECTPOITER);
						Color(COLORDEFAUL);	gotoMenuEX();
					}
		

		
		
				}
				else if (select==ENTER)/*chinh Mo top tin chi theo mon hoc*/
				{		
					LISTTC.LOP[LISTTC.SOLUONG] = TC_CREATNEWCLASS();
					p = ROOTTEMP;
					if (p==NULL) return;
					for(int w=0;w<edit-1;w++)
						p=p->right;
						if (p==NULL) return;
					TC_KHUNGADD(TC_NEWCOT());
					gotoxy(EDITSVX-13,EDITSVY+1);
					if (LISTTC.SOLUONG==0)
					{
						cout << TC_SEARCH_MAXVAL() + 100;
						LISTTC.LOP[LISTTC.SOLUONG]->MALOPTC = LISTTC.SOLUONG + 100;	
					}
					else
					{
						cout << TC_SEARCH_MAXVAL()+1;
						LISTTC.LOP[LISTTC.SOLUONG]->MALOPTC = TC_SEARCH_MAXVAL()+1;
					}
					gotoxy(EDITSVX-13,EDITSVY+5);
					cout << p->MH.MAMH;
					strcpy(LISTTC.LOP[LISTTC.SOLUONG]->MAMH,p->MH.MAMH);
					gotoxy(EDITSVX-13,EDITSVY+9);
					cout << p->MH.TENMH;
					gotoxy(EDITSVX-13,EDITSVY+13);
					inNumUS(&LISTTC.LOP[LISTTC.SOLUONG]->KHOA,4);
					while(LISTTC.LOP[LISTTC.SOLUONG]->KHOA==0)
					{
						Msg(L"Xin hãy nhập niên khóa!!",-1);
						inNumUS(&LISTTC.LOP[LISTTC.SOLUONG]->KHOA,4);
						
					}
					gotoxy(EDITSVX-13,EDITSVY+17);
					inNumUS(&LISTTC.LOP[LISTTC.SOLUONG]->HOCKY,1);
					while(LISTTC.LOP[LISTTC.SOLUONG]->HOCKY==0)
					{
						Msg(L"Xin hãy nhập học kỳ!!",-1);
						inNumUS(&LISTTC.LOP[LISTTC.SOLUONG]->HOCKY,1);
						
					}
					gotoxy(EDITSVX-13,EDITSVY+21);
					inNumUS(&LISTTC.LOP[LISTTC.SOLUONG]->NHOM,2);
					while(LISTTC.LOP[LISTTC.SOLUONG]->NHOM==0)
					{
						Msg(L"Xin hãy nhập s\u1ED1 nhóm!!",-1);
						inNumUS(&LISTTC.LOP[LISTTC.SOLUONG]->NHOM,2);
						
					}
					int curX=getX(),curY=getY();
					int check = 1;
					while(true)
					{
						if (check)
						{
							if(TC_CHECKEXIT(LISTTC.LOP[LISTTC.SOLUONG]))
							{
								Msg(L"L\u1EDBp này \u0111\u00E3 t\u1ED3n tại",-1);
								gotoxy(EDITSVX-13,EDITSVY+9+1*4);
							}
							else
							{
								break;
							}
						}
						check =0;
						int select1 = getch(),select_val1;
						if (select1 == 224)
						{
							select_val1=getch();
							if(select_val1==UP)
							{
								if (moveedit >1)
								{
									moveedit --;
								}else continue;
								
								gotoxy(EDITSVX-13,EDITSVY+9+moveedit*4);
								curX=getX();curY=getY();
							}
							else if(select_val1==DOWN)
							{
								if (moveedit <3)
								{
									moveedit ++;
								}else continue;
							
								gotoxy(EDITSVX-13,EDITSVY+9+moveedit*4);
								curX=getX();curY=getY();
							}

						}
						else if(select1== BACKSPACE)
						{
							for(int nI=0;nI<39;nI++)cout<<" ";
							gotoxy(EDITSVX-13,EDITSVY+9+moveedit*4);
							
							if (moveedit==1)
							{
								inNumUS(&LISTTC.LOP[LISTTC.SOLUONG]->KHOA,4);
								while(LISTTC.LOP[LISTTC.SOLUONG]->KHOA==0)
								{
								Msg(L"Xin hãy nhập niên khóa!!",-1);
								inNumUS(&LISTTC.LOP[LISTTC.SOLUONG]->KHOA,4);
												
								}
								
							}
							else if(moveedit==2)
							{
								inNumUS(&LISTTC.LOP[LISTTC.SOLUONG]->HOCKY,1);
								while(LISTTC.LOP[LISTTC.SOLUONG]->HOCKY==0)
								{
								Msg(L"Xin hãy nhập học kỳ!!",-1);
								inNumUS(&LISTTC.LOP[LISTTC.SOLUONG]->HOCKY,1);
												
								}
								
							}
							else if(moveedit==3)
							{
								inNumUS(&LISTTC.LOP[LISTTC.SOLUONG]->NHOM,2);
								while(&LISTTC.LOP[LISTTC.SOLUONG]->NHOM==0)
								{
									Msg(L"Xin hãy nhập s\u1ED1 nhóm!!",-1);
									inNumUS(&LISTTC.LOP[LISTTC.SOLUONG]->NHOM,2);
									
								}
							
							}
							gotoxy(curX,curY);

						}
						else if(select1== ENTER)
						check =1;
					
				
					
					}
					gotoxy(EDITSVX-13,EDITSVY+25);
					inNumUS(&LISTTC.LOP[LISTTC.SOLUONG]->MAXSV,3);
					while(LISTTC.LOP[LISTTC.SOLUONG]->MAXSV==0)
					{
						Msg(L"Xin hãy nhập s\u1ED1 sinh viên!!",-1);
						inNumUS(&LISTTC.LOP[LISTTC.SOLUONG]->MAXSV,3);
						
					}
					LISTTC.SOLUONG++;
				
					TC_SAVEFILE();
					TC_CREATNEWCLASS_SAVE();
					Msg(L"Tạo l\u1EDBp tín ch\u1EC9 thành công",1);		
					p = ROOTTEMP;		
					for(int s=0;s<(cureditpage-1)*NUMLINETABLE;s++)
					p=p->right;
					if (p==NULL) return;
					ClearDetailTable();
					MH_PRINTINFODETAIL(sodong+1,p,cureditpage,x,y,DEFAULT);
					gotoxy(x+2,y+((edit-1)%NUMLINETABLE+editold)*2);
					cout << " ";
					gotoxy(x+2,y+((edit-1)%NUMLINETABLE)*2);
					Color(COLORSELECT);
					TiengViet(SELECTPOITER);
					Color(COLORDEFAUL);	gotoMenuEX();
							
				}
		
				else if (select==ESC) break;	
				
			}
			
		}break;/*end case 4*/
	}/*end switch*/
}

void MH_REMOVE_CASE_3 ( TREE &r,TREE &rp )
{
	if (r->left != NULL)
		MH_REMOVE_CASE_3 (r->left,rp);
		//den day r la nut cuc trai cua cay con ben phai co nut goc la rp}
	else
	{
		//rp->key = r->key; //Chep noi dung cua r sang rp ";
		rp->MH =r->MH; // de lat nua free(rp)
		rp = r;
		r = rp->right;
	}
}
void MH_REMOVE_NODE (int x , TREE &p )
{
	TREE rp;
	if(p==root&&p->left==NULL&&p->right==NULL)
	{
		rp=p;root=NULL;
		delete rp;
		return;
	}
	if (p == NULL) {
		printf ("Khong tim thay");
	}
	else
		if (x < atoi(p->MH.MAMH)) MH_REMOVE_NODE (x, p->left);
		else if (x > atoi(p->MH.MAMH))
		MH_REMOVE_NODE (x, p->right);
		else // p->key = x
		{
			rp = p;
			if (rp->right == NULL) p = rp->left;
			// p l� n�t l� hoac la nut chi co cay con ben trai
			else if (rp->left == NULL)
				p = rp->right; // p l� nut co cay con ben phai
			else MH_REMOVE_CASE_3 (rp->right,rp);
			delete rp;
		}
}
void MH_SEARCH(TREE &ROOTTEMP)
{
	MsgSearch(L"Nh\u1EADp m\u00E3 m\u00F4n h\u1ECDc c\u1EA7n t\u00ECm");
	char MAMH[10]="";
	inCHUSO(MAMH,'U',10);
	TREE p = NULL;
	p = MH_SEARCH_NODE(root,atoi(MAMH));
	while(p == NULL)
	{
		if(strcmp(MAMH,"")==0)
		{
			Msg(L"Tho\u00E1t t\u00ECm ki\u1EBFm!",1);
			return;
		}
		Msg(L"M\u00E3 m\u00F4n h\u1ECDc kh\u00F4ng t\u1ED3n t\u1EA1i!",-1);
		MsgSearch(L"Nh\u1EADp m\u00E3 m\u00F4n h\u1ECDc c\u1EA7n t\u00ECm");
		strcpy(MAMH,"");
		inCHUSO(MAMH,'U',15);
		p = MH_SEARCH_NODE(root,atoi(MAMH));	
	}
	
	MH_KHUNGEDITMH(MH_NEWCOT(),p,1);
	gotoMenuEX();
	
	while (true)
	{
		int select = getch();
		if (select == 224)
		{
			int select_val = getch();
			if (select_val==DEL)/*Xoa phan tu*/
			{
				
				char option = MsgYN(L"B\u1ea1n có mu\u1ed1n xóa MH này?");
				if (option == YES)
				{
					
					if(TC_CHECKSV(p->MH.MAMH))
					{
						Msg(L"MH có SV ĐK,không th\u1EC3 xóa",-1);
						return;
					}
					if(MH_DELETE_INFO(ROOTTEMP,p->MH.MAMH))
					{
						MH_REMOVE_NODE(atoi(p->MH.MAMH),root);
						while(TC_SEARCH_INFO(p->MH.MAMH)!=-1)
						{
							TC_DELETE_ITEM(TC_SEARCH_INFO(p->MH.MAMH));
						}
						Msg(L"Xóa thành công!!",1);
					//ClearMenuFunTABLE();
						MH_SAVENEWFILE();
						TC_SAVEFILE();
						Msg(L"Lưu môn học thành công!!",1);
						return;	
					}
					else
					{
						Msg(L"Xóa thất bại!!!",-1);
					}
				}
						
			}/*end DEL*/
		}
		else if (select==F2)/*chinh sua 1 mon hoc*/
		{
			
			string TENMH="";
			int STCLT =0,STCTH=0;
			int flag[3]={0,0,0};
			int moveedit = 1;
			MH_KHUNGEDITMH(MH_NEWCOT(),p);
			gotoxy(EDITSVX-13,EDITSVY+10);
			int curX=getX(),curY=getY();
			while(true)
			{
				int select1 = getch(),select_val1;
				if (select1 == 224)
				{
					select_val1=getch();
					if(select_val1==UP)
					{
						if (moveedit >1)
						{
							moveedit --;
						}else continue;
								
						gotoxy(EDITSVX-13,EDITSVY+6+moveedit*4);
						curX=getX();curY=getY();
					}
					else if(select_val1==DOWN)
					{
						if (moveedit <3)
						{
							moveedit ++;
						}else continue;
							
						gotoxy(EDITSVX-13,EDITSVY+6+moveedit*4);
						curX=getX();curY=getY();
					}

				}
				else if(select1==ENTER||select1== BACKSPACE)
				{
					for(int nI=0;nI<39;nI++)cout<<" ";
					gotoxy(EDITSVX-13,EDITSVY+6+moveedit*4);

					if (moveedit==1)
					{
						TENMH= inNameSTR(40);
						while(TENMH=="")
						{
										
							gotoxy(curX,curY);
							for(int nI=0;nI<40;nI++)cout<<" ";
							gotoxy(curX,curY);
													
							Msg(L"Tên môn học không th\u1EC3 tr\u1ED1ng!",-1);

							gotoxy(curX,curY);
									
							TENMH= inNameSTR(40);
						}
									
					}
					else if(moveedit==2)
					{
						inNum(&STCLT,2);
									
									
					}
					else if(moveedit==3)
					{
						inNum(&STCTH,2);
								
					}
					
					flag[moveedit-1]=1;
					gotoxy(curX,curY);
				}
				else if(select1==F4)
				{
							
					if (p==NULL) return;
					TREE q;
					for(q = ROOTTEMP;q!=NULL&&strcmp(q->MH.MAMH,p->MH.MAMH)!=0;q=q->right);
					char option = MsgYN(L"B\u1ea1n có mu\u1ed1n lưu MH v\u1eeba sửa?");
					if (option==YES)
					{
						if (flag[0]==1)
						{
							q->MH.TENMH = TENMH;
							p->MH.TENMH = TENMH;
						}
						if(flag[1]==1)
						{
							p->MH.STCLT = STCLT;
							q->MH.STCLT = STCLT;
						}
								
						if(flag[2]==1)
						{
							p->MH.STCTH = STCTH;
							q->MH.STCTH = STCTH;
						}
						MH_SAVENEWFILE();
						Msg(L"Lưu môn học thành công!!",1);
						return;		
					}
							
				}
				else if(select1==ESC) break;
			}break;
		}else if(select==ESC) break;
	}
}
TREE MH_SEARCH_NODE (TREE root, int x)
{
	if(MH_EMPTY(root)) return NULL;
	TREE p;
	p = root;
	while (p != NULL && atoi(p->MH.MAMH) !=x)
	if(x < atoi(p->MH.MAMH))
	p = p->left;
	else
	p = p->right;
	return(p);
}

TREE MH_SEARCH_MIN()
{
	TREE p = root;
	if (p==NULL)return p;
	while(p->left!=NULL)p=p->left;
	return p;
}

void MH_SELECTION_SORT(TREE &r)
{
	if(r==NULL)return; 
	TREE p, q, pmin;
	MONHOC min;
	for(p = r; p->right != NULL; p = p->right)
	{ 
		min = p->MH;
		pmin = p;
		for(q = p->right; q != NULL; q = q->right)
		if(strcmp(str_2_char(q->MH.TENMH),str_2_char(min.TENMH))<0 )
		{
			min = q->MH;
			pmin = q;
		}
// hoan doi truong info cua hai nut p va pmin
		pmin->MH = p->MH;
		p->MH = min;
	}
}


/*==========================================================================*/
/*================================END XULY MONHOC   ========================*/
/*==========================================================================*/



/*==========================================================================*/
/*=======================Phan xu ly LOPTC    ===============================*/
/*==========================================================================*/
void TC_Init()
{
	ifstream file;
	int soluongsinhvien =0;
	file.open("DATA\\LOP\\listTC.data");
	SVDANGKY x;
	if (!file.is_open())
	{
		string DATA = "0";
		char filelist[] = "DATA\\LOP\\listTC.data";
		
		CREATFILE(filelist,&DATA);
		TiengViet(L"File không t\u1ed3n tại");
		return;
	}
	file>>LISTTC.SOLUONG;
	for(int i=0;i<LISTTC.SOLUONG;i++)
	{
		soluongsinhvien= 0;
		LISTTC.LOP[i]=TC_CREATNEWCLASS();
		file>>LISTTC.LOP[i]->MALOPTC>>LISTTC.LOP[i]->MAMH>>LISTTC.LOP[i]->KHOA>>LISTTC.LOP[i]->HOCKY>>LISTTC.LOP[i]->NHOM>>LISTTC.LOP[i]->MAXSV;
		string filename ="DATA\\LOP\\";
		filename = filename + i_to_string(LISTTC.LOP[i]->MALOPTC)+".in";
		char *newfile;
		newfile = new char[filename.length()];
		newfile = str_2_char(filename,filename.length());
	
		ifstream loadfile;
		loadfile.open(newfile);
		if(!loadfile.is_open())
		{
			string DATA = "0";
			CREATFILE(newfile,&DATA);
		}
		loadfile >>soluongsinhvien;
		if (soluongsinhvien==0)
		{
			loadfile.close();
			delete []newfile;
			continue;
		}
		DK_CLEARLIST(LISTTC.LOP[i]->SV);
		delete []newfile;
		for(int j=0;j<soluongsinhvien;j++)
		{
			loadfile >>x.MASV >> x.DIEM;
			
			if(LISTTC.LOP[i]->SV==NULL)
			{
				DIEM_INSERT_FIRST(LISTTC.LOP[i]->SV,x);
			}
			else
			{
				DIEM_INSERT_AFTER(LISTTC.LOP[i]->SV,x);
			}
		}
		loadfile.close();
		DIEM_SELECTION_SORT(LISTTC.LOP[i]->SV);
	}
	file.close();
	TC_QUICK_SORT(LISTTC);
}


bool TC_CHECKEXIT(LOPTINCHI *p)
{
	if (LISTTC.SOLUONG==0) return false;
	for(int i=0;i<LISTTC.SOLUONG;i++)
	{
		if(strcmp(p->MAMH,LISTTC.LOP[i]->MAMH)==0 && p->KHOA==LISTTC.LOP[i]->KHOA&&p->HOCKY==LISTTC.LOP[i]->HOCKY&&p->NHOM==LISTTC.LOP[i]->NHOM)
		return true;
	}
	return false;
}
bool TC_CHECKEXITEX(LOPTINCHI *p,int q)
{
	if (LISTTC.SOLUONG==0) return false;
	for(int i=0;i<LISTTC.SOLUONG;i++)
	{
		if (i!=q)
		if(strcmp(p->MAMH,LISTTC.LOP[i]->MAMH)==0 && p->KHOA==LISTTC.LOP[i]->KHOA&&p->HOCKY==LISTTC.LOP[i]->HOCKY&&p->NHOM==LISTTC.LOP[i]->NHOM)
		return true;
	}
	return false;
}
LOPTINCHI *TC_CREATNEWCLASS()
{
	LOPTINCHI *p;
	p=new LOPTINCHI;
	p->HOCKY =0;
	p->KHOA = 0;
	p->MALOPTC = 0;
	strcpy(p->MAMH,"");
	p->MAXSV=0;
	p->NHOM =0;
	p->SV = NULL;
	return p;
}
MAXCOT DIEM_NEWCOT(int type)
{
	MAXCOT NEWCOT;
	NEWCOT.SOLUONGCOT = 5;
	for(int i=0;i<NEWCOT.SOLUONGCOT;i++)
	{
		NEWCOT.INFOCOT[i] = new COT;
	}
	NEWCOT.INFOCOT[0]->WCOT = 7;
	NEWCOT.INFOCOT[0]->TENCOT = L"STT";
	NEWCOT.INFOCOT[1]->WCOT = 20;
	NEWCOT.INFOCOT[1]->TENCOT = L"Mã sinh viên";
	NEWCOT.INFOCOT[2]->WCOT = 45;
	NEWCOT.INFOCOT[2]->TENCOT = L"Họ";
	NEWCOT.INFOCOT[3]->WCOT = 30;
	NEWCOT.INFOCOT[3]->TENCOT = L"Tên";
	
	if (type==0)
	{
		NEWCOT.INFOCOT[4]->WCOT = 17;
		NEWCOT.INFOCOT[4]->TENCOT = L"\u0110i\u1EC3m";
	}
	
	else
	{
		NEWCOT.INFOCOT[4]->WCOT = 16;
		NEWCOT.INFOCOT[4]->TENCOT = L"\u0110i\u1EC3m TB";
	}
	
	return NEWCOT;
}
MAXCOT DIEM_NEWCOTINFO()
{
	MAXCOT NEWCOT;
	NEWCOT.SOLUONGCOT = 5;
	for(int i=0;i<NEWCOT.SOLUONGCOT;i++)
	{
		NEWCOT.INFOCOT[i] = new COT;
	}
	NEWCOT.INFOCOT[0]->WCOT = 7;
	NEWCOT.INFOCOT[0]->TENCOT = L"STT";
	NEWCOT.INFOCOT[1]->WCOT = 20;
	NEWCOT.INFOCOT[1]->TENCOT = L"Mã sinh viên";
	NEWCOT.INFOCOT[2]->WCOT = 45;
	NEWCOT.INFOCOT[2]->TENCOT = L"Họ";
	NEWCOT.INFOCOT[3]->WCOT = 30;
	NEWCOT.INFOCOT[3]->TENCOT = L"Tên";
	NEWCOT.INFOCOT[4]->WCOT = 17;
	NEWCOT.INFOCOT[4]->TENCOT = L"L\u1EDBp";
	return NEWCOT;
}
MAXCOT TK_NEWCOT()
{
	MAXCOT NEWCOT;
	NEWCOT.SOLUONGCOT = 9;
	for(int i=0;i<NEWCOT.SOLUONGCOT;i++)
	{
		NEWCOT.INFOCOT[i] = new COT;
	}
	NEWCOT.INFOCOT[0]->WCOT = 5;
	NEWCOT.INFOCOT[0]->TENCOT = L"STT";
	NEWCOT.INFOCOT[1]->WCOT = 15;
	NEWCOT.INFOCOT[1]->TENCOT = L"Mã sinh viên";
	NEWCOT.INFOCOT[2]->WCOT = 40;
	NEWCOT.INFOCOT[2]->TENCOT = L"Họ Tên";
	for(int i=3;i<=8;i++)
	{
	NEWCOT.INFOCOT[i]->WCOT = 9;
	NEWCOT.INFOCOT[i]->TENCOT = L"Mã     ";	
	}
	
	
	return NEWCOT;
}

MAXCOT TC_NEWCOT()
{
	MAXCOT NEWCOT;
	NEWCOT.SOLUONGCOT = 9;
	for(int i=0;i<NEWCOT.SOLUONGCOT;i++)
	{
		NEWCOT.INFOCOT[i] = new COT;
	}
	NEWCOT.INFOCOT[0]->WCOT = 5;
	NEWCOT.INFOCOT[0]->TENCOT = L"STT";
	NEWCOT.INFOCOT[1]->WCOT = 8;
	NEWCOT.INFOCOT[1]->TENCOT = L"Mã l\u1EDBp";

	NEWCOT.INFOCOT[2]->WCOT = 13;
	NEWCOT.INFOCOT[2]->TENCOT = L"Mã môn học";
	NEWCOT.INFOCOT[3]->WCOT = 42;
	NEWCOT.INFOCOT[3]->TENCOT = L"Tên môn học";
	NEWCOT.INFOCOT[4]->WCOT = 8;
	NEWCOT.INFOCOT[4]->TENCOT = L"Khóa";
	NEWCOT.INFOCOT[5]->WCOT = 8;
	NEWCOT.INFOCOT[5]->TENCOT = L"Học kì";
	NEWCOT.INFOCOT[6]->WCOT = 8;
	NEWCOT.INFOCOT[6]->TENCOT = L"Nhóm";
	NEWCOT.INFOCOT[7]->WCOT = 14;
	NEWCOT.INFOCOT[7]->TENCOT = L"SV t\u1ED1i \u0111a";
	NEWCOT.INFOCOT[8]->WCOT = 9;
	NEWCOT.INFOCOT[8]->TENCOT = L"Còn lại";

	return NEWCOT;
}
void TC_KHUNGEDITTC(MAXCOT NEWCOT,LOPTINCHI p,int type)/*Ve khung chinh sua sinh vien*/
{
	Color(COLORKHUNG);
	char firstchar,midchar,lastchar ;
	for(int i=0;i<EDITSVH+4;i++)
	{
		gotoxy(EDITSVX-EDITSVW/2,EDITSVY+i-POSTC);
		if (i==0)
		{
			firstchar = char(topchar);
			midchar = char(topchar);
			lastchar = char(topchar);
		}
		else if(i==EDITSVH+3)
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
		for(int j=1;j<EDITSVW-1;j++)
		{
			cout << midchar;
		}
		cout << lastchar<<endl;
	
	}
	Color(COLORDEFAUL);
	gotoxy(EDITSVX-8,EDITSVY+2-POSTC);
	Color(COLORTITLETEXT);
	if(type==0)
	TiengViet(L"  S\u1EECA L\u1EDAP TÍN CH\u1EC8  ");
	else
	TiengViet(L"  XEM L\u1EDAP T\u00CDN CH\u1EC8  ");
	Color(COLORDEFAUL);
	for(int i = 1;i<NEWCOT.SOLUONGCOT-1;i++)
	{
		
		gotoxy(EDITSVX-14,EDITSVY+1+4*i-POSTC);
		cout<<char(218);for(int j=1;j<INPUTEDITW;j++)cout<<char(196);cout<<char(191);
		gotoxy(EDITSVX-15-wcslen(NEWCOT.INFOCOT[i]->TENCOT),EDITSVY+2+4*i-POSTC);
		TiengViet(NEWCOT.INFOCOT[i]->TENCOT);
		cout << ' ';
		cout<<char(179);for(int j=1;j<INPUTEDITW;j++)cout<<' ';cout<<char(179);
		gotoxy(EDITSVX-14,EDITSVY+3+4*i-POSTC);
		cout<<char(192);for(int j=1;j<INPUTEDITW;j++)cout<<char(196);cout<<char(217);
		gotoxy(EDITSVX-13,EDITSVY+2+4*i-POSTC);
		if (i==1)
		{
			Color(COLORDISABLE);
			cout<< p.MALOPTC;
			Color(COLORDEFAUL);
		}
		
		else if (i==2)
		{
			Color(COLORDISABLE);
			cout<< p.MAMH;
			Color(COLORDEFAUL);
		}
		
		else if (i==3)
		{
			Color(COLORDISABLE);
			cout<< MH_SEARCH_NODE(root,atoi(p.MAMH))->MH.TENMH;
			Color(COLORDEFAUL);
		}
		
		else if (i==4)
		{
			if(type!=0)
			Color(COLORDISABLE);
			cout<< p.KHOA;
			Color(COLORDEFAUL);
		}
		
		else if (i==5)
		{
			if(type!=0)
			Color(COLORDISABLE);
			cout<< p.HOCKY;
			Color(COLORDEFAUL);
		}
		
		else if (i==6)
		{
			if(type!=0)
			Color(COLORDISABLE);
			cout<< p.NHOM;
			Color(COLORDEFAUL);
		}
		
		else if (i==7)
		{
			if(type!=0)
			Color(COLORDISABLE);
			cout<< p.MAXSV;
			Color(COLORDEFAUL);
		}
		

	}


}
void TC_KHUNGADD(MAXCOT NEWCOT)/*Ve khung Nhap TC*/
{
	Color(COLORKHUNG);
	char firstchar,midchar,lastchar ;
	for(int i=0;i<EDITSVH+4;i++)
	{
		gotoxy(EDITSVX-EDITSVW/2,EDITSVY+i-POSTC);
		if (i==0)
		{
			firstchar = char(topchar);
			midchar = char(topchar);
			lastchar = char(topchar);
		}
		else if(i==EDITSVH+3)
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
		for(int j=1;j<EDITSVW-1;j++)
		{
			cout << midchar;
		}
		cout << lastchar<<endl;
	
	}
	Color(COLORDEFAUL);
	gotoxy(EDITSVX-8,EDITSVY+2-POSTC);
	Color(COLORTITLETEXT);
	TiengViet(L"  NHẬP L\u1EDAP TÍN CH\u1EC8  ");
	Color(COLORDEFAUL);
	for(int i = 1;i<NEWCOT.SOLUONGCOT-1;i++)
	{
		
		gotoxy(EDITSVX-14,EDITSVY+1+4*i-POSTC);
		cout<<char(218);for(int j=1;j<INPUTEDITW;j++)cout<<char(196);cout<<char(191);
		gotoxy(EDITSVX-15-wcslen(NEWCOT.INFOCOT[i]->TENCOT),EDITSVY+2+4*i-POSTC);
		TiengViet(NEWCOT.INFOCOT[i]->TENCOT);
		cout << ' ';
		cout<<char(179);for(int j=1;j<INPUTEDITW;j++)cout<<' ';cout<<char(179);
		gotoxy(EDITSVX-14,EDITSVY+3+4*i-POSTC);
		cout<<char(192);for(int j=1;j<INPUTEDITW;j++)cout<<char(196);cout<<char(217);
		gotoxy(EDITSVX-13,EDITSVY+2+4*i-POSTC);
		
	}
	

}
void TC_PRINTINFODETAIL(int sodong,int *p,int curentpage,int x,int y,int type)
{

	DRAWTABLE(sodong,TC_NEWCOT());
	if (sodong-1 > NUMLINETABLE)
		sodong = NUMLINETABLE +1;
	gotoxy(x,y);
	int currentx,currenty;
	for (int i=0;i<sodong-1;i++)
	{

			
		gotoxy(x,y+i*2);
		if(*p>=0&&*p<LISTTC.SOLUONG)
		{
			for (int j=0;j<TC_NEWCOT().SOLUONGCOT;j++)
			{
				currentx=getX();
				currenty=getY();
				switch (j)
				{
					case 0:
					{
						gotoxy(getX()+2,getY());
						if(type==3||type==4)
						{
							if(i==0)
							{
							Color(COLORSELECT);
							TiengViet(SELECTPOITER);
							Color(COLORDEFAUL);	
							}

						}
						else if(type==6)
						{
							if(*p==0&&curentpage==1)
							{
								gotoxy(getX()-1,getY());
								Color(COLORSELECT);
								TiengViet(SELECTPOITER);
								Color(COLORDEFAUL);
								if (DANGKYMON[*p])
								{
									Color(COLORSELECT);
									TiengViet(CHECKEDBOX);
									Color(COLORDEFAUL);
								}
								else
								{
									Color(COLORSELECT);
									TiengViet(UNCHECKBOX);
									Color(COLORDEFAUL);
								}
							}
							else
							
							if (DANGKYMON[*p])
							{
								if (MONCODIEM[*p])
								{
									Color(COLORIMPORTANT);
									TiengViet(CHECKEDBOX);
									Color(COLORDEFAUL);	
								}else
								{
									
								TiengViet(CHECKEDBOX);
											
								}
							}
							else
							TiengViet(UNCHECKBOX);
						}
						else if(type==5)
						{
							
							if (DANGKYMON[*p])
							{
								if (MONCODIEM[*p])
								{
									Color(COLORIMPORTANT);
									TiengViet(CHECKEDBOX);
									Color(COLORDEFAUL);	
								}else
								{
									
								TiengViet(CHECKEDBOX);
								
								}
							}
							else
							TiengViet(UNCHECKBOX);
						}
						else if(type==DEFAULT)
						{
						}
						else if(type == PRINT)
						cout<< (curentpage-1)*NUMLINETABLE+i+1;
						gotoxy(getX()-2,getY());
					}
		
					break;
					case 1:
					cout<< LISTTC.LOP[*p]->MALOPTC;
					break;
					case 2:
					cout<< LISTTC.LOP[*p]->MAMH;
					break;
					case 3:
					cout<< MH_SEARCH_NODE(root,atoi(LISTTC.LOP[*p]->MAMH))->MH.TENMH;
					break;
					case 4:
					cout<< LISTTC.LOP[*p]->KHOA;
					break;
					case 5:
					cout<< LISTTC.LOP[*p]->HOCKY;
					break;
					case 6:
					cout<< LISTTC.LOP[*p]->NHOM;
					break;
					case 7:
					cout<< LISTTC.LOP[*p]->MAXSV;
					break;
					case 8:
						{
							if (LISTTC.LOP[*p]->MAXSV-DK_LOADNUMOFTC(*p)<=0)
							{
								Color(COLORTEXTALERT);
								cout<< LISTTC.LOP[*p]->MAXSV-DK_LOADNUMOFTC(*p);
								Color(COLORDEFAUL);
							}
							else
							cout<< LISTTC.LOP[*p]->MAXSV-DK_LOADNUMOFTC(*p);
							
						}
					
					break;

			
				}
				gotoxy(currentx+TC_NEWCOT().INFOCOT[j]->WCOT+1,currenty);
	
			
			}
		}
			
		(*p)++;
		if (*p<0||*p>=LISTTC.SOLUONG)break;
			
			
	}/*end for*/gotoMenuEX();
}
void TC_PRINTINFO(int type)
{
	ClearDetailTable();
	if(type==5||type==6)
	{
		if(type==5)
		{
			MsgSearch(L"Nh\u1EADp m\u00E3 sinh vi\u00EAn \u0111\u0103ng k\u00FD");
			char MSSV[15]="";
			inCHUSO(MSSV,'U',15);
			LISTSV p = NULL;
			p = SV_SEARCH_INFO_MSSV(FIRSTSV,(string)MSSV);
			while(p == NULL)
			{
				if(strcmp(MSSV,"")==0)
				{
					Msg(L"Tho\u00E1t \u0111\u0103ng k\u00FD m\u00F4n h\u1ECDc!",1);
					return;
				}
				Msg(L"M\u00E3 sinh vi\u00EAn kh\u00F4ng t\u1ED3n t\u1EA1i!",-1);
				MsgSearch(L"Nh\u1EADp m\u00E3 sinh vi\u00EAn \u0111\u0103ng k\u00FD");
				strcpy(MSSV,"");
				inCHUSO(MSSV,'U',15);
				p = SV_SEARCH_INFO_MSSV(FIRSTSV,(string)MSSV);		
			}
			SESSIONUSER = (string)MSSV;
		}
		DK_Init(SESSIONUSER);
	}
	if(SV_SEARCH_INFO_MSSV(FIRSTSV,SESSIONUSER)!=NULL)
	{
		gotoxy(MIDTABLE-6-SV_SEARCH_INFO_MSSV(FIRSTSV,SESSIONUSER)->SV.HO.length()/2-SV_SEARCH_INFO_MSSV(FIRSTSV,SESSIONUSER)->SV.TEN.length()/2,4);
		TiengViet(L"H\u1ECD v\u00E0 t\u00EAn: ");
		cout << SV_SEARCH_INFO_MSSV(FIRSTSV,SESSIONUSER)->SV.HO<<" "<<SV_SEARCH_INFO_MSSV(FIRSTSV,SESSIONUSER)->SV.TEN;
		gotoxy(MIDTABLE-20,6);
		TiengViet(L"M\u00E3 sinh vi\u00EAn: ");
		cout << SV_SEARCH_INFO_MSSV(FIRSTSV,SESSIONUSER)->SV.MASV;
		gotoxy(MIDTABLE+10,6);
		TiengViet(L"L\u1EDBp: ");
		cout <<SV_SEARCH_INFO_MSSV(FIRSTSV,SESSIONUSER)->SV.MALOP;
	}
	
	int sodong = LISTTC.SOLUONG;
	if(sodong==0) 
	{
		Msg(L"Không có l\u1EDBp tín ch\u1EC9!",-1);
		return;
	}
	
	int TOTALNUM = sodong;
	int MAXPAGE = (int)ceil((double)sodong/NUMLINETABLE);
	int curentpage = 1,cureditpage=1;
	int mod = sodong % NUMLINETABLE;
	gotoMenuFun();
	const int x=getX()+3,y = getY()+4+NUMLINETITLE;
	int currentx,currenty;
	gotoxy(x,y);

	if(type==3)/*XEM va xoa lop tin chi*/
	{
			
		int edit=1,editold=0,moveedit=1;
		int p = 0;
		if(p<0||p>=LISTTC.SOLUONG) return;
		TC_PRINTINFODETAIL(sodong+1,&p,cureditpage,x,y,type);
		int select;
		while(true)
		{
			select = getch();
			if (select == 224)
			{
				int select_val = getch();
				
				if (select_val==UP)
				{
				
		
					if (edit>1)
					{
						edit--;
						editold = 1;
					}else continue;
					if (edit %NUMLINETABLE==0 )
					{
						
						cureditpage--;sodong = NUMLINETABLE;
						p = 0;
						if(p<0||p>=LISTTC.SOLUONG) return;
						if (cureditpage!= 1)
						{
		
							for(p=0;p<NUMLINETABLE*(cureditpage-1);p++);
							
						
						}
						if(p<0||p>=LISTTC.SOLUONG) return;
						TC_PRINTINFODETAIL(sodong+1,&p,cureditpage,x,y,DEFAULT);
					}
					gotoxy(x+2,y+((edit-1)%NUMLINETABLE+editold)*2);
					cout << " ";
					gotoxy(x+2,y+((edit-1)%NUMLINETABLE)*2);
					Color(COLORSELECT);
					TiengViet(SELECTPOITER);
					Color(COLORDEFAUL);	gotoMenuEX();
				}
				else if (select_val==DOWN)
				{
					if (edit<TOTALNUM)
					{
						edit++;
						editold = -1;
					}else continue;
					if (edit %NUMLINETABLE==1 )
					{
						if (edit > NUMLINETABLE)
						{
						cureditpage++;editold=0;	
						}
						if(cureditpage < MAXPAGE)
						{
							sodong = NUMLINETABLE;
						}else
						{
							if (mod!=0)
							sodong = mod;
						}
					
						
						if(p<0||p>=LISTTC.SOLUONG) return;
						TC_PRINTINFODETAIL(sodong+1,&p,cureditpage,x,y,type);
					}
					gotoxy(x+2,y+((edit-1)%NUMLINETABLE+editold)*2);
					cout << " ";
					gotoxy(x+2,y+((edit-1)%NUMLINETABLE)*2);
					Color(COLORSELECT);
					TiengViet(SELECTPOITER);
					Color(COLORDEFAUL);	gotoMenuEX();
				}
				else if (select_val==DEL)/*Xoa phan tu*/
				{
					if (LISTTC.LOP[edit-1]->SV!=NULL)
					{
						Msg(L"L\u1EDBp có SV,không th\u1EC3 xóa!!",-1);
						continue;
					}
					char option = MsgYN(L"B\u1ea1n có mu\u1ed1n xóa l\u1EDBp này?");
					if (option == YES)
					{
						p = 0;
						if(p<0||p>=LISTTC.SOLUONG) return;
						for(p=0;p<edit-1;p++);
						if(p<0||p>=LISTTC.SOLUONG) return;
						if (LISTTC.LOP[p]->SV!=NULL)
						{
							Msg(L"L\u1EDBp có SV,không th\u1EC3 xóa!!",-1);
						 
						}else
						{
							if (TC_DELETE_ITEM (p))
							{
							
							Msg(L"Xóa thành công!!",1);
							
							if(edit>1){edit--;editold=1;}
							if(edit%NUMLINETABLE==0&&cureditpage>1)cureditpage--; 
							
							TOTALNUM--;
							TC_SAVEFILE();
							Msg(L"Sửa l\u1EDBp tín ch\u1EC9 thành công",1)	;
							}
							else
							{
								Msg(L"Xóa thất bại!!",-1);
							}
		
						}
							
					
					}
					
					for(p=0;p<(cureditpage-1)*NUMLINETABLE;p++);
					if (TOTALNUM==0)
					{
						TC_SAVEFILE();
						return;	
					}
					
					MAXPAGE = (int)ceil((double)TOTALNUM/NUMLINETABLE);
					mod = TOTALNUM % NUMLINETABLE;
					if (cureditpage < MAXPAGE||mod==0)
					sodong = NUMLINETABLE;
					else
					sodong = mod;
					TC_PRINTINFODETAIL(sodong+1,&p,cureditpage,x,y,DEFAULT);
					gotoxy(x+2,y+((edit-1)%NUMLINETABLE+editold)*2);
					cout << " ";
					gotoxy(x+2,y+((edit-1)%NUMLINETABLE)*2);
					Color(COLORSELECT);
					TiengViet(SELECTPOITER);
					Color(COLORDEFAUL);	gotoMenuEX();
				
				}
		
				
				
			}
			else if (select==F2)/*chinh sua lop tin chi*/
			{		
				
				moveedit = 1;
				for(p=0;p<edit-1;p++);

				if(p<0||p>=LISTTC.SOLUONG) return;
				TC_KHUNGEDITTC(TC_NEWCOT(),*LISTTC.LOP[p]);
				LOPTINCHI pcheck= *LISTTC.LOP[p];
				gotoxy(EDITSVX-13,EDITSVY+13);
				int curX=getX(),curY=getY();
				int check = 0;
				while(true)
				{
							
					if (check)
					{
						if(TC_CHECKEXITEX(&pcheck,p))
						{
							Msg(L"L\u1EDBp này \u0111\u00E3 t\u1ED3n tại",-1);
							gotoxy(EDITSVX-13,EDITSVY+9+moveedit*4);
						}
						else
						{
							break;
						}
					}
					check =0;
					int select1 = getch(),select_val1;
					if (select1 == 224)
					{
						select_val1=getch();
						if(select_val1==UP)
						{
							if (moveedit >1)
							{
								moveedit --;
							}else continue;
			
							gotoxy(EDITSVX-13,EDITSVY+9+moveedit*4);
							curX=getX();curY=getY();
						}
						else if(select_val1==DOWN)
						{
							if (moveedit <4)
							{
								moveedit ++;
							}else continue;
						
							gotoxy(EDITSVX-13,EDITSVY+9+moveedit*4);
							curX=getX();curY=getY();
						}
		
					}
					else if(select1== BACKSPACE)
					{
						for(int nI=0;nI<15;nI++)cout<<" ";
						gotoxy(EDITSVX-13,EDITSVY+9+moveedit*4);
		
						if (moveedit==1)
						{
								
							inNumUS(&pcheck.KHOA,4);
							while(pcheck.KHOA==0||TC_CHECKEXITEX(&pcheck,p))
							{
								if(pcheck.KHOA==0)
								{
									Msg(L"Xin hãy nhập niên khóa!!",-1);
									inNumUS(&pcheck.KHOA,4);
								}
								if(TC_CHECKEXITEX(&pcheck,p))
								{
									gotoxy(EDITSVX-13,EDITSVY+9+moveedit*4);
									for(int nI=0;nI<15;nI++)cout<<" ";
									gotoxy(EDITSVX-13,EDITSVY+9+moveedit*4);
									Msg(L"L\u1EDBp này \u0111\u00E3 t\u1ED3n tại!!",-1);
									inNumUS(&pcheck.KHOA,4);	
								}
												
							}
								
						}
						else if(moveedit==2)
						{
								
							inNumUS(&pcheck.HOCKY,1);
							while(pcheck.HOCKY==0||TC_CHECKEXITEX(&pcheck,p))
							{
								if(pcheck.HOCKY==0)
								{
									Msg(L"Xin hãy nhập học kỳ!!",-1);
									inNumUS(&pcheck.HOCKY,1);
								}
								if(TC_CHECKEXITEX(&pcheck,p))
								{
									gotoxy(EDITSVX-13,EDITSVY+9+moveedit*4);
									for(int nI=0;nI<15;nI++)cout<<" ";
									gotoxy(EDITSVX-13,EDITSVY+9+moveedit*4);
									Msg(L"L\u1EDBp này \u0111\u00E3 t\u1ED3n tại!!",-1);
									inNumUS(&pcheck.HOCKY,1);
								}
												
							}
								
						}
						else if(moveedit==3)
						{
								
							inNumUS(&pcheck.NHOM,2);
							while(pcheck.NHOM==0||TC_CHECKEXITEX(&pcheck,p))
							{
								
								if(pcheck.NHOM==0)
								{
									Msg(L"Xin hãy nhập s\u1ED1 nhóm!!",-1);
									inNumUS(&pcheck.NHOM,2);
								}
								if(TC_CHECKEXITEX(&pcheck,p))
								{
									gotoxy(EDITSVX-13,EDITSVY+9+moveedit*4);
									for(int nI=0;nI<15;nI++)cout<<" ";
									gotoxy(EDITSVX-13,EDITSVY+9+moveedit*4);
									Msg(L"L\u1EDBp này \u0111\u00E3 t\u1ED3n tại!!",-1);
									inNumUS(&pcheck.NHOM,2);
								}	
							}
							
						}
						else if(moveedit==4)
						{
							
							inNumUS(&pcheck.MAXSV,2);
							while(pcheck.MAXSV==0)
							{
								Msg(L"Xin hãy nhập s\u1ED1 sinh viên!!",-1);
								inNumUS(&pcheck.MAXSV,2);
								
							}
						
						}
						gotoxy(curX,curY);
		
					}
					else if(select1== ENTER)
					{
						check =1;	
					}
							
					else if(select1== F4)
					{
						if(TC_CHECKEXITEX(&pcheck,p))
						{
							Msg(L"L\u1EDBp này \u0111\u00E3 t\u1ED3n tại",-1);
							gotoxy(EDITSVX-13,EDITSVY+9+moveedit*4);
							return;
						}
						*LISTTC.LOP[p] = pcheck;
						TC_SAVEFILE();
						Msg(L"Sửa l\u1EDBp tín ch\u1EC9 thành công",1)	;
						break;
					}
					else if(select1==ESC) 
					{
						
						break;	
					}
				}
				ClearDetailTable();
				for(p=0;p<(cureditpage-1)*NUMLINETABLE;p++);
				TC_PRINTINFODETAIL(sodong+1,&p,cureditpage,x,y,DEFAULT);
				gotoxy(x+2,y+((edit-1)%NUMLINETABLE+editold)*2);
				cout << " ";
				gotoxy(x+2,y+((edit-1)%NUMLINETABLE)*2);
				Color(COLORSELECT);
				TiengViet(SELECTPOITER);
				Color(COLORDEFAUL);	gotoMenuEX();
			}
			else if(select==F3)
			{
				TC_SEARCH();
				ClearDetailTable();
				for(p=0;p<(cureditpage-1)*NUMLINETABLE;p++);
				TOTALNUM = LISTTC.SOLUONG;
				MAXPAGE = (int)ceil((double)TOTALNUM/NUMLINETABLE);
					mod = TOTALNUM % NUMLINETABLE;
					if (cureditpage < MAXPAGE||mod==0)
					sodong = NUMLINETABLE;
					else
					sodong = mod;
					TC_PRINTINFODETAIL(sodong+1,&p,cureditpage,x,y,DEFAULT);
					gotoxy(x+2,y+((edit-1)%NUMLINETABLE+editold)*2);
					cout << " ";
					gotoxy(x+2,y+((edit-1)%NUMLINETABLE)*2);
					Color(COLORSELECT);
					TiengViet(SELECTPOITER);
					Color(COLORDEFAUL);	gotoMenuEX();
			}
			else if (select==F4)/*Luu*/
			{
				char option = MsgYN(L"B\u1ea1n có mu\u1ed1n lưu những thay \u0111\u1ED5i?");
				if (option==YES)
				{
					TC_SAVEFILE();
				}
				else
				{
					TC_Init();
				}	
				
				Msg(L"Thoát sửa l\u1EDBp tín ch\u1EC9!",1);
				break;
			}
			else if(select==ESC) break;
			
		}
			
	}
	else if (type==5)/*dang ky mon hoc Admin*/
	{
			
		int edit=1,editold=0,moveedit=1;
		int p = 0;
		if(p<0||p>=LISTTC.SOLUONG) return;
		TC_PRINTINFODETAIL(sodong+1,&p,cureditpage,x,y,6);
		int select ;
		int check =0;
		while(true)
		{
			select = getch();
			if (select == 224)
			{
				int select_val = getch();
				
				if (select_val==UP)
				{
				
					if (edit>1)
					{
						edit--;
						editold = 1;
					}else continue;
					if (edit %NUMLINETABLE==0 )
					{
						
						cureditpage--;sodong = NUMLINETABLE;editold=0;	
						p = 0;
						if(p<0||p>=LISTTC.SOLUONG) return;
						if (cureditpage!= 1)
						{
		
							for(p=0;p<(cureditpage-1)*NUMLINETABLE;p++);
						
						}
						if(p<0||p>=LISTTC.SOLUONG) return;
						TC_PRINTINFODETAIL(sodong+1,&p,cureditpage,x,y,type);
					}
					gotoxy(x+1,y+((edit-1)%NUMLINETABLE+editold)*2);cout << " ";
					if (DANGKYMON[edit-1+editold]==0)
					{
					
						TiengViet(UNCHECKBOX);
				
					}
					else
					{
				
						if (MONCODIEM[edit-1+editold])
						{
							Color(COLORIMPORTANT);
							TiengViet(CHECKEDBOX);
							Color(COLORDEFAUL);	
						}else
						{
							
						TiengViet(CHECKEDBOX);
										
						}
					
					
					}
					gotoxy(x+1,y+((edit-1)%NUMLINETABLE)*2);
					Color(COLORSELECT);
					TiengViet(SELECTPOITER);
					Color(COLORDEFAUL);	
					if (DANGKYMON[edit-1]==0)
					{
						Color(COLORSELECT);
						TiengViet(UNCHECKBOX);
						Color(COLORDEFAUL);	gotoMenuEX();
					}
					else
					{
				
						
						Color(COLORSELECT);
						TiengViet(CHECKEDBOX);
						Color(COLORDEFAUL);	gotoMenuEX();
			
					}
				
				}
				else if (select_val==DOWN)
				{
					
					if (edit<TOTALNUM)
					{
						edit++;
						editold = -1;
					}else continue;
					if (edit %NUMLINETABLE==1 )
					{
						if (edit > NUMLINETABLE)
						{
						cureditpage++;editold=0;	
						}
						if(cureditpage < MAXPAGE)
						{
							sodong = NUMLINETABLE;
						}else
						{
							if (mod!=0)
							sodong = mod;
						}
						if(p<0||p>=LISTTC.SOLUONG) return;
						TC_PRINTINFODETAIL(sodong+1,&p,cureditpage,x,y,type);
					}
					gotoxy(x+1,y+((edit-1)%NUMLINETABLE+editold)*2);cout <<" ";
					
					if (DANGKYMON[edit-1+editold]==0)
					{
					
					TiengViet(UNCHECKBOX);
				
					}
					else
					{
				
						if (MONCODIEM[edit-1+editold])
						{
							Color(COLORIMPORTANT);
							TiengViet(CHECKEDBOX);
							Color(COLORDEFAUL);	
						}else
						{
							
							TiengViet(CHECKEDBOX);
							
						}
					
					
					}
					gotoxy(x+1,y+((edit-1)%NUMLINETABLE)*2);
					Color(COLORSELECT);
					TiengViet(SELECTPOITER);
					Color(COLORDEFAUL);	
					if (DANGKYMON[edit-1]==0)
					{
						Color(COLORSELECT);
						TiengViet(UNCHECKBOX);
						Color(COLORDEFAUL);	gotoMenuEX();
					}else
					{
				
					
						Color(COLORSELECT);
						TiengViet(CHECKEDBOX);
						Color(COLORDEFAUL);	gotoMenuEX();
			
					}
				}
			}
			else if (select==ENTER)/*In danh sach*/
			{
				if(DK_SEARCH_INFO_MSSV(LISTTC.LOP[edit-1]->SV,SESSIONUSER)&&DANGKYMON[edit-1])
				{
					if(DK_SEARCH_INFO_MSSV_p(LISTTC.LOP[edit-1]->SV,SESSIONUSER)->SV.DIEM !=-2)
					{
					Msg(L"Đã có \u0111i\u1EC3m,không th\u1EC3 hủy!!",-1);
					
					continue;	
					}
				}
				if (DK_CHECKDANGKYMON(LISTTC.LOP[edit-1]->MAMH)&&!DANGKYMON[edit-1] )
				{
					
					Msg(L"Bạn \u0111\u00E3 \u0111\u0103ng ký môn này r\u1ED3i!!",-1);
					
					continue;
				}
				else if(!DANGKYMON[edit-1]&&DK_LOADNUMOFTC(edit-1)>=LISTTC.LOP[edit-1]->MAXSV)
				{
					Msg(L"L\u1EDBp này \u0111\u00E3 \u0111ủ người!!",-1);
					
					continue;
				}
				
				gotoxy(x+2,y+((edit-1)%NUMLINETABLE)*2);	
				if (DANGKYMON[edit-1]==0)
				{
					DANGKYMON[edit-1]=1;
					Color(COLORCHECK);
					TiengViet(CHECKEDBOX);
					Color(COLORDEFAUL);	gotoMenuEX();
				}else
				{
					DANGKYMON[edit-1]=0;
					Color(COLORSELECT);
					TiengViet(UNCHECKBOX);
					Color(COLORDEFAUL);	gotoMenuEX();
				}
			}
			else if(select == F4)
			{
				SVDANGKY x;
				x.DIEM = -2;
				x.MASV = SESSIONUSER;
				for(int s=0;s<LISTTC.SOLUONG;s++)
				{
				   
				   if(DANGKYMON[s])
				   {
				   	if (!DK_SEARCH_INFO_MSSV(LISTTC.LOP[s]->SV,SESSIONUSER))
				   	
				   	if(LISTTC.LOP[s]->SV==NULL)
				   	{
					 DIEM_INSERT_FIRST(LISTTC.LOP[s]->SV,x);
					 }
					 else
					 {
					 	DIEM_INSERT_AFTER(LISTTC.LOP[s]->SV,x);
					 }
				   	
					}
					else
					{
						if(DK_DELETE_INFO(LISTTC.LOP[s]->SV,x));
		
							
					}
					string DATA ="";
					int count = 0;
					
					for(DSDANGKY t=LISTTC.LOP[s]->SV;t!=NULL;t=t->next)
					{
						DATA = DATA + t->SV.MASV + "\t" +i_to_string(t->SV.DIEM) +"\n";
						count++;
					}
					
					DATA = i_to_string(count) + "\n" + DATA;
						
					/*Ghi vao file*/
					string filename ="DATA\\LOP\\";
					filename = filename + i_to_string(LISTTC.LOP[s]->MALOPTC)+".in";
					char *newfile;
					newfile = new char[filename.length()];
					newfile = str_2_char(filename,filename.length());
					CREATFILE(newfile,&DATA);
					delete []newfile;
				}
				Msg(L"\u0110\u0103ng kí thành công!!",1);
				SESSIONUSER = "";	
				break;
			}
			else if(select==ESC) 
			{
				SESSIONUSER = "";
				break;	
			}
		
		}
			
	}
	else if (type==6)
	{
			
		int edit=1,editold=0,moveedit=1;
		int p = 0;
		if(p<0||p>=LISTTC.SOLUONG) return;
		TC_PRINTINFODETAIL(sodong+1,&p,cureditpage,x,y,6);
		int select ;
		int check =0;
		while(true)
		{
			select = getch();
			if (select == 224)
			{
				int select_val = getch();
				
				if (select_val==UP)
				{
				
					if (edit>1)
					{
						edit--;
						editold = 1;
					}else continue;
					if (edit %NUMLINETABLE==0 )
					{
						
						cureditpage--;sodong = NUMLINETABLE;editold=0;	
						p = 0;
						if(p<0||p>=LISTTC.SOLUONG) return;
						if (cureditpage!= 1)
						{
		
							for(p=0;p<(cureditpage-1)*NUMLINETABLE;p++);
						
						}
						if(p<0||p>=LISTTC.SOLUONG) return;
						TC_PRINTINFODETAIL(sodong+1,&p,cureditpage,x,y,5);
					}
					gotoxy(x+1,y+((edit-1)%NUMLINETABLE+editold)*2);cout <<" ";
					if (DANGKYMON[edit-1+editold]==0)
					{
					
						TiengViet(UNCHECKBOX);
				
					}
					else
					{
				
						if (MONCODIEM[edit-1+editold])
						{
							Color(COLORIMPORTANT);
							TiengViet(CHECKEDBOX);
							Color(COLORDEFAUL);	
						}else
						{
							
						TiengViet(CHECKEDBOX);
										
						}
					
					
					}
					gotoxy(x+1,y+((edit-1)%NUMLINETABLE)*2);
					Color(COLORSELECT);
					TiengViet(SELECTPOITER);
					Color(COLORDEFAUL);	
					if (DANGKYMON[edit-1]==0)
					{
						Color(COLORSELECT);
						TiengViet(UNCHECKBOX);
						Color(COLORDEFAUL);	gotoMenuEX();
					}
					else
					{
				
						
						Color(COLORSELECT);
						TiengViet(CHECKEDBOX);
						Color(COLORDEFAUL);	gotoMenuEX();
			
					}
				
				}
				else if (select_val==DOWN)
				{
					
					if (edit<TOTALNUM)
					{
						edit++;
						editold = -1;
					}else continue;
					if (edit %NUMLINETABLE==1 )
					{
						if (edit > NUMLINETABLE)
						{
						cureditpage++;editold=0;	
						}
						if(cureditpage < MAXPAGE)
						{
							sodong = NUMLINETABLE;
						}else
						{
							if (mod!=0)
							sodong = mod;
						}
						if(p<0||p>=LISTTC.SOLUONG) return;
						TC_PRINTINFODETAIL(sodong+1,&p,cureditpage,x,y,5);
					}
					gotoxy(x+1,y+((edit-1)%NUMLINETABLE+editold)*2);cout<<" ";
					if (DANGKYMON[edit-1+editold]==0)
					{
					
					TiengViet(UNCHECKBOX);
				
					}
					else
					{
				
						if (MONCODIEM[edit-1+editold])
						{
							Color(COLORIMPORTANT);
							TiengViet(CHECKEDBOX);
							Color(COLORDEFAUL);	
						}else
						{
							
							TiengViet(CHECKEDBOX);
							
						}
					
					
					}
					gotoxy(x+1,y+((edit-1)%NUMLINETABLE)*2);
					Color(COLORSELECT);
					TiengViet(SELECTPOITER);
					Color(COLORDEFAUL);
					if (DANGKYMON[edit-1]==0)
					{
						Color(COLORSELECT);
						TiengViet(UNCHECKBOX);
						Color(COLORDEFAUL);	gotoMenuEX();
					}else
					{
				
					
						Color(COLORSELECT);
						TiengViet(CHECKEDBOX);
						Color(COLORDEFAUL);	gotoMenuEX();
			
					}
				}
			}
			else if (select==ENTER)/*In danh sach*/
			{
				if(DK_SEARCH_INFO_MSSV(LISTTC.LOP[edit-1]->SV,SESSIONUSER)&&DANGKYMON[edit-1])
				{
					if(DK_SEARCH_INFO_MSSV_p(LISTTC.LOP[edit-1]->SV,SESSIONUSER)->SV.DIEM !=-2)
					{
					Msg(L"Đã có \u0111i\u1EC3m,không th\u1EC3 hủy!!",-1);
					
					continue;	
					}
				}
				if (DK_CHECKDANGKYMON(LISTTC.LOP[edit-1]->MAMH)&&!DANGKYMON[edit-1] )
				{
					
					Msg(L"Bạn \u0111\u00E3 \u0111\u0103ng ký môn này r\u1ED3i!!",-1);
					
					continue;
				}
				else if(!DANGKYMON[edit-1]&&DK_LOADNUMOFTC(edit-1)>=LISTTC.LOP[edit-1]->MAXSV)
				{
					Msg(L"L\u1EDBp này \u0111\u00E3 \u0111ủ người!!",-1);
					
					continue;
				}
				
				gotoxy(x+2,y+((edit-1)%NUMLINETABLE)*2);	
				if (DANGKYMON[edit-1]==0)
				{
					DANGKYMON[edit-1]=1;
					Color(COLORCHECK);
					TiengViet(CHECKEDBOX);
					Color(COLORDEFAUL);	gotoMenuEX();
				}else
				{
					DANGKYMON[edit-1]=0;
					Color(COLORSELECT);
					TiengViet(UNCHECKBOX);
					Color(COLORDEFAUL);	gotoMenuEX();
				}
			}
			else if(select == F4)
			{
				SVDANGKY x;
				x.DIEM = -2;
				x.MASV = SESSIONUSER;
				for(int s=0;s<LISTTC.SOLUONG;s++)
				{
				   
				   if(DANGKYMON[s])
				   {
				   	if (!DK_SEARCH_INFO_MSSV(LISTTC.LOP[s]->SV,SESSIONUSER))
				   	
				   	if(LISTTC.LOP[s]->SV==NULL)
				   	{
					 DIEM_INSERT_FIRST(LISTTC.LOP[s]->SV,x);
					 }
					 else
					 {
					 	DIEM_INSERT_AFTER(LISTTC.LOP[s]->SV,x);
					 }
				   	
					}
					else
					{
						if(DK_DELETE_INFO(LISTTC.LOP[s]->SV,x));
		
							
					}
					string DATA ="";
					int count = 0;
					
					for(DSDANGKY t=LISTTC.LOP[s]->SV;t!=NULL;t=t->next)
					{
						DATA = DATA + t->SV.MASV + "\t" +i_to_string(t->SV.DIEM) +"\n";
						count++;
					}
					
					DATA = i_to_string(count) + "\n" + DATA;
						
					/*Ghi vao file*/
					string filename ="DATA\\LOP\\";
					filename = filename + i_to_string(LISTTC.LOP[s]->MALOPTC)+".in";
					char *newfile;
					newfile = new char[filename.length()];
					newfile = str_2_char(filename,filename.length());
					CREATFILE(newfile,&DATA);
					delete []newfile;
				}
				Msg(L"\u0110\u0103ng kí thành công!!",1);
			
				break;
			}
			else if(select==ESC) 
			{
				
				break;	
			}
	
		}
			
	}
	else/*IN danh sach sinh vien lop tin chi,sua diem,xem diem*/
					
	{
			
		int edit=1,editold=0,moveedit=1;
		int p = 0;
		if(p<0||p>=LISTTC.SOLUONG) return;
		TC_PRINTINFODETAIL(sodong+1,&p,cureditpage,x,y,3);
		int select ;
		while(true)
		{
			select = getch();
			if (select == 224)
			{
				int select_val = getch();
				
				if (select_val==UP)
				{
				
		
					if (edit>1)
					{
						edit--;
						editold = 1;
					}else continue;
					if (edit %NUMLINETABLE==0 )
					{
						
						cureditpage--;sodong = NUMLINETABLE;
						p = 0;
						if(p<0||p>=LISTTC.SOLUONG) return;
						if (cureditpage!= 1)
						{
		
							for(p=0;p<NUMLINETABLE*(cureditpage-1);p++);
							
						
						}
						if(p<0||p>=LISTTC.SOLUONG) return;
						TC_PRINTINFODETAIL(sodong+1,&p,cureditpage,x,y,DEFAULT);
					}
					gotoxy(x+2,y+((edit-1)%NUMLINETABLE+editold)*2);
					cout << " ";
					gotoxy(x+2,y+((edit-1)%NUMLINETABLE)*2);
					Color(COLORSELECT);
					TiengViet(SELECTPOITER);
					Color(COLORDEFAUL);	gotoMenuEX();
				}
				else if (select_val==DOWN)
				{
					
					if (edit<TOTALNUM)
					{
						edit++;
						editold = -1;
					}else continue;
					if (edit %NUMLINETABLE==1 )
					{
						if (edit > NUMLINETABLE)
						{
						cureditpage++;editold=0;	
						}
						if(cureditpage < MAXPAGE)
						{
							sodong = NUMLINETABLE;
						}else
						{
							if (mod!=0)
							sodong = mod;
						}
						if(p<0||p>=LISTTC.SOLUONG) return;
						TC_PRINTINFODETAIL(sodong+1,&p,cureditpage,x,y,3);
					}
					gotoxy(x+2,y+((edit-1)%NUMLINETABLE+editold)*2);
					cout << " ";
					gotoxy(x+2,y+((edit-1)%NUMLINETABLE)*2);
					Color(COLORSELECT);
					TiengViet(SELECTPOITER);
					Color(COLORDEFAUL);	gotoMenuEX();
			
				}
		
				
				
			}
			else if (select==ENTER)/*In danh sach*/
			{
				for(p=0;p<edit-1;p++);
			
				DK_LOADSOLUONGSV(p,type);
				ClearDetailTable();
				for(p=0;p<(cureditpage-1)*NUMLINETABLE;p++);
				if (cureditpage < MAXPAGE||mod==0)
				sodong = NUMLINETABLE;
				else
				sodong = mod;
				TC_PRINTINFODETAIL(sodong+1,&p,cureditpage,x,y,DEFAULT);
				gotoxy(x+2,y+((edit-1)%NUMLINETABLE+editold)*2);
				cout << " ";
				gotoxy(x+2,y+((edit-1)%NUMLINETABLE)*2);
				Color(COLORSELECT);
				TiengViet(SELECTPOITER);
				Color(COLORDEFAUL);	gotoMenuEX();
			}
			else if(select==ESC) break;
			
		}
			
	}/*end case 2*/
		
	
}
int TC_DELETE_ITEM (int i)
{
	int j;
	if(i < 0 || i >= LISTTC.SOLUONG || LISTTC.SOLUONG==0) return 0;
	for(j = i+1; j< LISTTC.SOLUONG ; j++)
		LISTTC.LOP[j-1] = LISTTC.LOP[j];
	LISTTC.SOLUONG--;
	return 1;
}
void TC_SEARCH()
{
	MsgSearch(L"Nh\u1EADp m\u00E3 l\u1EDBp t\u00EDn ch\u1EC9 c\u1EA7n t\u00ECm");
	int MALOPTC=0;
	inNum(&MALOPTC);
	int p = -1;
	p = TC_SEARCH_INFOMATC(MALOPTC);
	while(p == -1)
	{
		if(MALOPTC==0)
		{
			Msg(L"Tho\u00E1t t\u00ECm ki\u1EBFm!",1);
			return;
		}
		Msg(L"M\u00E3 l\u1EDBp t\u00EDn ch\u1EC9 kh\u00F4ng t\u1ED3n t\u1EA1i!",-1);
		MsgSearch(L"Nh\u1EADp m\u00E3 l\u1EDBp t\u00EDn ch\u1EC9 c\u1EA7n t\u00ECm");
		
		MALOPTC=0;
		inNum(&MALOPTC);
		p = TC_SEARCH_INFOMATC(MALOPTC);	
	}
	
	TC_KHUNGEDITTC(TC_NEWCOT(),*LISTTC.LOP[p],1);
	gotoMenuEX();
	while (true)
	{
		int select = getch();
		if (select == 224)
		{
			int select_val = getch();
			if (select_val==DEL)/*Xoa phan tu*/
			{
				if (DK_LOADNUMOFTC(p)>=1)
				{
					Msg(L"L\u1EDBp có SV,không th\u1EC3 xóa!!",-1);
					continue;
				}
				char option = MsgYN(L"B\u1ea1n có mu\u1ed1n xóa l\u1EDBp này?");
				if (option == YES)
				{
					if (p==-1) return;
					if (DK_LOADNUMOFTC(p)>=1)
					{
						Msg(L"L\u1EDBp có SV,không th\u1EC3 xóa!!",-1);
						 
					}else
					{
						if (TC_DELETE_ITEM (p))
						{
							
							Msg(L"Xóa thành công!!",1);
							LISTTC.SOLUONG--;
							TC_SAVEFILE();
							return;
						}
						else
						{
							Msg(L"Xóa thất bại!!",-1);
						}
		
					}
							
					
				}
			}/*end DEL*/
		}
		else if (select==F2)/*chinh sua 1 sinh vien*/
		{
			LOPTINCHI pcheck= *LISTTC.LOP[p];
			int moveedit = 1;

			if (p==-1) return;
			TC_KHUNGEDITTC(TC_NEWCOT(),*LISTTC.LOP[p]);
			gotoxy(EDITSVX-13,EDITSVY+13);
			int curX=getX(),curY=getY();
			
			while(true)
			{
				
				int select1 = getch(),select_val1;
				if (select1 == 224)
				{
					select_val1=getch();
					if(select_val1==UP)
					{
						if (moveedit >1)
						{
							moveedit --;
						}else continue;
			
						gotoxy(EDITSVX-13,EDITSVY+9+moveedit*4);
						curX=getX();curY=getY();
					}
					else if(select_val1==DOWN)
					{
						if (moveedit <4)
						{
							moveedit ++;
						}else continue;
						
						gotoxy(EDITSVX-13,EDITSVY+9+moveedit*4);
						curX=getX();curY=getY();
					}
		
				}
				else if(select1== BACKSPACE)
				{
					for(int nI=0;nI<15;nI++)cout<<" ";
					gotoxy(EDITSVX-13,EDITSVY+9+moveedit*4);
		
					if (moveedit==1)
					{
							
						inNumUS(&pcheck.KHOA,4);
						while(pcheck.KHOA==0||TC_CHECKEXITEX(&pcheck,p))
						{
							if(pcheck.KHOA==0)
							{
								Msg(L"Xin hãy nhập niên khóa!!",-1);
								inNumUS(&pcheck.KHOA,4);
							}
							if(TC_CHECKEXITEX(&pcheck,p))
							{
								gotoxy(EDITSVX-13,EDITSVY+9+moveedit*4);
								for(int nI=0;nI<15;nI++)cout<<" ";
								gotoxy(EDITSVX-13,EDITSVY+9+moveedit*4);
								Msg(L"L\u1EDBp này \u0111\u00E3 t\u1ED3n tại!!",-1);
								inNumUS(&pcheck.KHOA,4);	
							}
											
						}
							
					}
					else if(moveedit==2)
					{
							
						inNumUS(&pcheck.HOCKY,1);
						while(pcheck.HOCKY==0||TC_CHECKEXITEX(&pcheck,p))
						{
							if(pcheck.HOCKY==0)
							{
								Msg(L"Xin hãy nhập học kỳ!!",-1);
								inNumUS(&pcheck.HOCKY,1);
							}
							if(TC_CHECKEXITEX(&pcheck,p))
							{
								gotoxy(EDITSVX-13,EDITSVY+9+moveedit*4);
								for(int nI=0;nI<15;nI++)cout<<" ";
								gotoxy(EDITSVX-13,EDITSVY+9+moveedit*4);
								Msg(L"L\u1EDBp này \u0111\u00E3 t\u1ED3n tại!!",-1);
								inNumUS(&pcheck.HOCKY,1);
							}
											
						}
							
					}
					else if(moveedit==3)
					{
							
						inNumUS(&pcheck.NHOM,2);
						while(pcheck.NHOM==0||TC_CHECKEXITEX(&pcheck,p))
						{
							
							if(pcheck.NHOM==0)
							{
								Msg(L"Xin hãy nhập s\u1ED1 nhóm!!",-1);
								inNumUS(&pcheck.NHOM,2);
							}
							if(TC_CHECKEXITEX(&pcheck,p))
							{
								gotoxy(EDITSVX-13,EDITSVY+9+moveedit*4);
								for(int nI=0;nI<15;nI++)cout<<" ";
								gotoxy(EDITSVX-13,EDITSVY+9+moveedit*4);
								Msg(L"L\u1EDBp này \u0111\u00E3 t\u1ED3n tại!!",-1);
								inNumUS(&pcheck.NHOM,2);
							}	
						}
						
					}
					else if(moveedit==4)
					{
							
						inNumUS(&pcheck.MAXSV,3);
						while(&pcheck.MAXSV==0)
						{
							Msg(L"Xin hãy nhập s\u1ED1 sinh viên!!",-1);
							inNumUS(&pcheck.MAXSV,3);
							
						}
						
					}
					gotoxy(curX,curY);
		
				}
				
							
				else if(select1== F4)
				{
					if(TC_CHECKEXITEX(&pcheck,p))
					{
						Msg(L"L\u1EDBp này \u0111\u00E3 t\u1ED3n tại",-1);
						gotoxy(EDITSVX-13,EDITSVY+9+moveedit*4);
						return;
					}
					*LISTTC.LOP[p] = pcheck;
					Msg(L"Sửa l\u1EDBp tín ch\u1EC9 thành công",1)	;
					TC_SAVEFILE();
					return;
					
				}
				else if(select1==ESC) 
				{
						
					break;	
				}
			}break;
						
		}else if(select==ESC) break;
	}
}
int TC_SEARCH_INFO( char  *info)
{
	for ( int i =0 ; i <LISTTC.SOLUONG ; i++)
	if (strcmp(LISTTC.LOP[i]->MAMH , info)==0) return i;
	return -1;
}
int TC_SEARCH_INFOMATC( int  info)
{
	for ( int i =0 ; i <LISTTC.SOLUONG ; i++)
	if (LISTTC.LOP[i]->MALOPTC == info) return i;
	return -1;
}
int TC_CHECKSV(char *MAMH)
{
	for ( int i =0 ; i <LISTTC.SOLUONG ; i++)
	{
		if(strcmp(LISTTC.LOP[i]->MAMH,MAMH)==0)
		{
			if(LISTTC.LOP[i]->SV!=NULL) return 1;
		}
	}
	return 0;
}
int TC_SEARCH_MAXVAL()
{
	int max = 0;
	for ( int i =0 ; i <LISTTC.SOLUONG ; i++)
	if (max<LISTTC.LOP[i]->MALOPTC)
	 max=LISTTC.LOP[i]->MALOPTC;
	return max;
}
void TC_Insertion_sort(DSLOPTINCHI LISTTC)
{
	LOPTINCHI x;
	int i,j;
	for (i=0; i< LISTTC.SOLUONG; i++)
	{
		x = *LISTTC.LOP[i];
		for (j=i-1; j>=0 ; j--)
		{
			if(MH_SEARCH_NODE(root,atoi(LISTTC.LOP[j]->MAMH))->MH.TENMH.compare(MH_SEARCH_NODE(root,atoi(x.MAMH))->MH.TENMH)>0)
			*LISTTC.LOP[j+1]=*LISTTC.LOP[j];
			/*else if(MH_SEARCH_NODE(root,atoi(LISTTC.LOP[j]->MAMH))->MH.TENMH.compare(MH_SEARCH_NODE(root,atoi(x.MAMH))->MH.TENMH)==0)
			{
				if(LISTTC.LOP[j]->KHOA<x.KHOA)
				*LISTTC.LOP[j+1]=*LISTTC.LOP[j];
			}*/
		}
			
		*LISTTC.LOP[j+1]=x;
	}

}
void TC_QUICK_SORT_EX(DSLOPTINCHI LISTTC, int q,int r)
{ 
	
	LOPTINCHI temp;
	int i=q;
	int j=r;
	LOPTINCHI x = *LISTTC.LOP[(q+r) / 2]; //L?y ph?n t? gi?a c?a d�y c?n s?p th? t? l�m ch?t
	do
	{ // Ph�n do?n d�y con a[q],..., a[r]
		
		while ( MH_SEARCH_NODE(root,atoi(LISTTC.LOP[i]->MAMH))->MH.TENMH.compare(MH_SEARCH_NODE(root,atoi(x.MAMH))->MH.TENMH) < 0) i++; //T�m ph?n t? d?u ti�n c� tr? l?n hon hay b?ng x
		while (MH_SEARCH_NODE(root,atoi(LISTTC.LOP[j]->MAMH))->MH.TENMH.compare(MH_SEARCH_NODE(root,atoi(x.MAMH))->MH.TENMH) > 0) j--; //T�m ph?n t? d?u ti�n c� tr? nh? hon hay b?ng x
		
				if (i<=j) // Doi cho A[i] voi A[j]
		{
			temp = *LISTTC.LOP[i];
			*LISTTC.LOP[i] =*LISTTC.LOP[j];
			*LISTTC.LOP[j] = temp;
			i++ ; j--;
		}
	} while (i<=j);
	if (q<j) // ph?n th? nh?t c� t? 2 ph?n t? tr? l�n
	TC_QUICK_SORT_EX(LISTTC,q,j);
	if (i<r) // ph?n th? ba c� t? 2 ph?n t? tr? l�n
	TC_QUICK_SORT_EX (LISTTC,i,r);
}
void TC_QUICK_SORT(DSLOPTINCHI LISTTC)
{ 
	if(LISTTC.SOLUONG==0) return;
	TC_QUICK_SORT_EX( LISTTC,0,LISTTC.SOLUONG-1); // G?i h�m TC_QUICK_SORT_EX v?i ph?n t? d?u c� ch? s? 0 d?n
// ph?n t? cu?i c�ng c� ch? s? n-1
}
/*==========================================================================*/
/*================================END XULY LOPTC  ========================*/
/*==========================================================================*/





/*==========================================================================*/
/*========================Bat dau xu ly DS dang ky  ========================*/
/*==========================================================================*/
DSDANGKY DK_NEWNODE()
{
	DSDANGKY p;
	p = new nodeDK;
	p->SV.DIEM = -2;
	p->SV.MASV = "";
	p->next = NULL;
	return p;
}
void DK_LOADSOLUONGSV(int curCLASS,int type)
{

	if (DK_LOADNUMOFTC(curCLASS) <=0)
	{
		Msg(L"L\u1EDBp không có sinh viên \u0110\u0103ng ký",-1);
		return;
	}
	
	DIEM_PRINTINFO(DK_LOADNUMOFTC(curCLASS),curCLASS,type);
}
void DIEM_PRINTINFODETAIL(int sodong,DSDANGKY &p,int curentpage,int x,int y,int type)
{
	if(p==NULL)return;
	DRAWTABLE(sodong,DIEM_NEWCOT(0));
	if (sodong-1 > NUMLINETABLE)
		sodong = NUMLINETABLE +1;
	gotoxy(x,y);
	int currentx,currenty;
	if(sodong==0)
	{
	
		return;
	}

	for (int i=0;i<sodong-1;i++)
	{

			
		gotoxy(x,y+i*2);
		if(p!=NULL)
		{
			for (int j=0;j<DIEM_NEWCOT(0).SOLUONGCOT;j++)
			{
				currentx=getX();
				currenty=getY();
				switch (j)
				{
					case 0:
					{
						gotoxy(getX()+2,getY());
						if(type==3)
						{
							if(i==0)
							{
							Color(COLORSELECT);
							TiengViet(SELECTPOITER);
							Color(COLORDEFAUL);	
							}

						}
						else if(type==DEFAULT)
						{
						}
						else if (type == PRINT ||type==4||type == 1)
						{
							cout<< (curentpage-1)*NUMLINETABLE+i+1;


						}
						gotoxy(getX()-2,getY());	
					}
		
					break;
					case 1:
					cout<< p->SV.MASV;
					break;
					case 2:
					cout<< SV_SEARCH_INFO_MSSV(FIRSTSV,p->SV.MASV)->SV.HO;
					break;
					case 3:
					cout<< SV_SEARCH_INFO_MSSV(FIRSTSV,p->SV.MASV)->SV.TEN;
					break;
					case 4:
					{
						gotoxy(MENUMAINTEXTLEN+117,currenty);
						if (type==4)
						{
							if (p->SV.DIEM!=-2)
							cout<< p->SV.DIEM;
							else
							{
								gotoxy(MENUMAINTEXTLEN+113,currenty);
								TiengViet(L"Chưa có");
							}

						}else if (type == 1)
						{
							if (p->SV.DIEM!=-2)
							cout<< p->SV.DIEM;
						}
					
					}
			
				break;
				}
				gotoxy(currentx+DIEM_NEWCOT(0).INFOCOT[j]->WCOT+1,currenty);
	
			
			}
		}
		
		p=p->next;
		if (p==NULL)break;
			
			
	}/*end for*/gotoMenuEX();
}
void DIEM_PRINTINFOCLASSDETAIL(int sodong,DSDANGKY &p,int curentpage,int x,int y,int type)
{
	if(p==NULL)return;
	DRAWTABLE(sodong,DIEM_NEWCOTINFO());
	if (sodong-1 > NUMLINETABLE)
		sodong = NUMLINETABLE +1;
	gotoxy(x,y);
	int currentx,currenty;
	for (int i=0;i<sodong-1;i++)
	{

			
		gotoxy(x,y+i*2);
		if(p!=NULL)
		{
			for (int j=0;j<DIEM_NEWCOTINFO().SOLUONGCOT;j++)
			{
				currentx=getX();
				currenty=getY();
				switch (j)
				{
					case 0:
					{
						gotoxy(getX()+2,getY());
						if(type==3||type==4)
						{
							if(i==0)
							{
							Color(COLORSELECT);
							TiengViet(SELECTPOITER);
							Color(COLORDEFAUL);	
							}

						}
						else if(type==DEFAULT)
						{
						}
						else if (type == PRINT )
						{
							cout<< (curentpage-1)*NUMLINETABLE+i+1;


						}
						gotoxy(getX()-2,getY());	
					}
		
					break;
					case 1:
					cout<< p->SV.MASV;
					break;
					case 2:
					cout<< SV_SEARCH_INFO_MSSV(FIRSTSV,p->SV.MASV)->SV.HO;
					break;
					case 3:
					cout<< SV_SEARCH_INFO_MSSV(FIRSTSV,p->SV.MASV)->SV.TEN;
					break;
					case 4:
					cout<< SV_SEARCH_INFO_MSSV(FIRSTSV,p->SV.MASV)->SV.MALOP;
					break;
			

			
				}
				gotoxy(currentx+DIEM_NEWCOTINFO().INFOCOT[j]->WCOT+1,currenty);
	
			
			}
		}
			
		p=p->next;
		if (p==NULL)break;
			
			
	}/*end for*/gotoMenuEX();
}
void DIEM_PRINTINFO(int sodong,int curCLASS,int type)
{
	ClearDetailTable();
	if(MH_SEARCH_NODE(root,atoi(LISTTC.LOP[curCLASS]->MAMH))==NULL)
	{
		Msg(L"Môn học không \u0111úng!!",-1);
		return;
	} 
	
	gotoxy(MIDTABLE-MH_SEARCH_NODE(root,atoi(LISTTC.LOP[curCLASS]->MAMH))->MH.TENMH.length()/2-3,4);
	TiengViet(L"Môn học:");
	cout<< MH_SEARCH_NODE(root,atoi(LISTTC.LOP[curCLASS]->MAMH))->MH.TENMH;
	gotoxy(MIDTABLE-15,6);
	TiengViet(L"Niên khóa:");
	cout << LISTTC.LOP[curCLASS]->KHOA;
	gotoxy(MIDTABLE+1,6);
	TiengViet(L"Học kỳ:");
	cout << LISTTC.LOP[curCLASS]->HOCKY;
	gotoxy(MIDTABLE+11,6);
	TiengViet(L"Nhóm:");
	cout << LISTTC.LOP[curCLASS]->NHOM;
	int TOTALNUM = sodong;
	
	int MAXPAGE = (int)ceil((double)sodong/NUMLINETABLE);
	int curentpage = 1,cureditpage=1;
	int mod = sodong % NUMLINETABLE;
	gotoMenuFun();
	const int x=getX()+3,y = getY()+4+NUMLINETITLE;
	int currentx,currenty;
	gotoxy(x,y);
	switch (type)
	
	{
		case 1:/*NHap diem*/
		{
			int edit=1,editold=0,moveedit=1;
			DSDANGKY p = LISTTC.LOP[curCLASS]->SV;
				if(p==NULL)return;
				
			if(!DIEM_CHECKCODIEM(LISTTC.LOP[curCLASS]->SV))
			while(edit<=TOTALNUM)
			{
				if(DIEM_CHECKCODIEM(LISTTC.LOP[curCLASS]->SV))break;
				if (edit %NUMLINETABLE==1 )
				{
					if (edit >NUMLINETABLE)
					{
						cureditpage++;editold=0;
					}
					
					if(cureditpage < MAXPAGE)
					{
						sodong = NUMLINETABLE;
					}else
					{
						if (mod!=0)
						sodong = mod;
					}


				
				DIEM_PRINTINFODETAIL(sodong+1,p,cureditpage,x,y,type);
				p = LISTTC.LOP[curCLASS]->SV;
				if (p==NULL) return;
				for(int w=0;w<edit-1;w++)
				p=p->next;
				if(p==NULL)return;
				}
	
				if(p->SV.DIEM==-2)
				{
				
					p = LISTTC.LOP[curCLASS]->SV;
					if (p==NULL) return;
					for(int w=0;w<edit-1;w++)
						p=p->next;
						if(p==NULL)return;
					gotoxy(x+113,y+((edit-1)%NUMLINETABLE)*2);
					inDiem(&p->SV.DIEM,2);
				
				}
				
	
				p=p->next;
				
				edit++;	
			}
		char option = MsgYN(L"\u0110ã nhập \u0111i\u1EC3m hoàn tất, ch\u1EC9nh sửa??");
		if(option==YES)
		{
			p = LISTTC.LOP[curCLASS]->SV;
			if (p==NULL) return;
			cureditpage=1;edit = 1;
			if(sodong < TOTALNUM)
			sodong = TOTALNUM;
			DIEM_PRINTINFODETAIL(sodong+1,p,cureditpage,x,y,type);
	
			while(true)
			{
				int select = getch();
				if (select == 224)
				{
					int select_val = getch();
					
					if (select_val==UP)
					{
			
						if (edit>1)
						{
							edit--;
							editold = 1;
						}else continue;
						if (edit %NUMLINETABLE==0 )
						{
							
							cureditpage--;sodong = NUMLINETABLE;
							p = LISTTC.LOP[curCLASS]->SV;
							if (p==NULL) return;
							if (cureditpage!= 1)
							{
			
								for(int w=0;w<NUMLINETABLE*(cureditpage-1);w++)
								p=p->next;
							
							}
							if (p==NULL) return;
							
							
							DIEM_PRINTINFODETAIL(sodong+1,p,cureditpage,x,y,type);
						}
						gotoxy(x+113,y+((edit-1)%NUMLINETABLE)*2);
					}
					else if (select_val==DOWN)
					{
						
						if (edit<TOTALNUM)
						{
							edit++;
							editold = -1;
						}else continue;
						if (edit %NUMLINETABLE==1 )
						{
							if (edit >NUMLINETABLE)
							{
								cureditpage++;editold=0;
							}
							
							if(cureditpage < MAXPAGE)
							{
								sodong = NUMLINETABLE;
							}else
							{
								if (mod!=0)
								sodong = mod;
							}
			
			
							if (p==NULL) return;
							
							DIEM_PRINTINFODETAIL(sodong+1,p,cureditpage,x,y,type);
						}
					gotoxy(x+113,y+((edit-1)%NUMLINETABLE)*2);
					}
					
			
					
					
				}else if(select==ENTER||select==BACKSPACE)
				{
					gotoxy(x+113,y+((edit-1)%NUMLINETABLE)*2);
					cout << "  ";
					gotoxy(x+113,y+((edit-1)%NUMLINETABLE)*2);
							p = LISTTC.LOP[curCLASS]->SV;
							if (p==NULL) return;
							for(int w=0;w<edit-1;w++)
							p=p->next;
							if (p==NULL) return;
							gotoxy(x+113,y+((edit-1)%NUMLINETABLE)*2);
							inDiem(&p->SV.DIEM,2);
				}
				else if (select==F4)/*Luu file*/
				{
					TC_SAVEONECLASS(curCLASS);
					Msg(L"Nhập \u0111i\u1EC3m thành công!!",1);
					break;
				}
				else if(select==ESC) break;
				
			}	
		}
		else/*Luu file*/
		{
			TC_SAVEONECLASS(curCLASS);
			Msg(L"Nhập \u0111i\u1EC3m thành công!!",1);

		}

	}break;
	

	case 2:/*in sinh vien cau b*/
	{
		DSDANGKY p = LISTTC.LOP[curCLASS]->SV;
		
		if (p==NULL) return;
		DIEM_PRINTINFOCLASSDETAIL(sodong+1,p,curentpage,x,y,PRINT);
		while (true)
		{
					

		
			int swpage = getch();
			if(swpage == 224)
			{
				
		
		
				
				int swpage_val = getch();
				if (swpage_val == PAGEDOWN)/*pagedown*/
					{
						if (curentpage< MAXPAGE)
						{	
			
						curentpage++;
						}
						else continue;
						if (curentpage == MAXPAGE)
					{
							if (mod!=0)
						sodong = mod;
					}
					else
					{
						sodong = NUMLINETABLE;
					}
							if(p==NULL)return;
					DIEM_PRINTINFOCLASSDETAIL(sodong+1,p,curentpage,x,y,PRINT);
					}
				else if(swpage_val == PAGEUP)/*down*/
					{
			
						
						if (curentpage>1)
						{	
			
						curentpage--;
						}
						else continue;
						sodong = NUMLINETABLE;
						p = LISTTC.LOP[curCLASS]->SV;
						if(p==NULL)return;
						if (curentpage!= 1)
						{
							for(int z=1;z<curentpage;z++)
						{
							for(int w=0;w<sodong;w++)
							p=p->next;
						}
						}
						
						if (p==NULL) return;
						if (curentpage == MAXPAGE)
					{
							if (mod!=0)
						sodong = mod;
					}
					else
					{
						sodong = NUMLINETABLE;
					}
							
					DIEM_PRINTINFOCLASSDETAIL(sodong+1,p,curentpage,x,y,PRINT);
				}
						
		
			}
			else
			{
					
				if ((char) swpage == ESC)
				{
		
					break;
			
							
				}
			      
			}

		}/*end while*/
				
	}break;/*end case2*/
	case 4:/*in sinh vien cau h*/
	{
		DSDANGKY p = LISTTC.LOP[curCLASS]->SV;
		if (p==NULL) return;
		DIEM_PRINTINFODETAIL(sodong+1,p,curentpage,x,y,type);
		while (true)
		{
					

		
			int swpage = getch();
			if(swpage == 224)
			{
				
		
		
				
				int swpage_val = getch();
				if (swpage_val == PAGEDOWN)/*pagedown*/
					{
						if (curentpage< MAXPAGE)
						{	
			
						curentpage++;
						}
						else continue;
						if (curentpage == MAXPAGE)
					{
							if (mod!=0)
						sodong = mod;
					}
					else
					{
						sodong = NUMLINETABLE;
					}
							
							if(p==NULL)return;
					DIEM_PRINTINFODETAIL(sodong+1,p,curentpage,x,y,type);
					}
				else if(swpage_val == PAGEUP)/*down*/
					{
			
						
						if (curentpage>1)
						{	
			
						curentpage--;
						}
						else continue;
						sodong = NUMLINETABLE;
						p = LISTTC.LOP[curCLASS]->SV;if(p==NULL)return;
						if (curentpage!= 1)
						{
							for(int z=1;z<curentpage;z++)
						{
							for(int w=0;w<sodong;w++)
							p=p->next;
						}
						}
						
						if (p==NULL) return;
						if (curentpage == MAXPAGE)
					{
							if (mod!=0)
						sodong = mod;
					}
					else
					{
						sodong = NUMLINETABLE;
					}
							
						DIEM_PRINTINFODETAIL(sodong+1,p,curentpage,x,y,type);
					}
						
		
			}
			else
			{
					
				if ((char) swpage == ESC)
				{
		
					break;
			
							
				}
			      
			}
		
		}/*end while*/
						
	}break;/*end case3*/

	}/*endswitch*/
}
int DK_LOADNUMOFTC(int curCLASS)
{
	int sodong = 0;
	string filename ="DATA\\LOP\\";
	filename = filename + i_to_string(LISTTC.LOP[curCLASS]->MALOPTC)+".in";
	char *newfile;
	newfile = new char[filename.length()];
	newfile = str_2_char(filename,filename.length());
	ifstream loadfile;
	loadfile.open(newfile);

	delete []newfile;
	if(!loadfile.is_open())
	{
		string num = "0";
		CREATFILE(newfile,&num);
	}

	loadfile >> sodong;
	loadfile.close();
	return sodong;
}
void DIEM_INSERT_AFTER(DSDANGKY p, SVDANGKY x)
{
   
   if(p == NULL)
		Msg(L"Kh\u00F4ng th\u1EC3 th\u00EAm v\u00E0o danh s\u00E1ch",-1);
   else
   {
   		DSDANGKY q;
   	 	q =DK_NEWNODE();
      	q->SV = x;
     	q->next = p->next;
     	p->next = q;
   }
   
}
void DIEM_INSERT_FIRST(DSDANGKY &q, SVDANGKY x)
{
   DSDANGKY p;
   p = DK_NEWNODE();
   p->SV = x;
   p->next = NULL;
   q = p;
}
void DIEM_SELECTION_SORT(DSDANGKY &HEAD)
{ 
	DSDANGKY p, q, pmin;
	SVDANGKY min;
	for(p = HEAD; p->next != NULL; p = p->next)
	{ 
		min = p->SV;
		pmin = p;
		for(q = p->next; q != NULL; q = q->next)
		if(strcmp(str_2_char(q->SV.MASV),str_2_char(min.MASV))<0 )
		{
			min = q->SV;
			pmin = q;
		}
		
// hoan doi truong info cua hai nut p va pmin
		pmin->SV = p->SV;
		p->SV = min;
	}
}
void DK_CLEARLIST(DSDANGKY &HEAD)
{  
	if(HEAD==NULL)return;
   DSDANGKY p;  
  while(HEAD != NULL)
   {
      p = HEAD;
      HEAD = HEAD->next;
      
      delete p;
   }
  
}
int DK_SEARCH_INFO_MSSV(DSDANGKY HEAD, string MSSV)
{  
	DSDANGKY p;
	for (p = HEAD;  p  != NULL ; p=p->next ) 
               if (MSSV==p->SV.MASV) return 1;
	 return 0;
}
int DIEM_CHECKCODIEM(DSDANGKY HEAD)
{
	for (DSDANGKY p = HEAD;  p  != NULL ; p=p->next ) 
	if(p->SV.DIEM==-2) return 0;
	return 1;
	
}
bool DK_CHECKDANGKY(string MSSV,char *MAMH)
{
	for(int i=0;i<LISTTC.SOLUONG;i++)
	{
		if (strcmp(LISTTC.LOP[i]->MAMH,MAMH)==0)
		{
			for(DSDANGKY p = LISTTC.LOP[i]->SV;p!=NULL;p=p->next )
			{
				if (p->SV.MASV == MSSV && p->SV.DIEM==-2)
				return true;
			}
		}
	}
	return false;
}
DSDANGKY DK_SEARCH_INFO_MSSV_p(DSDANGKY HEAD, string MSSV)
{  
	DSDANGKY p;
	for (p = HEAD;  p  != NULL ; p=p->next ) 
               if (MSSV==p->SV.MASV) return p;
	 return NULL;
}
void DK_Init(string MSSV)
{
	for (int i=0;i<MAXLOPTINCHI;i++)
	{
		DANGKYMON[i]=0;
		MONCODIEM[i]=0;
	}
	for(int i=0;i<LISTTC.SOLUONG;i++)
	{
		DANGKYMON[i] = DK_SEARCH_INFO_MSSV(LISTTC.LOP[i]->SV,MSSV);
		if (DK_SEARCH_INFO_MSSV(LISTTC.LOP[i]->SV,MSSV))
		{
			if(DK_SEARCH_INFO_MSSV_p(LISTTC.LOP[i]->SV,MSSV)->SV.DIEM!=-2)
			MONCODIEM[i] = 1;
		}
	}
}
bool DK_CHECKDANGKYMON(char *MAMH)
{
	for(int i=0;i<LISTTC.SOLUONG;i++)
	{
		if (DANGKYMON[i]&&!MONCODIEM[i])
		{
			if (strcmp(LISTTC.LOP[i]->MAMH,MAMH)==0)
			return true;
		}
	}
	return false;
}
int DK_DELETE_INFO(DSDANGKY &HEAD,SVDANGKY x)
{  
	DSDANGKY p=HEAD;
  if (HEAD==NULL ) return 0;
  if (HEAD->SV.MASV ==x.MASV ) {
     p=HEAD;
	 HEAD = p->next ;
	 delete p ; return 1;
  }
    
	for ( p=HEAD; p->next!=NULL && p->next->SV.MASV != x.MASV; p=p->next) ;
	if (p->next!= NULL ) {
		DSDANGKY q=p->next; 
		p->next=q->next;
		if (p->next==NULL)
		delete q; return 1;
	}
     return 0;
}
void DK_CHANGEINFO(DSDANGKY &HEAD,string oldMSSV,string MSSV)
{
	
  if (HEAD==NULL ) return;
  for(DSDANGKY p=HEAD;p!=NULL;p=p->next)
  {
  	if(p->SV.MASV==oldMSSV)
  	{
  		p->SV.MASV = MSSV;
	}
  }
}
int DK_DELETE_INFO_MSSV(DSDANGKY &HEAD,string MSSV)
{  
	DSDANGKY p=HEAD;
  if (HEAD==NULL ) return 0;
  if (HEAD->SV.MASV ==MSSV ) {
     p=HEAD;
	 HEAD = p->next ;
	 delete p ; return 1;
  }
    
	for ( p=HEAD; p->next!=NULL && p->next->SV.MASV != MSSV; p=p->next) ;
	if (p->next!= NULL ) {
		DSDANGKY q=p->next; 
		p->next=q->next;
		if (p->next==NULL)
		delete q; return 1;
	}
     return 0;
}
/*==========================================================================*/
/*================================END XULY DS dang ky ======================*/
/*==========================================================================*/


/*==========================================================================*/
/*================================Phan xu ly diem TB&TK ======================*/
/*==========================================================================*/
int DIEM_MAXDIEM(string MSSV,char* TENMH)
{
	int diem = -2;
	for(int i=0;i<LISTTC.SOLUONG;i++)
	{
		if(strcmp(LISTTC.LOP[i]->MAMH,TENMH)==0&&LISTTC.LOP[i]->SV!=NULL)
		{
			for(DSDANGKY p = LISTTC.LOP[i]->SV;p!=NULL;p=p->next)
			{
				if(p->SV.MASV==MSSV)
				{
					if (diem<p->SV.DIEM)
					diem = p->SV.DIEM;
				}
			}
		}
	}
	return diem;
}


void TK_PRINTINFO(int sodong,char *Tenlop,int type)/*in thong tin sinh vien*/
{
	if(sodong==0) 
	{
		Msg(L"L\u1EDBp không có sinh viên!",-1);
		return;
	}
	ClearDetailTable();
	gotoxy(90,4);
	TiengViet(L"Mã l\u1edbp: ");
	cout << Tenlop;
	gotoxy(85,6);
	TiengViet(L"S\u1ed1 sinh viên của l\u1edbp này là:");
	cout << sodong;
	if(sodong==0) 
	{
		Msg(L"L\u1EDBp này không có sinh viên!",-1);
		return;
	}
	/*============XU LY DU LIEU DIEM============*/
	/*-----------Khoi tao----------------*/
	/*DEm so tin chi va mon hoc*/
	TONGMH = 0;
	TONGTC = 0;
	MH_RECOUNTTC (root);
	/*load du lieu ten mon hoc vao mang*/
	int *TINCHI;
	char **DULIEUTENMH;
	TINCHI = new int[TONGMH];
	DULIEUTENMH = new char*[TONGMH];
	for (int i=0;i<TONGMH;i++)
	{
		DULIEUTENMH[i] = new char[10];
		TINCHI[i]=0;	
	}
	
	TONGMH = 0;
	MH_LOADTENMH (root,DULIEUTENMH,TINCHI);
	/*Khoi tao bang diem cho lop*/
	int **BANGDIEM;
	BANGDIEM = new int*[sodong];
	for(int i=0;i<sodong;i++)
	{
		BANGDIEM[i] = new int[TONGMH];
		for(int j=0;j<TONGMH;j++)
		BANGDIEM[i][j]=-2;
	}
	/*Khoi tao danh sach MSSV*/
	string *DULIEUMASV;
	DULIEUMASV = new string[sodong];
	int i=0;
	for(LISTSV p = FIRSTSV;p!=NULL&& i<sodong;p=p->next)
	{
		if(strcmp(p->SV.MALOP,Tenlop)==0)
		{
			DULIEUMASV[i]=p->SV.MASV;
			i++;
		}
	}
	/*-------------end khoi tao-------------*/
	
	/*-------------Bat dau load du lieu--------*/
	
	for (i=0;i<sodong;i++)
	{
		for(int j=0;j<TONGMH;j++)
		{
			BANGDIEM[i][j]=DIEM_MAXDIEM(DULIEUMASV[i],DULIEUTENMH[j]);
		
		}

	}
	
	
	
	
	/*==================END=======================*/
	int TOTALNUM = sodong;
	int MAXPAGE = (int)ceil((double)sodong/NUMLINETABLE);
	int MAXSWAP = (int)ceil((double)TONGMH/6);
	int curentpage = 1,curswappage = 1;
	
	int mod = sodong % NUMLINETABLE;
	int modswap = TONGMH%6;
	int socot = TONGMH;
	gotoMenuFun();
	const int x=getX()+3,y = getY()+4+NUMLINETITLE;
	int currentx,currenty;
	gotoxy(x,y);
	switch (type)
	
	{
		case 4:/*in diem trung binh cau i*/
		{	
			
			int p = 0;
			if (SV_SEARCH_INFO_MSSV(FIRSTSV,DULIEUMASV[p])==NULL) return;
		
			TK_PRINTINFOTBDETAIL(sodong+1,&p,curentpage,x,y,BANGDIEM,DULIEUMASV,TINCHI);
			while (true)
			{
					

		
				int swpage = getch();
				if(swpage == 224)
				{
					int swpage_val = getch();
					if (swpage_val == PAGEDOWN)/*pagedown*/
						{
							if (curentpage< MAXPAGE)
							{	
				
							curentpage++;
							}
							else continue;
							if (curentpage == MAXPAGE)
						{
								if (mod!=0)
							sodong = mod;
						}
						else
						{
							sodong = NUMLINETABLE;
						}
								
							if (SV_SEARCH_INFO_MSSV(FIRSTSV,DULIEUMASV[p])==NULL) return;
						TK_PRINTINFOTBDETAIL(sodong+1,&p,curentpage,x,y,BANGDIEM,DULIEUMASV,TINCHI);
						}
					else if(swpage_val == PAGEUP)/*down*/
						{
				
							
							if (curentpage>1)
							{	
				
							curentpage--;
							}
							else continue;
							sodong = NUMLINETABLE;
							p = 0;
							if (curentpage!= 1)
							{
								for(p=0;p<(curentpage-1)*NUMLINETABLE;p++);
							}
							
							if (SV_SEARCH_INFO_MSSV(FIRSTSV,DULIEUMASV[p])==NULL) return;
							if (curentpage == MAXPAGE)
						{
								if (mod!=0)
							sodong = mod;
						}
						else
						{
							sodong = NUMLINETABLE;
						}
								
							TK_PRINTINFOTBDETAIL(sodong+1,&p,curentpage,x,y,BANGDIEM,DULIEUMASV,TINCHI);
						}
							
			
				}
				else
				{
						
					if ((char) swpage == ESC)
					{
			
						break;
				
								
					}
				      
				}

			}/*end while*/
				
		}break;/*end case2*/
		case 5:/*in diem TK cau j*/
		{
			
			int p = 0;
			if (SV_SEARCH_INFO_MSSV(FIRSTSV,DULIEUMASV[p])==NULL) return;

			TK_PRINTINFODETAIL(sodong+1,&p,curentpage,x,y,BANGDIEM,DULIEUMASV,curswappage,socot,DULIEUTENMH);
			while (true)
			{
	
				int swpage = getch();
				if(swpage == 224)
				{

					int swpage_val = getch();
					if (swpage_val == DOWN)/*pagedown*/
					{
						
						if (curentpage< MAXPAGE)
						{	
			
						curentpage++;
						socot = TONGMH;
						curswappage = 1;
						}
						else continue;
						
						if (curentpage == MAXPAGE)
						{
								if (mod!=0)
							sodong = mod;
						}
						else
						{
							sodong = NUMLINETABLE;
						}
						for(p=0;p<(curentpage-1)*NUMLINETABLE;p++);
						if (SV_SEARCH_INFO_MSSV(FIRSTSV,DULIEUMASV[p])==NULL) return;
						TK_PRINTINFODETAIL(sodong+1,&p,curentpage,x,y,BANGDIEM,DULIEUMASV,curswappage,socot,DULIEUTENMH);
					}
					else if(swpage_val == PAGEUP)/*down*/
					{
			
						
						if (curentpage>1)
						{	
						socot = TONGMH;
						curswappage = 1;
						curentpage--;
						}
						else continue;
						sodong = NUMLINETABLE;
						p = 0;
						if (curentpage!= 1)
						{
						for(p=0;p<(curentpage-1)*NUMLINETABLE;p++);
						}
						
						if (SV_SEARCH_INFO_MSSV(FIRSTSV,DULIEUMASV[p])==NULL) return;
						if (curentpage == MAXPAGE)
						{
								if (mod!=0)
							sodong = mod;
						}
						else
						{
							sodong = NUMLINETABLE;
						}
							
						TK_PRINTINFODETAIL(sodong+1,&p,curentpage,x,y,BANGDIEM,DULIEUMASV,curswappage,socot,DULIEUTENMH);
					}
					else if (swpage_val == PAGEDOWN)/*pagedown*/
					{
						
						if (curentpage< MAXPAGE)
						{	
			
						curentpage++;
						socot = TONGMH;
						curswappage = 1;
						}
						else continue;
						
						if (curentpage == MAXPAGE)
						{
								if (mod!=0)
							sodong = mod;
						}
						else
						{
							sodong = NUMLINETABLE;
						}
						for(p=0;p<(curentpage-1)*NUMLINETABLE;p++);
						if (SV_SEARCH_INFO_MSSV(FIRSTSV,DULIEUMASV[p])==NULL) return;
						TK_PRINTINFODETAIL(sodong+1,&p,curentpage,x,y,BANGDIEM,DULIEUMASV,curswappage,socot,DULIEUTENMH);
					}
					else if(swpage_val == UP)/*down*/
					{
			
						
						if (curentpage>1)
						{	
						socot = TONGMH;
						curswappage = 1;
						curentpage--;
						}
						else continue;
						sodong = NUMLINETABLE;
						p = 0;
						if (curentpage!= 1)
						{
							for(p=0;p<(curentpage-1)*NUMLINETABLE;p++);
						}
						
						if (SV_SEARCH_INFO_MSSV(FIRSTSV,DULIEUMASV[p])==NULL) return;
						if (curentpage == MAXPAGE)
						{
								if (mod!=0)
							sodong = mod;
						}
						else
						{
							sodong = NUMLINETABLE;
						}
						
						TK_PRINTINFODETAIL(sodong+1,&p,curentpage,x,y,BANGDIEM,DULIEUMASV,curswappage,socot,DULIEUTENMH);
					}
					else if (swpage_val == RIGHT)/*pagedown*/
					{
						p = 0;
						if (curentpage!= 1)
						{
							for(p=0;p<(curentpage-1)*NUMLINETABLE;p++);
						}
						
						if (curswappage< MAXSWAP)
						{	
							curswappage ++;
						}
						else continue;
						if (curswappage == MAXSWAP)
						{
								if (modswap!=0)
							socot = modswap;
						}
						else
						{
							socot = TONGMH;
						}
						TK_PRINTINFODETAIL(sodong+1,&p,curentpage,x,y,BANGDIEM,DULIEUMASV,curswappage,socot,DULIEUTENMH);
					}
					else if(swpage_val == LEFT)/*down*/
					{
						p = 0;
						if (curentpage!= 1)
						{
						for(p=0;p<(curentpage-1)*NUMLINETABLE;p++);
						}
						
						if (curswappage>1)
						{	
			
						curswappage--;
						}
						else continue;
						socot = TONGMH;
		
						TK_PRINTINFODETAIL(sodong+1,&p,curentpage,x,y,BANGDIEM,DULIEUMASV,curswappage,socot,DULIEUTENMH);
					}		
		
				}
				else
				{
					
					if ((char) swpage == ESC)
					{
		
					break;
	
						
					}
	      
				}

			}/*end while*/
		}break;/*end case2*/
	
	}/*end switch*/
	delete[]TINCHI;
	for (int i=0;i<TONGMH;i++)
	{
		delete[]DULIEUTENMH[i];
			
	}
	delete[]DULIEUTENMH;
	for(int i=0;i<sodong;i++)
	{
		delete[]BANGDIEM[i];
	}
	delete[]BANGDIEM;
	delete[]DULIEUMASV;
}
void TK_PRINTINFOTBDETAIL(int sodong,int *p,int curentpage,int x,int y,int **BANGDIEM,string *DULIEUMASV,int *TINCHI)
{
	
	
	DRAWTABLE(sodong,DIEM_NEWCOT(1));
	if (sodong-1 > NUMLINETABLE)
	sodong = NUMLINETABLE +1;
	gotoxy(x,y);
	int currentx,currenty;
	float diem=0;
	float tong = 0;
	for (int i=0;i<sodong-1;i++)
	{
		if (SV_SEARCH_INFO_MSSV(FIRSTSV,DULIEUMASV[*p])==NULL)break;
		if(SV_SEARCH_INFO_MSSV(FIRSTSV,DULIEUMASV[*p])!=NULL)
		{
			diem = 0;
			tong = 0;
			for(int k=0;k<TONGMH;k++)
			{
				if(BANGDIEM[*p][k]!=-2)
				tong = tong + (float)BANGDIEM[*p][k]*TINCHI[k];
				
			}
			diem = tong/TONGTC;
			gotoxy(x,y+i*2);
				
			for (int j=0;j<DIEM_NEWCOT(1).SOLUONGCOT;j++)
			{
				currentx=getX();
				currenty=getY();
				switch (j)
				{
					case 0:
					{
						gotoxy(getX()+2,getY());
						cout<< (curentpage-1)*NUMLINETABLE+i+1;
						gotoxy(getX()-2,getY());
					}
		
					break;
					case 1:
					cout<< DULIEUMASV[*p];
					break;
					case 2:
					cout<< SV_SEARCH_INFO_MSSV(FIRSTSV,DULIEUMASV[*p])->SV.HO ;
					break;
					case 3:
					cout<< SV_SEARCH_INFO_MSSV(FIRSTSV,DULIEUMASV[*p])->SV.TEN;
					break;
					case 4:
						{
							gotoxy(MENUMAINTEXTLEN+117,currenty);
							cout<< setprecision(1)<<fixed<<diem;
						}
					
					break;
			
			
				}	
				gotoxy(currentx+DIEM_NEWCOT(1).INFOCOT[j]->WCOT+1,currenty);
	
			}
			
		(*p)++;
			
			
		}
	}/*end for*/gotoMenuEX();
}
void TK_PRINTINFODETAIL(int sodong,int *p,int curentpage,int x,int y,int **BANGDIEM,string *DULIEUMASV,int curswappage,int socot,char **DULIEUTENMH)
{
	
	DRAWTABLE(sodong,TK_NEWCOT());
	if (sodong-1 > NUMLINETABLE)
	sodong = NUMLINETABLE +1;
	gotoxy(x,y);
	int currentx,currenty;
	for(int m=0;m<6;m++)
	{
		gotoxy(MENUMAINTEXTLEN+68+10*m,y-2);
		cout <<"       ";
	}
	if (socot>6) socot = 6;
	for(int m=0;m<socot;m++)
	{
		gotoxy(MENUMAINTEXTLEN+68+10*m,y-2);
		TiengViet(L"Mã ");
		cout <<DULIEUTENMH[(curswappage-1)*6+m];
	}

	for (int i=0;i<sodong-1;i++)
	{
		if (SV_SEARCH_INFO_MSSV(FIRSTSV,DULIEUMASV[*p])==NULL)break;
		if(SV_SEARCH_INFO_MSSV(FIRSTSV,DULIEUMASV[*p])!=NULL)
		{
					
			gotoxy(x,y+i*2);
				
			for (int j=0;j<TK_NEWCOT().SOLUONGCOT;j++)
			{
				currentx=getX();
				currenty=getY();
				switch (j)
				{
					case 0:
					{
						gotoxy(getX()+2,getY());
						cout<< (curentpage-1)*NUMLINETABLE+i+1;
						gotoxy(getX()-2,getY());
					}
		
					break;
					case 1:
					cout<< DULIEUMASV[*p];
					break;
					case 2:
					cout<< SV_SEARCH_INFO_MSSV(FIRSTSV,DULIEUMASV[*p])->SV.HO <<" "<<SV_SEARCH_INFO_MSSV(FIRSTSV,DULIEUMASV[*p])->SV.TEN;
					break;
					case 3:
						{
							gotoxy(MENUMAINTEXTLEN+71+10*(j-3),currenty);
							if (socot>j-3)
							if(BANGDIEM[*p][(curswappage-1)*6+j-3]!=-2)
							cout<< BANGDIEM[*p][(curswappage-1)*6+j-3];
							else
							cout <<NONE;
						}
					
					break;
					case 4:
						{
							gotoxy(MENUMAINTEXTLEN+71+10*(j-3),currenty);
							if (socot>j-3)
							if(BANGDIEM[*p][(curswappage-1)*6+j-3]!=-2)
							cout<< BANGDIEM[*p][(curswappage-1)*6+j-3];
							else
							cout <<NONE;
						}
					
					break;
					case 5:
						{
							gotoxy(MENUMAINTEXTLEN+71+10*(j-3),currenty);
							if (socot>j-3)
							if(BANGDIEM[*p][(curswappage-1)*6+j-3]!=-2)
							cout<< BANGDIEM[*p][(curswappage-1)*6+j-3];
							else
							cout <<NONE;
						}
					
					break;
					case 6:
						{
							gotoxy(MENUMAINTEXTLEN+71+10*(j-3),currenty);
							if (socot>j-3)
							if(BANGDIEM[*p][(curswappage-1)*6+j-3]!=-2)
							cout<< BANGDIEM[*p][(curswappage-1)*6+j-3];
							else
							cout <<NONE;
						}
					
					break;
					case 7:
						{
							gotoxy(MENUMAINTEXTLEN+71+10*(j-3),currenty);
							if (socot>j-3)
							if(BANGDIEM[*p][(curswappage-1)*6+j-3]!=-2)
							cout<< BANGDIEM[*p][(curswappage-1)*6+j-3];
							else
							cout <<NONE;
						}
					
					break;
					case 8:
						{
							gotoxy(MENUMAINTEXTLEN+71+10*(j-3),currenty);
							if (socot>j-3)
							if(BANGDIEM[*p][(curswappage-1)*6+j-3]!=-2)
							cout<< BANGDIEM[*p][(curswappage-1)*6+j-3];
							else
							cout <<NONE;
						}
					
					break;
			
			
			
				}
				gotoxy(currentx+TK_NEWCOT().INFOCOT[j]->WCOT+1,currenty);
	
			}
			
		(*p)++;
		
		}
	}/*end for*/gotoMenuEX();
}
/*==========================================================================*/
/*================================END XULY Diem TK &TB ======================*/
/*==========================================================================*/



/*==========================================================================*/
/*================================PHAN LUU DU LIEU   ======================*/
/*==========================================================================*/
void TC_SAVEFILE()
{
	string DATA=i_to_string(LISTTC.SOLUONG) +"\n";
	for(int w=0;w<LISTTC.SOLUONG;w++)
	{
		DATA = DATA + i_to_string(LISTTC.LOP[w]->MALOPTC) +"\t"+(string) LISTTC.LOP[w]->MAMH+"\t"+i_to_string(LISTTC.LOP[w]->KHOA)+"\t"+i_to_string(LISTTC.LOP[w]->HOCKY)+"\t"+i_to_string(LISTTC.LOP[w]->NHOM)+"\t"+i_to_string(LISTTC.LOP[w]->MAXSV)+"\n";
						
	}
	char filelist[] = "DATA\\LOP\\listTC.data";
	CREATFILE(filelist,&DATA);
}

void MH_SAVENEWFILE()
{
	ofstream file;
	file.open("DATA\\MONHOC\\listMH.data",ios::out|ios::trunc);	
	file<<"";
	file.close();
	if(root!=NULL)
	{
		MH_SAVEFILE (root);
	}
	
}
void TC_CREATNEWCLASS_SAVE()
{
	string filename ="DATA\\LOP\\";
	filename = filename + i_to_string(LISTTC.LOP[LISTTC.SOLUONG-1]->MALOPTC)+".in";
	char *newfile;
	newfile = new char[filename.length()];
	newfile = str_2_char(filename,filename.length());
	string newfiledata = "0\n";
	CREATFILE(newfile,&newfiledata);
	delete[]newfile;
}
void TC_RESAVEDK()
{
	for(int s=0;s<LISTTC.SOLUONG;s++)
	{
		string DATA ="";
		int count = 0;
		for(DSDANGKY t=LISTTC.LOP[s]->SV;t!=NULL;t=t->next)
		{
			DATA = DATA + t->SV.MASV + "\t" +i_to_string(t->SV.DIEM) +"\n";
			count++;
										
		}
		DATA = i_to_string(count) + "\n" + DATA;
						
		string filename2 ="DATA\\LOP\\";
		filename2 = filename2 + i_to_string(LISTTC.LOP[s]->MALOPTC)+".in";
		char *newfile;
		newfile = new char[filename2.length()];
		newfile = str_2_char(filename2,filename2.length());
		CREATFILE(newfile,&DATA);
		delete []newfile;
	}
}
void TC_SAVEONECLASS(int curCLASS)
{
	string DATA = i_to_string(DK_LOADNUMOFTC(curCLASS))+"\n";
			
	for(DSDANGKY p = LISTTC.LOP[curCLASS]->SV;p!=NULL;p=p->next)
	{
		DATA = DATA + p->SV.MASV + "\t" + i_to_string(p->SV.DIEM) + "\n";	
	}
	string filename ="DATA\\LOP\\";
	filename = filename + i_to_string(LISTTC.LOP[curCLASS]->MALOPTC)+".in";
	char *newfile;
	newfile = new char[filename.length()];
	newfile = str_2_char(filename,filename.length());
	CREATFILE(newfile,&DATA);
	delete []newfile;	
}
void SV_SAVEFILE(char *Tenlop)
{
	SV_SELECTION_SORT(FIRSTSV);
	string DATA = "";
	int num =0;
	for(LISTSV p = FIRSTSV;p!=NULL;p=p->next)
	{
		if(strcmp(p->SV.MALOP,Tenlop)==0)
		{
			DATA = DATA + p->SV.MASV +"\t"+ md5(p->SV.MASV)+ "\t" +p->SV.HO +"\t"+p->SV.TEN+"\t"+p->SV.PHAI+"\t"+p->SV.SDT+"\t"+ (string) p->SV.MALOP +"\n";
			num++;
		}
	}
	DATA = i_to_string(num) +"\n"+DATA;
	char filename[50] = FOLDERDATA;
		
	strcat(filename,Tenlop);
	CREATFILE(filename,&DATA);
}

/*==========================================================================*/
/*================================END PHAN LUU DU LIEU======================*/
/*==========================================================================*/
