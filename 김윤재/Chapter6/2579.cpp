#include <bits/stdc++.h>
using namespace std;

int main() {
    int n,input;
    vector<int> stairs;
    int score[301]={0};
    cin>>n; //n=계단수
    for (int i = 0; i < n; i++){cin>>input;stairs.push_back(input);}

    cout<<score[n];
    return 0;
}

