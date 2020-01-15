#include <iostream>
#include <algorithm>
#define INF 11
using namespace std;

int value [11];
int first[11];
int coins[3] = {1,3,4};

int main(){
  value[0] = 0;
  for(int i=1; i<11; i++) {
    value[i]=INF;
    for(int j=0; j<3; j++){
      if(i-coins[j]>=0 & value[i]>value[i-coins[j]]){
        value[i] = value[i-coins[j]] +1;
        first[i] = coins[j];
      }
    }
  }
  int n = 10;
  while(n>0){
    cout<<first[n]<<endl;
    n-=first[n];
  }
}
