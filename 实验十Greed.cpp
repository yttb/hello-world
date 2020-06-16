#include <iostream>
#include<algorithm>
using namespace std;
const int N = 100;

struct A{//活动结构体
	int s;      //开始时间
	int f;      //结束时间
};

bool cmp_f(const A& x, const A& y)//结束时间排序
{
	return x.f < y.f;
}

bool cmp_s(const A& x, const A& y)//开始时间排序
{
	return x.s < y.s;
}

bool cmp_t(const A& x, const A& y)//占用时间排序
{
	return x.f-x.s < y.f-y.s;
}

int Greed(A a[],int n) {//贪婪算法
	
	sort(a+1, a + n + 1, cmp_f);//结束时间排序
	//sort(a + 1, a + n + 1, cmp_s);//开始时间排序
	//sort(a + 1, a + n + 1, cmp_t);//占用时间排序
	int pre = a[1].f;
	int num = 1;
	cout << "Greed:" << endl;
	cout << 1 << "\t";
	for (int i = 2; i <= n; i++) {
		if (a[i].s >= pre) {
			cout << i << "\t";
			num++;//活动数+1
			pre = a[i].f;
		}
	}
	return num;
}
int main() {
	A a[N];
	int n;
	cin >> n;//活动数
	for (int i = 1; i <= n; i++)
		cin >> a[i].s >> a[i].f;
	cout << endl << "the max number is " << Greed(a,n) << endl;
}
