/*
ID:esxgx1
LANG:C++
PROG:vijos1551
*/
#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
using namespace std;

#define NN		207
int dp[NN*NN];

struct tt{
	int a, b;
}t[NN];

int cmp(const tt &a, const tt &b)
{
    return a.b > b.b;
}

int main(void)
{

	#ifndef ONLINE_JUDGE
	freopen("in.txt", "r", stdin);
	#endif
	int N;
	while(scanf("%d", &N) > 0) {

		int sa = 0;		// 总打饭时间
		for(int i=1; i<=N; ++i) {
			scanf("%d%d", &t[i].a, &t[i].b);
			sa += t[i].a;
		}
		sort(t+1, t+N+1, cmp);
		memset(dp, 0, sizeof(int)*(sa+1));
		sa = 0;
		for(int i=1; i<=N; ++i) {
			#define a	t[i].a
			#define b	t[i].b
			sa += a;
			for(int j=sa; j>=0; --j) {
				if (j>=a&&sa-j>=a)
					dp[j] = min(max(dp[j-a], j+b), max(dp[j], sa-j+b));
				else if (j>=a) dp[j] = max(dp[j-a], j+b);
				else if (sa-j >= a) dp[j] = max(dp[j], sa-j+b);
				else dp[j] = 0x3f3f3f3f;
				//printf("%d %d %d(%d)\n", i, j, dp[i][j], sa-j + b);
			}
		}
		int minn = dp[0];
		for(int j=sa; j>1; --j)
			if (dp[j] < minn) minn = dp[j];
		printf("%d\n", minn);
	}
	return 0;
}
