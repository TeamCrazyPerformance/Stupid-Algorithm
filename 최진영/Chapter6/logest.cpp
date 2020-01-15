#include <iostream>
#include <algorithm>
using namespace std;

int length[8];
int num[8] = {6,2,5,1,7,4,8,3};

int main(){
  for(int k=0;k<8;k++){
    length[k]=1;
    for(int i=0;i<k;i++){
      if(num[i]<num[k]) length[k] = max(length[k],length[i]+1);
    }
  }
  cout<<length[7];
}
