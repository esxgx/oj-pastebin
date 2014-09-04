/*
ID:esxgx1
LANG:C++
PROG:hdu2089
*/
#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
using namespace std;

#define NN	9
unsigned dp[NN][4];

void work(int LN)
{
	dp[0][0] = 1;
	for(int i=1; i<=LN; ++i) {
		dp[i][0] = dp[i-1][0] * 9 - dp[i-1][1];						/// 无4和62的【含1】
		dp[i][1] = dp[i-1][0];										/// 开头是2的, 无62无4
		dp[i][2] = dp[i-1][2] * 10 + dp[i-1][0] + dp[i-1][1];		/// 有4或者62的
//		printf("%d 0=%d, 1=%d, 2=%d\n", i, dp[i][0], dp[i][1], dp[i][2]);
	}
}

unsigned solve(int i, int n, int &extra)
{
	unsigned curr = n % 10;
	unsigned rslt = curr * dp[i-1][2];
	int extra0 = extra;
	if (n/10) rslt += solve(i+1, n/10, extra0);
	if (extra0) {
		rslt += curr * dp[i-1][0];
		extra = 1;
	} else {
		if (curr > 4) rslt += dp[i-1][0];
		else if (curr == 4) extra = 1;

		if (n/10 % 10 > 6) rslt += dp[i][1];
		else if (n/10 % 10 == 6) {
			if (curr > 2) rslt += dp[i][1];
			else if (curr == 2) extra = 1;
		}
	}
	return rslt;
}

#define sol(n)	({int e=0; solve(1, n, e) + (e?1:0);})

int main(void)
{
	#ifndef ONLINE_JUDGE
	freopen("in.txt", "r", stdin);
	#endif
	work(NN);
	unsigned N, M;
	while(scanf("%u%u", &N, &M) > 0) {
		if (!(N || M)) break;
		int e0, e1;
		e0 = e1 = 0, N--;
		printf("%u\n", M - N - (sol(M) - sol(N)));
	}
	return 0;
}
