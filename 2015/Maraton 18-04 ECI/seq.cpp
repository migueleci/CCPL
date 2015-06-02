#include <bits/stdc++.h>
#define LEN	4000100
#define loop(i,a,b) 	for(i=a;i<b;i++)
#define SET(a,b) 		memset(a, b, sizeof a)
#define x				first
#define y				second
using namespace std;

char temp[LEN];
int gap,len,pos[LEN],tmp[LEN],sa[LEN];

bool gapcmp(int i, int j){
	if(pos[i]!=pos[j]) return pos[i]<pos[j];
	i += gap, j+=gap;
	return (i<len && j<len)? pos[i]<pos[j]:i>j;
}

void suff(char* t,int* sa, int tlen){
	int i;
	if(tlen<=1){ sa[0]=0; return; }
	loop(i,0,tlen) sa[i]=i,pos[i]=t[i];
	len=tlen, gap=1, tmp[tlen-1]=tmp[0]=1;
	while(tmp[tlen-1]<tlen){
		sort(sa,sa+tlen,gapcmp);
		loop(i,1,tlen) tmp[i]=tmp[i-1]+gapcmp(sa[i-1],sa[i]);
		loop(i,0,tlen) pos[sa[i]] = tmp[i];
		gap<<=1;
	}
}

int main(void){
	int i, n, k, casos;
	//freopen("seq.in","r",stdin);
	gets(temp);
	sscanf(temp,"%d", &casos);
	while(casos--){
		gets(temp);
		n=strlen(temp);
		loop(i,0,n) temp[n+i]=temp[i];
		temp[2*n]=0;
		suff(temp,sa,2*n);
		loop(i,0,2*n) if(sa[i]<n) break;
		//loop(i,0,2*n) printf("%s\n",s+sa[i]);
		if(i<2*n)	loop(k, 0, n) printf("%c", temp[(k+sa[i]+n)%n]);
		puts("");
	}
	return 0;
}
