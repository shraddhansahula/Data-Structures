#include<stdio.h>
void swap(int *a,int *b){
	int t;
	t=*a;
	*a=*b;
	*b=t;
}
void quickSort(int a[],int left,int right){
	int pivot=left;
	int smallIn=right,bigIn=left+1;
	if(right>left){
		while(1){
			while(a[bigIn]<=a[left]){
				++bigIn;
			}
			while(a[smallIn]>a[left]){
				--smallIn;
			}
			if(bigIn<smallIn)swap(&a[bigIn],&a[smallIn]);
			else break;
		}
		swap(&a[left],&a[smallIn]);
		quickSort(a,left,smallIn-1);
		quickSort(a,smallIn+1,right);
	}
}
int main(){
	int N;
	scanf("%d",&N);
	int array[N],i;
	for(i=0;i<N;i++)scanf("%d",&array[i]);
	quickSort(array,0,N-1);
	for(i=0;i<N;i++)printf("%d ",array[i]);
	printf("\n");
}
