#include<stdio.h>
#include<stdlib.h>
typedef int DataType;
struct node{
	DataType data;
	node *pNext;
};
typedef struct node Node;

struct Stack{
	Node *pTop;
};

void CreateStack(Stack &s){
	s.pTop=NULL;
}
Node* CreateNode(int x){
	Node *p=new Node();
	if(p==NULL){
		printf("Khong du bo nho de cap phat");
		return NULL;
	}
	p->data=x;
	p->pNext=NULL;
	return p;
}

bool IsEmpty(Stack &s){
	if(s.pTop==NULL){
		return true;//Stack rong
	}
	return false;//Stack khong rong
}

bool Push(Stack &s,node *p){
	if(p==NULL){
		return false;
	}
	if(IsEmpty(s)==true){
		s.pTop=p;
	}
	else{
		p->pNext=s.pTop;
		s.pTop=p;
	} 
	return true;
}

bool Pop(Stack &s){
	if(IsEmpty(s)==true)
	   return false;
	else{
		Node *p=s.pTop;
	int	x=p->data;
		s.pTop=p->pNext;
		delete p;
	}
	return true;// lay phan tu dau danh sach thanh cong
}

bool Peek(Stack &s, int &x){
	if(IsEmpty(s)==true)
	   return false;
	else{
	    x=s.pTop->data;	
	}
}

void Menu(Stack &s){
	int lua_chon;
	printf("Moi ban chon:");
	printf("\n1:Xuat Stack");
	printf("\n2:Them 1 phan tu vao stack");
	printf("\n3:Lay 1 phan tu khoi stack");
	printf("\n4:Xem thong tin phan tu o dinh stack");
    printf("\n0:Thoat!"); 
    
    do{
    	printf("\nBan chon:");
    	scanf("%d",&lua_chon);
    	switch(lua_chon){
			case 1:{
				for(node *k=s.pTop;k!=NULL;k=k->pNext){
					printf("%d ",k->data);
				}
				break;
			}
			case 2:{
			    int x; 
			    printf("Nhap gia tri node can them  vao stack: ");
			    scanf("%d",&x);
			    Node *p=CreateNode(x);
				Push(s,p);
				break;
			}
			case 3:{
				Pop(s);
				break;
			}
			case 4:{
				int x;
				Peek(s,x);
				printf("Gia tri phan tu dau Stack la: %d",x);
				break;
			}
			
		}
	}while(lua_chon!=0);
	}   


int main(){
	Stack s;
	CreateStack(s);
	FILE *f;
	f=fopen("bai6.txt","r");
	int n;
	fscanf(f,"%d",&n);
	for(int i=0;i<n;i++){
		int newVal;
		fscanf(f,"%d",&newVal);
		Node *p=CreateNode(newVal);
		Push(s,p);
	}
	Menu(s);
}









