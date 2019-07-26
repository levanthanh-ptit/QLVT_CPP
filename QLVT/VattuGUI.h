#ifndef VattuGUI_H
#define VattuGUI_H

#include "Vattu.h"
#import "SelectDataMenu.h"
#include "GeneralGUI.h"

void printVattu(Vattu* Va)
{
		cout << " Ma Vat tu   : " << Va->MAVT <<"\n";
		cout << " Ten Vat Tu  : " << Va->TENVT <<"\n";
		cout << " Don vi Tinh : " << Va->DVT <<"\n";
		cout << " So luong ton: " << Va->soluongton <<"\n\n";
}

void lietkeVattu(DsVattu ds,int batdau, int ketthuc)
{
	string title = "TONG DANH SACH VAT TU";
	printBanner(title, 100);
	for(int i = batdau ;i <= ketthuc ; i++)
	{
		cout <<" " <<i+1 <<".\n";
		printVattu(ds._vattu[i]);
	}
}

string toString(Vattu* vt){
	string s = " Ma Vat tu   : ";
	s+= vt->MAVT;
	s+="\n Ten Vat tu  : ";
	s+= vt->TENVT;
	s+="\n Don vi tinh : ";
	s+= vt->DVT;
	s+="\n So luong ton: ";
	s+= genericToString(vt->soluongton);
	s+='\n';
	return s;
}

void funcDeleteVT(int i){
	_clear();
	printBanner(*new string("XOA VAT TU"), 100);
	printVattu(DataVattu._vattu[i]);
	cout <<"Ban co chac muon xoa (y/n): ";
	char ans;
	cin >>ans;
	if(ans=='Y'||ans=='y') deleteVattu(i, DataVattu);

}

class XoaVattuAdapter: public SelectDataMenu{
	
	void printVattu(Vattu* Va)
	{
		int y_axis = wherey();
		int x_axis = textMarginLeft;
		gotoxy(x_axis, y_axis);
		cout << " Ma Vat tu   : " << Va->MAVT <<"\n";
		y_axis++;
		gotoxy(x_axis, y_axis);
		cout << " Ten Vat Tu  : " << Va->TENVT <<"\n";
		y_axis++;
		gotoxy(x_axis, y_axis);
		cout << " Don vi Tinh : " << Va->DVT <<"\n";
		y_axis++;
		gotoxy(x_axis, y_axis);
		cout << " So luong ton: " << Va->soluongton <<"\n\n";
	}
	
	public: 
		Vattu **holder;
		
		void printElement(int i) override {	
			cout <<i+1 <<".\n";
			printVattu(holder[i]);
			
		}
		
		bool onElementAction() override {
			funcDeleteVT(getIndex());
			return false;
		}	
	
		XoaVattuAdapter(int p_page_size, int &p_allElement, Vattu** p_holder)
		// call super constructor	
	 	: SelectDataMenu( p_page_size, p_allElement)
		{
			int holder_size = p_allElement;
			
			holder = new Vattu*[holder_size];
			for(int i = 0; i< holder_size; i++){
				Vattu* vt = clone(p_holder[i]);
				holder[i] = vt;
			}
	 	}
};

class XemVattuAdapter: public SelectDataMenu{
	
	void printVattu(Vattu* Va)
	{
		int y_axis = wherey();
		int x_axis = textMarginLeft;
		gotoxy(x_axis, y_axis);
		cout << " Ma Vat tu   : " << Va->MAVT <<"\n";
		y_axis++;
		gotoxy(x_axis, y_axis);
		cout << " Ten Vat Tu  : " << Va->TENVT <<"\n";
		y_axis++;
		gotoxy(x_axis, y_axis);
		cout << " Don vi Tinh : " << Va->DVT <<"\n";
		y_axis++;
		gotoxy(x_axis, y_axis);
		cout << " So luong ton: " << Va->soluongton <<"\n\n";
	}
	
	public: 
		Vattu **holder;
		
		void printElement(int i) override {	
			cout <<i+1 <<".\n";
			printVattu(holder[i]);
			
		}
		
		bool onElementAction() override {
			return true;
		}	
	
		XemVattuAdapter(int p_page_size, int p_allElement, Vattu** p_holder)
		// call super constructor	
	 	: SelectDataMenu( p_page_size, p_allElement)
		{
			int holder_size = p_allElement;
			
			holder = new Vattu*[holder_size];
			for(int i = 0; i< holder_size; i++){
				Vattu* vt = clone(p_holder[i]);
				holder[i] = vt;
			}
	 	}
};

void xoaVT(){
	_clear();
	XoaVattuAdapter deleteVTMenu(5, DataVattu.num, DataVattu._vattu);
	deleteVTMenu.title = "XOA VAT TU";
	deleteVTMenu.run();
}


void xemDSVT(){
	_clear();
	XemVattuAdapter xemVTMenu(5, DataVattu.num, DataVattu._vattu);
	xemVTMenu.title = "XEM DANH SACH VAT TU";
	xemVTMenu.run();
	
}

void themVT(){
	_clear();
	Vattu *vt = new Vattu;
	printBanner(*new string("THEM VAT TU"), 100);
	fflush(stdin);
	cout <<"Ma vat tu: ";
	cin.getline(vt->MAVT,10);
	cout <<"Ten vat tu: ";
	cin.getline(vt->TENVT,10);
	cout <<"Don vi tinh: ";
	cin.getline(vt->DVT,10);
	cout <<"so luong ton: ";
	cin >>vt->soluongton;
	Insert(DataVattu, DataVattu.num, vt);
	
}

void vatTu()
{
	string label[3] = {"Xem DS VT", "Xoa VT", "Them VT"};
	void(*funcs[3])();
	
	funcs[0] = xemDSVT;
	funcs[1] = xoaVT;
	funcs[2] = themVT;
	Menu vatTuMenu(label, 3, funcs); // 3 la size cua Menu.
	vatTuMenu.title="QUAN LY VAT TU";
	vatTuMenu.run();
}
#endif
