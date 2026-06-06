#include <stdio.h>

void FIFO(int pages[], int n, int frames) {
    int frame[20], i, j, k, pos = 0, faults = 0, found;

    for (i = 0; i < frames; i++)
        frame[i] = -1;

    printf("\nFIFO Page Replacement:\n");

    for (i = 0; i < n; i++) {
        found = 0;

        for (j = 0; j < frames; j++) {
            if (frame[j] == pages[i]) {
                found = 1;
                break;
            }
        }

        if (!found) {
            frame[pos] = pages[i];
            pos = (pos + 1) % frames;
            faults++;
        }

        printf("Page %d -> ", pages[i]);
        for (k = 0; k < frames; k++)
            printf("%d ", frame[k]);
        printf("\n");
    }

    printf("Total Page Faults = %d\n", faults);
}

void LRU(int pages[], int n, int frames) {
    int frame[20], time[20];
    int i, j, k, faults = 0, found, min, pos, counter = 0;

    for (i = 0; i < frames; i++) {
        frame[i] = -1;
        time[i] = 0;
    }

    printf("\nLRU Page Replacement:\n");

    for (i = 0; i < n; i++) {
        found = 0;

        for (j = 0; j < frames; j++) {
            if (frame[j] == pages[i]) {
                counter++;
                time[j] = counter;
                found = 1;
                break;
            }
        }

        if (!found) {
            min = time[0];
            pos = 0;

            for (j = 0; j < frames; j++) {
                if (frame[j] == -1) {
                    pos = j;
                    break;
                }

                if (time[j] < min) {
                    min = time[j];
                    pos = j;
                }
            }

            counter++;
            frame[pos] = pages[i];
            time[pos] = counter;
            faults++;
        }

        printf("Page %d -> ", pages[i]);
        for (k = 0; k < frames; k++)
            printf("%d ", frame[k]);
        printf("\n");
    }

    printf("Total Page Faults = %d\n", faults);
}

void Optimal(int pages[], int n, int frames) {
    int frame[20];
    int i, j, k, faults = 0, found;
    int farthest, pos, index;

    for (i = 0; i < frames; i++)
        frame[i] = -1;

    printf("\nOptimal Page Replacement:\n");

    for (i = 0; i < n; i++) {
        found = 0;

        for (j = 0; j < frames; j++) {
            if (frame[j] == pages[i]) {
                found = 1;
                break;
            }
        }

        if (!found) {
            for (j = 0; j < frames; j++) {
                if (frame[j] == -1) {
                    frame[j] = pages[i];
                    faults++;
                    found = 1;
                    break;
                }
            }

            if (!found) {
                farthest = i;
                pos = -1;

                for (j = 0; j < frames; j++) {
                    index = -1;

                    for (k = i + 1; k < n; k++) {
                        if (frame[j] == pages[k]) {
                            index = k;
                            break;
                        }
                    }

                    if (index == -1) {
                        pos = j;
                        break;
                    }

                    if (index > farthest) {
                        farthest = index;
                        pos = j;
                    }
                }

                frame[pos] = pages[i];
                faults++;
            }
        }

        printf("Page %d -> ", pages[i]);
        for (k = 0; k < frames; k++)
            printf("%d ", frame[k]);
        printf("\n");
    }

    printf("Total Page Faults = %d\n", faults);
}

int main() {
    int n, frames, i;
    int pages[50];

    printf("Enter number of pages: ");
    scanf("%d", &n);

    printf("Enter page reference string: ");
    for (i = 0; i < n; i++)
        scanf("%d", &pages[i]);

    printf("Enter number of frames: ");
    scanf("%d", &frames);

    FIFO(pages, n, frames);
    LRU(pages, n, frames);
    Optimal(pages, n, frames);

    return 0;
}
