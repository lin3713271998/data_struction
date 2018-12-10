/*1707004540林志鹏*/
#include<stdio.h>
#include <malloc.h>
#include <stdlib.h>
#define M  20 
#define FIN 5000 

//图邻接矩阵 
typedef struct{
	char vexs[M];
	int edges[M][M];
	int n,e;//n:顶点数e:边数 
}Mgraph;

//prim算法 
typedef struct edgedata{
	int beg,en;//边顶点序号 
	int length;	
}edge; 
edge tree[M-1];	

//拓扑排序邻接表 
typedef struct node{
int adjvex;
struct node *next;		
}edgenode; 
typedef struct de{
edgenode *firstedge;
char vertex;
}vertexnode;
typedef struct{
 vertexnode adjlist[M];
 int n,e;	
}aovgraph;

//最短路径 
typedef int dist[M][M];
typedef int path[M][M];


//图的邻接矩阵建立
void creat(Mgraph *g,char *s,int c){//c表示图的类型，c=0表示无向图 
int i,j,k,w;
FILE *rf;
rf = fopen(s,"r");	//fopen函数使用方法：https://baike.baidu.com/item/fopen/10942321?fr=aladdin 
if(rf)
{
	fscanf(rf,"%d%d",&g->n,&g->e);
	for(i=0;i<g->n;i++)
	fscanf(rf,"%ls",&g->vexs[i]);
	
	for(i=0;i<g->n;i++)//初始化邻接矩阵 
	    for(j=0;j<g->n;j++)
	       if(i==j) {g->edges[i][j]=0;
		   }
		   else {g->edges[i][j]=FIN;
		   }
	   
	for(k=0;k<g->e;k++)//读入边 
	{   fscanf(rf,"%d%d%d",&i,&j,&w);
		g->edges[i][j]=w;
	
		if(c==0) g->edges[j][i]=w; }   	
    fclose(rf);	 }	
	else g->n=0; 
}
//图的邻接表创建
void creatgraph(aovgraph *g2, char *s3, int c){
    int i, j, k; //循环变量
    edgenode *s, *s2; //连接用节点
    FILE *fp;
    fp = fopen(s3,"r");
    fscanf(fp, "%d %d", &g2->n, &g2->e); // n顶点数, e边数

    //录入点信息
    for(i = 0;i < g2->n; i++){
        fscanf(fp, "%1s", &g2->adjlist[i].vertex); //%1s相当于%c//666 
        g2->adjlist[i].firstedge = NULL; //边表置为空
    }

    //录入边信息
    for(k=0; k<g2->e; k++){
        fscanf(fp, "%d %d", &i, &j);
        s = (edgenode *)malloc(sizeof(edgenode)); //分配节点链式空间
        s->adjvex = j;
        s->next = g2->adjlist[i].firstedge;
        g2->adjlist[i].firstedge = s;

        if(c == 0){ //因为是无向图 所以需要进行逆向连接
//             s = (edgenode *)malloc(sizeof(edgenode));   
//             s->adjvex = i; //刚好与上面的i j反过来
//             s->next = g->adjlist[j].firstedge;
//             g->adjlist[i].firstedge = s;      
            s2 = (edgenode*)malloc(sizeof(edgenode));
            s2->adjvex = i;
            s2->next = g2->adjlist[j].firstedge;
            g2->adjlist[j].firstedge = s2;
        }
    }		
} 

//Prim最小生成树 
void prim(Mgraph g,edge tree[M-1]){
 edge x;
 int d,min,j,k,s,v;
 for(v=1;v<=g.n-1;v++)
 {
 	tree[v-1].beg=0;
	tree[v-1].en=v;
	tree[v-1].length=g.edges[0][v]; 
	}	
 for(k=0;k<g.n-3;k++)
 {
 	min = tree[k].length;
	for(j=k+1;j<g.n-2;j++)
	  if(tree[j].length<min)
	   {
	   	min = tree[j].length;
	   	s=j;
		} 
 	v=tree[s].en;
 	for(j=k+1;j<g.n-2;j++)
 	{d=g.edges[v][tree[j].en];
 	 if(d<tree[j].length)
 	   {tree[j].length=d;
 	    tree[j].beg=v;
		}
	 }
}	
printf("\n%c--%c %d\n",g.vexs[tree[j].beg],g.vexs[tree[j].en],tree[j].length);
printf("the root of it is %c\n",g.vexs[0]);		
}



