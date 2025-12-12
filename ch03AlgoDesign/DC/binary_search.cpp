#include<iostream>
#include<vector>
#include<algorithm>
#include<ctime>
#include<fstream>
using namespace std;

bool binarySearch(vector<int> v, int lo, int hi, int x);

bool binarySearch(vector<int> v, int x);
void binarySearch_driver();

int main(){
	binarySearch_driver();
	return 0;
}

void binarySearch_driver(){
	int n=10, x;
	vector<int> v;

	srand(time(0));
	for(int i=0; i<n; i++){
		x = rand()%20;
		v.push_back(x);
		cout <<x <<" ";
	}
	cout<<endl;
	sort(v.begin(),v.end());
	x = 10;

	if(binarySearch(v,x)) cout<<x<<" Found"<<endl;
	else cout<<x<<" not Found"<<endl;

}

bool binarySearch(vector<int> v, int lo, int hi, int x){
	int mid;
	while(lo<=hi){
		mid = (lo + hi) / 2;
		if(x < v[mid]){
			hi = mid - 1; 		
		}else if (x > v[mid]){
			lo = mid + 1; 
		} else{
			if(x == v[mid]) return true;
		}
	}
	return false;
}


bool binarySearch(vector<int> v, int x){
	int lo = 0, hi = v.size()-1, mid;
	while(lo<=hi){
		mid = (lo + hi) / 2;
		if(x < v[mid]){
			hi = mid - 1; 		
		}else if (x > v[mid]){
			lo = mid + 1; 
		} else{
			if(x == v[mid]) return true;
		}
	}
	return false;
}