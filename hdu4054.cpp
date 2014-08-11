/*
ID:esxgx1
LANG:C++
PROG:hdu4054
*/
#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
using namespace std;

int main(void)
{
	#ifndef ONLINE_JUDGE
	freopen("in.txt", "r", stdin);
	#endif

	char ascs[4097];

    while(cin.getline(ascs, 4097)) {
    	int len = strlen(ascs);
    	for(int i=0; i<len; i+=16) {
			printf("%04x: ", i);
			int t = 0;
			while(t<min(len-i, 16)) {
				printf("%02x", ascs[t++ +i]);
				if (!(t % 2)) putchar(' ');
			}
			while(t < 16) {
				printf("  "), ++t;
				if (!(t % 2)) putchar(' ');
			}
			t = 0;
			while(t<min(len-i, 16)) {
				if (ascs[t + i] >= 'A' && ascs[t + i] <= 'Z')
					putchar(ascs[t + i] - 'A' + 'a');
				else if (ascs[t + i] >= 'a' && ascs[t + i] <= 'z')
					putchar(ascs[t + i] - 'a' + 'A');
				else putchar(ascs[t + i]);
				++t;
			}
			putchar('\n');
    	}
    }
	return 0;
}
