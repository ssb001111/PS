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

    stable_sort(arr, arr+n);

    int arr_res[n];
    for (int i = 0; i < n; i++){
        arr_res[i] = 0;
    }

    arr_res[0] = arr[0];

    int result = arr_res[0];

    for (int i = 1; i < n; i++){
        arr_res[i] = arr_res[i-1] + arr[i];
        result += arr_res[i];
    }

    cout << result;
        
    return 0;
}
