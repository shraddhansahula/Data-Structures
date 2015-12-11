#include<stdio.h>
void merge(long long unsigned int a[],long long int start,long long int mid,long long int end)
{
	long long int i1,i2,i=0;
	long long unsigned int b[end-start+1];
	i1=start;
	i2=mid+1;
	while((i1<mid+1) && (i2<end+1))
	{
		b[i]=(a[i1] < a[i2])? a[i1]:a[i2];
		if(b[i]==a[i1])
			i1++;
		else if(b[i]==a[i2])
			i2++;
		i++;
	}
	while(i1<mid+1)
	{
		b[i]=a[i1];
		i++;
		i1++;
	}
	while(i2<end+1)
	{
		b[i]=a[i2];
		i++;
		i2++;
	}
	for(i=0;i<(end-start+1);i++)
	{
		a[i+start]=b[i];
	//	printf("%d-->%lld\n",i,a[i]);
	}
}
void msort(long long unsigned int a[],long long int start,long long int end)
{
	long long int mid;
	if(end>start)
	{
		mid=(end+start)/2;
		msort(a,start,mid);
		msort(a,mid+1,end);
		merge(a,start,mid,end);
	}
}
int main()
{
	//int T;
	//scanf("%d",&T);
	//while(T--)
	//{
		long long unsigned int array[5000];
		long long int i,N;
		//scanf("%lld",&N);
		N=5000;
		for(i=0;i<N;i++)
		{
			scanf("%lld",&array[i]);
		}
		msort(array,0,N-1);
		for(i=0;i<N;i++)
		{
			printf("%lld ",array[i]);
		}
		printf("\n");
	//}
	return 0;
}
