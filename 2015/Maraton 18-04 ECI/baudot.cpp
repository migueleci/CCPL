#include <bits/stdc++.h>
#define LIM	1100
#define loop(i,a,b) 	for(i=a;i<b;i++)
#define SET(a,b) 		memset(a, b, sizeof a)
#define x				first
#define y				second
using namespace std;

char baudot[2][1000],mes[1000],shifted;

void got(int k){
	if(baudot[shifted][k]<=4){
		if(baudot[shifted][k]==3) shifted=0;
		else shifted=1;
	}
	else{
		printf("%c",baudot[shifted][k]);
	}
}

int main(){
	int casos,i,j,k,n;
	//freopen("baudot.in","r",stdin);
	gets(baudot[0]);
	gets(baudot[1]);
	j=0,k=0;
	loop(i,0,32){
		if(baudot[0][i]==' '){
			if(j==1) baudot[0][i]=3;
			if(j==2) baudot[0][i]=4;
			j++;
		}
		if(baudot[1][i]==' '){
			if(k==1) baudot[1][i]=3;
			if(k==2) baudot[1][i]=4;
			k++;
		}		
	}
	while(gets(mes)){
		shifted=0;
		n = strlen(mes);
		k=0;
		loop(i,0,n){
			if(i%5==0) k = mes[i]-'0';
			else{
				k = 2*k+mes[i]-'0';
				if(i%5==4) got(k);
			}
		}
		printf("\n");
	}
	return 0;
}

