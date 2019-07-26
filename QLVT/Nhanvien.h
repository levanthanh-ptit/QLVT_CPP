#include <string.h>
#include <iostream>
#include <fstream>
//#include "HoaDon.h"
using namespace std;

/*file stream*/
ofstream f2;//write stream
// danh sach nhan vien ( binary serch tree)
struct Info_NV{
	int MANV;
	char HO[100];
	char TEN[100];
	char PHAI[5];
};
struct NhanVien{
	Info_NV info;
//	DsHoaDon nv_HoaDon;			// tro den cac hoa don ma nhan vien do da lap
};
struct NodeNV{
	NhanVien nv;
	NodeNV* left;
	NodeNV* right; 
};

typedef struct NodeNV* NVTree;

struct DsNhanVien{
	NVTree _nhanvien;
	int num = 0;
} DataNhanVien;

NhanVien* newNhanVien(int MANV, char HO[100], char TEN[100], char PHAI[5]){
	NhanVien *nv = new NhanVien;
	nv->info.MANV = MANV;
	strcpy(nv->info.HO, HO);
	strcpy(nv->info.TEN, TEN);
	strcpy(nv->info.PHAI, PHAI);
	return nv;
}

NodeNV* newNodeNV(int MANV, char HO[100], char TEN[100], char PHAI[5]){
	NodeNV* nodeNV = new NodeNV;
	nodeNV->nv.info.MANV = MANV;
	strcpy(nodeNV->nv.info.HO, HO);
	strcpy(nodeNV->nv.info.TEN, TEN);
	strcpy(nodeNV->nv.info.PHAI, PHAI);
	nodeNV->left = NULL;
	nodeNV->right = NULL;
	return nodeNV;
}

void travelLNR(NVTree &root, NhanVien** collector, int &count){
	if(root->left != NULL) travelLNR(root->left, collector, count);
	collector[count] = &root->nv;
	count++;
	if(root->right != NULL) travelLNR(root->right, collector, count);
}

void insertNodeNV(NVTree &root, NodeNV* node){
	if(root == NULL) {
		root = node;
		return;
	}
	if(root->nv.info.MANV > node->nv.info.MANV)
		insertNodeNV(root->left, node);
	if(root->nv.info.MANV < node->nv.info.MANV)
		insertNodeNV(root->right, node);
}

void deleteNodeNV(NVTree &root, int MANV){
	if(root == NULL) return;
	else
	if(root->nv.info.MANV > MANV) deleteNodeNV(root->left, MANV);
	else
	if(root->nv.info.MANV < MANV) deleteNodeNV(root->right, MANV);
	else
	if(root->nv.info.MANV == MANV){
		if(root->left == NULL) root = root->right;
		else
		if(root->right == NULL) root = root->left;
		else{
			NodeNV* p = root->left;
			while(p->right == NULL){
				p = p->right;
			}
			memcpy(&(root->nv), &(p->nv), sizeof(NhanVien));
			deleteNodeNV(root->left, p->nv.info.MANV);
		}	
	}
}

void deleteNhanVien(DsNhanVien &ds, int MANV){
	
	deleteNodeNV(ds._nhanvien, MANV);
	ds.num--;
}

void addNhanVien(DsNhanVien &ds, int MANV, char HO[100], char TEN[100], char PHAI[5]){
	NodeNV * nv = newNodeNV(MANV, HO, TEN, PHAI);
	insertNodeNV(ds._nhanvien, nv);
	ds.num++;	
}

void addNhanVien(DsNhanVien &ds, NodeNV* nv){
	insertNodeNV(ds._nhanvien, nv);
	ds.num++;
}

void initDataNhanVien(){
	for(int i = 0; i < 4; i++){
		char HO[100] = "Nguyen";
		char TEN[100] = "Van A";
		char PHAI[5] = "Nam";
		NodeNV *nv = newNodeNV(i*3, HO, TEN, PHAI);
		insertNodeNV(DataNhanVien._nhanvien, nv);
		DataNhanVien.num++;
	}
	cout <<">>4 NhanVien was init.\n";
}















