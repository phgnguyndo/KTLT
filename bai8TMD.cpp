//xoa phan tu trung nhau trong DSLK kep co thu tu k giam

#include<stdio.h>
#include<stdlib.h>

typedef int DataType;
struct node{
	DataType data;
	node *next,*pre;
};
typedef struct node Node;

struct LinkedList{
	Node *first;
	Node *last;
};
typedef struct LinkedList List;

Node *CreateNode(DataType newVal){
	Node *p=new Node();
	p->data=newVal;
	p->next=NULL;
	p->pre=NULL;
}

void CreateList(List &l){
	l.first=NULL;
	l.last=NULL;
}

void InsertAtFirst(List &l, DataType newVal){
	Node *p=CreateNode(newVal);
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

void InsertAtLast(List &l, DataType newVal){
	Node *p=CreateNode(newVal);
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

void InsertAtPos(List &l, DataType newVal, int pos){
	Node *p=CreateNode(newVal);
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

void DeleteAtFirst(List &l){
     if(l.first==NULL){
     	printf("Khong co gi de xoa ca!");
	 }
	 else if(l.first->next==NULL){
	 	free(l.first);
	 	l.first=l.last=NULL;
	 }
	 else{
	 	Node *temp=l.first;
	 	l.first->next->pre=NULL;
	 	l.first=l.first->next;
	 	free(temp);
	 }
	 
}

void DeleteAtLast(List &l){
	if(l.first==NULL){
     	printf("Khong co gi de xoa ca!");
	 }
	 else if(l.first->next==NULL){
	 	free(l.first);
	 	l.first=l.last=NULL;
	 }
	 else{
	 	Node *temp=l.last;
 	    l.last->pre->next=NULL;
 	    l.last=l.last->pre;
 	    free(temp);
	 }
}

void DeleteAtPos(List &l, int pos){
	if(pos<1){
		printf("Vi tri xoa k hop le!");
		return;
	}
	if(l.first==NULL){
		printf("Khong co gi de xoa ca!");
	}
	else{
		if(l.first->next==NULL)
		   DeleteAtFirst(l);
		else{
			 Node *temp=l.first;
           for(int i=1;i<pos;i++){
           	   temp=temp->next;
  	            if(temp==NULL){
  	            	printf("Vi tri xoa k hop le!");
		   			   return;
			   }
		   }
   		temp->pre->next=temp->next;
		}  		
	}
}

void PrintList(List l){
	for(Node *k=l.first; k!=NULL; k=k->next){
	    printf("%d ",k->data);
	}
}

void SortList(List &l){
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
		fscanf(f,"%d",&newVal);
		InsertAtLast(l,newVal);	
	}
	PrintList(l);
	printf("\nSap xep:\n");
	SortList(l);
	PrintList(l);
	printf("\n");
	Del_Repeat(l);
	PrintList(l);
	
	
}
