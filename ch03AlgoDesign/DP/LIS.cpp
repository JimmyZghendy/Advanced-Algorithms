#include<iostream>
using namespace std;
#include<vector>
#include<algorithm>
#include<ctime>
#include<stack>

void display(vector<int>&);
int LIS(vector<int> &a);

int LIS1(vector<int> &a, vector<int>&lis, vector<int> &p);
void displayLIS(vector<int> &a);

int main(){
	//int A[] = {10, 7, 3, 5, 8, 2, 9};
	//int A[] = {-7, 10, 9, 2, 3, 8, 8, 1};
	//int n = sizeof(A)/sizeof(int);
	//vector<int> a(A,A+n);
	int x, n=50 ;
	vector<int> a(n,0);
	
	for(int i=0; i<n; i++){
		x = rand()%100;
		cout<<x<<" ";
		a[i] = x;
	}
	cout<<endl;
	cout<<LIS(a)<<endl;
	displayLIS(a);
	return 0;
}

void display(vector<int> &v) {
	for (auto x : v)
		cout << x << " ";
	cout << endl;
}


int LIS(vector<int> &a) {
	int n = a.size();
	int max;
	vector<int> lis(n, 1);
	for (int i = 1; i<n; i++) {
		max = 0;
		for (int j = 0; j<i; j++) {
			if (a[i]>a[j] && lis[j] > max) {
				max = lis[j];
			}
		}
		lis[i] = max + 1;
	}
	return *max_element(lis.begin(), lis.end());
}

int LIS1(vector<int> &a, vector<int>&lis, vector<int> &p) {
	int n = a.size();
	stack<int> s;
	int max, k;
	for (int i = 1; i<n; i++) {
		max = 0; k = -1;
		for (int j = 0; j<i; j++) {
			if (a[i]>a[j] && lis[j] > max) {
				max = lis[j];
				k = j;
			}
		}
		p[i] = k;
		lis[i] = max + 1;
	}
	return *max_element(lis.begin(), lis.end());
}

void displayLIS(vector<int> &a) {
	int n = a.size();
	stack<int> s;
	int max, k;
	vector<int> p(n, -1);
	vector<int> lis(n, 1);
	max = LIS1(a, lis, p);
	for (int i = n - 1; i >= 0; i--)if (lis[i] == max) { k = i; s.push(a[k]); break; }
	while (p[k] >= 0) { k = p[k]; s.push(a[k]); }
	while (!s.empty()) { cout << s.top() << " "; s.pop(); }
	cout << endl;
}
