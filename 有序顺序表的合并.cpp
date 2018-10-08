#include <stdio.h>
#include <math.h>
#include <string.h>
#include <malloc.h>
#include <stdlib.h>
#include <conio.h>
# define SIZE 100

typedef struct{
    int *elem;
    int length;
    int listsize;
} SqList;

//初始化
int InitList_Sq(SqList *L){
    L-> elem  = (int *)malloc(SIZE * sizeof(int)) ;
    if(!L->elem) exit(-1);
    L->length = 0;
    L->listsize = SIZE;

    return 1;
}

//创建
void Create_sq(SqList *L){
    int i,n;
    printf("输入有序表里的元素个数：");
    scanf("%d",&n);
    L->length = n;
    for(i=0;i < n;i++){
        printf("输入第%d个元素的值：",i+1);
        scanf("%d",&L->elem[i]);
        printf("\n");
    }
}

//打印
void Disp(SqList L){
    int i,n;
    n = L.length;
    for(i=0;i<n;i++){
        printf("%5d",L.elem[i]);

    }
    printf("\n");
}

//合并 
void Combine(SqList *la,SqList lb){
    int i = la->length - 1,j = lb.length - 1;       

    while(i >= 0 && j >= 0){
        if(la->elem[i] <= lb.elem[j]){

            if (!la->elem[i + 1])
            {               
                la->elem[i + 1] = lb.elem[j];

            }else{
                for (int k = la->length - 1; k >= i+1; --k)
                {
                    la->elem[k +1] = la->elem[k];
                }
                la->elem[i + 1] = lb.elem[j];
            }
            la->length++;
            j--;                

        }else{
            i--;
        }
    }
}

 main(){
    SqList sla;
    SqList slb;
    InitList_Sq(&sla);
    InitList_Sq(&slb);

    Create_sq(&sla);
    Create_sq(&slb);
printf("合并后为:\n\n");
    Combine(&sla,slb);
    Disp(sla);
}


