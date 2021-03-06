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
	int T;
	scanf("%d",&T);
	while(T--){
		int numNodes,numConnect;
		scanf("%d %d",&numNodes,&numConnect);
		int adj[numNodes+1][numNodes+1],parent[numNodes+1],state[numNodes+1],distance[numNodes+1],i,j;
		for(i=0;i<numNodes;i++){
			state[i]=0;
			for(j=0;j<numNodes;j++)adj[i][j]=0;
		}
		while(numConnect--){
			scanf("%d %d",&i,&j);
			adj[i][j]=1;
			adj[j][i]=1;
		}
		int nflag=0,ans[numNodes],index=0;
		for(i=1;i<=numNodes;i++){
			int vulner=i-1,flag=0;
			if(i==numNodes){
				i=0;
				flag=1;
			}
			node *head=NULL;
			node *tail=NULL;
			node *dhead=NULL;
			node *dtail=NULL;
			int root,deq,k,count=0;
			root=i;
			distance[root]=0;
			state[root]=1;
			parent[root]=-1;
			enqueue(&head,&tail,root);
			while(head!=NULL){
				deq=dequeue(&head,&tail,&dhead,&dtail);
				for(j=0;j<numNodes;j++){
					if(adj[deq][j]==1 && j!=vulner){
						if(state[j]==0){
							state[j]=1;
							parent[j]=deq;
							distance[j]=distance[deq]+1;
							enqueue(&head,&tail,j);
						}
					}
				}
				state[deq]=2;
			}
			for(k=0;k<numNodes;k++)if(state[k]==0)count++;
			for(k=0;k<numNodes;k++)state[k]=0;
			if(count>1){
				ans[index]=vulner;
				index++;
				nflag=1;
			}
			if(flag)break;
		}
		if(!nflag)printf("NONE\n");
		else{
			for(i=0;i<index;i++){
				if(i==index-1)printf("%d\n",ans[i]);
				else printf("%d ",ans[i]);
			}
		}
	}
	return 0;
}
