#include<stdio.h>
#include<stdlib.h>
int main(){
	int Queue[10]={0},size=0,rear=0,front=0,scanVar,query;
	while(1){
		scanf("%d",&query);
		if(query==0)break;
		if(query==1){
			scanf("%d",&Queue[rear]);
			for(size=0;size<=rear;size++)printf("elememt[%d]->%d\n",size,Queue[size]);
			rear++;
			if(rear==9)rear=0;
		}
		else if(query==2){
			printf("%d",Queue[front]);
			front++;
			if(front==9)front=0;
		}
	}
}
