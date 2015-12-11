#include<stdio.h>
int main(){
	int testCases;
	scanf("%d",&testCases);
	while(testCases--){
		int numGen,firstPerson,secondPerson,count1=0,count2=0,f,s,flag=0;
		scanf("%d %d %d",&numGen,&firstPerson,&secondPerson);
		f=firstPerson;
		s=secondPerson;
		while(firstPerson){
			firstPerson=firstPerson>>1;
			count1++;
		}
		while(secondPerson){
			secondPerson=secondPerson>>1;
			count2++;
		}
		while(count1!=count2){
			if(count1>count2){
				f=f>>1;
				count1--;
			}
			else if(count2>count1){
				s=s>>1;
				count2--;
			}
		}
		while(s){
			if(s==f){
				printf("%d\n",s);
				flag=1;
				break;
			}
			f=f>>1;
			s=s>>1;
		}
		if(flag==0)printf("1\n");
	}
	return 0;
}
