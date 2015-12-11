#include<stdio.h>
#include<stdlib.h>
typedef struct node{
	int data;
	struct node *left;
	struct node *right;
}node;
void insert(node **root,int data){
	if(*root==NULL){
		*root=(node*)malloc(sizeof(node));
		(*root)->data=data;
		(*root)->left=NULL;
		(*root)->right=NULL;
	}
	else if((*root)->data < data){
		insert((&(*root)->right),data);
	}
	else if((*root)->data > data){
		insert((&(*root)->left),data);
	}
}
node *newRoot;
void preOrder(node **root,int val){
	if(*root){
		if((*root)->data!=val)insert(&newRoot,((*root)->data));
		preOrder(&(*root)->left,val);
		preOrder(&(*root)->right,val);
	}
}
int count=0;
void printPreOrder(node **root){
	if(*root){
		if(count==0){
			printf("%d",(*root)->data);
			count=1;
		}
		else printf(" %d",(*root)->data);
		printPreOrder(&(*root)->left);
		printPreOrder(&(*root)->right);
	
	}
}
int count1=0;
void printPostOrder(node **root){
	if(*root){
		printPostOrder(&(*root)->left);
		printPostOrder(&(*root)->right);
		if(count1==0){
			printf("%d",(*root)->data);
			count1=1;
		}
		else printf(" %d",(*root)->data);	
	}
}
int count2=0;
void printInOrder(node **root){
	if(*root){
		printInOrder(&(*root)->left);
		if(count2==0){
			printf("%d",(*root)->data);
			count2=1;
		}
		else printf(" %d",(*root)->data);
		printInOrder(&(*root)->right);
	
	}
}
int main(){
	int T;
	scanf("%d",&T);
	while(T--){
		count=0;
		count1=0;
		count2=0;
		newRoot=NULL;
		node * root=NULL;
		int numNodes,i,scanNum;
		scanf("%d",&numNodes);
		for(i=0;i<numNodes;i++){
			scanf("%d",&scanNum);
			insert(&root,scanNum);
		}
		for(i=0;i<numNodes;i++)scanf("%d",&scanNum);
		int newRootVal;
		scanf("%d",&newRootVal);
		newRoot=(node *)malloc(sizeof(node));
		newRoot->data=newRootVal;
		newRoot->left=NULL;
		newRoot->right=NULL;
		preOrder(&root,newRootVal);
		printInOrder(&newRoot);
		printf("\n");
		printPreOrder(&newRoot);
		printf("\n");
		printPostOrder(&newRoot);
		printf("\n");
	}
	return 0;
}
