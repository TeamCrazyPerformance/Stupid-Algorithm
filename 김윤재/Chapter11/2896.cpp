#include<bits/stdc++.h>
using namespace std;
int main(){
    int mi;
    int fruit[3];
    int ratio[3];
    double reduct[3];
    double left[3];
    for(int i=0;i<3;i++)cin>>fruit[i];
    for(int i=0;i<3;i++)cin>>ratio[i];
    mi=min(min(ratio[0],ratio[1]),ratio[2]);
    for(int i=0;i<3;i++){
        reduct[i]=ratio[i]/mi;
    }
    



    return 0;
}