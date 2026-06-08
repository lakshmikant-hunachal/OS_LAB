#include<stdio.h>

struct process{
    char name[20];
    int AT;
    int BT;
    int CT;
    int TAT;
    int WT;
    int RT;
    int completed;
};
int main()
{
    int n,time=0,completed=0;
    float avgTAT=0,avgWT=0;

    printf("Enter number of processes: ");
    scanf("%d",&n);

    struct process p[n];

    printf("\nEnter process details\n");

    for(int i=0;i<n;i++)
    {
        printf("\nEnter process %d name: ",i+1);
        scanf("%s",p[i].name);

        printf("Enter Arrival Time: ");
        scanf("%d",&p[i].AT);

        printf("Enter Burst Time: ");
        scanf("%d",&p[i].BT);

        p[i].completed=0;
    }

    while(completed<n)
    {
        int idx=-1;
        int minBT=9999;

        for(int i=0;i<n;i++)
        {
            if(p[i].AT<=time && p[i].completed==0)
            {
                if(p[i].BT < minBT)
                {
                    minBT=p[i].BT;
                    idx=i;
                }
            }
        }

        if(idx!=-1)
        {
            time += p[idx].BT;
            p[idx].CT=time;
            p[idx].TAT=p[idx].CT-p[idx].AT;
            p[idx].WT=p[idx].TAT-p[idx].BT;
            p[idx].RT=p[idx].WT;

            avgTAT+=p[idx].TAT;
            avgWT+=p[idx].WT;

            p[idx].completed=1;
            completed++;
        }
        else
        {
            time++;
        }
    }

    printf("\n\nProcess\tAT\tBT\tCT\tTAT\tWT\tRT\n");

    for(int i=0;i<n;i++)
    {
        printf("%s\t%d\t%d\t%d\t%d\t%d\t%d\n",
        p[i].name,p[i].AT,p[i].BT,p[i].CT,p[i].TAT,p[i].WT,p[i].RT);
    }

    printf("\nAverage Turnaround Time = %.2f",avgTAT/n);
    printf("\nAverage Waiting Time = %.2f\n",avgWT/n);

    return 0;
}
