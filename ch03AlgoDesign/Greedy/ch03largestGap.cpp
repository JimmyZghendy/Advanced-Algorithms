#include<iostream>
using namespace std;
#include<vector>
#include<algorithm>


int largestGap(vector<int> a) {
	int n = a.size();
	int lo = 0, hi = n - 1;
	int min, max;
	min = *min_element(a.begin(),a.end());
	max = *max_element(a.begin(), a.end());
	return max - min;
}

int main() {
	int A[] = {12, 5, 10, 23, 7, 2};
	int n = sizeof(A) / sizeof(int);
	vector<int> a(A, A + n);
	cout << largestGap(a) << endl;
	return 0;
}