/*
ID:esxgx1
LANG:C++
PROG:hdu4055
*/
#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
using namespace std;

int dp[1024][1024];

#define MOD	1000000007

int main(void)
{
	#ifndef ONLINE_JUDGE
	freopen("in.txt", "r", stdin);
	#endif

	char s[1024];
	while(scanf("%s", s) > 0) {
		int len = strlen(s);
		dp[0][0] = 1;
		for(int i = 0 ; i < len; ++i) {
			int i2 = i + 1;
			if (s[i] == 'D') {
					dp[i2][i2] = 0;
					for(int j = i2; j--; )
						dp[i2][j] = (dp[i2][j+1] + dp[i2-1][j]) % MOD;
			} else if (s[i] == 'I') {
					dp[i2][0] = 0;
					for(int j=1; j<=i2; ++j)
						dp[i2][j] = (dp[i2][j-1] + dp[i2-1][j-1]) % MOD;
			} else {
					int sum = 0;
					for(int k =0 ; k<i2; ++k) sum = (sum + dp[i2-1][k]) % MOD;
					for(int j=0; j<=i2; ++j)
						dp[i2][j] = sum;
			}
		}
		int sum = 0;
		for(int i=0; i<=len; ++i) sum = (sum + dp[len][i]) % MOD;
		printf("%d\n", sum);
	}
	return 0;
}
