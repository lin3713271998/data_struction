#include<stdio.h>
#include<stdlib.h>
#define N 21;
 
typedef struct Point
{
    int data;
    struct Point *next;
}Node,*pNode;
int main()
{
    void create(pNode);
    void separate(pNode,pNode);
    void print(pNode);
    pNode A=NULL,B=NULL;
    A=(pNode)malloc(sizeof(Node));
    B=(pNode)malloc(sizeof(Node));
    printf("Enter numbers(input 0 to end):\n");
    create(A);
    separate(A,B);
    print(A);
    print(B);
    return 0;
}
 
void create(pNode head)
{
    int n=0;
    pNode p,q;
    p=q=(pNode)malloc(sizeof(Node));
    scanf("%d",&p->data);
    while(p->data!=0)
    {
        ++n;
        if(n==1)
            head->next=p;
        else
            q->next=p;
        q=p;
        p=(pNode)malloc(sizeof(Node));
        scanf("%d",&p->data);
    }
    q->next=NULL;
}
 
void separate(pNode A,pNode B)
{
    pNode pa1,pa2,pb;
    pa1=A->next;
    pa2=A;
    pb=B;
    while(pa1!=NULL)
    {
        while(pa1->data%2!=0&&pa1->next!=NULL)
        {
            pa2=pa1;
            pa1=pa1->next;
        }
        if(pa1->data%2==0)
        {
            pa2->next=pa1->next;
            pb->next=pa1;
            pb=pb->next;
            pa1=pa2->next;
        }
        else
            pa1=pa1->next;
    }
    pb->next=NULL;
}
 
void print(pNode head)
{
    pNode p=head->next;
    while(p!=NULL)
    {
        printf("%d ",p->data);
        p=p->next;
    }
    putchar(10);
}

