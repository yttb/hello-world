#include<iostream>
#include <algorithm>
#include<cstdlib>
#include<cmath>
#define N 10 
using namespace std;
void selectSort(int a[], int left, int right) { 
	
	int max,index;
	for (int i = left; i < right; i++) {
		max = a[i]; index = i;
		for (int j = i + 1; j <= right; j++) {
			if (a[j] > max) {
				max = a[j];
				index = j;
			}
		}
		a[index] = a[i];
		a[i] = max;
	}
}
void insertSort(int a[], int left, int right) {

	int i, j, temp;
	for (i = left + 1; i <= right; i++) {
		j = i - 1;
		temp = a[i];
		while (j >= left && a[j] > temp) {
			a[j + 1] = a[j];
			j--;
		}
		a[j + 1] = temp;
	}
}
void swap(int* a, int* b) {
	int temp = *a;
	*a = *b;
	*b = temp;
}
int getMedian(int* const left, int* const right) {
	if (left >= right-1) {
		return *left;
	}
	int* l, * r;
	int dis = 0;
	for (l = left; l <= right; l+=5) {
		if (l + 4 <= right) {
			r = l + 4;
		}
		else {
			r = right;
		}
		insertSort(left,l-left,r-left);
		swap(left + dis, l + (r - l) / 2);
		dis++;
	}
	return getMedian(left, left + dis);
}

int Bfprt(int* const left, int* const right, int* const k) {

	int* l = left, *r = right;
	int pivot = getMedian(left, right);
	while (l < r) {
		while (l < r && *r >= pivot) {
			r--;
		}
		*l = *r;
		while (l < r && *l <= pivot) {
			l++;
		}
		*r = *l;
	}
	*l = pivot;
	if (l == k) return *l;
	else if (l > k) return Bfprt(left, l - 1, k);
	else Bfprt(l+1, right, k);

}
void printArray(int a[], int n) {
	for (int i = 0; i < n; i++) {
		cout << a[i] << "\t";
		if ((i+1) % 5 == 0) {
			cout << endl;
		}
	}
}
int main() {

	int arr[N] = {2,4,1,7,8,6,9,5,3,10};
	int k = 1;
	cout << "Please enter k between 1 and 10:" ;
	cin >> k;
	cout<< "The value of index k is:"<<Bfprt(arr, arr+N-1, arr+k-1);
	return 0;
}
