#include <iostream>
#include <string>
#include <algorithm>
#include <set>

using namespace std;

set<int> s;

int main() {

    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    
    int n, k;
    cin >> n >> k;

    int arr[k];
    arr[0] = 0;

    for (int i = 0; i < n; i++){
        int a;
        cin >> a;
        s.insert(a);
    }

    for (int i = 1; i <= k; i++){
        int result = 10001;
        for (auto iter = s.begin(); iter != s.end(); iter++){
            if (i - *iter >= 0){
                result = min(result, arr[i-*iter]);
            }
        }
        arr[i] = result + 1;
    }

    if (arr[k] >= 10002){
        cout << -1;
    }
    else{
        cout << arr[k];
    }

    return 0;
}
