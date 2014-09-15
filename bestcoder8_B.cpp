/*
ID:esxgx1
LANG:C++
PROG:bestcoder8_B
*/
#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
using namespace std;

int M;

const int n = 2;
struct mat {
	int at[n][n];
};

#define mod M
mat m22_m(const mat &a,const mat &b)
{
	mat t;
	for(int i=0;i<n;++i) {
		for(int k=0;k<n;++k) {
			long long u = 0;
			for(int j=0;j<n;++j)
				u += (long long)a.at[i][j] * b.at[j][k];
			t.at[i][k] = u % mod;
		}
	}
	return t;
}

mat expo(mat p,int k)
{
	mat e;
	memset(e.at,0,sizeof(e.at));
	for(int i=0; i<n; ++i) e.at[i][i]=1;
	for(;k; k>>=1) {
		if(k & 1) e = m22_m(e, p);
		p = m22_m(p,p);
	}
	return e;
}

inline void DEC(int &a, int b){a -= b; if (a < 0) a += M;}

int main(void)
{
	#ifndef ONLINE_JUDGE
	freopen("in.txt", "r", stdin);
	#endif

	int N;
	while(scanf("%d%d", &N, &M)>=0) {
		mat p;
		p.at[0][0] = 1, p.at[0][1] = 2;
		p.at[1][0] = 1, p.at[1][1] = 0;
		int rslt = expo(p, N).at[0][0];
		if (!(N&1)) DEC(rslt, 1);
		printf("%d\n", rslt);
	}
	return 0;
}
