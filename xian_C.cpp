/*
ID:esxgx1
LANG:C++
PROG:xian_C
*/
#include <cmath>
#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
using namespace std;

#define NN		500007

int coloridx[NN], color[NN], ncolors;

int cpre[NN];				// 某个颜色上一次出现的位置
int clbck[NN];				// n颜色回溯

int _dp[NN+1], *dp = &_dp[1];

int main(void)
{
	#ifndef ONLINE_JUDGE
	freopen("in.txt", "r", stdin);
	#endif

	int N;
	while(scanf("%d", &N) > 0) {
		for(int i=0; i<N; ++i) {
			scanf("%d", &color[i]);
			coloridx[i] = color[i];
		}
		// 颜色离散化
		sort(color, color + N);
		ncolors = unique(color, color + N) - color;

		for(int i=0; i<N; ++i)
			coloridx[i] = lower_bound(color, color + ncolors, coloridx[i]) - color;


		memset(clbck, -1, sizeof(clbck));
		memset(cpre, -1, sizeof(cpre));

		clbck[1] = cpre[coloridx[0]] = 0;
		dp[0] = 1;

		for(int i=1; i<N; ++i) {
			dp[i] = 0x3f3f3f3f;
			if (cpre[coloridx[i]] != i-1) {
				if (cpre[coloridx[i]] < 0)	{	// 颜色没出现过
					for(int j = sqrt(N); j>0; --j) clbck[j+1] = clbck[j];
				} else {
					int j = sqrt(N) + 1;
					for(; j > 0 && (clbck[j] < 0 || clbck[j] <= cpre[coloridx[i]]); --j);
					for(--j; j > 0 && clbck[j] > cpre[coloridx[i]]; --j) clbck[j+1] = clbck[j];
				}
				clbck[1] = i;
			}
			for(int j = 1; clbck[j] >= 0; ++j) {
				dp[i] = min(dp[i], dp[clbck[j]-1] + j*j);
				//printf("(%d) j=%d %d [pre%d]\n", i+1, j, clbck[j]+1, cpre[coloridx[i]] + 1);
			}

			//printf("%d %d\n", i, dp[i]);
			cpre[coloridx[i]] = i;
		}
		printf("%d\n", dp[N-1]);

	}
	return 0;
}
