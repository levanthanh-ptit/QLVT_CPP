#ifndef GeneralGUI_H
#define GeneralGUI_H


void printBanner(string title,int p_banner_size){
	int banner_size = 100;
	banner_size = p_banner_size;
	int paddingR, paddingL = (banner_size - 2 - title.length())/2;
	if((banner_size - title.length())%2==1) paddingR = paddingL+1;
	else paddingR = paddingL;
	cout<<(char)201 <<*new string(banner_size-2, (char)205) <<(char)187 <<'\n'
		<<(char)186 <<*new string(paddingL,' ') <<title <<*new string(paddingR,' ') <<(char)186 <<"\n"
		<<(char)200 <<*new string(banner_size-2, (char)205) <<(char)188 <<"\n\n";
}
#endif
