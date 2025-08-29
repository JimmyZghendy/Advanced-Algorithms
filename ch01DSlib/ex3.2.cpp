/*
ex3
2.	Write a program that reads the numbers in text file in_ex3.txt (shown below) and put them in a matrix (vector of vectors, or list of vectors). Note that, the first number indicate the number of vectors to store. Then, in each line, the first number indicate the number of numbers in each vector. The following is the in_ex3.txt file:
4
5 2 4 6 8 10
3 1 3 5
3 12 14 16
4 7 9 11 13
*/


#include<iostream>
#include<vector>
#include<ctime>
#include<algorithm>
#include<functional>
#include<fstream>
using namespace std;

int main() {
	vector<vector<int>> a;
	vector<vector<int>> A;
	ifstream fin;
	int n, nb, x, k=0;
	vector<int> v;
	fin.open("Solutions/ch01DSlib/in_ex3.txt");//adapt this path according to the place of your file
	if (!fin) { cerr << "Error" << endl; exit(1); }
	fin >> n;
	a.assign(n, vector<int>());

	while (!fin.eof()) {
		fin >> nb;
		for (int i = 1; i <= nb; i++) {
			fin >> x;
			v.push_back(x);
			a[k].push_back(x);//2nd method
		}
		k++;
		A.push_back(v);

		v.clear();
	}

	cout << a.size() << endl;
	cout << a[0].size() << endl;
	for (int i = 0; i < a.size(); i++) {
		for (int j = 0; j < a[i].size(); j++) {
			cout << a[i][j]<<" ";
		}
		cout << endl;
	}
	//2nd method
	cout << "---" << endl;
	cout << A.size() << endl;
	cout << A[0].size() << endl;
	for (int i = 0; i < A.size(); i++) {
		for (int j = 0; j < A[i].size(); j++) {
			
			cout << A[i][j] << " ";
		}
		cout << endl;
	}

	return 0;
}