//#include <bits/stdc++.h>
#include <iostream>
#include <cstring>
#define LEN 505
#define loop(i,a,b) 	for(i=a;i<b;i++)
#define SET(a,b) 		memset(a, b, sizeof a)
#define x				first
#define y				second
using namespace std;

char line[1000];
bool mm[LEN][LEN],cc[LEN][LEN], aux[LEN][LEN];
int V,c0,m0;

int main(){
	int casos,i,j, k, u, v;
	//freopen("mouse.in","r",stdin);
	bool primero=true;
	gets(line);
	sscanf(line,"%d",&casos);
	gets(line);
	while(casos--){
		if(!primero) puts("");
		primero=false;
		gets(line);
		sscanf(line,"%d %d %d",&V,&c0,&m0);
		c0--; m0--;
		memset(mm,0,sizeof(mm));
		memset(cc,0,sizeof(cc));
		
		loop(i,0,V) cc[i][i]=mm[i][i]=1;
		while(gets(line) && sscanf(line,"%d %d",&u,&v)==2){
			if(u==-1) break;
			cc[u-1][v-1]=1;
		}
		while(gets(line) && sscanf(line,"%d %d",&u,&v)==2){
			if(u==-1) break;
			mm[u-1][v-1]=1;
		}
		loop(i, 0, V) loop(j, 0, V) aux[i][j]=mm[i][j];
		loop(k, 0, V)loop(i, 0, V)loop(j, 0, V){
			mm[i][j]=mm[i][j] || (mm[i][k] && mm[k][j]);
			cc[i][j]=cc[i][j] || (cc[i][k] && cc[k][j]);
		}
		loop(i, 0, V) if (mm[m0][i] && cc[c0][i]) break;
		printf("%c ", (i!=V)?'Y':'N');
		loop(k, 0, V)
			if (cc[c0][k]){
				loop(i, 0, V) aux[k][i]=aux[i][k]=0;
			}
		
		loop(k, 0, V)loop(i, 0, V)loop(j, 0, V) aux[i][j]=aux[i][j] || (aux[i][k] && aux[k][j]);
		loop(i, 0, V) if (i!=m0 && aux[m0][i] && aux[i][m0]) break;
		printf("%c\n", (i!=V)?'Y':'N');
	}
	return 0;
}

