#include <stdio.h>

struct Process
{
    char name[20];
    int BT;
    int CT;
    int TAT;
    int WT;
};

int main()
{
    int ns, nu;

    printf("Enter number of System Processes: ");
    scanf("%d", &ns);

    struct Process system[ns];

    printf("\nEnter System Process Details\n");

    for(int i = 0; i < ns; i++)
    {
        printf("\nProcess Name: ");
        scanf("%s", system[i].name);

        printf("Burst Time: ");
        scanf("%d", &system[i].BT);
    }

    printf("\nEnter number of User Processes: ");
    scanf("%d", &nu);

    struct Process user[nu];

    printf("\nEnter User Process Details\n");

    for(int i = 0; i < nu; i++)
    {
        printf("\nProcess Name: ");
        scanf("%s", user[i].name);

        printf("Burst Time: ");
        scanf("%d", &user[i].BT);
    }

    int time = 0;
    float avgWT = 0, avgTAT = 0;

    /* System Queue (Higher Priority) */
    for(int i = 0; i < ns; i++)
    {
        system[i].WT = time;
        time += system[i].BT;
        system[i].CT = time;
        system[i].TAT = system[i].CT;

        avgWT += system[i].WT;
        avgTAT += system[i].TAT;
    }

    /* User Queue (Lower Priority) */
    for(int i = 0; i < nu; i++)
    {
        user[i].WT = time;
        time += user[i].BT;
        user[i].CT = time;
        user[i].TAT = user[i].CT;

        avgWT += user[i].WT;
        avgTAT += user[i].TAT;
    }

    printf("\n\nSYSTEM PROCESS QUEUE (FCFS)\n");
    printf("-------------------------------------------------\n");
    printf("Process\tBT\tCT\tTAT\tWT\n");

    for(int i = 0; i < ns; i++)
    {
        printf("%s\t%d\t%d\t%d\t%d\n",
               system[i].name,
               system[i].BT,
               system[i].CT,
               system[i].TAT,
               system[i].WT);
    }

    printf("\nUSER PROCESS QUEUE (FCFS)\n");
    printf("-------------------------------------------------\n");
    printf("Process\tBT\tCT\tTAT\tWT\n");

    for(int i = 0; i < nu; i++)
    {
        printf("%s\t%d\t%d\t%d\t%d\n",
               user[i].name,
               user[i].BT,
               user[i].CT,
               user[i].TAT,
               user[i].WT);
    }

    int total = ns + nu;

    printf("\nAverage Waiting Time = %.2f", avgWT / total);
    printf("\nAverage Turnaround Time = %.2f\n", avgTAT / total);

    return 0;
}