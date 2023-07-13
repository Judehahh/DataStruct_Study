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

void bubble_sort(int A[], int n) {
    for (int i = n; i > 0; --i) {
        bool flag = false;
        for (int j = 1; j < i; ++j) {
            if (A[j] < A[j - 1]) {
                swap(&A[j], &A[j - 1]);
                flag = true;
            }
        }
        if (flag == false)
            return;
    }
}

int main() {
	int array[10] = {9,8,7,6,6,6,5,4,3,3};
    printa(array, 10);
    bubble_sort(array, 10);
    printa(array, 10);

	return 0;
}

