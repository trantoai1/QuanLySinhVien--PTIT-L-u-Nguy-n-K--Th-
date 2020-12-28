
#include "define\define.h"
#include "io\FILE\file.h"

#include <math.h>

#include "menu\menu.h"
#ifndef STUDENTPJ
#define STUDENTPJ
#define MAXDSLOP 200
#define FOLDERDATA "DATA\\DSSV\\"
#define LISTDATA "DATA\\DSSV\\list.data"
#define MAXLOPTINCHI 1000// So luong mang con tro lop tin chi
/*=====================================================*/
/*========= Cau truc Danh sach sinh vien  =============*/
/*=====================================================*/
struct DSLOP{
	unsigned int SOLUONG;
	char MALOP[MAXDSLOP][15];
};


struct STUDENT{  
	string MASV;/*primary1*/
	string HO;
	string TEN;
	string PHAI;
	string SDT;
	char MALOP[15];
	string pass;
};
struct node
{  
	STUDENT SV ;
    struct node *next ;
};

typedef  node* LISTSV;


struct MNSV{ /*Quan ly con tro dslkdon*/
	LISTSV FIRST;
	LISTSV LAST;
};
/*=====================================================*/
/*=================END struct SV=======================*/
/*=====================================================*/




/*=====================================================*/
/*=================Struct MON HOC======================*/
/*=====================================================*/
struct MONHOC{

	char MAMH[10];/*primary1,key*/
	string TENMH;
	unsigned int STCLT;
	unsigned int STCTH;
	
};
struct NODEMH{
	MONHOC MH;
	NODEMH *left,*right;
};
typedef NODEMH* TREE;

/*=====================================================*/
/*=================END struct MH=======================*/
/*=====================================================*/

/*=====================================================*/
/*=================Struct LOPTC  ======================*/
/*=====================================================*/
struct SVDANGKY{
	string MASV;/*primary1*/
	int DIEM;
	
};
struct nodeDK{
	SVDANGKY SV;
	nodeDK *next;
};
typedef nodeDK* DSDANGKY;
struct LOPTINCHI{
	unsigned int MALOPTC;/*primary1*/
	char MAMH[10];/*primary2=MAMH,NIENKHOA,HOCKY,NHOM*/
	unsigned int KHOA;
	unsigned int HOCKY;
	unsigned int NHOM;
	unsigned int MAXSV;
	DSDANGKY SV;
};
struct DSLOPTINCHI{
	unsigned int SOLUONG;
	LOPTINCHI *LOP[MAXLOPTINCHI];
};

/*=====================================================*/
/*=================END struct LOPTC  ==================*/
/*=====================================================*/

void SV_PRINTINFODETAIL(int sodong,MAXCOT NEWCOT,char *Tenlop,LISTSV &p,int curentpage,int x,int y,int type=2);
void SV_KHUNGEDITSV(MAXCOT NEWCOT,LISTSV p,int type = 0);
void MH_KHUNGEDITMH(MAXCOT NEWCOT,TREE p,int type =0);
void TC_KHUNGEDITTC(MAXCOT NEWCOT,LOPTINCHI p,int type =0);
#endif

void DialogLoginCheck();
/*==========================================================================*/
/*=======================Phan xu ly Sinh vien===============================*/
/*==========================================================================*/
void LOP_BUBBLE_SORT(DSLOP LISTLOP);
void LOP_CAPNHATDANHSACHLOP(char *TENLOP);
int SV_CHECKLOGINSV (char *userlogin,char *passlogin);

void SV_Clearlist(LISTSV &FIRSTSV);

int SV_Delete_First (LISTSV  &FIRSTSV);
int SV_Delete_after(LISTSV p);
int SV_Delete_info(LISTSV &FIRSTSV,STUDENT x);

void SV_DRAWTABLENHAPSV(int sodong,char *TENLOP,int type);

int SV_Empty(LISTSV FIRSTSV);
int SV_GETCOUNTSV(char *MALOP);

void SV_Initialize(LISTSV &FIRSTSV);

void SV_Init();/*khoi tao du lieu sinh vien*/
void LOP_Insertion_sort(DSLOP LISTLOP);
void SV_Insert_First(LISTSV &FIRSTSV, STUDENT x);
void SV_Insert_after(LISTSV p, STUDENT x);



LISTSV SV_Newnode(void);
MAXCOT SV_NEWCOT();
MAXCOT LOP_NEWCOT();
void LOP_SEARCH_ADD(int type);

void LOP_PRINTLISTLOP();
void SV_PRINTINFO(int sodong,MAXCOT NEWCOT,char *Tenlop,int type);
void LOP_PRINTINFODETAIL(int sodong,int *p,int curentpage,int x,int y,int type);
void LOP_PRINTINFO(int type);
void LOP_RELOADLIST();

void SV_SEARCH();
bool LOP_SEARCH(char *TENLOP);

LISTSV SV_SEARCH_INFO(LISTSV FIRSTSV, STUDENT x);
LISTSV SV_SEARCH_INFO_CLASS(LISTSV FIRSTSV, char *Tenlop);
LISTSV SV_SEARCH_INFO_MSSV(LISTSV FIRSTSV, string MSSV);
LISTSV SV_SEARCH_INFO_MSSV_EX(LISTSV FIRSTSV, string MSSV,LISTSV p);

void SV_SELECTION_SORT(LISTSV &FIRSTSV);


/*==========================================================================*/
/*================================END XULY SINH VIEN========================*/
/*==========================================================================*/




/*==========================================================================*/
/*=======================Phan xu ly MON HOC  ===============================*/
/*==========================================================================*/

MONHOC MH_CREAT();

