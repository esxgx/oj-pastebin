/*
ID:esxgx1
LANG:C++
PROG:hdu3555
*/
#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
using namespace std;

#define LN	21
unsigned long long dp[LN + 1][3];

void work(int ln)
{
	dp[0][0] = 1;
	for(int i=1; i<=ln; ++i) {
		dp[i][0] = dp[i-1][0] * 9 + dp[i-1][1] * 8;	// 无49，开头无9
		dp[i][1] = dp[i-1][0] + dp[i-1][1];			// 无49, 开头是9
		dp[i][2] = dp[i-1][2] * 10 + dp[i-1][1];	// 有49
//		printf("i=%d, %I64u %I64u %I64u\n", i, dp[i][0], dp[i][1], dp[i][2]);
	}
}

unsigned long long solve(int i, unsigned long long N, int &extra)
{
	unsigned long long prefix = N/10;
	int curr = N % 10;
	int extra0 = extra;
	unsigned long long rslt = N % 10 * dp[i-1][2];
	if (curr >= 9 && prefix % 10 == 4) extra = 1;
	if (prefix) rslt += solve(i+1, prefix, extra0);
	if (extra0) {
			rslt += curr * (dp[i-1][0] + dp[i-1][1]);
			extra = 1;
	} else if (curr > 4) rslt += dp[i-1][1];
	return rslt;
}

int main(void)
{
	#ifndef ONLINE_JUDGE
	freopen("in.txt", "r", stdin);
	#endif
	int T;
	scanf("%d", &T);
	if (T) {
		work(LN);
		do {
			unsigned long long N;
			scanf("%I64d", &N);
			int extra = 0;
			printf("%I64d\n", solve(1, N, extra) + (extra ? 1 : 0));
			--T;
		}while(T);
	}
	return 0;
}
