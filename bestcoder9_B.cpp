/*
ID:esxgx1
LANG:C++
PROG:bestcoder9_B
*/
#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
using namespace std;

int a[1007];

int main(void)
{
	#ifndef ONLINE_JUDGE
	freopen("in.txt", "r", stdin);
	#endif
	int T;
	scanf("%d", &T);

	while(T) {
		int N;
		scanf("%d", &N);

		int ans = 1;		// no
		for(int i=0; i<N; ++i)
			scanf("%d", &a[i]);

		for(int i=N-1; i>=0; --i) {
			if (ans) ans = 0;		// no->yes
			else {
				if (a[i] > 1) ans = 0;	// yes -> yes
				else ans = 1;		// yes -> no
			}
		}
		printf(ans ? "No\n" : "Yes\n");
		--T;
	}
	return 0;
}
