#include <stdio.h>

typedef struct {
    int id;
    int execution;
    int period;
    int remaining;
    int next_release;
} Task;

int main() {
    int n = 3;
    Task tasks[3] = {
        {1, 1, 4, 0, 0},
        {2, 2, 5, 0, 0},
        {3, 3, 20, 0, 0}
    };

    int time, hyperperiod = 20;

    printf("Time\tRunning Task\n");

    for (time = 0; time < hyperperiod; time++) {

        for (int i = 0; i < n; i++) {
            if (time == tasks[i].next_release) {
                tasks[i].remaining = tasks[i].execution;
                tasks[i].next_release += tasks[i].period;
            }
        }

        int highest = -1;
        for (int i = 0; i < n; i++) {
            if (tasks[i].remaining > 0) {
                if (highest == -1 || tasks[i].period < tasks[highest].period) {
                    highest = i;
                }
            }
        }

        if (highest != -1) {
            printf("%d\tT%d\n", time, tasks[highest].id);
            tasks[highest].remaining--;
        } else {
            printf("%d\tIdle\n", time);
        }
    }

    return 0;
}
