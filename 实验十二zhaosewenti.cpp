#include<iostream>
using namespace std;
#define MAX 100
int color[MAX];
int graph[MAX][MAX] = { 0 };
int n, m;
int cnt = 0;
bool isDiffColor(int index) {
	for (int i = 0; i < n; i++) {
		if (graph[index][i] == 1 && color[index] == color[i]) {
			return false;
		}
	}
	return true;
}
void backTracking(int index) {

	if (index == n) {
		for (int i = 0; i < n; i++) {
			cout << color[i] << " ";
		}
		cnt++;
		cout << endl;
	}
	else {
		for (int j = 1; j <= m; j++) {
			color[index] = j;
			if (isDiffColor(index)) { 
				backTracking(index + 1);
			}
			color[index] = 0;
		}
	}
}
int main() {
	cout << "请输入顶点数n和颜色数m：" ;
	cin >> n >> m;
	cout << "请输入无向连通图：" << endl;
	for (int i = 0; i < n; i++) 
		for (int j = 0; j < n; j++) 
			cin >> graph[i][j];
	cout << "Answer:" << endl;
	backTracking(0);
	if (cnt == 0) {
		cout << "No" << endl;
	}
	else {
		cout << "可能的着色方案有：" << cnt << "种" << endl;
	}
}
