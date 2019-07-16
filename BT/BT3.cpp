#include <iostream>
#include<bits/stdc++.h>	

using namespace std;

struct Node{
	int info;
	Node* left;
	Node* right; 
};
typedef struct Node* Tree;

Node* newNode(){
	Node* p = new Node;
	p->info = rand()%100;
	p->left = p->right = NULL;
	return p;
}

void insertNode(Node* p, Tree &parent){
	if(parent == NULL)
	{
		parent = p;
		return;
	}
	else{
		if(p->info > parent->info) insertNode(p, parent->right);
		else insertNode(p, parent->left);
	}
}

void trLNR(Tree &parent){
	if(parent->left != NULL) trLNR(parent->left);
	cout <<parent->info <<" ";
	if(parent->right != NULL) trLNR(parent->right);	
}

void deleteNode(int x,Tree &parent){
	if(parent == NULL) return;
	else if(parent->info < x) deleteNode(x, parent->right);
	else if(parent->info > x) deleteNode(x, parent->left);
	else{
			if(parent->left == NULL) parent = parent->right;
			else if(parent->right == NULL) parent = parent->left;
			else{
				Node* p = parent->left;
				while(p->right != NULL){
					p = p->right;
				}
				parent->info = p->info;
				deleteNode(p->info, parent->left);
			}
		}
	return;
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
	deleteNode(x, root);
	trLNR(root);
	
}









