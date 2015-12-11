#include<stdio.h>
#include<stdlib.h>
typedef struct node{
	int data;
	struct node *left;
	struct node *right;
}node;
void cartInsert(node **root,int array[],int start,int end){
	if(end>=start){
		int min=array[start],i;
		for(i=start;i<=end;i++)if(array[i]<min)min=array[i];
		for(i=start;i<=end;i++)if(array[i]==min)break;
		node *new=(node *)malloc(sizeof(node));
		new->data=min;
		new->left=NULL;
		new->right=NULL;
		if(*root==NULL){
			*root=new;
		}
		if((*root)->left==NULL){
			cartInsert((&(*root)->left),array,start,i-1);
		}
		if((*root)->right==NULL){
			cartInsert((&(*root)->right),array,i+1,end);
		}
	}
}
int numN=0;
void preOrder(node **root,int Nodes){
	if(*root){
		if(numN==Nodes-1)printf("%d",(*root)->data);
		else printf("%d ",(*root)->data);
		numN++;
		preOrder(&(*root)->left,Nodes);
		preOrder(&(*root)->right,Nodes);
	}
}
int numN2=0;
void postOrder(node **root,int Nodes){
	if(*root){
		postOrder(&(*root)->left,Nodes);
		postOrder(&(*root)->right,Nodes);
		if(numN2==Nodes-1)printf("%d",(*root)->data);
		else printf("%d ",(*root)->data);
		numN2++;
	}
}
int main(){
	int T;
	scanf("%d",&T);
	while(T--){
	int numNodes,i;
	scanf("%d",&numNodes);
	int array[numNodes];
	for(i=0;i<numNodes;i++)scanf("%d",&array[i]);
	node *root=NULL;
	cartInsert(&root,array,0,numNodes-1);
	preOrder(&root,numNodes);
	printf("\n");
	postOrder(&root,numNodes);
	printf("\n");
	numN=0;
	numN2=0;
	}
	return 0;
}
