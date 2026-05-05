#include<stdio.h>
#include<stdlib.h>

struct process{
    char name[20];
    int AT;
    int BT;
    int CT;
    int TAT;
    int WT;
};

int main()
{
    int n;
    printf("Enter number of processes: ");
    scanf("%d",&n);

    struct process list[n];
    for(int i=0;i<n;i++)
    {
        printf("\nEnter process %d name: ",i+1);
        scanf("%s",list[i].name);

        printf("Enter arrival time of %s: ",list[i].name);
        scanf("%d",&list[i].AT);

        printf("Enter burst time of %s: ",list[i].name);
        scanf("%d",&list[i].BT);
    }

    for(int i = 0; i < n - 1; i++)
    {
        for(int j = 0; j < n - i - 1; j++)
        {
            if(list[j].AT > list[j + 1].AT)
            {
                struct process temp = list[j];
                list[j] = list[j + 1];
                list[j + 1] = temp;
            }
        }
    }

    for(int i=0;i<n;i++)
    {
        if(i == 0)
        {
            list[i].CT = list[i].AT + list[i].BT;
        }
        else
        {
            if(list[i-1].CT > list[i].AT)
                list[i].CT = list[i-1].CT + list[i].BT;
            else
                list[i].CT = list[i].AT + list[i].BT;
        }

        list[i].TAT = list[i].CT - list[i].AT;
        list[i].WT = list[i].TAT - list[i].BT;
    }

    printf("\n\nProcess Details (Sorted by Arrival Time):\n");

    for(int i=0;i<n;i++)
    {
        printf("\n%s process details\n",list[i].name);
        printf("Arrival Time: %d\n",list[i].AT);
        printf("Burst Time: %d\n",list[i].BT);
        printf("Completion Time: %d\n",list[i].CT);
        printf("Turnaround Time: %d\n",list[i].TAT);
        printf("Waiting Time: %d\n",list[i].WT);
    }

    return 0;
}


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

    printf("\n\nProcess\tAT\tBT\tCT\tTAT\tWT\n");

    for(int i=0;i<n;i++)
    {
        printf("%s\t%d\t%d\t%d\t%d\t%d\n",
        p[i].name,p[i].AT,p[i].BT,p[i].CT,p[i].TAT,p[i].WT);
    }

    printf("\nAverage Turnaround Time = %.2f",avgTAT/n);
    printf("\nAverage Waiting Time = %.2f\n",avgWT/n);

    return 0;
}*/
