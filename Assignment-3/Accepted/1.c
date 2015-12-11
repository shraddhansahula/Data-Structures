#include<stdio.h>
int main(){
	int testCases;
	scanf("%d",&testCases);
	while(testCases--){
		int inputNo;
		scanf("%d",&inputNo);
		int array[inputNo/2],i=0,j,flag=0,scanChar,sum[inputNo/2];
		for(j=0;j<inputNo/2;j++)sum[j]=0;
		int flagc=0;
		while(inputNo--){
			flag=0;
			scanf("%d",&scanChar);
			if(scanChar<0){
				array[i]=-scanChar;
				if(flagc){
					printf(":-( Try again.\n");
					flag=1;
					break;
				}
				if(i>0){
					if(array[i]>array[i-1]){
						printf(":-( Try again.\n");
						flag=1;
						break;
					}
				}
				i++;
			}
			else if(scanChar>0){
				if(i==1)flagc=1;
				if(scanChar!=array[i-1]){
					printf(":-( Try again.\n");
					flag=1;
					break;
				}
				else{
					if(i>=2){
						sum[i-2]+=array[i-1];
						if(sum[i-2]>=array[i-2]){
							flag=1;
							printf(":-( Try again.\n");
							break;
						}
					}
				}
				if(i>=1)sum[i-1]=0;
				i--;
			}
		}
		if(flag==0)printf(":-) Matrioshka!\n");
		while((inputNo--)>0)scanf("%d",&scanChar);
	}
	return 0;
}
