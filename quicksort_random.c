// Note: Randomized Quicksort is covered in ESTR2102 only.
#include <stdio.h>
#include <stdlib.h> // For srand() and rand() functions
#include <time.h> // For time() function

// A helper function that swaps two elements in an array
void swap(int *arr, int a, int b) {
    int tmp = arr[a];
    arr[a] = arr[b];
    arr[b] = tmp;
}

// A helper function that print all elements in an array
void print_arr(int *arr, int left, int right) {
    int i; // Loop variable

    printf("%d", arr[left]);
    for (i = left + 1; i <= right; i++) {
        printf(" %d", arr[i]);
    }
    putchar('\n');
}

// A function that performs partition on an array
int partition(int *arr, int left, int right) {
    int pivot = arr[left]; // Key value of pivot (First element as pivot)
    int l = left; // Left pointer
    int r = right; // Right pointer

    while (l < r) {
        while (arr[l] <= pivot && l < r) {
            l++; // Move to the right
        }
        while (arr[r] > pivot) {
            r--; // Move to the left
        }
        if (l < r) {
            swap(arr, l, r); // Swap
        }
    }

    arr[left] = arr[r];
    arr[r] = pivot;
    return r; // New position of pivot
}

// A function that performs quicksort on an array
void q_sort(int *arr, int left, int right) {
    int pivot; // Position of the pivot after partition

    if (left < right) { // Not the base case
        // Divide: Partition
        pivot = partition(arr, left, right);
        print_arr(arr, left, right);

        // Conquer: Solve sub-problems
        q_sort(arr, left, pivot-1);
        q_sort(arr, pivot+1, right);
    }
}

// A wrapper function that performs quicksort on an array
void quicksort(int n, int *arr) {
    q_sort(arr, 0, n-1);
}

/******************************************************************************************
*                  The following functions are for randomized quicksort!                  *
*******************************************************************************************/

// A function that performs partition with randomized pivot on an array
int r_partition(int *arr, int left, int right) {
    int pivot_pos = (rand() % (right - left + 1)) + left;
    int pivot = arr[pivot_pos]; // Key value of pivot
    int l = left; // Left pointer
    int r = right; // Right pointer

    swap(arr, left, pivot_pos); // Remaining parts are same as before

    while (l < r) {
        while (arr[l] <= pivot && l < r) {
            l++; // Move to the right
        }
        while (arr[r] > pivot) {
            r--; // Move to the left
        }
        if (l < r) {
            swap(arr, l, r); // Swap
        }
    }

    arr[left] = arr[r];
    arr[r] = pivot;
    return r; // New position of pivot
}

// A function that performs randomized quicksort on an array
void rq_sort(int *arr, int left, int right) {
    int pivot; // Position of the pivot after partition

    if (left < right) { // Not the base case
        // Divide: Partition
        pivot = r_partition(arr, left, right);
        print_arr(arr, left, right);

        // Conquer: Solve sub-problems
        rq_sort(arr, left, pivot-1);
        rq_sort(arr, pivot+1, right);
    }
}

// A wrapper function that performs randomized quicksort on an array
void randomized_quicksort(int n, int *arr) {
    rq_sort(arr, 0, n-1);
}

int main() {
    srand(time(NULL)); // Initialize random seed

    int arr1[] = {19, 25, 14, 1, 26, 22, 5, 27, 3};    
    quicksort(9, arr1);
    print_arr(arr1, 0, 8);

    int arr2[] = {19, 25, 14, 1, 26, 22, 5, 27, 3};    
    printf("Randomized Quicksort:\n");
    randomized_quicksort(9, arr2);
    print_arr(arr2, 0, 8);

    return 0;
}