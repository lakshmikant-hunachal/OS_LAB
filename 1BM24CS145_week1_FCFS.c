#include <stdio.h>

struct process
{
    char name[20];
    int AT, BT;
    int CT, TAT, WT;
};

int main()
{
    int n;

    printf("Enter number of processes: ");
    scanf("%d", &n);

    struct process p[n];

    for(int i = 0; i < n; i++)
    {
        printf("\nEnter process %d name: ", i + 1);
        scanf("%s", p[i].name);

        printf("Enter Arrival Time: ");
        scanf("%d", &p[i].AT);

        printf("Enter Burst Time: ");
        scanf("%d", &p[i].BT);
    }

    // Sort by Arrival Time
    for(int i = 0; i < n - 1; i++)
    {
        for(int j = 0; j < n - i - 1; j++)
        {
            if(p[j].AT > p[j + 1].AT)
            {
                struct process temp = p[j];
                p[j] = p[j + 1];
                p[j + 1] = temp;
            }
        }
    }

    for(int i = 0; i < n; i++)
    {
        if(i == 0)
            p[i].CT = p[i].AT + p[i].BT;
        else
        {
            if(p[i].AT > p[i - 1].CT)
                p[i].CT = p[i].AT + p[i].BT;
            else
                p[i].CT = p[i - 1].CT + p[i].BT;
        }

        p[i].TAT = p[i].CT - p[i].AT;
        p[i].WT = p[i].TAT - p[i].BT;
    }

    float avgTAT = 0, avgWT = 0;

    printf("\nProcess\tAT\tBT\tCT\tTAT\tWT\n");

    for(int i = 0; i < n; i++)
    {
        printf("%s\t%d\t%d\t%d\t%d\t%d\n",
               p[i].name, p[i].AT, p[i].BT,
               p[i].CT, p[i].TAT, p[i].WT);

        avgTAT += p[i].TAT;
        avgWT += p[i].WT;
    }

    printf("\nAverage TAT = %.2f", avgTAT / n);
    printf("\nAverage WT = %.2f\n", avgWT / n);

    return 0;
}