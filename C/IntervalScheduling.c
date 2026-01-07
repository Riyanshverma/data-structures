#include <stdio.h>
#include <stdlib.h>

// Structure to represent an interval
struct Interval {
    int start, finish;
};

// Function to compare intervals based on their finish time
int compare(const void *a, const void *b) {
    return ((struct Interval *)a)->finish - ((struct Interval *)b)->finish;
}

// Function to find the maximum number of non-overlapping intervals
void intervalScheduling(struct Interval intervals[], int n) {
    // Sort intervals based on finish time
    qsort(intervals, n, sizeof(struct Interval), compare);

    // Initialize variables
    int i = 0, count = 1;

    // Select the first interval
    printf("Selected Interval: (%d, %d)\n", intervals[i].start, intervals[i].finish);

    // Iterate through all intervals
    for (int j = 1; j < n; j++) {
        // If the current interval doesn't overlap with the previous selected interval, select it
        if (intervals[j].start >= intervals[i].finish) {
            printf("Selected Interval: (%d, %d)\n", intervals[j].start, intervals[j].finish);
            i = j;
            count++;
        }
    }

    printf("Maximum non-overlapping intervals: %d\n", count);
}

int main() {
    int n;
    printf("Enter the number of intervals: ");
    scanf("%d", &n);

    // Dynamically allocate memory for intervals
    struct Interval *intervals = (struct Interval *)malloc(n * sizeof(struct Interval));

    // Input intervals
    printf("Enter start and finish times of each interval:\n");
    for (int i = 0; i < n; i++) {
        printf("Interval %d: ", i + 1);
        scanf("%d %d", &intervals[i].start, &intervals[i].finish);
    }

    // Find maximum number of non-overlapping intervals
    intervalScheduling(intervals, n);

    // Free allocated memory
    free(intervals);

    return 0;
}