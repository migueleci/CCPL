#include <bits/stdc++.h>
#define loop(i, a, b) for (i=a; i<b; i++)
#define LEN 1000
#define X		first
#define Y		second
using namespace std;
typedef pair<int, string> ic;
typedef vector<ic > vic;

vic hand;

int envido(){
	int b[4]; b[0]=-1; b[1]=-1; b[2]=-1; b[3]=-1;
	int pos;
	loop(pos,0,3){
		//printf("pos=%d %d %s\n",pos,hand[pos].X,hand[pos].Y.c_str());
		if(strcmp(hand[pos].Y.c_str(),"espada")==0){
			if(b[0]==-1) b[0]=hand[pos].X;
			else if(b[0]<20) b[0]+=20+hand[pos].X;
		} else if(strcmp(hand[pos].Y.c_str(),"copa")==0){
			if(b[1]==-1) b[1]=hand[pos].X;
			else if(b[1]<20) b[1]+=20+hand[pos].X;
		} else if(strcmp(hand[pos].Y.c_str(),"oro")==0){
			if(b[2]==-1) b[2]=hand[pos].X;
			else if(b[2]<20) b[2]+=20+hand[pos].X;
		} else {
			if(b[3]==-1) b[3]=hand[pos].X;
			else if(b[3]<20) b[3]+=20+hand[pos].X;
		}
	}
	return max(b[0],max(b[1],max(b[2],b[3])));
}

vector<int> num;

int solve(){
  int punt=envido();
  //printf("%d\n",punt);
  if(punt==33) return 0;
  else{
		num.clear();
		num.push_back(hand[0].X);
		num.push_back(hand[1].X);
		num.push_back(hand[2].X);
		sort(num.begin(),num.end());
		//printf("%d %d %d\n",num[0],num[1],num[2]);
		if(num[2]==7) return 33-punt;
		else return num[2]+27-punt;
  }
}

int main(){
  int n1,n2,n3;
  char s1[10],s2[10],s3[10];
  //freopen("falta.txt","r",stdin);
  while(scanf("%d %s %d %s %d %s",&n1,s1,&n2,s2,&n3,s3)==6 && n1!=-1){
		hand.clear();
    if(n1>7) n1=0; hand.push_back(ic(n1,s1));
    if(n2>7) n2=0; hand.push_back(ic(n2,s2));
    if(n3>7) n3=0; hand.push_back(ic(n3,s3));
    sort(hand.begin(),hand.end(),greater<ic >());
    //printf("%d %s %d %s %d %s\n",n1,s1,n2,s2,n3,s3);
    printf("%d\n",solve());
  }
  return 0;
}
