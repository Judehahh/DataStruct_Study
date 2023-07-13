#include <stdio.h>
#include <stdbool.h>

void swap(int* a, int *b) {
    int tmp = *a;
    *a = *b;
    *b = tmp;
}

void printa(int A[], int len) {
	for (int i = 0; i < len; ++i) {
		printf("%d ", A[i]);
	} 
    printf ("\n");
}

int partition(int A[], int low, int high) {
    int mid = (low + high) / 2;
    int pivot = A[mid];
    A[mid] = A[low];
    while (low < high) {
        while (low < high && A[high] >= pivot)
            --high;
        A[low] = A[high];
        while (low < high && A[low] <= pivot)
            ++low;
        A[high] = A[low];
    }
    A[low] = pivot;
    return low;
}

void quick_sort(int A[], int low, int high) {
    if (low < high) {
        int pivot_index = partition(A, low, high);
        quick_sort(A, low, pivot_index - 1);
        quick_sort(A, pivot_index + 1, high);
    }
}

int main() {
	int array[10] = {9,8,7,6,6,6,5,4,3,3};
    printa(array, 10);
    quick_sort(array, 0, 10);
    printa(array, 10);

	return 0;
}

