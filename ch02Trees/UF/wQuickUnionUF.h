#ifndef wQuickUnionUF_H
#define wQuickUnionUF_H

#include<vector>
using namespace std;

class wQuickUnionUF{
	private:	
		vector<int> id; // access to component id
		vector<int> sz; // size of component for roots
	public:
		//initialize union-find data structure with N singleton objects (0 to N – 1)
		wQuickUnionUF(int N):id(N),sz(N){
			for(int i=0; i<N; i++) id[i] = i;
			for(int i=0; i<N; i++) sz[i] = 1;
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
			if(i == j) return;
			if(sz[i] < sz[j]){ id[i] = j; sz[j] += sz[i];}
			else             { id[j] = i; sz[i] += sz[j];}
		}

};
#endif

