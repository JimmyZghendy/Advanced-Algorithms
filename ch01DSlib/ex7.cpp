#include<iostream>
using namespace std;
#include<bitset>


#define M 32

int main(){
	bitset<M> bs1;
	bitset<M> bs2(20);
	bitset<M> bs3("1100");

	cout<<bs1<<endl;
	cout<<bs2<<endl;
	cout<<bs3<<endl;

	bitset<8> s;
	s[1]=1; s[4]=1; //s.set(1); s.set(4);
	cout<<s<<endl;

	cout<<"nb of set bits: "<<s.count()<<endl;
	cout<<"nb of unset bits: "<<s.size()-s.count()<<endl;
	
	for(int i=0; i<s.size(); i++){
		cout<<s[i]<<" ";
	}
	cout<<endl;

	if(s.any()) cout<<"At least one bit is set to 1"<<endl;
	else cout<<"No bit is set to 1"<<endl;

	if(s.all()) cout<<"All bits are sets"<<endl;
	else cout<<"Not all bits are sets"<<endl;

	cout<<"Setting all bits to 1..."<<endl;
	s.set();
	cout<<s<<endl;

	if(s.all()) cout<<"All bits are sets"<<endl;
	else cout<<"Not all bits are sets"<<endl;

	s.set(4,0); //s[4]=0;
	cout<<"Unsetting all bits"<<endl;
	s.reset();
	cout<<s<<endl;

	if(s.any()) cout<<"At least one bit set"<<endl;
	else cout<<"No bit is set"<<endl;

	cout<<"Flipping all bits..."<<endl;
	s.flip();
	cout<<s<<endl;
	int num = 35;
	bitset<8> bs4(num);
	cout<<num<<" = "<<bs4<<endl;//bitset<8>(num)




	return 0;
}