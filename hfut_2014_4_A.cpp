#include <cstdio>
#include <cstring>
using namespace std;

#define NN	1003
#define MOD	10007

int dp[NN][NN];

int main()
{
	int T, nCase = 0;
	char s[NN];
	scanf("%d",&T);
	while(T) {
		scanf("%s",s);
		int len=strlen(s);
		for(int i=0; i<len; ++i) {
			int j = 0;
			for(; j<i; ++j) dp[i][j] = 0;
			dp[i][j++] = 1;
			for(; j<len; ++j) dp[i][j] = 0;
		}
		for(int i=0; i<len; ++i)
			for(int j=i-1; j>=0; --j) {
				dp[j][i] = (dp[j][i-1] + dp[j+1][i] - dp[j+1][i-1] + MOD) % MOD;
				if(s[i] == s[j]) dp[j][i] = (dp[j][i] + dp[j+1][i-1] + 1 + MOD) % MOD;
			}
		printf("Case %d: %d\n", ++nCase, dp[0][len-1]);
		--T;
	}
	return 0;
}
