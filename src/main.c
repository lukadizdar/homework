#include <stdio.h>
#include "compute.h"
#include "file_io.h"

int main(void) {
    int numberCount = 7;
    int numbers[numberCount];
    int count = read_numbers("input.txt", numbers, numberCount);
    int sum = compute_sum(numbers, numberCount);
    float avg = compute_average(numbers, numberCount);
    float movavg = compute_moving_average(numbers, numberCount, 3);
    FILE *file1 = fopen("output.txt", "r");
    fseek (file1, 0, SEEK_END);
    long size = ftell(file1);
    fclose(file1);
    if (size != 0) {
        FILE *file2 = fopen("output.txt", "w");
        fclose(file2);
    }
    write_result("output.txt", (float)sum);
    write_result("output.txt", avg);
    write_result("output.txt", (movavg));
    return 0;
}