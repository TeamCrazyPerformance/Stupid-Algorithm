#include<bits/stdc++.h>
using namespace std;
int main(){
    int n;
    std::pair<int,int> v[50];
    int order[50];
    cin>>n;
    for(int i=0;i<n;i++){
        cin>>v[i].first;
        cin>>v[i].second;
        order[i]=1;
    }
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            if(i==j)continue;
            if(v[i].first<v[j].first&&v[i].second<v[j].second)order[i]++;

        }
    }
    for(int i=0;i<n;i++){
        cout<<order[i]<<" ";
    }
    return 0;
}