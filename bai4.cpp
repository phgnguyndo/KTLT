//Thao tac co ban voi DSLK kep du lieu nhap tu file

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

void InsertAtFirst(List &l, int newVal){
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

void InsertAtLast(List &l, int newVal){
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

void InsertAtPos(List &l, int newVal, int pos){
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
           	   if(temp == NULL ){
		   	printf("Vi tri xoa k hop le!");
		   	return;}
		   }
		   temp->pre->next=temp->next;
		   free(temp);
		}  		
	}
}

bool IsEmpty(List l){
	if(l.first==l.last==NULL)
	  return true;
    else return false;
}

int Search(List l, int val){
	Node *temp=l.first;
	int dem=0;
	while(temp->next!=NULL){
		temp=temp->next;
		if(temp->data==val)
		   dem++;		
	}
	return dem;
}

int makeEmpty(List l){
   while(IsEmpty(l)!=true){
   	DeleteAtFirst(l);
   }
}

void PrintList(List l){
	for(Node *k=l.first; k!=NULL; k=k->next){
	    printf("%d ",k->data);
	}
}


void MENU(List l){
int Lua_chon;
   printf("Moi ban chon thao tac can thuc hien:");
   printf("\n1:Kiem tra danh sach rong");
   printf("\n2:Them vao vi tri bat ki");
   printf("\n3:Tim mot phan tu trong danh sach");
   printf("\n4:Xoa mot phan tu bat ki");
   printf("\n5:Xoa phan tu dau ");
   printf("\n6:Xoa phan tu cuoi ");
   printf("\n7:Xuat DS");
   printf("\n8:Lam rong DS");
   printf("\n0:Thoat!");
   
   do
   {
   	    printf("\nBan chon: ");
   	    scanf("%d",&Lua_chon);
   	  switch(Lua_chon)
   	  {
   	  	case 1:
   	  		{
   	  			if(IsEmpty(l)==true)
   	  			printf("Danh sach rong");
   	  			else
   	  		    printf("Danh sach khong rong");
					 break;
			}
		case 2:
				{
					DataType newVal;
					int pos;
					printf("Nhap vi tri can chen:");
					scanf("%d",&pos);
					printf("Nhap gia tri can them: ");
					scanf("%d",&newVal);
					InsertAtPos(l,newVal,pos);
					printf("Dang sach sau khi chen: ");
					PrintList(l);
					break;
				}
				
		case 3:{
			int val;
			printf("Nhap gia tri can tim: ");
			scanf("%d",&val);
			int dem=Search(l,val);
			printf("Gia tri %d xuat hien %d lan trong DS",val,dem);
			break;
		}
		
		case 4: 
		{
			int pos;
			printf("Nhap vi tri can xoa: ");
			scanf("%d",&pos);
			DeleteAtPos(l,pos);
			break;					
		}
		case 5:{
			DeleteAtFirst(l);
			break;
		}
		case 6:{
			DeleteAtLast(l);
			break;
		}
		case 7:{
			printf("DS: ");
			PrintList(l);
			break;
		}
    }
}
while(Lua_chon != 0);
}

int main(){
	List l;
	CreateList(l);
	FILE *f;
	f=fopen("bai6.txt","r");
	int n;
	fscanf(f,"%d",&n);
	for(int i=0;i<n;i++){
		int newVal;
		fscanf(f,"%d",&newVal);
		InsertAtLast(l,newVal);	
	}
	
	MENU(l);
}
