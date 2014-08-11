/*
ID: esxgx1
PROG: buylow
LANG: C++
*/
#include <iostream>
#include <iomanip>
#include <cstring>
#include <cstdio>
using namespace std;

int N, price[5001];
int eqn[5001];

int dp[5001];

#define min(a,b)	((a)>(b)?(b):(a))
#define max(a,b)	((a)>(b)?(a):(b))

#define BIGNUM_LL			100
#define BIGNUM_BL			"4"
#define BIGNUM_MOD			10000UL
typedef typeof(BIGNUM_MOD) bignum_block;

struct bignum {
	unsigned len;
	bignum_block blks[BIGNUM_LL];

	bignum() {blks[0]=0, len=1;}

	bignum(unsigned num) {
		len = 0;
		while(num) {
			blks[len++] = num % BIGNUM_MOD;
			num /= BIGNUM_MOD;
		}
	}

	void operator += (bignum &b) {
		int i;
		bignum_block carry;

		i = len; do blks[i++] = 0; while(i<=b.len);

		carry = i = 0;
		for(; i<b.len; ++i) {
			blks[i] += b.blks[i];
			if (blks[i] >= BIGNUM_MOD) {
				++blks[i+1];
				blks[i]-=BIGNUM_MOD;
			}
		}
		for(; i<len; ++i) {
			if (blks[i] >= BIGNUM_MOD) {
				++blks[i+1];
				blks[i]-=BIGNUM_MOD;
			}
		}
		len = i + (blks[i] > 0);
	}

	void print() {
		printf("%d", blks[len-1]);
		for(int i=len-1; i--; )
			printf("%0" BIGNUM_BL "d", blks[i]);
	}
}dp2[5001];

int main(void)
{
	freopen("buylow.in", "r", stdin);
	freopen("buylow.out", "w", stdout);
	int i, m;

	cin >> N;
	for(i=0; i<N; ++i) cin >> price[i];
	N++;	// 增加一个超级节点, price[supernode] = 0;

	for(i=0; i<N-1; ++i) {
		int j;
		for(j=i+1; j<N; ++j)
			if (price[j] == price[i]) {
				eqn[i] = j;
				break;
			}
		if (j >= N) eqn[i] = N;
	}
	eqn[N-1] = N;

	for(i=0; i<N; ++i) {
		dp[i] = 1;
		dp2[i] = 1;
		int j;
		for(j=0; j<i; ++j) {
			if (price[i] < price[j]) {
				if (eqn[j] > i) {
					const int k = dp[j] + 1;
					if (k > dp[i]) {
						dp[i] = k;
						dp2[i] = dp2[j];
					} else if (k == dp[i])
						dp2[i] += dp2[j];
				}
			}
		}
	}
	cout << dp[N-1] - 1 << ' ';
	dp2[N-1].print();
	cout << endl;

	return 0;
}
