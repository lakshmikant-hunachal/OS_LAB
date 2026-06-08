#include <stdio.h>

int main() {
    int n, tq, i;
    
    printf("Enter number of processes: ");
    scanf("%d", &n);

    int bt[n], rt[n];
    int wt[n], tat[n];
    
    for(i = 0; i < n; i++) {
        printf("Enter Burst Time of P%d: ", i + 1);
        scanf("%d", &bt[i]);
        rt[i] = bt[i];
    }

    printf("Enter Time Quantum: ");
    scanf("%d", &tq);

    int time = 0;
    int done;

    do {
        done = 1;

        for(i = 0; i < n; i++) {
            if(rt[i] > 0) {
                done = 0;

                if(rt[i] > tq) {
                    time += tq;
                    rt[i] -= tq;
                } else {
                    time += rt[i];
                    wt[i] = time - bt[i];
                    rt[i] = 0;
                }
            }
        }
    } while(!done);

    printf("\nProcess\tBurst Time\tWaiting Time\tTurnaround Time\n");

    float totalWT = 0, totalTAT = 0;

    for(i = 0; i < n; i++) {
        tat[i] = bt[i] + wt[i];

        totalWT += wt[i];
        totalTAT += tat[i];

        printf("P%d\t%d\t\t%d\t\t%d\n",
               i + 1, bt[i], wt[i], tat[i]);
    }

    printf("\nAverage Waiting Time = %.2f", totalWT / n);
    printf("\nAverage Turnaround Time = %.2f\n", totalTAT / n);

    return 0;
}