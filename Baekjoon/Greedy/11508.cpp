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

    int result = 0;

    for (int i = 0; i < n; i+=3){
        int first = arr[i];
        int second = 0;
        if (i+1 < n){
            second = arr[i+1];
        }
        result += first;
        result += second;
    }

    cout << result;
        
    return 0;
}
