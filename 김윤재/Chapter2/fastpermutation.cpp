#include<stdio.h>
#include<vector>
using namespace std;
int isVisited[9];
int N;
void permute();
vector<int> v;
int main()
{
    scanf("%d", &N);
    permute();
}
void permute()
{
    if (v.size() == N)
    {
        for (int i = 0; i < v.size(); ++i)
            printf("%d ", v[i]);
        printf("\n");
    }
    for(int i=1;i<=N;++i)
        if (!isVisited[i])
        {
            isVisited[i] = 1;
            v.push_back(i);
            permute();
            isVisited[i] = 0;
            v.pop_back();
        }
}
