#include<stdio.h>
#include<stdlib.h>

struct node{
	int data;
	node *pre, *next;
};
typedef struct node Node;

struct LinkedList{
	Node *first;
	Node *last;
};

typedef struct LinkedList List;

Node *createNode(int newVal){
	Node *p=new(Node);
	p->data=newVal;
	p->pre=NULL;
	p->next=NULL;
	return p;
}

void InsertAtFirst(List &l, int newVal){
	Node *p=createNode(newVal);
	Node *temp=l.first;
	if(l.first==NULL){
		l.first=p;
		l.last=p;
		return;
	}
	else{
		temp->pre=p;
		p->next=temp;
		l.first=p;
	}	
}

void InsertAtLast(List &l, int newVal){
	Node *p=createNode(newVal);
	Node *temp=l.first;
	if(l.first==NULL){
		l.first=p;
		l.last=p;
		return;
	}
	else{
		l.last->next=p;
		p->pre=l.last;
		l.last=p;	    
	}
}

void InsertAtPos(List &l, int newVal, int pos){
	Node *p=createNode(newVal);
	Node *temp=l.first;
	if(pos<=1||l.first==NULL){
		InsertAtFirst(l,newVal);
	}
	else{
		for(int i=1;i<pos-1;i++){
			if(temp->next==NULL){
				InsertAtLast(l, newVal);
				return;
			}
			temp=temp->next;			
		}
		temp->next->next->pre=p;
		p->next=temp->next->next;
		temp->next=p;
		p->pre=temp;		
	}
}
	
void PrintfList(List l){
	for(node *k=l.first; k!=NULL; k=k->next){
		printf("%d ",k->data);
	}	
}
void Insert(List &l){
	printf("Them mot node vao danh sach lien ket ");
	int newVal,pos;
	printf("\nNhap vao vi tri can them: ");
	scanf("%d",&pos);
	printf("\nNhap vao gia tri can them: ");
	scanf("%d",&newVal);
	InsertAtPos(l,newVal,pos);
}
int main(){
	List l;
	FILE *f;
	f=fopen("bai6.txt","r");
	if(f == NULL){
	printf("1"); 
   	return 0;
    }
	int n;
	fscanf(f,"%d",&n);
	for(int i=0;i<n;i++){
		int val;
		fscanf(f,"%d",&val);
		InsertAtLast(l,val);
	}
	
	Insert(l);
	PrintfList(l);
}	
	
	
	
	
	
	

