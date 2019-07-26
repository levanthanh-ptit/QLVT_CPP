#ifndef Util_H
#define Util_H
#include <iostream>
#include <sstream>

void notthing(){ return;}
void notthing(int i){ return;}

template <typename T>
std::string genericToString(const T& t)
{
    ostringstream oss;
    
    if((double)t == 0)	return "0";
    else
    if(t == NULL)  return "NULL";
    else{
    	oss << t;
    	return oss.str();
	}  
}

template <typename T>
struct Holder{
	T** data;
	int count = 0;
	void deleteItem(int from){
		for(int i = from; i<count-1; i++){
			data[i] = data[i+1];
		}
		count--;
	}
	void insertItem(T* item, int index){
		T** temp;
		if(count > 0){
			temp = new T*[count];
			for(int i = 0; i<count; i++){
				temp[i] = data[i];
			}
		}
		count ++;		
		data = (T**)realloc(data, count*(sizeof(T*)));
		int i = 0;
		if(count > 1){
			for(; i< index; i++){
				data[i] = temp[i];
			}
		}
		data[i] = item;
		if(count > 1){
			for(; i < count; i++){
				data[i+1] = temp[i];
			}
		}
	}
};

void copy(char src[], char des[], int size){
	
	for(int i=0; i< size; i++){
		des[i] = src[i];
	}
}

void copy(string src, char des[], int size){
	
	cout <<"src: " <<src <<endl;
	for(int i=0; i< size; i++){
		des[i] = src[i];
	}
}

string copy(char src[]){
	string des ="";
	des += src;
	return des;
}

void extend(char src[], string &des){
	
	int i =0;
	while(src[i]!='\0'||i< sizeof(src)){
		des+=src[i];
		i++;
	}
}


#endif
