#include <stdio.h>

struct Task
{
    char name[20];
    int execution;
    int deadline;
};

int main()
{
    int n;

    printf("Enter number of tasks: ");
    scanf("%d",&n);

    struct Task t[n];

    for(int i=0;i<n;i++)
    {
        printf("\nEnter Task %d Name: ",i+1);
        scanf("%s",t[i].name);

        printf("Execution Time: ");
        scanf("%d",&t[i].execution);

        printf("Deadline: ");
        scanf("%d",&t[i].deadline);
    }

    // Sort by Deadline
    for(int i=0;i<n-1;i++)
    {
        for(int j=0;j<n-i-1;j++)
        {
            if(t[j].deadline > t[j+1].deadline)
            {
                struct Task temp=t[j];
                t[j]=t[j+1];
                t[j+1]=temp;
            }
        }
    }

    printf("\nEDF Scheduling Order:\n");

    for(int i=0;i<n;i++)
    {
        printf("%d. %s (Deadline=%d)\n",
        i+1,t[i].name,t[i].deadline);
    }

    return 0;
}