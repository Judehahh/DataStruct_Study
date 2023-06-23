#include <stdio.h>
#include <stdlib.h>

struct BiTNode {
    int data;
    struct BiTNode *left;
    struct BiTNode *right;
};

struct BiTNode *newNode(int data) {
    struct BiTNode *node = (struct BiTNode*)malloc(sizeof(struct BiTNode));
    node->data = data;
    node->left = NULL;
    node->right = NULL;
    return node;
}

void PreOrder_Recur(struct BiTNode *node) {
    if (node) {
        printf("%d", node->data);
        PreOrder_Recur(node->left);
        PreOrder_Recur(node->right);
    }
}

void InOrder_Recur(struct BiTNode *node) {
    if (node) {
        InOrder_Recur(node->left);
        printf("%d", node->data);
        InOrder_Recur(node->right);
    }
}

void PostOrder_Recur(struct BiTNode *node) {
    if (node) {
        PostOrder_Recur(node->left);
        PostOrder_Recur(node->right);
        printf("%d", node->data);
    }
}

int main() {
	struct BiTNode *root = newNode(1);
    root->left = newNode(2);
    root->right = newNode(3);
    root->left->left = newNode(4);
    root->left->right = newNode(5);

    printf("Binary tree created.\n");	

    printf("PreOrder_Recur the binary tree: \n");
    PreOrder_Recur(root);
    printf("\n");

    printf("InOrder_Recur the binary tree: \n");
    InOrder_Recur(root);
    printf("\n");

    printf("PostOrder_Recur the binary tree: \n");
    PostOrder_Recur(root);
    printf("\n");

    return 0;
}

