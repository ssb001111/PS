#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

int main() {

    cin.tie(NULL);
    ios_base::sync_with_stdio(false);

    int n;
    cin >> n;

    if (n == 0 or n == 1){
        cout << n;
    }
    else{

        int arr[n+1];
        arr[0] = 0;
        arr[1] = 1;

        for (int i = 2; i < n+1; i++){
            arr[i] = arr[i-1] + arr[i-2];
        }

        cout << arr[n];
    }
    
    return 0;
}
