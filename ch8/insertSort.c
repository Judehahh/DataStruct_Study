#include <stdio.h>

void printa(int A[], int len) {
	for (int i = 0; i < 10; ++i) {
		printf("%d ", A[i]);
	} 
    printf ("\n");
}

void insertSort(int A[], int len) {
	int i, j, temp;
	for (i = 1; i < len; i++) {
		if (A[i] < A[i - 1]) {
			temp = A[i];
			for (j = i - 1; j >= 0 && A[j] > temp; j--) {
				A[j + 1] = A[j];
			}
			A[j + 1] = temp;
		}
	}
}

void insertSort1(int A[], int len) {
	int i, j, tmp, high, low, mid;
	for (i = 1; i < len; ++i) {
		if (A[i] < A[i - 1]) {
			tmp = A[i];
			low = 0;
			high = i - 1;
			while (low <= high) {
				mid = (low + high) / 2;
				if (A[mid] > tmp)
					high = mid - 1;
				else
					low = mid + 1;
			}
			for (j = i - 1; j > high; --j)
				A[j + 1] = A[j]; 
			A[j + 1] = tmp;
		}
	}
}

int main() {
	int array[10] = {9,8,7,6,6,6,5,4,3,3};
	insertSort1(array, 10);
    printa(array, 10);

	return 0;
}

