#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

int main() {

    cin.tie(NULL);
    ios_base::sync_with_stdio(false);

    int n;
    cin >> n;

    int arr[n];

    for (int i = 0; i < n; i++){
        cin >> arr[i];
    }

    stable_sort(arr, arr+n, greater<int>());

    long long result = 0;

    for (int i = 0; i < n; i++){
        int p = arr[i] + 1;
        p -= (i + 1);
        if (p > 0){
            result += p;
        }
    }

    cout << result;
    
    return 0;
}
