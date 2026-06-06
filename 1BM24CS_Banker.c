#include <stdio.h>

int main()
{
    int n, r, i, j, k;

    printf("Enter number of processes -- ");
    scanf("%d", &n);

    printf("Enter number of resources -- ");
    scanf("%d", &r);

    int alloc[n][r], max[n][r], need[n][r];
    int avail[r], finish[n], safeSeq[n];

    // Input Allocation and Max matrices
    for(i = 0; i < n; i++)
    {
        printf("\nEnter details for P%d\n", i);

        printf("Enter allocation -- ");
        for(j = 0; j < r; j++)
            scanf("%d", &alloc[i][j]);

        printf("Enter Max -- ");
        for(j = 0; j < r; j++)
            scanf("%d", &max[i][j]);
    }

    // Input Available resources
    printf("\nEnter Available Resources -- ");
    for(i = 0; i < r; i++)
        scanf("%d", &avail[i]);

    // Calculate Need matrix
    for(i = 0; i < n; i++)
    {
        for(j = 0; j < r; j++)
        {
            need[i][j] = max[i][j] - alloc[i][j];
        }
    }

    // Initialize finish array
    for(i = 0; i < n; i++)
        finish[i] = 0;

    int count = 0;

    // Banker's Algorithm
    while(count < n)
    {
        int found = 0;

        for(i = 0; i < n; i++)
        {
            if(finish[i] == 0)
            {
                int flag = 1;

                for(j = 0; j < r; j++)
                {
                    if(need[i][j] > avail[j])
                    {
                        flag = 0;
                        break;
                    }
                }

                if(flag)
                {
                    printf("P%d is visited(", i);

                    for(j = 0; j < r; j++)
                    {
                        avail[j] += alloc[i][j];
                        printf("%d", avail[j]);

                        if(j != r - 1)
                            printf(" ");
                    }

                    printf(")\n");

                    safeSeq[count++] = i;
                    finish[i] = 1;
                    found = 1;
                }
            }
        }

        if(!found)
        {
            printf("\nSYSTEM IS NOT IN SAFE STATE\n");
            return 0;
        }
    }

    printf("\nSYSTEM IS IN SAFE STATE\n");
    printf("The Safe Sequence is -- (");

    for(i = 0; i < n; i++)
    {
        printf("P%d", safeSeq[i]);

        if(i != n - 1)
            printf(" ");
    }

    printf(")\n\n");

    // Display Allocation, Max and Need matrices
    printf("Process\tAllocation\tMax\tNeed\n");

    for(i = 0; i < n; i++)
    {
        printf("P%d\t", i);

        for(j = 0; j < r; j++)
            printf("%d ", alloc[i][j]);

        printf("\t\t");

        for(j = 0; j < r; j++)
            printf("%d ", max[i][j]);

        printf("\t");

        for(j = 0; j < r; j++)
            printf("%d ", need[i][j]);

        printf("\n");
    }

    return 0;
}
