#include <bits/stdc++.h>
#define loop(i,a,b)         for(i=a;i<b;i++)
#define rev(i,a,b)          for(i=a;i>=b;i--)
#define SET(a,b)            memset(a,b,sizeof(a))
#define LEN                 2050
#define INF                 1e9
#define EPS                 1e-9
#define x                   first
#define y                   second
#define pb                  pushback
using namespace std;
typedef long long large;
typedef pair<int,int> ii;
typedef vector<int> vi;
typedef vector<ii > vii;

double ans1[LEN][LEN];

double f1(int l, int s){
	//printf("f(%d,%d) = ?\n",l,s);
	if(ans1[l][s]>-.5) return ans1[l][s];
	double a;
	if(s>0 && l>0) a = (l*f1(l-1,s+1) + s*f1(l,s-1)) / (l+s);
	else if(l>0) a = f1(l-1,s+1);
	else a = s;
	//printf("f(%d,%d) = %.2lf\n",l,s,a);
	return ans1[l][s]=a;
}
double ans2[LEN][LEN];

double f2(int l, int s){
	//printf("f(%d,%d) = ?\n",l,s);
	if(ans2[l][s]>-.5) return ans2[l][s];
	double a;
	if(s>0 && l>0) a = 1+(l*f2(l-1,s+1) + s*f2(l,s-1)) / (l+s);
	else if(l==0) a = 0;
	else /*(s=0 l>0)*/ a = 1+(l*f2(l-1,s+1)) / (l+s);
	//printf("f(%d,%d) = %.2lf\n",l,s,a);
	return ans2[l][s]=a;
}

int main(){
	int l,s;
	loop(l,0,LEN) loop(s,0,LEN) ans1[l][s]=ans2[l][s]=-1;
	//freopen("pharmacy.txt", "r", stdin);
	while(scanf("%d %d", &l,&s)==2 && l+s>0) printf("%.9lf %.9lf\n",f1(l,s),f2(l,s));
	return 0;
}
