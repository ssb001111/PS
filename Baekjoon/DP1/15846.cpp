#include <iostream>
#include <string>
#include <algorithm>
#include <vector>

using namespace std;

int main() {

    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    
    int n;
    cin >> n;

    vector< pair<long long, long long> > v;
    long long arr[n];

    for (int i = 0; i < n; i++){
        long long a,b;
        cin >> a >> b;
        v.push_back(make_pair(a,b));
    }

    for (int i = n-1; i >= 0; i--){
        long long a = (n-1) - i + 1;
        long long result = 0;
        if (v[i].first <= a){ // 해당되는 날의 상담을 시도는 해 볼 수 있음
            long long to_add = v[i].second;
            if (i + v[i].first <= n-1){
                result = max(result, arr[i + v[i].first]);
            }
            result += to_add;
            if (i+1 <= n-1){
                result = max(result, arr[i+1]);
            }
        }
        else{ // 해당되는 날의 상담을 시도조차 못함
            if (i == n-1){
                result = 0;
            }
            else{
                result = max(result, arr[i+1]);
            }
            
        }
        arr[i] = result;
    }

    cout << arr[0];

    return 0;
}
