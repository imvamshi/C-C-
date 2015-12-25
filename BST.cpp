#include <iostream>
#define i(x) insert(root,x)
using namespace std;
struct node{
	int val;
	node* left;
	node* right;
};
struct node* root;
node* createnode(int data){
//C++ version of assigning memory
	node* newnode = new node();
//C version of assigning memory
	//node* newnode = (node*)malloc(sizeof(node));
	
	// (*newnode).val = data  <OR>  newnode -> val
	newnode -> val = data;
	newnode -> left  = NULL;
	newnode -> right = NULL;
	return newnode;
	
}
node*  insert(node* root,int data){
	if(root == NULL){//empty tree
		cout<<data<<" is created\n";
		root = createnode(data);
	}
	else if(data <= root ->val )
	 root -> left = insert(root -> left, data);
	else if(data >= root -> val)
	 root -> right = insert(root -> right, data);
	return root;
}
bool search(node* root, int key){
	if(root == NULL){ cout<<key<<" NOT FOUND!!!\n";
	 return false;
	}
	else if(root -> val == key ){
		 cout<<"Success "<<key<<" found :)\n"; return true;
	}
	else if(key <= root ->val) {
		return search(root -> left,key);
	}
	else if(key >= root ->val){
		return  search(root->right, key);
	}
}
main()
{
	root = NULL;
	root = i(8);root = i(3); root = i(40);
	int x;
	cout<<"search 0 to exit\n";
	while(1){
		cin>>x;
		if(x==0)exit(0);
		if(search(root,x)) 
		cout<<"Search successful\n";
	}
	
}
