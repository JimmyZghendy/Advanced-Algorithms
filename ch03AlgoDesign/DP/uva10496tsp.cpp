// Collecting Beepers uva10496
// DP TSP
#include<iostream>
#include <algorithm>
#include <cmath>
#include <string>
#include<vector>
#include<fstream>
using namespace std;




int tsp(int pos, int bitmask, int n, vector<vector<int>>& dist, vector <vector<int>>& memo);

int main() {
	ifstream fin;
	int xsize, ysize, x0, y0, n;//n: nb of beepers, we will add 1 for the start point
	vector<int> x, y;
	vector <vector<int>> memo, dist;
	int TC;

	fin.open("Solutions/ch03AlgoDesign/DP/uva10496TSP.txt");
	if (!fin) { cerr << "Error" << endl; exit(1); }
	fin>>TC;
	while (TC--) {
		fin>>xsize>>ysize; // these two values are not used
		fin>>x0>>y0;
		fin>>n;
		dist.assign(n+1, vector<int>(n+1,0));
		memo.assign(n + 1, vector<int>(1<<(n + 1), -1));
		x.assign(n+1, 0), y.assign(n+1, 0);
		x[0] = x0, y[0] = y0;
		for (int i = 1; i <= n; i++) // karel's position is at index 0
			fin>>x[i]>>y[i];

		for (int i = 0; i <= n; i++) // build distance table
			for (int j = 0; j <= n; j++)
				dist[i][j] = abs(x[i] - x[j]) + abs(y[i] - y[j]); // Manhattan distance

		cout<<"The shortest path has length: "<<tsp(0, 1,n,dist,memo)<<endl; // DP-TSP
	}

	return 0;
}

int tsp(int pos, int bitmask, int n, vector<vector<int>>&dist, vector<vector<int>>&memo) { // bitmask stores the visited coordinates
	if (bitmask == (1 << (n + 1)) - 1) return dist[pos][0]; // return trip to close the loop
	if (memo[pos][bitmask] != -1) return memo[pos][bitmask];
	int ans = 2000000000;//INF
	for (int nxt = 0; nxt <= n; nxt++) // O(n) here
		if (nxt != pos && !(bitmask & (1 << nxt))) // if coordinate nxt is not visited yet
			ans = min(ans, dist[pos][nxt] + tsp(nxt, bitmask | (1 << nxt),n,dist,memo));
	return memo[pos][bitmask] = ans;
}
