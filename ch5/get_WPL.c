#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>

struct tree_node {
    unsigned int weight;
    struct tree_node *left, *right;
};

void _get_WPL(struct tree_node *root, unsigned int depth, unsigned int *WPL)
{
    if (root->left == NULL && root->right == NULL) {
        *WPL += depth * root->weight;
        return;
    }
    if (root->left)
        _get_WPL(root->left, depth + 1, WPL);
    if (root->right)
        _get_WPL(root->right, depth + 1, WPL);
    return;
}

int get_WPL(struct tree_node *root)
{
    unsigned int ret = 0;
    if (root)
        _get_WPL(root, 0, &ret);
    return ret;
}

struct tree_node* new_node(unsigned int weight) {
    struct tree_node* node = (struct tree_node*)malloc(sizeof(struct tree_node));
    node->weight = weight;
    node->left = NULL;
    node->right = NULL;
    return node;
}

int main()
{
    struct tree_node *root = new_node(1);
    root->left = new_node(2);
    root->right = new_node(3);
    root->left->left = new_node(4);
    root->left->right = new_node(5);

    int WPL = get_WPL(root);
    printf("The Weighted Path Length of the tree is: %d\n", WPL);

    return 0;    
}
