#include <stdlib.h>
#include <stdbool.h>
#include <stdio.h>
#include <string.h>

# define INIT_LENGTH 10

struct linear_list {
    int *data;
    int MaxSize, length;
};

void list_print(struct linear_list L) {
    for (int i = 0; i < L.length; ++i)
        printf("The %d num in L is: %d\n", i, *(L.data + i));
    printf("\n");
}

bool list_insert(struct linear_list *L, int index, int val) {
    if (index < 0 || index > L->length)
        return false;   // index out of range
    if (L->length >= L->MaxSize)
        return false;   // list is full
    for (int i = L->length; i > index; --i)
        L->data[i] = L->data[i - 1];
    L->data[index] = val;
    ++L->length;
    return true;
}

bool list_delete(struct linear_list *L, int index, int *val) {
    if (index < 0 || index > L->length - 1)
        return false;   // index out of range
    *val = L->data[index];
    for (int i = index; i < L->length - 1; ++i)
        L->data[i] = L->data[i + 1];
    --L->length;
    return true;
}

int list_locate_elem(struct linear_list L, int val) {
    int i = L.length - 1;
    for(; i >= 0; --i)
        if(L.data[i] == val)
            return i;
    return -1;
}

int main() {
    struct linear_list L = {
        .data = (int*)malloc(sizeof(int) * INIT_LENGTH),
        .MaxSize = INIT_LENGTH,
        .length = 0,
    };
    int data = -1;

    memset(L.data, 0, L.MaxSize * sizeof(int));

    for (int i = 0; i < 10; ++i)
        if (!list_insert(&L, i, i + 1)) {
            printf("list insert error\n");
            return -1;
        }

    list_print(L);

    data = list_locate_elem(L, 11);
    printf("Elem 11 is the %d in L\n\n", data);

    if (!list_delete(&L, 4, &data)) {
        printf("list delete error\n");\
        return -1;
    }
    printf("delete the %d data in L, val = %d\n", 4, data);

    list_print(L);

    return 0;
}