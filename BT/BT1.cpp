#include <iostream>
#include<bits/stdc++.h>	
using namespace std;
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

void print(int ar[], int n){
	int i = 0;
	cout <<"DS : ";
	while(i<n){
		cout <<ar[i] <<" ";
		i++;
	}
	cout <<endl;
}

int main(){
	int n;
	cin >>n;
	int a[n];
	cout <<"DS ban dau: ";
	for(int i = 0; i<n; i++ ){
		a[i] = rand()%100;
		cout <<a[i] <<" ";
	}
	cout <<endl;
	
	// chia 2 phan le chan
	int i = 0, j = n-1, ddx;	
	while(i<n-1){
		if( a[i]%2 == 0){
			while(j>i){
				//duyet nguoc neu gap so le thi doi cho cho a[i]
				//j duoc danh dau lai de tang toc do duyet
				if(a[j]%2 != 0) {
					swap(a[i], a[j]);
					break;
				}
				j--;
			}
			//vi tri trai bang vi tri phai => khong can duyet tiep
			if(j == i) break;		
		}
		i++;
	}
	print(a, n);
	
	//sap xep 2 phan
	//phan dau
	bubbleSort(a,0,i);
	print(a, n);
	//phan cuoi
	bubbleSort(a,i+1,n-1);
	print(a, n);
}
