#include<iostream>
#include<vector>
using namespace std;

#define INF 99999

int coinChange(vector<int>& change, int V, vector<int>& c, vector<int>& a);
int minChange(int value, vector<int>& change, int V,  vector<int>& c, vector<int>& a);
void coinsValue(int value, vector<int>& a);
/*
int coinChange(int* change, int V, int* c, int n);
int minChange(int value, int* change, int V,  int* c, int n);
*/

int main(){
	int V = 38;
	vector<int> change(V+1,0);
	int C[]={1,3,4,5};
	int n = sizeof(C)/sizeof(int);
	vector<int> c(C,C+n);
	vector<int> a(V+1,0);
	cout<<"min nb of "<<V<<" coin change: "<<coinChange(change,V,c,a)<<endl;
	cout<<"all min nb of coin change: "<<endl;
	for(int i=0; i<=V; i++)
		cout<<i<<" "<<change[i]<<endl;
	cout<<"Coins value for value: "<<V<<": ";
	coinsValue(V,a);
	cout<<endl;
	return 0;
}


int coinChange(vector<int>& change, int V, vector<int>& c, vector<int>& a){
	change[0]=0;
	for(int i=1; i<=V; i++)
		change[i]=1+minChange(i,change,V,c,a);
	return change[V];
}

int minChange(int value, vector<int>& change, int V,  vector<int>& c, vector<int>& a){
	int min=INF, x, coin;
	for(int i=0; i<c.size(); i++){
		if(value-c[i]==0) x = 0;
		else if(value-c[i]<0) x = INF;
		else x = change[value-c[i]]; 

		if(x<min){
			min=x;
			coin = c[i];
		}
	}
	a[value]=coin;
	return min;
}

void coinsValue(int value, vector<int>& a){
	if(value == 0) return;
	cout<<a[value]<<" ";
	coinsValue(value-a[value],a); 	
}

/*
int coinChange(int* change, int V, int* c, int n){
	change[0]=0;
	for(int i=1; i<=V; i++)
		change[i]=1+minChange(i,change,V,c,n);
	return change[V];
}

int minChange(int value, int* change, int V,  int* c, int n){
	int min=INF, x;
	for(int i=0; i<n; i++){
		if(value-c[i]==0) x = 0;
		else if(value-c[i]<0) x = INF;
		else x = change[value-c[i]];
		if(x<min)
			min=x;
	}
	return min;
}
*/

