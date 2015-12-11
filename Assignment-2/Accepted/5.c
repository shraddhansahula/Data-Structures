#include<stdio.h>
#include<stdlib.h>
typedef struct node{
	int data;
	struct node * next;
	struct node * prev;
}node;
void print(node ** head,node ** tail){
	node * temp=*head;
	do{
		printf("content->%d\n",(temp)->data);
		temp=(temp)->next;
	}
	while(temp!=*head);
}
void insert(node ** head,node **tail,int val){
	node * new=(node*)malloc(sizeof(node));
	new->data=val;
	new->prev=NULL;
	new->next=NULL;
	if(*head==NULL){
		*head=new;
		*tail=new;
	}
	else{
		(*tail)->next=new;
		new->prev=*tail;
		new->next=*head;
		(*head)->prev=new;
		*tail=new;
	}
}
void delete(node **head,int val,int Count){
	int i=0;
	node *temp=*head;
	node *temp2;
	int val2;
	while(Count!=1){
		i=0;
		val2=val%(Count+1);
		while(i!=((val)-1)){
			temp=temp->next;
			i++;
		}
		temp->prev->next=temp->next;
		temp->next->prev=temp->prev;
		temp2=temp;
		temp=temp->next;
		*head=temp;
		free(temp2);
		Count--;
}
}
int compare(const void *a,const void *b){
	return (*(int*)a-*(int*)b);
}
int main(){
	int T;
	scanf("%d",&T);
	while(T--){
		node *head=NULL;
		node *tail=NULL;
		int numGuys;
		scanf("%d",&numGuys);
		int array[numGuys],i;
		for(i=0;i<numGuys;i++)scanf("%d",&array[i]);
		qsort(array,numGuys,sizeof(int),compare);
		for(i=0;i<numGuys;i++)insert(&head,&tail,array[i]);
		int K;
		scanf("%d",&K);
		delete(&head,K,numGuys);
		printf("%d\n",head->data);
	}
	return 0;
}
