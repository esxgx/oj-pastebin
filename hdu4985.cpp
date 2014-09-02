#include <cstdio>
#include <cmath>
using namespace std;

#define NN	110000
double g[NN + 1];

int main(void)
{
	for(int i=1; i<=NN; ++i) g[i] = g[i-1] + 1/(double)i;
	int N;
	while(scanf("%d", &N) > 0)
		printf("%.4f\n", N<=NN ? g[N] : log(N+1) + 0.577215664);
	return 0;
}
