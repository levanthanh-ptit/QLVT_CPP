#ifndef main_H
#define main_H

#include <iostream>
#include <string>
#include "Menu.h"
#include "mylib.h"
#include "Util.h"
#include "VattuGUI.h"
#include "NhanvienGUI.h"

using namespace std;

int main(){
	//
	// Vattu Init
	//
	initdataVattu();
	initDataNhanVien();
	getch();
	
	/**/
	cursorVisable(false);
	bool flag = true;
	string label[4] = {"Quan ly Vat tu", "Quan ly Nhan vien", "Quan ly Hoa don", "Quan ly CT hoa don"};
	void(*funcs[4])();
	funcs[0] = vatTu;
	funcs[1] = nhanVien;
	int menu_size = 4;
	Menu mainMenu(label, menu_size, funcs);
	mainMenu.title="QUAN LY VAT TU";
	mainMenu.run();

	/**/
	
	save_Vattu();
	return 0;
}
#endif
