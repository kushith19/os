#include <stdio.h>

#define MAX_PROCESSES 20
#define MAX_RESOURCES 10

int main() {
    int alloc[MAX_PROCESSES][MAX_RESOURCES], max[MAX_PROCESSES][MAX_RESOURCES];
    int need[MAX_PROCESSES][MAX_RESOURCES], avail[MAX_RESOURCES];
    int finish[MAX_PROCESSES] = {0}, safeSeq[MAX_PROCESSES];
    int np, nr;

    // Input: number of processes and resources
    printf("Enter number of processes: ");
    scanf("%d", &np);
    printf("Enter number of resources: ");
    scanf("%d", &nr);

    // Input: allocation matrix
    printf("Enter the Allocation matrix (%d x %d):\n", np, nr);
    for (int i = 0; i < np; i++) {
        for (int j = 0; j < nr; j++) {
            scanf("%d", &alloc[i][j]);
        }
    }

    // Input: max matrix
    printf("Enter the Max matrix (%d x %d):\n", np, nr);
    for (int i = 0; i < np; i++) {
        for (int j = 0; j < nr; j++) {
            scanf("%d", &max[i][j]);
        }
    }

    // Input: available resources
    printf("Enter the Available resources (%d values):\n", nr);
    for (int i = 0; i < nr; i++) {
        scanf("%d", &avail[i]);
    }

    // Calculate need matrix = max - alloc
    for (int i = 0; i < np; i++)
        for (int j = 0; j < nr; j++)
            need[i][j] = max[i][j] - alloc[i][j];

    // Apply Banker's Algorithm
    int idx = 0;
    for (int k = 0; k < np; k++) {
        for (int i = 0; i < np; i++) {
            if (!finish[i]) {
                int canRun = 1;
                for (int j = 0; j < nr; j++) {
                    if (need[i][j] > avail[j]) {
                        canRun = 0;
                        break;
                    }
                }

                if (canRun) {
                    for (int j = 0; j < nr; j++)
                        avail[j] += alloc[i][j];
                    finish[i] = 1;
                    safeSeq[idx++] = i;
                }
            }
        }
    }

    // Check if system is in a safe state
    int isSafe = 1;
    for (int i = 0; i < np; i++) {
        if (!finish[i]) {
            isSafe = 0;
            break;
        }
    }

    if (isSafe) {
        printf("System is in a SAFE state.\nSafe sequence: ");
        for (int i = 0; i < np; i++)
            printf("P%d%s", safeSeq[i], (i == np - 1 ? "\n" : " -> "));
    } else {
        printf("System is NOT in a safe state.\n");
    }

    return 0;
}
