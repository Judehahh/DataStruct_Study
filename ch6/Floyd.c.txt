// 准备工作，初始化图grpah、path矩阵
for (int k = 0; k < n; k++) {           // 以k为中转点
    // 扫描图中的每对结点，看通过k点中转后是否有优化
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (graph[i][j] > graph[i][k] + graph[k][i]) {
				graph[i][j] = graph[i][k] + graph[k][j];
				path[i][j] = k;
			}
		}
	}
}
