#include <iostream>
#include <algorithm>
#define INF 11
using namespace std;

int coins[3] = {1,3,4};
int c[11];

int main(){
  c[0]=1;
  for(int i=1;i<11;i++){
    for(int j=0;j<3;j++){
      if(i-coins[j]>=0) c[i] += c[i-coins[j]];
    }
  }
  cout<<c[5];
}
