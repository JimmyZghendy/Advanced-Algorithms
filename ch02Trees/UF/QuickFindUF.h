#ifndef QuickFindUF_H
#define QuickFindUF_H

#include<vector>
using namespace std;

class QuickFindUF{
	private:
		// access to component id (site indexed)
		vector<int> id; 

	public:
		//initialize union-find data structure with N singleton objects (0 to N – 1)
		QuickFindUF(int N):id(N){
			for(int i=0; i<N; i++)
				id[i] = i;
		}

		//are p and q in the same component?
		bool connected(int p, int q){
			return find(p) == find(q);
		}

		//component identifier for p (0 to N – 1)
		int find(int p){ return id[p];}

		//add connection between p and q
		void Union(int p, int q){
			int pid = id[p];
			int qid = id[q];
			for(int i=0; i<id.size();i++)
				if(id[i] == pid) id[i] = qid;
		}

};
#endif

