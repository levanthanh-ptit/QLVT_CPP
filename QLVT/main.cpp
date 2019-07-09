#ifndef main_H
#define main_H

#include <iostream>
#include <string>
#include "Menu.h"
#include "mylib.h"

using namespace std;

void hello()
{
	_clear();
	cout<<"Hi...\n";
	system("pause");
}
void bye()
{
	_clear();
	cout<<"Bye...\n";
	system("pause");
}
int main(){
	cursorVisable(false);
	bool flag = true;
	string a[4] = {"Vat tu", "Nhan vien", "Hoa don", "CT hoa don"};
	void(*funcs[2])();
	funcs[0] = hello;
	funcs[1] = bye;
	Menu mainMenu(a, 4, funcs);
	while(true){
		mainMenu.run();
	}
	return 0;
}
#endif
