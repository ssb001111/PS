#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

int main() {

    cin.tie(NULL);
    ios_base::sync_with_stdio(false);

    int n, k;
    cin >> n >> k;

    int arr[n];

    int res[n];

    for (int i = 0; i < n; i++){
        cin >> arr[i];
        res[i] = -1;
    }

    res[0] = 1;

    for (int i = 0; i < n; i++){
        int ok = 0;
        for (int j = 0; j < i; j++){
            if (res[j] == 1){
                int a = (i - j) * (1 + abs(arr[i]-arr[j]));
                if (a <= k){
                    ok = 1;
                }
            }
        }
        res[i] = ok;
        res[0] = 1;
    }

    if (res[n-1] == 1){
        cout << "YES";
    }
    else{
        cout << "NO";
    }

    return 0;
}
