void Floyd()
{
    int dist[maxn][maxn];  // dist存储i到j的最短距离
    for(int k = 1; k <= n; k++)
        for(int i = 1;i <= n; i++)
            for(int j = 1; j <= n; j++)
                if(dist[i][k] + dist[k][j] < dist[i][j])
                    dist[i][j] = dist[i][k] + dist[k][j];  // 不断更新最短距离
}
void dijkstra(Vertex s){	/*初始化所有节点*/
	for each Vertex v
	{
		v.dist = INFINITY;//将所有节点到起点 s 的距离设为无穷大
		v.known = false;//将所有节点标为未确定，即还未加入路径
}	
	s.dist = 0; //将起点自己的dist设为0
	for( ; ; ){  //一直循环，直到触发break
		Vertex v = smallest distance and unknown vertex; //从未确定的点集中取出距离起点最近的点
		if(v==null) break; //若取到的点是空，即已无点可取
		v.known = true; //将该点加入确定点
		for each Vertex w adjacent to v  //只遍历、选出与新加入节点v相连的节点w
			if( !w.known ) //如果w还是未确定的点
				//因为距离还未确定，所以比较，若是更近则更新
				if(v.dist + cvw < w.dist){ //自认，cvw是指当前所选节点w与新加入节点v的距离//
					w.dist = v.dist + cvw;
					w.path = v;
				}
	} 
	
}


