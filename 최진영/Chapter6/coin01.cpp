#include <iostream>
#include <algorithm>
#define INF 11
using namespace std;

int value [11];
int coins[3] = {1,3,4};

int solve(int x){
	if (x<0) return INF;
	if (x==0) return 0;
	int best = INF;
	if (value[x] != INF) return value[x];
	for(int i=0;i<3;i++) best = min(best,solve(x-coins[i])+1);
	value[x] = best;
	return best;
}

int main(){
	for(int i=1;i<11;i++) value[i] = INF;
	cout<<solve(10);
}
