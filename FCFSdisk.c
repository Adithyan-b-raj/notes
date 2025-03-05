#include<stdio.h>
#include<stdlib.h>
int main(){
        int RQ[100],i,n,TotalHeadMoment=0,initial;
        printf("enter the no of requests:\n");
        scanf("%d",&n);
        printf("enter the requests sequence:");
        for(i=0;i<n;i++)
        {
                scanf("%d",&RQ[i]);
        }
        printf("enter initial head position:");
        scanf("%d",&initial);
        for(i=0;i<n;i++)
        {       
                TotalHeadMoment+=abs(RQ[i]-initial);
                initial=RQ[i];
        }
        printf("Total head Moment is %d", TotalHeadMoment);
        return 0;
}
