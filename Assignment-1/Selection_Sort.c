#include<stdio.h>
int main(){
	int N;
	//scanf("%d",&N);
	N=200000;
	int array[N],i,j,temp;
	for(i=0;i<N;i++)scanf("%d",&array[i]);
	for(j=0;j<N;j++){
		for(i=0;i<N-j;i++){
			if(array[i]>array[N-j]){
				temp=array[i];
				array[i]=array[N-j];
				array[N-j]=temp;
			}
		}
	}
	for(i=0;i<N;i++)printf("%d ",array[i]);
}
