//Radix Sort not using linked lists
#include<stdio.h>
#include<stdlib.h>
int power(int n,int k){
	int i=n;
	int j;
	n=1;
	for(j=0;j<k;j++)n*=i;
	return n;
}
int main(){
	int N;
	scanf("%d",&N);
	int array[N],result[N],count[10]={0},i,j,max=0,maxDigi=0;
	for(i=0;i<N;i++){
		scanf("%d",&array[i]);
		result[i]=array[i];
		if(array[i]>max)max=array[i];
	}
	while(max!=0){
		maxDigi++;
		max=max/10;
	}
	j=maxDigi;
	while(maxDigi--){
		for(i=0;i<10;i++)count[i]=0;
		for(i=0;i<N;i++)count[(array[i]%power(10,j-maxDigi))/power(10,j-maxDigi-1)]++;
		for(i=1;i<10;i++)count[i]=count[i]+count[i-1];
		for(i=N-1;i>=0;i--){
			result[count[(array[i]%power(10,j-maxDigi))/power(10,j-maxDigi-1)]-1]=array[i];
			count[(array[i]%power(10,j-maxDigi))/power(10,j-maxDigi-1)]--;
		}
		for(i=0;i<N;i++)array[i]=result[i];
	}
	for(i=0;i<N;i++)printf("%d ",result[i]);
}
