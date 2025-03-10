#include <stdio.h>
int main()
{
    int pages[20], frames[10], last_used[20];
    int n, frame_count, page_faults = 0;

    printf("Enter the number of pages: ");
    scanf("%d", &n);
    printf("Enter the page reference string: ");
    for (int i = 0; i < n; i++)
        scanf("%d", &pages[i]);

    printf("Enter the number of frames: ");
    scanf("%d", &frame_count);

    for (int i = 0; i < frame_count; i++)
        frames[i] = -1;

    printf("\nPage\tFrames\t\tFault\n");

    for (int i = 0; i < n; i++)
    {
        int page = pages[i], found = 0;
        for (int j = 0; j < frame_count; j++)
        {
            if (frames[j] == page)
            {
                last_used[j] = i;
                found = 1;
                break;
            }
        }

        printf("%d\t", page);

        if (!found)
        {
            page_faults++;
            int replace_index = 0, min_time = last_used[0];
            for (int j = 0; j < frame_count; j++)
            {
                if (frames[j] == -1)
                {
                    replace_index = j;
                    break;
                }
                if (last_used[j] < min_time)
                {
                    min_time = last_used[j];
                    replace_index = j;
                }
            }

            frames[replace_index] = page;
            last_used[replace_index] = i;
            
            for (int j = 0; j < frame_count; j++)
                printf("%d ", frames[j] == -1 ? -1 : frames[j]);
            printf("\tPage Fault\n");
        }
        else
        {
            for (int j = 0; j < frame_count; j++)
                printf("%d ", frames[j] == -1 ? -1 : frames[j]);

            printf("\tPage Hit\n");
        }
    }

    printf("\nTotal page faults: %d\n", page_faults);
    printf("Total pages hit: %d\n", n - page_faults);

    return 0;
}
