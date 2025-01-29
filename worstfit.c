#include<stdio.h>
struct process{
        int size;
        int allocated;
};
void main()
{
        int nb,np,i,best;
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
                best=-1;
                for(int j=0;j<nb;j++){
                        if(pro[i].size<=block[j]){
                                if(best==-1){
                                        best=j;
                                }
                                else if(block[j]>block[best]){
                                        best=j;
                                }
                        }
                }
                if(best!=-1)
                {
                        pro[i].allocated=block[best];
                        block[best]=block[best]-pro[i].size;
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
