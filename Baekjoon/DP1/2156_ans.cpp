#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

int main() {

    cin.tie(NULL);
    ios_base::sync_with_stdio(false);

    int n;
    cin >> n;

    int a[n+1];
    int dp[n+1];
    for (int i=1; i<=n; i++){
        cin >> a[i];
    }

    dp[0] = 0; 
    dp[1] = a[1];
    dp[2] = a[1] + a[2];

    for (int i=3; i<=n; i++){

        // N번째 와인잔을 선택했을 때 마실 수 있는 경우의 수
        // 1. N-3번째까지의 최댓값 + N-1번째 잔 + N번째 잔 _] _ㅁ ㅁ
        // 2. N-2번째까지의 최댓값 + N번째 잔 _ _] _ ㅁ
        // 3. N-1번째까지의 최댓값(N선택 X) _ _] _ 

        dp[i] = max({dp[i-3]+a[i-1]+a[i], dp[i-2]+a[i], dp[i-1]});
    }

    cout << dp[n];

    return 0;
}
