#ifndef Menu_H
#define Menu_H

#include <iostream>
#include <stdio.h>
#include <string>
#include "mylib.h"

using namespace std;

void DEBG(int a){
	cout <<a <<endl;
}

class Menu{
	const int ENTER = 13;
	const int KEY_UP = 72;
	const int KEY_DOWN = 80;
	string* menu;
	int menuLength;
	int selected;
	void (**delegateFunc)();
	private:
		void printMenu(){
			_clear();
			for(int i = 0; i < menuLength; i++){
				if(i == selected) SetColor(6);		
				cout <<i+1 <<". " <<menu[i] <<"\n";
				if(i == selected) SetColor(15);
			}
		}
	public:
		Menu();
		Menu(string p_menu[], int p_size,void (**func)()){
			delegateFunc = func;
			DEBG(p_size);
			menuLength = p_size + 1;
			menu = new string[ p_size + 1 ];
			for(int i = 0; i< p_size; i++){
				menu[i] = p_menu[i];
			}
			menu[p_size] = "Thoat";
			selected = 0;
		}
		void run(){
			bool flag = true;
			char keyPressed;
			while(flag){
				printMenu();
				keyPressed = getch();
				if(keyPressed != ENTER)
					keyPressed = getch();
				if(keyPressed == KEY_DOWN){
					selected = (selected + 1)%menuLength;
				}
				else
				if(keyPressed == KEY_UP){
					selected = (selected - 1);
					if(selected<0) selected = menuLength - 1;
				}
				else
				if(keyPressed == ENTER){
					if(selected == menuLength -1) flag = false;
					(*delegateFunc[selected])();
				}
			}
		}
};	
#endif
