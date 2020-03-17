#include <bits/stdc++.h>
using namespace std;
int main(){
    int m,n,sum=0,maxsum=0,size;
    int cards[100],hand[3]={0};
    cin>>n;
    cin>>m;
    for(int i=0;i<n;i++)cin>>cards[i];
    //sort(cards,cards+400);
    for(int i=0;i<n;i++){
        hand[0]=cards[i];
        sum+=hand[0];
        for(int j=0;j<n;j++){
            if(sum+cards[j]>m||j==i)continue;
            hand[1]=cards[j];
            sum+=hand[1];
            for(int k=0;k<n;k++){
                if(sum+cards[k]>m||k==j||k==i)continue;
                hand[2]=cards[k];
                sum+=hand[2];
                if(sum>maxsum)maxsum=sum;
                sum-=hand[2];
            }
            sum-=hand[1];
        }
        sum-=hand[0];
    }
    cout<<maxsum;
    return 0;   
}

// 개 추한게 이거 두번째 포문 부터는 i+1, j+1 부터 굴려도됨
// 조합 만드는법 잊어버렸나 멍청이 초등학교부터 다시 다녀라