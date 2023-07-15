#include <stdio.h>

void printa(int A[], int len) {
	for (int i = 0; i < len; ++i) {
		printf("%d ", A[i]);
	}
    printf ("\n");
}

void merge(int A[], int low, int mid, int high) {
	printf("low = %d mid = %d high = %d\n", low, mid, high);
	int tmp[high - low + 1];
	int i, j;
	int k = 0;
	for (i = low, j = mid + 1; i <= mid && j <= high; ++k) {
		if (A[i] <= A[j])
			tmp[k] = A[i++];
		else
			tmp[k] = A[j++];
	}
	while (i <= mid)
		tmp[k++] = A[i++];
	while (j <= high)
		tmp[k++] = A[j++];
	for (i = low, k = 0; i <= high;)
		A[i++] = tmp[k++];
}

void merge_sort(int A[], int low, int high) {
	if (low < high) {
		int mid = (low + high) / 2;
		merge_sort(A, low, mid);
		merge_sort(A, mid + 1, high);
		merge(A, low, mid, high);
	}
}

int main() {
	int array[] = {9,8,7,6,6,6,5,4,3,3};
	int len = sizeof(array) / sizeof (int);
	printf("raw array: ");
	printa(array, len);
	merge_sort(array, 0, len - 1);
	printf("sorted array: ");
	printa(array, len);

	return 0;
}

