#include<stdio.h>
int compare(const void * a,const void * b){
	return (*(int*)a-*(int*)b);
}
int main(){
	int N,i;
	//scanf("%d",&N);
	N=200000;
	int array[N];
	for(i=0;i<N;i++){
		scanf("%d",&array[i]);
	}
	qsort(array,N,sizeof(int),compare);
	for(i=0;i<N;i++){
		printf("%d ",array[i]);
	}
	return 0;
}
