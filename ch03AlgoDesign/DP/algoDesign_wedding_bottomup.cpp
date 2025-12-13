/* UVa 11450 - Wedding Shopping - Bottom Up */
#include<iostream>
#include <cstdio>
#include <cstring>
using namespace std;

#define M 20
#define C 3
int price[C][5]={3, 4, 6 , 8, 0,
				 2, 5, 10, 0, 0,
				 4, 1, 3, 5, 5};                      
bool reachable[C][M+1];    


int shop(){
    for (int g = 1; g <= price[0][0]; g++)       // initial values (base cases)
      if (M - price[0][g] >= 0)      // to prevent array index out of bound
        reachable[0][M - price[0][g]] = true;  // using first garment g = 0

    for (int g = 1; g < C; g++)                   // for each remaining garment
      for (int money = 0; money < M; money++) if (reachable[g - 1][money]) // a reachable state
        for (int k = 1; k <= price[g][0]; k++) if (money - price[g][k] >= 0)
          reachable[g][money - price[g][k]] = true;   // also a reachable state

    for (int money = 0; money <= M; money++) 
		if(reachable[C - 1][money])
			return money; // the answer in here
	return -1;
}

void print_reachable(){
    for (int g = 0; g < C; g++) {                  
      for (int money = 0; money < M; money++) 
		  if (reachable[g][money]) 
			  cout<<"1";
		  else
			  cout<<"0";
	  cout<<endl;
	}
}

int main() {
  int score;
    memset(reachable, false, sizeof reachable);         // clear everything
	score = shop();
	print_reachable();
    if (score == -1) printf("no solution\n");         // last row has on bit
    else            printf("%d\n", M - score);
	return 0;
}  


/*
// same as above, but using space saving trick
#include <cstdio>
#include <cstring>
using namespace std;

int main() {
  int i, j, k, TC, M, C, cur;
  int price[25][25];
  bool reachable[2][210]; // reachable table[ONLY TWO ROWS][money (<= 200)]
  scanf("%d", &TC);
  while (TC--) {
    scanf("%d %d", &M, &C);
    for (i = 0; i < C; i++) {
      scanf("%d", &price[i][0]);
      for (j = 1; j <= price[i][0]; j++) scanf("%d", &price[i][j]);
    }

    memset(reachable, false, sizeof reachable);
    for (i = 1; i <= price[0][0]; i++)
      if (M - price[0][i] >= 0)
        reachable[0][M - price[0][i]] = true;

    cur = 1;                                      // we start with this row
    for (i = 1; i < C; i++) {
      memset(reachable[cur], false, sizeof reachable[cur]);    // reset row
      for (j = 0; j < M; j++) if (reachable[!cur][j])        // notice !cur
        for (k = 1; k <= price[i][0]; k++) if (j - price[i][k] >= 0)
          reachable[cur][j - price[i][k]] = true;
      cur = !cur;                                      // flip the two rows
    }

    for (j = 0; j <= M && !reachable[!cur][j]; j++);         // notice !cur

    if (j == M + 1) printf("no solution\n");         // last row has on bit
    else            printf("%d\n", M - j);
} } // return 0;

*/