/* 邻接矩阵存储 - 多源最短路算法 */ 
int floyd(Mgraph g,dist d, path p ) 
{     int i, j, k;     /* 初始化 */ 
      
   for ( i=0; i<g.n; i++ )     
    for( j=0; j<g.n; j++ ) {      
	       d[i][j] = g.edges[i][j];          
		   p[i][j] = -1;         }    
	for( k=0; k<g.n; k++ )    
	for( i=0; i<g.n; i++ )     
	for( j=0; j<g.n; j++ )    
        if( d[i][k] + d[k][j] < d[i][j] ) {   
			d[i][j] = d[i][k] + d[k][j];    
			if ( i==j && d[i][j]<0 ) /* 若发现负值圈 */                       
			  return false; /* 不能正确解决，返回错误标记 */                 
			      p[i][j] = k;         }   
         return true; /* 算法执行完毕，返回正确标记 */ 
  }
 //最短路径输出函数
 void print(Mgraph g,dist d, path p ){
 	int i,j;
 	for(i=0;i<g.n;i++)
 	{for(j=0;j<g.n;j++)
 	 printf("%d--%d\n",p[i][j],d[i][j]);
	 }
 	
 	
 } 
 //拓扑排序输出函数
void print2(aovgraph g2, int TopOrder[],int cnt)
{
    int i;
	for(i=0;i<=cnt;i++)
	printf("%d ",TopOrder[i]);
 }	   

/* 邻接表存储 - 拓扑排序算法 */ 
int topsort( aovgraph g2,int TopOrder[]) 
{    
    int Indegree[M], cnt,i;   
    int V,front,rear;
	   
	edgenode *W;    
    int queue[M];	     //  Queue Q = CreateQueue( Graph->Nv ); 
    front=rear=0;     
	      
	   for (V=0; V<g2.n; V++)  /* 初始化Indegree[] */          
	   Indegree[V] = 0;             
	     
	   for (V=0; V<g2.n; V++)    /* 遍历图，得到Indegree[] */         
	   for (W=g2.adjlist[V].firstedge; W; W=W->next)             
	   Indegree[W->adjvex]++; /* 对有向边<V, W->AdjV>累计终点的入度 */                  
	    
	   for (V=0; V<g2.n; V++)         
	   if ( Indegree[V]==0 )     /* 将所有入度为0的顶点入列 */            
	   queue[rear ++]=V;                   
	   cnt = 0;      
	   while(front<rear){     //当队列不为空    
	  // V = DeleteQ(Q);
	  V=queue[front++]; 
	//  printf("%d",V);/* 弹出一个入度为0的顶点 */        
	   TopOrder[cnt++] = V; /* 将之存为结果序列的下一个元素 */         
	          
	
	    for (W=g2.adjlist[V].firstedge; W; W=W->next)            
	   if ( --Indegree[W->adjvex] == 0 )/* 若删除V使得W->AdjV入度为0 */                 
	   queue[rear++]=W->adjvex; // AddQ(Q, W->AdjV); /* 则该顶点入列 */     
	    } /* while结束*/   
		       
	   if ( cnt !=g2.n ) {
	   	printf("有回路ERROR!");
	   	return false; /* 说明图中有回路, 返回不成功标志 */   
	   }        
	   else   {
	   	       print2(g2,TopOrder,cnt);
				return true;
	   }      
	   
	   
}	   


/*主函数*/ 
int main(){
Mgraph g;
aovgraph g2;
int cnt;
int TopOrder[M];
char filename[30];
path p;
dist d;
 
printf("Please input you want to open the file name:\n");
gets(filename);

printf("创建图\n");
creat(&g,filename,0);
creatgraph(&g2,filename,0);
printf("最小生成树\n");
prim(g,tree);

printf("最短路径(-1代表原点，5000代表无穷大)\n");
floyd(g,p,d); 
print(g,p,d);

printf("拓扑排序\n");
topsort(g2,TopOrder);


return 0;		
}






