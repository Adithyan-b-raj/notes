#include<stdio.h>
#include<stdlib.h>
int mutex=1;
int buffer,p=0,x=0;
void producer()
{
        --mutex;
        p++;
        x++;
        printf("\n producer produces item %d",x);
        ++mutex;
}
void consumer()
{
        --mutex;
        p--;
        printf("\n consumer consumes item %d",x);
        x--;
        ++mutex;
}
int main()
{
        int n;
        printf("enter the buffer size:");
        scanf("%d",&buffer);
        printf("\n1.press 1 for producer"
                "\n2.press 2 fro consumer"
                "\n3.press 3 for exit");
        while(1){
                printf("\n Enter the choice:");
                scanf("%d",&n);
                switch(n){
                case 1:
                        if((mutex==1)&&(p<buffer)){
                                producer();
                        }
                        else{
                                printf("buffer is full!");
                        }
                        break;
                case 2:
                        if((mutex==1)&&(p>0)){
                                consumer();
                        }else{
                                printf("buffer is empty");
                        }
                        break;
                case 3:
                        exit(0);
                default:
                        printf("invalid choice! please enter 1,2 or 3");
                }
        }
}

