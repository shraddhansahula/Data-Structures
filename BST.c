#include<stdio.h>
#include<stdlib.h>
typedef struct BSTnode{
	int num;
	struct BSTnode *left;
	struct BSTnode *right;
	struct BSTnode *prev;
}BSTnode;
void insert(BSTnode **root,int data){
	if(*root==NULL){
		*root=(BSTnode*)malloc(sizeof(BSTnode));
		(*root)->num=data;
		(*root)->left=NULL;
		(*root)->right=NULL;
		(*root)->prev=NULL;
	}
	else if((*root)->num < data){
		insert(&((*root)->right),data);
		(*root)->right->prev=(*root);
	}
	else if((*root)->num > data){
		insert(&((*root)->left),data);
		(*root)->left->prev=(*root);
	}
}
int find(BSTnode **root,int data){
	if((*root)->num==data)
		return 1;
	else if((*root)->num < data){
		if((*root)->right==NULL)
			return 0;
		else
			find((&(*root)->right),data);
	}
	else if(((*root)->num) > data){
		if((*root)->left==NULL)
			return 0;
		else
			find(&(*root)->left,data);
	}
}
/*void delete(BStnode **root,int val){
	BSTnode * delNode,tempNode;
}*/
void printInorder(BSTnode **root){
	if((*root)->left==NULL){
		printf("%d",(*root)->num);
		return;
	}
	else printInorder(&(*root)->left);
	printf("%d",(*root)->num);
	if((*root)->right==NULL){
		printf("%d",(*root)->num);
		return;
	}
	else printInorder(&(*root)->right);
}
void printPostorder(BSTnode **root){
	if((*root)->left==NULL){
		printf("%d",(*root)->num);
		return;
	}
	else printPostorder(&(*root)->left);
	if((*root)->right==NULL){
		printf("%d",(*root)->num);
		return;
	}
	else printPostorder(&(*root)->right);
	printf("%d",(*root)->num);
}
void printPreorder(BSTnode **root){
	int flag=0;
	if(printf("%d",(*root)->num))flag=1;
	if((*root)->left==NULL){
		if(!flag)printf("%d",(*root)->num);
		return;
	}
	else printPreorder(&(*root)->left);
	if((*root)->right==NULL){
		if(!flag)printf("%d",(*root)->num);
		return;
	}
	else printPreorder(&(*root)->right);
}
void displayTree(BSTnode **root);
//void delete(BSTnode **root,int val){
//	if(find(root,val)){
//		if((*root)->left==NULL && ((*root)->right)==NULL)free(*root);
//	}
//}
int main(){
	BSTnode *root=NULL;
	int scanNum,numSearch,query;
	while(1){
		scanf("%d",&query);
		if(query==1){
			scanf("%d",&scanNum);
			insert(&root,scanNum);
		}
		else if(query==2){
			scanf("%d",&scanNum);
			if(find(&root,scanNum))printf("Found\n");
			else if(!find(&root,scanNum))printf("Not Found\n");
		}
//		else if(query==3){
//			scanf("%d",scanNum);
//			delete(&root,scanNum);
//		}
		else if(query==4)printInorder(&root);
		else if(query==5)printPostorder(&root);
		else if(query==6)printPreorder(&root);
	}
}
void displayTree(BSTnode **root){
	//display the full tree
	if(*root==NULL) return;
	displayTree(&((*root)->left));
	printf("| %d ", (*root)->num); 
	displayTree((&(*root)->right));
}
