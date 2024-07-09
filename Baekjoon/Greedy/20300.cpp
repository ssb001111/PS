#include <iostream>
#include <string>
#include <algorithm>

using namespace std; 
 
int main() {

	  cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    
    int n;
    cin >> n;

    long long arr[n];

    for (int i = 0; i < n; i++){
        cin >> arr[i];
    }

    stable_sort(arr, arr+n, greater<long long>());

    long long result = 0;

    if (n % 2 == 1){
        result = arr[0];
        for (int i = 1; i < n/2 + 1; i++){
            long long first = arr[i];
            long long second = arr[n-i];
            long long res = first + second;
            if (res > result){
                result = res;
            }
        }
    }
    else{
        for (int i = 0; i < n/2; i++){
            long long first = arr[i];
            long long second = arr[n-1-i];
            long long res = first + second;
            if (res > result){
                result = res;
            }
        }
    }

    cout << result;
        
    return 0;
}
