// danh sach hoa don (danh sach lien ket don)
#include "CT_HOADON.h"
struct Thongtin_HD{
	char soHD[100];
	char day[3];
	char month[3];
	char year[5];
	char loai;
};
//cau truc 1 node
struct NodeHD{
	Thongtin_HD thongtin;
	CT_HoaDon chitiet;
	NodeHD* _next;
};
//container DsHoaDon
struct DsHoaDon{
	int num = 0;
	NodeHD* hdHead;
};
void init_hd(DsHoaDon &hd){
	hd.hdHead = NULL;
	hd.num =0;
}
NodeHD* GetNode_hd(Thongtin_HD tt,CT_HoaDon ct){
	NodeHD* p = new NodeHD;
	p->thongtin = tt;
	p->chitiet = ct;
	p->_next = NULL;
	return p;
}
void addTail_HD(DsHoaDon &hd,NodeHD* p){
	if(hd.hdHead == NULL) hd.hdHead = p;
	else{
		NodeHD* q = hd.hdHead;
		while(q->_next!= NULL){
			q =q->_next;
		}
		q->_next = p;
	}
	hd.num++;
}
#define CTHEAD hd.hdHead->chitiet.ctHead

void Print_thongtin_HD(Thongtin_HD tt,int x ,int y,unsigned short int c_line[]){
	cout <<tt.soHD <<"\n";
	cout <<tt.day <<"\n";
	cout <<tt.month <<"\n";
	cout <<tt.year <<"\n";
	cout <<tt.loai <<"\n";

}
