#include<stdio.h>
int main()
{
	long int a[10000];
	int t,i,j,k,l,n,p;
//	scanf("%d",&k);
//	for(l=0;l<k;l++)
//	{
		//printf("in1\n");
		n=10000;
		//scanf("%d",&n);
		a[0]=(-100000000);
		for(i=1;i<=n;i++)
		{
			//printf("in2\n");
			scanf("%ld",&a[i]);
		}
		for(i=2;i<=n;i++)
		{
			//printf("in3\n");
			t=a[i];
			p=(i-1);
			while(t<a[p])
			{
				//printf("in4\n");
				j=a[p+1];
				a[p+1]=a[p];
				a[p]=j;
				p-=(1);
			}
			a[p+1]=t;
		}
		for(i=1;i<=n;i++)
		{
			//printf("in5\n");
			printf("%ld",a[i]);
			if(i<n)
			{
				printf(" ");
			}
		}
		printf("\n");
//	}
	return 0;
}
