#include <stdio.h>
#include <malloc.h>
#include <stdlib.h>
#include <windows.h>

//树的定义 
typedef struct node{
	char data;
	struct node *lchild, *rchild;	
}bintnode;
bintnode *root;



//二叉树的创建函数 
bintnode *creat (){
bintnode *t;//??为何必须在这里创建 
char ch;
scanf("%c",&ch);
if(ch=='#')
t=NULL;
else
    {t=(bintnode*)malloc(sizeof(bintnode));
  	 t->data=ch;
  	 t->lchild=creat ();
  	  t->rchild=creat ();
	}			
return t;	
}
/*
前序遍历
(root->left->right)
*/
void preorder(bintnode *t)
{char data;
	
if(t!=NULL)
{data=t->data;
printf("%c",data);
preorder(t->lchild);
	
preorder(t->rchild);	
}	
	
}

//中序遍历(left->root->right)
void ineorder(bintnode *t){
char data;	
if(t!=NULL)
{data=t->data;

preorder(t->lchild);
printf("%c",data);	
preorder(t->rchild);	

}
}
//后序遍历 

void postorder(bintnode *t){

char data;	
if(t!=NULL)
{data=t->data;

preorder(t->lchild);
	
preorder(t->rchild);
printf("%c",data);
}
}

//主函数 

int main() 
{
	system("color 4");
	system("color 1D");
bintnode *t=0;
printf("二叉树的创建：");	
	t=creat();
printf("\n");	
printf("前序遍历：");	
preorder(t);
printf("\n");
printf("中序遍历：");
ineorder(t);
printf("\n");
printf("后序遍历：");
postorder(t);

return 0;	
}
	//abd#e##fg###c##















