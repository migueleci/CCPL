#include <bits/stdc++.h>
#define loop(i,a,b) 		for(i=a;i<b;++i)
#define rev(i,a,b) 		for(i=a;i>=b;--i)
#define LEN 200015
#define setmem(m,v) memset(m,v,sizeof(m))
#define SET(m,v) memset(m,v,sizeof(m))
#define x first
#define y second
using namespace std;
typedef long long ll;
typedef pair<int,int> ii;

int len;
ll a[LEN],t[LEN];

ll gcd(ll a, ll b){
	ll x;
	if(b>a) swap(a,b);
	while(b>0) x=a,a=b,b=a%b;
	return a;
}

int main(){
	int ntc,tc,i,bli;
	ll d,acumw,acumb,w,b,bl,ans,acw,acb,k,j;
	char s[2];
	//freopen("bricks.txt","r",stdin);
	scanf("%d",&ntc);
	loop(tc,1,ntc+1){
		scanf("%d", &len);
		acumb=acumw=0;
		loop(i, 0, len){
			scanf("%lld %s",&a[i],s);
			t[i]=(s[0]=='W');
			if(t[i]) acumw+=a[i];
			else acumb+=a[i];
		}
		//printf("%lld %lld\n",acumw,acumb);
		if(acumw==0 || acumb==0){
			printf("%lld\n",acumw+acumb);
			continue;
		}
		d = gcd(acumw,acumb);
		w = acumw/d;
		b = acumb/d;
		bl = w+b;
		//printf("gcd: %lld, bl: %lld\n",d,bl);
		ans=acw=acb=i=j=0;
		loop(i,0,len){
			if(t[i]==1) acw+=a[i];
			else acb+=a[i];
			if(acw/w>=1 && acb/b>=1){
				//printf("%lld %lld : %lld %lld : %lld %lld\n",w,b,acw,acb,acw/w,acb/b);
				j=min(acw/w,acb/b);
				acw-=(w*j);
				acb-=(b*j);
				ans++;
			}
			//printf("ac: %lld %lld\n",acw,acb);
			//if(acw%w==0 && acb%b==0 && acw/w == acb/b) ++ans, acw=acb=0;
		}
		printf("%lld\n",ans);
	}
	return 0;
}
