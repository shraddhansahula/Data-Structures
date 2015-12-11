#include<stdio.h>
#include<stdlib.h>
typedef struct opHold{
	int op;
	struct opHold *next;
	struct opHold *prev;
}opHold;
void push(opHold **head,opHold **tail,int data){
	opHold *new=(opHold*)malloc(sizeof(opHold));
	new->op=data;
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
int pop(opHold **head,opHold **tail){
	int data;
	data=(*tail)->op;
	opHold *temp;
	temp=*tail;
	*tail=temp->prev;
	if(*tail==NULL)
		*head=NULL;
	free(temp);
	return data;
}
int emptyStack(opHold **head){
	if(*head==NULL)
		return 1;
	return 0;
}
void print(opHold **head){
	opHold *temp;
	temp=*head;
	while(temp!=NULL){
		printf("%d",temp->op);
		temp=temp->next;
	}
}
int main(){
	opHold *head=NULL;
	opHold *tail=NULL;
	int pop1,pop2,operated;
	char scanNum;
	while(scanf("%c",&scanNum)!=EOF){
		if(scanNum >='0' && scanNum<='9')
			push(&head,&tail,scanNum-'0');
		else if(scanNum!='\n'){
			pop1=pop(&head,&tail);
			pop2=pop(&head,&tail);
			switch(scanNum){
				case '+':
					push(&head,&tail,(pop1+pop2));
					break;
				case '-':
					push(&head,&tail,(pop1-pop2));
					break;
				case '*':
					push(&head,&tail,(pop1*pop2));
					break;
				case '/':
					push(&head,&tail,(pop1/pop2));
					break;
			}
		}
		else
			continue;
	}
	print(&head);
	return 0;
}
