#include <stdio.h>
#include <math.h>
#include <string.h>
#include <malloc.h>
#include <stdlib.h>
#include <conio.h>
//树的定义 
typedef struct node{
	char data;
	struct node *lchild, *rchild;	
}bintnode;
bintnode *root;


//栈的定义
typedef struct stack{
bintnode *data[100];
int tag[100];
int top;	
}stack;
//stack *s;
 
stack init()
{
    stack s;
    s.top =0;
    return s;
}
//进栈
void push(stack *s,bintnode *t) 
{		
s->data[s->top]=t;
s->top++;	
}
//出栈 
bintnode *pop(stack *s)
{
if(s->top!=0)
	{s->top--;
	return(s->data[s->top]);
	}	
else
return NULL;	
	
}

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
{
	char data;
stack s;
s=init();
s.top = 0;
while((t)||(s.top!=0))	
	{
	if(t){
		data=t->data;
	printf("%c",data);
	push(&s,t);
	t=t->lchild;	
	}
	else
	{
		t=pop(&s);
		t=t->rchild;
	}		
}
}

//中序遍历(left->root->right)
void ineorder(bintnode *t){
stack s;
s=init();
s.top = 0;
while((t!=NULL)||(s.top!=0))	
{
	if(t)
	{
	push(&s,t);
	t=t->lchild;	
	}
	else
	{
		t=pop(&s);
		printf("%c",t->data);
		t=t->rchild;
	}		
}
}

//后序遍历 

void postorder(bintnode *t){
stack s;
s=init();
s.top = 0;
while((t!=NULL)||(s.top!=0))	
{
	if(t)
	{
	s.data[s.top]=t;
	s.tag[s.top]=0;
	s.top++;
	t=t->lchild;	
	}
	else
	if(s.tag[s.top-1]==1)
	{s.top--;
	t=s.data[s.top];
	printf("%c",t->data);
	t=NULL;
	}
	else
	{
	t=s.data[s.top-1];
	 s.tag[s.top-1]=1;
	 t=t->rchild;
	}		
}
}


//主函数 

int main() 
{
bintnode *T ;
printf("二叉树的创建：");	
	T=creat();
	
printf("前序遍历：");	
preorder(T);
printf("\n");
printf("中序遍历：");
ineorder(T);
printf("\n");
printf("后序遍历：");
postorder(T);
printf("\n");

return 0;	
}
	/*
	
	测试代码： 
	
	abd#e##fg###c##

    */













