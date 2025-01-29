#include<stdio.h>
int main()
{
        int a[20],b[20],frame,h,p=0,q=0,m=0,n,k,i,q1=1,currentpages=0;
        char f='F';
        printf("enter th eno of pages:");
        scanf("%d",&n);
        printf("enter the no of frames:");
        scanf("%d",&frame);
        printf("enter %d page numbers:",n);
        for(i=0;i<n;i++)
                scanf("%d",&b[i]);
        for(i=0;i<frame;i++)
                a[i]=-1;
        for(i=0;i<n;i++)
        {
                if(p==0)
                {
                        if(q>=frame)
                                q=0;
                        a[q]=b[i];
                        q++;
                        if(q1<frame)
                                q1=q;
                }
                printf("\n%d",b[i]);
                printf("\t");
                for(h=0;h<frame;h++)
                {
                        printf("%d\t",a[h]);
                }
                if(p==0 && q<=frame)
                {
                        printf("-->%c",f);
                        m++;
                }
                p=0;
                for(k=0;k<q1;k++)
                {
                        if(b[i+1]==a[k])
                                p=1;
                }
        }
        printf("\n No of faults:%d",m);
}
