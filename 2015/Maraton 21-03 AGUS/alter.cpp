#include <bits/stdc++.h>
/*
#include <iostream>
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <algorithm>
#include <functional>
#include <cctype>
#include <cmath>
#include <string>
#include <queue>
#include <stack>
#include <utility>
#include <vector>
#include <set>
#include <map>
*/
#define loop(i, a, b) for(i=a; i<b; i++)
#define SET(mat, a) memset(mat, a, sizeof(mat))
#define rev(i, a, b) for(i=a; i>=b; i--)
#define SZ	2000000
#define READ(f) freopen(f, "r", stdin)
#define mp make_pair
#define x first
#define y second


using namespace std;
typedef pair<int,int> ii;
int main(void){
	int i,N,M,n,m;
	//freopen("a.txt","r",stdin);
	while(scanf("%d %d",&N,&M)==2){
		n=N/2, m=M/2;
		printf("%d\n",n+m);
		loop(i,0,m)	printf("%d %d %d %d\n",1,2*i+2,N,2*i+2);
		loop(i,0,n)	printf("%d %d %d %d\n",2*i+2,1,2*i+2,M);
	}
	return 0;
}
