#include <bits/stdc++.h> 
using namespace std;
int main()
{
    int n;
    scanf("%d", &n);
    vector<int> arr(n, 0);
    vector<int> sums(n, 0);
​
    int Max = -10000;
​
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }
​
    sums[0] = arr[0];
    for (int i = 1; i < n; i++) {
        sums[i] = max(sums[i - 1] + arr[i], arr[i]);
        Max = max(Max, sums[i]);
    }
    Max = max(Max, sums[0]);
​
    printf("%d\n", Max);
    return 0;
}