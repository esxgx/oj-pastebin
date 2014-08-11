#include <stdio.h>

char str[20087];
unsigned fib[20000]={1, 1};

unsigned fib1(int n)
{
	if (fib[n]) return fib[n];
	return fib[n] = (fib1(n-1) + fib1(n-2)) % 10007;
}

int main(void)
{
	int o,T, p, c, t;
	unsigned r;
	scanf("%d", &T);
	for(o=1; o<=T; ++o) {
		scanf("%s", str);
		r = 1;
		t = p = c = 0;
		for(p = 0; str[p]; ++p) {
			if (str[p] == 'h') {
				if (str[p+1] == 'e') {
					++c;
					++p;
					t = 1; continue;
				}
			}
			if (t == 1) {
				r = (r * fib1(c)) % 10007; c = 0;
				t = 0;
			}
		}
		if (t == 1) {
				r = (r * fib1(c)) % 10007;
				t = 0;
		}
		printf("Case %d: %d\n", o, r % 10007);
	}
	return 0;
}
