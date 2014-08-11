/*
ID:esxgx1
LANG:C++
PROG:4_K
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
		int N, M;
		scanf("%d%d", &N, &M);
		int a;
		for(int i=0; i<N; ++i)
			for(int j=0; j<M; ++j)
				scanf("%d", &a);
		printf(a?"Alice\n":"Bob\n");
		--T;
	}
	return 0;
}
