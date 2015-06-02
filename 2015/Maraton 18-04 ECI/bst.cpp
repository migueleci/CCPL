//#include <bits/stdc++.h>
#include <stdio.h>

void root(int lo, int hi, int d){
	if(lo>hi) return; 
	int i,mid;
	if(hi-((1<<d)-1)>=lo) mid=hi-((1<<d)-1);
	else mid=lo;
	printf(" %d",mid);
	if(d==0) return;
	root(lo,mid-1,d-1);
	root(mid+1,hi,d-1);
}

int main(){
	int n,h,casos=1;
	//freopen("bst.in","r",stdin);
	while(scanf("%d %d",&n,&h)==2 && n+h>0){
		printf("Case %d:",casos++);
		if((1<<h)<=n) { printf(" Impossible.\n"); continue; }
		if(n<=h) h=n;
		root(1,n,h-1);
		puts("");
	}
	return 0;
}

