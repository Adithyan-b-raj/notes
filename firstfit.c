#include<stdio.h>
struct process{
        int size;
        int allocated;
};
void main()
{
        int nb,np,i;
        printf("enter the no of memory locations:");
        scanf("%d",&nb);
        int block[nb];
        printf("enter the size of memory location:");
        for(i=0;i<nb;i++)
        {
                scanf("%d",&block[i]);
        }
        printf("enter the no of process:");
        scanf("%d",&np);
        struct process pro[np];
        printf("enter the size of each process:");
        for(i=0;i<np;i++)
        {
                scanf("%d",&pro[i].size);
                pro[i].allocated=-1;
        }
        for(int i=0;i<np;i++){
                for(int j=0;j<nb;j++){
                        if(block[j]>=pro[i].size){
                        pro[i].allocated=block[j];
                        block[j]=block[j]-pro[i].size;
                        break;
                        }
                }
        }
        printf("\nsl.no\tprocess\tallocated");
        for(int i=0;i<np;i++)
        {
                if(pro[i].allocated!=-1)
                {
                        printf("\n%d\t%d\t%d",i+1,pro[i].size,pro[i].allocated);
                }
                else
                        printf("\n%d\t%d\tnot allocated",i+1,pro[i].size);
                printf("\n");
        }
} 
