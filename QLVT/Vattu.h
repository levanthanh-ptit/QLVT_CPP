#include <iostream>
#include <string>
#include <cstring>
#include <stdio.h>
#include <sstream>
#include <fstream>
using namespace std;

template <typename T>
std::string genericToString(const T& t)
{
    ostringstream oss;
    oss << t;
    return oss.str();
}
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
	Vattu _vattu[100]; // container chua data
} DataVattu;

void save_Vattu()
{
	f1.open("Data/DataVattu.data",ios::binary );
	f1.write((char*)&DataVattu, sizeof(DataVattu));
	f1.close();
}
void initdataVattu(){
	for(int i=0;i<100;i++) // toi da 100 phan tu
	{
		memset(DataVattu._vattu[i].MAVT,0,sizeof(DataVattu._vattu[i].MAVT));
		memset(DataVattu._vattu[i].TENVT,0,sizeof(DataVattu._vattu[i].TENVT));
		memset(DataVattu._vattu[i].DVT,0,sizeof(DataVattu._vattu[i].DVT));
	}
	ifstream f;
	f.open("Data/DataVattu.data",ios::binary);
	f.read((char*)&DataVattu,sizeof(DataVattu));
	f.close();
}
void Insert(DsVattu &ds,int pos,Vattu vt )
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
		if(strcmp(ds._vattu[i].MAVT , p)==0) return true;
	}
	return false;
} 
void FindandInsert(DsVattu &ds,Vattu vt)
{
	if(Find_VT(ds ,vt.MAVT)) return;
	for(int i=0;i<ds.num;i++){
		if(strcmp(ds._vattu[i].MAVT , vt.MAVT)>0){
			Insert(ds,i,vt);
			return ;
		}
	}
	Insert(ds,ds.num,vt);
	return ;
}
int Find_VT_return(DsVattu &ds,char *MaVT){
	for(int i=0;i<ds.num;i++){
		if(strcmp(ds._vattu[i].MAVT,MaVT)==0) return i;
	}
	return -1;
}

void deleteVattu(int n,DsVattu &ds){
	for(int i=n;i<ds.num-1;i++)
	{
		ds._vattu[i] = ds._vattu[i+1];
	}
	ds.num --;
	memset(ds._vattu[ds.num].MAVT,0,sizeof(ds._vattu[ds.num].MAVT));
	memset(ds._vattu[ds.num].TENVT,0,sizeof(ds._vattu[ds.num].TENVT));
	memset(ds._vattu[ds.num].DVT,0,sizeof(ds._vattu[ds.num].DVT));
}

void printVattu(Vattu Va)
{
		cout << "Ma Vat tu:    " << Va.MAVT <<"\n";
		cout << "Ten Vat Tu:   " << Va.TENVT <<"\n";
		cout << "Don vi Tinh:  " << Va.DVT <<"\n";
		cout << "So luong ton: " << Va.soluongton <<"\n";
}

void lietkeVattu(DsVattu ds,int batdau, int ketthuc,int x,int y,int SPACE,unsigned short int c_line[])
{
	for(int i = batdau ;i <= ketthuc ; i++)
	{
		printVattu(ds._vattu[i]);	// liet ke theo trang 
	}
}