int MH_EMPTY(TREE root);
void MH_FREETEMP(TREE &TEMP);

void MH_Init();
void MH_INSERT_NODE(TREE &p, MONHOC a);

void MH_KHUNGNHAP(MAXCOT NEWCOT);


void MH_LOADTENMH (TREE p,char **DULIEUTENMH,int *TINCHI);

MAXCOT MH_NEWCOT();
TREE MH_NEWNODE();

void MH_ADDNEW();
void MH_SAVEFILE (TREE p);

void MH_PRINTINFO(int sodong,int type,TREE ROOTTEMP);
void MH_PRINTINFODETAIL(int sodong,TREE &p,int curentpage,int x,int y,int type);
void MH_PRINTMH(int type);

void MH_RECOUNTTC (TREE p);
void MH_REMOVE_CASE_3 ( TREE &r,TREE &rp );
void MH_REMOVE_NODE (int x , TREE &p );

TREE MH_SEARCH_NODE (TREE root, int x);
void MH_SEARCH(TREE &ROOTTEMP);
TREE MH_SEARCH_MIN();

void MH_SELECTION_SORT(TREE &p);
int MH_DELETE_INFO(TREE &ROOTTEMP,char *x);

/*==========================================================================*/
/*================================END XULY MONHOC   ========================*/
/*==========================================================================*/


/*==========================================================================*/
/*=======================Phan xu ly LOPTC    ===============================*/
/*==========================================================================*/
void TC_Init();

MAXCOT DIEM_NEWCOT(int type);
MAXCOT TC_NEWCOT();
MAXCOT DIEM_NEWCOTINFO();
void TC_KHUNGADD(MAXCOT NEWCOT);

LOPTINCHI *TC_CREATNEWCLASS();
bool TC_CHECKEXIT(LOPTINCHI *p);
bool TC_CHECKEXITEX(LOPTINCHI *p,int q);
void TC_PRINTINFO(int type);
void TC_PRINTINFODETAIL(int sodong,int *p,int curentpage,int x,int y,int type);
int TC_DELETE_ITEM (int i);
void TC_SEARCH();
int TC_SEARCH_INFO( char  *info);
int TC_SEARCH_INFOMATC( int  info);
int TC_SEARCH_MAXVAL();
void TC_QUICK_SORT(DSLOPTINCHI LISTTC);
void TC_Insertion_sort(DSLOPTINCHI LISTTC);
void TC_QUICK_SORT_EX(DSLOPTINCHI LISTTC, int q,int r);
int TC_CHECKSV(char *MAMH);
/*==========================================================================*/
/*================================END XULY LOPTC  ========================*/
/*==========================================================================*/




/*==========================================================================*/
/*============================Phan xu ly DSDANGKY  ========================*/
/*==========================================================================*/
DSDANGKY DK_NEWNODE();
void DIEM_PRINTINFO(int sodong,int curCLASS,int type);
void DK_LOADSOLUONGSV(int curCLASS,int type);
void DIEM_PRINTINFODETAIL(int sodong,DSDANGKY &p,int curentpage,int x,int y,int type);
int DK_LOADNUMOFTC(int curCLASS);
void DIEM_INSERT_FIRST(DSDANGKY &q, SVDANGKY x);
void DIEM_INSERT_AFTER(DSDANGKY p, SVDANGKY x);
void DIEM_SELECTION_SORT(DSDANGKY &HEAD);
void DK_CLEARLIST(DSDANGKY &HEAD);
void DK_Init(string MSSV);
int DK_SEARCH_INFO_MSSV(DSDANGKY HEAD, string MSSV);
DSDANGKY DK_SEARCH_INFO_MSSV_p(DSDANGKY HEAD, string MSSV);
bool DK_CHECKDANGKYMON(char *MAMH);
bool DK_CHECKDANGKY(string MSSV,char *MAMH);
int DK_DELETE_INFO_MSSV(DSDANGKY &HEAD,string MSSV);
int DK_DELETE_INFO(DSDANGKY &HEAD,SVDANGKY x);
void DK_CHANGEINFO(DSDANGKY &HEAD,string oldMSSV,string MSSV);
int DIEM_CHECKCODIEM(DSDANGKY HEAD);
int DIEM_MAXDIEM(string MSSV,char* TENMH);
/*==========================================================================*/
/*=======================  END  xu ly DSDANGKY   ===============================*/
/*==========================================================================*/



/*==========================================================================*/
/*================================Phan xu ly DIEM  ======================*/
/*==========================================================================*/
MAXCOT TK_NEWCOT();
void TK_PRINTINFO(int sodong,char *Tenlop,int type);/*in thong tin sinh vien*/
void TK_PRINTINFOTBDETAIL(int sodong,int *p,int curentpage,int x,int y,int **BANGDIEM,string *DULIEUMASV,int *TINCHI);
void TK_PRINTINFODETAIL(int sodong,int *p,int curentpage,int x,int y,int **BANGDIEM,string *DULIEUMASV,int curswappage,int socot,char **DULIEUTENMH);
/*==========================================================================*/
/*=======================  END  xu ly DIEM   ===============================*/
/*==========================================================================*/





/*==========================================================================*/
/*================================PHAN LUU DU LIEU   ======================*/
/*==========================================================================*/
void TC_SAVEFILE();
void TC_CREATNEWCLASS_SAVE();
void TC_RESAVEDK();
void TC_SAVEONECLASS(int curCLASS);


void MH_SAVENEWFILE();


void SV_SAVEFILE(char *Tenlop);
/*==========================================================================*/
/*================================END PHAN LUU DU LIEU======================*/
/*==========================================================================*/
