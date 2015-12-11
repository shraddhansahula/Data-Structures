#include<stdio.h>
int main(){
	int T;
	scanf("%d",&T);
	while(T--){
		int N;
		scanf("%d",&N);
		int array[N][50],i,scanNum,j,result[N][50];
		for(i=0;i<N;i++)for(j=0;j<50;j++){
			array[i][j]=0;
			result[i][j]=0;
		}
		for(i=0;i<N;i++){
			j=49;
			scanf("%d",&scanNum);
			while(scanNum){
				array[i][j]=scanNum%10;
				j--;
				scanNum/=10;
			}
		}
		int k,count[10];
		scanf("%d",&k);
		k+=1;
		j=49;
		while(k--){
			int x=49;
			//printf("maxDigi->%d\n",maxDigi);
			for(i=0;i<10;i++)count[i]=0;
			for(i=0;i<N;i++)count[array[i][j]]++;
			for(i=1;i<10;i++){
				count[i]=count[i]+count[i-1];
				//	printf("count of %d->%d\n",i,count[i]);
			}
			for(i=N-1;i>=0;i--){
				while(x!=-1){
					result[count[array[i][j]]-1][x]=array[i][x];
					x--;
				}
				count[array[i][j]]--;
			}
			x=49;
			for(i=0;i<N;i++){
				while(x!=-1)
				{
				array[i][x]=result[i][x];
				x--;
				}
			}
			j--;
		}
		int flag=1;
		for(i=0;i<N;i++){
			for(j=0;j<50;j++)if(array[i][j]!=0){
				flag=j;
				break;
			}
			for(j=flag;j<50;j++)printf("%d",array[i][j]);
			printf(" ");
		}
	}
	return 0;
}
