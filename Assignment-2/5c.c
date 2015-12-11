#include<stdio.h>
#include<stdlib.h>
typedef struct node{
	int data;
	struct node * next;
}node;
int compare(const void *a,const void *b){
	return (*(int*)a-*(int*)b);
}
void print(node **head){
	node *temp=*head;
	while(temp->next!=*head){
		printf("--%d--",(temp)->data);
		temp=(temp)->next;
	}
	printf("--%d--",(temp)->data);
}
void insert(node **head,int val){
	node *new=(node*)malloc(sizeof(node));
	new->data=val;
	new->next=NULL;
	if(*head==NULL){
		*head=new;
		*tail=new;
	}
	else{
		(*tail)->next=new;
		*tail=new
		(*tail)->next=*head;
	}
}
void delete(node **head,int K,int count){
	int i;
	node *temp=*head;
	while(count!=1){
		i=0;
		while(i!=K-2){
			temp=temp->next;
			i++;
		}
		node *temp2=temp->next;
		temp->next=temp->next->next;
		free(temp2);
		temp=temp->next;
		count--;
	}
}
int main(){
	int T;
	scanf("%d",&T);
	while(T--){
		node *head=NULL;
		node *tail=NULL;
		int N;
		scanf("%d",&N);
		int array[N],i;
		for(i=0;i<N;i++)scanf("%d",&array[i]);
		qsort(array,N,sizeof(int),compare);
		for(i=0;i<N;i++)insert(&head,&tail,array[i]);
		print(&head);
		int K;
		scanf("%d",&K);
		delete(&head,K,N);
		printf("%d\n",head->data);
	}
}
