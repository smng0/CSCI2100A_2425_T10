#include <stdio.h>
#include <stdlib.h>

typedef int ElementType;

// A function that merges two sorted arrays
void merge_two_arrays(ElementType *arr, ElementType *tmp, int left, int mid, int right) {
    int i = 0; // Pointer to the first element of the left sub-array
	int j = mid + 1; // Pointer to the first element of the right sub-array
	int k = 0; // Pointer to the merged array

    // Both pointers are not out-of-bounds
    while (i <= mid && j <= right) {
        if (arr[i] <= arr[j]) { // Put smaller element into output and update pointers
            tmp[k++] = arr[i++];
        } else {
            tmp[k++] = arr[j++];
        }
    }

    // Remaining elements
    while (i <= mid) {
        tmp[k++] = arr[i++];
    }

    while (j <= right) {
        tmp[k++] = arr[j++];
    }

	// Copy back
	for (k = 0; k <= right; k++) {
		arr[k] = tmp[k];
	}
}

// A function that performs merge sort on an array
void msort(ElementType *arr, ElementType *tmp, int left, int right) {
	int mid;
	
	if (left < right) {
		mid = (left + right) / 2;
		msort(arr, tmp, left, mid);
		msort(arr, tmp, mid+1, right);
		merge_two_arrays(arr, tmp, left, mid, right);
	}
}

// A wrapper function that performs merge sort on an array
void merge_sort(int n, ElementType *arr) {
    ElementType *tmp = (ElementType *)malloc(n * sizeof(ElementType)); // Temporary array
	msort(arr, tmp, 0, n-1);
	free(tmp);
}

int main() {
    int i; // Loop variable
    ElementType arr[] = {19, 25, 14, 1, 26, 22, 5, 27, 3};
    merge_sort(9, arr);
    for (i = 0; i < 9; i++) {
        printf("%d ", arr[i]);
    }
    putchar('\n');
    return 0;
}