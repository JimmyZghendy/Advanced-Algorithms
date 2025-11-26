#include<iostream>
#include<fstream>
#include<vector>
using namespace std;
typedef pair<int,int> ii;

class wQuickUnionUF{
	private:	
		vector<int> id; // access to component id
		vector<int> sz; // size of component for roots
	public:
		//initialize union-find data structure with N singleton objects (0 to N – 1)
		wQuickUnionUF(int N){
			id.assign(N+1,0);
			sz.assign(N+1,1);
			for(int i=1; i<=N; i++) id[i] = i;
			for(int i=1; i<=N; i++) sz[i] = 1;
		}

		//are p and q in the same component?
		bool connected(int p, int q){return find(p) == find(q);}

		//component identifier for i (1 to N)
		int find(int i){ // Follow links to find a root.
			while(i != id[i])	i = id[i];
			return i;
		}

		//add connection between p and q
		void Union(int p, int q){
			int i = find(p);
			int j = find(q);
			if(i == j) return;
			if(sz[i] < sz[j]){ id[i] = j; sz[j] += sz[i];}
			else             { id[j] = i; sz[i] += sz[j];}
		}

		void display(){
			for(int i=1; i<id.size(); i++){
				cout<<i<<" ";
			}
			cout<<endl;
			for(int i=1; i<id.size(); i++){
				cout<<sz[i]<<" ";
			}
			cout<<endl;
			for(int i=1; i<id.size(); i++){
				cout<<id[i]<<" ";
			}
			cout<<endl;
		}


		ii largestGroup(){
			int max = -1;
			int idmax;
			ii p;
			for(int i=1; i<id.size(); i++){
				if(sz[i]>max){
					max = sz[i];
					idmax = i;
				}
			}
			p.first = max;
			p.second = idmax;
			return p;
		}
		void displayLargestGroup(){
			ii p = largestGroup();
			cout<<"Size of the largest group: "<<p.first<<endl;
			cout<<"The largest group: ";
			for(int i=1; i<id.size(); i++){
				if(p.second == find(i))
					cout<<i<<" ";
			}
			cout<<endl;
		}
};

int main(){
	int N,M, p, q, c;
	ifstream fin;
	fin.open("in_uva10608.txt");
	if(!fin){cerr<<"Error"<<endl; return 1;};
	fin>>c;
	while(c--!=0){
		fin>>N>>M;
		wQuickUnionUF uf(N);
		for(int i=0; i<M; i++){
			fin>>p>>q;
			if(uf.connected(p,q)) {cout<<p<<" and "<<q<<" already connected"<<endl;continue;} // Ignore if connected
			uf.Union(p,q); // Combine components
			cout<<p<<" "<<q<<" now connected"<<endl;
		}
		uf.display();
		uf.displayLargestGroup();
		cout<<"---"<<endl;
	}

	

	return 0;
}
