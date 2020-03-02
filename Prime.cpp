#include<stdio.h>
int Prim(MGraph Graph, LGraph MST)//如果不需要保存构成后的最小树,MST部分可以省去 
{ /* 将最小生成树保存为邻接表存储的图MST，返回最小权重和 */
  //因为最小树一定是稀疏树,所以用邻接表储存 
	WeightType dist[MaxVertexNum], TotalWeight;//分别是 储存各顶点离树的权值,总权值 
	Vertex parent[MaxVertexNum], V, W;//分别是 每个顶点的父节点(记录树),上一个收录的顶点,这次将要收录的顶点 
	int VCount;//已经收录的顶点个数 
	Edge E;//要加到树中边,储存边的信息 

	/* 初始化。默认初始点下标是0 */
	for (V = 0; V < Graph->Nv; V++) {
		/* 这里假设若V到W没有直接的边，则Graph->G[V][W]定义为INFINITY */
		dist[V] = Graph->G[0][V];//以0为起始点 
		parent[V] = 0; /* 暂且定义所有顶点的父结点都是初始点0 */
	}
	TotalWeight = 0; /* 初始化权重和     */
	VCount = 0;      /* 初始化收录的顶点数 */
	/* 创建包含所有顶点但没有边的图。注意用邻接表版本 */
	MST = CreateGraph(Graph->Nv);
	E = (Edge)malloc(sizeof(struct ENode)); /* 建立空的边结点 */

	/* 将初始点0收录进MST */
	dist[0] = 0;
	VCount++;
	parent[0] = -1; /* 当前树根是0 */

	while (1) {
		V = FindMinDist(Graph, dist);//寻找顶点 
		/* V = 未被收录顶点中dist最小者 */
		if (V == ERROR) /* 若这样的V不存在 */
			break;   /* 算法结束 */

		/* 将V及相应的边<parent[V], V>收录进MST */
		E->V1 = parent[V];//v的父节点 
		E->V2 = V;
		E->Weight = dist[V];
		InsertEdge(MST, E);//把边插入到MST 
		TotalWeight += dist[V];//权值相加 
		dist[V] = 0;//把V归0 
		VCount++;
		//更新dist 
		for (W = 0; W < Graph->Nv; W++) /* 对图中的每个顶点W */
			if (dist[W] != 0 && Graph->G[V][W] < INFINITY) {
				/* 若W是V的邻接点并且未被收录 */
				if (Graph->G[V][W] < dist[W]) {//G[v][w]为两边权值,dist[w]为待更新的值 
				/* 若收录V使得dist[W]变小 */
					dist[W] = Graph->G[V][W]; /* 更新dist[W] */
					parent[W] = V; /* 更新树 */
				}
			}
	} /* while结束*/
	if (VCount < Graph->Nv) /* MST中收的顶点不到|V|个 */
		TotalWeight = ERROR;
	return TotalWeight;   /* 算法执行完毕，返回最小权重和或错误标记 */
}
