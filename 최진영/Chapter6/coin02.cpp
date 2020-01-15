#include <iostream>
#include <algorithm>
#define INF 11
using namespace std;

int value [11];
int coins[3] = {1,3,4};

int main(){
	value[0]=0;
	for(int i=1;i<11;i++){
		value[i] = INF;
		for(int j=0;j<3;j++) value[i] = min(value[i],value[i-coins[j]]+1);
	}
	cout<<value[10];
}
