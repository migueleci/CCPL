#include <bits/stdc++.h>
#define loop(i, a, b) for(i=a; i<b; i++)
#define SET(a, x) memset(a, x, sizeof(a))
#define PI	(acos(-1.0))
using namespace std;

int main(void){
	double a, b, c, area, r1, r2, a1, a2, a3, s;
	while (scanf("%lf%lf%lf", &a, &b, &c)==3){
		s=(a+b+c)/2.0;
		area=sqrt((s-a)*(s-b)*(s-c)*s);
		r1=area/(0.5*(a+b+c));
		r2=a*b*c/(4.0*area);
		a1=PI*r1*r1;
		a2=area-a1;
		a3=PI*r2*r2-area;
		printf("%.4lf %.4lf %.4lf\n", a3, a2, a1);
	}

	return 0;
}
