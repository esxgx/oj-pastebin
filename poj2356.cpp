/*
ID:esxgx1
LANG:C++
PROG:poj2356
*/
#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
using namespace std;

#define NN	10007

int _sum[NN], *sum = &_sum[1];

int main(void)
{
	#ifndef ONLINE_JUDGE
	freopen("in.txt", "r", stdin);
	#endif

	int N;
	scanf("%d", &N);
	sum[-1] = 0;
	for(int i=0; i<N; ++i) {
		int k;
		scanf("%d", &k);
		sum[i] = sum[i-1] + k;
//		printf("%d, %d\n", i, sum[i]);
		int j = i-1;
		for(; j >= 0; --j)
			if (!((sum[i] - sum[j-1]) % N) && (sum[i] - sum[j-1]) / N > 1) break;
		if (j >= 0) {
			while(j <= i) {
				printf("%d\n", sum[j] - sum[j-1]);
				++j;
			}
			break;
		}
	}
	return 0;
}
