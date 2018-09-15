#include <stdio.h>
#include <math.h>
#include <string.h>
#include <malloc.h>
#include <stdlib.h>
#include <conio.h>
typedef struct{
	int a[100];
    int size;
	}slist;
	
/*界面*/ 
int Tips()
{
    int p;
    printf("<----------请选择功能---------->\n");
    printf("<----------1.置空-------->\n");
    printf("<----------2.打印-------->\n");
    printf("<----------3.查找-------->\n");
    printf("<----------4.插入-------->\n");
    printf("<----------5.删除-------->\n");
    scanf("%d",&p);
    return p;

}
/*置空*/ 
void append(slist *slt)
{
slt->size=0;	
}
/*打印*/
void display(slist slt)
{
	int i;
	for(i=1;i<=slt.size;i++)
	{
	printf("%5d",slt.a[i]);
	}
}

/*查找*/
void find(slist *slt,int y) 
{
	int x=y;
	int i=0;
	while(i<slt->size&&slt->a[i]!=x) i++;
	if(i<slt->size)
	printf("第%d个为所查找",i+1);
	else
	printf("未找到！\n");
}

/*插入*/
void insert(slist *slt,int y) 
{
    int i;
    int x;
    printf("请输入值\n");
    scanf("%d",&x);
	for(i=slt->size;i>y;i--)
	slt->a[i]=slt->a[i-1];
	slt->a[y]=x;
	slt->size++;
}

/*删除*/
void del(slist *slt,int x) 
{
	int b=x;
    int i;
	for(i=b;i<slt->size-1;i++)
	slt->a[i]=slt->a[i+1];
	slt->size--;
}


/*主函数*/
int main()
{
    int i=1;
	int x,y,z;
    int n = 5;
    slist l= {{1,2,3,4,5}, 5};
    while(i>0)
    {
        system("cls");
        i=Tips();
        switch(i)
        {
            case 1:
           {   system("cls");
               append(&l);
               getch();
               break;

           }
        
            case 2:
            {system("cls");
                for(i=0;i<l.size;i++)
    				{
					printf("%5d",l.a[i]);
					}
					  getch();
                break; 
            }
            case 3:
            {  system("cls");
				printf("请输入查找值\n");
            	scanf("%d",&z); 
               find(&l,z);
                 getch();
                break;
            }
            case 4:{ 
            	system("cls");
            	printf("请输入插入位置\n");
            	scanf("%d",&y);
            	insert(&l,y);
            	  getch();
            	break;
		           }
		    case 5:{
            	system("cls");
            	printf("请输入删除位置\n");
            	scanf("%d",&x);
            	del(&l,x);
            	  getch();
            	  break;
		           }
		     
       }
    }
}
