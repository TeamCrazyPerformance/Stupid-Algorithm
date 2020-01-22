#include <bits/stdc++.h>
using namespace std;

int main() {
    int n,input;
    vector<int> stairs;
    int score[301]={0};
    cin>>n; //n=계단수
    for (int i = 0; i<n; i++){cin>>input;stairs.push_back(input);}
    //stairs 인덱스가 하나씩 작음
    score[1]=stairs[0];
    score[2]=stairs[0]+stairs[1];
    for(int i = 3; i<=n; i++){
        score[i]=max(score[i-2]+stairs[i-1],score[i-3]+stairs[i-1]+stairs[i-2]);
    }
    
    cout<<score[n];
    return 0;
}

