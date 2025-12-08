#include<iostream>
#include<vector>
#include<algorithm>
#include<ctime>
#include<fstream>
using namespace std;

int main(){
	ifstream fin;
	int N, M, price;//N: # books, M: amount of money
	vector<int> p;//prices of books
	pair<int,int> books;
	int a, b, diff;
	fin.open("Solutions/ch03AlgoDesign/DC/in_uva11057.txt");
	if(!fin){cerr<<"Error"<<endl; return 1;}
	while(fin>>N){
		for(int i=0; i<N; i++){
			fin>>price; p.push_back(price);
		}
		sort(p.begin(),p.end());
		fin>>M;
		diff = M;//init
		for(int i=0; i<N-1; i++){
			a = p[i];
			b = M-a;
			if(binary_search(p.begin()+i+1,p.end(),b))
				if(abs(a-b)<diff){
					diff = abs(a-b);
					books.first = a;
					books.second = b;
				}
			}
		cout<<"Peter should buy books whose prices are "<<books.first<<" and "<<books.second<<endl;
		p.clear();
	}

	return 0;
}

