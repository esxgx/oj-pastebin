#include <cstdio>
using namespace std;

#define MAXV	201
#define MAXE	(MAXV-1)

int Vefw[MAXE], Veh[MAXV], Vet[MAXE], Veptr;

#define addedge(s,t) ({\
    Vefw[Veptr] = Veh[s], Vet[Veptr] = t; \
    Veh[s] = ++Veptr; })

int Vtrs[MAXV];		// 每个节点宝物数量
int dp[MAXV][MAXV];

int solve(int s)
{
	int

	return 0;
}

int N, M;

int main(void)
{
	freopen("hdu1561.txt", "r", stdin);
	while(scanf("%d%d", &N, &M), N && M) {
		++N;
		for(int t=1; t<N; ++t) {
			int s;
			scanf("%d%d",&s, &Vtrs[t]);
			addedge(s, t);
		}
		printf("%d\n", solve(0));
	}
	return 0;
}
