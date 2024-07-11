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

    double result = arr[0];

    for (int i = 1; i < n; i++){
        result += arr[i] / 2.0;
    }
    
    cout.precision(6);
    cout << fixed << result;
        
    return 0;
}
