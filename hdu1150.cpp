/*
ID:esxgx1
LANG:C++
PROG:hdu1150
*/
#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
using namespace std;

#define MAXN	107
#define MAXM	107

int N, M;
int visited[MAXM];
int matched[MAXM];


int e[MAXN][MAXN];

int aug(int i)
{
	for(int j=0; j<M; ++j) {
		if (e[i][j] && !visited[j]) {
			visited[j] = 1;
			if (matched[j] < 0 || aug(matched[j])) {
				matched[j] = i;
				return 1;
			}
		}
	}
	return 0;
}

int main(void)
{
	#ifndef ONLINE_JUDGE
	freopen("in.txt", "r", stdin);
	#endif

	int K;
	while(scanf("%d%d%d", &N, &M, &K) >= 3) {
		memset(e, 0, sizeof(e));
		for(int i=0; i<K; ++i) {
			int _, x, y;
			scanf("%d%d%d", &i, &x, &y);
			if (x > 0 && y > 0) e[x][y] = 1;
		}
		memset(matched, -1, sizeof(matched));
		// hungrian method
		int m = 0;
		for(int i=0; i<N; ++i) {
			m += aug(i);
			memset(visited, 0, sizeof(visited));
		}
		printf("%d\n", m);
	}
	return 0;
}
