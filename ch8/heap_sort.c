#include <stdio.h>

void printa(int A[], int len) {
	for (int i = 1; i <= len; ++i) {
		printf("%d ", A[i]);
	} 
    printf ("\n");
}

void swap(int* a, int *b) {
    int tmp = *a;
    *a = *b;
    *b = tmp;
}

void print_tree(int tree[], int size) {
    int level = 1; // 当前层数
    int i = 1; // 数组索引

    while (i <= size) {
        for (int j = 0; j < level && i <= size; j++) {
            printf("%d ", tree[i]);
            i++;
        }
        printf("\n");
        level *= 2;
    }
}

void adjust_heap(int A[], int start, int end) {
    A[0] = A[start];
    // 从start结点的左孩子开始向下调整
    for (int i = 2 * start; i <= end; i *= 2) {
        if (i < end && A[i] < A[i + 1]) 
            ++i;                // 找到最大的那个孩子
        if (A[0] >= A[i])
            break;              // 父结点比两个孩子都大
        else {
            A[start] = A[i];    // 把大的孩子"上浮"
            start = i;          // 大孩子的位置作为start继续向下调整
        }
    }
    A[start] = A[0];
}

void build_maxheap(int A[], int len) {
    for (int i = len / 2; i > 0; --i) {
        adjust_heap(A, i, len);    // 从最后一个非叶结点开始，调整以这个结点为根的堆
    }
}

void heap_sort(int A[], int len) {
    build_maxheap(A, len);
    // printf("max heap: \n");
    // print_tree(A, 10);
    for (int i = len; i > 1; --i) {
        swap(&A[1], &A[i]);
        adjust_heap(A, 1, i - 1);
    }
}

int main() {
	int array[11] = {0, 4, 5, 3, 8, 7, 6, 9, 3, 6, 6};
    printf("\nraw array:\n");
    printa(array, 10);

    heap_sort(array, 10);

    printf("\nsorted array:\n");
    printa(array, 10);

	return 0;
}

