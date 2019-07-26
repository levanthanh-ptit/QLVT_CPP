#ifndef SelectDataMenu_H
#define SelectDataMenu_H

#include <iostream>
#include <stdio.h>
#include <string>
#include "mylib.h"
#include "Util.h"
#include <fstream>


using namespace std;

fstream log;

class SelectDataMenu{
	protected:
	const int ENTER = 13;
	const int KEY_UP = 72;
	const int KEY_DOWN = 80;
	const int KEY_LEFT = 75;
	const int KEY_RIGHT = 77;

	#define KEY_F1 59
	#define KEY_F2 60
	#define KEY_F3 61
	#define KEY_F4 62
	#define KEY_F5 63
	#define KEY_F6 64
	#define KEY_F7 65
	#define KEY_F8 66
	#define KEY_F9 67
	#define KEY_F10 68
	
	int extendActionCount = 0;
	int *listExtendAction;
	string *listExtendActionLabel;
	int currentPage;
	int currentPage_size;
	int firstElementOfPage;
	int lastElementOfPage;
	int page_size;
	int* allElement;
	int allPages;
	int selectedLine = 0;
	int paddingL, paddingR, textMarginLeft = 1;
	private:
		// tinh toan banner
		void drawCalculate(){
			paddingL = (banner_size - 2 - title.length())/2;
			if((banner_size - title.length())%2==1) paddingR = paddingL+1;
			else paddingR = paddingL;
		}
		
		void key_down(){
			log <<"key down" <<selectedLine <<":::" <<currentPage_size;
			selectedLine = (selectedLine + 1)%(currentPage_size+1); // +1 vi da them nut Thoat
			log <<"end key down" <<selectedLine <<":::" <<currentPage_size;
		}
		
		void key_up(){
			log <<"key up" <<selectedLine <<":::" <<currentPage_size;
			selectedLine = (selectedLine - 1);
			if(selectedLine<0) selectedLine = currentPage_size;
			log <<"end key up" <<selectedLine <<":::" <<currentPage_size;
		}
			
		void key_left(){
			if(allPages == 0) return;
			if(currentPage > 1){
				currentPage--;
				calculateCurrentPageSize();
			}
		}
		
		void key_right(){
			if(allPages == 0) return;
			if(currentPage < allPages){
				currentPage++;
				calculateCurrentPageSize();
			}
		}
		
	public:
		int banner_size = 100;
		string title;		
		//
		// constructor
		//
		SelectDataMenu();
		
		SelectDataMenu(int p_page_size, int &p_allElement){
			log.open("log.txt", ios::out);
			currentPage = 1;
			page_size = p_page_size;
			
			allPages = p_allElement/page_size + (p_allElement%page_size>0?1:0);
			allElement = &p_allElement;
			// tinh so trang page 1
			calculateCurrentPageSize();
		};		
		
		int getIndex(){
			return ((currentPage-1)<0?0:(currentPage-1))*page_size + selectedLine;
		}
		
		virtual bool onElementAction(){
			
		}
		
		void initListExtendAction(int count){
			listExtendAction = new int[count];
			listExtendActionLabel = new string[count];
		}
		
		void addExtendAction(int key, string label){
			listExtendAction[extendActionCount] = key;
			listExtendActionLabel[extendActionCount] = label;
			extendActionCount++;
		}
		
		virtual bool onExtentAction(int key){
			
		}
		
		void calculatePage(){
			allPages = *allElement/page_size + (*allElement%page_size>0?1:0);
		}
		// chuyen xuong duoi
		void calculateCurrentPageSize(){
			selectedLine = 0;
			calculatePage();
			if(allPages == 0) {
				currentPage = 0;
				firstElementOfPage = 0;
				lastElementOfPage = 0;
				currentPage_size = 0;
				return;
			}
			if(currentPage>allPages) currentPage = allPages;
			if(currentPage == allPages && (*allElement%page_size>0||*allElement==0)) 
				currentPage_size = *allElement%page_size;
			else
				currentPage_size = page_size;
				
			firstElementOfPage = ((currentPage-1)<0?0:(currentPage-1))*currentPage_size;
			lastElementOfPage = firstElementOfPage + currentPage_size - 1;
			lastElementOfPage++; // them nut thoat
			log <<"AllElement:::" <<*allElement <<'\n';
			log <<"currentPage:::" <<currentPage <<'\n';
			log <<"allPages:::" <<allPages <<'\n';
			log <<"firstElementOfPage:::" <<firstElementOfPage<<'\n';
			log <<"lastElementOfPage:::" <<lastElementOfPage <<'\n';
		}
		
		virtual void printElement(int i){		
			cout <<" "<<i+1 <<".\n";
		}
		
		virtual void printMenu(){	
			int index = getIndex();			
			for(int i = firstElementOfPage; i <= lastElementOfPage; i++){
				int y_axis = wherey();
				int x_axis = textMarginLeft;
				gotoxy(x_axis, y_axis);
				if(i == index){
					SetColor(6);	
				} 
				if(i!=lastElementOfPage){
					printElement(i);
				}
				else{
					cout <<"\n<< Thoat.";
				}
				if(i == index) {
					SetColor(15);
				}
			}
		};
		
		virtual void printLayout(){
			_clear();
			if(title.compare("")!=0) 
				cout<<(char)201 <<*new string(banner_size-2, (char)205) <<(char)187 <<'\n'
					<<(char)186 <<*new string(paddingL,' ') <<title <<*new string(paddingR,' ') <<(char)186 <<"\n"
					<<(char)200 <<*new string(banner_size-2, (char)205) <<(char)188 <<"\n\n";
			cout<<"Page " <<currentPage <<" of " << allPages;
			SetColor(6);
			for(int i = 0; i<extendActionCount; i++) cout<<"   "<<listExtendActionLabel[i];
			SetColor(15);
			cout <<'\n' <<(char)201 <<*new string(banner_size-2, (char)205) <<(char)187 <<'\n';
							
			printMenu();
			drawBorder();
		};
		
		void drawBorder(){
			int y = wherey();
			
			for(int i = 6; i<=y+1; i++){
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
			
		~SelectDataMenu(){
			log.close();
		}
		void run(){
			cursorVisable(false);
			drawCalculate();
			bool flag = true;
			char keyPressed;
			while(flag == true){
				printLayout();
				keyPressed = getch();
				if(keyPressed != ENTER)
					keyPressed = getch();
				if(keyPressed == KEY_DOWN){
					key_down();
				}
				else
				if(keyPressed == KEY_UP){
					key_up();
				}
				else
				if(keyPressed == KEY_LEFT){
					key_left();
				}
				else
				if(keyPressed == KEY_RIGHT){
					key_right();
				}
				else
				if(keyPressed == ENTER){
					if(selectedLine == currentPage_size) {
						flag = false;
					}
					else{
						flag = onElementAction();
					}	
				}
				else{
					for(int i = 0; i < extendActionCount; i++){
						if(keyPressed == listExtendAction[i]) {
							flag = onExtentAction(listExtendAction[i]);
							calculateCurrentPageSize();
						}
					}
				}
			}
		}
};

#endif
