#include<stdio.h>
int main(){
	int no_Num,scanNum,done,swap;
	scanf("%d",&no_Num);
	int array[no_Num+1],i=1,parent=1,j=1,sparent=1,t;
	array[0]=32786;
	t=no_Num;
	//Insert
	while(no_Num--){
		scanf("%d",&scanNum);
		array[i]=scanNum;
		done=0;
		while(!done){
			if(array[i]<array[parent]){
				swap=array[i];
				array[i]=array[parent];
				array[parent]=swap;
				i=parent;
				parent=parent/2;
			}
			else done=1;
		}
		i=j;
		parent=sparent;
	//	printf("ye lo-%d\n",array[i]);
		if(i==parent){
			i=2*parent;
			j=i;
		}
		else if(i==(2*parent)){
			i+=1;
			j=i;
		}
		else{
			parent+=1;
			sparent=parent;
			i=2*parent;
			j=i;
		}
	}
	//for(i=0;i<t+1;i++)printf("%d ",array[i]);
	int k=t,g=t;
	//Delete
	while(k--){
	i=1;
	printf("%d\n",array[i]);
	array[i]=array[t];
	while((2*i)+1<t){
		if(array[i]>array[2*i] && array[2*i]<array[(2*i)+1]){
			swap=array[i];
			array[i]=array[2*i];
			array[2*i]=swap;
			i=2*i;
		}
		else if(array[i]>array[(2*i)+1]){
			swap=array[i];
			array[i]=array[(2*i)+1];
			array[(2*i)+1]=swap;
			i=(2*i)+1;
		}
	}
	t--;
	}
	//for(i=0;i<g+1;i++)printf("%d ",array[i]);
	//for(i=0;i<t+1;i++)printf("%d ",array[i]);
	//printf("\n");
	return 0;
}
