// Q1
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

// Q2

#include <stdio.h>
#include <stdlib.h>

int cmp(const void *a, const void *b) {
    return (*(int*)a - *(int*)b);
}

int main() {
    int at[] = {900, 910, 920, 1100, 1120};
    int dt[] = {940, 1200, 950, 1130, 1140};
    int n = 5;

    qsort(at, n, sizeof(int), cmp);
    qsort(dt, n, sizeof(int), cmp);

    int i = 0, j = 0, platforms = 0, max = 0;

    while (i < n && j < n) {
        if (at[i] <= dt[j]) {
            platforms++;
            if (platforms > max) max = platforms;
            i++;
        } else {
            platforms--;
            j++;
        }
    }

    printf("%d", max);
    return 0;
}

// Q3

#include <stdio.h>

int main() {
    int n = 3;
    float value[] = {100, 60, 120};
    float weight[] = {20, 10, 40};
    float W = 50;

    float ratio[3], temp;
    int i, j;
    float maxValue = 0;

    for (i = 0; i < n; i++)
        ratio[i] = value[i] / weight[i];

    for (i = 0; i < n - 1; i++) {
        for (j = i + 1; j < n; j++) {
            if (ratio[i] < ratio[j]) {
                temp = ratio[i]; ratio[i] = ratio[j]; ratio[j] = temp;
                temp = value[i]; value[i] = value[j]; value[j] = temp;
                temp = weight[i]; weight[i] = weight[j]; weight[j] = temp;
            }
        }
    }

    for (i = 0; i < n && W > 0; i++) {
        if (weight[i] <= W) {
            W -= weight[i];
            maxValue += value[i];
        } else {
            maxValue += value[i] * (W / weight[i]);
            W = 0;
        }
    }

    printf("%.0f", maxValue);
    return 0;
}

//Q4

#include <stdio.h>

int main() {
    int n = 5;
    int deadline[] = {2, 1, 2, 1, 3};
    int profit[] = {100, 19, 27, 25, 15};
    char jobs[] = {'1','2','3','4','5'};

    int i, j, maxD = 0;
    for (i = 0; i < n; i++)
        if (deadline[i] > maxD) maxD = deadline[i];

    int slot[10] = {0};
    int result[10];
    int totalProfit = 0, count = 0;

    for (i = 0; i < n - 1; i++) {
        for (j = i + 1; j < n; j++) {
            if (profit[i] < profit[j]) {
                int t = profit[i]; profit[i] = profit[j]; profit[j] = t;
                t = deadline[i]; deadline[i] = deadline[j]; deadline[j] = t;
                char c = jobs[i]; jobs[i] = jobs[j]; jobs[j] = c;
            }
        }
    }

    for (i = 0; i < n; i++) {
        for (j = deadline[i] - 1; j >= 0; j--) {
            if (!slot[j]) {
                slot[j] = 1;
                result[j] = i;
                totalProfit += profit[i];
                count++;
                break;
            }
        }
    }
    printf("Jobs");
    for (i = 0; i < maxD; i++)
        if (slot[i]) printf("   J%c ", jobs[result[i]]);

    printf("\nTotal Profit: %d", totalProfit);
    return 0;
}
