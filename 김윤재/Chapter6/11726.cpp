#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin>>n;
    int cases[1001]={1,1,2,3};
    //output: modular(10007)
    for (int i=4; i<=n; i++){
        cases[i]=(cases[i-3]*3+cases[i-4]*2)%10007; //가로 두개 세로는 한개? ㅁㄹ 틀리면 그때 생각
        //cout<<"i : "<<i<<" cases[i]: "<<cases[i]<<"\n";
    }
    cout<<cases[n];
    return 0;
}

// 답은 맞았는데 답 찾아보니까 dp[i] = (dp[i - 1] + dp[i - 2]) 라는데? 시발 왜
// cases[i-3]*3+cases[i-4]*2 와 cases[i-1] + cases[i-2] 가 왜 같을지 생각해보자. 그냥 수학이 그렇게 되는거 같기도?
//i-1 + i-2 가 되는 이유는 그냥 바로 뒤에꺼에 세로 하나 붙이는거랑 두개 뒤에꺼에 가로 두개로 붙이는거랑 세로/가로로 케이스 나누면 되서 그런거야
//멍청하면 고생하는거야 병시나
