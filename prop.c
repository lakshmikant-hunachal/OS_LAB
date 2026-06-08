#include <stdio.h>

struct Task
{
    char name[20];
    int weight;
};

int main()
{
    int n,totalWeight=0;
    float totalCPU;

    printf("Enter number of tasks: ");
    scanf("%d",&n);

    struct Task t[n];

    printf("Enter Total CPU Time: ");
    scanf("%f",&totalCPU);

    for(int i=0;i<n;i++)
    {
        printf("\nEnter Task %d Name: ",i+1);
        scanf("%s",t[i].name);

        printf("Weight: ");
        scanf("%d",&t[i].weight);

        totalWeight += t[i].weight;
    }

    printf("\nTask\tWeight\tAllocated CPU Time\n");

    for(int i=0;i<n;i++)
    {
        float cpuShare =
        ((float)t[i].weight/totalWeight)*totalCPU;

        printf("%s\t%d\t%.2f\n",
        t[i].name,
        t[i].weight,
        cpuShare);
    }

    return 0;
}