#ifndef Vattu_H
#define Vattu_H

#include <iostream>
#include <string>
#include <cstring>
#include <stdio.h>
#include <fstream>
#include "Util.h"
using namespace std;

/*file stream*/
ofstream f1;//write stream

struct Vattu{
	char MAVT[10];
	char TENVT[100];
	char DVT[100];
	double soluongton;
};
struct DsVattu{
	int num=0; // so luong vat tu da co
	Vattu* _vattu[100]; // container chua data
} DataVattu;

Vattu* clone(Vattu *vt){
	Vattu *ret = new Vattu;
	copy(vt->MAVT, ret->MAVT, 10);
	copy(vt->TENVT, ret->TENVT, 100);
	copy(vt->DVT, ret->DVT, 100);
	ret->soluongton = vt->soluongton;
	return ret;
}

void save_Vattu()
{
	f1.open("Data/DataVattu.data", ios::binary);
	if(!f1){
		cout <<"file error";
		getch();
	} 
	system("cls");
	cout <<"Save Vattu start:\n";
	f1 <<DataVattu.num;
	for(int i=0; i<DataVattu.num; i++){
		cout <<">>save: " <<DataVattu._vattu[i]->MAVT <<":::" <<DataVattu._vattu[i]->TENVT <<":::" <<DataVattu._vattu[i]->DVT <<":::" <<DataVattu._vattu[i]->soluongton <<'\n';
		f1.write((char*)DataVattu._vattu[i],sizeof(Vattu));
	}
	f1.close();
}

void initdataVattu(){
	ifstream f;
	f.open("Data/DataVattu.data",ios::binary);
	int n;
	f >> n;
	DataVattu.num = n;
	cout <<"Number of Vattu: " <<n <<endl;

	if(n==NULL||n<=0||n>=100) {
		cout <<"Seeding data:\n";
		DataVattu.num = 12;
		for(int i=0; i<12; i++){
			Vattu* vt = new Vattu;
			string MAVT = "MAVT";
			MAVT += genericToString(i+1);
			MAVT+='\0';
			string TENVT = "TENVT";
			TENVT += genericToString(i+1);
			TENVT +='\0';
			string DVT = "DVT";
			DVT += genericToString(i+1);
			DVT +='\0';

			copy(MAVT, vt->MAVT, 10);
			copy(TENVT, vt->TENVT, 100);
			copy(DVT, vt->DVT, 100);
			vt->soluongton = i;
			
			cout <<vt->MAVT <<endl;
			DataVattu._vattu[i] = vt;
		}
	} 
	else
	for(int i=0; i<DataVattu.num; i++){
		Vattu *x = new Vattu; // require 'new' to memory set x point to that memmories
		int size = sizeof(Vattu);
		f.read((char*)&*x, size);
		DataVattu._vattu[i] = x;
	}
	cout <<"finish load data Vattu.\n";
	f.close();
}

void Insert(DsVattu &ds,int pos,Vattu *vt )
{
	for(int i = ds.num;i > pos; i--){
		ds._vattu[i] = ds._vattu[i-1];
	}
	ds._vattu[pos] = vt;
	ds.num ++;
}
bool Find_VT(DsVattu &ds, char p[])
{
	for(int i = 0;i < ds.num; i++){
		if(strcmp(ds._vattu[i]->MAVT , p)==0) return true;
	}
	return false;
} 

void FindandInsert(DsVattu &ds,Vattu *vt)
{
	if(Find_VT(ds ,vt->MAVT)) return;
	for(int i=0;i<ds.num;i++){
		if(strcmp(ds._vattu[i]->MAVT , vt->MAVT)>0){
			Insert(ds,i,vt);
			return ;
		}
	}
	Insert(ds,ds.num,vt);
	return ;
}

int Find_VT_return(DsVattu &ds,char *MaVT){
	for(int i=0;i<ds.num;i++){
		if(strcmp(ds._vattu[i]->MAVT,MaVT)==0) return i;
	}
	return -1; // khong tim thay
}

void deleteVattu(int n,DsVattu &ds){
	for(int i=n;i<ds.num-1;i++)
	{
		ds._vattu[i] = ds._vattu[i+1];
	}
	ds.num --;
}

#endif
