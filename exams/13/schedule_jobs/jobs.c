#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include <stdint.h>
typedef struct {
    int profit;
    int duration;
    int deadline;
}job;
int ScheduleJobs(const job* jobs, size_t j_size) {

    int* a = malloc(j_size * sizeof(int));
    for (size_t i = 0; i < j_size; ++i) {
        a[i] = jobs[i].profit / jobs[i].duration;
    }
    int profitto = 0;
    int t = 0;
    int a_max_index = 0;
    int a_max = 0;
    bool zero = false;
    while (!zero) {
        zero = true;
        for (size_t k = 0; k < j_size; ++k) {
            if (a[k] > a_max) {
                a_max = a[k];
                a_max_index = k;
            }
            if (a[k] == a_max) {
                if (jobs[k].duration < jobs[a_max_index].duration) {
                    a_max = a[k];
                    a_max_index = k;
                }
            }
        }
        a[a_max_index] = 0;
        if (jobs[a_max_index].deadline >= t + jobs[a_max_index].duration) {
            profitto += jobs[a_max_index].profit;
            printf("%d ", a_max_index);
            t += jobs[a_max_index].duration;
        }
        for (size_t j = 0; j < j_size; ++j) {
            if (a[j] != 0) {
                zero = false;
                break;
            }
        }
        a_max = 0;
    }
    free(a);
    return profitto;
}