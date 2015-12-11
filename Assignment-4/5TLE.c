#include<stdio.h>
#include<stdlib.h>
typedef struct node{
	int data;
	struct node *next;
}node;
void insertSorted(node **root,int val){
	node *new=(node *)malloc(sizeof(node));
	new->data=val;
	new->next=NULL;
	node *temp;
	if(*root==NULL)*root=new;
	else if((*root)->data<val){
		new->next=(*root);
		*root=new;
	}
	else{
		temp=*root;
		while(temp->next!=NULL){
			if(temp->next->data>val)temp=(temp)->next;
		}
		new->next=(temp)->next;
		(temp)->next=new;
	}
}
int pick(node **root,int index){
	node *temp=*root;
	while(index!=0){
		(temp)=(temp)->next;
		index--;
	}
	return (temp)->data;
}
void print(node **root){
	node *temp=*root;
	while(temp!=NULL){
		printf("data-%d\n",temp->data);
		temp=(temp)->next;
	}
}
int main(){
	int N;
	scanf("%d",&N);
	node *root=NULL;
	int count=0;
	while(N--){
		int query,marks,index;
		scanf("%d",&query);
		if(query==1){
			index=(count+1)/4;
			if(index)printf("%d\n",pick(&root,index-1));
			else printf("-1\n");
		}
		else if(query==2){
			scanf("%d",&marks);
			insertSorted(&root,marks);
			//print(&root);
			count++;
		}
	}
	return 0;
}
