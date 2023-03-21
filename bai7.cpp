#include<stdio.h>
#include<stdlib.h>

typedef int DataType;
struct node{
	DataType data;
	node *next;
};
typedef struct node Node;

struct LinkedList{
	Node *first;
	Node *last;
};
typedef struct LinkedList List;

Node *CreateNode(DataType newVal)
{
	Node *p=new Node();
	p->data=newVal;
	p->next=NULL;
}

Node *CreateList(List &l){
	l.first=NULL;
	l.last=NULL;
}

void InsertAtFirst(List &l,Node *p){
	if(l.first==NULL){
		l.first=l.last=p;
	}
	else{
		p->next=l.first;
		l.first=p;		
	}
}

void InsertAtLast(List &l,Node *p){
	if(l.first==NULL){
		l.first=l.last=p;
	}
	else{
		l.last->next=p;
		l.last=p;
	}
}


void InsertAtPos(List &l, DataType val, int pos ){
	Node *p=CreateNode(val);
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

void DeleteAtFirst(List &l){
	Node *temp=l.first;
	if(l.first==NULL)
	  printf("khong co gi de xoa!");
	else{
		temp=temp->next;
		l.first=temp;
	}
}
void DeleteAtLast(List &l){
	Node *temp=l.first;
	if(l.first==NULL){
		printf("khong co gi de xoa!");
	}
	   
	else{
		
	   	while(temp->next->next!=NULL){
		     temp=temp->next;
		   }
		   temp->next=NULL;
	   }
}
void DeleteAtPos(List &l, int pos){
	Node *temp=l.first;
	if(temp->next==NULL){
        DeleteAtFirst(l);
	    return; 
    } 
	if(l.first==NULL)
	    printf("khong co gi de xoa!");
	else{
		for(int i=1;i<pos-1;i++)
		{
			temp=temp->next;
			if(temp==NULL){
				printf("Vi tri xoa k hop le!");
				return;
			}			
		}
		temp->next=temp->next->next;
	}
}

void PrintList(List l){
	if(l.first==NULL){
		printf("DS rong");
		return;
	}
	for(Node *k=l.first;k!=NULL;k=k->next){
		printf("%d ",k->data);
	}
}
void SortList(List &l){//sap xep
	for(Node *k=l.first;k!=NULL;k=k->next){
       	for(Node* temp=k->next;temp!=NULL;temp=temp->next){
       		 if(k->data>temp->data){
       		 	  int tmp=k->data;
				  k->data=temp->data;
				  temp->data=tmp;       		 	
				}
		   }
	}
}

void Del_Repeat(List &l){
	int a=1;
	int b=1;
	for(Node *k=l.first;k!=NULL;k=k->next){
       	for(Node* temp=k->next;temp!=NULL;temp=temp->next){
       		a++;
       		 if(k->data==temp->data){
       		 	 DeleteAtPos(l,a);    		 	
				}
		   }
		   a=b++;
	}
}

int main(){
	List l;
	CreateList(l);
	FILE *f;
	f=fopen("bai7.txt","r");
	int n;
	fscanf(f,"%d",&n);
	for(int i=0;i<n;i++){
		DataType newVal;
		fscanf(f,"%d", &newVal);
		Node *p=CreateNode(newVal);
		InsertAtLast(l,p);
	}
	PrintList(l);
	printf("\n");
	SortList(l);
	PrintList(l);
	Del_Repeat(l);
	printf("\n");
	PrintList(l);
		
}
