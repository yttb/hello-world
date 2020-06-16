#include<iostream>
#include<string.h>
#include<algorithm>
#include<stack>
using namespace std;
const int N = 100;

char X[N];
char Y[N];
char B[N][N];
int C[N][N] = { 0 };
stack<char> Stack;//创建一个存放字符的栈
int LCS(char* X, char* Y) {
	int m = strlen(X);
	int n = strlen(Y);
	for (int i = 0; i < m; i++) {
		for (int j = 0; j < n; j++) {
			if (X[i] == Y[j]) {
				C[i][j] = C[i - 1][j - 1] + 1;
				B[i][j] = 'D';
			}
			else if (C[i - 1][j] > C[i][j - 1]) {
				C[i][j] = C[i - 1][j];
				B[i][j] = 'X';
			}
			else {
				C[i][j] = C[i][j - 1];
				B[i][j] = 'Y';
			}
		}
	}
	return C[n - 1][m - 1];
}

void f(char(*B)[N], int i, int j) {
	if (i < 0 || j < 0)
		return;
	if (B[i][j] == 'D') {
		Stack.push(X[i]);//存入栈内
		f(B, i - 1, j - 1);
	}
	else if (B[i][j] == 'X')
		f(B, i - 1, j);
	else
		f(B, i, j - 1);
}
int main() {
	cin >> X;
	cin >> Y;
	cout << LCS(X, Y) << endl;
	f(B, strlen(X) - 1, strlen(Y) - 1);
	while (!Stack.empty()) {
		cout << Stack.top();
		Stack.pop();
	}
	return 0;

}
