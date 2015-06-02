#include <bits/stdc++.h>
#define loop(i, a, b) for(i=a; i<b; i++)
#define SET(a, x) memset(a, x, sizeof(a))
#define PI	(acos(-1.0))
#define LIM	2020
#define READ(file) freopen(file, "r", stdin)
#define Mod 7778777
using namespace std;
typedef long long int large;

char T[LIM][LIM], P[LIM], O[LIM][LIM];
int m, n, wm,hm,wp,hp,b[LIM],C[LIM][LIM];
large h0[LIM][LIM],h1[LIM][LIM],aa[LIM],bb[LIM],cc[LIM];
large Base;void rk(large* t,large tsz,large* ans,large psz){
	large i,j,poow=1,key=0;
  loop(i,0,psz){
    key = (Base*key+ t[i])%Mod;
    ans[i]=key;
    poow = (Base*poow)%Mod;
  }
  loop(i,psz,tsz+1){
    key = (Base*key+ Mod-poow*t[i-psz]%Mod+t[i])%Mod;
    ans[i]=key;
  }
}

int main(void){
	int i,j,ans;
	char tmp[LIM];
	//READ("j.txt");
	while(gets(tmp)){
		sscanf(tmp,"%d%d%d%d",&hp,&wp,&hm,&wm);
		ans=0;
		SET(O,0);
		SET(T,0);
		SET(C,0);
    loop(i,0,hp) gets(O[i]);
		loop(i,0,hm) gets(T[i]);
		Base=9999901;

    loop(i,0,hp){
			loop(j,0,wp) aa[j] = O[i][j]=='x';
			rk(aa,wp,bb,wp);
      cc[i] = bb[wp-1];

    }

		Base=7754787;
    rk(cc,hp,bb,hp);
    large OMFG = bb[hp-1];

		Base=9999971;
    //printf("%lld\n",OMFG);
		loop(i,0,hm){
			loop(j,0,wm) aa[j] = T[i][j]=='x';
			rk(aa,wm,h0[i],wp);
		}

		Base=9999937;
		loop(j,0,wm){
			loop(i,0,hm) aa[i]=h0[i][j];
			rk(aa,hm,bb,hp);
      loop(i,0,hm) h1[i][j]=bb[i];
		}

		loop(j,0,wm) loop(i,0,hm) C[i][j]+= h1[i+hp-1][j+wp-1]==OMFG;
    /*strcpy(P,O[0]);
    m=hp; n=hm;
    kmpPreprocess();
    loop(i,0,hm-hp+1) kmpH(i);
    SET(P,0);
    loop(i,0,hp) P[i]=O[i][0];
    m=wp; n=wm;
    kmpPreprocess();
    loop(i,0,wm-wp+1) kmpV(i);*/
		loop(i,0,hm-hp+1) loop(j,0,wm-wp+1) if(C[i][j]>=1) ans++;
		printf("%d\n",ans);
	}
	return 0;
}
