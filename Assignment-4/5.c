#include<stdio.h>
#include<stdlib.h>
int cmp(const void * a,const void * b){
	return (*(int *)b)-(*(int *)a);
}
int main(){
	int N,i;
	scanf("%d",&N);
	int array[N];
	for(i=0;i<N;i++)array[N]=-1;
	int index=-1;
	while(N--){
		int query,marks;
		scanf("%d",&query);
		if(query==1){
			if(((index+1)/4))printf("%d\n",array[((index+1)/4)-1]);
			else printf("-1\n");
		}
		else if(query==2){
			scanf("%d",&marks);
			index=index+1;
			array[index]=marks;
			qsort(array,index+1,sizeof(int),cmp);
		}
	}
	return 0;
}
