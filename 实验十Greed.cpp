#include <iostream>
#include<algorithm>
using namespace std;
const int N = 100;

struct A{//��ṹ��
	int s;      //��ʼʱ��
	int f;      //����ʱ��
};

bool cmp_f(const A& x, const A& y)//����ʱ������
{
	return x.f < y.f;
}

bool cmp_s(const A& x, const A& y)//��ʼʱ������
{
	return x.s < y.s;
}

bool cmp_t(const A& x, const A& y)//ռ��ʱ������
{
	return x.f-x.s < y.f-y.s;
}

int Greed(A a[],int n) {//̰���㷨
	
	sort(a+1, a + n + 1, cmp_f);//����ʱ������
	//sort(a + 1, a + n + 1, cmp_s);//��ʼʱ������
	//sort(a + 1, a + n + 1, cmp_t);//ռ��ʱ������
	int pre = a[1].f;
	int num = 1;
	cout << "Greed:" << endl;
	cout << 1 << "\t";
	for (int i = 2; i <= n; i++) {
		if (a[i].s >= pre) {
			cout << i << "\t";
			num++;//���+1
			pre = a[i].f;
		}
	}
	return num;
}
int main() {
	A a[N];
	int n;
	cin >> n;//���
	for (int i = 1; i <= n; i++)
		cin >> a[i].s >> a[i].f;
	cout << endl << "the max number is " << Greed(a,n) << endl;
}
