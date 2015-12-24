#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>
#define nl printf("\n")
#define pf printf
#define si(a) scanf("%d",&a)
#define sc(a) scanf("%c",&a);
struct node{
    int val;
    struct node *next;
};
struct node *first,*last,*damn,*temp,*prev,*newnode;
void i_beg();
void i_end();
void display();
void del();
void i_at();
struct node *create(int);
main()
{
    int val,i,j; char key;val=1;
    while(val<6 && val>0){
        pf("\n1.Start \t2.End \t3.Display\t4.Delete\t5.Insert\t6.Exit\n------------------------------------------------\n");
        si(val);
        if(val==6)exit(0);
        else{
            switch(val){
                case 1: i_beg(); break;
                case 2: i_end(); break;
                case 3: display();break;
                case 4: del(); break;
                case 5: i_at();break;
                case 6: exit(0);break;
            }
        }
    }
}

struct node * create(int val){
    newnode = (struct node *)malloc(sizeof( struct node));
    if(newnode == NULL)
    {
        pf("Oops! You have gone out of memory\n");
        return 0;
    }
    else
    {
        newnode -> val = val;
        newnode -> next = NULL;
        return newnode;
    }

}
void i_beg(){
    int x;
    //if(first -> val == last -> val && first == NULL) pf("Only one node exists!!!\n ");
    pf("Enter a value to insert\t");
    si(x);  newnode = create(x);
    if(first == last && first == NULL)
    {
        first = last = newnode;
        first -> next = NULL;
        last -> next = NULL;
        pf("\n %d inserted at first\n",x);
    }
    else
    {
        temp = first;
        first = newnode;
        first -> next = temp;
        pf("\n %d inserted at first\n",x);
    }
}
void i_end(){
    int x;
    //if(first -> val == last -> val && first == NULL) pf("Only one node exists!!!\n ");
    pf("Enter a value to insert\t");
    si(x);  newnode = create(x);
    if(first == last && first == NULL)
    {
        first = last = newnode;
        first -> next = NULL;
        last -> next = NULL;
        pf("\n %d inserted at last\n",x);
    }
    else
    {
        last -> next = newnode;
        last = newnode;
        last -> next = NULL;
        pf("\n %d inserted at last\n",x);
    }
}
void display(){
    prev = first;
    while(prev != NULL)
    {
        pf("%d -> ",prev -> val);
        prev  = prev -> next;
    }pf(" NULL");
    nl;
}
void del(){
    pf("Enter the position to delete\t");
    int i,pos;si(pos);
    for(prev = first,i=1 ; i<pos-1 ; prev=prev->next,i++);// not i< pos but i<pos-1
    temp = prev -> next;
    prev -> next =  temp->next;
}
void i_at(){
    pf("Enter the position to add after this position\t");
    int i,pos;si(pos);
    for(prev = first,i=1 ; i<pos ; prev=prev->next,i++);
    pf("Enter a value to insert\t");
    si(i);  newnode = create(i);
    temp = prev;

    // order of these statements is important
    newnode -> next = temp -> next;
    prev -> next = newnode;
    pf("%d inserted after position %d\n",i,pos);
}
