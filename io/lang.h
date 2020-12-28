#include <io.h>

#ifndef SVLANG
#define SVLANG

#define COLORCHECK 242
#define COLORSELECT 242
#define COLORDISABLE 143
#define COLORDISABLE2 248

#define COLORMAIN 162 
#define COLORMAINR 47
#define COLORMAINSUB 250 
#define COLORMAINRSUB 47

#define COLORDEFAUL 240
#define COLORRDEFAUL 47

#define COLORIMPORTANT 252
#define COLORTEXTALERT 207

#define COLORKHUNG 243
#define COLORSWSELECT 242
#define COLORTITLETEXT 47
#define SELECTPOITER L"\u25ba"

#define UNCHECKBOX L"\u25a1"
#define CHECKEDBOX L"\u25a0"
#define C_CHECKEDBOX L"\u25cf"
#define C_UNCHECKBOX L"\u25cb"
#define NumMenu 4 // so luong Menu
#define NumMenu2 1 // so luong Menu
#define MENUMAINPADDINGLEFT 2//Chu cach le trai Menu
#define MENUMAINTEXTLEN 35 // Do dai chu trong menu chinh
#define NUMHINT 11  /*so luong phan GOI Y*/

const wchar_t MenuName[5][NumMenu][MENUMAINTEXTLEN-MENUMAINPADDINGLEFT] = {
{/*0-menu main*/
	L"L\u1EDAP T\u00CDN CH\u1EC8",
	L"SINH VI\u00CAN",
	L"M\u00D4N H\u1ECCC",
	L"\u0110I\u1EC2M"
},
{/*1-menu LOPTC*/
	L"Th\u00EAm l\u1EDBp t\u00EDn ch\u1EC9",
	L"X\u00F3a v\u00E0 s\u1EEDa l\u1EDBp t\u00EDn ch\u1EC9",
	L"T\u00ECm l\u1EDBp t\u00EDn ch\u1EC9",
	L"DSSV l\u1EDBp t\u00EDn ch\u1EC9"
},
{/*2-menu sinh vien*/
	L"Th\u00EAm SV/Th\u00EAm l\u1EDBp",
	L"X\u00F3a v\u00E0 s\u1EEDa sinh vi\u00EAn",
	L"T\u00ECm sinh vi\u00EAn",
	L"In DSSV m\u1ED9t l\u1EDBp"
},
{/*3-menu Monhoc*/
	L"Th\u00EAm m\u00F4n h\u1ECDc",
	L"X\u00F3a v\u00E0 s\u1EEDa m\u00F4n h\u1ECDc",
	L"\u0110\u0103ng k\u00FD m\u00F4n h\u1ECDc",
	L"In danh s\u00E1ch m\u00F4n h\u1ECDc"
},
{/*4-menu Diem*/
	L"Nh\u1EADp \u0111i\u1EC3m l\u1EDBp t\u00EDn ch\u1EC9",
	L"B\u1EA3ng \u0111i\u1EC3m m\u00F4n h\u1ECDc",
	L"\u0110i\u1EC3m trung b\u00ECnh",
	L"\u0110i\u1EC3m t\u1ED5ng k\u1EBFt"
}	
};
const wchar_t MenuName2[NumMenu][MENUMAINTEXTLEN-MENUMAINPADDINGLEFT] = {

	L"\u0110\u0103ng k\u00FD m\u00F4n h\u1ECDc",
	L" "
};
const wchar_t MenuTITLE[5][NumMenu][70] = {
{/*0-menu main*/
	L"  CH\u1EE8C N\u0102NG L\u1EDAP T\u00CDN CH\u1EC8  ",
	L"      CH\u1EE8C N\u0102NG SINH VI\u00CAN     ",
	L"   CH\u1EE8C N\u0102NG M\u00D4N H\u1ECCC   ",
	L"     CH\u1EE8C N\u0102NG \u0110I\u1EC2M      "
},
{/*1-menu LOPTC*/
	L"  M\u1EDE L\u1EDAP T\u00CDN CH\u1EC8 M\u1EDAI  ",
	L"   CH\u1EC8NH S\u1EECA L\u1EDAP T\u00CDN CH\u1EC8 THEO DANH S\u00C1CH   ",
	L"   T\u00CCM KI\u1EBEM L\u1EDAP T\u00CDN CH\u1EC8   ",
	L"   IN DANH S\u00C1CH SINH VI\u00CAN L\u1EDAP T\u00CDN CH\u1EC8   "
},
{/*2-menu sinh vien*/
	L"   TH\u00CAM SINH VI\u00CAN M\u1EDAI, TH\u00CAM L\u1EDAP M\u1EDAI   ",
	L"   CH\u1EC8NH S\u1EECA SINH VI\u00CAN THEO DANH S\u00C1CH L\u1EDAP   ",
	L"   T\u00CCM KI\u1EBEM V\u00C0 CH\u1EC8NH S\u1EECA SINH VI\u00CAN   ",
	L"   IN DANH S\u00C1CH SINH VI\u00CAN THEO T\u00CAN L\u1EDAP   "
},
{/*3-menu Monhoc*/
	L"   TH\u00CAM M\u00D4N H\u1ECCC M\u1EDAI   ",
	L"   CH\u1EC8NH S\u1EECA M\u00D4N H\u1ECCC THEO DANH S\u00C1CH   ",
	L"   \u0110\u0102NG K\u00DD M\u00D4N H\u1ECCC   ",
	L"   IN DANH S\u00C1CH M\u00D4N H\u1ECCC   "
},
{/*4-menu Diem*/
	L"   NH\u1EACP \u0110I\u1EC2M CHO SINH VI\u00CAN THEO L\u1EDAP T\u00CDN CH\u1EC8   ",
	L"   B\u1EA2NG \u0110I\u1EC2M C\u1EE6A M\u1ED8T L\u1EDAP T\u00CDN CH\u1EC8   ",
	L"   B\u1EA2NG TH\u1ED0NG K\u00CA \u0110I\u1EC2M TRUNG B\u00CCNH KH\u00D3A H\u1ECCC   ",
	L"   B\u1EA2NG \u0110I\u1EC2M T\u1ED4NG K\u1EBET   "
}	
};

