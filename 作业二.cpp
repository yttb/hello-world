void Floyd()
{
    int dist[maxn][maxn];  // dist�洢i��j����̾���
    for(int k = 1; k <= n; k++)
        for(int i = 1;i <= n; i++)
            for(int j = 1; j <= n; j++)
                if(dist[i][k] + dist[k][j] < dist[i][j])
                    dist[i][j] = dist[i][k] + dist[k][j];  // ���ϸ�����̾���
}
void dijkstra(Vertex s){	/*��ʼ�����нڵ�*/
	for each Vertex v
	{
		v.dist = INFINITY;//�����нڵ㵽��� s �ľ�����Ϊ�����
		v.known = false;//�����нڵ��Ϊδȷ��������δ����·��
}	
	s.dist = 0; //������Լ���dist��Ϊ0
	for( ; ; ){  //һֱѭ����ֱ������break
		Vertex v = smallest distance and unknown vertex; //��δȷ���ĵ㼯��ȡ�������������ĵ�
		if(v==null) break; //��ȡ���ĵ��ǿգ������޵��ȡ
		v.known = true; //���õ����ȷ����
		for each Vertex w adjacent to v  //ֻ������ѡ�����¼���ڵ�v�����Ľڵ�w
			if( !w.known ) //���w����δȷ���ĵ�
				//��Ϊ���뻹δȷ�������ԱȽϣ����Ǹ��������
				if(v.dist + cvw < w.dist){ //���ϣ�cvw��ָ��ǰ��ѡ�ڵ�w���¼���ڵ�v�ľ���//
					w.dist = v.dist + cvw;
					w.path = v;
				}
	} 
	
}


