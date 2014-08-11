/*
ID:esxgx1
LANG:C++
PROG:hdu1008
*/
#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
using namespace std;

int main(void)
{
	#ifndef ONLINE_JUDGE
	freopen("in.txt", "r", stdin);
	#endif

	int N;
	while(scanf("%d", &N), N) {
		int p, ctime;
		ctime = p = 0;
		int a;
		for(int i=0; i<N; ++i) {
			scanf("%d", &a);
			if (p < a) ctime += 6 * (a-p);
			else if (p > a) ctime += 4 * (p - a);
			p = a;
		}
		printf("%d\n", ctime + 5*N);
	}
	return 0;
}
