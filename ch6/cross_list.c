#include <stdio.h>

#define MAXSIZE 20

struct vex_node {
    int from, to;
    struct vex_node* in_ptr;
    struct vex_node* out_ptr;
};

struct cross_list {
    int vex, edge;
    struct {
        int data;
        struct vex_node* in_ptr;
        struct vex_node* out_ptr;
    }head[MAXSIZE];
};

void create(struct cross_list* map);
void show(struct cross_list* map);
void insert(struct cross_list* map, int from, int to);

int main() {
    return 0;
}
