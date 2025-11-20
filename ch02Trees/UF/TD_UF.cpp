#include<iostream>
#include<fstream>
#include<vector>
using namespace std;

class wQuickUnionUF{
	private:	
		vector<int> id; // access to component id
		vector<int> sz; // size of component for roots
		vector<int> rank; //height of component for roots
		int Nc;//nb of components
	public:
		//initialize union-find data structure with N singleton objects (0 to N – 1)
		wQuickUnionUF(int N){
			id.assign(N,0); for(int i=0; i<N; i++) id[i] = i;
			sz.assign(N,1);
			rank.assign(N,0);
			Nc = N;
		}

		//are p and q in the same component?
		bool connected(int p, int q){return find(p) == find(q);}

		//component identifier for i (0 to N – 1)
		int find(int i){ // Follow links to find a root.
			while(i != id[i])	i = id[i];
			return i;
		}

		int findcomp(int i){ 
			// Follow links to find a root.
			while(i != id[i]){
				id[i] = id[id[i]];	
				i = id[i];
			}
			return i;
		}

		//add connection between p and q
		void Union(int p, int q){
			int i = find(p);
			int j = find(q);
			if(i == j) return; //if connected 
			if(rank[i] > rank[j]){ id[j] = i; sz[i] += sz[j];}
			else { 
				id[i] = j; sz[j] += sz[i];
				if(rank[i]==rank[j])
					rank[j]++;
			}
			Nc--;
		}
		int nc(){return Nc;}
		int size(int i){return sz[find(i)];}
		int Rank(int i){return rank[i];}
		int largestSet(){
			int max=0;
			for(int i=0; i<sz.size();i++)
				if(sz[i]>max)
					max=sz[i];
			return max;
		}
};


int main(){
	int N=10, p, q;
	ifstream fin;
	wQuickUnionUF uf(N);
	fin.open("in_UF.txt");
	if(!fin){cerr<<"Error"<<endl; return 1;};
	while(fin>>p>>q){ // Read from file pair to connect.
		if(uf.connected(p,q)) {cout<<p<<" and "<<q<<" already connected"<<endl;continue;} // Ignore if connected
		uf.Union(p,q); // Combine components
		cout<<p<<" "<<q<<" now connected"<<endl;
		cout<<"Nc: "<<uf.nc()<<endl;
		cout<<"size of component "<<p<<": "<<uf.size(p)<<endl;
		cout<<"id of "<<p<<": "<<uf.find(p)<<endl;
	}
	cout<<"---"<<endl;
	cout<<"Nc total: "<<uf.nc()<<endl;
	cout<<"i id size rank"<<endl;
	for(int i=0; i<N; i++){
		cout<<i<<": "<<uf.find(i)<<" "<<uf.size(i)<<" "<<uf.Rank(i)<<endl;
	}
	cout<<"largest Set size: "<<uf.largestSet()<<endl;
	return 0;
}


