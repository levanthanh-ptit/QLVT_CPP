#include <iostream>
#include<bits/stdc++.h>	

using namespace std;

void print(int ar[], int l, int r){
	int i = l;
	cout <<"DS : ";
	while(i<=r){
		cout <<ar[i] <<" ";
		i++;
	}
	cout <<endl;
}

void swap(int &x, int &y) 
{ 
    int temp = x; 
    x = y; 
    y = temp; 
}

void bubbleSort(int arr[], int l, int r) 
{  
   for (int i = l; i <r; i++)
   {
   	for (int j = i; j <=r; j++)
	   {
   		if (arr[i] > arr[j]) 
            swap(arr[i], arr[j]); 
		}    
   }        
}

bool ktSoNT(int p){
	// de kt so 'p' co phai la so nguyen to ta chia p cho i tu 1 den p-1
	// chi can chi den can bac 2 cua p la du
	for(int i = 2; i<= round(sqrt(p)); i++){
		if(p%i == 0) return false;
	}
	return true;
}

bool ktSoThuanNghich(int p){
	//doi so sang chuoi
	string s1 = to_string(p), s2 = "";
	//dao chuoi
	for(int i= s1.length()-1; i>=0; i--){
		s2 +=s1[i];
	}
	//so sanh
	if(s1.compare(s2)==0) return true;
	else return false;
}
int main(){
	int n;
	cin >>n;
	int a[n];
	cout <<"DS ban dau: ";
	for(int i = 0; i<n; i++ ){
		//lay random
		a[i] = rand()%1000;
		cout <<a[i] <<" ";
	}
	cout <<endl;
	
	//vi tri se doi cho cho so nt o dau day
	int i = 0;
	
	for(int j = 0; j<n; j++){
		if(ktSoNT(a[j])){
			swap(a[i], a[j]);
			i++;
		}
	}
	
	for(int j = i; j<n; j++){
		if(ktSoThuanNghich(a[j])){
			swap(a[i], a[j]);
			i++;
		}
			
	}
	print(a, 0, n-1);
}









