#include <stdio.h>
#include "compute.h"

int compute_sum(const int *numbers, int count) {
    int sum = 0;
    for (int i = 0; i < count; i++) {
        sum += numbers[i];
    }
    return sum;
}

float compute_average(const int *numbers, int count) {
    float sum = 0;
    for (int i = 0; i < count; i++) {
        sum += numbers[i];
    }
    return (sum/count);
}

float compute_moving_average(const int *numbers, int
count, int window_size) {
    float sum = 0;
    int i;
    if (window_size > count || window_size <= 0) {
        return -1; 
    }
    for (i = 0; i < window_size; i++) {
        sum += numbers[i];
    }
    float moving_avg = sum / window_size;
    for (i = window_size; i < count; i++) {
        sum = sum - numbers[i - window_size] + numbers[i];
        moving_avg = sum / window_size;
    }
    return moving_avg;
}