#include<stdio.h>
#include<stdlib.h>
typedef struct node{
	int data;
	int sum;
	struct node * next;
	struct node * prev;
}node;
void push(node **head,node **tail,int val){
	node *new=(node*)malloc(sizeof(node));
	new->data=val;
	new->sum=0;
	new->next=NULL;
	new->prev=NULL;
	if(*head==NULL){
		*head=new;
		*tail=new;
	}
	else{
		new->prev=*tail;
		(*tail)->next=new;
		*tail=new;
	}
}
int pop(node **head,node** tail){
	int val=0;
	node *temp;
	if(*head!=NULL){
		val=(*tail)->data;
		temp=*tail;
		(*tail)=(*tail)->prev;
		if(*tail!=NULL)(*tail)->next=NULL;
		free(temp);
	}
	return val;
}
void print(node **head){
	while(*head!=NULL){
		printf("%d %d\n",(*head)->data,(*head)->sum);
		(*head)=(*head)->next;
	}
}
int main(){
	int T;
	scanf("%d",&T);
	while(T--){
		int inputNo,flag=0;
		scanf("%d",&inputNo);
		node *head=NULL;
		node *tail=NULL;
		while(inputNo--){
			int scanChar;
			scanf("%d",&scanChar);
			if(scanChar<0){
				if(((tail)->data)<scanChar){
					flag=1;
					printf(":-( Try Again.\n");
					break;
				}
			}
			push(&head,&tail,-scanChar);
			print(&head);
		}
		else{
			popChar=pop(&head,&tail);
			if(scanChar!=popChar){
				flag=1;
				printf(":-( Try Again.\n");
				break;
			}
		//	if(tail!=NULL)(tail->sum)+=popChar;
		}
	}
	if(flag==0)printf(":-) Matrioshka\n");
}
return 0;
}
