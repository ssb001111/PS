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
        int r;
        cin >> r;
        arr[i] = r;
    }

    int result = 0;

    stable_sort(arr, arr+n);

    int e = n;

    for (int i = 0; i < n; i++){
        int m = arr[i] * e;
        if (m > result){
            result = m;
        }
        e--;
    }

    cout << result;
    
    return 0;
}
