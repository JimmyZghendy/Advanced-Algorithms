/* UVa 11450 - Wedding Shopping - Top Down */
// this code is similar to recursive backtracking code
// parts of the code specific to top-down DP are commented with: `TOP-DOWN'
// if these lines are commented, this top-down DP will become backtracking!
#include<iostream>
using namespace std;
#include <algorithm>
#include <cstdio>
#include <cstring>
using namespace std;

/*
int M, C, price[25][25];                 // price[g (<= 20)][model (<= 20)]
int memo[210][25];    // TOP-DOWN: dp table memo[money (<= 200)][g (<= 20)]
*/
/*
const int M=12, C=3; 
int price[C][5]={3, 6, 4 , 8, 0,
				 2, 5, 10, 0, 0,
				 4, 1, 5, 3, 5};                 				 
int memo[M+1][C+1];   
*/

const int M=100, C=4; 
int price[C][5]={3, 8, 6 , 4, 0,
				 2, 5, 10, 0, 0,
				 4, 1, 3, 3, 7,
				 4, 50, 14, 23, 8};                 				 
int memo[M+1][C+1]; 

int shop(int money, int g) {//TOP-DOWN
  if (money < 0) return -1000000000;     // fail, return a large -ve number
  if (g == C) return M - money;        // we have bought last garment, done
  if (memo[money][g] != -1) return memo[money][g]; // TOP-DOWN: memoization
  int ans = -1;   // start with a -ve number as all prices are non negative
  for (int model = 1; model <= price[g][0]; model++)      // try all models
    ans = max(ans, shop(money - price[g][model], g + 1));
  return memo[money][g] = ans; // TOP-DOWN: assign ans to table + return it
}



int shop1(int money, int g) {//TOP-DOWN
  if (money < 0) return -1000000000;
  if (g == C) return M - money; //expenses
  int &ans = memo[money][g];                 // remember the memory address
  if (ans != -1) return ans; //memo init to -1
  for (int model = 1; model <= price[g][0]; model++)
    ans = max(ans, shop1(money - price[g][model], g + 1));
  return ans;                // ans (or memo[money][g]) is directly updated
}

int shop0(int money, int g) {//Complete search
  if (money < 0) return -1000000000;
  if (g == C) return M - money; //expenses
  int ans = -1000000000;                 
  for (int model = 1; model <= price[g][0]; model++)
    ans = max(ans, shop0(money - price[g][model], g + 1));
  return ans;                
}


void print_shop(int money, int g) { // this function does not return anything
  if (money < 0 || g == C) return;                      // similar base cases
  for (int model = 1; model <= price[g][0]; model++)   // which model is opt?
    if (shop(money - price[g][model], g + 1) == memo[money][g]) { // this one
      cout<<price[g][model]<<" - ";
      print_shop(money - price[g][model], g + 1); // recurse to this one only
      break;
}   }



int main() {            // easy to code if you are already familiar with it
 int score;
/*	
int i, j, TC, score;
  cout<<"Input TC:"; 
  cin>>TC;
  while (TC--) {
	cout<<"Input M and C: ";
	cin>>M>>C;
    for (i = 0; i < C; i++) {
		cin>>price[i][0]; // store K in price[i][0]
      for (j = 1; j <= price[i][0]; j++) cin>>price[i][j]; 
    }

    memset(memo, -1, sizeof memo);    // TOP-DOWN: initialize DP memo table
    score = shop(M, 0);                            // start the top-down DP
    if (score < 0) cout<<"no solution\n";
    else           cout<<score<<endl;
} 
*/
   memset(memo, -1, sizeof memo);
    score = shop(M, 0);                            
    if (score < 0) cout<<"no solution\n";
    else           cout<<score<<endl;
	print_shop(M, 0);
} // return 0;

