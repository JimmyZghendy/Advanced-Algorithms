#include<iostream>
#include<vector>
#include<ctime>
#include<algorithm>
#include<functional>
using namespace std;

int main(){
	vector<vector<int>> a;
	int m=4, n=3;

	a.assign(n,vector<int>(m,0));

	for(int i=0; i<a.size(); i++){
		for(int j=0; j<a[i].size(); j++)
			cout<<a[i][j]<<" ";
		cout<<endl;
	}


	return 0;
}