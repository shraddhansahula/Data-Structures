#include<stdio.h>
#include<stdlib.h>
typedef struct node{
	int power;
	int coeff;
	int id;
}node;
typedef struct add{
	int power;
	int coeff;
}add;
typedef struct sub{
	int power;
	int coeff;
}sub;
typedef struct mutli{
	int power;
	int coeff;
}multi;
int compare(const void *a,const void *b){
	return (*(node*)a).power-(*(node*)b).power;
}
int main(){
	int T,coeff,power;
	scanf("%d",&T);
	while(T--){
		int firstPoly,secondPoly;
		scanf("%d %d",&firstPoly,&secondPoly);
		int total=firstPoly+secondPoly,i,j;
		node array[total];
		for(i=0;i<total;i++){
			scanf("%d %d",&array[i].power,&array[i].coeff);
			if(i<=firstPoly-1)
				array[i].id=0;
			else
				array[i].id=1;
		}
		node first[firstPoly],second[secondPoly];
		for(i=0;i<firstPoly;i++){
			first[i].power=array[i].power;
			first[i].coeff=array[i].coeff;
		}
		for(i=firstPoly;i<total;i++){
			second[i-firstPoly].power=array[i].power;
			second[i-firstPoly].coeff=array[i].coeff;
		}
		qsort(array,total,sizeof(node),compare);
		//for(i=0;i<firstPoly;i++)printf("%d %d\n",first[i].power,first[i].coeff);
		//for(i=0;i<secondPoly;i++)printf("%d %d\n",second[i].power,second[i].coeff);
		node add[total],sub[total];
		int countadd=0,countsub=0;
		for(i=0;i<total;i++){
			if(array[i].power==array[i+1].power){
				add[countadd].coeff=array[i].coeff+array[i+1].coeff;
				add[countadd].power=array[i].power;
				countadd++;
				if(array[i].coeff-array[i+1].coeff!=0){
					sub[countsub].coeff=array[i].coeff-array[i+1].coeff;
					sub[countsub].power=array[i].power;
					countsub++;
				}
				i++;
			}
			else{
				add[countadd].coeff=array[i].coeff;
				add[countadd].power=array[i].power;
				countadd++;
				if(array[i].id==0)sub[countsub].coeff=array[i].coeff;
				else sub[countsub].coeff=-array[i].coeff;
				sub[countsub].power=array[i].power;
				countsub++;
			}
		}
		node multi[firstPoly*secondPoly];
		int countmulti=0;
		for(i=0;i<firstPoly;i++){
			for(j=0;j<secondPoly;j++){
				multi[countmulti].power=first[i].power+second[j].power;
				multi[countmulti].coeff=first[i].coeff*second[j].coeff;
				countmulti++;
			}
		}
		node multicorr[countmulti];
		int cmulti=0,flag=0;
		qsort(multi,countmulti,sizeof(node),compare);
		for(i=0;i<countmulti;i++){
			multicorr[cmulti].power=multi[i].power;
			multicorr[cmulti].coeff=multi[i].coeff;
			for(j=i+1;j<countmulti;j++){
				if(multi[i].power==multi[j].power){
					//multicorr[cmulti].power=multicorr[j].power;
					multicorr[cmulti].coeff+=multi[j].coeff;
					i++;
				}
				else
					break;
			}
			cmulti++;

		}
		printf("%d\n",countadd);
		for(i=countadd-1;i>=0;i--){
			printf("%d %d\n",add[i].power,add[i].coeff);
		}
		printf("%d\n",countsub);
		for(i=countsub-1;i>=0;i--){
			printf("%d %d\n",sub[i].power,sub[i].coeff);
		}
		/*printf("%d\n",countmulti);
		for(i=countmulti-1;i>=0;i--){
			printf("%d %d\n",multi[i].power,multi[i].coeff);
		}*/
		printf("%d\n",cmulti);
		for(i=cmulti-1;i>=0;i--){
			printf("%d %d\n",multicorr[i].power,multicorr[i].coeff);
		}
	}
	return 0;
}
