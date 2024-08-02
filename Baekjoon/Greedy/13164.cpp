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

    for (int i = 0; i < n; i++){
        cin >> arr[i];
    }

    int arr_v2[n-1 + n];
    for (int i = 0; i < n-1; i++){
        arr_v2[i] = arr[i+1] - arr[i];
    }
    for (int i = n-1; i < 2*n - 1; i++){
        arr_v2[i] = 0;
    }
    stable_sort(arr_v2, arr_v2+n-1+n, greater<int>());

    int result = 0;

    for (int i = k-1; i < 2*n-1; i++){
        result += arr_v2[i];
    }

    cout << result;

    return 0;
}
