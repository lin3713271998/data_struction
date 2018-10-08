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

//��ʼ��
int InitList_Sq(SqList *L){
    L-> elem  = (int *)malloc(SIZE * sizeof(int)) ;
    if(!L->elem) exit(-1);
    L->length = 0;
    L->listsize = SIZE;

    return 1;
}

//����
void Create_sq(SqList *L){
    int i,n;
    printf("������������Ԫ�ظ�����");
    scanf("%d",&n);
    L->length = n;
    for(i=0;i < n;i++){
        printf("�����%d��Ԫ�ص�ֵ��",i+1);
        scanf("%d",&L->elem[i]);
        printf("\n");
    }
}

//��ӡ
void Disp(SqList L){
    int i,n;
    n = L.length;
    for(i=0;i<n;i++){
        printf("%5d",L.elem[i]);

    }
    printf("\n");
}

//�ϲ� 
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
printf("�ϲ���Ϊ:\n\n");
    Combine(&sla,slb);
    Disp(sla);
}


