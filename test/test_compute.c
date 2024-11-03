#include <stdio.h>
#include <assert.h>
#include "compute.h"

void test_compute_sum() {
    int numbers[] = {2,3,5,6};
    int sum = compute_sum(numbers, 4);
    assert(sum == 16);;
}

void test_compute_average() {
    int numbers[] = {1, 2, 3, 4, 5};
    float average = compute_average(numbers, 5);
    assert(average == 3.0);
}

void test_compute_moving_average() {
    int numbers[] = {1, 2, 3, 4, 5};
    float moving_average = compute_moving_average(numbers, 5, 3);
    assert(moving_average == 2.0);
}






