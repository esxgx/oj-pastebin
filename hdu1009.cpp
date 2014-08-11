/*
ID:esxgx1
LANG:C++
PROG:hdu1009
*/
#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
using namespace std;

struct room {
	int J, F;
	double r;
}rr[1007];

int cmp(const struct room &a, const struct room &b)
{
	if (!a.F) return 1;
	if (!b.F) return 0;
	return a.r > b.r;
}

#define eps		1e-7

int main(void)
{
	#ifndef ONLINE_JUDGE
	freopen("in.txt", "r", stdin);
	#endif
	double M;
	int N;
	while(({int Mo; scanf("%d%d", &Mo, &N); M = Mo; Mo != -1 || N != -1;})) {
		for(int i=0; i<N; ++i) {
			scanf("%d%d", &rr[i].J, &rr[i].F);
			if (rr[i].F) rr[i].r = (double)rr[i].J / rr[i].F;
		}
		sort(rr, rr+N, cmp);
		double J = 0;
		for(int i=0; i<N; ++i) {
			if (rr[i].F) {
				if (M < eps) break;
				J += rr[i].r * min((double)rr[i].F, M);
				M -= min((double)rr[i].F, M);
			} else J += rr[i].J;
		}
		printf("%.3f\n", J);
	}
	return 0;
}
