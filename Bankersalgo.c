#include <stdio.h>

void main(){
    int numProcess,numRes,i,j;
    printf("Enter the number of processes and the number of resources\n");
    scanf("%d%d",&numProcess,&numRes);
    int allocation[10][10],max[10][10],need[10][10],work[10];
    
    printf("Enter the allocation matrix\n");
    for(i=0;i<numProcess;i++){
        for(j=0;j<numRes;j++){
            scanf("%d",&allocation[i][j]);
        }
    }
    
    printf("Enter the max matrix\n");
    for(i=0;i<numProcess;i++){
        for(j=0;j<numRes;j++){
            scanf("%d",&max[i][j]);
        }
    }
    
    int availiable[10];
    printf("Enter the availiable resources\n");
    for(i=0;i<numRes;i++){
        scanf("%d",&availiable[i]);
        work[i] = availiable[i];
    }
    
    for(i=0;i<numProcess;i++){
        for(j=0;j<numRes;j++){
            need[i][j] = max[i][j] - allocation[i][j];
        }
    }
    
    printf("The need matrix is : \n");
    for(i=0;i<numProcess;i++){
        for(j=0;j<numRes;j++){
            printf("%d ",need[i][j]);
        }
        printf("\n");
    }
    
    int flag;
    int finished[10];
    int k = 0;
    int safesequence[10];
    int l;
    for(i=0;i<numProcess;i++){
        finished[i] = 0;
    }
    
    for(l=0;l<numProcess;l++){
        for(i=0;i<numProcess;i++){
            flag = 0;
            if(finished[i] == 0){
                for(j=0;j<numRes;j++){
                    if(need[i][j] > work[j]){
                        flag = 1;
                        break;
                    }
                }
                if(flag == 0){
                    for(j=0;j<numRes;j++){
                        work[j] += allocation[i][j];
                    }
                    safesequence[k] = i;
                    k++;
                    finished[i] = 1;
                }
            }
        }
    }
    flag = 1;
    for(i=0;i<numProcess;i++){
        if(finished[i] == 0){
            flag = 0;
            break;
        }
    }
    if(flag == 1){
        printf("The safesequence is : <");
        for(i=0;i<k;i++){
            printf("P%d,",safesequence[i]);
        }
        printf(">\n");
    }
}

















