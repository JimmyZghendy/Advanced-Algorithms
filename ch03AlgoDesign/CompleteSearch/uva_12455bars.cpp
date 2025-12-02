#include<iostream>
using namespace std;
#include<fstream>
#include<vector>
//Subset Sum Problem
bool allSubsetsSum(int X, vector<int> &v);
bool allSubsetsSum(int X, vector<int> &v, vector<int> &result);
void display(vector<int>& v);
int main(){
	fstream fin;
	int t; // nb of test cases
	int n; //length of the bar
	int p; //nb of bars
	vector<int> v;
	vector<int> result;

	fin.open("ch04algoDesign/GreedyDC/in_uva12455.txt");
	if(!fin){cerr<<"Error"<<endl; return 1;}
	fin>>t;
	while(t--){
		fin>>n>>p;
		v.assign(p,0);
		for(int i=0; i<p; i++)
			fin>>v[i];
		if(allSubsetsSum(n,v,result)) {cout<<"YES:";display(result);result.clear();}
		else cout<<"NO"<<endl;
	}
	return 0;
}

bool allSubsetsSum(int X, vector<int> &v, vector<int> &result){
	int N = v.size();
	int sum ;
	for(int k=0; k<(1<<N); k++){
		sum = 0;
		for(int i=0; i<N; i++) 
			if(k & (1<<i)){
				sum+=v[i];
				result.push_back(v[i]);
			}
		if(sum == X) return true;
		else {result.clear();}
	}
	return false;
}

bool allSubsetsSum(int X, vector<int> &v){
	int N = v.size();
	int sum ;
	for(int k=0; k<(1<<N); k++){
		sum = 0;
		for(int i=0; i<N; i++) 
			if(k & (1<<i))
				sum+=v[i];
		if(sum == X) return true;
	}
	return false;
}

void display(vector<int>& v){
	for(auto x: v){
		cout<<x<<" ";
	}
	cout<<endl;
}