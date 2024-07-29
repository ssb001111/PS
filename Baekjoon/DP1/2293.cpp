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

    for (int i = 0; i < n; i++){
        int e;
        cin >> e;
        s.insert(e);
    }

    int arr[k+1];
    arr[0] = 1;
    for (int i = 1; i < k+1; i++){
        arr[i] = 0;
    }

    for (auto iter = s.begin(); iter != s.end(); iter++){
        for (int i = 1; i < k+1; i++){
            if (i - *iter > -1){
                arr[i] += arr[i - *iter];
            }
        }
    }
    
    cout << arr[k];

    return 0;
}
