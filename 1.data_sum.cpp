#define MAX 100
typedef struct{
				int a[MAX];
				int size;
              }list_a,list_b,list_c; 
/*先把c表初始化，把c置空*/
/*合并*/
int sum(list_a *slt1,list_b *slt2,list_c *slt3) 
{int i,j,t=1;
for(i=1;i<=slt1->size;i++)
{for(j=1;j<=slt2->size;j++)
{
	if(slt1->a[i]>slt2->a[j])
	{slt3->a[t]=slt2->a[j];
	t++;
	}
	else if(slt1->a[i]=slt2->a[j])
	{slt3->a[t]=slt2->a[j];
	slt3->a[t+1]=slt2->a[j];
	t++;
	}
	else
	{slt3->a[t]=slt1->a[i];
	t++;
	}	
}	
}
	
	return *slt3;	
}

