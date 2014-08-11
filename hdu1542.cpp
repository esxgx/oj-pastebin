/*
ID:esxgx1
LANG:C++
PROG:hdu1542
*/
#include <cstdio>
#include <cstring>
#include <deque>
#include <algorithm>
using namespace std;

#define eps		1e-5
#define NN	1007

struct rt{
	double x, y1, y2;
	int val;
};
rt rr[NN << 1];
double mapx[NN << 1], mapy[NN << 1];


#define MAXN	(NN << 1)

int cnt[MAXN * 4];
double sum[MAXN * 4];

#define recursive_def	int l, int r, int i
#define lsi			i<<1
#define rsi			i<<1 | 1
#define lsn			l, m, lsi
#define rsn			m, r, rsi

#define pushup		sum[i] = sum[lsi] + sum[rsi];

void build(recursive_def)
{
	cnt[i] = 0;
	sum[i] = 0;
	if (l == r) return;
	int m = (l+r) >> 1;
	build(lsn);
	if (l != m) build(rsn);
}

void update(int L, int R, int val, recursive_def)
{
	if (l + 1 == r) {
		if (L <= l && r <= R) {
			if (cnt[i] * (cnt[i] + val)<=0)
				sum[i] += val * (mapy[r] - mapy[l]);
			cnt[i] += val;
//			printf("%f %f (%f)\n", mapy[l], mapy[r], sum[i]);
		}
		return;
	}
	int m = (l+r) >> 1;
	if (L <= m) update(L, R, val, lsn);
	if (m <= R && l != m) update(L, R, val, rsn);
	pushup
//	printf("%f %f (%f)\n", mapy[l], mapy[r], sum[i]);
}

int cmp1(const rt &a, const rt &b)
{
	return a.x < b.x;
}

int main(void)
{
	#ifndef ONLINE_JUDGE
	freopen("in.txt", "r", stdin);
	#endif

	int Case = 1;
	int n;
	while(scanf("%d", &n), n) {
			int ri, px, py;
			ri = px = py = 0;
			for(int i=0; i<n; ++i) {
					double x1, y1, x2, y2;
					scanf("%lf%lf%lf%lf", &x1, &y1, &x2, &y2);
					rr[ri].x = x1, rr[ri].y1 = y1, rr[ri].y2 = y2;
					rr[ri].val = 1; ++ri;
					rr[ri].x = x2, rr[ri].y1 = y1, rr[ri].y2 = y2;
					rr[ri].val = -1; ++ri;
					mapx[px++] = x1; mapx[px++] = x2;
					mapy[py++] = y1; mapy[py++] = y2;
			}

			sort(rr, rr + ri, cmp1);
			sort(mapx, mapx + px); px = unique(mapx, mapx + px) - mapx;
			sort(mapy, mapy + py); py = unique(mapy, mapy + py) - mapy;
			int j;
			double lx, S;
			lx = S = 0, j = 0;
			build(0, py - 1, 1);
			for(int i=0; i<ri; ++i) {
				while ((mapx[j] - rr[i].x) <= eps) ++j;
				S += (rr[i].x - lx) * sum[1];
//				printf("%d %f %f\n", i, sum[1], (rr[i].x - lx) * sum[1]);
				lx = rr[i].x;
				int y1 = lower_bound(mapy, mapy + py, rr[i].y1) - mapy;
				int y2 = lower_bound(mapy, mapy + py, rr[i].y2) - mapy;
//				printf("->%d %d %d\n", y1, y2, rr[i].val);
				update(y1, y2, rr[i].val, 0, py - 1, 1);
			}
			printf("Test case #%d\nTotal explored area: %.2f\n\n", Case, S);
			++Case;
	}
	return 0;
}
