/*
ID:esxgx1
LANG:C++
PROG:sgu275
*/
#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
using namespace std;

typedef unsigned long long ULL;

ULL a[107];

int main(void)
{
	#ifndef ONLINE_JUDGE
	freopen("in.txt", "r", stdin);
	#endif

	int N;
	while(cin >> N){
		for(int i=0; i<N; ++i)
			cin >> a[i];
		ULL ans = 0;
		for(int i=61; i>=0; --i) {
			for(int j=0; j<N; ++j) {
				if (a[j] & 1ULL<<i) {
					if (!(ans & 1ULL<<i)) ans ^= a[j];

					for(int k=0; k<N; ++k)		// 根据xor的传递性
						if (k!=j && (a[k] & (1ULL<<i))) a[k] ^= a[j];

					a[j] = 0;
					break;
				}
			}
		}
		cout << ans << endl;
	}
	return 0;
}
