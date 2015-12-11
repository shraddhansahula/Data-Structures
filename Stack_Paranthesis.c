#include<stdio.h>
#include<stdlib.h>
typedef struct bracHold{
	char brac;
	struct bracHold *next;
	struct bracHold *prev;
}bracHold;
void push(bracHold **head,bracHold **tail,char data);
char pop(bracHold **head,bracHold **tail);
int emptyStack(bracHold **head);
void print(bracHold **head){
	bracHold *temp=*head;
	while(temp!=NULL){
		printf("Out->%c",temp->brac);
		temp=(temp)->next;
	}
}
int main(){
	bracHold *head=NULL;
	bracHold *tail=NULL;
	char scanChar,popChar;
	int flag=0;
	while(scanf("%c",&scanChar)!=EOF){
		if((scanChar=='(') || (scanChar=='{') || (scanChar=='[')){
			push(&head,&tail,scanChar);
		//	print(&head);
		}
		else if((scanChar==')') || (scanChar=='}') || (scanChar==']')){
			if(!emptyStack(&head)){
				popChar=pop(&head,&tail);
				//printf("poped->%c\n",popChar);
				if(scanChar==')' && popChar=='(')
					continue;
				else if(scanChar=='}' && popChar=='{')
					continue;
				else if(scanChar==']' && popChar=='[')
					continue;
				else{
					flag=1;
					printf("Not Valid\n");
					break;
				}
			}
			else{
				printf("Not Valid\n");
			}
		}
	}
	if(flag==0)
		printf("Valid\n");
	return 0;
}
void push(bracHold **head,bracHold **tail,char data){
	bracHold *new=(bracHold*)malloc(sizeof(bracHold));
	new->brac=data;
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
char pop(bracHold **head,bracHold **tail){
	char data;
	data=(*tail)->brac;
	bracHold *temp=*tail;
	*tail=temp->prev;
	if(*tail==NULL)
		*head=NULL;
	free(temp);
	return data;
}
int emptyStack(bracHold **head){
	if(*head==NULL)
		return 1;
	return 0;
}
