#include <iostream>
using namespace std;
struct node{
	int value;
	node *left,*right;
};
node *root = NULL,*temp,*newnode;
node *create(int x){
	newnode = new node;
	newnode -> value = x;
	newnode -> left = NULL; newnode -> right = NULL;
	return newnode;
}
void insert(node *root,node *newnode){
	if(newnode->value < root->value){
		if(root->left!=NULL) insert(root->left,newnode);
		else root->left = newnode;
	}
	if(newnode->value>root->value){
		if(root->right!=NULL) insert(root->right,newnode);
		else root->right = newnode;
	}
}
bool search(node *root,int val){
	//notfound, found, traverse
	if(root==NULL)return false;
	else if(root->value==val)return true;
	else if(val<root->value) search(root->left,val);
	else if(val>root->value) search(root->right,val);
	
}
main()
{	int n,val;bool c;
	while(1)
	{
		cout<<"\n1.Insert 2. Search\n";cin>>n;
		switch(n){
			case 1: if(root==NULL){
				 		cout<<"tree is empty \n Enter a root value\t";
				 		cin>>val;		 
						root = create(val);
						cout<<val<<"\t created as root\n";
					}else{
						cout<<"Enter a value to insert\n";
						cin>>val;
						newnode = create(val);
						insert(root,newnode);
						cout<<"\t"<<val<<" inserted\n";
					} break;
			case 2: cout<<"Enter a value to search\n";cin>>val;
					c = search(root,val);
					c == true ? cout<<val<<" Found\n":cout<<val<<" Notfound\n";
		}
	}
}
