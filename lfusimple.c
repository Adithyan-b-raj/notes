#include <stdio.h>

int main() {
    int pages[20], frames[20], freq[20], last_used[20];
    int i, j, n, framescount, pagefault = 0;
    printf("Enter the number of pages: ");
    scanf("%d", &n);
    printf("Enter the reference string: ");
    for (i = 0; i < n; i++) {
        scanf("%d", &pages[i]);
    }
    printf("Enter the number of frames: ");
    scanf("%d", &framescount);
    for (i = 0; i < framescount; i++) {
        frames[i] = -1;  
        freq[i] = 0;  
        last_used[i] = -1; 
    }

    printf("\nPages\tFrames\t\tFault\n");

    for (i = 0; i < n; i++) {
        int page = pages[i];
        int found = 0;

        for (j = 0; j < framescount; j++) {
            if (frames[j] == page) {
                found = 1;
                freq[j]++; 
                last_used[j] = i;
                break;
            }
        }

        printf("%d", page);

        if (!found) {
            pagefault++;
            int replace_index = 0;
            int min_freq = freq[0];
            int lru_time = last_used[0];

            for (j = 0; j < framescount; j++) {
                if (frames[j] == -1) {
                    replace_index = j;
                    break;
                }
                if (freq[j] < min_freq || (freq[j] == min_freq && last_used[j] < lru_time)) {
                    min_freq = freq[j];
                    lru_time = last_used[j];
                    replace_index = j;
                }
            }

          
            frames[replace_index] = page;
            freq[replace_index] = 1; 
            last_used[replace_index] = i;

            for (j = 0; j < framescount; j++) {
                printf("\t%d", frames[j] == -1 ? -1 : frames[j]);
            }
            printf("\tPage Fault\n");
        } else {
      
            for (j = 0; j < framescount; j++) {
                printf("\t%d", frames[j] == -1 ? -1 : frames[j]);
            }
            printf("\tPage Hit\n");
        }
    }

    printf("Total Page Faults: %d\n", pagefault);
    printf("Total Page Hits: %d\n", n - pagefault);

    return 0;
}
