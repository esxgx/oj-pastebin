/*
ID:esxgx1
LANG:C++
PROG:hdu4417
*/
#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
using namespace std;

#define MAXN	100007

int v[MAXN * 4];

#define recursive_def	int l, int r, int i
#define lsi		i<<1
#define rsi		i<<1 | 1
#define lsn		l, m, lsi
#define rsn		m+1, r, rsi
#define pushup	v[i] = v[lsi] + v[rsi];

void build(recursive_def)
{
	v[i] = 0;
	if (l == r) return;
	else {
		int m = (l+r) >> 1;
		build(lsn);
		build(rsn);
	}
}

void update(int x, recursive_def)
{
	if (l == r) v[i] += 1;
	else {
		int m = (l+r) >> 1;
		if (x <= m) update(x, lsn);
		else update(x, rsn);
		pushup
	}
}

int query(int L, int R, recursive_def)
{
	if (L <= l && r <= R) return v[i];
	int m = (l+r) >> 1;
	int rslt;
	if (L <= m) rslt = query(L, R, lsn);
	else rslt = 0;

	if (m < R) rslt += query(L, R, rsn);
	return rslt;
}

struct A{
	int x, h;
} brick[MAXN];

int cmp1(const A &a, const A &b)
{
	return a.h < b.h;
}

#define MAXM	100007

struct B{
	int L, R, H, d, cnt;
} qs[MAXM];

int cmp2(const B &a, const B &b)
{
	return a.H < b.H;
}

int cmp3(const B &a, const B &b)
{
	return a.d < b.d;
}

int main(void)
{
	#ifndef ONLINE_JUDGE
	freopen("in.txt", "r", stdin);
	#endif
	int T;
	scanf("%d", &T);
	for(int t=1; t<=T; ++t) {
		int N, M;
		printf("Case %d:\n", t);
		scanf("%d%d", &N, &M);
		for(int i=0; i<N; ++i) {
			scanf("%d", &brick[i].h);
			brick[i].x = i;
		}
		sort(brick, brick + N, cmp1);
		for(int i=0; i<M; ++i) {
			scanf("%d%d%d", &qs[i].L, &qs[i].R, &qs[i].H);
			qs[i].d = i;
		}
		sort(qs, qs+M, cmp2);
		build(0, N-1, 1);
		int bb = 0;
		for(int i=0; i<M; ++i) {
			while(brick[bb].h <= qs[i].H) {
				update(brick[bb].x, 0, N-1, 1);
				if (++bb >= N) break;
			}
			qs[i].cnt = query(qs[i].L, qs[i].R, 0, N-1, 1);
		}
		sort(qs, qs+M, cmp3);
		for(int i=0; i<M; ++i)
			printf("%d\n", qs[i].cnt);
	}
	return 0;
}
