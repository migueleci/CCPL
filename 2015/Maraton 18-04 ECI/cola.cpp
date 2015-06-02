#include <bits/stdc++.h>
#define LIM	1100
#define loop(i,a,b) 	for(i=a;i<b;i++)
#define SET(a,b) 		memset(a, b, sizeof a)
#define x				first
#define y				second
using namespace std;

int main(){
	int n, p, s, pend;
	while(scanf("%d", &n)==1 && n>0){
		p=s=pend=0;
		while(n>=3){
			p+=(n/3)*3;
			n=n/3+n%3;
		}
		p+=n;
		if (n==2) p++;
		printf("%d\n", p);
	}
	return 0;
}

