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
void checkPrior(opHold **head,opHold **tail,int data){
	opHold *temp=*head;
	while(temp!=NULL){
		if(temp->op<=data)
			pop(&(*head),&(*tail));
		temp=temp->next;
	}
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
		printf("%d\n",temp->op);
		temp=temp->next;
	}
}
int power(int num1,int num2){
	int pow=1;
	while(num2--)pow=pow*num1;
	return pow;
}
int main(){
	int T;
	scanf("%d",&T);
	getchar();
	while(T--){
		opHold *head=NULL;
		opHold *tail=NULL;
		int pop1,pop2,operated;
		char scanNum;
		opHold *rvrh=NULL;
		opHold *rvrt=NULL;
		int flag=0;
		int opCount=0,numCount=0;
		while(scanf("%c",&scanNum)){
			if(scanNum=='\n')break;
			if(scanNum=='+' || scanNum=='-' || scanNum=='*' || scanNum=='/' || scanNum=='^')opCount++;
			else numCount++;
			push(&rvrh,&rvrt,scanNum-'0');
		}
	//	print(&rvrh);
		if((rvrt->op)+'0'=='+' || rvrt->op+'0'=='-' || rvrt->op+'0'=='/' || rvrt->op+'0'=='*' || rvrt->op+'0'=='^'){
			printf("invalid\n");
			continue;
		}
		else if(numCount-opCount!=1){
			printf("invalid\n");
			continue;
		}
		while(rvrh!=NULL){
			scanNum=pop(&rvrh,&rvrt)+'0';
			if(scanNum >='0' && scanNum<='9')
				push(&head,&tail,scanNum-'0');
			else if(scanNum!='\n'){
				pop1=pop(&head,&tail);
				pop2=pop(&head,&tail);
				switch(scanNum){
					case '^':
						push(&head,&tail,power(pop1,pop2));
						break;
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
						if(pop2==0){
							flag=1;
							break;
						}
						push(&head,&tail,(pop1/pop2));
						break;
				}
			}
			else
				continue;
			if(flag==1)break;
		}
		if(flag==1)printf("invalid\n");
		else print(&head);
	}
	return 0;
}
