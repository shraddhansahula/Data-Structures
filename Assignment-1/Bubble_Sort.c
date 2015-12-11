#include<stdio.h>
int main(){
	int N,i,j,temp;
	N=200000;
	//scanf("%d",&N);
	int array[N];
	for(i=0;i<N;i++){
		scanf("%d",&array[i]);
	}
	for(i=0;i<N;i++){
		for(j=0;j<N-1;j++){
			if(array[j]>array[j+1]){
				temp=array[j];
				array[j]=array[j+1];
				array[j+1]=temp;
			}
		}
	}
	for(i=0;i<N;i++)
		printf("%d ",array[i]);
	return 0;
}
