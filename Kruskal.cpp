#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>
#include <string.h>

#define MAX         100                 // 矩阵最大容量
#define INF         (~(0x1<<31))        // 最大值(即0X7FFFFFFF)
#define isLetter(a) ((((a)>='a')&&((a)<='z')) || (((a)>='A')&&((a)<='Z')))
#define LENGTH(a)   (sizeof(a)/sizeof(a[0]))
typedef struct _graph
{
	char vexs[MAX];       // 顶点集合
	int vexnum;           // 顶点数
	int edgnum;           // 边数
	int matrix[MAX][MAX]; // 邻接矩阵
}Graph, *PGraph;

// 边的结构体
typedef struct _EdgeData
{
	char start; // 边的起点
	char end;   // 边的终点
	int weight; // 边的权重
}EData;
void kruskal(Graph G)
{
	int i, m, n, p1, p2;
	int length;
	int index = 0;          // rets数组的索引
	int vends[MAX] = { 0 };     // 用于保存"已有最小生成树"中每个顶点在该最小树中的终点。
	EData rets[MAX];        // 结果数组，保存kruskal最小生成树的边
	EData *edges;           // 图对应的所有边

	// 获取"图中所有的边"
	edges = get_edges(G);
	// 将边按照"权"的大小进行排序(从小到大)
	sorted_edges(edges, G.edgnum);

	for (i = 0; i < G.edgnum; i++)
	{
		p1 = get_position(G, edges[i].start);   // 获取第i条边的"起点"的序号
		p2 = get_position(G, edges[i].end);     // 获取第i条边的"终点"的序号

		m = get_end(vends, p1);                 // 获取p1在"已有的最小生成树"中的终点
		n = get_end(vends, p2);                 // 获取p2在"已有的最小生成树"中的终点
		// 如果m!=n，意味着"边i"与"已经添加到最小生成树中的顶点"没有形成环路
		if (m != n)
		{
			vends[m] = n;                       // 设置m在"已有的最小生成树"中的终点为n
			rets[index++] = edges[i];           // 保存结果
		}
	}
	free(edges);

	// 统计并打印"kruskal最小生成树"的信息
	length = 0;
	for (i = 0; i < index; i++)
		length += rets[i].weight;
	printf("Kruskal=%d: ", length);
	for (i = 0; i < index; i++)
		printf("(%c,%c) ", rets[i].start, rets[i].end);
	printf("\n");
}
int main(void)
{
	return 0;
}