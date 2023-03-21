//Bai3: Danh sach lien ket don su dung mang
#include<stdio.h>
#include<stdlib.h>
#define MAX 100

typedef int item;
struct LinkedList{
	item a[MAX];
	int size;
};
typedef struct LinkedList List;

void CreateList(List *L);//khoi tao danh sach rong
bool IsEmpty(List *L);//kiem tra danh dach rong
bool IsFull(List *L);
void InsertAtPos(List *L,item newVal,int pos);//chen x vao vi tri k
void PrintList(List L);//Xuat DS
void InsertAtLast(List *L,int newVal);
void InsertAtFirst(List *L,int newVal);
void DeleteAtPos(List *L,int pos);



void CreateList(List *L){
	(*L).size=0;
}

bool IsEmpty(List *L){
	if((*L).size==0)
	  return true;
    else
      return false;
}
bool IsFull(List *L){
	if((*L).size==MAX)
	   return true;
    else
       return false;
}

void InsertAtFirst(List *L,int newVal ){
	if(IsFull(L)==true){
		printf("DS day!");
		return;
	}
	else if(IsEmpty(L)==true){
		(*L).a[0]=newVal;
		(*L).size++;
	}
	
	else{
		int temp;
		for(int i=(*L).size;i>0;i--){
		    (*L).a[i]=(*L).a[i-1];
		    (*L).a[0]=newVal;
		    (*L).size++;
		}
	}
	
}

void InsertAtLast(List *L,int newVal){
     if(IsFull(L)==true){
		printf("DS day!");
		return;
	}
	else if(IsEmpty(L)==true){
		(*L).a[0]=newVal;
		(*L).size++;
	}
	else{
		(*L).a[(*L).size]=newVal;
		(*L).size++;
		
	}	
}

void InsertAtPos(List *L,int pos,item newVal){
	if(IsEmpty(L)==true){
		InsertAtFirst(L,newVal);
	}
	else if(IsFull(L)==true){
		printf("DS day!");
		return;
	}
	else{
		(*L).size++;
		for(int i=(*L).size;i>pos-1;i--){
			(*L).a[i]=(*L).a[i-1];
            
		}	(*L).a[pos-1]=newVal;	
	}
}

void DeleteAtPos(List *L,int pos){
	if(IsEmpty(L)==true){
		printf("Khong co gi de xoa!");
	}
	if(pos<1||pos>(*L).size){
		printf("Vi tri xoa khong hop le!\n");
		return;
	}
	for(int i=pos-1;i<(*L).size;i++){
		(*L).a[i]=(*L).a[i+1];
	}
	(*L).size--;
}

void PrintList(List L){
	for(int i=0;i<(L).size;i++){
		printf("%d ",(L).a[i]);
	}
	
}


int main(){
	List L;
    CreateList(&L);
	
	FILE *f;
	f=fopen("Bai3.txt","r");
	int n;
	fscanf(f,"%d",&n);
	for(int i=0;i<n;i++){
		int val;
		fscanf(f,"%d",&val);
		InsertAtLast(&L,val);
	}
	PrintList(L);
	int Lua_chon;
   printf("Moi ban chon thao tac can thuc hien:");
   printf("\n1:Kiem tra danh sach rong");
   printf("\n2: Kiem tra danh sach day");
   printf("\n3:Do dai danh sach");
   printf("\n4:Them vao vi tri bat ki");
   printf("\n5:Tim mot phan tu trong danh sach");
   printf("\n6:Xoa phan tu tai vi tri k");
   printf("\n0:Thoat!");
   
   do
   {
   	    printf("\nBan chon: ");
   	    scanf("%d",&Lua_chon);
   	  switch(Lua_chon)
   	  {
   	  	case 1:
   	  		{
   	  			if(IsEmpty(&L)==true)
   	  			printf("Danh sach rong");
   	  			else
   	  		    printf("Danh sach khong rong");
					 break;
			}
		case 2:
			{
				if(IsFull(&L)==true)
				printf("Danh sach day");
				else
				printf("Danh sach chua day");
				break;
			}
		case 3: printf("Do dai danh sach la: %d",L.size);		
			break;
		case 4:
				{
					item newVal;
					int pos;
					printf("Nhap vi tri can chen:");
					scanf("%d",&pos);
					printf("Nhap gia tri can them: ");
					scanf("%d",&newVal);
					InsertAtPos(&L,pos, newVal);
					printf("Dang sach sau khi chen: ");
					PrintList(L);
					break;
				}
		
		case 6: 
		{
			int pos;
			printf("Nhap vi tri can xoa: ");
			scanf("%d",&pos);
			DeleteAtPos(&L,pos);
			printf("Danh sach sau khi xoa: ");
			PrintList(L);
			break;
			
		}
		
    }
}
while(Lua_chon != 0);

}









