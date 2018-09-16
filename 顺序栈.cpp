#include <stdio.h>
#include <math.h>
#include <string.h>
#include <malloc.h>
#include <stdlib.h>
#include <conio.h>
typedef struct {
	int	a[100];
	int	top;
}stack;
stack slt;
/*界面*/
int Tips()
{
	int p;
	printf( "<----------请选择功能---------->\n" );
	printf( "<----------1.进栈-------->\n" );
	printf( "<----------2.出栈-------->\n" );
	printf( "<----------3.打印-------->\n" );
	printf( "<----------4.取栈顶-------->\n" );
	scanf( "%d", &p );
	return(p);
}


/* 初始化 */
void init( stack *L )
{
	L->top	= 0;
}


/* 出栈 */
void pop( stack *L )
{
	if ( L->top == 0 )
	{
		printf( "空的" );
	}else  {
		L->top--;
	}
}


/* 遍历输出 */
void display( stack *L )
{
	for ( int i = 0; i < L->top; i++ )
	{
		printf( "%d ", L->a[i] );
	}
	printf( "\n" );
}


/* 取栈顶 */
void read( stack *L )
{
	if ( L->top == 0 )
	{
		printf( "空的" );
	}else  {
		printf( "%d\n", L->a[L->top - 1] );
	}
}


/*主函数*/
int main()
{
	int	num;
	int	i;
	init( &slt );
	while ( true )
	{
		system( "cls" );
		i = Tips();
		switch ( i )
		{
		case 1:
		{ system( "cls" );

		  printf( "*********输入5个入栈数据*********\n\n\n" );
		  for ( i = 1; i <= 5; i++ )
		  {
			  printf( "输入第%d个入栈数据\n", i );
			  scanf( "%d", &num );
			  /* slt = (stack*)malloc(sizeof(stack)); */
			  slt.top++;   /* 入栈所以加 */
			  slt.a[slt.top] = num;
		  }
		  getch();
		  break; }
		case 2:
		{
			system( "cls" );
			pop( &slt );
			getch();
			break;
		}
		case 3:
		{ system( "cls" );
		  display( &slt );
		  getch();
		  break; }
		case 4:
		{ system( "cls" );
		  read( &slt );
		  getch();
		  break; }
		}
	}
}
