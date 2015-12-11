#include<stdlib.h>
typedef struct node{
	int data,height;
	struct node * right;
	struct node * left;
}AVLnode;
int flag=0;
int height(AVLnode * node){
	if(!node) return -1;
	else return node->height;
}
AVLnode * findMin(AVLnode * root){
	if(!root) return NULL;
	else{
		if(root->left==NULL) return root;
		else return findMin(root->left);
	}
}
AVLnode * SingleRotateR(AVLnode * invalid){
	AVLnode * hope;
	hope=invalid->right;
	invalid->right=hope->left;
	hope->left=invalid;
	invalid->height=((height(invalid->left)>height(invalid->right))?height(invalid->left):height(invalid->right))+1;
	hope->height=((height(hope->left)>height(hope->right))?height(hope->left):height(hope->right))+1;
	return hope;
}
AVLnode * SingleRotateL(AVLnode * invalid){
	AVLnode * hope;
	hope=invalid->left;
	invalid->left=hope->right;
	hope->right=invalid;
	invalid->height=((height(invalid->left)>height(invalid->right))?height(invalid->left):height(invalid->right))+1;
	hope->height=((height(hope->left)>height(hope->right))?height(hope->left):height(hope->right))+1;
	return hope;
}
AVLnode * DoubleRotateR(AVLnode * invalid){
	AVLnode *hope;
	hope=SingleRotateL(invalid->right);
	invalid->right=hope;
	return SingleRotateR(invalid);
}
AVLnode * DoubleRotateL(AVLnode * invalid){
	AVLnode * hope;
	hope=SingleRotateR(invalid->left);
	invalid->left=hope;
	return SingleRotateL(invalid);
}
AVLnode * delete(AVLnode * root,int val){
	AVLnode * temp;
	if(root->data==val){
		if(root->right && root->left){
			temp=findMin(root->right);
			root->data=temp->data;
			root->right=delete(root->right,root->data);
		if(height(root->right)-height(root->left)==2 || height(root->left)-height(root->right)==2){
			if(height(root->left)<height(root->right)){
				if(height(root->right->right)>=height(root->right->left)) root=SingleRotateR(root);
				else root=DoubleRotateR(root);
			}
			else{
				if(height(root->left->left)>=height(root->left->right)) root=SingleRotateL(root);
				else root=DoubleRotateL(root);
			}
		}
		}
		else{
			temp=root;
			if(root->left==NULL){
				root=root->right;
	if(root) root->height=(height(root->left)>height(root->right)?height(root->left):height(root->right))+1;
			}
			else if(root->right==NULL){
				root=root->left;
	if(root) root->height=(height(root->left)>height(root->right)?height(root->left):height(root->right))+1;
			}
			free(temp);
		}
	}
	else if(root->data > val){
		root->left=delete(root->left,val);
		if(height(root->right)-height(root->left)==2 || height(root->left)-height(root->right)==2){
			if(height(root->right)<height(root->left)){
				if(height(root->left->left)>=height(root->left->right)) root=SingleRotateL(root);
				else root=DoubleRotateL(root);
			}
			else{
				if(height(root->right->right)>=height(root->right->left)) root=SingleRotateR(root);
				else root=DoubleRotateR(root);
			}
		}
	}
	else if(root->data < val){
		root->right=delete(root->right,val);
		if(height(root->right)-height(root->left)==2 || height(root->left)-height(root->right)==2){
			if(height(root->left)<height(root->right)){
				if(height(root->right->right)>=height(root->right->left)) root=SingleRotateR(root);
				else root=DoubleRotateR(root);
			}
			else{
				if(height(root->left->left)>=height(root->left->right)) root=SingleRotateL(root);
				else root=DoubleRotateL(root);
			}
		}
	}
	if(root) root->height=(height(root->left)>height(root->right)?height(root->left):height(root->right))+1;
	return root;
}
void find(AVLnode ** root,int val){
	if(*root){
		find(&(*root)->left,val);
		if((*root)->data==val) flag=1;
		find(&(*root)->right,val);
	}
}
int pflag=0;
void preOrder(AVLnode ** root){
	if(*root){
		if(pflag==0){
			printf("%d",(*root)->data);
			pflag=1;
		}
		else printf(" %d",(*root)->data);
		preOrder(&(*root)->left);
		preOrder(&(*root)->right);
	}
}
AVLnode * insert(AVLnode * root,int val){
	if(!root){
		root=(AVLnode *)malloc(sizeof(AVLnode));
		root->data=val;
		root->left=NULL;
		root->right=NULL;
	}
	else if(root->data < val){
		root->right=insert(root->right,val);
		if(height(root->right)-height(root->left)==2 || height(root->left)-height(root->right)==2){
			if(val > root->right->data) root=SingleRotateR(root);
			else root=DoubleRotateR(root);
		}
	}
	else if(root->data > val){
		root->left=insert(root->left,val);
		if(height(root->right)-height(root->left)==2 || height(root->left)-height(root->right)==2){
			if(val < root->left->data) root=SingleRotateL(root);
			else root=DoubleRotateL(root);
		}
	}
	root->height=(height(root->left)>height(root->right)?height(root->left):height(root->right))+1;
	return root;
}
int main(){
	int testCases;
	scanf("%d",&testCases);
	while(testCases--){
		AVLnode *root=NULL;
		int noQueries;
		scanf("%d",&noQueries);
		while(noQueries--){
			pflag=0;
			flag=0;
			getchar();
			int scanNum;
			AVLnode *delNode=NULL;
			char qId;
			scanf("%c",&qId);
			if(qId=='i'){
				scanf("%d",&scanNum);
				root=insert(root,scanNum);
			}
			else if(qId=='d'){
				scanf("%d",&scanNum);
				find(&root,scanNum);
				if(flag) root=delete(root,scanNum);
			}
			else{
				preOrder(&root);
				printf("\n");
			}
		}
	}
	return 0;
}

