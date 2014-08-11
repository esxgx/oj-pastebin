/*
ID:esxgx1
LANG:C++
PROG:hdu4348
*/
#include <cassert>
#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
using namespace std;

#define MAXM	200007
#define NN	10000007

int lsi[NN], rsi[NN], used;
long long tag[NN];
long long v[NN];

inline void clone(int t, int T)
{
//	assert(lsi[T] < used) ,assert(rsi[T] < used);
	lsi[t] = lsi[T], rsi[t] = rsi[T];
	tag[t] = tag[T]; v[t] = v[T];
}

#define pushdown(t)	if (tag[t] != 0) {\
	int nl, nr; \
	nl = used++, nr = used++;	\
	clone(nl, lsi[t]), clone(nr, rsi[t]);	\
	tag[nl] += tag[t]; tag[nr] += tag[t];	\
	v[nl] += tag[t] * (m-l+1);	\
	v[nr] += tag[t] * (r-m);	\
	lsi[t] = nl, rsi[t] = nr, tag[t] = 0;	\
}



#define pushup(t)	v[t] = v[lsi[t]] + v[rsi[t]];

int build(int l, int r)
{
	int t = used++;
	tag[t] = 0;
	if (l == r) {
		scanf("%I64d", &v[t]);
        lsi[t] = rsi[t] = 0;
	} else {
		int m = (l+r) >> 1;
		lsi[t] = build(l, m);
		rsi[t] = build(m+1, r);
		pushup(t)
		// printf("====%d %d %d\n", l, r, v[t]);
	}
	return t;
}

int rshift(int L, int R, int d, int l, int r, int T)
{
	int t = used++;
//	printf("=<>=%d %d %d\n", l, r, v[T]);
	if (L<=l && r<=R) {
		tag[t] = tag[T] + d;
		lsi[t] = lsi[T], rsi[t] = rsi[T];
		v[t] = v[T] + d * (long long)(r-l+1);
//		printf(">--<%d %d %lld %lld\n", l, r, tag[t], v[t]);
	} else {
//		assert(l<r);
        int m = (l+r) >> 1;
        clone(t, T);
		pushdown(t)
        if (L <= m) lsi[t] = rshift(L, R, d, l, m, lsi[t]);
        if (m < R) rsi[t] = rshift(L, R, d, m+1, r, rsi[t]);
        pushup(t)
//		printf("---<%d %d %lld %lld\n", l, r, v[t], tag[t]);

	}
	return t;
}


long long query(int L, int R, int l, int r, int T, long long tg)
{
//	printf("l %d r %d  %d 000\n", l, r, tag[T]);
	if (L <= l && r <= R) return v[T] + tg * (r-l+1);
	tg += tag[T];
	long long rslt = 0;
	int m = (l+r) >> 1;
	//pushdown(T)
	if (L <= m) rslt += query(L, R, l, m, lsi[T], tg);
	if (m < R) rslt += query(L, R, m+1, r, rsi[T], tg);
//	printf("l %d r %d %lld(%lld)\n", l, r, rslt, tag[T]);
	return rslt;
}

/*
long long query(int L, int R, int l, int r, int T, long long tg)
{
//	printf("l %d r %d  %d 000\n", l, r, tag[T]);
	if (L <= l && r <= R) return v[T];
	long long rslt = 0;
	int m = (l+r) >> 1;
	pushdown(T)
	if (L <= m) rslt += query(L, R, l, m, lsi[T], tg);
	if (m < R) rslt += query(L, R, m+1, r, rsi[T], tg);
	pushup(T)
	printf("l %d r %d %lld (%lld)\n", l, r, rslt, tag[T]);
	return rslt;
}*/


int T[MAXM];

int main(void)
{
	#ifndef ONLINE_JUDGE
	freopen("in.txt", "r", stdin);
	#endif

	int N, M, Case = 0;
	while(scanf("%d%d", &N, &M) > 0) {
		if (Case++) putchar('\n');
		used = 1;
		int t = 0;
		T[0] = build(1, N);
		for(;M; --M) {
			char type[4];
			int L, R, D;
            scanf("\n%s%d", type, &L);
            switch(type[0]) {
				case 'Q':
					scanf("%d", &R);
					printf("%I64d\n", query(L, R, 1, N, T[t], 0));
					break;
				case 'C':
					scanf("%d%d", &R, &D);
					T[t+1] = rshift(L, R, D, 1, N, T[t]);
					// printf("t=%d %d\n", t+1, T[t+1]);
					++t;
					break;
				case 'H':
					scanf("%d%d", &R, &D);
					printf("%I64d\n",query(L, R, 1, N, T[D], 0));
					break;
				case 'B':
					if (L < t) used = T[L + 1];
					t = L;
            }
		}
	}

	return 0;
}
