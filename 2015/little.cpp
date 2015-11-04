//#include <bits/stdc++.h>
#include <utility>
#include <algorithm>
#include <cstdio>
#include <cstring>
#include <string>
#include <vector>
#include <queue>
#include <deque>
#include <stack>
#include <iostream>
#include <map>
#include <queue>
#include <cmath>
#define INF         1e9
#define LIM         10100
#define UNVISITED   -1
#define loop(i,a,b) for(i=a;i<b;i++)
#define SET(a,b)    memset(a,b,sizeof a)
#define pb          push_back
#define x           first
#define y           second
using namespace std;
typedef pair<double,double> dd;
typedef pair<int,int> ii;
typedef pair<int,ii > iii;
typedef deque<string> quilt;
typedef vector<int> vi;
typedef vector<dd > vdd;
typedef vector<ii > vii;
typedef map<string,quilt> msq;

char cad[LIM];
msq dict;
bool error;

void prec(){
	quilt q1;
	q1.push_back("//");
	q1.push_back("/+");
	dict["A"]=q1; q1.clear();
	q1.push_back("\\\\");
	q1.push_back("+\\");
	dict["turn(A)"]=q1; q1.clear();
	q1.push_back("+/");
	q1.push_back("//");
	dict["turn(turn(A))"]=q1; q1.clear();
	q1.push_back("\\+");
	q1.push_back("\\\\");
	dict["turn(turn(turn(A)))"]=q1; q1.clear();
	q1.push_back("--");
	q1.push_back("--");
	dict["B"]=q1; q1.clear();
	q1.push_back("||");
	q1.push_back("||");
	dict["turn(B)"]=q1; q1.clear();
}

quilt turn(quilt x){
	return x;
}


quilt sew(quilt a, quilt b){
	return a;
}

void parse(int low,int high ){
	int i;
	string ccad=cad; ccad=ccad.substr(low,high-low);
	if (dict.count(ccad)==0) {
		if (ccad[0]=='t') {
			parse(low+5,high-1);
			if(error) return;
			dict[ccad]=turn(dict[ccad.substr(5,high-1-low-5)]);
		} else if(ccad[0]=='s'){
			int a=0;
			loop(i,low+4,high){
				if(cad[i]=='(') a++;
				else if(cad[i]==')') a--;
				else if(cad[i]==',' && a==0) break;
			}
			
			parse(low+4,i-1); parse(i+1,high-1);
			if(error) return;
			quilt a=dict[ccad.substr(4, i-low-1)];
			quilt b=dict[ccad.substr(i-low+1, high-low-1)];
			if(a.size()!=b.size()){error=1; return;}
			dict[ccad]=sew(a,b);
		}
	}
}

int main(){
	freopen("little.txt","r",stdin);
	char c;
	prec();
	int i,caso=1;
	while((c=getchar())!=EOF){
		if(c!='\t' && c!=' ' && c!='\n') cad[i++]=c;
		if(c==';') {
			printf("Quilt %d:\n",caso++);
			cad[i]=0;
			error=0;
			puts(cad);
			//parse(0, strlen(cad));
			i=0;
		}
	}
}