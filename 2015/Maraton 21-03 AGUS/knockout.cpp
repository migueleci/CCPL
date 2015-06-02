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
int N,M;
int r[SZ][2];
int main(void){
	int i,j,k, a, b, c, ct=0;
	int t1;
	//freopen("k.txt","r",stdin);
	while(scanf("%d %d",&N,&M)==2){
		loop(i,0,N) scanf("%d %d",&r[i][0],&r[i][1]);
		loop(i,0,M){
			scanf("%d %d %d",&a, &b, &c);
			ct=0;
			loop(j, 0, N){
				k=(r[j][1]-r[j][0])*2;
				//printf("%d-%d\n",r[j][1],r[j][0] );
				if (c%k==0) t1=r[j][0];
				else if (c%(k/2)==0) t1=r[j][1];
				else if (c%k<k/2)t1=r[j][0]+c%k;
				else t1=r[j][0]+(k-c%(k/2))%(k/2);
				//printf("-->%d\n", t1);
				if (t1>=a && t1<=b) ct++;
			}
			printf("%d\n", ct);
		}
		
	}
	return 0;
}
