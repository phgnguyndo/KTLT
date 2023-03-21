#include<stdio.h>
#include<stdlib.h>
//Chuong trinh them 1 node vao DSLK don co thu tu sao cho DS van co thu tu

struct node{
	int data;
	node *next;
};
typedef struct node Node;

struct LinkedList{
	Node *first;
	Node *last;
};
typedef struct LinkedList list;

void CreateList(list &l){
	l.first=NULL;
	l.last=NULL;
}

node* CreateNode(int x){
	Node *p=new Node;
	p->data=x;
	p->next=NULL;
    return p;
 }


void InsertAtFirst(list &l, Node *p){
	if(l.first==NULL){
		l.first=l.last=p;
	}
	else{
		p->next=l.first;
		l.first=p;
	}
}

void InsertAtLast(list &l, Node* p){
	if(l.first==NULL){
		l.first=l.last=p;
	}
	else{
		l.last->next=p;
		l.last=p;
	}
}

void PrintList(list l){
	for(Node *k=l.first; k!=NULL; k=k->next){
	    printf("%d ",k->data);
	}
}

void InsertAtPos(list &l, int v, int pos ){
	Node *p=CreateNode(v);
	Node *temp=l.first;
	  if(pos<=1||l.first==NULL){	    
      InsertAtFirst(l,p);	  	
	  }
	  else{
	      for(int i=1; i<pos-1;i++){
	      	if(temp->next ==NULL){
	      	InsertAtLast(l,p);
	      	return; 
			  
			  }
	      	temp=temp->next;
		  }
			p->next=temp->next;
			temp->next=p;
		}	  			
	}
	

int main()
{
	list l;
	CreateList(l);
	
	FILE *f;
	f=fopen("bai6.txt","r");
	int n;
	fscanf(f,"%d",&n);
	for(int i=0;i<n;i++){
		int newVal;
		fscanf(f,"%d",&newVal);
		Node *p=CreateNode(newVal);
		InsertAtLast(l,p);
	}
	printf("LinkedList: ");
	PrintList(l);
	int newVal,pos;
	printf("\nNhap gia tri can them: ");
	scanf("%d",&newVal);
	printf("\nNhap vi tri can them: ");
	scanf("%d",&pos);
	InsertAtPos(l,newVal,pos);	
    PrintList(l);	
}
