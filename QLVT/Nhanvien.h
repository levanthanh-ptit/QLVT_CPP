#include <string.h>
#include <iostream>
#include <fstream>
#include "HoaDon.h"
using namespace std;

/*file stream*/
ofstream f2;//write stream
// danh sach nhan vien ( binary serch tree)
struct Thongtin_NV{
	int MANV;
	char HO[100];
	char TEN[100];
	char PHAI[5];
};
struct NhanVien{
	Thongtin_NV thongtin;
	DsHoaDon nv_HoaDon;			// tro den cac hoa don ma nhan vien do da lap
};
struct NodeNV{
	NhanVien nv;
	NodeNV* left;
	NodeNV* right; 
};
typedef struct NodeNV* Tree;
int i =1;
int pt = 1;
struct DsNhanVien{
	Tree _nhanvien;
	int num = 0;
}DataNhanVien;

