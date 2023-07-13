#include <stdio.h>

void printa(int A[], int len) {
	for (int i = 0; i < len; ++i) {
		printf("%d ", A[i]);
	} 
    printf ("\n");
}

void insert_sort(int A[], int len) {
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

void binary_insert_sort(int A[], int len) {
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

void shell_sort(int A[], int n) {
    int step, i, j, tmp;
    for (step = n / 2; step >= 1; step /= 2) {
        for (i = step; i < n; ++i) {
            if (A[i] < A[i - step]) {
                tmp = A[i];
                for (j = i - step; j >= 0 && A[j] > tmp; j -= step) {
                   A[j + step] = A[j]; 
                }
                A[j + step] = tmp;
            }
        }
    }
}

int main() {
	int array[10] = {9,8,7,6,6,6,5,4,3,3};
    shell_sort(array, 10);
    printa(array, 10);

	return 0;
}

