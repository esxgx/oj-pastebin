/*
ID:esxgx1
LANG:C++
PROG:hdu4_B
*/
#include <cmath>
#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
using namespace std;

double Ai[57];

#define eps		1e-8

int main(void)
{
	#ifndef ONLINE_JUDGE
	freopen("in.txt", "r", stdin);
	#endif

	int T;
	scanf("%d", &T);
	while(T) {
		int n;
		scanf("%d", &n);
		for(int i=0; i<n; ++i)
			scanf("%lf", &Ai[i]);
        sort(Ai, Ai+n), Ai[n] = 1e9;
        int t;
        double rslt = 0;
        for(t=0; t<n-1; ++t) {
			double l = Ai[t+1] - Ai[t];
            double lst = Ai[0] - l;
            int c, i;
            c = i = 0;
            for(; i<n; ++i) {
				printf("%f \n", lst);
				if (fabs(Ai[i+1] - Ai[i] - l) < eps) {
					lst = max(Ai[i+1] - l, Ai[i]);
					printf("111\n");
					++i;
				} else if (lst + l - Ai[i] <= eps)
					lst = Ai[i],printf("222\n");
				else if (Ai[i+1] - Ai[i] - l >= eps)
					lst = Ai[i] + l, printf("333\n");
				else break;
            }
            if (i>=n && l > rslt) rslt = l;
            printf("-->\n");

		}
		printf("%.3f\n", rslt);
		--T;
	}
	return 0;
}
