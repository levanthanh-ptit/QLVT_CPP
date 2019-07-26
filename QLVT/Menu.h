#ifndef Menu_H
#define Menu_H

#include <iostream>
#include <stdio.h>
#include <string>
#include "mylib.h"
#include "Util.h"

using namespace std;

void DEBUG(int a){
	cout <<a <<endl;
}
void DEBUG(bool a){
	cout <<(a?"true":"false") <<endl;
}

typedef void(*FunctionPointer)();


		
class Menu{
	const int ENTER = 13;
	const int KEY_UP = 72;
	const int KEY_DOWN = 80;
	string* menu;
	int menuLength;
	int selected;
	int paddingL, paddingR;
	FunctionPointer *delegateFunc;
	private:
		void drawCaculate(){
		paddingL = (banner_size - 2 - title.length())/2;
		if((banner_size - title.length())%2==1) paddingR = paddingL+1;
		else paddingR = paddingL;
		}	
	public:
		int banner_size = 100;
		string title;
		
		virtual void onElementAction(int p_selected){
			(*delegateFunc[selected])();
		}
		
		void printMenu(){
			_clear();
			if(title.compare("")!=0) 
				cout<<(char)201 <<*new string(banner_size-2, (char)205) <<(char)187 <<'\n'
					<<(char)186 <<*new string(paddingL,' ') <<title <<*new string(paddingR,' ') <<(char)186 <<"\n"
					<<(char)200 <<*new string(banner_size-2, (char)205) <<(char)188 <<"\n\n";
			
				cout <<(char)201 <<*new string(banner_size-2, (char)205) <<(char)187 <<'\n';
				
			for(int i = 0; i < menuLength; i++){
				if(i == selected){
					SetColor(6);	
				};
				
				if(i<menuLength-1)
					cout <<' ' <<i+1 <<". " <<menu[i] <<"\n";
				else
					cout <<"\n << Thoat.";
					
				if(i == selected) {
					SetColor(15);
				}
			}
			drawBorder();
		}
		
		void drawBorder(){
			int y = wherey();
			
			for(int i = 5; i<=y+1; i++){
				gotoxy(0, i);
				cout <<(char)186;
				gotoxy(banner_size-1, i);
				cout <<(char)186;
			}
			y--;
			gotoxy(0, y);
			cout <<(char)204 <<*new string(banner_size-2, (char)205) <<(char)185 ;
			y+=2;
			gotoxy(0, y);
			cout <<(char)200 <<*new string(banner_size-2, (char)205) <<(char)188 ;
			
		}
		
		Menu();
		Menu(string p_menu[], int p_size, FunctionPointer *func){
			delegateFunc = func;
			menuLength = p_size + 1;
			menu = p_menu;
			selected = 0;
		}
		void run(){
			cursorVisable(false);
			drawCaculate();
			bool flag = true;
			char keyPressed;
			while(flag == true){
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
					if(selected == menuLength -1) {
						flag = false;
					}
					else{
						onElementAction(selected);
					}	
				}
			}
		}
};	
#endif
