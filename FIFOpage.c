#include<stdio.h>
void main() { 
    int i, j, n, rs[50], frame[10], nf, k, avail, pagefault = 0, pagehit = 0;
    printf("\nEnter the number of pages:\n"); 
    scanf("%d", &n); 
    printf("\nEnter the reference string:\n"); 
    for(i = 0; i < n; i++) 
        scanf("%d", &rs[i]); 
    printf("\nEnter the number of frames: "); 
    scanf("%d", &nf); 
    for(i = 0; i < nf; i++) 
        frame[i] = -1; 
    j = 0; 
    printf("Ref string\tPage frames\t\tPage Fault/Page Hit\n"); 
    for(i = 0; i < n; i++) { 
        printf("%d\t\t", rs[i]);
        
            avail = 0;
        for(k = 0; k < nf; k++) 
            if(frame[k] == rs[i]) 
            { 
             avail = 1;
             for(k=0;k<nf;k++)
            printf("%d\t", frame[k]); 
            }
                 
        if(avail == 0) { 
            frame[j] = rs[i]; 
            j = (j + 1) % nf; 
            for(k=0;k<nf;k++)
            printf("%d\t", frame[k]); 
            pagefault++; 
            printf("Page Fault\n"); 
        } else { 
            pagehit++; 
            printf("Page Hit\n"); 
        }
    } 

    printf("\nTotal Page Faults: %d", pagefault); 
    printf("\nTotal Page Hits: %d", pagehit); 
}
