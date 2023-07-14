#define MAX_VERTEX_NUM 10

struct Graph{};
int d[MAX_VERTEX_NUM];      // 表示从u到i的最短路径
int path[MAX_VERTEX_NUM];   // 记录从u到i的路径
int visted[MAX_VERTEX_NUM];

void BFS_MIN_Distance(Graph G, int u) {
    for (int i = 0; i < G.vexnum; ++i) {
        d[i] = -1;
        path[i] = -1;
    }
    d[u] = 0;
    visted[u] = true;
    struct stack Q;
    Q.push(u);
    while (!Q.empty()) {
        u = Q.pop();
        for (w = firstNeighbour(G, u); w > = 0; w = nextNeighbour(G, u, w)) {
            if (!visted[w]) {
                visted[w] = true;
                d[w] = d[u] + 1;
                path[w] = u;
                Q.push(w);
            }
        }
    }
}


int main() {
    return 0;
}
