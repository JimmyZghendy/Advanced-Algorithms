#include<iostream>
using namespace std;

#include "QuickUnionUF.h"

int main(){
	int N, p, q;

	cout<<"Input N: "; cin>>N;

	QuickUnionUF uf(N);
	cout<<"Input (p,q): "<<endl;
	while(cin>>p>>q){ // Read pair to connect.
		if(uf.connected(p,q)) continue; // Ignore if connected
		uf.Union(p,q); // Combine components
		cout<<p<<""<<q<<" now connected"<<endl;
	}
	//cout<<uf.count()<<" component"<<endl;

	return 0;
}
