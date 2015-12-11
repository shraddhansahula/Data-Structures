#include<stdio.h>
#include<stdlib.h>
typedef struct node{
	int digi;
	struct node *next;
	struct node *prev;
}node;
void insert(node **head,node **tail,int val){
	node *new=(node*)malloc(sizeof(node));
	new->digi=val;
	new->next=NULL;
	new->prev=NULL;
	if(*head==NULL){
		*head=new;
		*tail=new;
	}
	else{
		(*tail)->next=new;
		new->prev=*tail;
		new->next=NULL;
		*tail=new;
	}
}
void print(node **head){
	node *temp=*head;
	while(temp!=NULL){
		if(temp->next==NULL)printf("%d",temp->digi);
		else printf("%d",temp->digi);
		temp=temp->next;
	}
}
int selectindex(node **tail,int passCount){
	node *temp=*tail;
	passCount-=1;
	while(passCount--){
		temp=temp->prev;
	}
	if(temp==NULL)return 0;
	return temp->digi;

}
int main(){
	int T;
	scanf("%d",&T);
	while(T--){
		int N,j,i;
		scanf("%d",&N);
		node *head[N];
		node *tail[N];
		node *resulthead[N];
		node *resulttail[N];
		for(j=0;j<N;j++)head[j]=tail[j]=resulthead[j]=resulttail[j]=NULL;
		char scanNum[51];
		j=0;
		int cN=N;
		while(N--){
			scanf("%s",scanNum);
			int i=0;
			while(scanNum[i]!='\0'){
				insert(&(head[j]),&(tail[j]),scanNum[i]-'0');
				i++;
			}
			j++;
		}
		int count[10],pK,Kc=1;
		scanf("%d",&pK);
		while(pK--){
			for(i=0;i<10;i++)count[i]=0;
			for(i=0;i<cN;i++){
				count[selectindex(&(tail[i]),Kc)]++;
			}
			for(i=1;i<10;i++)count[i]+=count[i-1];
			for(i=cN-1;i>=0;i--){
				resulthead[count[selectindex(&(tail[i]),Kc)]-1]=head[i];
				resulttail[count[selectindex(&(tail[i]),Kc)]-1]=tail[i];
				count[selectindex(&(tail[i]),Kc)]--;
			}
			for(i=0;i<cN;i++){
				head[i]=resulthead[i];
				tail[i]=resulttail[i];
			}
			Kc++;
		}
		for(i=0;i<cN;i++){
			print(&head[i]);
			if(i<cN-1)
				printf(" ");
		}
		printf("\n");
	}
	return 0;
		
}
