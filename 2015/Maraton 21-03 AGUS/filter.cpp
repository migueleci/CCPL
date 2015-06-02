//#include <bits/stdc++.h>
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
typedef long long large;
int filt[110];

int main(void){
	int i;
	freopen("f.txt","r",stdin);
	while(scanf("%d %d",&M,&flen)==2){
		loop(i,0,flen) scanf("%d",&filt[i]);
		loop(i,0,N) scanf("%d %d %d")
		//printf("%d\n",N);
	}
	return 0;
}
