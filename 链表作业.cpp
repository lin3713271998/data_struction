#include <stdio.h>
#include <math.h>
#include <string.h>
#include <malloc.h>
#include <stdlib.h>
#include <conio.h>
#define len sizeof(stu)

typedef struct student{
    int num;//学号
	char name[20];//姓名
	int studentclass;//班级
	int dorm;//宿舍号
    struct student *next;
}stu;
stu *head;
int n;
int Tips()
{
    int p;
    printf("<-----链表学生管理系统功能实现------>\n");
    printf("<----------1.添加------------------->\n");
    printf("<----------2.删除------------------->\n");
    printf("<----------3.查找------------------->\n");
    printf("<----------4.逆转输出--------------->\n");
    printf("<----------5.删除XY之间------------->\n");
    printf("<----------6.打印输出--------------->\n");
    printf("<----------7.结点数----------------->\n");
    printf("<----------8.插入到后面------------->\n");
    printf("<----------0.退出------------------->\n");
   
    scanf("%d",&p);
    return p;

}


/*添加*/
stu * creat()
{
    stu *p1,*p2,*head;int i,k=1,sum;
    n=0;
    printf("输入学生信息的个数\n");
    scanf("%d",&sum);

    for(i=0;i<sum;i++)
    {
        p1=(stu *)malloc(len);
        printf("\n输入第%d个学生的信息\n",k++);
        printf("\n 请输入学生的学号：");
        scanf("%d",&p1->num);
		printf("\n 请输入学生的姓名:");
		scanf("%s", &p1->name);
		printf("\n 请输入学生的班级:");
		scanf("%d", &p1->studentclass);
		printf("\n 请输入学生的宿舍号:");
		scanf("%d", &p1->dorm); 
        n=n+1;
        if(n==1)
            head=p1;
        else
        p2->next=p1;
        p2=p1;
    }
    p2->next=0;
    return head;
}

/*删除*/
stu * del(stu * head,long num)
{
    stu *p1,*p2;
    if(head==0)
        printf("表空!\n");
    else
    {
        p1=head;
        while(p1->num!=num && p1->next!=0)
        {
            p2=p1;p1=p1->next;
        }
        if(p1->num==num)
        {
            if(p1==head)
            {
            head=p1->next;
            }
            else
            {
                p2->next=p1->next;

            }
            printf("删除学号:%ld成功\n",num);
            n=n-1;
       }
       else
            printf("没有%ld这个学号!\n",num);
    }
      return head;
}


/*查找*/
stu *find(stu * head,int x)
{
    int num=x;
     stu * p;
    
    p=head;
    if(head!=0)
    {
     while(p!=0)
       {if(p->num==num) 
       { printf("学号:%-10ld 姓名：%s 班级：%d 宿舍：%d\n",p->num,p->name,p->studentclass,p->dorm);
       getch();
	   }
        p=p->next;
        
		}
    
}
}

/*输出*/
void print(stu * head)
{
    stu * p;
    printf("此时的%d个学生信息是:\n",n);
    p=head;
    if(head!=0)
    {
     while(p!=0)
       {
        printf("学号:%-10ld 姓名：%s 班级：%d 宿舍：%d\n",p->num,p->name,p->studentclass,p->dorm);
        p=p->next;
       }
    }
}

/*结点数*/
void num(stu * head)
{
    stu * p;
    int num;
    p=head;
    if(head!=0)
    {
     while(p!=0)
       {num=num+1;
        p=p->next;
       }
        printf("结点数为%d",num);
    }
}

/*删除xy之间*/
void delin(stu * head)
{
    stu * p,*q;
    int x,y;
    p=head;
    q=head;
    if(head!=0)
    {
     printf("请输入x y\n ");
     scanf("%d %d",&x,&y);
    	for(p=head;p!=0;q=q->next)
   		 {
		    	if(p->num>=x&&p->num<=y)
		    	{
		    
		       del(head,p->num);
				}
           p=p->next;
		 }
    }
    printf("删除结果为：\n");
print(head);
}

//插入
void insert(stu *head)
{
    stu *p,*pnew;
    int m;
	pnew=(stu*)malloc(sizeof(stu));
    printf("班级:\n");
	scanf("%d",&pnew->studentclass);
	printf("学号:\n");
	scanf("%d",&pnew->num);
	printf("姓名:\n");
	scanf("%s",&pnew->name);
	printf("宿舍号:\n");
	scanf("%d",&pnew->dorm);
	printf("\n");
    printf("请输入想要插到的位置：\n");
	scanf("%d",&m);
	p=head;
	for(int j=1;j<m&&p!=NULL;j++)
	{
	    p=p->next;
	}
	pnew->next=p->next;
	p->next=pnew;
}
 
//typedef struct student{
//    int num;//学号
//	char name[20];//姓名
//	int studentclass;//班级
//	int dorm;//宿舍号
//    struct student *next;
//}stu;
/*转制*/ 
void rever(stu *head)
{
  stu *p,*q,*s;
  q=head;
  p=q->next;
  s=p->next;
  
while (s->next!=NULL)
{
p->next=q;
q=p;
p=s;
s=p->next;
}
s->next=p;
p->next=q;
head->next=NULL;
head=s;
print(head);
}

/*主函数*/
int main()
{
    stu * head=0,*stud;
    int m,x;
    long del_num;
    int i=1;
	int g;
    while(i>0)
    {
        system("cls");
        i=Tips();
        switch(i)
        {
            case 1:
           {   system("cls");
               printf("开始输入学生信息:\n");
               head=creat();
               system("cls");
               print(head);
               printf("请输入0返回\n");
               scanf("%d",&m);
               while(m!=0)
               {
                   printf("请输入0返回\n");
                   scanf("%d",&m);
               }
               break;

           }
            case 2:
           { 
                system("cls");
                printf("输入要删除的学号:");
                scanf("%ld",&del_num);
                head=del(head,del_num);
                print(head);
                printf("请输入0返回\n");
                scanf("%d",&m);
                while(m!=0)
                {
                   printf("请输入0返回\n");
                   scanf("%d",&m);
                }
                break;
           }
            case 3:
            {
                system("cls");
                getch();
                printf("\n 请输入所找学生的学号:");
		    	scanf("%d",&x); 
		    	find(head,x) ;
                break;
            }
            
            case 4:{//逆转输出 
            	system("cls");
            	rever(head);
            	getch();
				break; 
		           }
		    case 5:{ 
            	system("cls");
            	delin(head);
            	getch();
            	break;
		           }
		           
		    case 6:
            {   
                system("cls");
                print(head);
                printf("请输入0返回\n");
                scanf("%d",&m);
                while(m!=0)
                {
                    printf("请输入0返回\n");
                    scanf("%d",&m);
                }
                break;
            }
             case 7:{
            	system("cls");
            	 num(head);
            	 getch();
            	 break; 
		           }
		    case 8:{
            	system("cls");
            	 insert(head);
            	 getch();
            	 break; 
		           }
		    
		          
       }
    }
}
