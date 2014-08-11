/*
ID:esxgx1
LANG:C++
PROG:hdu4_A
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

	int T;
	scanf("%d", &T);
	while(T) {
		int a[6];
		scanf("%d%d%d%d%d%d", &a[0], &a[1], &a[2], &a[3], &a[4], &a[5]);
		sort(a, a+6, greater<int>());
		printf(a[0] + a[1] > a[2] + a[3] + a[4]?"Grandpa Shawn is the Winner!\n":"What a sad story!\n");
		--T;
	}
	return 0;
}
