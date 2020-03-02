#include<stdio.h>
int Prim(MGraph Graph, LGraph MST)//�������Ҫ���湹�ɺ����С��,MST���ֿ���ʡȥ 
{ /* ����С����������Ϊ�ڽӱ�洢��ͼMST��������СȨ�غ� */
  //��Ϊ��С��һ����ϡ����,�������ڽӱ��� 
	WeightType dist[MaxVertexNum], TotalWeight;//�ֱ��� ���������������Ȩֵ,��Ȩֵ 
	Vertex parent[MaxVertexNum], V, W;//�ֱ��� ÿ������ĸ��ڵ�(��¼��),��һ����¼�Ķ���,��ν�Ҫ��¼�Ķ��� 
	int VCount;//�Ѿ���¼�Ķ������ 
	Edge E;//Ҫ�ӵ����б�,����ߵ���Ϣ 

	/* ��ʼ����Ĭ�ϳ�ʼ���±���0 */
	for (V = 0; V < Graph->Nv; V++) {
		/* ���������V��Wû��ֱ�ӵıߣ���Graph->G[V][W]����ΪINFINITY */
		dist[V] = Graph->G[0][V];//��0Ϊ��ʼ�� 
		parent[V] = 0; /* ���Ҷ������ж���ĸ���㶼�ǳ�ʼ��0 */
	}
	TotalWeight = 0; /* ��ʼ��Ȩ�غ�     */
	VCount = 0;      /* ��ʼ����¼�Ķ����� */
	/* �����������ж��㵫û�бߵ�ͼ��ע�����ڽӱ�汾 */
	MST = CreateGraph(Graph->Nv);
	E = (Edge)malloc(sizeof(struct ENode)); /* �����յı߽�� */

	/* ����ʼ��0��¼��MST */
	dist[0] = 0;
	VCount++;
	parent[0] = -1; /* ��ǰ������0 */

	while (1) {
		V = FindMinDist(Graph, dist);//Ѱ�Ҷ��� 
		/* V = δ����¼������dist��С�� */
		if (V == ERROR) /* ��������V������ */
			break;   /* �㷨���� */

		/* ��V����Ӧ�ı�<parent[V], V>��¼��MST */
		E->V1 = parent[V];//v�ĸ��ڵ� 
		E->V2 = V;
		E->Weight = dist[V];
		InsertEdge(MST, E);//�ѱ߲��뵽MST 
		TotalWeight += dist[V];//Ȩֵ��� 
		dist[V] = 0;//��V��0 
		VCount++;
		//����dist 
		for (W = 0; W < Graph->Nv; W++) /* ��ͼ�е�ÿ������W */
			if (dist[W] != 0 && Graph->G[V][W] < INFINITY) {
				/* ��W��V���ڽӵ㲢��δ����¼ */
				if (Graph->G[V][W] < dist[W]) {//G[v][w]Ϊ����Ȩֵ,dist[w]Ϊ�����µ�ֵ 
				/* ����¼Vʹ��dist[W]��С */
					dist[W] = Graph->G[V][W]; /* ����dist[W] */
					parent[W] = V; /* ������ */
				}
			}
	} /* while����*/
	if (VCount < Graph->Nv) /* MST���յĶ��㲻��|V|�� */
		TotalWeight = ERROR;
	return TotalWeight;   /* �㷨ִ����ϣ�������СȨ�غͻ������ */
}
