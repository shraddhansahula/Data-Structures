#include<stdio.h>
#include<stdlib.h>
typedef struct node{
	int num;
	struct node *next;
	struct node *prev;
}node;
void push(node **head,node **tail,int data){
	node *new=(node*)malloc(sizeof(node));
	new->num=data;
	new->prev=NULL;
	if(*head==NULL){
		*head=new;
		*tail=new;
		(*head)->next=NULL;
		(*tail)->next=NULL;
	}
	else{
		(*tail)->next=new;
		new->prev=*tail;
		*tail=new;
		(*tail)->next=NULL;
	}
}
int pop(node **head,node **tail){
	int data;
	data=(*tail)->num;
	node *temp=*tail;
	*tail=temp->prev;
	if(*tail==NULL)
		*head=NULL;
	free(temp);
	return data;
}
int emptyStack(node **head){
	if(*head==NULL)
		return 1;
	return 0;
}
void enqueue(node **head,node **tail,int val){
	push(head,tail,val);
}
int dequeue(node **head1,node **tail1,node **head2,node **tail2){
	while((*head1)!=NULL){
		push(head2,tail2,pop(head1,tail1));
	}
	int data;
	data=pop(head2,tail2);
	while((*head2)!=NULL){
		push(head1,tail1,pop(head2,tail2));
	}
	return data;
}
void print(node **head){
	node *temp=*head;
	while(temp!=NULL){
		printf("Out->%d",temp->num);
		temp=(temp)->next;
	}
}
int main(){
	node *head1=NULL;
	node *head2=NULL;
	node *tail1=NULL;
	node *tail2=NULL;
	int scanVar,query,flag=0;
	while(1){
		scanf("%d",&query);
		switch(query){
			case 1:
				scanf("%d",&scanVar);
				enqueue(&head1,&tail1,scanVar);
				print(&head1);
				break;
			case 2:
				printf("%d\n",dequeue(&head1,&tail1,&head2,&tail2));
				break;
			default:
				flag=1;
		}
		if(flag)break;
	}
}
