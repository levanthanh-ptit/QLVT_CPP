#ifndef main_H
#define main_H

#include <iostream>
#include <string>
#include "Menu.h"
#include "mylib.h"
#include "NhanVien.h"

using namespace std;


void xoaVT(){
	_clear();
	for(int i = 1; i <=10; i++){
		cout<<"Da xoa VT " <<i <<"\n";
	}
	system("pause");
}

void vatTu()
{
	string label[3] = {"Them VT", "Xoa VT", "Sua VT"};
	void(*funcs[3])();
	funcs[1] = xoaVT;
	Menu mainMenu(label, 3, funcs); // 3 la size cua Menu.
	mainMenu.run();
}
void nhanVien()
{
	_clear();
	cout<<"Bye...\n";
	system("pause");
}
int main(){
	cursorVisable(false);
	bool flag = true;
	string label[4] = {"Vat tu", "Nhan vien", "Hoa don", "CT hoa don"};
	void(*funcs[4])();
	funcs[0] = vatTu;
	funcs[1] = nhanVien;
	Menu mainMenu(label, 4, funcs); // 4 la size cua Menu.
	mainMenu.run();
	return 0;
}
#endif
