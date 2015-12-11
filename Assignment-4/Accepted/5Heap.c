#include<stdio.h>
void maxHeapInsert(int array[],int val,int index){
	array[index]=val;
	int done=0,parent,i,swap;
	if(index==1)return;
	parent=index/2;
	while(!done){
		if(parent==0)break;
		if(array[parent]<array[index]){
			swap=array[parent];
			array[parent]=array[index];
			array[index]=swap;
			index=parent;
			parent=parent/2;
		}
		else done=1;
	}
}
void minHeapInsert(int array[],int val,int index){
	array[index]=val;
	int done=0,parent,i,swap;
	if(index==1)return;
	parent=index/2;
	while(!done){
		if(parent==0)break;
		if(array[parent]>array[index]){
			swap=array[parent];
			array[parent]=array[index];
			array[index]=swap;
			index=parent;
			parent=parent/2;
		}
		else done=1;
	}
}
int maxHeapDelete(int array[],int max){
	if(max==0)return -1;
	int data,done=0;
	data=array[1];
	array[1]=array[max];
	int i=1,swap;
	while((2*i)<max){
		if((2*i+1)<max){
				if(array[2*i]>array[2*i+1]){
					if((array[i]<array[2*i])){
						swap=array[2*i];
						array[2*i]=array[i];
						array[i]=swap;
						i=2*i;
					}
					else break;
				}
				else{
					if((array[i]<array[2*i+1])){
						swap=array[2*i+1];
						array[2*i+1]=array[i];
						array[i]=swap;
						i=2*i+1;
					}
					else break;
				}
			}
			else
			{
				if(array[i]<array[2*i])
				{
					swap=array[2*i];
					array[2*i]=array[i];
					array[i]=swap;
					i=2*i;
				}
				else break;
			}
	}
	return data;
}
int minHeapDelete(int array[],int min){
	if(min==0)return -1;
	int data,done=0;
	data=array[1];
	array[1]=array[min];
	int i=1,swap;
	while((2*i)<min){
		if((2*i+1)<min){
				if(array[2*i]<array[2*i+1]){
					if((array[i]>array[2*i])){
						swap=array[2*i];
						array[2*i]=array[i];
						array[i]=swap;
						i=2*i;
					}
					else break;
				}
				else{
					if((array[i]>array[2*i+1])){
						swap=array[2*i+1];
						array[2*i+1]=array[i];
						array[i]=swap;
						i=2*i+1;
					}
					else break;
				}
			}
		else
		{
			if(array[i]>array[2*i])
			{
				swap=array[2*i];
				array[2*i]=array[i];
				array[i]=swap;
				i=2*i;
			}
			else break;
		}
	}
	return data;
}
int main(){
	int N,i;
	scanf("%d",&N);
	int maxHeap[N],minHeap[N],max=0,min=0,count=0;
	while(N--){
		int query,marks,cutoff;
		scanf("%d",&query);
		if(query==1){
			if(min!=0)cutoff=minHeap[1];
			else cutoff=-1;
			printf("%d\n",cutoff);
		}
		else if(query==2){
			scanf("%d",&marks);
			count=count+1;
			if(count%4==0){
				if(marks>maxHeap[1]){				
					min++;
					minHeapInsert(minHeap,marks,min);
				}
				else{
					min++;
					minHeapInsert(minHeap,maxHeapDelete(maxHeap,max),min);
					maxHeapInsert(maxHeap,marks,max);
				}
			}
			else{
				if(marks>minHeap[1] && min!=0){
					max++;
					maxHeapInsert(maxHeap,minHeapDelete(minHeap,min),max);
					minHeapInsert(minHeap,marks,min);
				}
				else{
					max++;
						maxHeapInsert(maxHeap,marks,max);
				}
			}
		}
	}
	return 0;
}
