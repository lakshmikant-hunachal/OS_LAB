#include <stdio.h>

struct Task
{
    char name[20];
    int execution;
    int period;
};

int main()
{
    int n;

    printf("Enter number of tasks: ");
    scanf("%d", &n);

    struct Task t[n];

    for(int i=0;i<n;i++)
    {
        printf("\nEnter Task %d Name: ",i+1);
        scanf("%s",t[i].name);

        printf("Execution Time: ");
        scanf("%d",&t[i].execution);

        printf("Period: ");
        scanf("%d",&t[i].period);
    }

    // Sort by Period (ascending)
    for(int i=0;i<n-1;i++)
    {
        for(int j=0;j<n-i-1;j++)
        {
            if(t[j].period > t[j+1].period)
            {
                struct Task temp=t[j];
                t[j]=t[j+1];
                t[j+1]=temp;
            }
        }
    }

    printf("\nRate Monotonic Priority Order:\n");

    for(int i=0;i<n;i++)
    {
        printf("%d. %s (Period=%d)\n",
        i+1,t[i].name,t[i].period);
    }

    return 0;
}