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

    stable_sort(arr, arr+n, greater<int>());

    int result = 0;

    for (int i = 0; i < n; i++){
        if (arr[i] <= k){
            result += k / arr[i];
            k = k % arr[i];
        }
    }

    cout << result;
    
    return 0;
}
