#include<stdio.h>
int main(){
	int i;
	//This for loop generates random numbers(limits can be 5k,10k,100k,200k)
	for(i=0;i<200000;i++){
		printf("%d ",i%1000007);
	}
}
