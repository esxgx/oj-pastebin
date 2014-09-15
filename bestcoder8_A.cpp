/*
ID:esxgx1
LANG:C++
PROG:bestcoder8_A
*/
#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
using namespace std;

int a[107];
long long b[107*107];

int main(void)
{
	#ifndef ONLINE_JUDGE
	freopen("in.txt", "r", stdin);
	#endif

	int N;
	while(scanf("%d", &N) > 0) {
		for(int i=0; i<N; ++i) scanf("%lld", &a[i]);
		int k = 0;
		for(int i=0; i<N; ++i)
			for(int j=i+1; j<N; ++j)
				b[k++] = a[i] + a[j];
		sort(b, b+k);
		int j = unique(b, b+k) - b;
		long long S = 0;
		for(int i=0; i<j; ++i)
			S += b[i];
		printf("%lld\n", S);
	}
	return 0;
}
