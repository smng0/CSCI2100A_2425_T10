#include <stdio.h>
#include <stdlib.h>

// A function that merges two sorted arrays
void merge_two_arrays(int n1, int n2, int *arr1, int *arr2, int *merged) {
    int i = 0, j = 0, k = 0; // Pointers to the first element of arr1, arr2 and merged

    // Both pointers are not out-of-bounds
    while (i < n1 && j < n2) {
        if (arr1[i] <= arr2[j]) { // Put smaller element into output and update pointers
            merged[k++] = arr1[i++];
        } else {
            merged[k++] = arr2[j++];
        }
    }

    // Remaining elements
    while (i < n1) {
        merged[k++] = arr1[i++];
    }

    while (j < n2) {
        merged[k++] = arr2[j++];
    }
}

int main() {
    int i; // Loop counter
    int arr1[] = {1, 14, 19, 25}; // Input 1
    int arr2[] = {3, 5, 22, 26, 27}; // Input 2
    int *arr3 = (int *)calloc(9, sizeof(int)); // Output
    merge_two_arrays(4, 5, arr1, arr2, arr3); // Merging
    for (i = 0; i < 9; i++) {
        printf("%d ", arr3[i]);
    }
    putchar('\n');
    return 0;
}