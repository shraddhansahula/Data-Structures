#include<stdio.h>
#include<stdlib.h>
#include<string.h>
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
/*void checkPrior(opHold **head,opHold **tail,char data){
  opHold *temp=*head;
  while(temp!=NULL){
  if(temp->op<=data)
  pop(&(*head),&(*tail));
  temp=temp->next;
  }
  }*/
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
	int T;
	scanf("%d",&T);
		getchar();
	while(T--){
		int flag=0;
		opHold *head=NULL;
		opHold *tail=NULL;
		char scanChar,popChar,prevChar;
		opHold *storeh=NULL;
		opHold *storet=NULL;
		char str[200];
		int i=0;
		scanf("%s",str);
		int strl=strlen(str)-1;
		if((str[0]>=42 && str[0]<=47)||str[0]=='^'){
			printf("invalid\n");
			continue;
		}
		if((str[strl]>=42 && str[strl]<=47)||str[strl]=='^'){
			printf("invalid\n");
			continue;
		}
		prevChar=0;
		while(scanChar=(str[i++])){
			if(scanChar=='\0'){
				flag==2;
				break;
			}
			if(((prevChar>=42) && (prevChar<=47)) && ((scanChar>=42) && (scanChar<=47))){
				printf("invalid\n");
				flag=1;
				break;
			}
			else if(((prevChar>=48) && (prevChar<=57)) && ((scanChar>=48) && (scanChar<=57))){
				printf("invalid\n");
				flag=1;
				break;
			}
			else if((prevChar==scanChar)&&(prevChar>=42)&&(scanChar>=42)){
				printf("invalid\n");
				flag=1;
				break;
			}
			push(&storeh,&storet,scanChar);
			prevChar=scanChar;
		}
		if(flag==1)continue;
		opHold *storehout=NULL;
		opHold *storetout=NULL;
		while(storeh!=NULL){
			if(flag==1)break;
			char storep=pop(&storeh,&storet);
			switch(storep){
				case '^':
				case '*':
				case '/':
					while(!emptyStack(&head)){
						popChar=pop(&head,&tail);
						if(popChar=='^'){
							push(&storehout,&storetout,popChar);
						}
						else{
							push(&head,&tail,popChar);
							break;
						}
					}
					push(&head,&tail,storep);
					break;
				case '+':
				case '-':
					while(!emptyStack(&head)){
						popChar=pop(&head,&tail);
						if(popChar=='/' || popChar=='*' || popChar=='^'){
							push(&storehout,&storetout,popChar);
						}
						else{
							push(&head,&tail,popChar);
							break;
						}
					}
					push(&head,&tail,storep);
					//	print(&head);
					break;
				case ')':
					push(&head,&tail,storep);
					break;
				case '(':
					while(!emptyStack(&head) && (popChar=pop(&head,&tail))!=')'){
						push(&storehout,&storetout,popChar);
					}
					if(popChar!=')')flag=1;
					break;
				default:
					push(&storehout,&storetout,storep);
					break;
		}
		}
		if(flag==1){
			printf("invalid\n");
			continue;
		}
		while(!emptyStack(&head)){
			char check;
			check=pop(&head,&tail);
			if(check==')'){
				printf("invalid\n");
				flag=1;
			}
			else push(&storehout,&storetout,check);
		}
		if(flag==1)continue;
		while(storehout!=NULL){
			printf("%c",pop(&storehout,&storetout));
		}
	printf("\n");
	}
	return 0;
}

