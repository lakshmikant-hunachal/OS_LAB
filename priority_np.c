#include <stdio.h>

struct Process {
    int pid, at, bt, pri, ct, tat, wt, completed;
};

int main() {
    int n, i, completed = 0, time = 0;
    float avgWT = 0, avgTAT = 0;

    printf("Enter number of processes: ");
    scanf("%d", &n);

    struct Process p[n];

    for(i = 0; i < n; i++) {
        p[i].pid = i + 1;

        printf("\nProcess P%d\n", i + 1);

        printf("Arrival Time: ");
        scanf("%d", &p[i].at);

        printf("Burst Time: ");
        scanf("%d", &p[i].bt);

        printf("Priority (Lower number = Higher priority): ");
        scanf("%d", &p[i].pri);

        p[i].completed = 0;
    }

    while(completed < n) {
        int idx = -1;
        int highest = 9999;

        for(i = 0; i < n; i++) {
            if(p[i].at <= time && !p[i].completed) {
                if(p[i].pri < highest) {
                    highest = p[i].pri;
                    idx = i;
                }
            }
        }

        if(idx == -1) {
            time++;
            continue;
        }

        time += p[idx].bt;

        p[idx].ct = time;
        p[idx].tat = p[idx].ct - p[idx].at;
        p[idx].wt = p[idx].tat - p[idx].bt;

        p[idx].completed = 1;
        completed++;
    }

    printf("\nPID\tAT\tBT\tPRI\tCT\tTAT\tWT\n");

    for(i = 0; i < n; i++) {
        printf("P%d\t%d\t%d\t%d\t%d\t%d\t%d\n",
               p[i].pid, p[i].at, p[i].bt, p[i].pri,
               p[i].ct, p[i].tat, p[i].wt);

        avgWT += p[i].wt;
        avgTAT += p[i].tat;
    }

    printf("\nAverage Waiting Time = %.2f", avgWT / n);
    printf("\nAverage Turnaround Time = %.2f\n", avgTAT / n);

    return 0;
}