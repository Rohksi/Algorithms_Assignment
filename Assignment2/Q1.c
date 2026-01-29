#include <stdio.h>

int main() {
    int start[] = {1, 3, 0, 5, 8, 5};
    int finish[] = {2, 4, 6, 7, 9, 9};
    int n = 6;

    int i, j;
    int count = 1;

    printf("Selected activities: (%d, %d)", start[0], finish[0]);

    i = 0;
    for (j = 1; j < n; j++) {
        if (start[j] >= finish[i]) {
            printf(", (%d, %d)", start[j], finish[j]);
            count++;
            i = j;
        }
    }

    printf("\nMaximum number of activities = %d\n", count);

    return 0;
}
