#include <iostream>
#include<bits/stdc++.h>	

using namespace std;

struct Node{
	int info;
	Node* next;
};
typedef struct Node* Tree;

Node* newNode(){
	Node* p = new Node;
	p->info = rand()%100;
	p->next = NULL;
	return p;
}

void insertNode(Node* p, Tree &parent){
	if(parent == NULL)
	{
		parent = p;
		return;
	}
	else{
		insertNode(p,parent->next)
	}
}

bool find(int x, Tree &parent){
		if(parent->info == x)
			cout <<""
}

int main(){
	Tree root = NULL;
	for(int i = 1; i < 10; i++){
		Node* p = newNode();
		insertNode(p, root);
	}
	trLNR(root);
	int x;
	Node* p = newNode();
	cout <<"\nNhap x: ";
	cin >>x;
	p->info = x;
	insertNode(p, root);
	trLNR(root);
	
}









