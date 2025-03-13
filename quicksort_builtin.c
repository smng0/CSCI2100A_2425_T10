#include <stdio.h>
#include <stdlib.h>

// Reference: https://en.cppreference.com/w/c/algorithm/qsort

// Comparison function for sorting in ascending order
int compare_asc(const void* a, const void* b) {
    int arg1 = *(const int*)a;
    int arg2 = *(const int*)b;
    return (arg1 > arg2) - (arg1 < arg2);
}

// Comparison function for sorting in descending order
int compare_desc(const void* a, const void* b) {
    int arg1 = *(const int*)a;
    int arg2 = *(const int*)b;
    return (arg1 < arg2) - (arg1 > arg2);
}

int main() {
    int i; // Loop variable

    // Example 1: Sorting in ascending order
    int arr1[] = {19, 25, 14, 1, 26, 22, 5, 27, 3};
    qsort(arr1, 9, sizeof(int), compare_asc);

    for (i = 0; i < 9; i++) {
        printf("%d ", arr1[i]);
    }
    putchar('\n');

    // Example 2: Sorting in descending order
    int arr2[] = {19, 25, 14, 1, 26, 22, 5, 27, 3};
    qsort(arr2, 9, sizeof(int), compare_desc);

    for (i = 0; i < 9; i++) {
        printf("%d ", arr2[i]);
    }
    putchar('\n');

    return 0;
}