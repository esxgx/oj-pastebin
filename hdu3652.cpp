/*
ID:esxgx1
LANG:C++
PROG:hdu3652
*/
#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
using namespace std;

typedef long long LL;
#define LN		9
LL dp[LN + 1][13][3];


void work(void)
{
#define jj(k) dp[i+1][(jm + s[i]*k) % 13][0] += dp[i][jm][0], dp[i+1][(jm + s[i]*k) % 13][2] += dp[i][jm][2]
#define kk	dp[i+1][(jm + s[i] * 3) % 13][1] += dp[i][jm][0]
#define ll dp[i+1][(jm + s[i] * 1) % 13][2] += dp[i][jm][1]
	const LL s[] = {
		10, 100, 1000, 10000, 100000, 1000000, 10000000,
		100000000, 1000000000
	};
	dp[0][0][0] = 1;
	for(int i = 0; i<LN; ++i) {
		for(int jm = 0; jm < 13; ++jm) {
			jj(0), jj(1), jj(2), jj(3), jj(4),
			jj(5), jj(6), jj(7), jj(8), jj(9);
			kk, ll;
		}
	}
}

int solve(int i, int n, int mod, int &extra)
{
	int rslt, curr;
	curr = n % 10, rslt = 0;
	for(int k=0; k<curr; ++k) {
		rslt += dp[i-1][(mod - k * s[i]]
	}



}

int main(void)
{
	#ifndef ONLINE_JUDGE
	freopen("in.txt", "r", stdin);
	#endif
	work();
	int n;
	while(scanf("%d", &n) > 0) {
		int e, rslt;
		e = 0;
		rslt = solve(1, n, 0, e);
		printf("%d\n", rslt + e ? 1 : 0);
	}
	return 0;
}
