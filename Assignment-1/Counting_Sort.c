#include<stdio.h>
int main(){
	int N;
	//scanf("%d",&N);
	N=5000;
	int array[N],i,max=0,result[N];
	for(i=0;i<N;i++){
		scanf("%d",&array[i]);
		if(array[i]>max)
			max=array[i];
	}
	int count[max+1];
	for(i=0;i<=max;i++)
		count[i]=0;
	for(i=0;i<N;i++){
		count[array[i]]++;
	}//extra space
	for(i=1;i<=max;i++){
		count[i]=count[i]+count[i-1];
	}
	for(i=N-1;i>=0;i--){
		result[count[array[i]]-1]=array[i];
		count[array[i]]--;
	}
	for(i=0;i<N;i++){
		printf("%d ",result[i]);
	}
	return 0;
}
