#include <stdio.h>

void printa(int A[], int len) {
	for (int i = 0; i < len; ++i) {
		printf("%d ", A[i]);
	} 
    printf ("\n");
}

void swap(int* a, int *b) {
    int tmp = *a;
    *a = *b;
    *b = tmp;
}

void select_sort(int A[], int len) {
    for (int i = 0; i < len - 1; ++i) {
        int min = i;
        for (int j = i + 1; j < len; ++j) {
            if (A[j] < A[min])
                min = j;
        }
        if (min != i)
            swap(&A[i], &A[min]);
    }
}

int main() {
	int array[10] = {9,8,7,6,6,6,5,4,3,3};
    select_sort(array, 10);
    printa(array, 10);

	return 0;
}

