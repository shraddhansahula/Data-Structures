#include<stdio.h>
typedef struct box{
	int vertNo;
	int time;
}vertice;
int adj[500][500],state[500],tadj[500][500],time=1,bhondu,flag=0;
vertice vert[500];
int cmp(const void* a,const void* b){
	return (*(vertice *)b).time-(*(vertice *)a).time;
}
void dfs(int v,int verC){
	int k=0;
	for(k=0;k<verC;k++){
		if(adj[v][k]==1 && state[k]==0){
			state[k]=1;
			time++;
			dfs(k,verC);
		}
	}
	state[v]=2;
	vert[v].time=time;
	time++;
}
void sdfs(int v,int verC){
	flag=0;
	int k;
	for(k=0;k<verC;k++){
		if(tadj[v][k]==1 && state[k]==0){
			flag=1;
			state[k]=1;
			sdfs(k,verC);
		}
	}
	state[v]=2;
	if(flag==0){
		bhondu=v;
		flag=1;
	}
}
int main(){
	int T;
	scanf("%d",&T);
	while(T--){
		int i,j;
		int verCount,edgeCount;
		scanf("%d %d",&verCount,&edgeCount);
		for(i=0;i<verCount;i++)
			for(j=0;j<verCount;j++){
				adj[i][j]=0;
				tadj[i][j]=0;
			}
		while(edgeCount--){
			scanf("%d %d",&i,&j);
			adj[i][j]=1;
			tadj[j][i]=1;
		}
		i=0;
		while(i!=verCount){
			state[i]=0;
			vert[i].vertNo=i;
			i++;
		}
		for(i=0;i<verCount;i++){
			if(state[i]==0){
				state[i]=1;
				time++;
				dfs(i,verCount);
			}
		}
	//	for(i=0;i<verCount;i++)printf("d->%d f->%d\n",dtime[i],ftime[i]);
		qsort(vert,verCount,sizeof(vertice),cmp);
	//	for(i=0;i<verCount;i++)printf("f->%d vert->%d\n",vert[i].time,vert[i].vertNo);
		i=0;
		while(i!=verCount){
			state[i]=0;
			i++;
		}
		int iden,sccCount=0;
		i=0;
		while(i!=verCount){
			iden=vert[i].vertNo;
			if(state[iden]==0){
				sccCount++;
				state[iden]=1;
				sdfs(iden,verCount);
			}
		//	printf("b->%d\n",bhondu);
		//	if(adj[bhondu][iden]==1)sccCount++;
		/*	else{
				for(j=0;j<verCount;j++)if(state[j]!=0)sccCount++;
			}*/
			i++;
		}
		printf("%d\n",sccCount);
	}
}
