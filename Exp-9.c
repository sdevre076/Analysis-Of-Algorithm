#include <stdio.h>
#include <stdlib.h>

#define MAX 20

typedef struct {
    int id;
    int deadline;
    int profit;
} Job;

// Compare function for qsort (descending by profit)
int compare(const void *a, const void *b) {
    Job *j1 = (Job *)a;
    Job *j2 = (Job *)b;
    return j2->profit - j1->profit;  // descending
}

int main() {
    int n;
    Job jobs[MAX];
    int slots[MAX];
    int maxDeadline = 0, totalProfit = 0;

    printf("Enter number of jobs (max %d): ", MAX);
    scanf("%d", &n);

    // Input jobs
    for (int i = 0; i < n; i++) {
        printf("Enter job id, deadline, profit for job %d: ", i + 1);
        scanf("%d %d %d", &jobs[i].id, &jobs[i].deadline, &jobs[i].profit);

        if (jobs[i].deadline > maxDeadline)
            maxDeadline = jobs[i].deadline;
    }

    // Sort jobs by profit using qsort
    qsort(jobs, n, sizeof(Job), compare);

    // Initialize slots as empty (-1)
    for (int i = 0; i <= maxDeadline; i++) {
        slots[i] = -1;
    }

    // Job sequencing (Greedy)
    for (int i = 0; i < n; i++) {
        for (int j = jobs[i].deadline; j > 0; j--) {
            if (slots[j] == -1) {
                slots[j] = i;  // store index of job placed
                totalProfit += jobs[i].profit;
                break;
            }
        }
    }

    // Output result
    printf("\nScheduled Jobs:\n");
    for (int i = 1; i <= maxDeadline; i++) {
        if (slots[i] != -1)
            printf("Slot %d -> Job %d (Profit %d)\n",
                   i, jobs[slots[i]].id, jobs[slots[i]].profit);
        else
            printf("Slot %d -> (empty)\n", i);
    }

    printf("\nTotal Profit = %d\n", totalProfit);

    return 0;
}