const wchar_t MenuHINT[NUMHINT][MENUMAINTEXTLEN-MENUMAINPADDINGLEFT] = {
		L"\u2191 : Lên",
		L"\u2193 : Xu\u1ed1ng",
		L"Di chuy\u1EC3n b\u1EB1ng m\u0169i t\u00EAn",
		L"Nh\u1EA5n ENTER \u0111\u1EC3 ch\u1ECDn",
		L"Nh\u1EA5n ESC \u0111\u1EC3 \u0111\u0103ng xu\u1EA5t"
	};
const wchar_t GUIDE[5][NumMenu][NUMHINT][MENUMAINTEXTLEN-MENUMAINPADDINGLEFT] = {
{/*0-menu main*/
	{
		L"\u2191 : Lên",
		L"\u2193 : Xu\u1ed1ng",
		L"Di chuy\u1EC3n b\u1EB1ng m\u0169i t\u00EAn",
		L"Nh\u1EA5n ENTER \u0111\u1EC3 ch\u1ECDn",
		L"Nh\u1EA5n ESC \u0111\u1EC3 quay l\u1EA1i"
	},
	{
		L"\u2191 : Lên",
		L"\u2193 : Xu\u1ed1ng",
		L"Di chuy\u1EC3n b\u1EB1ng m\u0169i t\u00EAn",
		L"Nh\u1EA5n ENTER \u0111\u1EC3 ch\u1ECDn",
		L"Nh\u1EA5n ESC \u0111\u1EC3 quay l\u1EA1i"
	},
	{
		L"\u2191 : Lên",
		L"\u2193 : Xu\u1ed1ng",
		L"Di chuy\u1EC3n b\u1EB1ng m\u0169i t\u00EAn",
		L"Nh\u1EA5n ENTER \u0111\u1EC3 ch\u1ECDn",
		L"Nh\u1EA5n ESC \u0111\u1EC3 quay l\u1EA1i"
	},
	{
		L"\u2191 : Lên",
		L"\u2193 : Xu\u1ed1ng",
		L"Di chuy\u1EC3n b\u1EB1ng m\u0169i t\u00EAn",
		L"Nh\u1EA5n ENTER \u0111\u1EC3 ch\u1ECDn",
		L"Nh\u1EA5n ESC \u0111\u1EC3 quay l\u1EA1i"
	}
	
},
{/*1-menu LOPTC*/
	{
		L"\u2191 : Lên",
		L"\u2193 : Xu\u1ed1ng",
		L"Di chuy\u1EC3n ch\u1ECDn m\u00F4n h\u1ECDc m\u1EDF l\u1EDBp",
		L"Nh\u1EA5n ENTER m\u1EDF l\u1EDBp ",
		L"Nh\u1EA5n ESC \u0111\u1EC3 quay l\u1EA1i"
	},
	{
		L"\u2191 : Lên",
		L"\u2193 : Xu\u1ed1ng",
		L"Di chuy\u1EC3n b\u1EB1ng m\u0169i t\u00EAn",
		L"Nh\u1EA5n F2 ch\u1EC9nh s\u1EEDa l\u1EDBp \u0111\u00E3 ch\u1ECDn",
		L"Nh\u1EA5n F3 \u0111\u1EC3 t\u00ECm ki\u1EBFm",
		L"Nh\u1EA5n F4 \u0111\u1EC3 l\u01B0u thao t\u00E1c",
		L"Nh\u1EA5n DEL \u0111\u1EC3 x\u00F3a l\u1EDBp \u0111\u00E3 ch\u1ECDn",
		L"Nh\u1EA5n ESC \u0111\u1EC3 quay l\u1EA1i"
	},
	{
		L"M\u00E3 l\u1EDBp tr\u1ED1ng s\u1EBD tho\u00E1t",
		L"Nh\u1EA5n F2 ch\u1EC9nh s\u1EEDa l\u1EDBp \u0111\u00E3 t\u00ECm",
		L"Nh\u1EA5n F4 \u0111\u1EC3 l\u01B0u thao t\u00E1c",
		L"Nh\u1EA5n DEL \u0111\u1EC3 x\u00F3a l\u1EDBp \u0111\u00E3 t\u00ECm",
		L"Nh\u1EA5n ESC \u0111\u1EC3 quay l\u1EA1i"
	},
	{
		L"\u2191 : Lên",
		L"\u2193 : Xu\u1ed1ng",
		L"Di chuy\u1EC3n b\u1EB1ng m\u0169i t\u00EAn",
		L"Nh\u1EA5n ENTER \u0111\u1EC3 ch\u1ECDn",
		L"Nh\u1EA5n PAGEUP, PAGEDN \u0111\u1ED5i trang",
		L"Nh\u1EA5n ESC \u0111\u1EC3 quay l\u1EA1i"
	}
},
{/*2-menu sinh vien*/
	{
		L"\u2191 : Lên",
		L"\u2193 : Xu\u1ed1ng",
		L"Di chuy\u1EC3n ch\u1ECDn l\u1EDBp th\u00EAm SV",
		L"Nh\u1EA5n F3 \u0111\u1EC3 t\u00ECm l\u1EDBp/Th\u00EAm l\u1EDBp",
		L"Nh\u1EA5n ENTER th\u00EAm sinh vi\u00EAn",
		L"Khi nh\u1EADp nh\u1EA5n \u2190 \u2192 \u0111\u1EC3 ch\u1ECDn ph\u00E1i",
		L"M\u00E3 SV tr\u1ED1ng s\u1EBD tho\u00E1t nh\u1EADp",
		L"Nh\u1EA5n F4 \u0111\u1EC3 l\u01B0u thao t\u00E1c",
		L"Nh\u1EA5n ESC \u0111\u1EC3 quay l\u1EA1i"
	},
	{
		L"\u2191 : Lên",
		L"\u2193 : Xu\u1ed1ng",
		L"Di chuy\u1EC3n b\u1EB1ng m\u0169i t\u00EAn",
		L"Nh\u1EA5n F2 ch\u1EC9nh s\u1EEDa SV \u0111\u00E3 ch\u1ECDn",
		L"Nh\u1EA5n F3 \u0111\u1EC3 t\u00ECm ki\u1EBFm",
		L"Nh\u1EA5n F4 \u0111\u1EC3 l\u01B0u thao t\u00E1c",
		L"Nh\u1EA5n DEL \u0111\u1EC3 x\u00F3a SV \u0111\u00E3 ch\u1ECDn",
		L"Nh\u1EA5n ESC \u0111\u1EC3 quay l\u1EA1i"
	},
	{
		L"M\u00E3 SV tr\u1ED1ng s\u1EBD tho\u00E1t",
		L"Nh\u1EA5n F2 ch\u1EC9nh s\u1EEDa SV \u0111\u00E3 t\u00ECm",
		L"Nh\u1EA5n F4 \u0111\u1EC3 l\u01B0u thao t\u00E1c",
		L"Nh\u1EA5n DEL \u0111\u1EC3 x\u00F3a SV \u0111\u00E3 t\u00ECm",
		L"Nh\u1EA5n ESC \u0111\u1EC3 quay l\u1EA1i"
	},
	{
		L"\u2191 : Lên",
		L"\u2193 : Xu\u1ed1ng",
		L"Di chuy\u1EC3n b\u1EB1ng m\u0169i t\u00EAn",
		L"Nh\u1EA5n ENTER \u0111\u1EC3 ch\u1ECDn",
		L"Nh\u1EA5n PAGEUP, PAGEDN \u0111\u1ED5i trang",
		L"Nh\u1EA5n ESC \u0111\u1EC3 quay l\u1EA1i"
	}
},
{/*3-menu Monhoc*/
	{
		L"\u2191 : Lên",
		L"\u2193 : Xu\u1ed1ng",
		L"Di chuy\u1EC3n s\u1EEDa th\u00F4ng tin tr\u00F9ng",
		L"Nh\u1EA5n F4 \u0111\u1EC3 l\u01B0u thao t\u00E1c",
		L"Nh\u1EA5n ESC \u0111\u1EC3 quay l\u1EA1i"
	},
	{
		L"\u2191 : Lên",
		L"\u2193 : Xu\u1ed1ng",
		L"Di chuy\u1EC3n b\u1EB1ng m\u0169i t\u00EAn",
		L"Nh\u1EA5n F2 ch\u1EC9nh s\u1EEDa MH \u0111\u00E3 ch\u1ECDn",
		L"Nh\u1EA5n F3 \u0111\u1EC3 t\u00ECm ki\u1EBFm",
		L"Nh\u1EA5n F4 \u0111\u1EC3 l\u01B0u thao t\u00E1c",
		L"Nh\u1EA5n DEL \u0111\u1EC3 x\u00F3a MH \u0111\u00E3 ch\u1ECDn",
		L"Nh\u1EA5n ESC \u0111\u1EC3 quay l\u1EA1i"
	},
	{
		L"\u2191 : Lên",
		L"\u2193 : Xu\u1ed1ng",
		L"Di chuy\u1EC3n b\u1EB1ng m\u0169i t\u00EAn",
		L"M\u00E3 SV tr\u1ED1ng s\u1EBD tho\u00E1t",
		L"Nh\u1EA5n ENTER ch\u1ECDn, h\u1EE7y m\u00F4n",
		L"Nh\u1EA5n F4 \u0111\u1EC3 l\u01B0u thao t\u00E1c",
		L"M\u00E0u \u0111\u1ECF l\u00E0 \u0111\u00E3 c\u00F3 \u0111i\u1EC3m",
		L"Nh\u1EA5n ESC \u0111\u1EC3 quay l\u1EA1i"
	},
	{
		
		L"Nh\u1EA5n PAGEUP, PAGEDN \u0111\u1ED5i trang",
		L"Nh\u1EA5n ESC \u0111\u1EC3 quay l\u1EA1i"
	}
},
{/*4-menu Diem*/
	{
		L"\u2191 : Lên",
		L"\u2193 : Xu\u1ed1ng",
		L"Di chuy\u1EC3n ch\u1ECDn l\u1EDBp nh\u1EADp \u0111i\u1EC3m",
		L"Nh\u1EA5n ENTER nh\u1EADp \u0111i\u1EC3m",
		
		L"Nh\u1EA5n F4 \u0111\u1EC3 l\u01B0u thao t\u00E1c",
		L"Nh\u1EA5n ESC \u0111\u1EC3 quay l\u1EA1i"
	},
	{
		L"\u2191 : Lên",
		L"\u2193 : Xu\u1ed1ng",
		L"Di chuy\u1EC3n b\u1EB1ng m\u0169i t\u00EAn",
		
		L"Nh\u1EA5n ENTER \u0111\u1EC3 ch\u1ECDn",
		L"Nh\u1EA5n PAGEUP, PAGEDN \u0111\u1ED5i trang",
		L"Nh\u1EA5n ESC \u0111\u1EC3 quay l\u1EA1i"
	},
	{
		L"\u2191 : Lên",
		L"\u2193 : Xu\u1ed1ng",
		L"Di chuy\u1EC3n b\u1EB1ng m\u0169i t\u00EAn",
		L"Nh\u1EA5n F3 \u0111\u1EC3 t\u00ECm l\u1EDBp",
		L"Nh\u1EA5n ENTER \u0111\u1EC3 ch\u1ECDn",
		L"Nh\u1EA5n PAGEUP, PAGEDN \u0111\u1ED5i trang",
		L"Nh\u1EA5n ESC \u0111\u1EC3 quay l\u1EA1i"
	},
	{
		L"\u2191 : Lên",
		L"\u2193 : Xu\u1ed1ng",
		L"Di chuy\u1EC3n b\u1EB1ng m\u0169i t\u00EAn",
		L"Nh\u1EA5n ENTER \u0111\u1EC3 ch\u1ECDn",
		L"Nh\u1EA5n PAGEUP, PAGEDN \u0111\u1ED5i trang",
		L"Nh\u1EA5n \u2190 \u2192  xem m\u00F4n kh\u00E1c",
		L"Nh\u1EA5n ESC \u0111\u1EC3 quay l\u1EA1i"
	}
}

};
#endif
