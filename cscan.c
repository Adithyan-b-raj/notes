#include<stdio.h>
#include<stdlib.h>
int main(){
        int RQ[100],i,n,TotalHeadMoment=0,initial,size,move,j;
        printf("enter the no of requests:\n");
        scanf("%d",&n);
        printf("enter the requests sequence:");
        for(i=0;i<n;i++)
        {
                scanf("%d",&RQ[i]);
        }
        printf("enter initial head position:");
        scanf("%d",&initial);
        printf("enter total disk size\n");
        scanf("%d",&size);
        printf("enter the head direction for high 1 and for low 0\n");
        scanf("%d",&move);
        for(i=0;i<n;i++){
                for(j=0;j<n-i-1;j++){
                        if(RQ[j]>RQ[j+1]){
                                int temp;
                                temp=RQ[j];
                                RQ[j]=RQ[j+1];
                                RQ[j+1]=temp;
                        }
                }
        }
        int index;
        for(i=0;i<n;i++){
                if(initial<RQ[i]){
                        index=i;
                        break;
                }
        }
        if(move==1)
        {
                for(i=index;i<n;i++)
                {
                        TotalHeadMoment+=abs(RQ[i]-initial);
                        initial=RQ[i];
                }
                TotalHeadMoment+=abs(size-RQ[i-1]-1);
                TotalHeadMoment+=abs(size-1-0);
                initial=0;
                for(i=0;i<index;i++)
                {
                        TotalHeadMoment+=abs(RQ[i]-initial);
                        initial=RQ[i];
                }
        }
        else
        {       
                for(i=index-1;i>=0;i--)
                {
                        TotalHeadMoment+=abs(RQ[i]-initial);
                        initial=RQ[i];
                }
                TotalHeadMoment+=abs(RQ[i+1]-0);
                TotalHeadMoment+=abs(size-1-0);
                initial=size-1;
                for(i=n-1;i>=index;i--)
                {
                        TotalHeadMoment+=abs(RQ[i]-initial);
                        initial=RQ[i];
                }
        }
        printf("total head movement is %d",TotalHeadMoment);
        return 0;

}

