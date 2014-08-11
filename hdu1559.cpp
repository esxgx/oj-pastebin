/*
ID:esxgx1
LANG:C++
PROG:hdu1559
*/
#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
using namespace std;

int m[1007][1007];
long long sumx[1007], sumy[1007];
long long sum[1007][1007];

int main(void)
{
	#ifndef ONLINE_JUDGE
	freopen("in.txt", "r", stdin);
	#endif

	int T;
	int M, N, X, Y;
	scanf("%d", &T);
	while(T) {
		scanf("%d%d%d%d", &M, &N, &X, &Y);
		memset(sumx, 0, sizeof(sumy));
		memset(sum, 0, sizeof(sum));
		for(int i=0; i<M; ++i) {
			sumy[i] = 0;
			for(int j=0; j<N; ++j) {
				scanf("%d", &m[i][j]);
				sumy[i] += m[i][j], sumx[j] += m[i][j];
				sum[i+1][j+1] += sum[i][j] + sumy[i] + sumx[j] - m[i][j];

			}
		}
		long long maxx = -0x3f3f3f3f3f3f3f3fLL;
		for(int i=X-1; i<M; ++i) {
			for(int j=Y-1; j<N; ++j) {
				#define i	i+1
				#define j	j+1
				if (maxx < sum[i][j] - sum[i-X][j] - sum[i][j-Y] + sum[i-X][j-Y])
					maxx = sum[i][j] - sum[i-X][j] - sum[i][j-Y] + sum[i-X][j-Y];
				#undef i
				#undef j
			}
		}
		printf("%I64d\n", maxx);
		--T;
	}
	return 0;
}
