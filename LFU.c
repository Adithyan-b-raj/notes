=#include <stdio.h>
#define MAX_FRAMES 10
#define MAX_PAGES 100

struct Frame
{
    int page, freq;
};

int main()
{
        int pages[MAX_PAGES], n, frame_count;
        printf("Enter the number of pages: ");
        scanf("%d", &n);
        printf("Enter the page reference string: ");
        for (int i = 0; i < n; i++)
        {
                scanf("%d", &pages[i]);
        }
        printf("Enter the number of frames: ");
        scanf("%d", &frame_count);
        struct Frame frames[MAX_FRAMES];
        int page_faults = 0;
        for (int i = 0; i < frame_count; i++)
        {
                frames[i].page = -1;
                frames[i].freq = 0;
        }
        printf("Step\tPage\tFrames\tFault\n");
        for (int i = 0; i < n; i++)
        {
                int page = pages[i], found = 0;
                printf("%d\t%d\t", i + 1, page);
                for (int j = 0; j < frame_count; j++)
                {
                        if (frames[j].page == page)
                        {
                                frames[j].freq++;
                                found = 1;
                                break;
                        }
                }
                if (!found)
                {
                        page_faults++;
                        int replace_index = -1;
                        for (int j = 0; j < frame_count; j++)
                        {
                                if (frames[j].page == -1)
                                {
                                        replace_index = j;
                                        break;
                                }
                        }

                        if (replace_index == -1)
                        {
                                int min_freq = frames[0].freq, min_index = 0;
                                for (int j = 1; j < frame_count; j++)
                                {
                                        if (frames[j].freq < min_freq)
                                        {
                                                min_freq = frames[j].freq;
                                                min_index = j;
                                        }
                                }
                                replace_index = min_index;
                        }

                        frames[replace_index].page = page;
                        frames[replace_index].freq = 1;
                }
                for (int j = 0; j < frame_count; j++)
                {
                        if (frames[j].page == -1)
                                printf("- ");
                        else
                                printf("%d ", frames[j].page);
                }

                if (found)
                        printf("\tPages Hit\n");
                else
                        printf("\tPages Fault\n");
        }
    printf("\nTotal page faults: %d\n", page_faults);
    printf("Total pages hit%d\n",n-page_faults);

    return 0;
}

