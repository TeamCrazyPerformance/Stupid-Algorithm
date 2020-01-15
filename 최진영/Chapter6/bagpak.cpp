#include <iostream>
#include <algorithm>
using namespace std;

int main(){
  int w[4] = {1,3,3,5};
  bool possible[13];
  for(int i=0;i<13;i++) possible[i] = false;
  possible[0] = true;
  for(int i=1;i<13;i++){
    for(int j=0;j<4;j++){
      if(i-w[j]>=0 && possible[i-w[j]] == true) possible[i] = true;
    }
  }
}
