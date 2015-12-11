#include<stdio.h>
#include<stdlib.h>
typedef struct BSTnode{
	int num;
	int height;
	struct BSTnode *left;
	struct BSTnode *right;
	struct BSTnode *prev;
}BSTnode;
BSTnode * IRnode;
int myNodeNum;
int myNodeHeight;
int array[100000],i=0,flag=0,level[1000],j=0;
void insert(BSTnode **root,int data){
	if(*root==NULL){
		*root=(BSTnode*)malloc(sizeof(BSTnode));
		(*root)->num=data;
		(*root)->left=NULL;
		(*root)->right=NULL;
		(*root)->height=0;
		(*root)->prev=NULL;
	}
	else if((*root)->num < data){
		insert((&(*root)->right),data);
		(*root)->right->prev=*root;
		(*root)->right->height=(*root)->height+1;
	}
	else if((*root)->num > data){
		insert((&(*root)->left),data);
		(*root)->left->prev=*root;
		(*root)->left->height=(*root)->height+1;
	}
}
void find(BSTnode **root,int val){
	if(*root){
		find((&(*root)->left),val);
		if((*root)->num==val){
			myNodeNum=(*root)->num;
			myNodeHeight=(*root)->height;
			flag=1;
		}
		find((&(*root)->right),val);
	}
}
void findIR(BSTnode **root,int val){
	if(*root){
		findIR((&(*root)->left),val);
		if((*root)->num==val){
			IRnode=*root;
		}
		findIR((&(*root)->right),val);
	}
}
void levelOrder(BSTnode **root){
	if(*root){
		if(((*root)->height)==myNodeHeight){
			level[j]=(*root)->num;
			j++;
		}
		levelOrder(&(*root)->left);
		levelOrder(&(*root)->right);
	}
}
void inOrder(BSTnode **root){
	if(*root){
		inOrder((&(*root)->left));
		array[i]=(*root)->num;
		i++;
		inOrder((&(*root)->right));
	}
}
int main(){
	int testCases;
	scanf("%d",&testCases);
	while(testCases--){
		for(i=0;i<100000;i++)array[i]=0;
		i=0;
		for(j=0;j<1000;j++)level[j]=0;
		j=0;
		flag=0;
		BSTnode * root=NULL;
		int numElements,scanNum;
		IRnode=NULL;
		scanf("%d",&numElements);
		while(numElements--){
			scanf("%d",&scanNum);
			insert(&root,scanNum);
		}
		int node,kMin,IRnodeVal;
		scanf("%d %d",&node,&kMin);
		find(&root,node);
		if(flag==1){
			levelOrder(&root);
			for(j=0;j<1000;j++){
				if(level[j]==node && j!=999){
					IRnodeVal=level[j+1];
					break;
				}
				if(j==999)printf("$ $\n");
			}
			findIR(&root,IRnodeVal);
			if(IRnode==NULL){
				printf("$ $\n");
				continue;
			}
			else inOrder(&IRnode);
			if(kMin>i)printf("%d $\n",IRnode->num);
			else printf("%d %d\n",IRnode->num,array[kMin-1]);
		}
		else printf("$ $\n");
	}
	return 0;
}
