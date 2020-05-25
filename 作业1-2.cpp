void kruskal(Graph G)
{
    int i,m,n,p1,p2;
    int length;
    int index = 0;          // rets���������
    int vends[MAX]={0};     // ���ڱ���"������С������"��ÿ�������ڸ���С���е��յ㡣
    EData rets[MAX];        // ������飬����kruskal��С�������ı�
    EData *edges;           // ͼ��Ӧ�����б�

    // ��ȡ"ͼ�����еı�"
    edges = get_edges(G);
    // ���߰���"Ȩ"�Ĵ�С��������(��С����)
    sorted_edges(edges, G.edgnum);

    for (i=0; i<G.edgnum; i++)
    {
        p1 = get_position(G, edges[i].start);   // ��ȡ��i���ߵ�"���"�����
        p2 = get_position(G, edges[i].end);     // ��ȡ��i���ߵ�"�յ�"�����

        m = get_end(vends, p1);                 // ��ȡp1��"���е���С������"�е��յ�
        n = get_end(vends, p2);                 // ��ȡp2��"���е���С������"�е��յ�
        // ���m!=n����ζ��"��i"��"�Ѿ���ӵ���С�������еĶ���"û���γɻ�·
        if (m != n)
        {
            vends[m] = n;                       // ����m��"���е���С������"�е��յ�Ϊn
            rets[index++] = edges[i];           // ������
        }
    }
    free(edges);

    // ͳ�Ʋ���ӡ"kruskal��С������"����Ϣ
    length = 0;
    for (i = 0; i < index; i++)
        length += rets[i].weight;
    printf("Kruskal=%d: ", length);
    for (i = 0; i < index; i++)
        printf("(%c,%c) ", rets[i].start, rets[i].end);
    printf("\n");
}
��������������������������������
��Ȩ����������ΪCSDN�������ǡ���������ԭ�����£���ѭCC 4.0 BY-SA��ȨЭ�飬ת���븽��ԭ�ĳ������Ӽ���������
ԭ�����ӣ�https://blog.csdn.net/qq_45601688/article/details/104617779
