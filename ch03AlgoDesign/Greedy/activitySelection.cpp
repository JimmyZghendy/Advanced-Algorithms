#include<iostream>
#include<algorithm>
#include<vector>
#include<fstream>
using namespace std;

typedef pair<int,int> ii;
bool comp(ii &p1, ii & p2){
    return p1.second<p2.second;
}

int main(){
    ifstream fin;
    vector<ii> v;
    vector<ii> res;
    int n, start, finish;
    fin.open("Solutions/ch03AlgoDesign/Greedy/in_activitySelection.txt");
	if(!fin){cerr<<"Error"<<endl; return 1;}
    fin>>n;
    for(int i=0; i<n; i++){
        fin>>start>>finish;
        v.push_back(make_pair(start,finish));
	}
    sort(v.begin(),v.end(),comp);

    res.push_back(v[0]);
	finish = v[0].second;
    for(int i=1; i<v.size();i++){
        if(v[i].first >= finish){
            finish = v[i].second;
            res.push_back(v[i]);
		}  
	}
    cout<<"Result"<<endl;
    for(auto x: res){
        cout<<x.first<<" "<<x.second<<endl;
	}
    cout<<"Count: "<<res.size()<<endl;
    return 0;
}

