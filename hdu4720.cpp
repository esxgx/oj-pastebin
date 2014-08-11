/*
ID:esxgx1
LANG:C++
PROG:hdu4720
*/
#include <cmath>
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

	int T;
	scanf("%d", &T);
	for(int t = 1; t<=T; ++t) {
		double Xa, Ya, Xb, Yb, Xc, Yc, X, Y;
		double A,B,C,y,x,r;
		scanf("%lf%lf%lf%lf%lf%lf", &Xa, &Ya, &Xb, &Yb, &Xc, &Yc);
		A=sqrt((Xa-Xb)*(Xa-Xb)+(Ya-Yb)*(Ya-Yb));
		B=sqrt((Xa-Xc)*(Xa-Xc)+(Ya-Yc)*(Ya-Yc));
		C=sqrt((Xb-Xc)*(Xb-Xc)+(Yb-Yc)*(Yb-Yc));
		y=(A+B+C)/2;
		x=sqrt(y*(y-A)*(y-B)*(y-C));
		r=A*B*C/(4*x);
		scanf("%lf%lf", &X, &Y);
		printf("%f %f\n", r, sqrt((x - X) * (x - X) + (y - Y)*(y - Y)));

		if (sqrt((x - X) * (x - X) + (y - Y)*(y - Y)) <= r) printf("Case #%d: Danger\n", t);
		else printf("Case #%d: Safe\n", t);
	}

	return 0;
}
