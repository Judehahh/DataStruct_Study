#include <stdio.h>

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

int find_min(int A[], int low, int high, int k) {
    if (k - 1 < low || k - 1 > high) {
        printf("ERROR: k = %d out of range\n", k);
        return -1;
    }
    int pivot_index = partition(A, low, high);
    if (pivot_index == k - 1)
        return A[pivot_index];
    else if(pivot_index > k - 1)
        return find_min(A, low, pivot_index - 1, k);
    else
        return find_min(A, pivot_index + 1, high, k);
}

int main() {
	int array[10] = {9,8,7,6,6,6,5,4,3,3};
	int tmp[10] = {9,8,7,6,6,6,5,4,3,3};
    printf("raw array: ");
    printa(array, 10);
    quick_sort(tmp, 0, 9);
    printf("sorted array: ");
    printa(tmp, 10);

    int k;
    for (k = 1; k <= 10; ++k) {
        printf("the %d th min in array is: %d\n", k, find_min(array, 0, 9, k));
    }

	return 0;
}

