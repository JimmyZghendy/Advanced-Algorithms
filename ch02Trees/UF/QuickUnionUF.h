#ifndef QuickUnionUF_H
#define QuickUnionUF_H

#include<vector>
using namespace std;

class QuickUnionUF{
	private:
		// access to component id (site indexed)
		vector<int> id; 

	public:
		//initialize union-find data structure with N singleton objects (0 to N – 1)
		QuickUnionUF(int N):id(N){
			for(int i=0; i<N; i++)
				id[i] = i;
		}

		//are p and q in the same component?
		bool connected(int p, int q){
			return find(p) == find(q);
		}

		//component identifier for i (0 to N – 1)
		int find(int i){ 
			while(i != id[i])	i = id[i];
			return i;
		}

		//add connection between p and q
		void Union(int p, int q){
			int i = find(p);
			int j = find(q);
			id[i] = j;
		}

};
#endif

