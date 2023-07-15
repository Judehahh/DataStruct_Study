#include <stdio.h>

void printa(int A[], int len) {
	for (int i = 0; i < len; ++i) {
		printf("%d ", A[i]);
	}
	printf ("\n");
}

void count_sort(int A[], int len) {
	int tmp[len];
	for (int i = 0; i < len; ++i) {
		int count = 0;
		for (int j = 0; j < len; ++j)
		if (A[i] > A[j])
			++count;
		tmp[count] = A[i];
	}
	for (int i = 0; i < len; ++i)
		A[i] = tmp[i];
}

int main() {
	int array[] = {9,8,7,11,2,10,5,4,6,3};
	int len = sizeof(array) / sizeof (int);
	printf("raw array: ");
	printa(array, len);
	count_sort(array, len);
	printf("sorted array: ");
	printa(array, len);

	return 0;
}

