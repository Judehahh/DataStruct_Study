#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node *next;
};

void print_list(struct node *head) {
    struct node *temp = head->next;
    while (temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

void select_sort_list(struct node *head) {
    struct node *fast, *slow, *tmp, *prev;
    slow = head;
    while (slow->next != NULL) {
        tmp = slow->next;
        fast = slow->next;
        prev = slow;
        while (fast->next != NULL) {
            if (fast->next->data < tmp->data) {
                tmp = fast->next;
                prev = fast;
            }
            fast = fast->next;
        }
        prev->next = tmp->next;
        tmp->next = slow->next;
        slow->next = tmp;
        slow = slow->next;
    }
}


int main() {
    int arr[] = {10, 4, 5, 3, 8, 7, 6, 9, 3, 6, 6};
    int n = sizeof(arr)/sizeof(arr[0]);

    struct node *head = (struct node*)malloc(sizeof(struct node));
    head->next = NULL;

    for (int i = n-1; i >= 0; i--) {
        struct node *new_node = (struct node*)malloc(sizeof(struct node));
        new_node->data = arr[i];
        new_node->next = head->next;
        head->next = new_node;
    }

    print_list(head);

    select_sort_list(head);
    print_list(head);

    return 0;
}

