#include<stdio.h>
#include<stdlib.h>
typedef struct node{
	int num;
	struct node * next;
	struct node * prev;
}node;
void enqueue(node **head,node **tail,int val){
	node *new=(node*)malloc(sizeof(node));
	new->num=val;
	new->next=NULL;
	new->prev=NULL;
	if(*head==NULL){
		*head=new;
		*tail=new;
	}
	else{
		(new)->prev=*tail;
		(*tail)->next=new;
		*tail=new;
		(*tail)->next=NULL;
	}
}
int dequeue(node **head,node **tail){
	int data;
	data=(*head)->num;
	node * temp=*head;
	*head=(*head)->next;
	free(temp);
	return data;
}
void push(node **head,node **tail,int val){
	enqueue(head,tail,val);
}
int pop(node **head,node **tail){
	node *temp=*tail;
	while(*head!=temp)
		enqueue(head,tail,dequeue(head,tail));
	int data=(*head)->num;
	*head=(*head)->next;
	free(temp);
	return data;
}
int main(){
	int scanVar,query,flag=0;
	node *head=NULL;
	node *tail=NULL;
	while(1){
		scanf("%d",&query);
		switch(query){
			case 1:
				scanf("%d",&scanVar);
				push(&head,&tail,scanVar);
				//print(&head1);
				break;
			case 2:
				printf("%d\n",pop(&head,&tail));
				break;
			default:
				flag=1;
		}
		if(flag)break;
	}
}
