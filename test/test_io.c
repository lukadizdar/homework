#include <stdio.h>
#include <assert.h>
#include "file_io.h"

void test_read_numbers() {
    FILE *file1 = fopen("input.txt", "r");
    int numbers[10];
    int count = read_numbers("input.txt", &numbers, count);
    assert(count == 7);
    fclose(file1);
}

void test_write_results() {
    FILE *file2 = fopen("output.txt", "w");
    float result = 19.;
    int status = write_result("output.txt", result);
    assert (status == 0);
    fclose(file2);
    FILE *file3 = fopen("output.txt", "r");
    float read_result;
    fscanf("output.txt", "%f", &read_result);
    assert(read_result = result);
    fclose(file3);
}