#include<stdio.h>
#include<stdlib.h>

typedef struct opHold{
	char op;
	struct opHold *next;
	struct opHold *prev;
}opHold;
void push(opHold **head,opHold **tail,char data){
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
char pop(opHold **head,opHold **tail){
	char data;
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
		printf("Stack->%c",temp->op);
		temp=temp->next;
	}
}
int main(){
	opHold *head=NULL;
	opHold *tail=NULL;
	char scanChar,popChar;
	while(scanf("%c",&scanChar)!=EOF){
		switch(scanChar){
			case '+':
				while(!emptyStack(&head)){
					popChar=pop(&head,&tail);
					if(popChar=='/' || popChar=='*' || popChar=='+'){
						printf("%c",popChar);
					}
					else{
						push(&head,&tail,popChar);
						break;
					}
				}
				push(&head,&tail,scanChar);
				//	print(&head);
				break;
			case '-':
				while(!emptyStack(&head)){
					popChar=pop(&head,&tail);
					if(popChar=='/' || popChar=='*' || popChar=='+' || popChar=='-'){
						printf("%c",popChar);
					}
					else{
						push(&head,&tail,popChar);
						break;
					}
				}
				push(&head,&tail,scanChar);
				break;
			case '*':
				while(!emptyStack(&head)){
					popChar=pop(&head,&tail);
					if(popChar=='/' || popChar=='*'){
						printf("%c",popChar);
					}
					else{
						push(&head,&tail,popChar);
						break;
					}
				}
				push(&head,&tail,scanChar);
				break;
			case '/':
				while(!emptyStack(&head)){
					popChar=pop(&head,&tail);
					if(popChar=='/'){
						printf("%c",popChar);
					}
					else{
						push(&head,&tail,popChar);
						break;
					}
				}
				push(&head,&tail,scanChar);
				break;
			case '(':
				push(&head,&tail,scanChar);
				break;
			case ')':
				while(!emptyStack(&head)){
					popChar=pop(&head,&tail);
					if(popChar!='(')
						printf("%c",popChar);
					else
						break;
				}
				break;
			default:
				printf("%c",scanChar);
				break;
		}
	}
	while(!emptyStack(&head)){
		printf("%c",pop(&head,&tail));
	}
	return 0;
}

